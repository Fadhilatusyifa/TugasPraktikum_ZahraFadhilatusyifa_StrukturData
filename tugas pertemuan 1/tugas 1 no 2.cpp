#include <iostream> // menggunakan library 'iostream' yang memberikan akses ke fungsi=fungsi standar untuk input dan output dalam c++.
using namespace std; // untuk mendeklarasikan penggunaan namespace 'std', yang mengandung banyak fungsi dan objek standar dari c++.

// Fungsi untuk melakukan kompresi karakter pada array karakter
void compress(const char* input) { // mendeklarasikan fungsi bernama 'compress', fungsi ini akan mengambil parameter berupa pointer ke karakter yang tidak dapat diubah,
                                   // yang menunjuk pada array karakter yang akan dikompresi.
    // Inisialisasi karakter dan hitungan
    char current_char = input[0]; // mendeklarasikan variabel 'current_char' dengan tipe data char dan menginisialisasinya dengan karakter pertama dari array input.
    int count = 1; // mendeklarasikan variabel 'count' dengan tipe data integer dan menginisialisasinya dengan 1, yang akan digunakan untuk menghitung kemunculan karakter-
                   // yang sama secara berurutan

    // Loop untuk melakukan kompresi karakter
    for (int i = 1; input[i] != '\0'; ++i) {//menginisialisasi loop 'for' yang dimulai dari indeks kedua array input dan berlanjut hingga menemukan karakter null terminator '\0'.
        // Mengecek apakah karakter saat ini sama dengan 'current_char'.
        if (input[i] == current_char) {
            count++; // Tambah hitungan 1 jika karakter sama dengan 'current_char'
        } else {
            // jika karakter saat ini tidak sama dengan 'current_char', maka akan mencetak output jumlah kemunculan karakter sebelumnya (jika lebih dari 1), kemudian
            // direset nilai 'current_char' dengan karakter baru dan 'count' direset menjadi 1.
            if (count >= 1) { // mengecek apakah jumlah kemunculan karakter yang diproses ('count) lebih dari sama dengan 1.
                cout << "'" << current_char << "','" << count << "',"; // jika kondisi di atas terpenuhi(artinya jumlah kemunculan karakter lebih dari sama dengan 1),
                                                                       // maka akan mencetak karakter bersama dengan jumlah kemunculannya,tanda koma (') dan spasi di akhir.
                                                                       // misalnya, jika karakter 'a' muncul 3 kali, maka akan dicetak 'a','3'.
            }
            // Update karakter saat ini dan reset hitungan untuk karakter baru
            current_char = input[i]; // Mengubah karakter saat ini ('current_char) menjadi karakter yang sedang di proses dalam iterasi saat ini dari array.
                                     // ini karna berpindah kekarakter baru untuk melakukan penghitungan.
            count = 1;// mengatur ulang hitungan ('count') menjadi 1. ini dilakukan karna memulai penghitungan baru untuk karakter yang baru ditemukan.
        }
    }
     // Cetak karakter terakhir dan jumlah kemunculannya (jika lebih dari sama dengan 1)
    if (count >= 1) { // mengecek apakah jumlah kemunculan karakter yang diproses ('count) lebih dari sama dengan 1.
        cout << "'" << current_char << "','" << count << "'"; // jika kondisi di atas terpenuhi(artinya jumlah kemunculan karakter lebih dari sama dengan 1), maka akan mencetak
                                                              // karakter bersama dengan jumlah kemunculannya,tanda koma (') dan spasi di akhir. misalnya, jika karakter 'a'
                                                              // muncul 3 kali, maka akan dicetak 'a','3'.
    // jika kondisi tidak terpenuhi atau kurang dari 1, maka program akan mencetak tanda koma ('), diikuti oleh nilai dari 'current_char', dan tanda koma lagi di akhir.
    } else {
        cout << "'" << current_char << "'";
    }
}

// fungsi utama dari program, dimana eksekusi program dimulai.
int main() {
    const int MAX_SIZE = 100; // tentukan maksimum ukuran array input yaitu 100.
    char input[MAX_SIZE]; // Array karakter untuk menyimpan yang dimasukkan oleh pengguna

    cout << "Masukkan array karakter : "; // menampilkan sebuah perintah untuk memasukkan array karakter.
    cin.getline(input, MAX_SIZE); // mengambil input dari pengguna untuk di simpan di dalam array 'input'.

    // Menampilkan output array karakter sebelum kompresi
    cout << "\nArray karakter sebelum di kompresi = ";
    cout << "[";
    // loop for ini akan berjalan melalui setiap karakter dalam array 'input' sampai menemukan karakter dari array ke dalam output, diapit oleh tanda kutip tunggal (').
    // misalnya, jika karakter a, maka akan ducetak 'a'.
    for (int i = 0; input[i] != '\0'; ++i) {
        cout << "'" << input[i] << "'";
        // kondisi ini memeriksa apakah masih ada karakter saat ini di dalam array. jika iya (artinya bukan karakter null terminator), maka akan mencetak tanda koma ','
        // dan spasi setelah karakter untuk memisahkan karakter-karakter dalam output.
        if (input[i + 1] != '\0') {
            cout << ", ";
        }
    }
    // setelah loop selesai,tanda kurung siku penutup ']' dicetak untuk menandakan akhir dari array.
    cout << "]" << endl;

    // Menampilkan output array karakter setelah di kompresi
    cout << "\nArray karakter setelah di kompresi = [";
    compress(input); // memanggil fungsi 'compress' dengan parameter 'input'. fungsi 'compress' bertanggung jawab untuk melakukan kompresi terhadap array karakter yang
                     // diberikan, dan hasil kompresi akan langsung ditampilkan ke dalan output.
    cout << "]" << endl; //  setelah proses kompresi selesai, tanda kurung siku penutup ']' dicetsk untuk menandakan akhir dari array.

    cout << "\nProgram ini dibuat oleh :" << endl;
    cout << "Nama  : Zahra Fadhilatusyifa" << endl;
    cout << "NPM   : 2310631170159" << endl;
    cout << "Kelas : 2C-Informatika" << endl;

    return 0; // mengembalikan nilai 0 kepada sistem operasi untuk menandakan bahwa program sudah berakhir dengan sukses.
}

