# proyek_array_C_C2583207040
Aplikasi berbasis bahasa C untuk monitoring stok, pengelolaan produk, transaksi penjualan, dan laporan penjualan kantin kampus dengan penerapan Array, Searching, dan Bubble Sort.
# SISTEM MONITORING STOK DAN PENJUALAN KANTIN KAMPUS

## Identitas Mahasiswa

| Keterangan | Informasi |
|---|---|
| Nama Lengkap | [Salsabila Rusdi] |
| NIM | [C2583207040] |
| Kelas | [PTI3A] |
| Program Studi | Pendidikan Teknologi Informasi |
| Fakultas | Fakultas Keguruan dan Ilmu Pendidikan |
| Universitas | Universitas Muhammadiyah Tasikmalaya |
| Mata Kuliah | Algoritma dan Pemrograman Lanjutan |
| Dosen Pengampu | Taofik Muhammad, M.Kom |
| Tahun Akademik | 2026/2027 Ganjil |

---

## 1. Deskripsi Proyek

**Sistem Monitoring Stok dan Penjualan Kantin Kampus** merupakan aplikasi berbasis console yang dibuat menggunakan bahasa pemrograman C. Program ini dirancang untuk membantu pengelola kantin kampus dalam mengelola data produk, memantau ketersediaan stok, melakukan transaksi penjualan, serta mengetahui laporan pendapatan dan produk yang paling banyak terjual.

Program ini dibuat sebagai bentuk penerapan materi Algoritma dan Pemrograman Lanjutan, khususnya penggunaan array sebagai struktur data utama, percabangan, perulangan, fungsi, pencarian, dan pengurutan.

Seluruh data produk dan transaksi disimpan sementara di dalam memori selama program berjalan. Program tidak menggunakan database maupun file eksternal.

## 2. Tujuan Proyek

Tujuan pembuatan program ini adalah:

1. Mempermudah pengelolaan data produk kantin kampus.
2. Membantu memantau jumlah stok produk yang tersedia.
3. Memproses transaksi pembelian beberapa jenis produk dalam satu transaksi.
4. Menghitung subtotal dan total pembayaran secara otomatis.
5. Memperbarui stok dan jumlah produk terjual setelah transaksi berhasil.
6. Menyediakan laporan penjualan dan informasi produk terlaris.
7. Menerapkan konsep array dan algoritma menggunakan bahasa pemrograman C.

## 3. Fitur Program

Program memiliki beberapa fitur utama sebagai berikut:

| No. | Fitur | Keterangan |
|---|---|---|
| 1 | Lihat Daftar Produk | Menampilkan seluruh nama produk, harga, dan stok. |
| 2 | Tambah Produk | Menambahkan produk baru beserta harga dan stok. |
| 3 | Ubah Produk | Mengubah harga dan stok produk yang tersedia. |
| 4 | Transaksi Penjualan | Memproses pembelian beberapa jenis produk dalam satu transaksi. |
| 5 | Tambah Stok | Menambahkan jumlah stok produk. |
| 6 | Cari Produk | Mencari produk berdasarkan nama atau sebagian nama produk. |
| 7 | Urutkan Produk | Mengurutkan produk berdasarkan harga termurah atau jumlah terjual terbanyak. |
| 8 | Laporan Penjualan | Menampilkan jumlah setiap produk terjual, total unit, pendapatan, dan produk terlaris. |
| 9 | Cek Stok Menipis | Menampilkan produk dengan jumlah stok kurang dari 5. |
| 0 | Keluar | Mengakhiri program. |

## 4. Penerapan Array

Array digunakan sebagai struktur data utama untuk menyimpan dan mengelola informasi produk. Program menggunakan array karakter dua dimensi dan beberapa array satu dimensi.

### A. Array Karakter Dua Dimensi

```c
char namaProduk[MAKS][PANJANG_NAMA] = {
    "Spaghetti",
    "Americano",
    "Matcha Latte",
    "Mac n chees ",
    "Jagung Bakar"
};
```

Array tersebut digunakan untuk menyimpan nama produk. Kapasitas maksimalnya adalah 50 produk dengan panjang maksimal 100 karakter untuk setiap nama produk.

### B. Array Satu Dimensi

```c
int harga[MAKS] = {15000, 12000, 5000, 18000, 4000};
int stok[MAKS] = {20, 15, 30, 10, 25};
int jumlahTerjual[MAKS] = {0, 0, 0, 0, 0};
int pendapatanProduk[MAKS] = {0, 0, 0, 0, 0};
```

