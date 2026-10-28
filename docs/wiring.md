# Wiring

Sambungan antar bagian. Cukup untuk mengikuti sinyal utama, bukan untuk merakit ulang.

```text
termokopel biji  ── SPI ──┐
termokopel ruang ── SPI ──┼── ESP32 ── serial ── layar HMI
termokopel motor ── SPI ──┘     │
                                ├── servo ──────── katup gas
knop dan tombol ── analog/digital┤
                                ├── perintah kecepatan ── drum
papan sensor ── serial ─────────┤
  tekanan gas                   ├── perintah kecepatan ── blower
  sensor gas                    └── on/off ────────────── bak cooling
                                │
laptop (Artisan) ── USB ────────┘
```

## Jenis sinyal

Tiga termokopel tipe K masuk ke antarmuka di papan controller, lalu dibaca ESP32 lewat SPI. Tiga saluran itu terpisah: suhu biji, suhu ruang di dalam drum, dan suhu motor. Yang digambar sebagai kurva hanya dua yang pertama. Suhu motor dipakai untuk menjaga drum.

Knop burner, udara, dan drum adalah tegangan analog. ESP32 mengubahnya menjadi persen. Tombol panel (drum, udara, burner, cooling, pompa, darurat) masuk sebagai sinyal digital.

Perintah burner tidak langsung menyalakan api. Persen knop menjadi posisi servo pada katup gas. Servo bergerak bertahap menuju posisi itu, tidak meloncat.

Drum dan blower menerima perintah kecepatan. Bak cooling dan pompa hanya hidup atau mati.

Tekanan gas dan sensor gas tidak diukur ESP32. Keduanya duduk di papan kedua. Papan itu mengirim satu baris data ke ESP32 lewat serial. Selama baris itu tidak datang, controller menganggap tekanan dan gas tidak ada, bukan mengarang angka.

Layar HMI juga serial, dua arah. ESP32 mengirim suhu, kurva, timer, dan status. Layar mengirim tombol: mulai catat, berhenti, reset, ganti satuan, dan masuk halaman pemanasan.

Laptop tersambung ke USB controller. Artisan hanya meminta suhu. Knop di panel tetap yang menggerakkan katup, drum, dan udara.

Listrik katup, drum, dan blower tidak masuk ke kaki ESP32. Controller hanya mengirim sinyal.

## Saat satu sangrai berjalan

1. Biji ada di dalam drum. Operator menyalakan drum dan blower, lalu membuka gas lewat knop. Servo mengikuti knop dan membuka katup.
2. Tiga termokopel dibaca terus. Suhu biji dan suhu ruang menjadi kurva. Suhu motor diawasi di belakang.
3. Blower menarik udara dan membawa kulit kering keluar dari drum. Persen udara yang tampil di layar mengikuti knop.
4. Papan kedua melaporkan tekanan dan kondisi gas. Kalau laporan itu, atau suhu motor, atau tombol darurat, menyatakan tidak aman, ESP32 menutup katup. Drum bisa ikut berhenti.
5. Di akhir, operator menutup knop gas. Katup ikut tertutup. Biji keluar dari drum ke bak cooling, dan cooling dinyalakan dari panel. Kurva di layar tetap ada sampai di-reset. Salinannya bisa tersimpan di laptop.
