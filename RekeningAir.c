#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#define biayaAdmin          //Biaya administrasi Rp50
#define denda10Sampai100    //Denda pemakaian 10 sampai 100 m3 Rp10
#define dendaLebihDari100   //Denda pemakaian melebihi 100 m3 Rp20
#define BPM_R               //biaya pemeliharaan meter rumah tangga Rp.10
#define BPM_U               //biaya pemeliharaan meter usaha Rp.20

void menu(),
     registrasi1(), regisKelompok(), regisRT(), regisUsaha(),
     d1(), d2(), d3(), d4(), d5();

char nama[255],
     alamat[100],
     golongan[10];

int  pBulanLalu,
     pBulanIni,
     pTotal;

bool getInt(int*target), getChar(char*target);


int main()
{
    menu();
    return 0;
}


void menu()
 {
    int pilihanMenu = 0;
    printf("\t\t  ______________________________________________________________________ \n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                       P E M B A Y A R A N  A I R                     ||\n");
    printf("\t\t||                   PERUMDA AIR MINUM TIRTA SEWAKADARMA                ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t|| [1] Instruksi Penggunaan                                             ||\n");
    printf("\t\t|| [2] Registrasi Pelanggan                                             ||\n");
    printf("\t\t|| [3] Kredit Program                                                   ||\n");
    printf("\t\t|| [0] Keluar                                                           ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\n\t\tPilih menu yang diinginkan: ");
    if (getInt(&pilihanMenu)){
         switch (pilihanMenu)
         {
            case 1:
                system("cls");
                //
                break;
            case 2:
                system("cls");
                registrasi1();
                break;
            case 3:
                system("cls");
                //
                break;
            case 4:
                system("cls");

                break;
            case 0:
                keluar();
                break;
            default:
                printf("\n\t\tPilihan Anda salah. Silahkan coba lagi (dimulai dalam 2 detik).");
                inputSalah();
                menu();
                break;
         }
    } else {
        inputSalah();
        menu();}
 }


void registrasi1()
{
    int navigasi = 0;
    printf("\t\t  ______________________________________________________________________\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                    M E N U  R E G I S T R A S I                      ||\n");
    printf("\t\t||                Mohon Masukkan Nama dan Alamat Anda                   ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||______________________________________________________________________||\n");

    printf("\t\t  Nama Pelanggan: ");
    scanf ("%[^\n]%*c", nama);
    printf("\t\t  Alamat        : ");
    scanf ("%[^\n]%*c", alamat);

    printf("\t\t  ______________________________________________________________________\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| Klik [1] untuk melanjutkan ke registrasi berikutnya.                 ||\n");
    printf("\t\t|| Klik [0] untuk kembali ke menu awal.                                 ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\t\t  Pilihan  : ");
    if(getInt(&navigasi))
    {
        if(navigasi == 1)
        {
            system("cls");
            regisKelompok();
        }
        else if (navigasi == 0)
        {
            system("cls");
            menu();
        } else
        {
            printf("Masukkan Anda salah. Mohon coba lagi.");
            registrasi1();
        }

    }
    else
    {
        inputSalah();
        registrasi1();
    }

}


void regisKelompok()
{
    int pilihanMenu = 0;
    printf("\t\t  ______________________________________________________________________\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      M E N U  R E G I S T R A S I                    ||\n");
    printf("\t\t||            Mohon Masukkan Tipe Kelompok Fasilitas Air Anda           ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| [1] Penggunaan untuk rumah tangga (RT)                               ||\n");
    printf("\t\t|| [2] Penggunaan untuk usaha/niaga                                     ||\n");
    printf("\t\t|| [0] Kembali ke menu utama                                            ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\n\t\t Pilih tipe kelompok fasilitas : ");
    if (getInt(&pilihanMenu)){
         switch (pilihanMenu)
         {
            case 1:
                system("cls");
                regisRT();
                break;
            case 2:
                system("cls");
                regisUsaha();
                break;
            case 3:
                system("cls");
                //
                break;
            case 4:
                system("cls");

                break;
            case 0:
                system("cls");
                menu();
                break;
            default:
                printf("\n\t\tPilihan Anda salah. Silahkan coba lagi (dimulai dalam 2 detik).");
                inputSalah();
                regisKelompok();
                break;
         }
    } else {
        inputSalah();
        regisKelompok();}
 }