Penjelasan penggunaan array:

- `harga[]` digunakan untuk menyimpan harga setiap produk.
- `stok[]` digunakan untuk menyimpan jumlah stok produk.
- `jumlahTerjual[]` digunakan untuk menyimpan jumlah unit produk yang telah terjual.
- `pendapatanProduk[]` digunakan untuk menyimpan total pendapatan dari setiap produk.

### C. Variabel Pengelolaan Data

```c
int jumlahProduk = 5;
int totalPendapatan = 0;
```

- `jumlahProduk` digunakan untuk mengetahui jumlah produk yang sedang tersimpan.
- `totalPendapatan` digunakan untuk menyimpan akumulasi seluruh pendapatan transaksi.

Setiap array menggunakan indeks yang saling berhubungan. Sebagai contoh, indeks ke-0 pada `namaProduk[]`, `harga[]`, dan `stok[]` menunjukkan data produk yang sama.

Kapasitas maksimal array adalah 50 produk sesuai ketentuan tugas proyek.

## 5. Data Produk Awal

Program menyediakan lima produk sebagai data awal, yaitu:

| No. | Nama Produk | Harga | Stok |
|---|---|---:|---:|
| 1 | Spaghetti | Rp15.000 | 20 |
| 2 | Americano | Rp12.000 | 15 |
| 3 | Matcha Latte | Rp5.000 | 30 |
| 4 | Mac n Chees | Rp18.000 | 10 |
| 5 | Jagung Bakar | Rp4.000 | 25 |

Data produk tersebut dapat ditambah, diubah, dan dikelola melalui menu program selama kapasitas belum mencapai 50 produk.

## 6. Penerapan Algoritma dan Konsep Pemrograman

Program menerapkan beberapa konsep algoritma dan pemrograman sebagai berikut:

### A. Percabangan

Menggunakan `if`, `else`, dan `switch` untuk menentukan proses berdasarkan kondisi dan pilihan menu pengguna.

### B. Perulangan

Menggunakan beberapa jenis perulangan:

- `for` untuk menampilkan dan mengolah data produk.
- `while` untuk melakukan input dan transaksi.
- `do-while` untuk menampilkan menu utama secara berulang sampai pengguna memilih keluar.

### C. Fungsi

Program dibagi menjadi beberapa fungsi agar setiap fitur memiliki tugas masing-masing, sehingga kode lebih terstruktur dan mudah dipahami.

### D. Searching (Pencarian)

Pencarian produk dilakukan menggunakan fungsi `strstr()` dan `tolower()` dari library `string.h` dan `ctype.h`.

Pencarian dapat dilakukan menggunakan nama lengkap maupun sebagian nama produk dan tidak membedakan huruf besar atau kecil.

### E. Sorting (Pengurutan)

Pengurutan produk menggunakan algoritma **Bubble Sort** dengan dua pilihan:

1. Mengurutkan harga produk dari termurah.
2. Mengurutkan jumlah produk terjual dari terbanyak.

Ketika proses pengurutan berlangsung, seluruh data produk yang berkaitan ikut ditukar agar informasi nama, harga, stok, jumlah terjual, dan pendapatan tetap sesuai.

### F. Validasi Input

Program menyediakan pemeriksaan input untuk beberapa kondisi, antara lain:

- Input menu harus berupa angka.
- Pilihan menu harus tersedia.
- Nomor produk harus sesuai dengan daftar produk.
- Nama produk tidak boleh kosong.
- Nama produk tidak boleh sama dengan produk yang sudah tersedia.
- Harga dan stok tidak boleh bernilai negatif.
- Jumlah pembelian harus lebih dari nol.
- Pembelian tidak boleh melebihi stok yang tersedia.
- Penambahan produk tidak boleh melebihi kapasitas maksimal array.

## 7. Petunjuk Kompilasi dan Menjalankan Program

### A. Persyaratan

Sebelum menjalankan program, pastikan perangkat telah memiliki:

- Compiler bahasa C, seperti GCC.
- Terminal atau Command Prompt.
- Text editor atau IDE, seperti Visual Studio Code.

### B. Clone Repository

Buka terminal dan jalankan perintah berikut:

```bash
git clone https://github.com/USERNAME/Proyek-Array-C-NIM.git
```

Masuk ke folder proyek:

```bash
cd Proyek-Array-C-NIM
```

Ganti `USERNAME` dan `NIM` sesuai akun GitHub dan NIM masing-masing.

