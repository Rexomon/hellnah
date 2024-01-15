#include <iostream>
#include <fstream>
using namespace std;

struct DataPengunjung
{
    long long int ktp;
    int nomorkamar;
    string nama, notelp, alamat, email;
};

void daftarPengunjung(DataPengunjung pengunjung, int &kamarterisi)
{
    ofstream daftarpengunjung;
    int jumlahpengunjung;
    daftarpengunjung.open("infopengunjung.txt");

    cout << "Pengisian Data Pengunjung" << endl;
    cout << "Masukkan jumlah pengunjung: ";
    cin >> jumlahpengunjung;
    cout << endl;

    for (int i = 0; i < jumlahpengunjung; i++)
    {
        cin.ignore();
        cout << "Masukkan Nama: ";
        getline(cin, pengunjung.nama);

        cout << "Masukkan Nomor KTP: ";
        cin >> pengunjung.ktp;

        cin.ignore();
        cout << "Masukkan Email: ";
        getline(cin, pengunjung.email);

        cout << "Masukkan No Telpon: ";
        getline(cin, pengunjung.notelp);

        cout << "Masukkan Alamat: ";
        getline(cin, pengunjung.alamat);

        cout << "Masukkan Nomor Kamar: ";
        cin >> pengunjung.nomorkamar;
        cout << endl;

        kamarterisi++;

        daftarpengunjung << "\t Pengunjung Ke-" << i + 1 << endl;
        daftarpengunjung << "Nama Pengunjung            : " << pengunjung.nama << endl;
        daftarpengunjung << "Nomor KTP Pengunjung       : " << pengunjung.ktp << endl;
        daftarpengunjung << "Alamat Email               : " << pengunjung.email << endl;
        daftarpengunjung << "No Telpon Pengunjung       : " << pengunjung.notelp << endl;
        daftarpengunjung << "Alamat                     : " << pengunjung.alamat << endl;
        daftarpengunjung << "Nomor Kamar Pengunjung     : " << pengunjung.nomorkamar << endl;
        daftarpengunjung << endl;
    }

    daftarpengunjung.close();
}

void tampilkanDataPengunjung(DataPengunjung pengunjung)
{
    ifstream filepengunjung("infopengunjung.txt");

    if (filepengunjung.peek() == ifstream::traits_type::eof())
    {
        cout << "Data pengunjung tidak ada!" << endl;
        cout << endl;
    }
    else
    {
        string data;
        while (getline(filepengunjung, data))
        {
            cout << data << endl;
        }
    }

    filepengunjung.close();
};

int hitungJumlahKamar(int &kamarterisi)
{
    int jumlahkamar = 20;
    int kamarkosong = jumlahkamar - kamarterisi;
    return kamarkosong;
};

void tampilkanInfoKamar(int kamarterisi)
{
    cout << "Info jumlah Kamar" << endl;
    cout << "Kamar berjumlah: " << 20 << endl;
    cout << "Kamar Tersisa: " << (20 - kamarterisi) << endl;
    cout << "Kamar Terisi: " << kamarterisi << endl;
}
