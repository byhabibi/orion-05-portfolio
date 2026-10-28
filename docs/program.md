# Cara kerja

Controller mengulang satu putaran. Di dalam putaran itu ada beberapa keadaan sangrai. Angka kalibrasi tidak ditulis di sini. Potongan program utamanya ada di [firmware/main.cpp](../firmware/main.cpp). Isi modul sensor, katup, dan layar tidak disertakan.

## Keadaan yang dilihat operator

**Siaga.** Suhu tetap tampil. Kurva belum berjalan. Knop hanya sampai ke mesin bila pemeriksaan keselamatan mengizinkan.

**Pemanasan.** Layar pindah ke halaman pemanasan dan menghitung waktu. Suhu ruang dipantau. Setelah ruang cukup panas dan bertahan sebentar, layar kembali ke halaman sangrai. Pemanasan tidak sama dengan mulai mencatat kurva.

**Mencatat.** Tombol mulai di layar mengosongkan kurva, menjalankan timer, dan mulai menambah titik. Sekali dalam satu detik program menyimpan suhu biji dan suhu ruang, menghitung laju naik suhu, lalu menggambar satu titik. Gas, drum, dan udara tetap mengikuti knop.

**Berhenti.** Timer dan kurva diam di tempat. Tombol ini tidak membuka gas. Menutup gas tetap lewat knop, atau lewat keselamatan bila kondisi tidak aman.

**Reset.** Kurva, timer, dan laju suhu dikosongkan. Mesin kembali ke tampilan siaga.

**Tidak aman.** Pemeriksaan ini jalan setiap putaran, bukan sekali di awal. Kebocoran gas menutup burner dan membunyikan alarm. Tekanan gas yang tidak memenuhi syarat ikut menahan gas. Suhu motor yang terlalu tinggi dapat menghentikan drum. Suhu biji yang melewati batas mematikan burner. Tombol darurat menutup keluaran berbahaya. Knop yang masih terbuka tidak bisa menahan gas tetap menyala setelah syarat itu gagal.

**Akhir fisik.** Gas sudah tertutup, biji pindah ke bak cooling, cooling menyala dari panel. Kurva yang dipakai roaster tetap di layar sampai reset, dan bisa disalin ke laptop.

## Bagian program

| Bagian | Tugas | Ada di repo ini |
|---|---|---|
| Utama | Menjalankan urutan di bawah | Ya, potongan `main` |
| Suhu | Tiga termokopel, buang lonjakan singkat | Tidak |
| Panel | Knop, tombol, putaran drum | Tidak |
| Papan sensor | Tekanan gas dan sensor gas | Tidak |
| Aktuator | Servo katup, kecepatan drum dan blower, cooling | Tidak |
| Keselamatan | Memutuskan keluaran mana yang masih boleh hidup | Tidak |
| Layar | Kurva, angka, tombol | Tidak |
| Suara | Alarm saat keselamatan meminta | Tidak |
| Catatan | Jawab permintaan suhu dari Artisan | Tidak |

## Urutan di dalam controller

```text
nyala:
  siapkan jalur panel, sensor, katup, layar, suara, catatan

setiap putaran:
  baca tombol layar
  baca permintaan laptop
  baca baris dari papan sensor
  gerakkan servo sedikit menuju posisi knop
  kalau mulai: kosongkan kurva dan jalankan timer
  kalau berhenti: tahan kurva
  kalau reset: kosongkan kurva dan timer
  baca suhu biji, ruang, dan motor
  buang lonjakan yang tidak bertahan
  baca knop
  periksa aman atau tidak
  kalau aman, ikuti knop
  kalau tidak aman, tutup gas atau hentikan drum
  sekali per detik, saat sedang mencatat: tambah titik kurva dan laju suhu
  gambar angka di layar
  bunyikan alarm bila perlu
  kirim suhu bila laptop meminta
```
