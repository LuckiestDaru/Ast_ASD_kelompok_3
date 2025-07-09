#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

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
    float harga;
};
struct menuMakanan menuMakan[100];

//sama aja kayak di atas
struct strukHarga{
    char namaMenu[50];
    int jumlah;
    float harga;
};
struct strukHarga strukPembelian[100];

int maxIndexMenu;
int jumlahAwalMenu = 20;

struct anggotaKelompok {
    char nama[100];
    char nim[20];
    char kontribusi[150];
};

struct anggotaKelompok tim[] = {
    {"Zefanya Derby Gracia Lengkong", "672024071", "Menu utama dan menampilkan developer."},
    {"Andaru Hanif Pergita", "672024094", "Menu register dan login."},
    {"Natanael Waluyo Margatan", "672024103", "Menu menambah menu makanan."},
    {"Rafael Abel Dimas Pangestu", "672024182", "Menu kalkulasi harga dan total pembelian."},
    {"Eko Prasetyo", "672024247", "Menu menampilkan menu makanan."}
};
int jumlahAnggota = sizeof(tim) / sizeof(tim[0]);

//manggil ulang
int login_menu();

int cariDiMenuMakanan(char menu[50]){
    char perbandingan [50];
    for(int i = 0; i < maxIndexMenu;i++){
        //strcpy itu string copy soalnya string ga bisa langsung di copy harus make strcpy yg awal itu variable tempatnya yg kedua target copynya
        strcpy(perbandingan, menuMakan[i].namaMenu);
        //strcmp itu buat compare returnnya itu integer kalo integernya 0 berarti sama yg di compare
        if(strcasecmp(perbandingan,menu) == 0){
            return i;
        }
    }
    return -1;
}

void tambahMenu() {
    char menuBaru[50];
    float harga;
    getchar();
    printf("\nMasukkan nama menu : ");
    gets(menuBaru);
    printf("Masukkan harga menu : ");
    scanf("%f", &harga);

    int index = cariDiMenuMakanan(menuBaru);
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
    float daftarHarga[] = {
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
        printf("%2d. %-25s Rp %.0f\n", i + 1, menuMakan[i].namaMenu, menuMakan[i].harga);
    }
    printf("\n");
}

void updateMenu(){
    system("cls");
    char menu [100];
    float hargaBaru;
    tampilkanMenu("Rumah Makan FUFUFAFA");
    printf("Masukkan nama menu yang ingin di ganti harganya : ");
    getchar();
    gets(menu);

    int index = cariDiMenuMakanan(menu);
    if(index != -1){
        printf("Masukkan harga menu yang baru : ");
        scanf("%f",&hargaBaru);
        menuMakan[index].harga = hargaBaru;
        printf("Harga menu berhasil di ubah\n");
        system("pause");
    }else{
        printf("Menu tidak ada");
    }
}

void pemesanan() {
    char namaPesanan[50];
    int jumlahPesanan;
    char lanjut;
    int jumlahItem = 0;

    do {
        system("cls");
        tampilkanMenu("Rumah Makan FUFUFAFA");

        printf("Masukkan nama menu yang ingin dipesan: ");
        getchar();
        gets(namaPesanan);
        int index = cariDiMenuMakanan(namaPesanan);

        if (index != -1) {
            printf("Masukkan jumlah pesanan: ");
            scanf("%d", &jumlahPesanan);

            strcpy(strukPembelian[jumlahItem].namaMenu, menuMakan[index].namaMenu);
            strukPembelian[jumlahItem].jumlah = jumlahPesanan;
            strukPembelian[jumlahItem].harga = menuMakan[index].harga * jumlahPesanan;

            jumlahItem++;
            printf("Pesanan berhasil ditambahkan.\n");
        } else {
            printf("Menu tidak ditemukan!\n");
        }

        printf("Apakah ingin memesan lagi? (y/n): ");
        getchar();
        scanf("%c", &lanjut);
    } while (tolower(lanjut) == 'y');

    system("cls");
    printf("============== Struk Pembelian ==============\n");
    int totalHarga = 0;
    for (int i = 0; i < jumlahItem; i++) {
        printf("%2d. %-25s x%d = Rp %.0f\n",
               i + 1,
               strukPembelian[i].namaMenu,
               strukPembelian[i].jumlah,
               strukPembelian[i].harga);
        totalHarga += strukPembelian[i].harga;
    }
    printf("Total Harga: Rp %d\n", totalHarga);
    printf("=============================================\n");
    system("pause");
    printf("Terima kasih telah berkunjung!\n");
}

