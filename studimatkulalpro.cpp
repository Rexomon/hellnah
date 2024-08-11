#include <iostream>

using namespace std;

string HurufAcak()
{
    string huruf = "";
    for (int i = 0; i < 2; ++i)
    {
        char hurufs = 'A' + rand() % 26;
        huruf += hurufs;
    }
    return huruf;
}

string AngkaAcak()
{
    string nomor = "";
    for (int i = 0; i < 3; ++i)
    {
        int number = rand() % 10;
        nomor += to_string(number);
    }
    return nomor;
}

string CetakResi()
{
    return HurufAcak() + AngkaAcak();
}

void cetakBarang(string &namapengirim, string alamat[], string barang[], int berat[], string resi[], int jumlahbarang)
{
    cout << "================================" << endl;
    for (int i = 0; i < jumlahbarang; i++)
    {
        cout << endl;
        cout << "Nama Pengirim: " << namapengirim << endl;
        cout << "Alamat Tujuan: " << alamat[i] << endl;
        cout << "Nama Barang: " << barang[i] << endl;
        cout << "Berat: " << berat[i] << " kg" << endl;
        cout << "Resi: " << resi[i] << endl;
        cout << endl;
    }
    cout << "================================" << endl;
}

void sortingData(string &namapengirim, string alamat[], string barang[], int berat[], string resi[], int jumlahbarang)
{
    for (int i = 0; i < jumlahbarang; i++)
    {
        for (int j = 0; j < jumlahbarang; j++)
        {
            if (berat[i] > berat[j])
            {
                int temp = berat[i];
                berat[i] = berat[j];
                berat[j] = temp;

                string tempStr = barang[i];
                barang[i] = barang[j];
                barang[j] = tempStr;

                string almt = alamat[i];
                alamat[i] = alamat[j];
                alamat[j] = almt;

                string rsi = resi[i];
                resi[i] = resi[j];
                resi[j] = rsi;
            }
        }
    }
}

void dataTersorting(string &namapengirim, string alamat[], string barang[], int berat[], string resi[], int jumlahbarang)
{
    sortingData(namapengirim, alamat, barang, berat, resi, jumlahbarang);
    cetakBarang(namapengirim, alamat, barang, berat, resi, jumlahbarang);
    cout << endl;

    char pil;
    cout << "Mau cek barang(y/n)? ";
    cin >> pil;
    cout << endl;

    if (pil == 'y')
    {
        bool kargo = false;
        bool reguler = false;

        for (int i = 0; i < jumlahbarang; i++)
        {
            if (berat[i] > 10)
            {
                kargo = true;
            }
        }

        if (kargo)
        {
            cout << "================================" << endl;
            cout << "Daftar Barang Masuk Kargo" << endl;
            cout << "================================" << endl;
            for (int i = 0; i < jumlahbarang; i++)
            {
                if (berat[i] > 10)
                {
                    cout << "Pengirim: " << namapengirim << endl;
                    cout << "Alamat Tujuan: " << alamat[i] << endl;
                    cout << "Nama Barang: " << barang[i] << " " << berat[i] << " kg" << endl;
                    cout << "Resi: " << resi[i] << endl;
                    cout << endl;
                }
            }
        }

        for (int i = 0; i < jumlahbarang; i++)
        {
            if (berat[i] <= 10)
            {
                reguler = true;
            }
        }

        if (reguler)
        {
            cout << "================================" << endl;
            cout << "Daftar Barang Masuk Reguler" << endl;
            cout << "================================" << endl;
            for (int i = 0; i < jumlahbarang; i++)
            {
                if (berat[i] <= 10)
                {
                    cout << "Pengirim: " << namapengirim << endl;
                    cout << "Alamat Tujuan: " << alamat[i] << endl;
                    cout << "Nama Barang: " << barang[i] << " " << berat[i] << " kg" << endl;
                    cout << "Resi: " << resi[i] << endl;
                    cout << endl;
                }
            }
        }
    }
}

void CariResi(string &namapengirim, string alamat[], string barang[], int berat[], string resi[], int jumlahbarang)
{
    string cariResi;
    cout << "Masukkan Resi yang ingin dicari: ";
    cin >> cariResi;

    bool ketemu = false;
    for (int i = 0; i < jumlahbarang; i++)
    {
        if (resi[i] == cariResi)
        {
            cout << "================================" << endl;
            cout << "Detail Barang dengan Resi " << cariResi << endl;
            cout << "================================" << endl;
            cout << "Pengirim: " << namapengirim << endl;
            cout << "Alamat Tujuan: " << alamat[i] << endl;
            cout << "Nama Barang: " << barang[i] << " " << berat[i] << " kg" << endl;
            cout << "Resi: " << resi[i] << endl;
            cout << endl;
            ketemu = true;
            break; // keluar dari loop jika resi ditemukan
        }
    }
    if (!ketemu)
    {
        cout << "Resi tidak ditemukan." << endl;
    }
}

void inputBarang(string &namapengirim, string alamat[], string barang[], int berat[], string resi[], int &jumlahbarang)
{
    srand(time(0));

    cout << "Masukkan Nama Pengirim: ";
    cin.ignore();
    getline(cin, namapengirim);
    cout << "Jumlah Barang: ";
    cin >> jumlahbarang;

    cout << endl;

    for (int i = 0; i < jumlahbarang; i++)
    {
        cin.ignore();
        cout << "Nama Pengirim: " << namapengirim << endl;
        cout << "Alamat Tujuan ke-" << i + 1 << ": ";
        getline(cin, alamat[i]);
        cout << "Masukkan nama barang ke-" << i + 1 << ": ";
        cin >> barang[i];
        cout << "Masukkan berat barang " << barang[i] << ": ";
        cin >> berat[i];
        resi[i] = CetakResi();
        // cout << "Resi: " << resi[i] << endl;
        cout << endl;
    }

    cout << endl;
    cetakBarang(namapengirim, alamat, barang, berat, resi, jumlahbarang);
    cout << endl;

    char pil;
    cout << "Ingin Sorting barang?(y/n): ";
    cin >> pil;
    cout << endl;

    if (pil == 'y')
    {
        dataTersorting(namapengirim, alamat, barang, berat, resi, jumlahbarang);
    }
}

int main()
{
    int jumlahbarang = 0;
    int max_barang = 100;
    string namapengirim;
    string alamat[max_barang];
    string barang[max_barang];
    string resi[max_barang];
    int berat[max_barang];
    int pil;
    do
    {
        cout << "===================" << endl;
        cout << "Jasa Ekspedisi" << endl;
        cout << "===================" << endl;
        cout << "1. Masukkan Pengirim dan Barang" << endl;
        cout << "2. Cari Resi" << endl;
        cout << "3. Keluar" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> pil;
        cout << endl;

        if (pil == 1)
        {
            inputBarang(namapengirim, alamat, barang, berat, resi, jumlahbarang);
        }
        else if (pil == 2)
        {
            CariResi(namapengirim, alamat, barang, berat, resi, jumlahbarang);
        }
        else if (pil == 3)
        {
            cout << "Terimakasih, sampai jumpa!" << endl;
        }

    } while (pil != 3);
}
