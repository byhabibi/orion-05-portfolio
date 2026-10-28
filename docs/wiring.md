# Wiring

Sambungan antar bagian. Cukup untuk mengikuti alur mesin, bukan untuk merakit ulang.

```text
termokopel biji ──┐
termokopel ruang ─┼── ESP32 ── layar HMI
termokopel motor ─┘     │
                        ├── katup gas
knop panel ─────────────┤
                        ├── drum
papan sensor ───────────┤
  tekanan gas           ├── blower udara
  sensor gas            └── bak cooling
                        │
laptop (Artisan) ───────┘
```

## Peran tiap bagian

ESP32 adalah otak. Tiga termokopel tipe K masuk ke situ: suhu biji, suhu ruang di dalam drum, dan suhu motor. Angka biji dan angka ruang yang tampil di layar berasal dari dua sensor pertama.

Knop di panel juga masuk ke ESP32. Putaran knop menjadi perintah untuk katup gas, kecepatan drum, dan blower.

Tekanan gas dan sensor gas duduk di papan lain. Papan itu mengukur, lalu mengirim hasilnya ke ESP32. ESP32 tidak mengukur dua sensor itu sendiri.

Layar HMI dua arah. ESP32 mengirim suhu, kurva, dan status. Layar mengirim tombol yang ditekan operator, misalnya mulai mencatat sangrai atau berhenti.

Laptop hanya menerima suhu lewat USB supaya kurva yang sama bisa disimpan di Artisan. Knop di mesin tetap yang mengatur api, drum, dan udara.

Listrik pemanas dan rangkaian controller dipisah. Tegangan mesin tidak masuk ke kaki controller.

## Saat satu sangrai berjalan

1. Biji ada di dalam drum. Operator menyalakan drum dan blower, lalu membuka gas lewat knop.
2. Termokopel melaporkan panas biji dan panas ruang. ESP32 menampilkan keduanya sebagai kurva.
3. Blower menarik udara, sekaligus membawa kulit kering yang terlepas dari biji keluar dari drum.
4. Kalau sensor gas atau suhu motor melaporkan kondisi yang tidak aman, ESP32 menutup jalur gas dan, bila perlu, menghentikan drum.
5. Di akhir, operator menutup gas. Biji keluar dari drum ke bak cooling. Kurva di layar tetap ada, dan salinannya bisa tersimpan di laptop.
