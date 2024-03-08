#include <iostream> // menggunakan library 'iostream' untuk mendukung input-output standar dalam c++.
using namespace std; // untuk mendeklarasikan penggunaan namespace 'std', yang mengandung banyak fungsi dan objek standar dari c++

int main(){ // fungsi utama dari program, dimana eksekusi program dimulai.
    int jml; // mendeklarasikan variabel 'jml' yang bertipe data 'int', yang akan digunakan untuk menyimpan jumlah siswa.
    string x[100]; // mendeklarasikan sebuah array 'x' dengan ukuran 100, yang bertipe data 'string'. array ini akan digunakan untuk menyimpan nama-nama siswa.
    string *px; // mendeklarasikan sebuah pointer 'px' yang bertipe data 'string'. pointer ini akan digunakan untuk menunjuk ke alamat memori dari elemen-elemen array 'x'.
    //px= x;
    px = &x[0]; // menginisialisasi pointer 'px' untuk menunjuk ke alamat memori dari elemen pertama dalam array 'x'.

    cout << "Masukkan jumlah siswa : "; // menampilkan sebuah perintah untuk memasukkan jumlah siswa.
    cin >> jml; // mengambil input dari pengguna untuk jumlah siswa dan menyimpan ke dalam variabel 'jml'.

    //loop 'for' yang digunakan untuk meminta memasukkan nama-nama siswa dan menyimpannya ke dalam array 'x'.
    for (int i = 0; i < jml; i++){
        cout << "masukkan data nama siswa ke-" <<i+1<< " : "; // menampilkan sebuah perintah untuk memasukkan nama siswa ke-.
        cin >> x[i]; // mengambil input dari pengguna untuk nama siswa ke- , dan menyimpannya ke dalam array 'x'.

        cout << endl;
    }

    cout << "Nama Siswa        Alamat pada komputer" << endl; // menampilkan teks 'nama siswa' dan 'alamat pada komputer'.
    cout << "=============================================" << endl; // menampilkan garis pemisah antara header dengan data siswa.

    // loop 'for' yang digunakan untuk menampilkan nama siswa serta alamat memori dari setiap nama di dalam array 'x'.
    for (int i = 0; i < jml; i++){
        cout << "" <<*px<< "\t\t  " <<px<< endl; // menampilkan nama siswa dan alamat memori dari nama tersebut.
                                                 // '*px' digunakan untuk mendapatkan nilai dari elemen yang di tunjuk oleh pointre 'px'.
                                                 // sedangkan 'px' digunakan untuk menampilkan alamat memori dari elemen tersebut.
        px++; // menaikkan nilai pointer 'px' sehingga menunjuk ke elemen selanjutnya dalam array 'x'.
    }

    cout << "\nProgram ini dibuat oleh : " << endl;
    cout << "Nama  : Zahra Fadhilatusyifa" << endl;
    cout << "NPM   : 2310631170159" << endl;
    cout << "Kelas : 2C-Informatika" << endl;

    return 0; // mengembalikan nilai 0 kepada sistem operasi untuk menandakan bahwa program sudah berakhir dengan sukses.
}