void regisRT()
{
    int pilihanMenu = 0;
    printf("\t\t  ______________________________________________________________________\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                  M E N U  R E G I S T R A S I : R T                  ||\n");
    printf("\t\t||              Mohon Masukkan Lebar Jalan Muka Rumah Anda              ||\n");
    printf("\t\t||                (Termasuk saluran got, berm, dan persil)              ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| [1] 0-3,99 meter                                                     ||\n");
    printf("\t\t|| [2] 4-6,99 meter                                                     ||\n");
    printf("\t\t|| [3] 7-10 meter                                                       ||\n");
    printf("\t\t|| [4] >10 meter                                                        ||\n");
    printf("\t\t|| [5] Memiliki usaha di samping tempat tinggal                         ||\n");
    printf("\t\t|| [0] Kembali ke menu utama                                            ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\n\t\t Pilih lebar jalan : ");
    if (getInt(&pilihanMenu)){
         switch (pilihanMenu)
         {
            case 1:
                system("cls");
                d1();
                break;
            case 2:
                system("cls");
                d2();
                break;
            case 3:
                system("cls");
                d3();
                break;
            case 4:
                system("cls");
                d4();
                break;
            case 5:
                system("cls");
                d5();
            case 0:
                system("cls");
                menu();
                break;
            default:
                printf("\n\t\tPilihan Anda salah. Silahkan coba lagi (dimulai dalam 2 detik).");
                inputSalah();
                regisRT();
                break;
         }
    } else {
        inputSalah();
        regisRT();}
 }


void regisUsaha()
{
    int pilihanMenu = 0;
    printf("\t\t  ______________________________________________________________________\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||               M E N U  R E G I S T R A S I : U S A H A               ||\n");
    printf("\t\t||              Mohon Masukkan Lebar Jalan Muka Usaha Anda              ||\n");
    printf("\t\t||                   (Termasuk saluran got dan berm)                    ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| [1] 0-6,99 meter                                                     ||\n");
    printf("\t\t|| [2] 7-10 meter                                                       ||\n");
    printf("\t\t|| [3] >10 meter                                                        ||\n");
    printf("\t\t|| [0] Kembali ke menu utama                                            ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\n\t\t Pilih lebar jalan : ");
    if (getInt(&pilihanMenu)){
         switch (pilihanMenu)
         {
            case 1:
                system("cls");
                e1();
                break;
            case 2:
                system("cls");
                e2();
                break;
            case 3:
                system("cls");
                e3();
                break;
            case 0:
                system("cls");
                menu();
                break;
            default:
                printf("\n\t\tPilihan Anda salah. Silahkan coba lagi (dimulai dalam 2 detik).");
                inputSalah();
                regisUsaha();
                break;
         }
    } else {
        inputSalah();
        regisUsaha();}
 }


void d1()
{
    int pilihanMenu = 0;
    printf("\t\t  ______________________________________________________________________\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                  M E N U  R E G I S T R A S I : R T                  ||\n");
    printf("\t\t||                Mohon Masukkan Daya Listrik Rumah Anda                ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| [1] Daya listrik 450 VA                                              ||\n");
    printf("\t\t|| [2] Daya listrik 900 VA                                              ||\n");
    printf("\t\t|| [3] Daya listrik 1.300 VA                                            ||\n");
    printf("\t\t|| [4] Daya listrik > 1.300 VA                                          ||\n");
    printf("\t\t|| [0] Kembali ke menu sebelumnya                                       ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\n\t\t Pilih daya listrik : ");
    if (getInt(&pilihanMenu)){
         switch (pilihanMenu)
         {
            case 1:
                system("cls");
                //
                break;
            case 2:
                system("cls");
                //
                break;
            case 3:
                system("cls");
                //
                break;
            case 4:
                system("cls");

                break;
            case 0:
                system("cls");
                regisRT();
                break;
            default:
                printf("\n\t\tPilihan Anda salah. Silahkan coba lagi (dimulai dalam 2 detik).");
                inputSalah();
                d1();
                break;
         }
    } else {
        inputSalah();
        d1();}
 }


void d2()
{
    int pilihanMenu = 0;
    printf("\t\t  ______________________________________________________________________\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                  M E N U  R E G I S T R A S I : R T                  ||\n");
    printf("\t\t||                Mohon Masukkan Daya Listrik Rumah Anda                ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| [1] Daya listrik 450 VA                                              ||\n");
    printf("\t\t|| [2] Daya listrik 900 VA                                              ||\n");
    printf("\t\t|| [3] Daya listrik 1.300 VA                                            ||\n");
    printf("\t\t|| [4] Daya listrik > 1.300 VA                                          ||\n");
    printf("\t\t|| [0] Kembali ke menu sebelumnya                                       ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\n\t\t Pilih daya listrik : ");
    if (getInt(&pilihanMenu)){
         switch (pilihanMenu)
         {
            case 1:
                system("cls");
                //
                break;
            case 2:
                system("cls");
                //
                break;
            case 3:
                system("cls");
                //
                break;
            case 4:
                system("cls");

                break;
            case 0:
                system("cls");
                regisRT();
                break;
            default:
                printf("\n\t\tPilihan Anda salah. Silahkan coba lagi (dimulai dalam 2 detik).");
                inputSalah();
                d2();
                break;
         }
    } else {
        inputSalah();
        d2();}
 }


