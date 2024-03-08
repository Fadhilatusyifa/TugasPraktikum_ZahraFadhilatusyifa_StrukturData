#include <iostream> // menggunakan library 'iostream' untuk mendukung input-output standar dalam c++.
#include <iomanip> // menggunakan library 'iomanip' untuk menggunakan salah satu fungsi yang ada di library 'iomanip' yaitu 'setw' untuk
                   // menetapkan lebar field output.
using namespace std;  // untuk mendeklarasikan penggunaan namespace 'std', yang mengandung banyak fungsi dan objek standar dari c++.


const int MAX_MHS = 20; //konstanta yang mendefinisikan jumlah data mahasiswa yaitu maksimal 20.

//struktur yang diberi nama 'Nilai' yang digunakan untuk mengorganisir data yang berkaitan dengan penilaian seorang mahasiswa.
struct Nilai {
    float absen; // mendeklarasikan sebuah variabel 'absen' yang bertipe data 'float' digunakan untuk menyimpan nilai absen mahasiswa.
    float tugas; // mendeklarasikan sebuah varibel 'tugas' yang bertipe data 'float digunakan untuk menyimpan nilai tugas mahasiswa.
    float uts; // mendeklarasikan sebuah variabel 'uts' yang bertipe data 'float' digunakan untuk menyimpan nilai uts dari mahasiswa.
    float uas; // mendeklarasikan sebuah variabel 'uas' yang bertipe data 'float' digunakan untuk menyimpan nilai uas dari mahasiswa.
    float nilaiAkhir; // mendeklarasikan sebuah variabel 'nilaiAkhir' yang bertipe data 'float' yang digunakan untuk menyimpan nilai akhir atau total dari semua nilai yang telah diberikan.
    char indexhuruf; // mendeklarasikan sebuah variabel 'indexhuruf' yang bertipe data 'char' yang digunakan untuk menyimpan indeks huruf yang mencerminkan nilai akhir, misalnya A,B,C, dst.
}; // menutup definisi dari struktur Nilai.

//struktur yang diberi nama 'mahasiswa' yang digunakan untuk mengorganisir data yang berkaitan dengan seorang mahasiswa.
struct Mahasiswa {
    string npm; // mendeklarasikan sebuah variabel 'npm' yang bertipe data 'string' yang digunakan untuk menyimpan NPM dari mahasiswa.
    string nama; // mendeklarasikan sebuah variabel 'nama' yang bertipe data 'string' yang digunakan untuk menyimpan nama dari mahasiswa.
    Nilai nilai; // mendeklarasikan variabel 'nilai' yang bertipe data 'Nilai'  yang digunakan untuk menyimpan informasi penilaian dari mahasiswa.
}; // menutup definisi dari struktur mahasiswa.

// fungsi untuk menghitung nilai akhir sorang mahasiswa berdasarkan bobot yang telah ditentukan untuk setiap komponen nilai, dan kemudian menetapkan indeks hrurf yang sesuai berdasarkan 
// nilai akhir yang dihasilkan.
void hitungNilaiAkhir(Nilai &nilai){  // mendekalarasikan sebuah fungsi bernama 'hitungnilaiAkhir' yang tidak mengembalikan nilai 'void' dan menerima parameter 'nilai' yang merupakan 
                                      // referensi'&' dari objek 'Nilai'.
    // menghitung nilai akhir mahasiswa dengan cara mengalikan setiap nilai (absen, tugas, uts, uas) dengan bobotny masing-masing.
    // dimaana absen memiliki bobot 10%, tugas 20%, UTS 30%, UAS 40%, setelah itu, kita jumlahkan semua hasil perkalian.
    nilai.nilaiAkhir = 0.1 * nilai.absen +
                       0.2 * nilai.tugas +
                       0.3 * nilai.uts +
                       0.4 * nilai.uas;

    // berdasarkan nilai akhir yang dihitung sebelumnya, kita tentukan indeks hurufnya.
    if (nilai.nilaiAkhir > 80) // jika nilai akhir lebih dari 80, maka indeks hurufnya adalah 'A'
        nilai.indexhuruf = 'A';
    else if (nilai.nilaiAkhir > 70) // jika nilai akhir lebih dari 70, maka indeks hurufnya adalah 'B'
        nilai.indexhuruf = 'B';
    else if (nilai.nilaiAkhir > 60) // jiks nilai akhir lebih dari 60, maka indeks hurufnya adalah 'C' 
        nilai.indexhuruf = 'C';
    else // jika tidak memenuhi kriteria-kriteria tersebut, maka indeks hurufnya adalah 'D'
        nilai.indexhuruf = 'D';
} // menutup fungsi 'hitungnilaiAkhir'

