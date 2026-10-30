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

## Struktur dan Rencana Dokumentasi Repositori

```text
.
├── README.md
├── docs/
│   ├── BM100.md
│   ├── BM200.md
│   └── BM300.md
├── firmware/       [rencana folder]
├── analysis/       [rencana folder]
├── hardware/       [rencana folder]
├── protocols/      [rencana folder]
├── publication/    [rencana folder]
├── data/           [rencana folder]
└── results/        [rencana folder]
```

Folder bertanda **rencana folder** belum tersedia dalam repositori. Status berikut membedakan bahan yang sudah tersedia dari kelengkapan yang masih direncanakan.

| Bagian | Isi yang direncanakan | Status dan keterangan |
| --- | --- | --- |
| `docs/` | Dokumentasi BM100, BM200, dan BM300 | Tersedia dalam bentuk draf teks Markdown. |
| `firmware/` | Kode program mikrokontroler dan petunjuk penggunaannya | Kode sudah tersedia di lokasi terpisah menurut anggota kelompok, tetapi belum diunggah ke repositori. |
| `analysis/` | Kode pengolahan data dan perhitungan parameter evaluasi | Direncanakan untuk dokumentasi analisis; berkas pengolahan data terpisah belum disertakan. |
| `hardware/` | Diagram blok, skema rangkaian, dan desain perangkat | Deskripsi rancangan terdapat dalam BM200/BM300. Berkas desain dan gambar terpisah belum diunggah; gambar dalam Word tidak tercakup dalam ekstraksi teks. |
| `protocols/` | Prosedur kalibrasi, pengujian, dan pencatatan data | Rencana verifikasi/pengujian tercantum dalam BM200/BM300; belum disajikan sebagai berkas prosedur terpisah. |
| `publication/` | Rencana manuskrip, judul sementara, kontribusi, target jurnal, dan jadwal submit | Bagian dari rencana dokumentasi luaran UTS; berkas khusus publikasi belum disertakan. |
| `data/` | Data mentah pengujian yang boleh dibagikan dan keterangan satuan | Belum ada data pengujian yang diunggah. Ketidaktersediaan data di repo tidak menyatakan bahwa pengujian sudah atau belum dilaksanakan. |
| `results/` | Tabel, grafik, dan ringkasan hasil pengujian aktual | Belum ada berkas hasil yang diunggah. Angka target dalam dokumen perencanaan tidak diperlakukan sebagai hasil pengujian. |

## Keterangan Dokumentasi

Dokumen disajikan dalam format Markdown hasil ekstraksi teks dari berkas Word. Gambar, tanda tangan, tata letak tabel, dan sebagian format persamaan tidak tercakup dalam versi ini. Bagian CV dan kontak email tidak disertakan.

Dokumen masih berstatus draf dan memuat perbedaan penyebutan komponen: sampul BM100/BM200 menyebut Arduino Uno dan BMP280, sedangkan bagian isi membahas ESP32 dan MPX5010DP. Angka target dan rancangan pengujian dalam dokumen tidak dinyatakan sebagai hasil pengujian aktual. Dokumentasi ini tidak menyatakan bahwa prototipe telah tervalidasi untuk penggunaan klinis.
