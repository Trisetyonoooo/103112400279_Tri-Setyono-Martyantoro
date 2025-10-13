#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Pointer awal
Node* head = nullptr;

void insertBelakang(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void tampilkanList() {
    if (head == nullptr) {
        cout << "List kosong!\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void reverseList() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;  // simpan node berikutnya
        current->next = prev;  // balik arah pointer
        prev = current;        // geser prev ke current
        current = next;        // pindah ke node berikutnya
    }

    head = prev; // ubah head ke node terakhir
    cout << "Linked list berhasil dibalik!\n";
}

// Program utama
int main() {
    int n, data;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Masukkan data ke-" << i + 1 << ": ";
        cin >> data;
        insertBelakang(data);
    }

    cout << "\nLinked list sebelum dibalik:\n";
    tampilkanList();

    reverseList();

    cout << "\nLinked list setelah dibalik:\n";
    tampilkanList();

    return 0;
}