// fungsi untuk memasukkan data mahasiswa ke dalam array 'mahasiswa[]'.
void inputdatamhs(Mahasiswa mahasiswa[], int& jumlahMahasiswa){ // mendeklarasikan sebuah fungsi bernama 'inputdatamhs' menerima dua parameter yaitu sebuah array dari objek Mahasiswa yang berisi data mahasiswa,
                                                                // dan 'jumlahMahasiswa' yaitu sebuah referensi ke variabel 'int' yang menyatakan jumlah total mahasiswa dalam array 'mahasiswa[]'.
    
    // memeriksa apakah jumlah mahasiswa yang sudah dimasukkan 'jumlahMahasiswa' masih kurang dari batas maksimal mahasiswa 'MAX_MHS', jika masih ada ruang kosong untuk menambahkan mahasiswa baru,
    // maka proses penambahan data dapat dilanjutkan.
    if (jumlahMahasiswa < MAX_MHS){
        cout << "\n#Input data mahasiswa." << endl; // mencetak pesan ke layar yang memberitahu pengguna bahwa pengguna akan menginput data mahasiswa.
        cout << "\nMasukkan Data mahasiswa" << endl; // mencetak pesan ke layar yang memberitahu pengguna bahwa pengguna diminta untuk memasukkan data mahasiswa.
        cout << "Masukkan NPM   : "; // meminta pengguna untuk memasukkan NPM (Nomor Pokok Mahasiswa) mahasiswa.
        cin >> mahasiswa[jumlahMahasiswa].npm; // menerima input dari pengguna kemudian menyimpan npm yang dimasukkan pengguna ke dalam data mahasiswa yang sesuai di dalam array 'mahasiswa[]'.
        cout << "Masukkan Nama  : "; // meminta pengguna untuk memasukkan nama mahasiswa.
        cin.ignore(); // digunakan untuk membersihkan buffer input sebelum melakukan operasi 'getline'.
        getline(cin, mahasiswa[jumlahMahasiswa].nama); // menerima input dari pengguna, fungsi 'getline' digunakan untuk membaca keseluruhan baris input dari pengguna, termasuk spasi, 
                                                       // dan menyimpannya ke dalam variabel 'nama' pada objek mahasiswa yang terletak di dalam array 'mahasiswa[]', dengan indeks yang sesuai
                                                       // dengan 'jumlahMahasiswa', ini memungkinkan pengguna untuk memasukkan nama mahasiswa yang mungkin terdiri lebih dari satu kata, termasuk
                                                       // spasi, dan menyimpannya secara lengkap.
        cout << "Masukkan Nilai Mahasiswa" << endl; // mencetak pesan ke layar yang memberitahu pengguna bahwa pengguna diminta untuk memasukkan nilai mahasiswa.
        cout << "Masukkan Nilai Absen : "; // meminta pengguna untuk memasukkan nilai absen mahasiswa.
        cin >> mahasiswa[jumlahMahasiswa].nilai.absen; // menerima input dari pengguna kemudian menyimpan nilai absen yang dimasukkan pengguna ke dalam data mahasiswa yang sesuai di dalam array 'mahasiswa[]'.
        cout << "Masukkan Nilai Tugas : "; // meminta pengguna untuk memasukkan nilai tugas dari mahasiswa.
        cin >> mahasiswa[jumlahMahasiswa].nilai.tugas; // menerima input dari pengguna kemudian menyimpan nilai tugas yang dimasukkan pengguna ke dalam data mahasiswa yang sesuai di dalam array 'mahasiswa[]'.
        cout << "Masukkan Nilai UTS   : "; // meminta pengguna untuk memasukkan nilai uts dari mahasiswa.
        cin >> mahasiswa[jumlahMahasiswa].nilai.uts; // menerima input dari pengguna kemudian menyimpan nilai uts yang dimasukkan pengguna ke dalam data mahasiswa yang sesuai di dalam array 'mahasiswa[]'
        cout << "Masukkan Nilai UAS   : "; // meminta pengguna untuk memasukkan nilai uas dari mahasiswa.
        cin >> mahasiswa[jumlahMahasiswa].nilai.uas; // menerrima input dari pengguna kemudian menyimpan nilai uas yang dimasukkan pengguna ke dalam data mahasiswa yang sesuai di dalam array 'mahasiswa[]'.

    hitungNilaiAkhir(mahasiswa[jumlahMahasiswa].nilai); // memanggil fungsi 'hitungnilaiAkhir()' dengan parameter nilai mahasiswa yang baru dimasukkan, untuk menghitung nilai akhir mahasiswa tersebut.

    jumlahMahasiswa++; // variabel 'jumlahMahasiswa' ditambah satu, menandakan bahwa satu mahasiswa baru telah dimasukkan ke dalam program.
    cout << endl;  // mencetak newline(baris baru) untuk pindah ke baris berikutnya.
    } else { // bagian dari if statement sebelumnya, dimana jika jumlah mahasiswa sudah mencapai batas maksimal 'MAX_MHS' maka program akan mencetak pesan 
             // bahwa jumlah mahasiswa sudah mencapai batas maksimal, dan tidak dapat menerima input lagi.
        cout << "\nMaaf, jumlah mahasiswa sudah mencapai batas maksimal (20)." << endl;
    }
} // menutup fungsi 'inputdatamhs'.

