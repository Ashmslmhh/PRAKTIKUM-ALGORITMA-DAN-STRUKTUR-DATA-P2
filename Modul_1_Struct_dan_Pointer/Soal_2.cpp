#include <iostream>
using namespace std;
struct kendaraan {
    string plat, jenis, pemilik, alamat, kota;
};
struct kendaraan x;
main() {
    x.plat = "DA1234MK";
    x.jenis = "RUSH";
    x.pemilik = "Andika Hartanto";
    x.alamat = "Jl. Kayu Tangi 1";
    x.kota = "Banjarmasin";
    cout << "a. Plat Nomor Kendaraan : " << x.plat << endl;
    cout << "b. Jenis Kendaraan : " << x.jenis << endl;
    cout << "c. Nama Pemilik : " << x.pemilik << endl;
    cout << "d. Alamat : " << x.alamat << endl;
    cout << "e. Kota : " << x.kota << endl;
}