### C. Kompilasi Program

Gunakan perintah berikut untuk mengompilasi program dengan GCC:

```bash
gcc main.c -o kantin
```

### D. Menjalankan Program

Untuk Windows:

```bash
kantin.exe
```

Untuk Linux atau macOS:

```bash
./kantin
```

### E. Penggunaan Program

Setelah program berhasil dijalankan, menu utama akan ditampilkan pada terminal.

```text
============================================
     SISTEM MONITORING STOK DAN PENJUALAN
                 KANTIN KAMPUS
============================================
1. Lihat Daftar Produk
2. Tambah Produk
3. Ubah Produk
4. Transaksi Penjualan
5. Tambah Stok
6. Cari Produk
7. Urutkan Produk
8. Laporan Penjualan
9. Cek Stok Menipis
0. Keluar
============================================
Masukkan pilihan menu:
```

Pengguna dapat memilih fitur dengan memasukkan nomor menu sesuai kebutuhan. Untuk mengakhiri program, masukkan angka `0`.

## 8. Pengujian Program (Tugas 6)

Pengujian dilakukan berdasarkan tujuh skenario yang telah ditentukan dalam instruksi tugas proyek praktikum. Pengujian bertujuan untuk memastikan setiap fitur dapat berjalan sesuai fungsi dan menghasilkan keluaran yang benar.

### Tabel Pengujian Program

| No. | Skenario | Input atau Tindakan | Hasil yang Diharapkan | Bukti |
|---|---|---|---|---|
| 1 | Tambah produk | Masukkan produk baru berupa nama, harga, dan stok. | Produk berhasil ditambahkan dan muncul dalam daftar produk. | Screenshot |
| 2 | Transaksi | Lakukan pembelian beberapa produk dalam satu transaksi. | Subtotal setiap produk dan total pembayaran dihitung dengan benar. | Screenshot |
| 3 | Pembaruan stok | Selesaikan transaksi penjualan. | Stok dan jumlah produk terjual berubah sesuai jumlah pembelian. | Screenshot |
| 4 | Stok tidak cukup | Masukkan jumlah pembelian yang melebihi stok tersedia. | Transaksi ditolak dan stok tetap tidak berubah untuk produk tersebut. | Screenshot |
| 5 | Laporan | Pilih menu laporan penjualan setelah melakukan transaksi. | Total unit, total pendapatan, dan produk terlaris ditampilkan dengan benar. | Screenshot |
| 6 | Pengurutan | Urutkan produk berdasarkan harga dan jumlah penjualan. | Produk ditampilkan sesuai urutan yang ditentukan. | Screenshot |
| 7 | Pencarian dan stok | Cari produk dan periksa produk dengan stok kurang dari 5. | Hasil pencarian dan peringatan stok menipis ditampilkan dengan tepat. | Screenshot |

### Dokumentasi Screenshot Hasil Pengujian

Setiap pengujian didokumentasikan menggunakan tangkapan layar sebagai bukti pelaksanaan pengujian program.

#### 1. Pengujian Tambah Produk

**Langkah pengujian:**
1. Pilih menu `2. Tambah Produk`.
2. Masukkan nama produk baru.
3. Masukkan harga produk.
4. Masukkan stok produk.
5. Periksa hasilnya melalui menu daftar produk.

**Hasil yang diharapkan:** Produk baru berhasil ditambahkan dan muncul dalam daftar produk.

**Bukti Pengujian:**

![UTS-1](UTS-1)

#### 2. Pengujian Transaksi Penjualan

**Langkah pengujian:**
1. Pilih menu `4. Transaksi Penjualan`.
2. Masukkan nomor produk yang ingin dibeli.
3. Masukkan jumlah pembelian.
4. Pilih produk lainnya jika diperlukan.
5. Masukkan angka `0` untuk menyelesaikan transaksi.

**Hasil yang diharapkan:** Program menampilkan struk pembelian, subtotal setiap produk, dan total pembayaran dengan perhitungan yang benar.

**Bukti Pengujian:**

![UTS-2](UTS-2)

#### 3. Pengujian Pembaruan Stok

**Langkah pengujian:**
1. Catat jumlah stok awal produk.
2. Lakukan transaksi pembelian.
3. Pilih menu `1. Lihat Daftar Produk`.
4. Pilih menu `8. Laporan Penjualan`.

**Hasil yang diharapkan:** Stok produk berkurang sesuai jumlah pembelian, sedangkan jumlah produk terjual dan pendapatan produk bertambah.

