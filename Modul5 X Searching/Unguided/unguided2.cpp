#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string isbn, judul, penulis;
    Buku* next;
};

Buku* head = nullptr;

void tambahBuku(string isbn, string judul, string penulis) {
    Buku* newNode = new Buku;
    newNode->isbn = isbn;
    newNode->judul = judul;
    newNode->penulis = penulis;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Buku* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Buku berhasil ditambahkan!\n";
}

void hapusBuku(string isbn) {
    if (head == nullptr) {
        cout << "Tidak ada buku dalam daftar.\n";
        return;
    }

    Buku* temp = head;
    Buku* prev = nullptr;

    if (temp != nullptr && temp->isbn == isbn) {
        head = temp->next;
        delete temp;
        cout << "Buku dengan ISBN " << isbn << " berhasil dihapus.\n";
        return;
    }

    while (temp != nullptr && temp->isbn != isbn) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Buku dengan ISBN " << isbn << " tidak ditemukan.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Buku berhasil dihapus.\n";
}

void perbaruiBuku(string isbn) {
    Buku* temp = head;
    while (temp != nullptr) {
        if (temp->isbn == isbn) {
            cout << "Masukkan judul baru: ";
            getline(cin, temp->judul);
            cout << "Masukkan penulis baru: ";
            getline(cin, temp->penulis);
            cout << "Data buku berhasil diperbarui.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Buku dengan ISBN " << isbn << " tidak ditemukan.\n";
}

void lihatBuku() {
    if (head == nullptr) {
        cout << "Belum ada buku yang tersimpan.\n";
        return;
    }

    Buku* temp = head;
    cout << "\nDaftar Buku:\n";
    while (temp != nullptr) {
        cout << "ISBN     : " << temp->isbn << endl;
        cout << "Judul    : " << temp->judul << endl;
        cout << "Penulis  : " << temp->penulis << endl;
        cout << "---------------------------\n";
        temp = temp->next;
    }
}

// ====== FUNGSI SEARCHING ======
void cariBuku(string key, int pilihan) {
    if (head == nullptr) {
        cout << "Data buku kosong!\n";
        return;
    }

    Buku* temp = head;
    bool ditemukan = false;

    while (temp != nullptr) {
        if ((pilihan == 1 && temp->judul == key) ||
            (pilihan == 2 && temp->penulis == key) ||
            (pilihan == 3 && temp->isbn == key)) {
            cout << "\nBuku ditemukan!\n";
            cout << "ISBN     : " << temp->isbn << endl;
            cout << "Judul    : " << temp->judul << endl;
            cout << "Penulis  : " << temp->penulis << endl;
            cout << "---------------------------\n";
            ditemukan = true;
        }
        temp = temp->next;
    }

    if (!ditemukan) {
        cout << "Buku dengan data tersebut tidak ditemukan.\n";
    }
}

// ====== PROGRAM UTAMA ======
int main() {
    int pilihan;
    string isbn, judul, penulis, key;

    do {
        cout << "\n=== MENU DATA BUKU ===\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Hapus Buku\n";
        cout << "3. Perbarui Buku\n";
        cout << "4. Lihat Buku\n";
        cout << "5. Cari Buku\n";
        cout << "6. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan ISBN: ";
                getline(cin, isbn);
                cout << "Masukkan Judul: ";
                getline(cin, judul);
                cout << "Masukkan Penulis: ";
                getline(cin, penulis);
                tambahBuku(isbn, judul, penulis);
                break;
            case 2:
                cout << "Masukkan ISBN yang akan dihapus: ";
                getline(cin, isbn);
                hapusBuku(isbn);
                break;
            case 3:
                cout << "Masukkan ISBN yang akan diperbarui: ";
                getline(cin, isbn);
                perbaruiBuku(isbn);
                break;
            case 4:
                lihatBuku();
                break;
            case 5:
                int opsi;
                cout << "\nCari berdasarkan:\n";
                cout << "1. Judul\n";
                cout << "2. Penulis\n";
                cout << "3. ISBN\n";
                cout << "Pilih: ";
                cin >> opsi;
                cin.ignore();
                cout << "Masukkan kata kunci: ";
                getline(cin, key);
                cariBuku(key, opsi);
                break;
            case 6:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 6);

    return 0;
}