// fungsi yang digunakan untuk menampilkan data mahasiswa.
void tampilandatamhs(Mahasiswa mahasiswa[], int jumlahMahasiswa){ // mendeklarasikan sebuah fungsi bernama 'tampilandatamhs' menerima dua parameter yaitu sebuah array dari objek Mahasiswa  yang berisi data mahasiswa
                                                                  // yang akan ditampilkan dan 'jumlahMahasiswa' yaitu sebuah referensi ke variabel 'int' yang menyatakan jumlah total mahasiswa dalam array 'mahasiswa[]'.

    cout << "\n#Tampilan Data Mahasiswa." << endl; // mencetak pesan ke layar yang memberi tahu pengguna bahwa data mahasiswa akan ditampilkan.

    // membuat tabel untuk menampilkan data mahasiswa dan nilai-nilai mereka.
    cout << "=========================================================================================================" << endl; // mencetak garis sebagai pemisah bagian atas dari tabel.
    cout << "|                                       Data Mahasiswa                                                  |" << endl; // mencetak judul utama tabel, yaitu 'Data Mahasiswa', judul ini ditempatkan di tengah-tengah
                                                                                                                                 // tabel dengan batas garis '|' di awal dan diakhir.
    cout << "|=======================================================================================================|" << endl; // mencetak garis sebagai pemisah antara judul utama dan judul kolom tabel.
    cout << "|               |                         |                           Nilai                             |" << endl; // mencetak judul kolom tabel untuk kolom NPM, nama, dan Nilai.
    cout << "|      NPM      |         Nama            |-------------------------------------------------------------|" << endl; // mencetak judul kolom tabel untuk atribut NPM dan nama mahasiswa, dan juga membuat garis pemisah 
                                                                                                                                 // antara judul kolom dan nilai-nilai.
    cout << "|               |                         |  Absen  |  Tugas  |  UTS  |  UAS  |  Akhir  |  Index Huruf  |" << endl; // mencetak judul kolom tabel untuk nilai-nilai mahasiswa, yaitu Absen, tugas, uts, uas, nilai akhir, dan index huruf.
    cout << "|=======================================================================================================|" << endl; // mencetak garis sebagai pemisah antara judul kolom dan baris-baris data mahasiswa.

    // loop 'for' yang akan berjalan sebanyak 'jumlahMahasiswa', dimana 'jumlahMahasiswa' adalah jumlah total mahasiswa yang ingin di tampilkan. variabel 'i' digunakan
    // sebagai counter untuk iterasi melalui indeks mahasiswa.
    for (int i = 0; i < jumlahMahasiswa; i++){ 
        cout << "| " << setiosflags(ios::left) << setw(14) <<mahasiswa[i].npm; // mencetak npm mahasiswa ke layar. 'setiosflags(ios::left)' membuat output tersusun ke kiri 
                                                                               // dan 'setw(14)' menetapkan lebar output menjadi 14 karakter. 
        cout << "| " << setiosflags(ios::left) << setw(24) << mahasiswa[i].nama; // mencetak nama mahasiswa ke layar. 'setiosflags(ios::left)' membuat output tersusun ke kiri 
                                                                                 // dan 'setw(24)' menetapkan lebar output menjadi 24 karakter. 
        cout << "|   " << setiosflags(ios::left) << setw(6) << mahasiswa[i].nilai.absen; // mencetak nilai absen dari mahasiswa ke layar. 'setiosflags(ios::left)' membuat output tersusun ke kiri 
                                                                                         // dan 'setw(6)' menetapkan lebar output menjadi 6 karakter. 
        cout << "|   " << setiosflags(ios::left) << setw(6) << mahasiswa[i].nilai.tugas; // mencetak nilai tugas dari mahasiswa ke layar. 'setiosflags(ios::left)' membuat output tersusun ke kiri 
                                                                                         // dan 'setw(6)' menetapkan lebar output menjadi 6 karakter. 
        cout << "|  " << setiosflags(ios::left) << setw(5) << mahasiswa[i].nilai.uts; // mencetak nilai uts dari mahasiswa ke layar. 'setiosflags(ios::left)' membuat output tersusun ke kiri 
                                                                                      // dan 'setw(5)' menetapkan lebar output menjadi 5 karakter. 
        cout << "|  " << setiosflags(ios::left) << setw(5) << mahasiswa[i].nilai.uas; // mencetak nilai uas dari mahasiswa ke layar. 'setiosflags(ios::left)' membuat output tersusun ke kiri 
                                                                                      // dan 'setw(5)' menetapkan lebar output menjadi 5 karakter. 
        cout << "|  " << setiosflags(ios::left) << setw(7) << mahasiswa[i].nilai.nilaiAkhir; // mencetak nilai Akhir mahasiswa ke layar. 'setiosflags(ios::left)' membuat output tersusun ke kiri 
                                                                                             // dan 'setw(7)' menetapkan lebar output menjadi 7 karakter. 
        cout << "|       " << setiosflags(ios::left) << setw(8) << mahasiswa[i].nilai.indexhuruf; // mencetak index huruf mahasiswa ke layar. 'setiosflags(ios::left)' membuat output tersusun ke kiri 
                                                                                                  // dan 'setw(8)' menetapkan lebar output menjadi 8 karakter. 
        cout << "|"; // menambahkan garis vertikal di akhir setiap baris tabel, menendakan akhir kolom.
        cout << endl; // mencetak newline (baris baru) untuk pindah ke baris berikutnya setelah semua data mahasiswa di satu baris selesai diproses.
    }
    cout << "=========================================================================================================" << endl; // mencetak baris sebagai penutup dan penanda bagian bawah dari tabel.
} // menutup fungsi 'tampilandatamhs'.

