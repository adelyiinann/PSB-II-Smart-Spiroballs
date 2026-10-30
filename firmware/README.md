# Firmware Smart Spiroballs

## Berkas

[SmartSpiroballs/SmartSpiroballs.ino](SmartSpiroballs/SmartSpiroballs.ino) berasal dari berkas kelompok `code spiroballs.txt`. Ekstensi diubah menjadi `.ino` dan ditempatkan pada folder dengan nama yang sama; logika program tidak diubah.

## Fungsi dalam kode

- Inisialisasi BMP280 pada alamat I2C `0x76` dan OLED SSD1306 melalui U8x8.
- Pengambilan 50 pembacaan tekanan awal sebagai baseline, dengan jeda 100 ms.
- Pembacaan perubahan tekanan terhadap baseline, pencatatan tekanan puncak, serta durasi sesi.
- Mode FREE dan mode HOLD dengan durasi target 3 detik.
- Penentuan level 0–3 menggunakan ambang perubahan tekanan yang tertulis dalam program.
- Penyajian hasil melalui OLED dan Serial pada baud rate 115200.

Pengambilan baseline adalah penetapan acuan awal pembacaan, bukan bukti kalibrasi terhadap alat standar. Komentar pada kode mengenai asal ambang belum didukung data pengujian yang diunggah di repositori.

## Komponen dan dependensi yang disebut dalam kode

| Komponen/dependensi | Keterangan |
| --- | --- |
| BMP280 | Menggunakan `Adafruit_BMP280.h`; alamat sensor ditetapkan `0x76`. |
| OLED SSD1306 | Menggunakan `U8g2lib.h` dengan kelas U8x8 I2C. |
| Tombol | Pin digital 2, dikonfigurasi `INPUT_PULLUP`. |
| Komunikasi I2C | Menggunakan `Wire.h`. |

Jenis board, versi Arduino core, versi library, dan rangkaian aktual belum dicantumkan dalam berkas sumber. Board dan pin I2C harus disesuaikan dengan perangkat yang benar-benar digunakan.

## Pengoperasian yang diimplementasikan

1. Saat mulai, program mengambil baseline dan menampilkan menu.
2. Tombol ditekan kurang dari 1 detik untuk mengganti mode.
3. Tombol ditahan lebih dari 2 detik lalu dilepas untuk memulai sesi.
4. Program menampilkan hitung mundur, kemudian menunggu perubahan tekanan melewati ambang pemicu.
5. Hasil sesi ditampilkan di OLED dan dicetak melalui Serial.

Penekanan tombol selama 1–2 detik tidak memicu aksi pada logika saat ini.

## Status implementasi

Kode sumber telah didokumentasikan; kompilasi dan pengujian pada perangkat belum diverifikasi dalam sesi dokumentasi ini. Program belum mengimplementasikan perhitungan FVC/PEFR, klasifikasi klinis, koneksi Wi-Fi, atau bot Telegram.

Level bola merupakan keluaran dari aturan ambang dalam kode, bukan pembacaan langsung posisi bola atau kategori diagnosis. Mode HOLD memakai logika waktu dan toleransi jeda dalam program; label PASS tidak membuktikan validitas pengukuran klinis.

## Membuka kode

Buka berkas `SmartSpiroballs.ino` pada Arduino IDE. Pemilihan board, pemasangan dependensi, dan pengunggahan ke perangkat memerlukan konfigurasi sesuai perangkat aktual.
