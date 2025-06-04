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

void tambah() {
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


int main(){
    printf("test test\n\n");

    system("pause");
    return 0;
}