// fungsi yang digunakan untuk mengedit data mahasiswa dari array 'mahasiswa[]' berdasarkan npm yang dimasukkan oleh pengguna.
void editdatamhs(Mahasiswa mahasiswa[], int jumlahMahasiswa){ // mendeklarasikan sebuah fungsi bernama 'editdatamhs' menerima dua parameter yaitu sebuah array dari objek Mahasiswa  yang berisi data mahasiswa
                                                              // dan 'jumlahMahasiswa' yaitu sebuah referensi ke variabel 'int' yang menyatakan jumlah total mahasiswa dalam array 'mahasiswa[]'.

    cariLagi: // label 'cariLagi' digunakan untuk melanjutkan pencarian data mahasiswa lagi setelah tidak menemukan data yang diinginkan pada pencarian sebelumnya. Misalnya, jika pengguna menjawab 'Y' atau 'y' 
              // ketika ditanya apakah mereka ingin mencari data mahasiswa lagi, program akan melompat kembali ke label cariLagi: menggunakan goto. Dari sana, proses pencarian data mahasiswa akan dimulai kembali.

    string npm_cari; // mendeklarasikan sebuah variabel 'npm_cari' yang bertipe data 'string' yang digunakan untuk menyimpan npm yang ingin dicari atau diedit.
    cout << "\nMasukkan NPM Mahasiswa yang ingin diedit : "; // meminta pengguna untuk memasukkan npm mahasiswa yang ingin diedit.
    cin >> npm_cari; // menerima input dari pengguna berupa npm mahasiswa yang ingin dicari untuk diedit dan menyimpannya ke dalam variabel 'npm_cari'.

    // loop 'for' yang akan berjalan sebanyak 'jumlahMahasiswa', dimana 'jumlahMahasiswa' adalah jumlah total mahasiswa yang ingin di tampilkan. variabel 'i' digunakan
    // sebagai counter untuk iterasi melalui indeks mahasiswa.
    for (int i = 0; i < jumlahMahasiswa; i++){
        if (mahasiswa[i].npm==npm_cari){ // kondisi 'if' yang mengecek apakah npm dari mahasiswa pada indeks ke-i sama dengan npm yang ingin diedit ('npm_cari'). jika benar, maka akan dieksekusi untuk
                                         // mengedit data mahsiswa tersebut.
            
            // mencetak informasi tentang mahasiswa yang berhasil ditemukan.
            cout << "\nData Mahasiswa Berhasil ditemukan        " << endl; // mencetak pesan bahwa data mahasiswa telah berhasil ditemukan.
            cout << "-------------------------------------------------" << endl; // mencetak garis putus-putus sebagai pemisah antara informasi mahasiswa.
            cout << "NPM Mahasiswa   : " << mahasiswa[i].npm << endl; // mencetak npm dari mahasiswa yang berhasil ditemukan.
            cout << "Nama Mahasiswa  : " << mahasiswa[i].nama << endl; // mencetak nama mahasiswa yang berhasil ditemukan.
            cout << "Nilai mahasiswa " << endl; // mencetak judul 'nilai mahasiswa'.
            cout << "Nilai Absen : " << mahasiswa[i].nilai.absen << endl; // mencetak nilai absensi mahasiswa yang berhasil ditemukan.
            cout << "Nilai Tugas : " << mahasiswa[i].nilai.tugas << endl; // mencetak nilai tugas mahasiswa yang berhasil ditemukan.
            cout << "Nilai UTS   : " << mahasiswa[i].nilai.uts << endl; // mencetak nilai uts mahasiswa yang berhasil ditemukan.
            cout << "Nilai UAS   : " << mahasiswa[i].nilai.uas << endl; // mencetak nilai uas mahasiswa yang berhasil ditemukan.
            cout << "-------------------------------------------------" << endl; // mencetak garis putus-putus sebagai pemisah setelah informasi tentang mahasiswa berhasil dicetak.

            cout << "\nUbah Data Mahasiswa" << endl; // mencetak pesan ke layar yang memberitahu pengguna bahwa pengguna akah mengubah data mahasiswa.
            cout << "Masukkan Nama Mahasiswa Baru : "; // meminta pengguna untuk memasukkan nama baru untuk mahasiswa.
            cin.ignore(); // digunakan untuk membersihkan buffer input sebelum melakukan operasi 'getline'
            getline(cin, mahasiswa[i].nama); // menerima input dari pengguna dan menyimpannya sebagai nama baru untuk mahasiswa ke-i.
            cout << "Masukkan Nilai Absen Baru    : "; // meminta pengguna untuk memasukkan nilai absensi baru untuk mahasiswa.
            cin >> mahasiswa[i].nilai.absen; // menerima input dari pengguna dan menyimpannya sebagai nilai absensi baru untuk mahasiswa ke-i.
            cout << "Masukkan Nilai Tugas Baru    : "; // meminta pengguna untuk memasukkan nilai tugas baru untuk mahasiswa.
            cin >> mahasiswa[i].nilai.tugas; // menerima input dari pengguna dan menyimpannya sebagai nilai tugas baru untuk mahasiswa ke-i.
            cout << "Masukkan Nilai UTS Baru      : "; // meminta pengguna untuk memasukkan nilai uts baru untuk mahasiswa.
            cin >> mahasiswa[i].nilai.uts; // menerima input dari pengguna dan menyimpannya sebagai nilai uts baru untuk mahasiswa ke-i.
            cout << "Masukkan Nilai UAS Baru      : "; // meminta pengguna untuk memasukkan nilai uas baru untuk mahasiswa.
            cin >> mahasiswa[i].nilai.uas; // menerima input dari pengguna dan menyimpannya sebagai nilai uas baru untuk mahasiswa.

            cout << "Data Mahasiwa berhasil diubah." << endl; // mencetak pesan bahwa data mahasiswa berhasil diubah.
            return; // fungsi selesai dan akan kembali ke tempat pemanggil fungsi.
        }else{ // sebuah kondisi 'else' yang akan dijalankan jika npm yang dicari tidak ditemukan dalam array data mahasiswa, dan akan menampilkan pesan data mahasiswa dengan npm yang dicari oleh pengguna
               // tidak ditemukan.
            cout << "Data Mahasiswa dengan NPM " << npm_cari << " tidak ditemukan." << endl;
            char a; // mendeklarasikan sebuah variabel 'a' yang bertipe data 'char' yang digunakan untuk menyimpan pilihan yang dimasukkan oleh pengguna.
            cout << "Apakah anda ingin mencari data mahasiswa lagi? (y/n) : "; // mencetak pesan ke layar yang bertanya kepada pengguna apakah ingin mencari data mahasiswa lagi?, jika iya maka pengguna diminta 
                                                                               // untuk memasukkan pilihan 'y' jika tidak ingin mencari lagi maka pengguna diminta untuk memasukkan pilihan 'n'.
            cin >> a; // menerima input dari pengguna kemudian menyimpan jawaban pengguna ke dalam variabel 'a'.
            if (a == 'Y' || 'y'){ // kondisi ini memeriksa apakah nilai variabel 'a' sama dengan karakter 'Y' atau apakah karakter 'y' dianggap benar (true). jika 'a' sama dengan 'Y' atau jika 'y' dianggap benar, 
                                  // maka kondisi akan terpenuhi dan kode dalam blok 'if' akan dieksekusi.
                goto cariLagi; // jika kondisi terpenuhi, program akan melanjutkan eksekusi dari label 'cariLagi'.
            } else{ // jika kondisi 'if' tidak terpenuhi, maka pernyataan 'return' akan dieksekusi.
                return; // 'return' digunakan untuk menghentikan eksekusi fungsi saat ini dan mengembalikan kontrol ke tempat dimana fungsi dipanggil.
            }
        }
    }
} // menutup fungsi 'editdatamhs'.

