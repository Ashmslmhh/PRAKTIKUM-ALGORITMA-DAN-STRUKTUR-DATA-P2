#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20
using namespace std;
struct Queue {
    int Front, Rear, size;
    char Q[MAX];
};

Queue antrean;
int isEmpty(){
    return antrean.Front == antrean.Rear;
}

int isFull(){
    return ((antrean.Rear + 1) % antrean.size) == antrean.Front;
}

void enqueue(char huruf){
    if (isFull() == 1){
        cout << "Queue Penuh" << endl;
    }
    else{
        antrean.Q[antrean.Rear] = huruf;
        cout << "Data: " << antrean.Q[antrean.Rear] << " Masuk ke dalam Queue " << endl;
        antrean.Rear = (antrean.Rear + 1) % antrean.size;
    }
}

void dequeue(){
    if (isEmpty() == 1){
        cout << "Queue kosong" << endl;
    }
    else{
        cout << "Data yang dihapus: " << antrean.Q[antrean.Front] << endl;
        antrean.Front = (antrean.Front + 1) % antrean.size;
    }
}

void peek(){
    if(isEmpty()==1){
        cout << "Queue kosong" << endl;
    } 
    else {
        int i = antrean.Front;
        while(i != antrean.Rear){
            cout << "Queue ke " << i << " = " << antrean.Q[i] << endl;
            i = (i + 1) % antrean.size;
        }
    }
}

void remove(){
    antrean.Front = 0;
    antrean.Rear = 0;
    cout << "Queue telah di-reset" << endl;
}

void Inisialisasi(){
    antrean.Front = 0;
    antrean.Rear = 0;
    antrean.size = MAX; 
}

int main(){
    Inisialisasi();
    int pilihan;
    char huruf;
    do{
        cout << "\nQUEUE" << endl;
        cout << "==============" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. RESET QUEUE" << endl;
        cout << "5. QUIT" << endl;
        cout << "PILIHAN : "; cin >> pilihan;
        switch (pilihan)
        {
        case 1:
        {
            string input;
            cout << "Masukkan Huruf: "; cin >> input;
            huruf = input[0];
            enqueue(huruf);
            break;
        }
        case 2:
            dequeue();
            break;
            
        case 3:
            peek();
            break;
        
        case 4:
            remove();
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