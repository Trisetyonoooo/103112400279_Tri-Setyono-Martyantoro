#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan satu: ";
    cin >> a;
    cout << "Masukkan bilangan dua: ";
    cin >> b;

    
    cout << "\nHasil Operasi:" << endl;
    cout << "Penjumlahan: " << a + b << endl;
    cout << "Pengurangan: " << a - b << endl;
    cout << "Perkalian  : " << a * b << endl;

    if (b != 0) {
        cout << "Pembagian  : " << a / b << endl;
    } else {
        cout << "Pembagian  : Pembagi tidak boleh nol" << endl;
    }

    return 0;
}