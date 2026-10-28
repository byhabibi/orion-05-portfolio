# Program

Bentuk programnya, bukan sumber yang terpasang di mesin. Angka kalibrasi, ambang safety, dan isi tiap fungsi tidak dimuat di sini.

Bahasa yang dipakai C++, di atas framework Arduino, dibangun dengan PlatformIO.

## Bagian

| Bagian | Tugas |
|---|---|
| Suhu | Baca tiga termokopel, buang lonjakan singkat, sisakan angka yang layak digambar |
| Panel | Baca knop dan tombol |
| Aktuator | Ubah perintah jadi katup gas, drum, aliran udara, dan cooling |
| Keselamatan | Putuskan bagian mana yang boleh tetap hidup |
| Layar | Kirim kurva, suhu, dan status. Terima tombol dari HMI |
| Papan sensor | Terima tekanan gas dan pembacaan sensor gas |
| Suara | Bunyikan alarm keselamatan |
| Catatan | Jawab permintaan suhu dari Artisan lewat USB |
| Utama | Menjalankan urutan di bawah, setiap putaran |

## Urutan

```text
nyala:
  siapkan sensor, aktuator, layar, dan catatan

setiap putaran:
  baca layar dan panel
  baca suhu
  baca tekanan dan sensor gas
  rapikan suhu supaya satu lonjakan tidak masuk kurva
  hitung status keselamatan
  kalau aman, ikuti knop untuk gas, drum, dan udara
  kalau tidak aman, matikan bagian yang harus berhenti
  gambar angka dan kurva di HMI
  kirim suhu bila Artisan meminta
```

Keselamatan duduk di atas knop. Perintah operator tidak menembus kondisi yang sudah mematikan burner atau drum.

Yang terlihat di halaman ini cukup untuk membaca susunan kerjanya. Tidak cukup untuk menyalin controller ke mesin lain.
