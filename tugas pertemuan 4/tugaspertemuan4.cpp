#include <iostream> // menggunakan library 'iostream' untuk mendukung input-output standar dalam c++.
using namespace std; // untuk mendeklarasikan penggunaan namespace 'std', yang mengandung banyak fungsi dan objek standar dari c++.

// mendefinisikan sebuah struktur bernama 'Node' yang memiliki dua anggota, yaitu 'data' dan 'next'. 
struct Node{ 
    int data; // mendeklarasikan variabel bernama 'data' yang bertipe data 'int' digunakan untuk menyimpan data.
    Node* next; // pointer yang menunjuk ke node selajutnya dalam linked list 

    // konstruktor untuk 'Node' 
    Node(int val) : data(val), next(nullptr){} // menginisialisasi 'data' dengan nilai 'val' yang diberikan dan 'next' dengan 'nullptr' 
                                               // menetapkan nide berikutnya sebagai null karena kita belum tahu apa yang akan menjadi node berikutnya.
};

//fungsi untuk membalikkan LinkedList 
Node* reverseLinkedList(Node* head){ // mengambil sebuah pointer ke 'head' dari linked list sebagai parameter dan mengembalikan pointer ke head
                                     // dari linked list yang sudah di reverse.
    Node *prev = nullptr, *current = head, *next = nullptr; // inisialisasi tiga pointer : prev, current, dan next
                                                            // prev : pointer ke node sebelumnya (awalnya null)
                                                            // current : pointer ke node saat ini (dimulai dari head)
                                                            // next : pointer ke node selanjutnya dari current (awalnya null)
    while (current != nullptr){ // selama current tidak menunjuk ke null (artinya masih ada node yang belum di reverse), kita lakukan loop
        next = current->next; // simpan 'next' dengan mengambil pointer ke node selanjutnya dari 'current;
        current->next = prev; // balikkan panah 'next' dari current agar menunjuk ke 'prev', sehingga node saat ini menjadi node terakhir dalam linked list.
        prev = current; // pindahkan 'prev' ke 'current' untuk langkah iterasi berikutnya
        current = next; // pindahkan 'current' ke 'next' untuk mengiterasi ke node berikutnya
    }
    return prev; // setelah loop selesai, 'prev' akan menunjuk ke node terakhir dari linked list yang sudah di-reverse, maka kembalikan 'prev' sebagai head 
                 // dari linked list yang sudah di-reverse.
}

//fungsi untuk mencetak linked list
void displayLinkedList(Node* head){
    Node* temp = head; // membuat sebuah variabel pointer sementara bernama 'temp' yang awalnya menunjuk ke 'head'. variabel ini akan digunakan untuk
                       // melakukan iterasi melalui linked list.
    while (temp != nullptr){ // selama 'temp' tidak menunjuk ke 'nullptr' (belum mencapai akhir dari linked list), ini akan melakukan iterasi melalui
                             // linked list.
        cout << temp->data << " "; // mencetak nilai data dari node yang ditunjuk oleh 'temp'
        temp = temp->next; // setelah mencetak nilai node saat ini, pindahkan 'temp' ke node selanjutnya dalam linked list 
    } // proses ini diulang sampai mencapai akhir dari linked list (yaitu ketika 'temp' menunjuk ke 'nullptr')
    cout << endl; // setelah selesai mencetak seluruh linked list, cetak newmline (garis baru) untuk pindah ke baris berikutnya
}

