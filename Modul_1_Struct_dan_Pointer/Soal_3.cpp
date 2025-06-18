#include <iostream>
using namespace std;

struct masukkan {
    char hrf[10];
    char kta[10];
    int angk;
};
struct masukkan y;
main() {
    cout << "Masukkan sebuah huruf = "; cin >> y.hrf;
    cout << "Masukan sebuah kata = "; cin >> y.kta;
    cout << "Masukkan Angka = "; cin >> y.angk;
    cout << "\nHuruf yang Anda masukkan adalah " << y.hrf;
    cout << "\nKata yang Anda masukkan adalah " << y.kta;
    cout << "\nAngka yang Anda masukkan adalah " << y.angk;
}