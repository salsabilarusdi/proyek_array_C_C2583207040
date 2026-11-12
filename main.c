#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAKS 50
#define PANJANG_NAMA 100

// ==========================================
// DEKLARASI ARRAY DAN VARIABEL
// ==========================================

char namaProduk[MAKS][PANJANG_NAMA] = {
    "Spaghetti",
    "Americano",
    "Matcha Latte",
    "Mac n Chees",
    "Jagung Bakar"
};

int harga[MAKS] = {15000, 12000, 5000, 18000, 4000};
int stok[MAKS] = {20, 15, 30, 10, 25};
int jumlahTerjual[MAKS] = {0, 0, 0, 0, 0};
int pendapatanProduk[MAKS] = {0, 0, 0, 0, 0};

int jumlahProduk = 5;
int totalPendapatan = 0;

// ==========================================
// DEKLARASI FUNGSI
// ==========================================

void bersihkanBuffer();
int bacaAngka(char pesan[]);
void tampilkanMenu();
void tampilkanProduk();
void tambahProduk();
void ubahProduk();
void transaksiPenjualan();
void tambahStok();
void cariProduk();
int cariProdukDenganNama(char nama[]);
void urutkanProduk();
void laporanPenjualan();
void cekStokMenipis();

// ==========================================
// FUNGSI MEMBERSIHKAN BUFFER
// ==========================================

void bersihkanBuffer() {
    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}

// ==========================================
// FUNGSI INPUT ANGKA
// ==========================================

int bacaAngka(char pesan[]) {
    int angka;

    while (1) {
        printf("%s", pesan);

        if (scanf("%d", &angka) == 1) {
            bersihkanBuffer();
            return angka;
        }

        printf("Input harus berupa angka!\n");
        bersihkanBuffer();
    }
}

// ==========================================
// MENU UTAMA
// ==========================================

void tampilkanMenu() {
    printf("\n============================================\n");
    printf("     SISTEM MONITORING STOK DAN PENJUALAN\n");
    printf("                 KANTIN KAMPUS\n");
    printf("============================================\n");
    printf("1. Lihat Daftar Produk\n");
    printf("2. Tambah Produk\n");
    printf("3. Ubah Produk\n");
    printf("4. Transaksi Penjualan\n");
    printf("5. Tambah Stok\n");
    printf("6. Cari Produk\n");
    printf("7. Urutkan Produk\n");
    printf("8. Laporan Penjualan\n");
    printf("9. Cek Stok Menipis\n");
    printf("0. Keluar\n");
    printf("============================================\n");
}

// ==========================================
// 1. MENAMPILKAN DAFTAR PRODUK
// ==========================================

void tampilkanProduk() {
    int i;

    printf("\n========== DAFTAR MENU KANTIN ==========\n");

    printf("%-5s %-22s %-15s %-10s\n",
           "No", "Nama Produk", "Harga", "Stok");

    printf("-------------------------------------------------------\n");

    for (i = 0; i < jumlahProduk; i++) {
        printf("%-5d %-22s Rp%-13d %-10d\n",
               i + 1,
               namaProduk[i],
               harga[i],
               stok[i]);
    }

    printf("-------------------------------------------------------\n");
}

// ==========================================
// 2. MENAMBAHKAN PRODUK
// ==========================================

void tambahProduk() {
    char namaBaru[PANJANG_NAMA];
    int hargaBaru, stokBaru;
    int i;

    if (jumlahProduk >= MAKS) {
        printf("\nKapasitas produk sudah mencapai 50 produk!\n");
        return;
    }

    printf("\n========== TAMBAH PRODUK ==========\n");

    printf("Masukkan nama produk: ");
    fgets(namaBaru, PANJANG_NAMA, stdin);

    namaBaru[strcspn(namaBaru, "\n")] = '\0';

    if (strlen(namaBaru) == 0) {
        printf("Nama produk tidak boleh kosong!\n");
        return;
    }

    for (i = 0; i < jumlahProduk; i++) {
        if (strcmp(namaProduk[i], namaBaru) == 0) {
            printf("Nama produk sudah tersedia!\n");
            return;
        }
    }

    hargaBaru = bacaAngka("Masukkan harga produk: Rp");

    if (hargaBaru < 0) {
        printf("Harga tidak boleh negatif!\n");
        return;
    }

    stokBaru = bacaAngka("Masukkan stok produk: ");

    if (stokBaru < 0) {
        printf("Stok tidak boleh negatif!\n");
        return;
    }

    strcpy(namaProduk[jumlahProduk], namaBaru);

    harga[jumlahProduk] = hargaBaru;
    stok[jumlahProduk] = stokBaru;
    jumlahTerjual[jumlahProduk] = 0;
    pendapatanProduk[jumlahProduk] = 0;

    jumlahProduk++;

    printf("\nProduk berhasil ditambahkan!\n");
}

