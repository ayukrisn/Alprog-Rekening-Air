#include <stdio.h>
#include<windows.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#define biayaAdmin          //Biaya administrasi Rp50
#define denda10Sampai100    //Denda pemakaian 10 sampai 100 m3 Rp10
#define dendaLebihDari100   //Denda pemakaian melebihi 100 m3 Rp20
#define BPM_R               //biaya pemeliharaan meter rumah tangga Rp.10
#define BPM_U               //biaya pemeliharaan meter usaha Rp.20

int main()
{
    menu();
    return 0;
}


void menu()
 {
    int pilihanMenu = 0;
    printf("\t\t  ______________________________________________________________________\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                       P E M B A Y A R A N  A I R                     ||\n");
    printf("\t\t||          A I R   M I N U M  T I R T A  S E W A K A D A R M A         ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| [1] Masuk sebagai Pelanggan Rumah Tangga                             ||\n");
    printf("\t\t|| [2] Masuk sebagai Pelanggan Usaha                                    ||\n");
    printf("\t\t|| [3] Instruksi Penggunaan                                             ||\n");
    printf("\t\t|| [0] Keluar                                                           ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\n\t\tPilih menu yang diinginkan: ");
    if (getInt(&pilihanMenu)){
         switch (pilihanMenu)
         {
            case 1:
                system("cls");
                masukRT();
                break;
            case 2:
                system("cls");
                masukU();
                break;
            case 3:
                system("cls");

                break;
            case 0:
                keluar();
                break;
            default:
                printf("\n\t\tPilihan Anda salah. Silahkan coba lagi (dimulai dalam 2 detik).");
                inputSalah();
                menu();
         }
    } else {
        inputSalah();
        menu();}
 }


void masukRT()
{
    int idPelanggan = 0;
    printf("\t\t  ______________________________________________________________________\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                  K A T E G O R I  R U M A H  T A N G G A             ||\n");
    printf("\t\t||                        Masukkan ID Pelanggan Anda                    ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| Klik [0] untuk kembali ke menu utama                                 ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\t\t  ID Pelanggan :  ");
    if (getInt(&idPelanggan)){
    switch (idPelanggan)
         {
            case 0111: //Rumah Tangga D1-1
                system("cls");

                break;
            case 0112: //Rumah Tangga D1-2
                system("cls");

                break;
            case 0121: //Rumah Tangga D2-1
                system("cls");

                break;
            case 0122: //Rumah Tangga D2-2
                system("cls");

                break;
            case 0131: //Rumah Tangga D3-1
                system("cls");

                break;
            case 0132: //Rumah Tangga D3-2
                system("cls");

                break;
            case 0141: //Rumah Tangga D4-1
                system("cls");

                break;
            case 0142: //Rumah Tangga D4-2
                system("cls");

                break;
            case 0113: //Rumah Tangga D1-3
                system("cls");

                break;
            case 0114: //Rumah Tangga D1-4
                system("cls");

                break;
            case 0123: //Rumah Tangga D2-3
                system("cls");

                break;
            case 0124: //Rumah Tangga D2-4
                system("cls");

                break;
            case 0133: //Rumah Tangga D3-3
                system("cls");

                break;
            case 0134: //Rumah Tangga D3-4
                system("cls");

                break;
            case 0143: //Rumah Tangga D4-3
                system("cls");

                break;
            case 0144: //Rumah Tangga D4-4
                system("cls");

                break;
            case 0151: //Rumah Tangga D5-1
                system("cls");

                break;
            case 0152: //Rumah Tangga D5-2
                system("cls");

                break;
            case 0153: //Rumah Tangga D5-3
                system("cls");

                break;
            case 0154: //Rumah Tangga D5-4
                system("cls");

                break;
            case 0:
                menu();
                break;
            default:
                printf("\n\t\tPilihan Anda salah. Silahkan coba lagi (dimulai dalam 2 detik).");
                inputSalah();
                menu();
         }
    } else {
        inputSalah();
        menu();}
 }


void masukU()
{
    int idPelanggan = 0;
    printf("\t\t  ______________________________________________________________________\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                       K A T E G O R I  U S A H A                     ||\n");
    printf("\t\t||                       Masukkan ID Pelanggan Anda                     ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| Klik [0] untuk kembali ke menu utama                                 ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\t\t  ID Pelanggan :  ");
    if (getInt(&idPelanggan)){
    switch (idPelanggan)
         {
            case 0211: //Niaga E1-1
                system("cls");

                break;
            case 0212: //Niaga E1-2
                system("cls");

                break;
            case 0213: //Niaga E1-3
                system("cls");

                break;
            case 0214: //Niaga E1-4
                system("cls");

                break;
            case 0221: //Niaga E2-1
                system("cls");

                break;
            case 0222: //Niaga E2-2
                system("cls");

                break;
            case 0223: //Niaga E2-3
                system("cls");

                break;
            case 0224: //Niaga E2-4
                system("cls");

                break;
            case 0231: //Niaga E3-1
                system("cls");

                break;
            case 0233: //Niaga E3-3
                system("cls");

                break;
            case 0234: //Niaga E3-4
                system("cls");

                break;
            case 0:
                menu();
                break;
            default:
                printf("\n\t\tPilihan Anda salah. Silahkan coba lagi (dimulai dalam 2 detik).");
                inputSalah();
                menu();
         }
    } else {
        inputSalah();
        menu();}
 }


void repeat()
{
    char pilihanUlang;
    printf("\n\n\t\t Apakah Anda ingin kembali ke menu utama?");
    printf("\n\t\t Ketik [Y] untuk 'Ya' dan [N] untuk 'Tidak'\n");
    printf("\t\t Pilihan: ");
    if (getChar(&pilihanUlang)){
    if(pilihanUlang == 'Y' || pilihanUlang == 'y')
    {
        system("cls");
        menu();
    } else if(pilihanUlang == 'N' || pilihanUlang == 'n')
        {
            keluar();
        } else
            {
                printf("\t\t Masukan Anda salah. Silahkan coba lagi.");
                repeat();
            }
    } else { repeat();}
}

void keluar()
{
    system("cls");
    printf("\t\t  ______________________________________________________________________\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                       T E R I M A  K A S I H                         ||\n");
    printf("\t\t||                Karena Telah Menggunakan Program Ini                  ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\t\t  ______________________________________________________________________  \n");
    exit(0);
}


bool getInt(int*target)
{
    if(scanf("%i", target) > 0) {
        flushIn();
        return true;
    } else {
            printf("\n\t\t Masukkan Anda tidak valid. Silahkan coba lagi. \n");
            flushIn();
            return false; }

}

bool getChar(char*target)
{
    if(scanf("%c", target) > 0) {
        flushIn();
        return true;
    } else {
            printf("\n\t\t Masukkan Anda tidak valid. Silahkan coba lagi. \n");
            flushIn();
            return false; }

}

void flushIn()
{
    int ch = 0;
    while ((ch = getchar()) != '\n' && ch != -1);
}

