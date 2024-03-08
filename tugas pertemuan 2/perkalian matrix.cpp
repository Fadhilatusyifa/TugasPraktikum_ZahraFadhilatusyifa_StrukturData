#include <iostream> // menggunakan library 'iostream' untuk mendukung input-output standar dalam c++.
using namespace std; // untuk mendeklarasikan penggunaan namespace 'std', yang mengandung banyak fungsi dan objek standar dari c++.

int main() { // fungsi utama dari program, dimana eksekusi program dimulai.
    // mendeklarasikan dua matrix A dan B dengan tipe data 'int', masing-masing dengan ukuran 2x2,sebagai array dua dimensi-
    // yang berisi bilangan bulat.
    int matrixA[2][2];
    int matrixB[2][2];

    // Input matriks A
    cout << "Masukkan nilai matriks A: " << endl; // menampilkan sebuah perintah kepada pengguna untuk
                                                  // memasukkan nilai-nilai untuk matriks A.
    // perulangan untuk mengisi nilai matriks A.
    for (int i = 0; i < 2; i++) { // perulangan ini untuk mengakses setiap baris dalam matriks A.karena matriks A memiliki dua baris,
                                  // perulangan ini akan diulangi dua kali.
        for (int j = 0; j < 2; j++) { // perulangan ini untuk mengakses setiap elemen dalam satu baris matriks A. karena matriks A memiliki-
                                      // dua kolom, perulangan ini akan diulangi dua kali.
            cout << "Masukkan nilai dari matrix A = [" << i << "][" << j << "] : "; // menampilkan sebuah perintah kepada pengguna untuk-
                                                                                    // memasukkan nilai-nilai untuk matriks A.
            cin >> matrixA[i][j]; // mengambil input dari pengguna dan menyimpannya ke dalam elemen-elemen matriks A.
        }
    }

     // Output matriks A
    cout << "Matriks A : " << endl; //mencetak output "matriks A" ke layar, memberi tahu bahwa matriks A akan dicetak.
    for (int i = 0; i < 2; i++) { // perulangan ini untuk mengakses setiap baris dalam matriks A.karena matriks A memiliki dua baris,
                                  // perulangan ini akan diulangi dua kali.
        for (int j = 0; j < 2; j++) { // perulangan ini untuk mengakses setiap elemen dalam satu baris matriks A. karena matriks A memiliki-
                                      // dua kolom, perulangan ini akan diulangi dua kali.
            cout << matrixA[i][j] << " "; //mencetak nilai elemen matriks A yang sedang diakses (pada posisi baris 'i' dan kolom 'j') ke layar.
        }
        cout << endl; //setelah selesai mencetak semua elemen dalam satu baris matriks A,baris ini akan mencetak newline(baris baru) untuk pindah
                      //ke baris berikutnya.
    }
    cout << endl; // mencetak newline(baris baru) untuk pindah ke baris berikutnya.

    // Input matriks B
    cout << "Masukkan nilai matriks B: " << endl; // menampilkan sebuah perintah kepada pengguna untuk
                                                  // memasukkan nilai-nilai untuk matriks B.
    //perulangan untuk mengisi nilai matriks B.
    for (int i = 0; i < 2; i++) { // perulangan ini untuk mengakses setiap baris dalam matriks B.karena matriks B memiliki dua baris,
                                  // perulangan ini akan diulangi dua kali.
        for (int j = 0; j < 2; j++) { // perulangan ini untuk mengakses setiap elemen dalam satu baris matriks B. karena matriks B memiliki-
                                      // dua kolom, perulangan ini akan diulangi dua kali.
            cout << "Masukkan nilai dari matrix B = [" << i << "][" << j << "] : "; //menampilkan sebuah perintah kepada pengguna untuk
                                                                                    //memasukkan nilai-nilai untuk matriks b.
            cin >> matrixB[i][j]; //mengambil input dari pengguna dan menyimpannya ke dalam elemen-elemen
                                  //matriks B.
        }
    }

    // Output matriks B
    cout << "Matriks B : " << endl; //mencetak output "matriks B" ke layar, memberi tahu bahwa matriks B akan dicetak.
    for (int i = 0; i < 2; i++) { // perulangan ini untuk mengakses setiap baris dalam matriks B.karena matriks B memiliki dua baris,
                                  // perulangan ini akan diulangi dua kali.
        for (int j = 0; j < 2; j++) { // perulangan ini untuk mengakses setiap elemen dalam satu baris matriks B. karena matriks B memiliki-
                                      // dua kolom, perulangan ini akan diulangi dua kali.
            cout << matrixB[i][j] << " "; //mencetak nilai elemen matriks B yang sedang diakses (pada posisi baris 'i' dan kolom 'j') ke layar.
        }
        cout << endl; //setelah selesai mencetak semua elemen dalam satu baris matriks B,baris ini akan mencetak newline(baris baru) untuk pindah
                      //ke baris berikutnya.
    }
    cout << endl;  // mencetak newline(baris baru) untuk pindah ke baris berikutnya.

    // Perkalian matriks
    int matrixC[2][2] = {0}; //mendeklarasikan matriks C sebagai matriks hasil perkalian dari matriks A dsn B ke dalam matriks C.
    cout << "Hasil perkalian matriks A dan B (C = A * B): " << endl; //mencetak output untuk memberitahu bahwa akan dilakukan operasi
                                                                     //perkalian matriks A dan B, dan hasilnya akan disimpan di matriks C.
    //perulangan untuk mengisi nilai matriks C
    for (int i = 0; i < 2; i++) { // perulangan ini untuk mengakses setiap baris dalam matriks C.karena matriks C memiliki dua baris,
                                  // perulangan ini akan diulangi dua kali.
        for (int j = 0; j < 2; j++) { // perulangan ini untuk mengakses setiap elemen dalam satu baris matriks C. karena matriks C memiliki-
                                      // dua kolom, perulangan ini akan diulangi dua kali.
            for (int k = 0; k < 2; k++) { //perulangan ini untuk mengalikan setiap elemen matriks A dan B serta menjumlahkannya untuk mendapatkan
                                          //elemen matriks C.
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j]; //menambahkan hasil perkalian elemen matriks A dan B ke elemen matriks C sesuai dengan
                                                                //aturan perkalian matriks.
            }
        }
    }

    // Output matriks hasil perkalian
    cout << "Matriks C : " << endl; //mencetak output "matriks C" ke layar, memberi tahu bahwa matriks C akan dicetak.
    for (int i = 0; i < 2; i++) { // perulangan ini untuk mengakses setiap baris dalam matriks C.karena matriks C memiliki dua baris,
                                  // perulangan ini akan diulangi dua kali.
        for (int j = 0; j < 2; j++) { // perulangan ini untuk mengakses setiap elemen dalam satu baris matriks C. karena matriks C memiliki-
                                      // dua kolom, perulangan ini akan diulangi dua kali.
            cout << matrixC[i][j] << " "; //mencetak nilai elemen matriks C yang sedang diakses (pada posisi baris 'i' dan kolom 'j') ke layar.
        }
        cout << endl; // setelah selesai mencetak semua elemen dalam satu baris matriks B,baris ini akan mencetak newline(baris baru) untuk pindah
                      // ke baris berikutnya.
    }
    cout << "\nNama  : Zahra Fadhilatusyifa" << endl;
    cout << "NPM   : 2310631170159" << endl;
    cout << "Kelas : 2C-Informatika" << endl;

    return 0; // mengembalikan nilai 0 kepada sistem operasi untuk menandakan bahwa program sudah berakhir dengan sukses.
}

