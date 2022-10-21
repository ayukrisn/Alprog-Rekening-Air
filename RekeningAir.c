#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include <time.h>

#define biayaAdmin          3000         //Biaya administrasi Rp3000
#define dendaRT             8000         //Denda pemakaian 10 sampai 100 m3 Rp8000
#define dendaUsaha          10000        //Denda pemakaian melebihi 100 m3 Rp10000
#define BPM_R               5000         //biaya pemeliharaan meter rumah tangga Rp.5000
#define BPM_U               5000         //biaya pemeliharaan meter usaha Rp.5000
#define tempo               21           //tempo bayar

void menu(),
     registrasi1(), regisKelompok(), regisRTSubsidi(), regisRTNonSubsidi(), regisUsaha(),
     inputPemakaian();
     /*d11(), d12(), d13(), d14(),
     d21(), d22(), d23(), d24(),
     d31(), d32(), d33(), d34(),
     d41(), d42(), d43(), d44(),
     d51(), d52(), d53(), d54();*/
     /*e11(), e12(), e13(), e14(),
     e21(), e22(), e23(), e24(),
     e31(), e32(), e33(), e34(),*/

char nama[255],
     alamat[255];

int  pBulanLalu, pBulanIni, totalPemakaian,
     tarifPemakaian, denda, totalBiaya;

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
    printf("\t\t|| [1] Rumah Tangga / Non Niaga Bersubsidi                              ||\n");
    printf("\t\t|| [2] Rumah Tangga / Non Niaga Tanpa Subsidi                           ||\n");
    printf("\t\t|| [3] Usaha / Niaga                                                    ||\n");
    printf("\t\t|| [0] Kembali ke menu utama                                            ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\n\t\t Pilih tipe kelompok fasilitas : ");
    if (getInt(&pilihanMenu)){
         switch (pilihanMenu)
         {
            case 1:
                system("cls");
                regisRTSubsidi();
                break;
            case 2:
                system("cls");
                regisRTNonSubsidi();
                break;
            case 3:
                system("cls");
                regisUsaha();
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


void regisRTSubsidi()
{
    int pilihanMenu = 0;
    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t  ======================================================================  \n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                 RUMAH TANGGA / NON NIAGA BERSUBSIDI                  ||\n");
    printf("\t\t||           Mohon untuk memilih tipe rumah Anda pada daftar ini        ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t|| > Rumah Tangga A1 [Lebar Jalan : 0-3,99 meter]                       ||\n");
    printf("\t\t||   [1] Daya Listrik 450 VA || D1-1                                    ||\n");
    printf("\t\t||   [2] Daya Listrik 900 VA || D1-2                                    ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| > Rumah Tangga A2 [Lebar Jalan : 4-6,99 meter]                       ||\n");
    printf("\t\t||   [3] Daya Listrik 450 VA || D2-1                                    ||\n");
    printf("\t\t||   [4] Daya Listrik 900 VA || D2-2                                    ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| > Rumah Tangga A3 [Lebar Jalan : 7-10 meter]                         ||\n");
    printf("\t\t||   [5] Daya Listrik 450 VA || D3-1                                    ||\n");
    printf("\t\t||   [6] Daya Listrik 900 VA || D3-2                                    ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| > Rumah Tangga A4 [Lebar Jalan : >10 meter]                          ||\n");
    printf("\t\t||   [7] Daya Listrik 450 VA || D4-1                                    ||\n");
    printf("\t\t||   [8] Daya Listrik 900 VA || D4-2                                    ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t||   [0] Kembali ke menu sebelumnya                                     ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\n\t\t Mohon masukkan pilihan sesuai dengan tipe rumah Anda. ");
    printf("\n\t\t  Contoh: 1 ");
    printf("\n\t\t  Pilihan : ");
    if (getInt(&pilihanMenu)){
         switch (pilihanMenu)
         {
            case 1:
                system("cls");
                d11();
                break;
            case 2:
                system("cls");
                //d12();
                break;
            case 3:
                system("cls");
                //d21();
                break;
            case 4:
                system("cls");
                //d22();
                break;
            case 5:
                system("cls");
                //d31();
            case 6:
                system("cls");
                //d32();
            case 7:
                system("cls");
                //d41();
            case 8:
                system("cls");
                //d42();
            case 0:
                system("cls");
                regisKelompok();
                break;
            default:
                printf("\n\t\tPilihan Anda salah. Silahkan coba lagi (dimulai dalam 2 detik).");
                inputSalah();
                regisRTSubsidi();
                break;
         }
    } else {
        inputSalah();
        regisRTSubsidi();}
 }


void regisRTNonSubsidi()
{
    int pilihanMenu = 0;
    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t  ======================================================================  \n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||               RUMAH TANGGA / NON NIAGA TANPA BERSUBSIDI              ||\n");
    printf("\t\t||           Mohon untuk memilih tipe rumah Anda pada daftar ini        ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t|| > Rumah Tangga A1 [Lebar Jalan : 0-3,99 meter]                       ||\n");
    printf("\t\t||   [1]  Daya Listrik  1.300 VA || D1-3                                ||\n");
    printf("\t\t||   [2]  Daya Listrik >1.300 VA || D1-4                                ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| > Rumah Tangga A2 [Lebar Jalan : 4-6,99 meter]                       ||\n");
    printf("\t\t||   [3]  Daya Listrik  1.300 VA || D2-3                                ||\n");
    printf("\t\t||   [4]  Daya Listrik >1.300 VA || D2-4                                ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| > Rumah Tangga A3 [Lebar Jalan : 7-10 meter]                         ||\n");
    printf("\t\t||   [5]  Daya Listrik  1.300 VA || D3-3                                ||\n");
    printf("\t\t||   [6]  Daya Listrik >1.300 VA || D3-4                                ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| > Rumah Tangga A4 [Lebar Jalan : >10 meter]                          ||\n");
    printf("\t\t||   [7]  Daya Listrik  1.300 VA || D4-3                                ||\n");
    printf("\t\t||   [8]  Daya Listrik >1.300 VA || D4-4                                ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| > Rumah Tangga A5 [Persil Rumah terdapat Jenis Usaha]                ||\n");
    printf("\t\t||   [9]  Daya Listrik    450 VA || D5-1                                ||\n");
    printf("\t\t||   [10] Daya Listrik    900 VA || D5-2                                ||\n");
    printf("\t\t||   [11] Daya Listrik  1.300 VA || D5-3                                ||\n");
    printf("\t\t||   [12] Daya Listrik >1.300 VA || D5-4                                ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t||   [0] Kembali ke menu sebelumnya                                     ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\n\t\t Mohon masukkan pilihan sesuai dengan tipe rumah Anda. ");
    printf("\n\t\t  Contoh: 1 ");
    printf("\n\t\t  Pilihan : ");
    if (getInt(&pilihanMenu)){
         switch (pilihanMenu)
         {
            case 1:
                system("cls");
                //d13();
                break;
            case 2:
                system("cls");
                //d14();
                break;
            case 3:
                system("cls");
                //d23();
                break;
            case 4:
                system("cls");
                //d24();
                break;
            case 5:
                system("cls");
                //d33();
            case 6:
                system("cls");
                //d34();
            case 7:
                system("cls");
                //d43();
            case 8:
                system("cls");
                //d44();
            case 9:
                system("cls");
                //d51();
            case 10:
                system("cls");
                //d52();
            case 11:
                system("cls");
                //d53();
            case 12:
                system("cls");
                //d54();
            case 0:
                system("cls");
                regisKelompok();
                break;
            default:
                printf("\n\t\tPilihan Anda salah. Silahkan coba lagi (dimulai dalam 2 detik).");
                inputSalah();
                regisRTNonSubsidi();
                break;
         }
    } else {
        inputSalah();
        regisRTNonSubsidi();}
 }



void regisUsaha()
{
int pilihanMenu = 0;
    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t  ======================================================================  \n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                             USAHA / NIAGA                            ||\n");
    printf("\t\t||       Mohon untuk memilih tipe usaha/niaga Anda pada daftar ini      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t|| > Niaga Kecil [Lebar Jalan : 0-6,99 meter]                           ||\n");
    printf("\t\t||   [1]  Daya Listrik    450 VA || E1-1                                ||\n");
    printf("\t\t||   [2]  Daya Listrik    900 VA || E1-2                                ||\n");
    printf("\t\t||   [3]  Daya Listrik  1.300 VA || E1-3                                ||\n");
    printf("\t\t||   [4]  Daya Listrik >1.300 VA || E1-4                                ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| > Niaga Sedang [Lebar Jalan : 7-10 meter]                            ||\n");
    printf("\t\t||   [5]  Daya Listrik    450 VA || E2-1                                ||\n");
    printf("\t\t||   [6]  Daya Listrik    900 VA || E2-2                                ||\n");
    printf("\t\t||   [7]  Daya Listrik  1.300 VA || E2-3                                ||\n");
    printf("\t\t||   [8]  Daya Listrik >1.300 VA || E2-4                                ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t|| > Niaga Besar [Lebar Jalan : >10 meter]                              ||\n");
    printf("\t\t||   [9]  Daya Listrik    450 VA || E3-1                                ||\n");
    printf("\t\t||   [10] Daya Listrik    900 VA || E3-2                                ||\n");
    printf("\t\t||   [11] Daya Listrik  1.300 VA || E3-3                                ||\n");
    printf("\t\t||   [12] Daya Listrik >1.300 VA || E3-4                                ||\n");
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t||   [0] Kembali ke menu sebelumnya                                     ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\n\t\t Mohon masukkan pilihan sesuai dengan tipe rumah Anda. ");
    printf("\n\t\t  Contoh: 1 ");
    printf("\n\t\t  Pilihan : ");
    if (getInt(&pilihanMenu)){
         switch (pilihanMenu)
         {
            case 1:
                system("cls");
                //e11();
                break;
            case 2:
                system("cls");
                //e12();
                break;
            case 3:
                system("cls");
                //e13();
                break;
            case 4:
                system("cls");
                //e14();
                break;
            case 5:
                system("cls");
                //e21();
            case 6:
                system("cls");
                //e22();
            case 7:
                system("cls");
                //d23();
            case 8:
                system("cls");
                //d24();
            case 9:
                system("cls");
                //e31();
            case 10:
                system("cls");
                //e32();
            case 11:
                system("cls");
                //d33();
            case 12:
                system("cls");
                //d34();
            case 0:
                system("cls");
                regisKelompok();
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


void inputPemakaian()
{
    printf("\t\t  ______________________________________________________________________\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      INPUT PEMAKAIAN AIR MINUM                       ||\n");
    printf("\t\t||            Mohon Masukkan Pemakaian Air Minum Anda (dalam m3)        ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||______________________________________________________________________||\n");
    printf("\t\t  Mohon untuk memasukkan angka seperti contoh di bawah. \n");
    printf("\t\t  Contoh: 1300 \n");
    printf("\t\t  Pemakaian air minum bulan lalu : ");
    if(getInt(&pBulanLalu)){
        printf("\t\t  Pemakaian air minum bulan ini: ");
        if(getInt(&pBulanIni))
        {
            printf("\n\t\t  Total pemakaian : %d m3.\n", totalPemakaian = pBulanIni - pBulanLalu);
            printf("\t\t  Anda akan diarahkan pada total biaya dalam 5 detik lagi.");
            sleep(5);
            system("cls");
        }
        else
        {
            inputSalah();
            inputPemakaian();
        }
   } else
    {
            inputSalah();
            inputPemakaian();
    }
}


void d11()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*1780;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*2060;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*5880;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaRT;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : D1-1 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void d12()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*2060;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*2340;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*5940;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaRT;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : D1-2 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void d21()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*2340;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*2620;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*6000;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaRT;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : D2-1 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void d22()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*2620;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*2900;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*6060;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaRT;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : D2-2 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void d31()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*2900;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*3180;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*6120;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaRT;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : D3-1 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}



void d32()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*3180;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*3460;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*6180;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaRT;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : D3-2 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void d41()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*3460;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*3740;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*6240;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaRT;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : D4-1 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void d42()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*3740;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*4020;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*6300;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaRT;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : D4-2 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void d13()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*6340;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*9200;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*9600;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaRT;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : D1-3 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void d14()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*6420;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*9350;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*9650;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaRT;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : D1-4 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void d23()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*6490;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*9500;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*9800;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaRT;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : D2-3 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void d24()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*6570;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*9650;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*9950;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaRT;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : D2-4 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void d33()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*6640;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*9800;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*10100;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaRT;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : D3-3 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void d34()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*6720;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*9950;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*10250;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaRT;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : D3-4 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void d43()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*6790;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*10100;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*10400;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaRT;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : D4-3 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void d44()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*6870;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*10250;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*10550;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaRT;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : D4-4 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void d51()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*6940;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*10400;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*10700;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaRT;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : D5-1 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void d52()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*7020;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*10550;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*10850;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaRT;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : D5-2 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void d53()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*7090;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*10700;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*11000;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaRT;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : D5-3 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void d54()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*7170;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*10850;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*11150;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaRT;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : D5-4 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void e11()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*9200;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*9850;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*10950;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaU;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : E1-1 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void e12()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*9500;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*10150;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*11250;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaU;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : E1-2 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void e13()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*9800;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*10450;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*11550;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaU;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : E1-3 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void e14()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*10100;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*10750;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*11850;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaU;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : E1-4 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void e21()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*10400;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*11050;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*12150;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaU;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : E2-1 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void e22()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*10700;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*11350;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*12550;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaU;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : E2-2 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void e23()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*11000;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*11650;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*13150;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaU;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : E2-3 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void e24()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*11300;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*11950;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*13950;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaU;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : E2-4 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void e31()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*11600;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*12250;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*14750;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaU;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : E3-1 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void e32()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*11900;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*12550;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*15050;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaU;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : E3-2 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void e33()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*12200;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*12850;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*15850;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaU;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : E3-3 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

}


void e34()
{
    inputPemakaian();
    if (totalPemakaian <= 10) {
        tarifPemakaian = totalPemakaian*12500;
    } else if (11 <= totalPemakaian <= 20) {
        tarifPemakaian = totalPemakaian*13150;
    } else if ( totalPemakaian > 20) {
        tarifPemakaian = totalPemakaian*16650;}

    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if ((tm.tm_mday - tempo) <= 0) denda = 0;
    else denda = dendaU;

    totalBiaya = totalPemakaian + BPM_R + biayaAdmin + denda;

    printf("\t\t    __________________________________________________________________    \n");
    printf("\t\t||======================================================================||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t||                      TOTAL PEMBAYARAN AIR MINUM                      ||\n");
    printf("\t\t||                                                                      ||\n");
    printf("\t\t|| ==================================================================== ||\n");
    printf("\t\t                          [Identitas Pelanggan] \n");

    printf("\t\t     Nama     : %s \n", nama);
    printf("\t\t     Alamat   : %s \n", alamat);
    printf("\t\t|| -------------------------------------------------------------------- ||\n");
    printf("\t\t                             [Daftar Biaya] \n" );

    printf("\t\t     Golongan           : E3-4 \n");
    printf("\t\t     Tanggal            : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Jatuh Tempo        : %d-%d-%d\n", tempo, tm.tm_mon+1, tm.tm_year+1900);
    printf("\t\t     Tarif Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t     Biaya Administrasi : %d \n", biayaAdmin);
    printf("\t\t     Biaya Pemeliharaan : %d \n", BPM_R);
    printf("\t\t     Denda              : %d \n", denda);
    printf("\t\t   --------------------------------------------------------------------   \n");
    printf("\t\t     Total Pemakaian    : %d \n", tarifPemakaian);
    printf("\t\t||______________________________________________________________________||\n");
    repeat();

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
