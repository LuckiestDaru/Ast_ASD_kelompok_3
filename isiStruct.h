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