void d3()
{
    int pilihanMenu = 0;
    printf("\t\t  ______________________________________________________________________\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                  M E N U  R E G I S T R A S I : R T                  ||\n");
    printf("\t\t||                Mohon Masukkan Daya Listrik Rumah Anda                ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| [1] Daya listrik 450 VA                                              ||\n");
    printf("\t\t|| [2] Daya listrik 900 VA                                              ||\n");
    printf("\t\t|| [3] Daya listrik 1.300 VA                                            ||\n");
    printf("\t\t|| [4] Daya listrik > 1.300 VA                                          ||\n");
    printf("\t\t|| [0] Kembali ke menu sebelumnya                                       ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\n\t\t Pilih daya listrik : ");
    if (getInt(&pilihanMenu)){
         switch (pilihanMenu)
         {
            case 1:
                system("cls");
                //
                break;
            case 2:
                system("cls");
                //
                break;
            case 3:
                system("cls");
                //
                break;
            case 4:
                system("cls");

                break;
            case 0:
                system("cls");
                regisRT();
                break;
            default:
                printf("\n\t\tPilihan Anda salah. Silahkan coba lagi (dimulai dalam 2 detik).");
                inputSalah();
                d3();
                break;
         }
    } else {
        inputSalah();
        d3();}
 }


void d4()
{
    int pilihanMenu = 0;
    printf("\t\t  ______________________________________________________________________\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                  M E N U  R E G I S T R A S I : R T                  ||\n");
    printf("\t\t||                Mohon Masukkan Daya Listrik Rumah Anda                ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| [1] Daya listrik 450 VA                                              ||\n");
    printf("\t\t|| [2] Daya listrik 900 VA                                              ||\n");
    printf("\t\t|| [3] Daya listrik 1.300 VA                                            ||\n");
    printf("\t\t|| [4] Daya listrik > 1.300 VA                                          ||\n");
    printf("\t\t|| [0] Kembali ke menu sebelumnya                                       ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\n\t\t Pilih daya listrik : ");
    if (getInt(&pilihanMenu)){
         switch (pilihanMenu)
         {
            case 1:
                system("cls");
                //
                break;
            case 2:
                system("cls");
                //
                break;
            case 3:
                system("cls");
                //
                break;
            case 4:
                system("cls");

                break;
            case 0:
                system("cls");
                regisRT();
                break;
            default:
                printf("\n\t\tPilihan Anda salah. Silahkan coba lagi (dimulai dalam 2 detik).");
                inputSalah();
                d4();
                break;
         }
    } else {
        inputSalah();
        d4();}
 }


void d5()
{
    int pilihanMenu = 0;
    printf("\t\t  ______________________________________________________________________\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                  M E N U  R E G I S T R A S I : R T                  ||\n");
    printf("\t\t||                Mohon Masukkan Daya Listrik Rumah Anda                ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| [1] Daya listrik 450 VA                                              ||\n");
    printf("\t\t|| [2] Daya listrik 900 VA                                              ||\n");
    printf("\t\t|| [3] Daya listrik 1.300 VA                                            ||\n");
    printf("\t\t|| [4] Daya listrik > 1.300 VA                                          ||\n");
    printf("\t\t|| [0] Kembali ke menu sebelumnya                                       ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\n\t\t Pilih daya listrik : ");
    if (getInt(&pilihanMenu)){
         switch (pilihanMenu)
         {
            case 1:
                system("cls");
                //
                break;
            case 2:
                system("cls");
                //
                break;
            case 3:
                system("cls");
                //
                break;
            case 4:
                system("cls");

                break;
            case 0:
                system("cls");
                regisRT();
                break;
            default:
                printf("\n\t\tPilihan Anda salah. Silahkan coba lagi (dimulai dalam 2 detik).");
                inputSalah();
                d5();
                break;
         }
    } else {
        inputSalah();
        d5();}
 }


