#include <iostream>
#include <string>

using namespace std;

struct Transaksi {
    string waktu;
    string jenisPembayaran;
    int jumlah;
};

void selectionSort(Transaksi arr[], int n, bool sortByWaktu) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (sortByWaktu) {
                if (arr[j].waktu < arr[minIndex].waktu) {
                    minIndex = j;
                }
            } else {
                if (arr[j].jenisPembayaran < arr[minIndex].jenisPembayaran) {
                    minIndex = j;
                }
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void printTransaksi(Transaksi arr[], int n) {
    cout << "No.\tWaktu\tJenis Pembayaran\tJumlah" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << arr[i].waktu << "\t" << arr[i].jenisPembayaran << "\t" << arr[i].jumlah << endl;
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah transaksi: ";
    cin >> n;

    Transaksi transaksi[n];

    for (int i = 0; i < n; i++) {
        cout << "Masukkan waktu transaksi " << i + 1 << ": ";
        cin >> transaksi[i].waktu;
        cout << "Masukkan jenis pembayaran transaksi " << i + 1 << ": ";
        cin >> transaksi[i].jenisPembayaran;
        cout << "Masukkan jumlah transaksi " << i + 1 << ": ";
        cin >> transaksi[i].jumlah;
    }

    cout << "Pilih metode pengurutan:" << endl;
    cout << "1. Waktu" << endl;
    cout << "2. Jenis Pembayaran" << endl;
    int pilihan;
    cin >> pilihan;

    if (pilihan == 1) {
        selectionSort(transaksi, n, true);
    } else if (pilihan == 2) {
        selectionSort(transaksi, n, false);
    } else {
        cout << "Pilihan tidak valid" << endl;
        return 1;
    }

    printTransaksi(transaksi, n);

    return 0;
}