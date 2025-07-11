#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

//ini struct buat akun
struct akun{
    char nama[50];
    char password[20];
}AkunBaru[50];

int adaAkun = 0;

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

struct TransaksiNode {
    char namaMenu[50];
    int jumlah;
    float harga;
    struct TransaksiNode* next;
};

struct TransaksiNode* head = NULL;

int maxIndexMenu = 20;

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
void hapusTransaksi();

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

    for (int i = 0; i < maxIndexMenu; i++) {
        strcpy(menuMakan[i].namaMenu, daftarMenu[i]);
        menuMakan[i].harga = daftarHarga[i];
    }
}

void sort(int pilihan){
    if(pilihan == 1){
        for(int i = 0; i < maxIndexMenu;i++){
            for(int j = 0; j < maxIndexMenu; j++){
                if(menuMakan[i].harga <= menuMakan[j].harga){
                    struct menuMakanan temp = menuMakan[i];
                    menuMakan[i] = menuMakan[j];
                    menuMakan[j] = temp;
                }
            }
        }
    }else if(pilihan == 2){
        for(int i = 0; i < maxIndexMenu;i++){
            for(int j = 0; j < maxIndexMenu; j++){
                if(menuMakan[i].harga >= menuMakan[j].harga){
                    struct menuMakanan temp = menuMakan[i];
                    menuMakan[i] = menuMakan[j];
                    menuMakan[j] = temp;
                }
            }
        }
    }
}

void tampilkanMenu() {
    printf("=== Selamat Datang di Rumah Makan FUFUFAFA ===\n");
    printf("Daftar Menu:\n");
    for (int i = 0; i < maxIndexMenu; i++) {
        printf("%2d. %-25s Rp %.0f\n", i + 1, menuMakan[i].namaMenu, menuMakan[i].harga);
    }
    printf("\n");
}

void cariMenu(){
    system("cls");
    char namaMenu[100];
    getchar();
    printf("Masukan nama menu yang mau di cari : ");
    gets(namaMenu);

    int index = cariDiMenuMakanan(namaMenu);
    if(index != -1){
        printf("Menu %s tersedia dengan harga %0.f\n",menuMakan[index].namaMenu,menuMakan[index].harga);
    }else{
        printf("menu tidak di temukan");
    }
    system("pause");
    system("cls");
}

void tampilkan(){
    int pilihan;
    do{
        // getchar();
        tampilkanMenu();
        printf("1. Tampilkan dari yang termurah sampai yang termahal\n");
        printf("2. Tampilkan dari yang termahal sampai yang termurah\n");
        printf("3. Cari Menu\n");
        printf("4. Exit\n");
        printf("Silahlan Memilih (1-3) : ");
        scanf("%d",&pilihan);
        system("cls");
        switch (pilihan)
            {
            case 1:
                sort(pilihan);
                break;
            case 2:
                sort(pilihan);
                break;
            case 3:
                cariMenu();
                break;
            case 4:
                break;
            default:
                printf("Pilihan tidak valid silahkan (pilih 1-3)");
                break;
            }
    }while(pilihan != 4);

}

