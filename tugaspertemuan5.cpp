#include <iostream>
#include <windows.h>

using namespace std;

// definisi struktur node untuk menyimpan data dalam tumpukan
struct Node {
    int data;
    Node* next;
};

// definisi struktur stack untuk merepresentasikan tumpukan
struct Stack {
    Node* top;
    Stack(){ // konstruktor untuk inisialisasi tumpukan
        top = NULL;
    }

    // fungsi untuk menambahkan elemen ke dalam tumpukan 
    void push(int value){
        Node* newNode = new Node;
        newNode -> data = value;
        newNode -> next = top;
        top = newNode;
        system("cls");
        cout << "\nNilai " << value << " sudah diinput ke dalam stack.\n";
    }

    // fungsi untuk menghapus dan mengembalikan nilai dari elemen teratas tumpukan 
    int pop(){
        if (top == NULL){ 
            cout << "Stack sudah kosong." << endl;
            return  -1; // Mengembalikan nilai -1 menandakan tumpukan kosong
        }
        Node* temp = top;
        int poppedValue = top -> data;
        top = top -> next;
        delete temp; // menghapus elemen teratas yang sudah tidak diperlukan lagi
        return poppedValue; // mengembalikan nilai data dari elemen teratas yang sudah dihapus
    }

    // fungsi untuk memeriksa apakah tumpukan kosong
    bool isEmpty(){
        if(top == 0){
            return  true;
        } else {
            return false;
        }
    }

    // fungsi untuk menampilkan isi dari tumpukan 
    void display(){
        if (top == NULL){
            cout << " " << endl;
            return;
        }
        Node* currentNode = top;
        cout << " ";
        while (currentNode != NULL){
            cout << " ";
            while (currentNode != NULL){
                cout << currentNode -> data << " -> ";
                currentNode = currentNode -> next;
            }
            cout << endl;
        }
    }   
};

// fungsi untuk memindahkan data dari satu tumpukan ke tumpukan lainnya
void pemindahandata(Stack& asal, Stack& tujuan, char dataasal, char datatujuan){
    char enter;
    if(!asal.isEmpty()){ // Memeriksa apakah tumpukan asal kosong
        int disk = asal.pop(); // mengambil elemen dari tumpukan asal
        tujuan.push(disk);

        system("cls");
        cout << "\nMemindahkan nilai " << dataasal << " ke " << datatujuan << endl;
        cout << "\nTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'
    } else {
        system("cls");
        cout << "\nTower " << dataasal << " kosong." << endl;
        cout << "\nTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'
    }
}

int main(){
    Stack A, B, C;
    Stack Abefore, Bbefore, Cbefore; // variabel untuk menyimpan status tumpukan sebelum pemindahan dilakukan
    int menu, data, nilai;
    char asal, tujuan;
    char enter;

    system("cls");

    while(true){
        system("cls");
        cout << "\nMenu : " << endl;
        cout << "1. Push " << endl;
        cout << "2. Pop " << endl;
        cout << "3. Display " << endl;
        cout << "4. Keluar " << endl;
        cout << "Masukkan pilihan anda : " ;
        cin >> menu;

        switch(menu){
            case 1 : 
            system("cls");
            cout << "\nMasukkan nilai yang ingin dipush : ";
            cin >> nilai;
            A.push(nilai);
            Abefore.push(nilai);
            cout << "\nTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'
            break;

            case 2 :
            system("cls");
            cout << "\nMasukkan Tower asal   (A/B/C) : ";
            cin >> asal;
            cout << "Masukkan Tower tujuan (A/B/C) : ";
            cin >> tujuan;

            // memindahkan data sesuai input pengguna menggunakan fungsi pemindahandata
            switch (asal){
                case 'A' :
                    switch(tujuan) {
                        case 'B' :
                            pemindahandata(A,B, 'A','B');
                            break;
                        case 'C' :
                            pemindahandata(A,C, 'A','C');
                            break;
                    }
                    break;
                case 'B' :
                    switch(tujuan){
                        case 'A' :
                            pemindahandata(B,A, 'B','A');
                            break;
                        case 'C' :
                            pemindahandata(B,C, 'B','C');
                            break;
                    }
                    break;
                case 'C' :
                    switch(tujuan){
                        case 'A' : 
                            pemindahandata(C,A, 'C','A');
                            break;
                        case 'B' : 
                            pemindahandata(C,B, 'C','B');
                            break;
                    }
                    break;
                default :
                    cout << "Tower asal tidak valid." << endl;
                    cout << "\nTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'
                    break;
            }
            break;

            case 3 :
            // menampilkan status awal tumpukan
            system("cls");
            cout << "\nThis is stack of hanoi tower!" << endl;
            cout << "=============================" << endl;
            cout << "Tower A : ";
            Abefore.display();
            cout << "Tower B : ";
            Bbefore.display();
            cout << "Tower C : ";
            Cbefore.display();
            cout << endl;

            // menampilkan stack setelah operasi pop (perpindahan)
            cout << "\nMemindahkan nilai " << asal << " ke " << tujuan << endl;
            cout << "This is stack of hanoi tower!" << endl;
            cout << "=============================" << endl;
            cout << "Tower A : ";
            A.display();
            cout << "Tower B : ";
            B.display();
            cout << "Tower C : ";
            C.display();
            cout << endl;
            cout << "\nTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'
            break;

            case 4 :
            system("cls");
            cout << "==============================" << endl;
            cout << "Nama  : Zahra Fadhilatusyifa" << endl;
            cout << "NPM   : 2310631170159" << endl;
            cout << "Kelas : 2C-Informatika" << endl;
            cout << "==============================" << endl;
            return 0;

            default :
            system("cls");
            cout << "Pilihan anda tidak valid" << endl;
            cout << "\nTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'
            break;
        }
    }
    return 0;
}
