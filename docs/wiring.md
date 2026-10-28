# Wiring

Gambaran sambungan. Bukan gambar kabel, bukan nomor pin, dan bukan daftar komponen.

```text
termokopel biji ──┐
termokopel ruang ─┼── ESP32 ── HMI
termokopel motor ─┘     │
                        ├── katup gas
knop panel ─────────────┤
                        ├── drum
papan sensor ───────────┤
  tekanan gas           ├── aliran udara
  sensor gas            └── cooling
                        │
laptop (Artisan) ───────┘
```

## Yang disambungkan

Controller-nya ESP32. Tiga termokopel tipe K masuk ke ESP32: suhu biji, suhu ruang sangrai, dan suhu motor.

Knop di panel masuk ke ESP32. Dari situ ESP32 mengatur katup gas, putaran drum, aliran udara, dan cooling.

Tekanan gas dan sensor gas tidak dibaca ESP32 langsung. Keduanya masuk ke papan kedua, lalu papan itu mengirim satu paket data ke ESP32.

HMI adalah layar sentuh. ESP32 mengirim angka dan kurva. Layar mengirim tombol yang ditekan operator.

Laptop hanya mendengarkan suhu lewat USB, untuk dicatat di Artisan. Laptop tidak menggantikan knop panel.

Listrik mesin dan rangkaian controller dipisah. Tegangan mesin tidak masuk ke pin controller.