void updateMenu(){
    system("cls");
    char menu [100];
    float hargaBaru;
    tampilkanMenu();
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

void hapusMenu() {
    system("cls");
    char menuDihapus[50];

    tampilkanMenu();
    printf("Masukkan nama menu yang ingin dihapus: ");
    getchar();
    gets(menuDihapus);

    int index = cariDiMenuMakanan(menuDihapus);

    if (index != -1) {
        for (int i = index; i < maxIndexMenu - 1; i++) {
            menuMakan[i] = menuMakan[i + 1];
        }
        maxIndexMenu--;

        printf("\nMenu berhasil dihapus!\n");
    } else {
        printf("\nMenu tidak ditemukan!\n");
    }

    system("pause");
}

void tambahTransaksi(char namaMenu[], int jumlah, float harga) {
    struct TransaksiNode* baru = (struct TransaksiNode*)malloc(sizeof(struct TransaksiNode));
    strcpy(baru->namaMenu, namaMenu);
    baru->jumlah = jumlah;
    baru->harga = harga;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        struct TransaksiNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void tampilkanTransaksi() {
    struct TransaksiNode* temp = head;
    int no = 1;
    float total = 0;

    printf("============== Struk Pembelian ==============\n");
    while (temp != NULL) {
        printf("%2d. %-25s x%d = Rp %.0f\n", no++, temp->namaMenu, temp->jumlah, temp->harga);
        total += temp->harga;
        temp = temp->next;
    }
    printf("Total Harga: Rp %.0f\n", total);
    printf("=============================================\n");
}

void updateTransaksi() {
    if (head == NULL) {
        printf("Belum ada transaksi yang bisa diupdate.\n");
        return;
    }

    char menuUpdate[50];
    int jumlahBaru;
    float hargaPerItem;

    getchar();
    printf("Masukkan nama menu yang ingin diupdate: ");
    gets(menuUpdate);

    struct TransaksiNode* temp = head;
    while (temp != NULL) {
        if (strcasecmp(temp->namaMenu, menuUpdate) == 0) {
            printf("Jumlah sebelumnya: %d\n", temp->jumlah);
            printf("Masukkan jumlah baru: ");
            scanf("%d", &jumlahBaru);
            hargaPerItem = temp->harga / temp->jumlah;
            temp->jumlah = jumlahBaru;
            temp->harga = hargaPerItem * jumlahBaru;
            printf("Transaksi berhasil diupdate!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Menu tidak ditemukan dalam transaksi.\n");
}

void pemesanan() {
    char namaPesanan[50];
    int jumlahPesanan;
    char lanjut;
    int jumlahItem = 0;

    do {
        system("cls");
        tampilkanMenu();

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

            // ✅ Tampilkan semua yang sudah dipesan sejauh ini
            printf("\n--- Daftar Pesanan Saat Ini ---\n");
            for (int i = 0; i < jumlahItem; i++) {
                printf("%2d. %-25s x%d = Rp %.0f\n", i + 1,
                    strukPembelian[i].namaMenu,
                    strukPembelian[i].jumlah,
                    strukPembelian[i].harga);
            }
            printf("--------------------------------\n");
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

    for (int i = 0; i < jumlahItem; i++) {
        tambahTransaksi(strukPembelian[i].namaMenu, strukPembelian[i].jumlah, strukPembelian[i].harga);
    }

    char ubah[10];
    printf("\nIngin update transaksi? (y/n): ");
    scanf("%s", ubah);

    if (tolower(ubah[0]) == 'y') {
        updateTransaksi();
        printf("\nStruk setelah update:\n");
        tampilkanTransaksi();
        system("pause");
    }

    // ✅ Tambahkan opsi untuk menghapus transaksi
    printf("\nIngin menghapus transaksi? (y/n): ");
    scanf("%s", ubah);
    if (tolower(ubah[0]) == 'y') {
        hapusTransaksi();
        printf("\nStruk setelah penghapusan:\n");
        tampilkanTransaksi();
        system("pause");
    }
}

void hapusTransaksi() {
    if (head == NULL) {
        printf("Belum ada transaksi yang bisa dihapus.\n");
        return;
    }

    char namaHapus[50];
    getchar();
    printf("Masukkan nama menu yang ingin dihapus dari transaksi: ");
    gets(namaHapus);

    struct TransaksiNode *temp = head, *prev = NULL;

    while (temp != NULL) {
        if (strcasecmp(temp->namaMenu, namaHapus) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Transaksi berhasil dihapus!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Menu tidak ditemukan dalam transaksi.\n");
}

void saveAkun(struct akun acc) {
    FILE *file = fopen ("akun.txt", "a");

    if (file == NULL) {
        printf("Gagal membuka file!\n");
        system("pause");
        return;
    }

    fprintf(file, "%s,%s\n", acc.nama, acc.password);
    fclose(file);
}

void bacaAkun() {
    FILE *file = fopen("akun.txt", "r");

    if (file == NULL) {
        printf("File atau Data tidak ditemukan....\nmembuat file baru....\n");

        strcpy(AkunBaru[0].nama, "user");
        strcpy(AkunBaru[0].password, "user");
        adaAkun = 1;

        saveAkun(AkunBaru[0]);
        printf("Silahkan login kembali mengunakan 'user'.\n");
        system("pause");
        return;
    }

    for (int i = 0; i < 50; i++) {
        int hasilScan = fscanf(file,"%[^,],%[^\n]\n", AkunBaru[i].nama, AkunBaru[i].password);
        if (hasilScan == 2) {
            adaAkun++;
        } else {
            break;
        }
    }
    fclose(file);
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
    saveAkun(AkunBaru[adaAkun]);
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

    bacaAkun();
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
        printf("5. Hapus Menu Makanan\n");
        printf("6. Credits\n");
        printf("7. Logout\n");
        printf("8. Exit\n");
        printf("-------------------------------\n");
        printf("Pilih opsi (1-8): ");

        if (scanf("%d", &pilihan) != 1) {
            while (getchar() != '\n');
            pilihan = 0;
        }

        switch (pilihan) {
            case 1:
                system("cls");
                tampilkan();
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
                hapusMenu();
                break;
            case 6:
                tampilkanCredits();
                system("pause");
                break;
            case 7:
                login_menu();
                break;
            case 8:
                system("cls");
                printf("Sampai berjumpa lagi!"); //change this to whatever yall please..
				system("pause");
                break;
            default:
                printf("Opsi tidak valid. Silakan pilih antara 1-8.\n");
                system("pause");
        }
    } while (pilihan != 8);
    return 0;
}
