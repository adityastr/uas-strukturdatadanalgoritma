#include <iostream>
#include <string>

using namespace std;

// Struktur data untuk menyimpan informasi kontak
struct Kontak {
    string nama;
    string nomorTelepon;
};

// Fungsi untuk mencari nomor telepon berdasarkan nama
void cariNomorTelepon(Kontak kontak[], int jumlahKontak, string nama) {
    bool ditemukan = false;
    for (int i = 0; i < jumlahKontak; i++) {
        if (kontak[i].nama == nama) {
            cout << "Nomor telepon " << nama << " adalah " << kontak[i].nomorTelepon << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Nomor telepon " << nama << " tidak ditemukan!" << endl;
    }
}

int main() {
    // Buat array kontak dengan 5 elemen
    Kontak kontak[5];

    // Isi array kontak
    kontak[0] = {"John Doe", "081234567890"};
    kontak[1] = {"Muhamad Aditya Saputra", "085678912345"};
    kontak[2] = {"Jane Doe", "081987654321"};
    kontak[3] = {"Budi Setiawan", "085432109876"};
    kontak[4] = {"Rudi Hartono", "081765432109"};

    // Cari nomor telepon berdasarkan nama
    string nama;
    cout << "Masukkan nama: ";
    getline(cin, nama);
    cariNomorTelepon(kontak, 5, nama);

    return 0;
}