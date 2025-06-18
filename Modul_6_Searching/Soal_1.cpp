#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

void sequentialSearch(const vector<int> &nums, int target) {
    vector<int> indeks;

    for (auto i = 0; i < nums.size(); ++i) {
        if (nums[i] == target) indeks.push_back(i);
    }

    if (indeks.empty()) {
        cout << "Angka " << target << " tidak ditemukan dalam array";
        cout << endl;
    }
    else {
        cout << "Angka " << target << " terdapat dalam array sebanyak " << indeks.size() << " Kali";
        cout << endl;
        cout << "Angka " << target << " ditemukan pada indeks: ";
        for (auto i = 0; i < indeks.size(); i++) {
            cout << indeks[i];
            if (i != indeks.size() - 1) cout << ", ";
            cout << endl;
        }
    }
}

void binarySearch(const vector<int> &nums, int target) {
    int right = nums.size() - 1;
    int left = 0;
    int indeks = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            indeks = mid;
            break;
        }
        if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    if (indeks == -1) cout << "Angka " << target << " tidak ditemukan dalam array" << endl;
    else cout << "angka " << target << " ditemukan pada indeks ke " << indeks << endl;
}

void clearScreen(){
    system("cls");
}

void explain() {
    cout << endl;
    cout << "== PERBEDAAN ANTARA SEQUENTIAL SEARCH DAN BINARY SEARCH ==" << endl << endl;
    cout << "SEQUENTIAL SEARCH" << endl;
    cout << "  Cara Kerja :" << endl;
    cout << "   - Melakukan loop dari indeks 0 sampai akhir array." << endl;
    cout << "   - Mengecek setiap elemen satu per satu." << endl;
    cout << "   - Jika elemen cocok dengan target, maka indeks-nya disimpan ke dalam vector indeks." << endl;
    cout << "  Contoh Penerapan :" << endl;
    cout << "   - Mencari nama dalam daftar absen yang ditulis acak." << endl;
    cout << "   - Mencari kata dalam paragraf tanpa sorting." << endl;
    cout << "   - Pencarian item dalam file teks." << endl;
    cout << "  Kekurangan :" << endl;
    cout << "   - Lambat untuk dataset besar karena harus mengecek satu per satu." << endl;
    cout << "   - Tidak efisien dalam performa." << endl;
    cout << "   - Tidak memanfaatkan struktur data yang terurut." << endl;
    cout << endl;
    cout << "BINARY SEARCH" << endl;
    cout << "  Cara Kerja :" << endl;
    cout << "   - Array sudah dalam keadaan terurut." << endl;
    cout << "   - Menggunakan dua pointer left dan right untuk menentukan batas pencarian." << endl;
    cout << "   - Hitung titik tengah (mid) dari rentang." << endl;
    cout << "  Contoh Penerapan :" << endl;
    cout << "   - Mencari kata dalam kamus digital." << endl;
    cout << "   - Mencari ID pengguna dalam database yang sudah diurutkan." << endl;
    cout << "   - Mencari nilai tertentu dalam array hasil sorting." << endl;
    cout << "  Kekurangan :" << endl;
    cout << "   - Tidak bisa digunakan pada data yang tidak urut." << endl;
    cout << "   - Harus dilakukan proses sorting terlebih dahulu (yang bisa jadi mahal: O(n log n))." << endl;
    cout << "   - Lebih kompleks dalam implementasi dibanding sequential search." << endl;
}

int main() {
    int opt, target;
    do {
        cout << "Pilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih: ";
        cin >> opt;

        switch (opt) {
            case 1: {
                vector<int> nums (100);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 50);

                for (auto &val: nums) {
                    val = (dist(rng));
                }

                cout << "Generating 100 numbers..." << endl;
                for (auto i = 0; i < nums.size(); i++){
                    cout << nums[i] << "[" << i << "]" << " ";
                }
                cout << endl;
                cout << "Masukkan angka yang ingin dicari: "; cin >> target;

                sequentialSearch(nums, target);
                break;
            }

            case 2: {
                int size;
                cout << "Masukkan ukuran vector: ";
                cin >> size;
                if (size < 1){
                    cout << "Error: Mohon masukkan bilangan di atas 0" << endl;
                    break;
                }

                vector<int> nums(size);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto &val: nums) {
                    val = (dist(rng));
                }

                sort(nums.begin(), nums.end());

                cout << "Generating " << size << " numbers..." << endl;
                for (auto i = 0; i < nums.size(); i++){
                    cout << nums[i] << "[" << i << "]" << " ";
                }
                cout << endl;
                cout << "Masukkan angka yang ingin dicari: "; cin >> target;

                binarySearch(nums, target);
                break;
            }

            case 3:
                explain();
                break;

            case 4:
                cout << "\nTERIMA KASIH\n";
                cout << "Programme was made by Ashma Salimah (2410817220015)" << endl;
                break;

            default:
                cout << "Opsi tidak terdefinisi, mohon masukkan ulang opsi" << endl;
                break;
        }

        if (opt != 4) {
            cout << "\nTekan sembarang tombol untuk melanjutkan...";
            getch();
            clearScreen();
        }

    } while (opt != 4);

    return 0;
}