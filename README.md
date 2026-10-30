# PSB II – Smart Spiroballs / Smart SpiroGame

Dokumentasi proyek kelompok Perancangan Sistem Biomedis II, Teknik Biomedis, Institut Teknologi Sumatera.

## Gambaran proyek

Dokumen kelompok membahas pengembangan prototipe berbasis sensor tekanan dan mikrokontroler untuk akuisisi serta pengolahan sinyal pernapasan, antarmuka permainan, dan rencana komunikasi melalui Telegram. Nama Smart SpiroGame juga digunakan dalam dokumen sumber.

Repositori ini mendokumentasikan rencana dan bahan desain. Keberadaan dokumen tidak membuktikan bahwa perangkat telah selesai dibuat, dikalibrasi, diuji, atau layak digunakan secara klinis.

## Dokumen yang tersedia

| Dokumen | Isi | Status |
| --- | --- | --- |
| [BM100](docs/BM100.md) | Proposal pengembangan proyek | Draf dokumen |
| [BM200](docs/BM200.md) | Spesifikasi dan rencana verifikasi | Draf dokumen |
| [BM300](docs/BM300.md) | Konsep, desain, dan rencana pengujian | Draf dokumen |

Versi Markdown merupakan ekstraksi teks dari dokumen Word kelompok. Gambar, tanda tangan, tata letak tabel, dan sebagian format persamaan tidak ikut dipertahankan. Dokumen Word asli tetap disimpan secara lokal. Bagian CV dan kontak email tidak dimasukkan ke versi teks publik.

## Status dan keterbatasan

- Bahan BM100, BM200, dan BM300 tersedia sebagai dokumen perencanaan.
- Sampul BM100/BM200 menyebut Arduino Uno dan BMP280, sedangkan bagian isi membahas ESP32 dan MPX5010DP. Konfigurasi perangkat aktual perlu dikonfirmasi dan dokumen perlu diselaraskan.
- Angka spesifikasi, target akurasi, jadwal, klaim standar, dan referensi dalam dokumen sumber belum diverifikasi ulang. Angka target bukan hasil pengujian.
- Kode program belum dimasukkan. Lokasinya terpisah dari folder dokumen dan akan ditambahkan setelah diperiksa.
- Data mentah dan hasil pengujian belum disertakan dalam unggahan awal ini. Status pelaksanaan pengujian perlu dikonfirmasi kepada kelompok.
- Prototipe tidak boleh dianggap sebagai alat diagnosis atau perangkat klinis tervalidasi berdasarkan dokumentasi ini.

## Rencana struktur repositori

```text
.
├── README.md
├── docs/
│   ├── BM100.md
│   ├── BM200.md
│   └── BM300.md
├── firmware/        # rencana: kode mikrokontroler
├── analysis/        # rencana: pengolahan data
├── hardware/        # rencana: skema rangkaian dan desain
├── protocols/       # rencana: prosedur kalibrasi dan pengujian
├── data/            # rencana: data uji nonidentitas yang boleh dibagikan
└── results/         # rencana: hasil pengujian aktual
```

Folder berlabel rencana belum menunjukkan berkas yang sudah tersedia.

## Penambahan kode berikutnya

Sertakan kode sumber, versi board/mikrokontroler, daftar library beserta versinya, diagram koneksi pin, dan petunjuk kompilasi serta penggunaan. Password Wi-Fi, token bot Telegram, chat ID pribadi, dan kredensial lain tidak boleh dimasukkan. Gunakan berkas konfigurasi lokal dan contoh konfigurasi tanpa nilai rahasia.

## Pekerjaan selanjutnya

1. Konfirmasi konfigurasi perangkat yang benar-benar digunakan.
2. Selaraskan BM100–BM300 dengan progres aktual.
3. Tambahkan kode yang telah diperiksa.
4. Lengkapi rencana uji terukur, jadwal aktual, dan pembagian tanggung jawab.
5. Tambahkan rencana manuskrip, target jurnal, serta rencana waktu submit sesuai tugas UTS.
6. Unggah hasil pengujian hanya setelah pengujian benar-benar dilakukan.
