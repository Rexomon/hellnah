#include <iostream>
#include "yesmanimconfused.cpp"
using namespace std;

int main()
{
    DataPengunjung pengunjung;
    ofstream file("infopengunjung.txt", ios::trunc);
    int kamarterisi = 0;
    int pilihan;

    do
    {
        cout << "Pendataan Pengunjung Hostel" << endl;
        cout << "1. Pendaftaran Pengunjung" << endl;
        cout << "2. Tampilkan Data Pengunjung" << endl;
        cout << "3. Tampilkan Informasi Kamar" << endl;
        // cout << "4. Keluar dari Menu" << endl;
        cout << "Pilih Menu: ";
        cin >> pilihan;
        system("clear");
        cout << endl;

        if (pilihan == 1)
        {
            daftarPengunjung(pengunjung, kamarterisi);
            system("clear");
        }
        else if (pilihan == 2)
        {
            tampilkanDataPengunjung(pengunjung);
        }
        else if (pilihan == 3)
        {
            tampilkanInfoKamar(kamarterisi);
            cout << endl;
        }
        else if (pilihan == 4)
        {
            cout << "Anda keluar dari menu, terima kasih!";
            return 0;
        }
        else
        {
            cout << "Anda memasukkan nilai yang salah!";
            cout << endl;
        }
    } while (pilihan != 4);
    
}
