#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//ini struct buat akun
struct akun{
    char nama[50];
    char password[20];
};
//ini array buat nampung akun 
struct akun AkunBaru[50];

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

void menuAwal(){
    menuMakan[0].namaMenu[50] = "Nasi Goreng";
    menuMakan[0].harga = 13000;
    menuMakan[1].namaMenu[50] = "Mie Goreng";
    menuMakan[1].harga = 10000;
    maxIndexMenu = 2;
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

int main(){

    char namaWarung[] = "Rumah Makan FUFUFAFA";
    inisialisasiMenu();
    tampilkanMenu(namaWarung);

    printf("test test\n\n");

    system("pause");
    return 0;
}