#include <iostream>
#include <string>

using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

// Menambahkan karakter ke stack
void push(char value) {
    if(top == MAX - 1){
        cout << "Stack Penuh !\n";
    } else {
        top++;
        stack[top] = value;
        cout << value << " ditambahkan dalam stack\n";
    }
}

// Mengambil karakter paling atas
char pop() {
    if(top == -1){
        cout << "Stack kosong !\n";
        return '\0';
    } else {
        char value = stack[top];
        top--;
        return value;
    }
}

int main() {

    string kata;

    cout << "Masukkan sebuah kata: ";
    cin >> kata;

    // Memasukkan setiap karakter ke stack
    for(char c : kata) {
        push(c);
    }

    // Mengeluarkan karakter dari stack
    cout << "Hasil kebalikan: ";

    while(top != -1) {
        cout << pop();
    }

    cout << endl;

    return 0;
}