// ==========================================
// 3. MENGUBAH DATA PRODUK
// ==========================================

void ubahProduk() {
    int nomor;
    int hargaBaru, stokBaru;

    tampilkanProduk();

    nomor = bacaAngka("\nMasukkan nomor produk yang akan diubah: ");

    if (nomor < 1 || nomor > jumlahProduk) {
        printf("Nomor produk tidak ditemukan!\n");
        return;
    }

    printf("\nProduk yang dipilih: %s\n", namaProduk[nomor - 1]);

    hargaBaru = bacaAngka("Masukkan harga baru: Rp");

    if (hargaBaru < 0) {
        printf("Harga tidak boleh negatif!\n");
        return;
    }

    stokBaru = bacaAngka("Masukkan stok baru: ");

    if (stokBaru < 0) {
        printf("Stok tidak boleh negatif!\n");
        return;
    }

    harga[nomor - 1] = hargaBaru;
    stok[nomor - 1] = stokBaru;

    printf("\nData produk berhasil diperbarui!\n");
}

// ==========================================
// FUNGSI PENCARIAN NAMA PRODUK
// ==========================================

int cariProdukDenganNama(char nama[]) {
    int i, j;
    char nama1[PANJANG_NAMA];
    char nama2[PANJANG_NAMA];

    strcpy(nama1, nama);

    for (i = 0; nama1[i] != '\0'; i++) {
        nama1[i] = (char)tolower((unsigned char)nama1[i]);
    }

    for (i = 0; i < jumlahProduk; i++) {
        strcpy(nama2, namaProduk[i]);

        for (j = 0; nama2[j] != '\0'; j++) {
            nama2[j] = (char)tolower((unsigned char)nama2[j]);
        }

        if (strstr(nama2, nama1) != NULL) {
            return i;
        }
    }

    return -1;
}

// ==========================================
// 4. TRANSAKSI PENJUALAN
// ==========================================

