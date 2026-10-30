# PSB II – Smart Spiroballs / Smart SpiroGame

Dokumentasi proyek kelompok Perancangan Sistem Biomedis II, Program Studi Teknik Biomedis, Institut Teknologi Sumatera.

## Gambaran Proyek

Smart Spiroballs / Smart SpiroGame merupakan proyek pengembangan prototipe berbasis sensor tekanan dan mikrokontroler untuk akuisisi serta pengolahan sinyal pernapasan, antarmuka permainan, dan integrasi komunikasi melalui Telegram. Dokumen dalam repositori ini memuat perencanaan dan rancangan sistem.

## Dokumen Proyek

| Dokumen | Isi | Status |
| --- | --- | --- |
| [BM100](docs/BM100.md) | Proposal pengembangan proyek | Draf |
| [BM200](docs/BM200.md) | Spesifikasi dan rencana verifikasi | Draf |
| [BM300](docs/BM300.md) | Konsep, desain, dan rencana pengujian | Draf |
| [Presentasi UTS PSB II](presentations/UTS_PSB_II_Smart_Spiroballs.pdf) | Presentasi kelompok: rancangan, progres, rencana pengujian, dan luaran | Tersedia |

## Struktur dan Rencana Dokumentasi Repositori

```text
.
├── README.md
├── docs/
│   ├── BM100.md
│   ├── BM200.md
│   └── BM300.md
├── presentations/
│   └── UTS_PSB_II_Smart_Spiroballs.pdf
├── firmware/
│   ├── README.md
│   └── SmartSpiroballs/
│       └── SmartSpiroballs.ino
├── analysis/       [rencana folder]
├── hardware/       [rencana folder]
├── protocols/      [rencana folder]
├── publication/    [rencana folder]
├── data/           [rencana folder]
└── results/        [rencana folder]
```

Folder bertanda **rencana folder** merupakan bagian dari rencana pengembangan dokumentasi dan akan ditambahkan sesuai tahapan proyek. Keterangan berikut menjelaskan dokumen yang tersedia serta rencana kelengkapannya.

| Bagian | Isi yang direncanakan | Status dan keterangan |
| --- | --- | --- |
| `docs/` | Dokumentasi BM100, BM200, dan BM300 | Tersedia dalam bentuk draf teks Markdown. |
| `firmware/` | Kode program mikrokontroler dan petunjuk penggunaannya | Tersedia: [kode Arduino](firmware/SmartSpiroballs/SmartSpiroballs.ino) dan [dokumentasi firmware](firmware/README.md). Kode menggunakan BMP280, OLED, dan tombol; kompilasi serta pengujian perangkat belum diverifikasi dalam dokumentasi ini. |
| `analysis/` | Kode pengolahan data dan perhitungan parameter evaluasi | Pengembangan dan pengunggahan kode analisis direncanakan untuk mendukung pengolahan data serta evaluasi hasil pengujian. |
| `hardware/` | Diagram blok, skema rangkaian, dan desain perangkat | Deskripsi rancangan tersedia dalam BM200/BM300. Diagram blok, skema rangkaian, dan gambar desain direncanakan untuk diunggah sebagai berkas terpisah. |
| `protocols/` | Prosedur kalibrasi, pengujian, dan pencatatan data | Rencana verifikasi dan pengujian tersedia dalam BM200/BM300. Penyusunan serta pengunggahan prosedur kerja sebagai dokumen tersendiri direncanakan untuk melengkapi dokumentasi pengujian. |
| `publication/` | Rencana manuskrip, judul sementara, kontribusi, target jurnal, dan jadwal submit | Penyusunan rencana manuskrip, penentuan target jurnal, dan jadwal submit direncanakan sebagai luaran publikasi proyek. Dokumen akan diunggah setelah disusun. |
| `data/` | Data mentah pengujian yang boleh dibagikan dan keterangan satuan | Pengunggahan data mentah beserta keterangan variabel dan satuan direncanakan setelah data tersedia dan diperiksa untuk dibagikan. |
| `results/` | Tabel, grafik, dan ringkasan hasil pengujian aktual | Pengunggahan tabel, grafik, dan ringkasan evaluasi direncanakan setelah data pengujian selesai diolah. Angka target pada dokumen merupakan kriteria perencanaan, bukan hasil pengujian. |

## Implementasi Firmware

Firmware yang diunggah menyediakan pembacaan BMP280, baseline tekanan, mode FREE/HOLD, level berbasis ambang, serta tampilan OLED dan Serial. Perhitungan FVC/PEFR dan integrasi Telegram yang disebut dalam dokumen perencanaan belum diimplementasikan pada kode ini. Jenis board aktual belum dapat dipastikan hanya dari kode sumber.

## Presentasi UTS

[Unduh atau baca presentasi UTS PSB II](presentations/UTS_PSB_II_Smart_Spiroballs.pdf). Berkas terdiri dari 9 halaman. Salinan untuk repositori menggunakan kompresi gambar; teks dan jumlah halaman dipertahankan. Berkas sumber asli tidak diubah.

## Keterangan Dokumentasi

Dokumen disajikan dalam format Markdown hasil ekstraksi teks dari berkas Word. Gambar, tanda tangan, tata letak tabel, dan sebagian format persamaan tidak tercakup dalam versi ini. Bagian CV dan kontak email tidak disertakan.

Dokumen masih berstatus draf dan memuat perbedaan penyebutan komponen: sampul BM100/BM200 menyebut Arduino Uno dan BMP280, sedangkan bagian isi membahas ESP32 dan MPX5010DP. Angka target dan rancangan pengujian dalam dokumen tidak dinyatakan sebagai hasil pengujian aktual. Dokumentasi ini tidak menyatakan bahwa prototipe telah tervalidasi untuk penggunaan klinis.