// fungsi yang digunakan untuk mengahapus data mahasiswa dari array 'mahasiswa[]' berdasarkan npm yang dimasukkan oleh pengguna.
void hapusdatamhs(Mahasiswa mahasiswa[], int& jumlahMahasiswa){ // mendeklarasikan sebuah fungsi bernama 'hapusdatamhs' menerima dua parameter yaitu sebuah array dari objek Mahasiswa yang berisi data mahasiswa,
                                                                // dan 'jumlahMahasiswa' yaitu sebuah referensi ke variabel 'int' yang menyatakan jumlah total mahasiswa dalam array 'mahasiswa[]'.

    cariLagi: // label 'cariLagi' digunakan untuk melanjutkan pencarian data mahasiswa lagi setelah tidak menemukan data yang diinginkan pada pencarian sebelumnya. Misalnya, jika pengguna menjawab 'Y' atau 'y' 
              // ketika ditanya apakah mereka ingin mencari data mahasiswa lagi, program akan melompat kembali ke label cariLagi: menggunakan goto. Dari sana, proses pencarian data mahasiswa akan dimulai kembali.

    string npm_cari; // mendeklarasikan sebuah variabel 'npm_cari' yang bertipe data 'string' yang digunakan untuk menyimpan npm yang ingin dicari untuk menghapus data mahasiswa.
    cout << "\n#menghapus data mahasiswa." << endl; // mencetak pesan ke layar yang memberitahu pengguna bahwa pengguna akan menghapus data mahasiswa.
    cout << "\nMasukkan NPM Mahasiswa untuk menghapus data mahasiswa yang ingin diahapus :  "; // meminta pengguna untuk memasukkan npm mahasiswa yang ingin dihapus. 
    cin >> npm_cari; // mengambil input dari pengguna berupa npm mahasiswa yang ingin dicari untuk menhapus data mahasiswa dan menyimpannya ke dalam variabel 'npm_cari'.

    // loop 'for' yang akan berjalan sebanyak 'jumlahMahasiswa', dimana 'jumlahMahasiswa' adalah jumlah total mahasiswa yang ingin di tampilkan. variabel 'i' digunakan
    // sebagai counter untuk iterasi melalui indeks mahasiswa.
    for (int i = 0; i < jumlahMahasiswa; i++){
        if (mahasiswa[i].npm == npm_cari){  // kondisi 'if' yang mengecek apakah npm dari mahasiswa pada indeks ke-i sama dengan npm yang ingin dihapus ('npm_cari'). jika benar, maka akan dieksekusi untuk
                                            // menghapus data mahsiswa tersebut.
            // loop 'for' kedua yang akan digunakan untuk menggeser data di dalam array setelah data yang ingin dihapus. loop ini akan memindahkan data pada indeks ke-j menjadi pada indeks ke-(j+1).
            for (int j = 0; j < jumlahMahasiswa - 1; j++){ 
                mahasiswa[j] = mahasiswa[j + 1]; // jika npm sesuai, maka loop ini akan menggeser data dalam array ke kiri, sehingga data pada indeks ke-(j+1)akan diubah menjadi data pada indeks ke-j.
                                                 // hal ini dilakukan untuk menghapus data mahasiswa yang ditemukan.
            }
            jumlahMahasiswa--; // jumlah mahasiswa dikurangi satu karena satu data mahasiswa telah dihapus dari array.
            cout << "\nData Mahasiswa berhasil dihapus." << endl; // pesan ini akan ditampilkan jika data mahasiswa berhasil dihapus.
            return; // fungsi selesai dan akan kembali ke tempat pemanggil fungsi.
        } else{ // sebuah kondisi 'else' yang akan dijalankan jika npm yang dicari tidak ditemukan dalam array data mahasiswa, dan akan menampilkan pesan data mahasiswa dengan npm yang dicari oleh pengguna
                // tidak ditemukan.
            cout << "\nData Mahasiswa dengan NPM " << npm_cari << " tidak ditemukan." << endl; 
            char a; // mendeklarasikan sebuah variabel 'a' yang bertipe data 'char' yang digunakan untuk menyimpan pilihan yang dimasukkan oleh pengguna.
            cout << "\nApakah anda ingin mencari data mahasiswa lagi? (y/n) : "; // mencetak pesan ke layar yang bertanya kepada pengguna apakah ingin mencari data mahasiswa lagi?, jika iya maka pengguna diminta 
                                                                                 // untuk memasukkan pilihan 'y' jika tidak ingin mencari lagi maka pengguna diminta untuk memasukkan pilihan 'n'.
            cin >> a; // menerima input dari pengguna kemudian menyimpan jawaban pengguna ke dalam variabel 'a'.
            if (a == 'Y' || 'y'){ // kondisi ini memeriksa apakah nilai variabel 'a' sama dengan karakter 'Y' atau apakah karakter 'y' dianggap benar (true). jika 'a' sama dengan 'Y' atau jika 'y' dianggap benar, 
                                  // maka kondisi akan terpenuhi dan kode dalam blok 'if' akan dieksekusi.
                goto cariLagi; // jika kondisi terpenuhi, program akan melanjutkan eksekusi dari label 'cariLagi'.
            } else{ // jika kondisi 'if' tidak terpenuhi, maka pernyataan 'return' akan dieksekusi.
                return; // 'return' digunakan untuk menghentikan eksekusi fungsi saat ini dan mengembalikan kontrol ke tempat dimana fungsi dipanggil.
            }
        }
    }
   
} // menutup fungsi 'hapusdatamhs'.

