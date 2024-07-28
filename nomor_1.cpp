#include <iostream>
#include <string>

using namespace std;

// Struktur data untuk menyimpan informasi mahasiswa
struct Mahasiswa {
    string nama;
    string npm;
    string jurusan;
};

// Kelas Queue untuk menyimpan data mahasiswa
class Queue {
private:
    Mahasiswa* data;
    int front;
    int rear;
    int kapasitas;
    int jumlah;

public:
    // Konstruktor untuk inisialisasi queue
    Queue(int kapasitas) {
        this->kapasitas = kapasitas;
        this->data = new Mahasiswa[kapasitas];
        this->front = 0;
        this->rear = 0;
        this->jumlah = 0;
    }

    // Destruktor untuk menghapus memori yang dialokasikan
    ~Queue() {
        delete[] data;
    }

    // Fungsi untuk menambah elemen ke queue (enqueue)
    void enqueue(Mahasiswa mahasiswa) {
        if (jumlah < kapasitas) {
            data[rear] = mahasiswa;
            rear = (rear + 1) % kapasitas;
            jumlah++;
            cout << "Mahasiswa " << mahasiswa.nama << " berhasil ditambahkan ke queue." << endl;
        } else {
            cout << "Queue sudah penuh. Tidak dapat menambahkan mahasiswa lagi." << endl;
        }
    }

    // Fungsi untuk menghapus elemen dari queue (dequeue)
    void dequeue() {
        if (jumlah > 0) {
            Mahasiswa mahasiswa = data[front];
            front = (front + 1) % kapasitas;
            jumlah--;
            cout << "Mahasiswa " << mahasiswa.nama << " berhasil dihapus dari queue." << endl;
        } else {
            cout << "Queue kosong. Tidak dapat menghapus mahasiswa." << endl;
        }
    }

    // Fungsi untuk menampilkan elemen di depan queue (front)
    void tampilkanFront() {
        if (jumlah > 0) {
            Mahasiswa mahasiswa = data[front];
            cout << "Mahasiswa di depan queue: " << mahasiswa.nama << " (" << mahasiswa.npm << ")" << endl;
        } else {
            cout << "Queue kosong." << endl;
        }
    }

    // Fungsi untuk menampilkan elemen di belakang queue (rear)
    void tampilkanRear() {
        if (jumlah > 0) {
            Mahasiswa mahasiswa = data[(rear - 1 + kapasitas) % kapasitas];
            cout << "Mahasiswa di belakang queue: " << mahasiswa.nama << " (" << mahasiswa.npm << ")" << endl;
        } else {
            cout << "Queue kosong." << endl;
        }
    }
};

int main() {
    // Buat queue dengan kapasitas 5
    Queue queue(5);

    // Tambah mahasiswa ke queue
    Mahasiswa mahasiswa1 = {"John Doe", "1234567890", "Informatika"};
    queue.enqueue(mahasiswa1);

    Mahasiswa mahasiswa2 = {"Muhamad Aditya Saputra", "9876543210", "Informatika"};
    queue.enqueue(mahasiswa2);

    // Tampilkan elemen di depan queue
    queue.tampilkanFront();

    // Tampilkan elemen di belakang queue
    queue.tampilkanRear();

    // Hapus mahasiswa dari queue
    queue.dequeue();

    // Tampilkan elemen di depan queue
    queue.tampilkanFront();

    return 0;
}