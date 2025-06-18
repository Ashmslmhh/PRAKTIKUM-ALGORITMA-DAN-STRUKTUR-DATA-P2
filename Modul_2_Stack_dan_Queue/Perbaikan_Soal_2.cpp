#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20

using namespace std;

struct Stack {
    int atas;
    int data[MAX];  
};

Stack Tumpuk;

int isEmpty(){
    if (Tumpuk.atas == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(){
    if (Tumpuk.atas == MAX-1) {
        return 1;
    }
    else {
        return 0;
    }
}

void push(int data){
    if (isEmpty()==1){
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
             << " Masuk ke Stack " << endl;
    }
    else if (isFull()==0){
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
             << " Masuk ke Stack " << endl;        
    }
    else {
        cout << "Tumpukan Penuh" << endl;
    }
}

void pop(){
    if (isEmpty()==0){
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Diambil dari stack" << endl;
        Tumpuk.atas--;
    }
    else {
        cout << "Data Kosong" << endl;
    }
}

void seek(){
    if (isEmpty()==0){
        for(int i = Tumpuk.atas; i >= 0; i--){
            cout << "\nTumpukan Ke " << i << " = " << Tumpuk.data[i];
        }
        cout << endl;
    }
    else {
        cout << "Tumpukan Kosong" << endl;
    }
}

void clear(){
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong !" << endl;
}

void inisialisasi(){
    Tumpuk.atas = -1;
}

int main(){
    inisialisasi();
    int pilihan, data;
    do{
        cout << "\nSTACK" << endl;
        cout << "==============" << endl;
        cout << "1. PUSH" << endl;
        cout << "2. POP" << endl;
        cout << "3. CETAK STACK" << endl;
        cout << "4. BERSIHKAN STACK" << endl;
        cout << "5. QUIT" << endl;
        cout << "PILIHAN : "; cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            cout << "Masukkan Nilai: "; cin >> data;
            push(data);
            break;
        
        case 2:
            pop();
            break;
            
        case 3:
            seek();
            break;

        case 4:            
            clear();
            break;
        case 5:
            cout << "TERIMA KASIH" << endl;
            break;
        default:
            cout << "PILIHAN TIDAK VALID!" << endl;
            break;
        }
        cout << "Tekan tombol apa saja untuk melanjutkan";
        getch();
        system("cls");
    }
    while (pilihan < 5);    
    return 0;
}