int main(){ // fungsi utama dari program, dimana eksekusi program dimulai.
    Mahasiswa mahasiswa[MAX_MHS]; // array 'mahasiswa' yang berisi data mahasiswa. 
    int jumlahMahasiswa = 0; // mendeklarasikan variabel 'jumlahMahasiwa' yang bertipe data 'int' digunakan untuk melacak jumlah mahasiswa yang saat ini
                             // ada dalam program, nilai awalnya diatur 0. 
    char pilihan; // mendeklarasikan variabel 'pilihan' yang bertipe data 'char' digunakan untuk menyimpan pilihan menu yang dimasukkan oleh pengguna.
    do
    {
        // mencetak menu pilihan dengan beberapa opsi yang dapat dipilih oleh pengguna.
        cout << "\n\t\t=============================================================" << endl; //mencetak garis sebagai pemisah dan penanda bagian atas dari menu pilihan.
        cout << "\t\t|                      MENU PILIHAN                         |" << endl; // mencetak judul 'MENU PILIHAN' di tengah-tengah baris dengan batas garis '|' di awal dan akhir.
        cout << "\t\t|===========================================================|" << endl; // mencetak garis sebagai pemisah antara judul dan opsi-opsi menu.
        cout << "\t\t| Ketik c untuk : Input Data Mahasiswa.                     |" << endl; // mencetak opsi pertama dari menu, yaitu 'ketik c untuk : input data mahasiswa'. dengan batas garis '|' di awal dan akhir.
        cout << "\t\t| Ketik r untuk : Melihat Tampilan Data Mahasiswa.          |" << endl; // mencetak opsi kedua dari menu, yaitu 'ketik r untuk : melihat tampilan data mahasiswa'. dengan batas garis '|' di awal dan akhir.
        cout << "\t\t| Ketik u untuk : Edit Data Mahasiswa.                      |" << endl; // mencetak opsi ketiga dari menu, yaitu 'ketik u untuk : edit data mahasiswa'. dengan batas garis '|' di awal dan akhir.
        cout << "\t\t| Ketik d untuk : Menghapus Data Mahasiswa.                 |" << endl; // mencetak opsi keempat dari menu, yaitu 'ketik d untuk : menghapus data mahasiswa'. dengan batas garis '|' di awal dan akhir.
        cout << "\t\t| Ketik e untuk : Keluar dari program.                      |" << endl; // mencetak opsi kelima dari menu, yaitu 'ketik e untuk : keluar dari program.'. dengan batas garis '|' di awal dan akhir.
        cout << "\t\t=============================================================" << endl; // mencetak garis sebagai penutup dan penanda bagian bawah dari menu pilihan.
        
        cout << "\t\tSilahkan pilih menu yang anda inginkan :                     " << endl; // mencetak pesan yang meminta pengguna untuk memilih salah satu opsi dari menu.
        cout << "\t\t[c]         [r]          [u]          [d]         [e] : "; // mencetak daftar singkat opsi yang tersedia, yaitu [c],[r],[u],[d], dan [e], dan meminta pengguna untuk memilih salah satu dari opsi tersebut.
        cin >> pilihan; // menerima input dari pengguna dan menyimpannya ke dalam variabel 'pilihan', yang kemungkinan nilainya adalah 'c','r','u','d','e', sesuai dengan opsi yang dipilih pengguna.

        switch (pilihan) { // awal dari switch statement yang digunakan untuk mengevaluasi nilai dari variabel 'pilihan' untuk menentukan jalur mana yang akan diambil dalam program
                           // berdasarkan nilai tersebut. dan berdasarkan nilai tersebut.
            // jika nilai dari variabel 'pilihan' adalah 'c'atau 'C', program akan menjalankan fungsi 'inputdatamhs()', yang mungkin bertugas untuk meminta pengguna memasukkan data mahasiswa.
            case 'c': 
            case 'C':
                inputdatamhs(mahasiswa, jumlahMahasiswa);
                break; // digunakan untuk keluar dari switch statement. ini diperlukan untuk mencegah eksekusi terus berlanjut ke kasus berikutnya setelah kasus yang cocok telah ditemukan.
            
            // jika nilai dari variabel 'pilihan' adalah 'r' atau 'R', program akan menjalankan fungsi 'tampilandatamhs()', yang kemungkinan akan menampilkan data mahasiswa yang sudah ada.
            case 'r':
            case 'R':
                tampilandatamhs(mahasiswa, jumlahMahasiswa);
                break; // digunakan untuk keluar dari switch statement.
            
            // jika nilai dari variabel 'pilihan' adalah 'u' atau 'U', program akan menjalankan fungsi 'editdatamhs()', yang memungkinkan pengguna untuk mengedit data mahasiswa yang sudah ada.
            case 'u':
            case 'U':
                editdatamhs(mahasiswa, jumlahMahasiswa);
                break; // digunakan untuk keluar dari switch statement.

            // jika nilai dari variabel pilihan adalah 'd' atau 'D', program akan menjalankan fungsi 'hapusdatamhs()', yang kemungkinan akan menghapus data mahasiswa.
            case 'd':
            case 'D':
                hapusdatamhs(mahasiswa, jumlahMahasiswa);
                break; // digunakan untuk keluar dari switch statement.

            // jika nilai dari variabel 'pilihan' adalah 'e' atau 'E', program akan menampilkann pesan terima kasih dan kemudian keluar dari program.
            case 'e':
            case 'E':
                cout << "\n\t\t_____________________________________________________________" << endl;
                cout << "\n\t\t          Terima Kasih telah menggunakan program ini       " << endl;
                cout << "\t\t_____________________________________________________________" << endl;
                break; // digunakan untuk keluar dari switch statement.
            
            default: // jika tidak ada case yang cocok dengan nilai 'pilihan', program akan menampilkan pesan bahwa pilihan tidak valid.
                cout << "\n\t\t_____________________________________________________________" << endl;
                cout << "\n\t\tPilihan tidak valid!                       " << endl;
                cout << "\t\t_____________________________________________________________" << endl;
                break; // digunakan untuk keluar dari switch statement.
        }
    } while (pilihan != 'e' && pilihan != 'E'); // kondisi dimana loop akan berlanjut selama variabel 'pilihan' tidak sama dengan 'e' dan tidak sama dengan 'E'. artinya, loop akan 
                                                // berlanjut selama pengguna tidak memilih opsi untuk keluar dari program. kalau pengguna memilih opsi tersebut (dengan mengetik 'e' atau 'E'),
                                                // kondisi ini akan menjadi 'false'. dan loop akan berhenti.

    cout << "\nNama  : zahra fadhilatusyifa." << endl;
    cout << "NPM   : 2310631170159." << endl;
    cout << "Kelas : 2C-Informatika." << endl;
    cout << endl; 

    return 0; // mengembalikan nilai 0 kepada sistem operasi untuk menandakan bahwa program sudah berakhir dengan sukses.

}