int main(){ // fungsi utama dari program, dimana eksekusi program dimulai.
    int jml; // mendeklarasikan sebuah variabel 'jml' yang bertipe data 'int' digunakan untuk menyimpan jumlah data yang akan dimasukkan.
    cout << "\nMasukkan jumlah data : "; // meminta pengguna untuk memasukkan jumlah data yang akan dimasukkan.
    cin >> jml; // menerima input dari pengguna dan menyimpannya ke dalam variabel 'jml'.
    
    Node* head = nullptr; // mendeklarasi pointer 'head' dari tipe 'Node' yang diinisialisasi dengan 'nullptr'.
                          // 'head' digunakan untuk menunjukkan elemen pertama dalam linked list.
    Node* tail = nullptr; // mendeklarasi pointer 'tail' dari tipe 'Node' yang diinisialisai dengan 'nullptr'.
                          // 'tail' digunakan untuk menunjukkan elemen terakhir dalam linked list.
    
    
    for (int i = 0; i < jml; i++){ // loop 'for' digunakan untuk mengulangi proses input nilai data sebanyak 'jml' kali, di mana 'jml' adalah 
                                   // jumlah data yang akan dimasukkan 
        cout << "\nMasukkan nilai data ke-" << i+1 << " : "; // meminta pengguna untuk memasukkan nilai data ke- 'i+1'. penjumlahan 'i+1'
                                                             // dilakukan karena 'i' dimulai dari 0, tetapi kita ingin nomor data dimulai dari 1.
        int val; // mendeklarasikan variabel 'val' yang bertipe data 'int' digunakan untuk menyimpan nilai data yang akan dimasukkan.
        cin >> val; // menerima input dari pengguna dan menyimpannya ke dalam variabel 'val'.
        Node* newNode = new Node (val); // sebuah node baru 'newNode' dibuat dengan menggunakan operator 'new' dan nilai data yang dimasukkan oleh
                                        // pengguna disimpan di dalamnya

        if (head == nullptr){ // mengecek kondisi apakah linked list sudah memiliki elemen atau belum. ini dilakukan dengan memeriksa apakah 'head' 
                              // adalah 'nullptr' yang berarti linked list masih kosong.
            head = newNode; // 'head' ditetapkan menjadi 'newNode' yang menandakan bahwa 'newNode' adalah elemen pertama dalam linked list
            tail = newNode; // karna linked list hanya memiliki satu elemen, 'tail' juga ditetapkan menjadi 'newNode', menunjukkan bahwa 'newNode' 
                            // juga elemen terakhir dalam linked list.
        } else { // jika linked list tidak kosong, maka 
            tail->next = newNode; // pointer 'next' dari node terakhir 'tail' ditetapkan untuk menunjuk ke 'newNode', sehingga 'newNode' ditambahkan 
                                  // setelah node terkahir dalam linked list
            tail = newNode; // kemudian 'tail' diperbarui untuk menunjuk ke 'newNode', sehingga 'newNode' menjadi elemen terakhir dalam linked list.
        }
    }

    // menampilkan LinkedList sebelum dibalik
    cout << "\n--------------------------------------------------------"; // mencetak garis putus-putus sebagai pemisah sebelum menampilkan linked list.
    cout << "\nLinkedList sebelum dibalik : "; // mencetak pesan yang memberitahu pengguna bahwa linked list sebelum dibalik
    displayLinkedList(head); // memanggil fungsi 'displayLinkedList' untuk menampilkan linked list sebelum proses pembalikan dilakukan. fungsi ini menerima 
                             // pointer ke head dari linked list sebagai argumen dan mencetak seluruh elemen linked list dengan nilai datanya.

    // Memanggil fungsi untuk membalikkan LinkedList. fungsi ini menerima pointer ke head dari linked list sebagai argumen, dan mengembalikan pointer ke head
    // dari linked list yang baru setelah di balik. Oleh karena itu, nilai 'head' diperbarui dengan pointer baru yang menunjuk ke head Linked List yang baru setelah pembalikan.
    head = reverseLinkedList(head);

    // menampilkan LinkedList setelah dibalik
    cout << "\nLinkedList setelah dibalik : "; // mencetak pesan yang memberitahu pengguna bahwa linked list setelah dibalik
    displayLinkedList(head); // memanggil fungsi 'displayLinkedList' untuk menampilkan linked list setelah dilakukan pembalikan, fungsi ini akan mencetak seluruhh
                             // elemen linked list dengan nilai-nilai yang telah dibalik.
    cout << "--------------------------------------------------------" << endl; // mencetak garis putus-putus untuk memisahkan informasi yang ditampilkan setelah
                                                                                // pembalikan linked list

    cout << "\nNama  : Zahra Fadhilatusyifa" << endl;
    cout << "NPM   : 2310631170159" << endl;
    cout << "kelas : 2C-Informatika" << endl;
    cout << endl; // mencetak newline (garis baru) untuk pindah ke baris berikutnya.

    return 0; // mengembalikan nilai 0 kepada sistem operasi untuk menandakan bahwa program sudah berakhir dengan sukses.
}
