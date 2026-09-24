# Tugas-AKhir-AlPro
Sistem Manajemen Parkir CLI menggunakan bahasa C. Program ini mendukung hingga 100 slot parkir dengan fitur check-in (pencatatan plat &amp; jam masuk), check-out beserta kalkulasi tarif otomatis untuk mobil/motor berdasarkan durasi, serta pemantauan status kendaraan. Proyek ini cocok untuk belajar implementasi array dan struct di C.
# Sistem Manajemen Parkir (CLI)

Sistem Manajemen Parkir sederhana berbasis antarmuka baris perintah (CLI) yang ditulis menggunakan bahasa C. Program ini memungkinkan pengguna untuk mengelola slot parkir, mencatat kendaraan masuk dan keluar, serta menghitung biaya parkir secara otomatis.

## Fitur Utama

- **Kendaraan Masuk (Check-In)**: Mencatat plat nomor, jenis kendaraan (Mobil/Motor), dan jam masuk ke dalam slot yang kosong.
- **Kendaraan Keluar (Check-Out)**: Menghitung durasi parkir dan menampilkan struk pembayaran (Tarif: Mobil Rp5.000/jam, Motor Rp2.000/jam).
- **Tampilkan Daftar Parkir**: Memantau slot parkir yang sedang terisi beserta detail kendaraannya.
- **Kapasitas**: Mendukung hingga 100 slot parkir.

## Prasyarat

Pastikan kamu memiliki *compiler* C yang terinstal di komputermu, seperti **GCC** (GNU Compiler Collection).

## Cara Menjalankan Program

1. *Clone* repository ini atau unduh file `parkir.c`.
2. Buka terminal atau *command prompt* dan arahkan ke direktori tempat file `parkir.c` berada.
3. Kompilasi kode sumber menggunakan GCC dengan perintah:
   ```bash
   gcc parkir.c -o parkir