void e1()
{
    int pilihanMenu = 0;
    printf("\t\t  ______________________________________________________________________\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||               M E N U  R E G I S T R A S I : U S A H A               ||\n");
    printf("\t\t||                Mohon Masukkan Daya Listrik Usaha Anda                ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| [1] Daya listrik 450 VA                                              ||\n");
    printf("\t\t|| [2] Daya listrik 900 VA                                              ||\n");
    printf("\t\t|| [3] Daya listrik 1.300 VA                                            ||\n");
    printf("\t\t|| [4] Daya listrik > 1.300 VA                                          ||\n");
    printf("\t\t|| [0] Kembali ke menu sebelumnya                                       ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\n\t\t Pilih daya listrik : ");
    if (getInt(&pilihanMenu)){
         switch (pilihanMenu)
         {
            case 1:
                system("cls");
                //
                break;
            case 2:
                system("cls");
                //
                break;
            case 3:
                system("cls");
                //
                break;
            case 4:
                system("cls");

                break;
            case 0:
                system("cls");
                regisUsaha();
                break;
            default:
                printf("\n\t\tPilihan Anda salah. Silahkan coba lagi (dimulai dalam 2 detik).");
                inputSalah();
                e1();
                break;
         }
    } else {
        inputSalah();
        e1();}
 }


void e2()
{
    int pilihanMenu = 0;
    printf("\t\t  ______________________________________________________________________\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||               M E N U  R E G I S T R A S I : U S A H A               ||\n");
    printf("\t\t||                Mohon Masukkan Daya Listrik Usaha Anda                ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| [1] Daya listrik 450 VA                                              ||\n");
    printf("\t\t|| [2] Daya listrik 900 VA                                              ||\n");
    printf("\t\t|| [3] Daya listrik 1.300 VA                                            ||\n");
    printf("\t\t|| [4] Daya listrik > 1.300 VA                                          ||\n");
    printf("\t\t|| [0] Kembali ke menu sebelumnya                                       ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\n\t\t Pilih daya listrik : ");
    if (getInt(&pilihanMenu)){
         switch (pilihanMenu)
         {
            case 1:
                system("cls");
                //
                break;
            case 2:
                system("cls");
                //
                break;
            case 3:
                system("cls");
                //
                break;
            case 4:
                system("cls");

                break;
            case 0:
                system("cls");
                regisUsaha();
                break;
            default:
                printf("\n\t\tPilihan Anda salah. Silahkan coba lagi (dimulai dalam 2 detik).");
                inputSalah();
                e2();
                break;
         }
    } else {
        inputSalah();
        e2();}
 }


void e3()
{
    int pilihanMenu = 0;
    printf("\t\t  ______________________________________________________________________\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||               M E N U  R E G I S T R A S I : U S A H A               ||\n");
    printf("\t\t||                Mohon Masukkan Daya Listrik Usaha Anda                ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| [1] Daya listrik 450 VA                                              ||\n");
    printf("\t\t|| [2] Daya listrik 900 VA                                              ||\n");
    printf("\t\t|| [3] Daya listrik 1.300 VA                                            ||\n");
    printf("\t\t|| [4] Daya listrik > 1.300 VA                                          ||\n");
    printf("\t\t|| [0] Kembali ke menu sebelumnya                                       ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\n\t\t Pilih daya listrik : ");
    if (getInt(&pilihanMenu)){
         switch (pilihanMenu)
         {
            case 1:
                system("cls");
                //
                break;
            case 2:
                system("cls");
                //
                break;
            case 3:
                system("cls");
                //
                break;
            case 4:
                system("cls");

                break;
            case 0:
                system("cls");
                regisUsaha();
                break;
            default:
                printf("\n\t\tPilihan Anda salah. Silahkan coba lagi (dimulai dalam 2 detik).");
                inputSalah();
                e3();
                break;
         }
    } else {
        inputSalah();
        e3();}
 }


void keluar()
{
    system("cls");
    printf("\t\t  ______________________________________________________________________\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                       T E R I M A  K A S I H                         ||\n");
    printf("\t\t||                    Sampai jumpa di lain waktu!                       ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\t\t  ______________________________________________________________________  \n");
    exit(0);
}


void repeat()
{
    char pilihanUlang;
    printf("\n\n\t\t Apakah Anda ingin kembali ke menu utama?");
    printf("\n\t\t Ketik [Y] untuk 'Ya' dan [T] untuk 'Tidak'\n");
    printf("\t\t Pilihan: ");
    if (getChar(&pilihanUlang)){
    if(pilihanUlang == 'Y' || pilihanUlang == 'y')
    {
        system("cls");
        menu();
    } else if(pilihanUlang == 'T' || pilihanUlang == 't')
        {
            keluar();
        } else
            {
                printf("\t\t Masukan Anda salah. Silahkan coba lagi.");
                repeat();
            }
    } else { repeat();}
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


void inputSalah()
{
    sleep(2);
    system("cls");
}


void flushIn()
{
    int ch = 0;
    while ((ch = getchar()) != '\n' && ch != -1);
}

