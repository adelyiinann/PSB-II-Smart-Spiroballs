#include <Wire.h>
#include <U8g2lib.h>
#include <Adafruit_BMP280.h>

#define BTN 2

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);
Adafruit_BMP280 bmp;

bool holdMode = false;
float baseline = 0;

void calibrateBaseline() {
  u8x8.clear();
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  
  u8x8.drawString(0, 0, "SMART SPIRO");
  u8x8.drawString(0, 2, "CALIBRATING");
  u8x8.drawString(0, 3, "PLEASE WAIT");

  Serial.println("Memulai kalibrasi baseline...");
  float sum = 0;

  for(int i=0; i<50; i++) {
    sum += bmp.readPressure();
    delay(100);
  }

  baseline = sum / 50.0;

  u8x8.clear();
  u8x8.drawString(0, 0, "BASELINE OK");
  u8x8.drawString(0, 2, "P:");
  u8x8.setCursor(2, 2);
  u8x8.print((int)baseline);

  Serial.print("Baseline Selesai: ");
  Serial.println(baseline);
  
  delay(2000);
}

void showMenu() {
  u8x8.clear();
  u8x8.setFont(u8x8_font_chroma48medium8_r);

  u8x8.drawString(0, 0, "SMART SPIRO");

  if(holdMode)
    u8x8.drawString(0, 2, "MODE : HOLD 3S");
  else
    u8x8.drawString(0, 2, "MODE : FREE");

  u8x8.drawString(0, 4, "Click = Mode");
  u8x8.drawString(0, 5, "Hold = Start");
}

void countdown() {
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  for(int i=3; i>=1; i--) {
    u8x8.clear();
    u8x8.setCursor(7, 3);
    u8x8.print(i);
    delay(1000);
  }

  u8x8.clear();
  u8x8.drawString(6, 3, "GO!");
  delay(700);
}

void runTest() {
  float peakPressure = baseline; 
  bool blowing = false;
  bool holdFail = false;

  unsigned long startBlow = 0;
  unsigned long lastBlow = 0;

  float duration = 0;

  countdown();

  u8x8.setFont(u8x8_font_chroma48medium8_r);

  while(true) {
    float pressure = bmp.readPressure();
    float deltaP = pressure - baseline; 

    if(pressure > peakPressure)
      peakPressure = pressure;

    // Perubahan Logika: Diturunkan ke 8 Pa agar hembusan sekecil apa pun langsung memicu timer mulai jalan
    if(deltaP > 8) { 
      if(!blowing) {
        blowing = true;
        startBlow = millis();
      }
      lastBlow = millis();
    }

    // ================= FREE MODE =================
    if(!holdMode) {
      u8x8.clear();
      u8x8.drawString(0, 0, "FREE MODE");
      
      u8x8.drawString(0, 2, "dP:");
      u8x8.setCursor(4, 2);
      u8x8.print((int)deltaP);

      u8x8.drawString(0, 3, "Peak:");
      u8x8.setCursor(6, 3);
      u8x8.print((int)peakPressure);

      // Anggap tiupan selesai jika berhenti ditiup selama 1 detik
      if(blowing && (millis() - lastBlow > 1000)) {
        duration = (lastBlow - startBlow) / 1000.0;
        break;
      }
    }
    // ================= HOLD MODE =================
    else {
      if(blowing) {
        float elapsed = (millis() - startBlow) / 1000.0;
        int sec = (int)elapsed + 1;

        if(sec > 3) sec = 3;

        int liveLevel;
        float liveDelta = peakPressure - baseline;

        // Level bola tetap menggunakan batas hasil rata-rata kalibrasi data kamu
        if(liveDelta < 18)        liveLevel = 0;
        else if(liveDelta < 43)   liveLevel = 1;
        else if(liveDelta < 90)   liveLevel = 2;
        else                      liveLevel = 3;

        u8x8.clear();
        u8x8.drawString(0, 0, "HOLD TEST");
        
        u8x8.drawString(0, 2, "dP:");
        u8x8.setCursor(4, 2);
        u8x8.print((int)liveDelta);

        u8x8.drawString(0, 3, "Level:");
        u8x8.setCursor(7, 3);
        u8x8.print(liveLevel);

        u8x8.setCursor(7, 5);
        u8x8.print(sec);

        if(elapsed >= 3.0) {
          duration = 3.0;
          break;
        }

        // Jika di tengah jalan tiupan terputus/drop total selama 1 detik
        if(millis() - lastBlow > 1000) {
          duration = (lastBlow - startBlow) / 1000.0;
          holdFail = true;
          break;
        }
      } else {
        u8x8.clear();
        u8x8.drawString(0, 0, "HOLD TEST");
        u8x8.drawString(0, 2, "WAITING BLOW...");
      }
    }

    delay(20);
  }

  float deltaPeak = peakPressure - baseline;

  int level;
  if(deltaPeak < 18)        level = 0;
  else if(deltaPeak < 43)   level = 1;
  else if(deltaPeak < 90)   level = 2;
  else                      level = 3;

  u8x8.clear();
  u8x8.drawString(0, 0, "RESULT");
  
  u8x8.drawString(0, 2, "dP:");
  u8x8.setCursor(4, 2); u8x8.print((int)deltaPeak);

  u8x8.drawString(0, 3, "Time:");
  u8x8.setCursor(6, 3); u8x8.print(duration, 1); u8x8.print("s");

  u8x8.drawString(0, 4, "Level:");
  u8x8.setCursor(7, 4); u8x8.print(level);

  u8x8.drawString(0, 5, "Ball:");
  u8x8.setCursor(6, 5);
  if(level == 0)      u8x8.print("NONE");
  else if(level == 1) u8x8.print("1");
  else if(level == 2) u8x8.print("2");
  else                u8x8.print("3");

  if(holdMode) {
    u8x8.setCursor(0, 7);
    if(holdFail) u8x8.print("FAIL");
    else         u8x8.print("PASS");
  }

  Serial.println("==========");
  Serial.print("Baseline = ");  Serial.println(baseline);
  Serial.print("Peak = ");      Serial.println(peakPressure);
  Serial.print("Delta Peak = "); Serial.println(deltaPeak);
  Serial.print("Duration = ");   Serial.println(duration);
  Serial.print("Level = ");      Serial.println(level);

  delay(8000);
  showMenu();
}

void setup() {
  Serial.begin(115200);

  pinMode(BTN, INPUT_PULLUP);

  u8x8.begin();
  u8x8.setPowerSave(0); 

  if(!bmp.begin(0x76)) {
    u8x8.clear();
    u8x8.setFont(u8x8_font_chroma48medium8_r);
    u8x8.drawString(0, 0, "BMP FAIL");
    while(1);
  }

  calibrateBaseline();
  showMenu();
}

void loop() {
  if(digitalRead(BTN) == LOW) {
    unsigned long t0 = millis();

    while(digitalRead(BTN) == LOW) {
      delay(10);
    }

    unsigned long pressTime = millis() - t0;

    if(pressTime < 1000) {
      holdMode = !holdMode;
      showMenu();
    }
    else if(pressTime > 2000) {
      runTest();
    }
  }
}
