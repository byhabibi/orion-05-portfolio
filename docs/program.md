# Program

Ini bentuk programnya, supaya terbaca bagaimana controller berpikir. Bukan sumber yang terpasang di mesin. Angka kalibrasi dan ambang internal tidak ditulis di sini.

Bahasanya C++, framework Arduino, dibangun dengan PlatformIO.

## Apa yang operator alami

1. Mesin menyala. Controller menyiapkan sensor, katup, drum, layar, dan suara.
2. Operator mengisi biji, lalu memutar knop. Drum berputar, udara mengalir, gas mengikuti knop.
3. Setiap saat program membaca suhu biji, suhu ruang, dan suhu motor. Lonjakan yang hanya sesaat tidak digambar, supaya kurva tidak penuh garis tegak.
4. Dua suhu yang lolos filter itu dikirim ke layar. Roaster memakai kurva itu untuk menahan atau menaikkan api.
5. Program juga membaca tekanan gas dan sensor gas dari papan kedua.
6. Sebelum perintah knop sampai ke mesin, program menanyakan keselamatan. Selama aman, knop yang menentukan. Kalau tidak aman, gas ditutup atau drum dihentikan, meskipun knop masih terbuka.
7. Tombol di layar memulai dan menghentikan pencatatan kurva. Menekan catat tidak menyalakan gas. Menutup gas tetap lewat knop dan lewat keselamatan.
8. Kalau laptop meminta data, program mengirim suhu yang sama dengan yang ada di layar.

Akhir dari satu siklus ada di mesin, bukan hanya di layar: gas tertutup, biji pindah ke cooling, kurva yang tadi dipakai roaster tetap tersimpan.

## Bagian di dalam program

| Bagian | Tugas |
|---|---|
| Suhu | Baca tiga termokopel dan buang lonjakan singkat |
| Panel | Baca knop dan tombol |
| Aktuator | Ubah perintah jadi bukaan gas, putaran drum, blower, dan cooling |
| Keselamatan | Menentukan bagian mana yang masih boleh hidup |
| Layar | Gambar kurva dan angka. Terima tombol operator |
| Papan sensor | Terima tekanan gas dan kondisi sensor gas |
| Suara | Bunyikan alarm bila keselamatan meminta |
| Catatan | Kirim suhu ke Artisan saat diminta |
| Utama | Mengulang urutan di bawah |

## Urutan di dalam controller

```text
nyala:
  siapkan sensor, aktuator, layar, suara, dan catatan

setiap putaran:
  baca tombol layar dan posisi knop
  baca suhu biji, ruang, dan motor
  baca tekanan gas dan sensor gas
  buang lonjakan suhu yang tidak bertahan
  tentukan status aman atau tidak
  kalau aman, ikuti knop
  kalau tidak aman, tutup gas atau hentikan drum
  gambar kurva dan angka di layar
  bunyikan alarm bila perlu
  kirim suhu bila laptop meminta
```

Keselamatan diperiksa setiap putaran, bukan sekali di awal. Karena itu knop yang masih terbuka tidak bisa menahan gas tetap menyala setelah kondisi bahaya terpenuhi.
