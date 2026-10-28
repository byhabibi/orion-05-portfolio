# Orion 05

Orion 05 adalah mesin sangrai cocoa berbahan bakar gas. Biji dipanaskan di dalam drum, lalu didinginkan. Rasa yang keluar bergantung pada suhu dan waktu yang bisa dilihat serta diatur.

Saya mengembangkan sensor dan controllernya.

## Mesin

Di HMI, roaster melihat kurva suhu biji dan suhu ruang di dalam mesin. Dua angka itu menjadi acuan untuk menahan panas, menaikkan api, atau mengakhiri sangrai saat cita rasa yang dicari sudah terbentuk.

Aliran udara dari blower sentrifugal menarik husk, kulit kering yang terurai saat cocoa dipanaskan, supaya isi drum tetap bersih. Suhu dan putaran drum bisa diatur, jadi proses sangrai berjalan terkontrol.

## Kontrol

- ESP32 menjalankan controller
- Termokopel tipe K membaca suhu biji, suhu ruang, dan suhu motor
- HMI layar sentuh menampilkan kurva, waktu, dan status keselamatan
- Knop burner menggerakkan katup gas
- Suhu motor yang terlalu tinggi dapat menghentikan drum
- Sensor gas dapat mematikan burner
- Papan kedua membaca tekanan gas dan sensor gas
- Suhu sangrai dicatat ke Artisan lewat USB

## Yang saya kerjakan

Pengembangan sensor dan controller, lalu commissioning di mesin bersama tim.

Termokopel saya evaluasi pada mesin yang sedang berjalan, sampai kurva suhu layak dipakai sebagai acuan. Firmware menggambar kurva itu di HMI dan menghubungkan knop burner ke katup gas. Gangguan alarm gas dan pembacaan tekanan saya telusuri sampai ke jalur sensor.

## Teknologi

ESP32, PlatformIO, framework Arduino, termokopel, HMI Nextion, pencatatan data lewat USB.

Cara bagian-bagian itu tersambung, dan apa yang terjadi dari biji masuk sampai cooling, ada di [docs/wiring.md](docs/wiring.md). Cara program mengulang keputusan itu ada di [docs/program.md](docs/program.md).

## Batas repo ini

Ini halaman portfolio. Yang ada gambaran fungsi, bukan sumber produksi. Tidak ada schematic, BOM, harga, nomor pin, atau parameter proses. Halaman ini tidak cukup untuk membangun ulang mesin.