**Bukti Pengujian:**

![UTS-03](UTS-O3)

#### 4. Pengujian Stok Tidak Mencukupi

**Langkah pengujian:**
1. Pilih menu `4. Transaksi Penjualan`.
2. Pilih salah satu produk.
3. Masukkan jumlah pembelian yang melebihi stok tersedia.

**Hasil yang diharapkan:** Program menampilkan pesan bahwa stok tidak mencukupi dan menolak produk tersebut dari keranjang transaksi. Stok produk tetap tidak berubah akibat pembelian yang ditolak.

**Bukti Pengujian:**

![UTS-4](UTS-4)

#### 5. Pengujian Laporan Penjualan

**Langkah pengujian:**
1. Lakukan beberapa transaksi penjualan.
2. Pilih menu `8. Laporan Penjualan`.
3. Periksa jumlah produk terjual dan total pendapatan.

**Hasil yang diharapkan:** Program menampilkan jumlah setiap produk yang terjual, total unit terjual, total pendapatan, dan produk terlaris berdasarkan jumlah unit penjualan.

**Bukti Pengujian:**

![UTS-5](UTS-5)

#### 6. Pengujian Pengurutan Produk

**Langkah pengujian:**
1. Pilih menu `7. Urutkan Produk`.
2. Pilih angka `1` untuk mengurutkan harga dari termurah.
3. Jalankan kembali fitur pengurutan.
4. Pilih angka `2` untuk mengurutkan jumlah terjual dari terbanyak.

**Hasil yang diharapkan:** Produk berhasil diurutkan sesuai pilihan menggunakan algoritma Bubble Sort.

**Bukti Pengujian:**

![UTS-6](UTS-6)

#### 7. Pengujian Pencarian Produk dan Pengecekan Stok

**Langkah pengujian:**

**A. Pencarian Produk**
1. Pilih menu `6. Cari Produk`.
2. Masukkan nama atau sebagian nama produk.
3. Periksa informasi produk yang ditampilkan.

**B. Pengecekan Stok**
1. Pastikan terdapat produk dengan stok kurang dari 5.
2. Pilih menu `9. Cek Stok Menipis`.
3. Periksa produk yang ditampilkan.

**Hasil yang diharapkan:** Program dapat menemukan produk berdasarkan nama dan menampilkan produk dengan stok kurang dari 5.

**Bukti Pengujian:**

![UTS-8](UTS-8)

## 9. Struktur Repository GitHub

Repository proyek disusun dengan struktur direktori sebagai berikut:

```text
Proyek-Array-C-NIM/
│
├── main.c
├── README.md
│
└── screenshots/
    ├── 01-tambah-produk.png
    ├── 02-transaksi-penjualan.png
    ├── 03-pembaruan-stok.png
    ├── 04-stok-tidak-cukup.png
    ├── 05-laporan-penjualan.png
    ├── 06-pengurutan-produk.png
    └── 07-pencarian-dan-stok.png
```

Keterangan:

- `main.c` merupakan file source code utama program.
- `README.md` merupakan dokumentasi proyek yang menjelaskan identitas, deskripsi, fitur, penerapan array, petunjuk penggunaan, dan hasil pengujian.
- `screenshots/` merupakan folder untuk menyimpan seluruh bukti tangkapan layar pengujian program.

## 10. Kesimpulan

Sistem Monitoring Stok dan Penjualan Kantin Kampus merupakan aplikasi berbasis console yang dibuat menggunakan bahasa pemrograman C untuk membantu pengelolaan data produk dan transaksi penjualan kantin.

Program ini menerapkan array satu dimensi dan array karakter dua dimensi sebagai struktur data utama, serta menggunakan konsep percabangan, perulangan, fungsi, pencarian, dan pengurutan.

Melalui fitur-fitur yang tersedia, pengguna dapat mengelola produk, memantau stok, melakukan transaksi penjualan, dan melihat laporan pendapatan serta produk terlaris.

Dengan adanya program ini, proses pengelolaan stok dan penjualan kantin diharapkan dapat dilakukan secara lebih mudah, terstruktur, dan sistematis.

---

**Mata Kuliah:** Algoritma dan Pemrograman Lanjutan  
**Dosen Pengampu:** Taofik Muhammad, M.Kom  
**Program Studi:** Pendidikan Teknologi Informasi  
**Universitas Muhammadiyah Tasikmalaya**  
**Tahun Akademik:** 2026/2027 Ganjil
