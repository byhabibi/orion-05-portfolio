# Orion 05

Orion 05 adalah mesin roasting cocoa berbahan bakar gas. Biji dipanaskan di dalam drum, lalu didinginkan. Rasa yang keluar bergantung pada suhu dan waktu yang bisa dilihat serta diatur.

Saya mengembangkan sensor dan controllernya.

## Mesin

Di HMI, roaster melihat kurva suhu biji dan suhu ruang di dalam mesin. Dua angka itu menjadi acuan untuk menahan panas, menaikkan api, atau mengakhiri roasting saat cita rasa yang dicari sudah terbentuk.

Aliran udara dari blower sentrifugal menarik husk, kulit kering yang terurai saat cocoa dipanaskan, supaya isi drum tetap bersih. Suhu dan putaran drum bisa diatur, jadi proses roasting berjalan terkontrol.

## Kontrol

- ESP32 menjalankan controller
- Termokopel tipe K membaca suhu biji, suhu ruang, dan suhu motor
- HMI layar sentuh menampilkan kurva, waktu, dan status keselamatan
- Knop burner menggerakkan katup gas
- Suhu motor yang terlalu tinggi dapat menghentikan drum
- Sensor gas dapat mematikan burner
- Papan kedua membaca tekanan gas dan sensor gas
- Suhu roasting dicatat ke Artisan lewat USB

## Yang saya kerjakan

Pengembangan sensor dan controller, lalu commissioning di mesin bersama tim.

Termokopel saya evaluasi pada mesin yang sedang berjalan, sampai kurva suhu layak dipakai sebagai acuan. Firmware menggambar kurva itu di HMI dan menghubungkan knop burner ke katup gas. Gangguan alarm gas dan pembacaan tekanan saya telusuri sampai ke jalur sensor.

## Teknologi

ESP32, PlatformIO, framework Arduino, termokopel, HMI Nextion, pencatatan data lewat USB.

Sambungan dan jenis sinyalnya ada di [docs/wiring.md](docs/wiring.md). Keadaan roasting, dari siaga sampai cooling, ada di [docs/program.md](docs/program.md). Kerangka program utamanya ada di [firmware/main.cpp](firmware/main.cpp).

## Batas repo ini

Ini halaman portfolio. Yang bisa dibaca hanya alur utama dan potongan `main`. Modul sensor, katup, layar, schematic, BOM, harga, nomor pin, dan parameter proses tidak ada. Halaman ini tidak cukup untuk membangun ulang mesin.
