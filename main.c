#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <tuple>

//ini struct buat akun
struct akun{
    char nama[50];
    char password[20];
};
//ini array buat nampung akun
//"user" akun bawaan aja biar ga ribet:v
struct akun AkunBaru[50] = {
    {"user","user"}
};

int adaAkun = 1;

//sama kayak di atas
struct menuMakanan {
    char namaMenu[50];
    int harga;
};
struct menuMakanan menuMakan[100];

//sama aja kayak di atas
struct strukHarga{
    char namaMenu[50];
    int jumlah;
    int harga;
};
struct strukHarga strukPembelian[100];

int maxIndexMenu;
int jumlahAwalMenu = 20;

//manggil ulang
void buatAkun();
int login_menu();

//tanda kalo functionnya returnnya itu pointer
//karena kalo array masuk ke parameter itu sebenernya yg di masukin pointernya jadi ga bisa langsung di return
//makanya functionnya ada tanda * yg berarti itu function yang bentuk returnnya pointer
char * lower(char str[100]){
    for(int i = 0; i < strlen(str);i++){
        str[i] = tolower(str[i]);
    }
    return str;
}

int search(char barang[50]){
    barang = lower(barang);
    char perbandingan [50];
    for(int i = 0; i < maxIndexMenu;i++){
        //strcpy itu string copy soalnya string ga bisa langsung di copy harus make strcpy yg awal itu variable tempatnya yg kedua target copynya
        strcpy(perbandingan, menuMakan[i].namaMenu);
        //strcmp itu buat compare returnnya itu integer kalo integernya 0 berarti sama yg di compare
        if(strcmp(lower(perbandingan),barang) == 0){
            return i;
        }
    }
    return -1;
}

void tambahMenu() {
    char menuBaru[50];
    int harga;
    printf("\nMasukkan nama menu : ");
    gets(menuBaru);
    printf("Masukkan harga menu : ");
    scanf("%d", &harga);

    int index = search(menuBaru);
    if(index == -1){
        strcpy(menuMakan[maxIndexMenu].namaMenu,menuBaru);
        menuMakan[maxIndexMenu].harga = harga;

        printf("\nBarang berhasil ditambahkan!\n");
        maxIndexMenu++;
        system("pause");
        getchar();
    }else{
        printf("Menu sudah ada\n");
        system("pause");
    }
}

void inisialisasiMenu() {
    char* daftarMenu[] = {
        "Nasi Goreng", "Ayam Goreng", "Soto Ayam", "Bakso", "Mie Goreng",
        "Rendang", "Gado-Gado", "Nasi Uduk", "Sate Ayam", "Pecel Lele",
        "Sayur Asem", "Capcay", "Tahu Tempe", "Nasi Kuning", "Lontong Sayur",
        "Rawon", "Gudeg", "Sop Buntut", "Ikan Bakar", "Kari Ayam"
    };
    int daftarHarga[] = {
        15000, 17000, 14000, 13000, 15000,
        20000, 12000, 13000, 18000, 14000,
        10000, 12000, 8000, 13000, 14000,
        16000, 15000, 25000, 18000, 16000
    };

    for (int i = 0; i < jumlahAwalMenu; i++) {
        strcpy(menuMakan[i].namaMenu, daftarMenu[i]);
        menuMakan[i].harga = daftarHarga[i];
    }
    maxIndexMenu = jumlahAwalMenu;
}

void tampilkanMenu(char* namaWarung) {
    printf("=== Selamat Datang di %s ===\n", namaWarung);
    printf("Daftar Menu:\n");
    for (int i = 0; i < maxIndexMenu; i++) {
        printf("%2d. %-25s Rp %d\n", i + 1, menuMakan[i].namaMenu, menuMakan[i].harga);
    }
    printf("\n");
}

