#include <ctype.h>
#include <stdio.h>
#include <string.h>

int const isiparkiran = 100;

typedef struct {
    char plat[20];
    int tipe;
    int masuk;
    int terisi;
} tempatparkir;

void display();
void masuk(tempatparkir* area, int* hitung);
void keluar(tempatparkir* area, int* hitung);
void kendaraan(tempatparkir* area);

int main() {
    tempatparkir parkiran[isiparkiran];
    int mulai = 0;
    int choice;
    for (int i = 0; i < isiparkiran; i++) {
        parkiran[i].terisi = 0;
    }
    do {
        display();
        printf("Pilih menu: ");
        if (scanf("%d", &choice) != 1) {
            printf("Input tidak valid. Silakan masukkan angka.\n");
            while (getchar() != '\n'); // Membersihkan buffer input
            continue;
        }
        switch (choice) {
            case 1:
                masuk(parkiran, &mulai);
                break;
            case 2:
                keluar(parkiran, &mulai);
                break;
            case 3:
                kendaraan(parkiran);
                break;
            case 4:
                printf("\nKeluar dari sistem. Terima kasih!\n");
                break;
            default:
                printf("\nPilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 4);
    return 0;
}

void display() {
    printf("\n=== Sistem Manajemen Parkir ===\n");
    printf("1. Kendaraan Masuk (Check-In)\n");
    printf("2. Kendaraan Keluar (Check-Out)\n");
    printf("3. Tampilkan Daftar Parkir\n");
    printf("4. Keluar\n");
}

void masuk(tempatparkir* area, int* hitung) {
    if (*hitung >= isiparkiran) {
        printf("\nMaaf, kapasitas parkir penuh!\n");
        return;
    }
    for (int i = 0; i < isiparkiran; i++) {
        if (area[i].terisi == 0) {
            printf("\n--- Formulir Masuk ---\n");
            printf("Masukkan Plat Nomor (Contoh: B 1234 XYZ): ");
            scanf(" %19[^\n]", area[i].plat);
            for (int j = 0; area[i].plat[j] != '\0'; j++) {
                area[i].plat[j] = toupper(area[i].plat[j]);
            }
            printf("Jenis Kendaraan (1 = Mobil, 2 = Motor): ");
            scanf("%d", &area[i].tipe);
            printf("Jam Masuk (0-23): ");
            scanf("%d", &area[i].masuk);
            area[i].terisi = 1;
            (*hitung)++;
            printf("Berhasil! Kendaraan diparkir pada slot ke-%d.\n", i + 1);
            break;
        }
    }
}

void keluar(tempatparkir* area, int* hitung) {
    if (*hitung == 0) {
        printf("\nParkiran saat ini kosong.\n");
        return;
    }
    char cariplat[20];
    printf("\nMasukkan Plat Nomor yang akan keluar: ");
    scanf(" %19[^\n]", cariplat);
    while (getchar() != '\n');
    for(int j=0; cariplat[j] != '\0'; j++) {
        cariplat[j] = toupper(cariplat[j] != '\0');
    }
    int found = 0;
    for (int i = 0; i < isiparkiran; i++) {
        if (area[i].terisi == 1 && strcmp(area[i].plat, cariplat) == 0) {
            int exitTime, duration, fee;
            printf("Jam Keluar (0-23): ");
            scanf("%d", &exitTime);
            duration = exitTime - area[i].masuk;
            if (duration <= 0) {
                duration += 24;
            }
            if (area[i].tipe == 1) {
                fee = duration * 5000;
            } else {
                fee = duration * 2000;
            }
            printf("\n--- Struk Pembayaran Parkir ---\n");
            printf("Plat Nomor  : %s\n", area[i].plat);
            printf("Jenis       : %s\n",(area[i].tipe == 1) ? "Mobil" : "Motor");
            printf("Durasi      : %d jam\n", duration);
            printf("Total Biaya : Rp %d\n", fee);
            area[i].terisi = 0;
            (*hitung)--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nKendaraan dengan plat nomor '%s' tidak ditemukan.\n",cariplat);
    }
}

void kendaraan(tempatparkir* area) {
    printf("\n--- Daftar Kendaraan di Area Parkir ---\n");
    int count = 0;
    for (int i = 0; i < isiparkiran; i++) {
        if (area[i].terisi == 1) {
            printf("Slot %03d | Plat: %-12s | Tipe: %-5s | Masuk: %02d:00\n",
                    i + 1, area[i].plat, area[i].tipe == 1 ? "Mobil" : "Motor",
                    area[i].masuk);
            count++;
        }
    }
    if (count == 0) {
        printf("Area parkir saat ini kosong.\n");
    }
}