#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string nama;
    int jumlah;
    string tipe;
    Node* next;

    Node(string nama, int jumlah, string tipe) {
        this->nama = nama;
        this->jumlah = jumlah;
        this->tipe = tipe;
        this->next = NULL;
    }
};

class ManajemenProduk {
private:
    Node* head;

public:
    ManajemenProduk() {
        head = NULL;
    }

    void tambahProduk() {
        string nama;
        int jumlah;
        string tipe;
        cout << "========== TAMBAH PRODUK ==========" << endl;
        cout << "Nama Produk : ";
        getline(cin, nama);
        cout << "Jumlah Produk : ";
        cin >> jumlah;
        cin.ignore(); // Membersihkan buffer input
        cout << "Tipe Produk : ";
        getline(cin, tipe);

        Node* newNode = new Node(nama, jumlah, tipe);
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }

        cout << "Produk berhasil ditambahkan!" << endl;
    }

    void tampilkanSemuaProduk() {
        cout << "========== SEMUA DATA PRODUK ==========" << endl;
        if (head == NULL) {
            cout << "Belum ada data produk yang tersimpan." << endl;
        }
        else {
            Node* current = head;
            int posisi = 1;
            while (current != NULL) {
                cout << "Produk " << posisi << endl;
                cout << "Nama Produk: " << current->nama << endl;
                cout << "Jumlah Produk: " << current->jumlah << endl;
                cout << "Tipe Produk: " << current->tipe << endl;
                cout << endl;

                current = current->next;
                posisi++;
            }
        }
    }

    void cariProdukByNama() {
        cout << "========== CARI PRODUK BERDASARKAN NAMA ==========" << endl;
        if (head == NULL) {
            cout << "Belum ada data produk yang tersimpan." << endl;
        }
        else {
            string targetNama;
            cout << "Nama Produk yang dicari: ";
            getline(cin, targetNama);

            Node* current = head;
            int posisi = 1;
            bool ditemukan = false;
            while (current != NULL) {
                if (current->nama == targetNama) {
                    cout << "Produk ditemukan pada posisi " << posisi << endl;
                    cout << "Nama Produk: " << current->nama << endl;
                    cout << "Jumlah Produk: " << current->jumlah << endl;
                    cout << "Tipe Produk: " << current->tipe << endl;
                    cout << endl;

                    ditemukan = true;
                }

                current = current->next;
                posisi++;
            }

            if (!ditemukan) {
                cout << "Nama produk " << targetNama << " TIDAK DITEMUKAN" << endl;
            }
        }
    }

    void algoritmaSortByJumlahProduk() {
        if (head == NULL || head->next == NULL) {
            return; // Tidak perlu sorting jika hanya terdapat 0 atau 1 node
        }

        bool swapped;
        Node* current;
        Node* last = NULL;
        do {
            swapped = false;
            current = head;

            while (current->next != last) {
                if (current->jumlah < current->next->jumlah) {
                    swapNodes(current, current->next);
                    swapped = true;
                }
                current = current->next;
            }
            last = current;
        } while (swapped);
    }

private:
    void swapNodes(Node* a, Node* b) {
        string tempNama = a->nama;
        int tempJumlah = a->jumlah;
        string tempTipe = a->tipe;

        a->nama = b->nama;
        a->jumlah = b->jumlah;
        a->tipe = b->tipe;

        b->nama = tempNama;
        b->jumlah = tempJumlah;
        b->tipe = tempTipe;
    }
};

int main() {
    ManajemenProduk manajemenProduk;
    int pilihan;
    do {
        cout << "========== APLIKASI MANAJEMEN DATA PRODUK ==========" << endl;
        cout << "1. Tambah Produk" << endl;
        cout << "2. Tampilkan Semua Produk" << endl;
        cout << "3. Cari Produk berdasarkan Nama" << endl;
        cout << "4. Urutkan Produk berdasarkan Jumlah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            manajemenProduk.tambahProduk();
            break;
        case 2:
            manajemenProduk.tampilkanSemuaProduk();
            break;
        case 3:
            manajemenProduk.cariProdukByNama();
            break;
        case 4:
            manajemenProduk.algoritmaSortByJumlahProduk();
            cout << "Produk berhasil diurutkan berdasarkan jumlah." << endl;
            break;
        case 5:
            cout << "Terima kasih! Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }

        cout << endl;
    } while (pilihan != 5);

    return 0;
}



//NO.2
// BubbleSort, linear seacrh, linked list
//NO.3
// Deklarasi array dengan ukuran yang cukup untuk menampung elemen
//  Tentukan variabel posisi front dan rear
//  Implementasi fungsi enqueue() --> menambahkan
//  Implementasikan fungsi dequeue() --> menghapus
//  Implementasikan fungsi isFull() --> antrian penuh
//  Implementasikan fungsi isEmpty() --> antrian kosong


//NO.4
//menyimpan dan mengelola data dalam urutan Last-In-First-Out (LIFO).


//NO.5
//A. 5
//B. inorder simpul kiri akar bawah kiri simpul kanan

