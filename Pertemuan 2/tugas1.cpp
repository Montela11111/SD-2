#include <iostream>
using namespace std;

struct Node {
    int nilai;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

bool isEmpty() {
    return (head == NULL);
}

void tampilkan() {
    Node* bantu = head;
    cout << "Isi Linked List: ";
    while (bantu != NULL) {
        cout << bantu->nilai << " -> ";
        bantu = bantu->next;
    }
    cout << "NULL\n";
}

void tambahDepan(int nilaiBaru) {
    Node* newNode = new Node();
    newNode->nilai = nilaiBaru;
    newNode->next = NULL;

    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    tampilkan();
}

void tambahBelakang(int nilaiBaru) {
    Node* newNode = new Node();
    newNode->nilai = nilaiBaru;
    newNode->next = NULL;

    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    tampilkan();
}

void tambahSetelah(int target, int nilaiBaru) {
    if (isEmpty()) {
        cout << "Linked list masih kosong!\n";
        return;
    }

    Node* bantu = head;
    while (bantu != NULL && bantu->nilai != target) {
        bantu = bantu->next;
    }

    if (bantu == NULL) {
        cout << "Nilai " << target << " tidak ditemukan dalam linked list!\n";
    } else {
        Node* newNode = new Node();
        newNode->nilai = nilaiBaru;
        newNode->next = bantu->next;
        bantu->next = newNode;

        if (bantu == tail) {
            tail = newNode;
        }
        tampilkan();
    }
}

void hapusNode(int target) {
    if (isEmpty()) {
        cout << "Linked list kosong, tidak ada yang bisa dihapus!\n";
        return;
    }

    Node* hapus = NULL;
    if (head->nilai == target) {
        hapus = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        delete hapus;
        tampilkan();
        return;
    }

    Node* bantu = head;
    while (bantu->next != NULL && bantu->next->nilai != target) {
        bantu = bantu->next;
    }

    if (bantu->next == NULL) {
        cout << "Nilai " << target << " tidak ditemukan!\n";
    } else {
        hapus = bantu->next;
        bantu->next = hapus->next;
        if (hapus == tail) {
            tail = bantu;
        }
        delete hapus;
        tampilkan();
    }
}

int main() {
    int pilihan, nilai, target;

    do {
        cout << "\n===== MENU SINGLE LINKED LIST =====\n";
        cout << "1. Tambah di awal\n";
        cout << "2. Tambah di akhir\n";
        cout << "3. Tambah setelah nilai tertentu\n";
        cout << "4. Hapus berdasarkan nilai\n";
        cout << "5. Tampilkan Linked List\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahDepan(nilai);
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahBelakang(nilai);
                break;
            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> nilai;
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> target;
                tambahSetelah(target, nilai);
                break;
            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> target;
                hapusNode(target);
                break;
            case 5:
                tampilkan();
                break;
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}