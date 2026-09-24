#include <stdio.h>
#include <string.h>

int MAX_PARKING = 100;

typedef struct
{
    char plateNumber[20];
    int type;
    int entryTime;
    int isOccupied;
} ParkingSlot;

void displayMenu();
void checkIn(ParkingSlot *lot, int *currentCount);
void checkOut(ParkingSlot *lot, int *currentCount);
void displayVehicles(ParkingSlot *lot);

int main()
{
    ParkingSlot parkingLot[MAX_PARKING];
    int currentCount = 0;
    int choice;
    for (int i = 0; i < MAX_PARKING; i++)
    {
        parkingLot[i].isOccupied = 0;
    }
    do
    {
        displayMenu();
        printf("Pilih menu: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            checkIn(parkingLot, &currentCount);
            break;
        case 2:
            checkOut(parkingLot, &currentCount);
            break;
        case 3:
            displayVehicles(parkingLot);
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

void displayMenu()
{
    printf("\n=== Sistem Manajemen Parkir ===\n");
    printf("1. Kendaraan Masuk (Check-In)\n");
    printf("2. Kendaraan Keluar (Check-Out)\n");
    printf("3. Tampilkan Daftar Parkir\n");
    printf("4. Keluar\n");
}

void checkIn(ParkingSlot *lot, int *currentCount)
{
    if (*currentCount >= MAX_PARKING)
    {
        printf("\nMaaf, kapasitas parkir penuh!\n");
        return;
    }
    for (int i = 0; i < MAX_PARKING; i++)
    {
        if (lot[i].isOccupied == 0)
        {
            printf("\n--- Form Check-In ---\n");
            printf("Masukkan Plat Nomor (Contoh: B 1234 XYZ): ");
            scanf(" %19[^\n]", lot[i].plateNumber);
            printf("Jenis Kendaraan (1 = Mobil, 2 = Motor): ");
            scanf("%d", &lot[i].type);
            printf("Jam Masuk (0-23): ");
            scanf("%d", &lot[i].entryTime);
            lot[i].isOccupied = 1;
            (*currentCount)++;
            printf("Berhasil! Kendaraan diparkir pada slot ke-%d.\n", i + 1);
            break;
        }
    }
}

void checkOut(ParkingSlot *lot, int *currentCount)
{
    if (*currentCount == 0)
    {
        printf("\nParkiran saat ini kosong.\n");
        return;
    }
    char searchPlate[20];
    printf("\nMasukkan Plat Nomor yang akan keluar: ");
    scanf(" %19[^\n]", searchPlate);
    int found = 0;
    for (int i = 0; i < MAX_PARKING; i++)
    {
        if (lot[i].isOccupied == 1 && strcmp(lot[i].plateNumber, searchPlate) == 0)
        {
            int exitTime, duration, fee;
            printf("Jam Keluar (0-23): ");
            scanf("%d", &exitTime);
            duration = exitTime - lot[i].entryTime;
            if (duration <= 0)
            {
                duration += 24;
            }
            if (lot[i].type == 1)
            {
                fee = duration * 5000;
            }
            else
            {
                fee = duration * 2000;
            }
            printf("\n--- Struk Pembayaran Parkir ---\n");
            printf("Plat Nomor  : %s\n", lot[i].plateNumber);
            printf("Jenis       : %s\n", (lot[i].type == 1) ? "Mobil" : "Motor");
            printf("Durasi      : %d jam\n", duration);
            printf("Total Biaya : Rp %d\n", fee);
            lot[i].isOccupied = 0;
            (*currentCount)--;
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("\nKendaraan dengan plat nomor '%s' tidak ditemukan.\n", searchPlate);
    }
}

void displayVehicles(ParkingSlot *lot)
{
    printf("\n--- Daftar Kendaraan di Area Parkir ---\n");
    int count = 0;
    for (int i = 0; i < MAX_PARKING; i++)
    {
        if (lot[i].isOccupied == 1)
        {
            printf("Slot %03d | Plat: %-12s | Tipe: %-5s | Masuk: %02d:00\n",i + 1,lot[i].plateNumber,lot[i].type == 1 ? "Mobil" : "Motor",lot[i].entryTime);
            count++;
        }
    }
    if (count == 0)
    {
        printf("Area parkir saat ini kosong.\n");
    }
}