int login() {
    int loginStatus,i = 0;
    char coba,ch;
    do {
        system("cls");
        printf("=== LOGIN ===\n");
        char inputNama[50];
        char inputPw[20];

        printf("Masukkan nama pengguna: ");
        scanf("%s", inputNama);
        getchar();

        //13 itu enter dan 8 itu backspace (hapues)
        printf("Masukkan password: ");
        while ((ch = getch()) != 13) {
            if (ch == 8) {
                if (i > 0) {
                    i--;
                    printf("\b \b");
                }
            } else {
                inputPw[i] = ch;
                i++;
                printf("*");
            }
        }
        inputPw[i] = '\0';


        for (int i = 0; i < adaAkun; i++) {
            if (strcmp(AkunBaru[i].nama, inputNama) == 0 && strcmp(AkunBaru[i].password, inputPw) == 0) {
                printf("\nLogin berhasil! Selamat datang, %s!\n", AkunBaru[i].nama);
                system("pause");

                loginStatus = 1;
                return loginStatus;
            }
        }
        printf("\nNama pengguna atau password salah!\n");
        do {
            printf("Apakah ingin mecoba login kembali? y/n\n");
            scanf("%c", &coba);
        }while (coba != 'y' && coba != 'n');
    }while (coba != 'n');
    loginStatus = 0;
    return (loginStatus);
}

int regisAkun(){
    int loginStatus, i = 0;
    char ch;

    system("cls");
    printf("=== Buat Akun Baru ===\n");

    //biar akun ga lebih dari size akunBaru
    if (adaAkun >= 50) {
        printf("Maaf, kapasitas akun sudah penuh.\n");
        system("pause");
        return loginStatus = 0;
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
            return loginStatus = 0;
        }
    }

    printf("Masukkan password (tanpa spasi): ");
    while ((ch = getch()) != 13) {
        if (ch == 8) {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            inputPw[i] = ch;
            i++;
            printf("*");
        }
    }
    inputPw[i] = '\0';

    strcpy(AkunBaru[adaAkun].nama, inputNama);
    strcpy(AkunBaru[adaAkun].password, inputPw);
    adaAkun++;

    printf("\nAkun baru berhasil dibuat\nTekan enter untuk melanjutkan...");
    getchar();
    return loginStatus = 0;
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
                loginStatus = regisAkun();
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

void tampilkanCredits() {
    system("cls");
    printf("=================== Credits ===================\n");
    printf("Program ini dibuat oleh:\n \n");
    for (int i = 0; i < jumlahAnggota; i++) {
        printf("%d. %s (%s)\n   -> %s\n \n", i + 1, tim[i].nama, tim[i].nim, tim[i].kontribusi);
    }
    printf("-----------------------------------------------\n");
    printf("          Perut kenyang, hati senang!\n");
}

int main(){
    int pilihan;

    login_menu();
    system("cls");
    char namaWarung[] = "Rumah Makan FUFUFAFA";
    inisialisasiMenu();

    do {
        system("cls");
        //jika perlu opsi menu utama bisa diganti, btw aku liat di penjelasan buat pengerjaan tts kalo di setiap program bakalan ada 5 total opsi di menu?
        //mungkin opsi no.3 kita dipisah jadi dua? opsi satu buat nambah menu ke daftar pembelian pelanggan, dan satunya buat liat total harga dari pesanan pelanggan?
        printf("===== Program Rumah Makan =====\n");
        printf("1. Tampilkan Daftar Menu\n");
        printf("2. Tambah Menu Makanan\n");
        printf("3. Pesan Menu\n");
        printf("4. Ganti Harga di Menu\n");
        printf("5. Credits\n");
        printf("6. Logout\n");
        printf("7. Exit\n");
        printf("-------------------------------\n");
        printf("Pilih opsi (1-5): ");

        if (scanf("%d", &pilihan) != 1) {
            while (getchar() != '\n');
            pilihan = 0;
        }

        switch (pilihan) {
            case 1:
                system("cls");
                tampilkanMenu(namaWarung);
                system("pause");
                break;
            case 2:
                system("cls");
                tambahMenu();
                break;
            case 3:
                pemesanan();
                break;
            case 4:
                updateMenu();
                break;
            case 5:
                tampilkanCredits();
                system("pause");
                break;
            case 6:
                login_menu();
                break;
            case 7:
                system("cls");
                printf("Sampai berjumpa lagi!"); //change this to whatever yall please..
				system("pause");
                break;
            default:
                printf("Opsi tidak valid. Silakan pilih antara 1-5.\n");
                system("pause");
        }
    } while (pilihan != 7);


    return 0;
}