void transaksiPenjualan() {
    int daftarNomor[MAKS];
    int daftarJumlah[MAKS];
    int daftarSubtotal[MAKS];

    int nomor, jumlah;
    int jumlahItem = 0;
    int total = 0;
    int i, j;
    int totalDipilih;

    printf("\n========== TRANSAKSI PENJUALAN ==========\n");

    while (1) {
        tampilkanProduk();

        nomor = bacaAngka(
            "\nMasukkan nomor produk (0 untuk selesai): ");

        if (nomor == 0) {
            break;
        }

        if (nomor < 1 || nomor > jumlahProduk) {
            printf("Nomor produk tidak ditemukan!\n");
            continue;
        }

        jumlah = bacaAngka("Masukkan jumlah pembelian: ");

        if (jumlah <= 0) {
            printf("Jumlah pembelian harus lebih dari nol!\n");
            continue;
        }

        totalDipilih = jumlah;

        for (i = 0; i < jumlahItem; i++) {
            if (daftarNomor[i] == nomor - 1) {
                totalDipilih += daftarJumlah[i];
            }
        }

        if (totalDipilih > stok[nomor - 1]) {
            printf("\nStok tidak mencukupi!\n");
            printf("Stok tersedia: %d\n", stok[nomor - 1]);
            continue;
        }

        if (jumlahItem >= MAKS) {
            printf("Keranjang transaksi sudah penuh!\n");
            break;
        }

        daftarNomor[jumlahItem] = nomor - 1;
        daftarJumlah[jumlahItem] = jumlah;
        daftarSubtotal[jumlahItem] = harga[nomor - 1] * jumlah;

        total += daftarSubtotal[jumlahItem];
        jumlahItem++;

        printf("Produk berhasil dimasukkan ke keranjang!\n");
        printf("Masukkan produk lainnya atau 0 untuk selesai.\n");
    }

    if (jumlahItem == 0) {
        printf("\nTidak ada transaksi yang diproses.\n");
        return;
    }

    // Menampilkan struk pembelian

    printf("\n============== STRUK PEMBELIAN ==============\n");

    printf("%-22s %-10s %-15s\n",
           "Nama Produk", "Jumlah", "Subtotal");

    printf("------------------------------------------------\n");

    for (i = 0; i < jumlahItem; i++) {
        printf("%-22s %-10d Rp%-13d\n",
               namaProduk[daftarNomor[i]],
               daftarJumlah[i],
               daftarSubtotal[i]);
    }

    printf("------------------------------------------------\n");
    printf("TOTAL PEMBAYARAN: Rp%d\n", total);

    // Memperbarui stok dan jumlah terjual

    for (i = 0; i < jumlahItem; i++) {
        int indeks = daftarNomor[i];

        stok[indeks] -= daftarJumlah[i];

        jumlahTerjual[indeks] += daftarJumlah[i];

        pendapatanProduk[indeks] += daftarSubtotal[i];
    }

    totalPendapatan += total;

    printf("\nTransaksi berhasil!\n");
    printf("Stok produk berhasil diperbarui.\n");
    printf("Jumlah produk terjual berhasil diperbarui.\n");
}

// ==========================================
// 5. MENAMBAHKAN STOK
// ==========================================

void tambahStok() {
    int nomor, tambahan;

    tampilkanProduk();

    nomor = bacaAngka("\nMasukkan nomor produk: ");

    if (nomor < 1 || nomor > jumlahProduk) {
        printf("Nomor produk tidak ditemukan!\n");
        return;
    }

    tambahan = bacaAngka("Masukkan jumlah stok tambahan: ");

    if (tambahan <= 0) {
        printf("Jumlah tambahan harus lebih dari nol!\n");
        return;
    }

    stok[nomor - 1] += tambahan;

    printf("\nStok berhasil ditambahkan!\n");
    printf("Stok sekarang: %d\n", stok[nomor - 1]);
}

// ==========================================
// 6. MENCARI PRODUK
// ==========================================

void cariProduk() {
    char nama[PANJANG_NAMA];
    int hasil;

    printf("\n========== CARI PRODUK ==========\n");

    printf("Masukkan nama produk: ");
    fgets(nama, PANJANG_NAMA, stdin);

    nama[strcspn(nama, "\n")] = '\0';

    if (strlen(nama) == 0) {
        printf("Nama pencarian tidak boleh kosong!\n");
        return;
    }

    hasil = cariProdukDenganNama(nama);

    if (hasil == -1) {
        printf("\nProduk tidak ditemukan!\n");
    } else {
        printf("\nProduk ditemukan!\n");
        printf("Nama Produk : %s\n", namaProduk[hasil]);
        printf("Harga       : Rp%d\n", harga[hasil]);
        printf("Stok        : %d\n", stok[hasil]);
        printf("Terjual     : %d\n", jumlahTerjual[hasil]);
    }
}

// ==========================================
// 7. MENGURUTKAN PRODUK (BUBBLE SORT)
// ==========================================

