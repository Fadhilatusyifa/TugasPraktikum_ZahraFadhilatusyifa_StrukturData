#include <iostream> // menggunakan library 'iostream' untuk mendukung input-output standar dalam c++.
using namespace std; // untuk mendeklarasikan penggunaan namespace 'std', yang mengandung banyak fungsi dan objek standar dari c++.

//fungsi untuk merotasi matriks sebesar 90 derajat
void rotateMatrix(int matrix[3][3]) { // deklarasi fungsi 'rotateMatrix' yang menerima sebuah matriks 3x3 sebagao parameter.
    int rotatedMatrix[3][3];// deklarasi matriks 'rotateMatrix' dengan ukuran yang sama (3x3) untuk menyimpan hasil rotasi
                            // dari matriks input.

    for(int i = 0; i < 3; i++){ // loop pertama yang akan mengiterasi melalui baris matriks input.
        for(int j = 0; j < 3; j++){ // loop kedua yang akan mengiterasi melalui kolom matriks input.
            rotatedMatrix[j][2 - i] = matrix[i][j]; // di dalam loop kedua, setiap elemen pada 'rotateMatrix' diberi nilai
                                                    // yang berasal dari elemen matriks input. namun penempatan elemen pada
                                                    // 'rotateMatrix' dilakukan dengan cara membalikkan indeks baris dan kolom
                                                    // matriks input. Hal ini dilakukan untuk menghasilkan rotasi 90 derajat
                                                    // secara berlawanan arah jarum jam.
        }
    }

    //output matriks yang telah diputar
    cout << "Matriks setelah diputar:" << endl; // mencetak pesan 'matriks setlah diputar' di layar sebagai indikasi bahwa matriks
                                                // yang akan dicetak adalah hasil dari rotasi matriks sebelumnya.
    for(int i = 0; i < 3; i++){ // loop pertamaa yang akan melalui baris matriks hasil rotasi.
        for(int j = 0; j < 3; j++){ // loop kedua yang akan mengiterasi melalui kolom matriks hasil rotasi.
            cout << rotatedMatrix[i][j] << " "; // di dalam loop kedua setiap elemen dari matriks hasil rotasi dicetak ke layar.
        }
        cout << endl; // setelah selesai mencetak semua elemen dalam satu baris matriks, baris baru 'endl' ditambahkan untuk berpindah
                      // ke baris berikutnya dalam output.
    } // menandakan akhir dari fungsi 'rotateMatrix'
}

int main() { // fungsi utama dari program, dimana eksekusi program dimulai.
    int matrix[3][3]; // deklarasi matriks 'matrix' berukuran 3x3 yang akan digunakan untuk menyimpan nilai matriks yang dimasukkan oleh
                      // pengguna.

    //input nilai matrix
    for(int i = 0; i < 3; i++){ // loop pertama yang akan mengiterasi melalui setiap baris matriks. dalam kasus ini, matriks memiliki ukuran
                                // 3x3, sehingga loop ini akan dijalankan tiga kali, sekali untuk setiap baris matriks.
        for(int j = 0; j < 3; j++){ // loop kedua yang bersarang di dalam loop pertama untuk mengiterasi melalui setiap kolom dalam baris saat ini,
                                // dalam kasus matriks 3x3, loop ini akan dijalankan tiga kali, sekali untuk setiap kolom dalam setiap baris.
            cout << "Masukan nilai dari matriks [" << i <<"][" << j << "] : "; // mencetak pesan kepada pengguna, meminta mereka memasukkan nilai
                                                                               // untuk elemen matriks yang berada di baris 'i' dan kolom 'j'.
            cin >> matrix[i][j]; // operasi input yang digunakan untuk mengambil nilai yang dimasukkan oleh pengguna dan menyimpannya di dalam elemen
                                 // matriks yang sesuai, yaitu elemen pada baris 'i' dan kolom 'j'.
        }
        cout << endl; // mencetak newline(baris baru) untuk pindah ke baris berikutnya setelah selesai memasukkan semua nilai untuk satu baris matriks.
    }

    //tampilkan matriks sebelum diputar
    cout << "Matriks sebelum diputar:" << endl; // mencetak pesan 'matriks sebelum diputar' di layar untuk menandakan bahwa matriks yang akan dicetak
                                                // adalah matriks sebelum dilakukan rotasi.
    for(int i = 0; i < 3; i++){ // loop pertama yang digunakan untuk mengiterasi melalui setiap baris matriks.
        for(int j = 0; j < 3; j++){ // loop kedua yang bersarang di dalam loop pertama digunakan untuk mengiterasi melalui setiap elemen dalam baris
                                    // matriks saat ini.
            cout << matrix[i][j] << " "; // di dalam loop kedua, setiap elemen dari matriks di cetak ke layar. elemen-elemen ini dipisahkan oleh spasi
                                         // agar terlihat rapi saat dicetak.
        }
        cout << endl; // mencetak newline(baris baru) untuk pindah ke baris berikutnya setelah selesai mencetak semua elemen dalam satu baris matriks.
    }

    //putar matriks 90 derajat sekali
    rotateMatrix(matrix); // setelah selesai mencetak matriks sebelum rotasi, memanggil fungsi 'rotateMatrix()' untuk melakukan rotasi pada matriks yang
                          // telah dimasukkan.

    cout << "\nNama  : Zahra Fadhilatusyifa" << endl;
    cout << "NPM   : 2310631170159" << endl;
    cout << "Kelas : 2C-Informatika" << endl;


    return 0; // mengembalikan nilai 0 kepada sistem operasi untuk menandakan bahwa program sudah berakhir dengan sukses.
}
