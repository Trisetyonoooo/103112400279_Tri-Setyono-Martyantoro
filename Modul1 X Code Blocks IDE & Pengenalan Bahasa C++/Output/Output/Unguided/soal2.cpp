#include <iostream>
using namespace std;

int main() {
    int angka,puluh,sisa;        
    string hasil;    

    string satuan[] = {"nol", "satu", "dua", "tiga", "empat",
                       "lima", "enam", "tujuh", "delapan", "sembilan"};
    string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas",
                        "empat belas", "lima belas", "enam belas",
                        "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh",
                        "lima puluh", "enam puluh", "tujuh puluh",
                        "delapan puluh", "sembilan puluh"};

    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;

    cout << angka << " : ";

    if (angka == 100) {
        hasil = "seratus";
    } else if (angka < 10) {
        hasil = satuan[angka];
    } else if (angka < 20) {
        hasil = belasan[angka - 10];
    } else {
        puluh = angka / 10;
        sisa = angka % 10;
        hasil = puluhan[puluh];
        if (sisa != 0) {
            hasil = hasil + " " + satuan[sisa];
        }
    }

    cout << hasil;

    return 0;
}