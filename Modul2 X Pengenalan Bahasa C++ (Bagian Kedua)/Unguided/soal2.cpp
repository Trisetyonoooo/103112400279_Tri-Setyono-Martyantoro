#include <iostream>

using namespace std;

void kuadrat(int &a)
{
    a = a * a;
}

int main() {
    int angka;

    cout << "Masukkan angka: ";
    cin >> angka;
    cout << "Nilai awal: " << angka << endl;
    kuadrat(angka);
    cout << "Nilai setelah dikuadratkan: " << angka << endl;

    return 0;
}