void kalkulasi()
{
    system("cls");
    int kode, jumlah;
    char ulang;
    int total = 0, subtotal;

    do
    {
        system("cls");
        printf("=== Selamat Datang di Rumah Makan FUFUFAFA ===\n");
        printf("Daftar Menu:\n");
        printf("1. Nasi Goreng     - Rp 15000\n");
        printf("2. Ayam Goreng     - Rp 17000\n");
        printf("3. Soto Ayam       - Rp 14000\n");
        printf("4. Bakso           - Rp 13000\n");
        printf("5. Mie Goreng      - Rp 15000\n");
        printf("6. Rendang         - Rp 20000\n");
        printf("7. Gado-Gado       - Rp 12000\n");
        printf("8. Nasi Uduk       - Rp 13000\n");
        printf("9. Sate Ayam       - Rp 18000\n");
        printf("10. Pecel Lele     - Rp 14000\n");
        printf("11. Sayur Asem     - Rp 10000\n");
        printf("12. Capcay         - Rp 12000\n");
        printf("13. Tahu Tempe     - Rp 8000\n");
        printf("14. Nasi Kuning    - Rp 13000\n");
        printf("15. Lontong Sayur  - Rp 14000\n");
        printf("16. Rawon          - Rp 16000\n");
        printf("17. Gudeg          - Rp 15000\n");
        printf("18. Sop Buntut     - Rp 25000\n");
        printf("19. Ikan Bakar     - Rp 18000\n");
        printf("20. Kari Ayam      - Rp 16000\n");

        printf("\nMasukkan kode menu (1-20): ");
        scanf("%d", &kode);
        printf("Jumlah porsi: ");
        scanf("%d", &jumlah);

        // Menentukan harga berdasarkan kode
        int harga = 0;
        switch(kode)
        {
        case 1:
            harga = 15000;
            break;
        case 2:
            harga = 17000;
            break;
        case 3:
            harga = 14000;
            break;
        case 4:
            harga = 13000;
            break;
        case 5:
            harga = 15000;
            break;
        case 6:
            harga = 20000;
            break;
        case 7:
            harga = 12000;
            break;
        case 8:
            harga = 13000;
            break;
        case 9:
            harga = 18000;
            break;
        case 10:
            harga = 14000;
            break;
        case 11:
            harga = 10000;
            break;
        case 12:
            harga = 12000;
            break;
        case 13:
            harga = 8000;
            break;
        case 14:
            harga = 13000;
            break;
        case 15:
            harga = 14000;
            break;
        case 16:
            harga = 16000;
            break;
        case 17:
            harga = 15000;
            break;
        case 18:
            harga = 25000;
            break;
        case 19:
            harga = 18000;
            break;
        case 20:
            harga = 16000;
            break;
        default:
            printf("Kode tidak valid!\n");
            continue;
        }

        subtotal = harga * jumlah;
        total += subtotal;
        printf("Subtotal: Rp %d\n", subtotal);

        printf("Apakah ingin memesan lagi? (y/n): ");
        scanf(" %c", &ulang);
    }
    while (ulang == 'y' || ulang == 'Y');

    printf("\nTotal yang harus dibayar: Rp %d\n", total);
    printf("Terima kasih telah berkunjung!\n");
}

int login() {
    int loginStatus;
    char coba;
    do {
        system("cls");
        printf("=== LOGIN ===\n");
        char inputNama[50];
        char inputPw[20];

        printf("Masukkan nama pengguna: ");
        scanf("%s", inputNama);
        getchar();

        printf("Masukkan password: ");
        scanf("%s", inputPw);
        getchar();

        for (int i = 0; i < adaAkun; i++) {
            if (strcmp(AkunBaru[i].nama, inputNama) == 0 && strcmp(AkunBaru[i].password, inputPw) == 0) {
                printf("Login berhasil! Selamat datang, %s!\n", AkunBaru[i].nama);
                system("pause");

                loginStatus = 1;
                return(loginStatus);
            }
        }
        printf("Nama pengguna atau password salah!\n");
        do {
            printf("Apakah ingin mecoba login kembali? y/n\n");
            scanf("%c", &coba);
        }while (coba != 'y' && coba != 'n');
    }while (coba != 'n');
    loginStatus = 0;
    return (loginStatus);
}

void buatAkun(){
    system("cls");
    printf("=== Buat Akun Baru ===\n");

    //biar akun ga lebih dari size akunBaru
    if (adaAkun >= 50) {
        printf("Maaf, kapasitas akun sudah penuh.\n");
        system("pause");
        return;
    }

    char inputNama[50];
    char inputPw[20];

    printf("Masukkan nama pengguna (tanpa spasi): ");
    scanf("%s", inputNama);
    getchar();

    // biar nama akun ga ada yg sama
    for (int i = 0; i < adaAkun; i++) {
        if (strcmp(AkunBaru[i].nama, inputNama) == 0) {
            printf("Nama pengguna sudah ada. Silakan gunakan nama lain.\n");
            system("pause");
            return;
        }
    }

    printf("Masukkan password (tanpa spasi): ");
    scanf("%s", inputPw);
    getchar();

    strcpy(AkunBaru[adaAkun].nama, inputNama);
    strcpy(AkunBaru[adaAkun].password, inputPw);
    adaAkun++;

    printf("Akun baru berhasil dibuat\nTekan enter untuk melanjutkan...");
    system("pause");
    login_menu();
}

int login_menu() {
    int pilLog,loginStatus;
    do {
        system("cls");

        printf("======== Selamat Datang ========\n");
        printf("Anda belum melakukan login\n");
        printf("1. Login\n");
        printf("2. Register\n");
        printf("Pilihan anda : \n");
        if (scanf("%d", &pilLog) != 1) {
            while (getchar() != '\n');
            pilLog = 0;
        }

        while (pilLog != 1 && pilLog != 2) {
            printf("Tolong isi 1 atau 2..\nPilihan anda : \n");
            while ( getchar() != '\n' );
            if (scanf("%d", &pilLog) != 1) {
                while (getchar() != '\n');
                pilLog = 0;
            }
        }

        switch (pilLog) {
            case 1:
                loginStatus = login();
            break;
            case 2:
                buatAkun();
            break;
            default:
                printf("Tolong isi 1 atau 2..\nPilihan anda : \n");
            while ( getchar() != '\n' );
            if (scanf("%d", &pilLog) != 1) {
                while (getchar() != '\n');
                pilLog = 0;
            }
            break;
        }
    }while (loginStatus == 0);
    return (0);
}

int main(){

    login_menu();
    system("cls");
    char namaWarung[] = "Rumah Makan FUFUFAFA";
    inisialisasiMenu();
    tampilkanMenu(namaWarung);

    system("pause");
    return 0;
}