void urutkanProduk() {
    int pilihan;
    int i, j;
    int tukar;

    int tempHarga;
    int tempStok;
    int tempTerjual;
    int tempPendapatan;

    char tempNama[PANJANG_NAMA];

    printf("\n========== PENGURUTAN PRODUK ==========\n");
    printf("1. Harga dari termurah\n");
    printf("2. Jumlah terjual dari terbanyak\n");

    pilihan = bacaAngka("Pilih jenis pengurutan: ");

    if (pilihan != 1 && pilihan != 2) {
        printf("Pilihan tidak tersedia!\n");
        return;
    }

    for (i = 0; i < jumlahProduk - 1; i++) {
        for (j = 0; j < jumlahProduk - i - 1; j++) {

            tukar = 0;

            if (pilihan == 1 && harga[j] > harga[j + 1]) {
                tukar = 1;
            }

            if (pilihan == 2 &&
                jumlahTerjual[j] < jumlahTerjual[j + 1]) {
                tukar = 1;
            }

            if (tukar) {

                tempHarga = harga[j];
                harga[j] = harga[j + 1];
                harga[j + 1] = tempHarga;

                tempStok = stok[j];
                stok[j] = stok[j + 1];
                stok[j + 1] = tempStok;

                tempTerjual = jumlahTerjual[j];
                jumlahTerjual[j] = jumlahTerjual[j + 1];
                jumlahTerjual[j + 1] = tempTerjual;

                tempPendapatan = pendapatanProduk[j];
                pendapatanProduk[j] = pendapatanProduk[j + 1];
                pendapatanProduk[j + 1] = tempPendapatan;

                strcpy(tempNama, namaProduk[j]);
                strcpy(namaProduk[j], namaProduk[j + 1]);
                strcpy(namaProduk[j + 1], tempNama);
            }
        }
    }

    printf("\nProduk berhasil diurutkan!\n");

    tampilkanProduk();
}

// ==========================================
// 8. LAPORAN PENJUALAN
// ==========================================

void laporanPenjualan() {
    int i;
    int totalUnit = 0;
    int terlaris = 0;

    printf("\n========== LAPORAN PENJUALAN ==========\n");

    printf("%-5s %-22s %-12s %-15s\n",
           "No", "Nama Produk", "Terjual", "Pendapatan");

    printf("---------------------------------------------------------\n");

    for (i = 0; i < jumlahProduk; i++) {

        printf("%-5d %-22s %-12d Rp%-13d\n",
               i + 1,
               namaProduk[i],
               jumlahTerjual[i],
               pendapatanProduk[i]);

        totalUnit += jumlahTerjual[i];

        if (jumlahTerjual[i] > jumlahTerjual[terlaris]) {
            terlaris = i;
        }
    }

    printf("---------------------------------------------------------\n");

    printf("Total Unit Terjual : %d\n", totalUnit);
    printf("Total Pendapatan   : Rp%d\n", totalPendapatan);

    if (totalUnit == 0) {
        printf("Produk Terlaris    : Belum ada penjualan\n");
    } else {
        printf("Produk Terlaris    : %s (%d unit)\n",
               namaProduk[terlaris],
               jumlahTerjual[terlaris]);
    }
}

// ==========================================
// 9. CEK STOK MENIPIS
// ==========================================

void cekStokMenipis() {
    int i;
    int ditemukan = 0;

    printf("\n========== PERINGATAN STOK MENIPIS ==========\n");

    for (i = 0; i < jumlahProduk; i++) {

        if (stok[i] < 5) {

            printf("%s - Stok tersisa: %d\n",
                   namaProduk[i],
                   stok[i]);

            ditemukan = 1;
        }
    }

    if (!ditemukan) {
        printf("Tidak ada produk dengan stok kurang dari 5.\n");
    }
}

// ==========================================
// PROGRAM UTAMA
// ==========================================

int main() {
    int pilihan;

    do {

        tampilkanMenu();

        pilihan = bacaAngka("Masukkan pilihan menu: ");

        switch (pilihan) {

            case 1:
                tampilkanProduk();
                break;

            case 2:
                tambahProduk();
                break;

            case 3:
                ubahProduk();
                break;

            case 4:
                transaksiPenjualan();
                break;

            case 5:
                tambahStok();
                break;

            case 6:
                cariProduk();
                break;

            case 7:
                urutkanProduk();
                break;

            case 8:
                laporanPenjualan();
                break;

            case 9:
                cekStokMenipis();
                break;

            case 0:
                printf("\nTerima kasih telah menggunakan program!\n");
                printf("Program selesai.\n");
                break;

            default:
                printf("\nPilihan menu tidak tersedia!\n");
        }

    } while (pilihan != 0);

    return 0;
}
