#include <stdio.h>
#include <stdlib.h> // Untuk system("cls")
#include <string.h>
#include <conio.h> 
#include <windows.h>
#include <unistd.h>
#include <ctype.h> //touper


//deklarasi fungsi
int awal();
int halaman();
void gotoxy(int x, int y);
void arrowHere(int realPosition, int arrowPosition);
void angka_loading(int persen);


//variabel global
char name[50];
char total_tipe_kamar[50];
char username[10];
char password[10];
int tipe_kamar;
int hari;
int harga_kamar;
int harga;
int total_harga;
int total_hari;
int jumlah_pengunjung = 0; // Menyimpan jumlah pengunjung
//variabel khusus
struct Pengunjung; 




/////////FUNGSI MAIN////////////

void main(){
    if (awal() == 1){
    halaman();
    }
}

///////////////////////////////



struct Pengunjung {
    char nama[50];
    int tipe_kamar;
    int hari;
    int total_harga;
};
struct Pengunjung data_pengunjung[50]; // Menyimpan data pengunjung

//fungsi gotoxy
void gotoxy(int x, int y){//fungsi goto untuk dipanggil ke main
    COORD coord; //variabel koordiat
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//fungsi arrow
void arrowHere(int realPosition, int arrowPosition) {
    if(realPosition == arrowPosition) {
        printf("--> ");
    } else {
        printf("    ");
    }
}

//fungsi loading
void angka_loading(int persen) {
    system("cls");
    gotoxy(40,10);
    printf("Login berhasil, tunggu sampai loading selesai\n\n");
    gotoxy(56,12);
    printf("Loading %d%%\r", persen);
    fflush(stdout);
}

//fungsi halaman depan
int awal(){

    gotoxy(20,4);printf("\t\t+===============================================+\n");
    gotoxy(20,5);printf("\t\t|\t\t\t\t\t\t|\n");
    gotoxy(20,6);printf("\t\t|\t Selamat Datang di Hotel Wilson\t\t|\n");
    gotoxy(20,7); printf("\t\t|\t\t\t\t\t\t|\n");
    gotoxy(20,8); printf("\t\t+===============================================+\n");
    gotoxy(20,9); printf("\t");


    gotoxy(41,13);system("pause");
    system("cls");

    return 1; //dipanggil fungsi main
}

//fungsi buatan utama
int halaman(){
int key=0, p=1;

    system("cls");
    home:
    printf("\n\n\n\n\n\n\t\t\t+===============================================================+\n");
    printf("\t\t\t|\t\t\t\t\t\t\t\t|\n");
    printf("\t\t\t|\t\t Selamat Datang di Hotel Wilson\t\t\t|\n");
    printf("\t\t\t|\t\t\t\t\t\t\t\t|\n");
    printf("\t\t\t|_______________________________________________________________|\n");
    printf("\t\t\t|\t\t\t\t\t\t\t\t|\n");
    printf("\t\t\t|alamat: Jl. Pattimura No.75      || \t contact: 0857-4788-7622|\n");
    printf("\t\t\t+===============================================================+\n\n");
        gotoxy(54,15);
        printf("Pilih Menu");
        gotoxy(47,17);
        arrowHere(1, p);
        printf("1. Admin\n");
        gotoxy(47,18);
        arrowHere(2, p);
        printf("2. Pengunjung\n");
        gotoxy(47,19);
        arrowHere(3, p);
        printf("3. Kesan Pesan Asdos\n");
        gotoxy(47,20);
        arrowHere(4, p);
        printf("4. Exit\n");

    do {
        key = _getch(); // Use getchar() to handle arrow keys

        if (key == 80) {
            p++;
            if (p > 4) p = 1;
        } else if (key == 72) {
            p--;
            if (p < 1) p = 4;
        }
        system("cls");

    printf("\n\n\n\n\n\n\t\t\t+===============================================================+\n");
    printf("\t\t\t|\t\t\t\t\t\t\t\t|\n");
    printf("\t\t\t|\t\t Selamat Datang di Hotel Wilson\t\t\t|\n");
    printf("\t\t\t|\t\t\t\t\t\t\t\t|\n");
    printf("\t\t\t|_______________________________________________________________|\n");
    printf("\t\t\t|\t\t\t\t\t\t\t\t|\n");
    printf("\t\t\t|alamat: Jl. Pattimura No.75      || \t contact: 0857-4788-7622|\n");
    printf("\t\t\t+===============================================================+\n\n");
        gotoxy(54,15);
        printf("Pilih Menu");
        gotoxy(47,17);
        arrowHere(1, p);
        printf("1. Admin\n");
        gotoxy(47,18);
        arrowHere(2, p);
        printf("2. Pengunjung\n");
        gotoxy(47,19);
        arrowHere(3, p);
        printf("3. Kesan Pesan Asdos\n");
        gotoxy(47,20);
        arrowHere(4, p);
        printf("4. Exit\n");

    } while (key != 13); // Loop until Enter key is pressed


//Menu Admin
if(p == 1) {
    while (1){
        system ("cls");
        gotoxy(50,10);
        printf("Username: ");
        scanf("%s", username);
        gotoxy(50,11);
        printf("Password: ");
        fflush(stdin);

        char ch;
        int i=0;
        while((ch=(char) _getch()) != '\r'){
            if(ch != '\r'){ // Mengabaikan karakter Enter
            password [i] = ch;
            printf ("*");

            i++;
            }
        }
        fflush(stdin);  // Membersihkan buffer input
        printf("\n");
        // Memeriksa username dan password
        if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0) {
            system("cls");
            goto loading; // Jika login berhasil, dilanjutkan dengan animasi loading
        } 
        else{
            gotoxy(40,10);
            printf("Username atau Password salah cah bagus\n\n\n");
            gotoxy(40,11);
            system("pause");

            system("cls");

        }

}
        loading:
        system("cls");
        int i;
        for (i = 1; i <= 100; ++i){
            angka_loading(i);
            usleep(10000); // lama waktu loading
        }
        system("cls");
        gotoxy(47,11);
        printf("Loading selesai bosqu!\n\n\n");
        gotoxy(43,14);
        system("pause");
        system("cls");
        goto admin;

        int input1;
        admin:

            printf("\n\n\n\n\n\n\t\t\t+===============================================================+\n");
            printf("\t\t\t|\t\t\t\t\t\t\t\t|\n");
            printf("\t\t\t|\t\t Selamat Datang di Hotel Wilson\t\t\t|\n");
            printf("\t\t\t|\t\t\t\t\t\t\t\t|\n");
            printf("\t\t\t|_______________________________________________________________|\n");
            printf("\t\t\t|\t\t\t\t\t\t\t\t|\n");
            printf("\t\t\t|alamat: Jl. Pattimura No.75      || \t contact: 0857-4788-7622|\n");
            printf("\t\t\t+===============================================================+\n\n");

                gotoxy(54,15);
                printf("Menu Admin:\n");
                gotoxy(47,17);
                printf("1. Lihat Daftar Tamu Hotel\n");
                gotoxy(47,18);
                printf("2. Kembali\n");
                gotoxy(47,19);
                printf ("masukan pilihan anda: ");
                scanf("%d", &input1);

    //menu admin = 1
    if(input1 == 1){
        system("cls");
        printf("\n\n\n\n\n\n\t\t\t\t+-------------------------------------------------------+\n");
        printf("\t\t\t\t| \t\tDaftar Tamu Hotel Wilson\t\t|\n");
        printf("\t\t\t\t+-------------------------------------------------------+\n");

        for (int i = 0; i < jumlah_pengunjung; i++){
        // Toupper Bosqu
            for (int j = 0; data_pengunjung[i].nama[j] != '\0'; j++) {
            data_pengunjung[i].nama[j] = toupper(data_pengunjung[i].nama[j]);
        }
        printf("\t\t\t\t|\t\t\t%s\t\t\t\t|\n", data_pengunjung[i].nama);
        }
        printf("\t\t\t\t+-------------------------------------------------------+\n");

        gotoxy (45,13);
                system("pause");
                system("cls");
                goto admin;
    }
    //menu admin = 2
    else if(input1 == 2){
                system("cls");
                goto home;
    }
    //menu admin = 3
    else{
                system("cls");
                goto admin;
    }
                getch();
                system("cls");
}



// Menu Pengunjung
else if(p == 2) {
system("cls");
    int input2;
    int input22;
    int total_hari = 0; // Menyimpan total hari dari semua input
    int total_harga = 0; // Menyimpan total harga dari semua input

    pengunjung:

    printf("\n\n\n\n\n\n\t\t\t+===============================================================+\n");
    printf("\t\t\t|\t\t\t\t\t\t\t\t|\n");
    printf("\t\t\t|\t\t Selamat Datang di Hotel Wilson\t\t\t|\n");
    printf("\t\t\t|\t\t\t\t\t\t\t\t|\n");
    printf("\t\t\t|_______________________________________________________________|\n");
    printf("\t\t\t|\t\t\t\t\t\t\t\t|\n");
    printf("\t\t\t|alamat: Jl. Pattimura No.75      || \t contact: 0857-4788-7622|\n");
    printf("\t\t\t+===============================================================+\n\n");

    gotoxy(54,15);
    printf("Menu Pengunjung:\n");
    gotoxy(47,17);
    printf("1. Input Data Pengunjung\n");
    gotoxy(47,18);
    printf("2. Cetak Struk\n");
    gotoxy(47,19);
    printf("3. Kembali\n");
    gotoxy(47,20);
    printf("Masukkan pilihan anda: ");
    scanf("%d", &input2);

    //Menu Pengunjung = 1
    if (input2 == 1) {
        system("cls");
        // Input data pengunjung
        gotoxy(47,11);
        printf("Masukkan nama pengunjung: ");
        scanf("%s", data_pengunjung[jumlah_pengunjung].nama);

        do {
            system ("cls");
            pilih:
            gotoxy(54,9);
            printf("Pilih tipe kamar:\n");
            gotoxy(43,11);
            printf("1. Single Bed (Rp. 300.000 per malam)\n");
            gotoxy(43,12);
            printf("2. Double Bed (Rp. 500.000 per malam)\n");
            gotoxy(43,13);
            printf("Masukkan pilihan Anda: ");
            scanf("%d", &data_pengunjung[jumlah_pengunjung].tipe_kamar);
            printf("\n");

            if (data_pengunjung[jumlah_pengunjung].tipe_kamar == 1 || data_pengunjung[jumlah_pengunjung].tipe_kamar == 2) {
                system ("cls");
                gotoxy(47,11);
                printf("Masukkan jumlah malam menginap: ");
                scanf("%d", &data_pengunjung[jumlah_pengunjung].hari);

                if (data_pengunjung[jumlah_pengunjung].hari > 0) {
                    if (data_pengunjung[jumlah_pengunjung].tipe_kamar == 1) {
                        data_pengunjung[jumlah_pengunjung].total_harga = 300000 * data_pengunjung[jumlah_pengunjung].hari;
                    } else {
                        data_pengunjung[jumlah_pengunjung].total_harga = 500000 * data_pengunjung[jumlah_pengunjung].hari;
                    }

                    total_hari += data_pengunjung[jumlah_pengunjung].hari;
                    total_harga += data_pengunjung[jumlah_pengunjung].total_harga;

                    jumlah_pengunjung++; // Menambah jumlah pengunjung
                } 
                else {
                    system("cls");
                    goto pilih;
                }
            } 
            else {
                system("cls");
                goto pilih;
            }

            system("cls");
            gotoxy(40,11);
            printf("Ingin memesan kamar lagi? (0 untuk tidak): ");
            scanf("%d", &input22);
            system("cls");

        } 
        while (input22 != 0);

        gotoxy(47,11);
        system("pause");
        system("cls");
        goto pengunjung;
    } 


    //Menu Pengunjung = 2
    else if (input2 == 2) {
        system("cls");

        //struk
        printf("\n\n\n\n\n\t\t\t+-------------------------------------------------------------------------------+\n");
        printf("\t\t\t| Nama\t\t| Tipe Kamar\t\t| Hari\t\t| Total Harga\t\t|\n");
        printf("\t\t\t+---------------+-----------------------+---------------+-----------------------+\n");

        for (int i = 0; i < jumlah_pengunjung; i++) {
            printf("\t\t\t|%s", data_pengunjung[i].nama);
            printf("\t\t|%s \t\t", (data_pengunjung[i].tipe_kamar == 1) ? "Single Bed" : "Double Bed");
            printf("|%d \t\t", data_pengunjung[i].hari);
            printf("|%d \t\t", data_pengunjung[i].total_harga);
            printf("|\n");
        }
        printf("\t\t\t+---------------+-----------------------+---------------+-----------------------+\n");
        gotoxy(47,11);
        system("pause");
        system("cls");
        goto pengunjung;
    }
    //menu pengunjung = 3
    else {
        system("cls");
        goto home;
    }
}

//Menu Pesan & Kesan asdos
else if(p==3) {
                system("cls");
                gotoxy(29,2);printf("Terimakasih banyak atas dedikasinya dalam meng(h)ajar dan membimbing kami\n");
                printf("\n");
                gotoxy(42,4);printf("Yang Mulia Hosea Raka Narwastudjati\n");
                gotoxy(60,5);printf("&\n");
                gotoxy(44,6);printf("Pangeran Vincent Exelcio Susanto\n");

    gotoxy(50,10);printf("   *****    *****\n");
    gotoxy(50,11);printf("  *******  *******\n");
    gotoxy(50,12);printf("   ***** We *****\n");
    gotoxy(50,13);printf("    *** Love ***\n");
    gotoxy(50,14);printf("     ** You  **\n");
    gotoxy(50,15);printf("      *** ***\n");
    gotoxy(50,16);printf("       ** **\n");
    gotoxy(50,17);printf("        ***\n");

                gotoxy(45,20);system ("pause");
                system("cls");
                goto home;
}

//Menu exit
else if(p==4){
                system("cls");
                gotoxy(55,10);
                printf("Created by:\n\n");
                gotoxy(43,11);
                printf("Otniel Ferdianto Hendrawan - 672023239\n");
                gotoxy(43,12);
                printf("Mikael Willy Mei Putra - 672023257\n\n");

                gotoxy(41,15);
                char makasih[50] = "Terimakasih, kami pamit undur diri bosqu!\n";

                for(int i = 0; i < 50; i++){
                printf("%c",makasih[i]);
                Sleep(80);//jeda 80 milidetik per loop
                }
                sleep (3);
}

else{
system("cls");
main();
}
    return 0;
}
