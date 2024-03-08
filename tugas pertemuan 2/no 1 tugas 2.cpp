#include <iostream> // menggunakan library 'iostream' untuk mendukung input-output standar dalam c++.
#include<iomanip> // menggunakan library 'iomanip' untuk menggunakan salah satu fungsi yang ada di library 'iomanip' yaitu 'setw' untuk
                  // menetapkan lebar field output.
using namespace std; // untuk mendeklarasikan penggunaan namespace 'std', yang mengandung banyak fungsi dan objek standar dari c++

const int MIN_TANGGAL = 5; // konstanta yang mendefinisikan jumlah minimal hari yaitu minimal 5 hari.
const int MAX_NAMA_BARANG = 50; // konstanta yang mendefinisikan panjang maksimal untuk nama barang. ini menetapkan batasan
                                // maksimal untuk jumlah karakter dalam nama barang.

struct DataBarang { // struktur 'DataBarang' yang digunakan untuk mendefinisikan sebuah tipe data baru yang memiliki empat anggota.
    string nama; // mendeklarasikan variabel 'nama' bertipe data 'string' digunakan untuk menyimpan nama barang.
    int jumlah; // mendeklarasikan variabel 'jumlah' bertipe data 'int' digunakan untuk menyimpan jumlah barang.
    int tanggal; // mendeklarasikan variabel 'tanggal' bertipe data 'int' digunakan untuk menyimpan informasi tanggal barang.
    int kode; // mendeklarasikan variabel 'kode' bertipe data 'int' digunakan untuk menyimpan kode untuk mencari barang.
};

//membuat fungsi bernama 'garis()' untuk mencetak garis horizontal menggunakan karakter '=' sebanyak 70 kali.
void garis() // deklarasi sebuah fungsi bernama 'garis()'. 'void' menunjukkan bahwa fungsi ini tidak mengembalikan nilai apapun.
{
    for (int i = 0; i < 70; i++){ // perulangan inisialisasi variabel 'i' dengan nilai 0, kemudian melakukan kondisi perulangan,
                                  // yang berarti perulangan akan terus berlanjut selama nilai 'i' kurang dari 70. setelah itu
                                  // melakukan pengoperasian yang akan dieksekusi setiap kali iterasi dilakukan, yang meningkatkan
                                  // nilai 'i' sebanyak 1.
        cout << "="; // mencetak karakter '=' ke layar. ini dilakulan berulang-ulang sesuai dengan jumlah yang telah ditentukan.
    }
}

int main(){ // fungsi utama dari program, dimana eksekusi program dimulai.

    int jumlahinput; // mendeklarasikan sebuah variabel yang bernama 'jumlahinput' yang bertipe data 'int'. akan digunakan untuk
                     // menyimpan jumlah data barang yang akan dimasukkan oleh pengguna.
    cout << "Masukkan jumlah data barang yang diinputkan : "; // mencetak pesan ke layar meminta pengguna untuk memasukkan jumlah
                                                              // data barang yang akan diinputkan.
    cin >> jumlahinput;// mengambil input dari pengguna dan menyimpannya ke dalam variabel 'jumlahinput'.

    int jumlahtanggal; // mendeklarasikan sebuah variabel yang bernama 'jumlahtanggal' yang bertipe data 'int'. akan digunakan untuk
                       // menyimpan tanggal terakhir.
    cout << "Masukkan tanggal : "; // mencetak pesan ke layar meminta pengguna untuk memasukkan tanggal.
    cin >> jumlahtanggal; // mengambil input dari pengguna dan menyimpannya ke dalam variabel 'jumlah tanggal'.

    if (jumlahtanggal < MIN_TANGGAL){ // melakukan pengondisian apakah nilai yang disimpan di dalam variabel 'jumlahtanggal' lebih kecil
                                      // daripada nilai yang disimpan di dalam konstanta 'MIN_TANGGAL'.
        cout << "tanggal hari harus minimal " << MIN_TANGGAL << endl; // jika kondisi di atas terpenuhi akan mencetak informasi bahwa tanggal
                                                                      // harus minimal sejumlah nilai yang disimpan di dalam konstanta 'MIN_TANGGAL'

    return 0; // ini akan menghentikan eksekusi program dan mengembalikan nilai 0, menandakan bahwa program telah berakhir dengan sukses.
              // ini digunakan jika syarat minimum tidak terpenuhi, sehingga program tidak akan melanjutkan eksekusinya.
    }

    // sebuah array dari tipe data 'DataBarang', yang ukurannya adalah hasil dari perkalian antara konstanta 'MIN_TANGGAL' dan 'jumlahinput' yang merupakan
    // jumlah data barang yang tadi sudah dimasukkan oleh pengguna.
    DataBarang dataBarang[MIN_TANGGAL * jumlahinput];

    // Memasukkan data
    // sebuah loop 'for' yang akan meminta pengguna untuk memasukkan nama barang sebanyak 'jumlahinput'.
    for (int i = 0; i < jumlahinput; ++i){ // perulangan inisialisasi variabel penghitung 'i' yang dimulai dari 0, kemudian melakukan kondisi perulangan selama nilai 'i'
                                           // lebih kecil dari 'jumlahinput' setelah itu melakukan pengoperasian increment yang akan dieksekusi setiap kali iterasi
                                           // dilakukan, yang meningkatkan nilai 'i' sebanyak 1.
        cout << "Masukkan nama barang ke-" << i+1 <<  " : "; // mencetak pesan ke layar yang meminta pengguna untuk memasukkan nama barang ke-. pengguna diminta
                                                             // memasukkan nama barang untuk setiap barang, mulai dari 1 hingga jumlah barang yang ditentukan
                                                             // oleh 'jumlahinput'. 'i+1' digunakan karna barang pertama dihitung sebagai barang ke-1, sedangkan
                                                             // dalam komputasi, array dimulai dari indeks 0.
        cin >> dataBarang[i].nama; // operasi input yang digunakan untuk mendapatkan nama barang dari pengguna. nama barang yang dimasukkan oleh pengguna akan
                                   // disimpan di dalam elemen array 'nama' dari objek 'daraBarang' pada indeks yang sedang di iterasi('i').
    }
    cout << endl; // mencetak newline(baris baru) setelah loop selesai dieksekusi.

    for(int i=0; i < jumlahtanggal; ++i){ // perulangan inisialisasi variabel penghitung 'i' (adalah vatiabel yang digunakan untuk melcak nomor tanggal) yang dimulai
                                          // dari 0, kemudian melakukan kondisi perulangan selama nilai 'i' lebih kecil dari'jumlahtanggal' setelah itu melakukan 
                                          // pengoperasian increment yang akan dieksekusi setiap kali iterasi dilakukan, yang meningkatkan nilai 'i' sebanyak 1.
        cout << "Tanggal ke-" << i+1 << endl; // mencetak nomor urut tanggal ke layar, 'i+1" digunakan karna tanggal dimulai dari tanggal 1, bukan tanggal 0.
        cout << endl; // mencetak newline(baris baru) setelah loop selesai dieksekusi.
    // loop ini bertujuan untuk mengumpulkan jumlah barang yang berbeda untuk setiap tanggal.
    for (int j = 0; j < jumlahinput; ++j){ // perulangan inisialisasi variabel penghitung 'j' yang dimulai dari 0, kemudian melakukan kondisi perulangan selama nilai 
                                           // 'j' lebih kecil dari 'jumlahinput' setelah itu melakukan pengoperasian increment yang akan dieksekusi setiap kali iterasi 
                                           // dilakukan, yang meningkatkan nilai 'i' sebanyak 1.
        cout << "Masukkan jumlah " << dataBarang[j].nama << " tanggal " << i+1 << " : "; // mencetak pesa yang meminta pengguna memasukkan jumah barang untuk tanggal
                                                                                         // dan barang tertentu.
        cin >> dataBarang[j * jumlahtanggal + i].jumlah; // operasi input pengguna diminta untuk memasukkan jumlah barang tertentu pada tanggal tertentu.
        dataBarang[j * jumlahtanggal + i].tanggal = i + 1; // menetapkan tanggal ke struktur atau variabel yang sesuai untuk mengingat tanggal mana yang dimasukkan 
                                                           // pengguna untuk barang tertentu,
        cout << endl; // mencetak newline(baris baru) setelah loop selesai dieksekusi.
    }
    cout << endl; // mencetak newline(baris baru) untuk pindah ke baris berikutnya.
    }
    garis(); // memanggil fungsi 'garis()' untuk mencetak garis pemisah.
    cout << endl; // mencetak newline(baris baru) untuk pindah ke baris berikutnya.

    cout << "\t\t\tTabel data barang" << endl; // mencetak judul 'Tabel data barang' ke layar. '\t' adalah karakter tab yang memberi
                                               // jarak tambahan di awal teks.
    garis(); // memanggil fungsi 'garis()' untuk mencetak garis pemisah.
    cout << endl; // // mencetak newline(baris baru) untuk pindah ke baris berikutnya.
    cout << setw(7) << "tanggal"; //  mencetak header 'tanggal' dengan lebar kolom 7 karakter menggunakan 'setw'. 'setw' digunakan untuk
                                  // mengatur lebar kolom untuk memastikan output tetap rapi.

    // loop untuk mencetak nama barang.
    for (int i = 0; i < jumlahinput; i++){ // perulangan inisialisasi variabel penghitung 'i' yang dimulai dari 0, kemudian melakukan kondisi perulangan selama nilai
                                           // 'i' lebih kecil dari 'jumlahinput' setelah itu melakukan pengoperasian increment yang akan dieksekusi setiap kali iterasi
                                           //  dilakukan, yang meningkatkan nilai 'i' sebanyak 1.
        cout << setw(15) << dataBarang[i].nama; // setiap nama barang dicetak dengan lebar kolom 15 karakter untuk memastikan tampilan tabel yang rapi.
    }
    cout << endl; // mencetak newline(baris baru) untuk pindah ke baris berikutnya.
    garis(); // memanggil fungsi 'garis()' untuk mencetak garis pemisah.
    cout << endl; // mencetak newline(baris baru) untuk pindah ke baris berikutnya.

    // loop untuk mencetak jumlah barang di setiap tanggal nya.
    for (int i = 0; i < jumlahtanggal; i++){ // perulangan inisialisasi variabel penghitung 'i' yang dimulai dari 0, kemudian melakukan kondisi perulangan selama 
                                             // nilai 'i' lebih kecil dari 'jumlahtanggal' setelah itu melakukan pengoperasian increment yang akan dieksekusi setiap
                                             // kali iterasi dilakukan, yang meningkatkan nilai 'i' sebanyak 1.
        cout << setw(4) << i+1; // setiap nomor urutan tanggal dicetak dengan lebar kolom 4 karakter.
        for(int j = 0; j < jumlahinput; j++){ // perulangan inisialisasi variabel penghitung 'j' yang dimulai dari 0, kemudian melakukan kondisi perulangan selama nilai
                                              // 'j' lebih kecil dari 'jumlahinput' setelah itu melakukan pengoperasian increment yang akan dieksekusi setiap kali 
                                              // iterasi dilakukan, yang meningkatkan nilai 'j' sebanyak 1.
            cout << setw(15) << dataBarang[j * jumlahtanggal + i].jumlah; // mencetak jumlah barang pada tanggal tertentu untuk setiap barang.
                                                                          // dengan lebar kolom 15 karakter. 'dataBarang[j * jumlah tanggal + i].jumlah' mengakses jumlah
                                                                          // barang pada tanggal tertentu untuk barang dengan indeks 'j' (nomor urutan barang) dan tanggal
                                                                          // dengan indeks 'i' (nomor urutan tanggal).
        }
        cout << endl; // mencetak newline(baris baru) setelah selesai mencetak data jumlah barang untuk semua barang pada tanggal tertentu.
    }
    garis(); // memanggil fungsi 'garis()' untuk mencetak garis pemisah.
    cout << endl; // mencetak newline(baris baru) untuk pindah ke baris berikutnya.

    while (true){ // sebuah loop 'while' yang akan berjalan terus selama kondisi di dalamnya adalah 'true' ini menunjukkan bahwa program akan terus berjalan sampai 
                  // ada perintah untuk keluar dari loop. ini digunakan untuk mencari detail barang berdasarkan tanggal dan kode barang yang dimasukkan oleh pengguna.

    int kodeBarangCari; // mendeklarasikan sebuah variabel yang bernama 'kodeBarangCari' yang akan digunakan untuk menyimpan kode barang yang dimasukkan oleh pengguna.
    int caritanggalbarang;  // mendeklarasikan sebuah variabel bernama 'caritanggalbarang' yang akan digunakan untuk menyimpan tanggal barang yang dimasukkan
                            //  oleh pengguna.

    cout << "\nMasukkan tanggal dan kode barang untuk mencari detail barang" << endl; // mencetak pesan ke layar yang memberitahu pengguna bahwa mereka harus memasukkan
                                                                                      // tanggal dan kode barang untuk mencari detail barang.
    cout << "Masukkan tanggal     : "; // mencetak pesan ke layar yang meminta pengguna untuk memasukkan tanggal yang ingin dicari.
    cin >> caritanggalbarang; // operasi input yang digunakan untuk mendapatkan input dari pengguna mengenai tanggal yang ingin dicari. nilai yang dimasukkan oleh 
                              // pengguna akan disimpan di dalam variabel 'caritanggalbarang'.
    cout << "Masukkan kode barang : "; // mencetak pesan ke layar yang meminta pengguna untuk memasukkan kode yang ingin dicari.
    cin >> kodeBarangCari; // operasi input yang digunakan untuk mendapatkan input dari pengguna mengenai kode barang yang ingin dicari. nilai yang dimasukkan oleh 
                           // pengguna akan disimpan di dalam variabel 'kodeBarangCari'.

    garis(); // memanggil fungsi 'garis()' untuk mencetak garis pemisah.
    // melakukan pengondisian untuk memeriksa apakah kode barang yang dimasukkan oleh pengguna valid. jika kode barang valid(yaitu lebih besar atau sama dengan 0, 
    // dan kurang dari hasil perkalian 'jumlahinput' dengan 'jumlahtanggal'), maka program akan mengeksekusi blok kode di dalamnya.
    if (kodeBarangCari >= 0 && kodeBarangCari < jumlahinput * jumlahtanggal) {
        cout << "\nDetail Barang"; // mencetak 'detail barang'.
        cout << "\nData Tanggal  : " << caritanggalbarang; // mencetak tanggal yang dimasukkan oleh pengguna. variabel 'caritanggalbarang' berisi tanggal yang
                                                           // dimasukkan oleh pengguna.
        cout << "\nNama Barang   : " << dataBarang[kodeBarangCari].nama; // mencetak nama barang yang sesuai dengan kode barang yang dimasukkan oleh pengguna. '
                                                                         // dataBarang[kodeBarangCari]' mengakses elemen array 'dataBarang' dengan indeks 
                                                                         // 'kodeBarangCari' dan '.nama' mengambil atribut nama dari objek tersebut
        cout << "\nAlamat Barang : " << &dataBarang[kodeBarangCari]; // mencetak alamat memori dari barang yang sesuai dengan kode barang yang dimasukkan oleh pengguna.
                                                                     // '&dataBarang[kodeBarangCari]' mengambil alamat memori dari elemen array 'dataBarang' dengan 
                                                                     // indeks 'kodeBarangCari'.
        cout << endl; // mencetak baris baru setelah detail barang selesai dicetak.

    garis(); // memanggil fungsi 'garis()' untuk mencetak garis pemisah.
    cout << endl; // mencetak newline(baris baru) untuk pindah ke baris berikutnya.
    }
    else { //jika kode barang yang dimasukkan tidak valid. maka program akan mencetak 'detail barang tidak ditemukan.kode barang tidak valid'.
        cout << "Detail barang tidak ditemukan. Kode barang tidak valid." << endl;
    }
    char jawaban;// mendeklarasikan sebuah variabel 'jawaban' sebagai karakter.variabel ini akan digunakan untuk menyimpan jawaban pengguna apakah ingin melanjutkan
                 // pencarian detail barang lagi atau tidak.
        cout << "Apakah Anda ingin mencari detail barang lagi? (y/n): "; // mencetak pesan ke layar yang bertanya kepada pengguna apakah ingin melanjutkan pencarian 
                                                                         // detail barang lagi. yang berisi opsi 'y' untuk ya dan 'n' untuk tidak.
        cin >> jawaban; // operasi input dimana pengguna diminta untuk memasukkan karakter 'y' atau 'n', dan karakter yang dimasukkan akan disimpan di dalam variabel
                        // 'jawaban'.

        // jika jawaban pengguna tidak sama dengan 'y' atau 'Y' maka program akan keluar dari loop 'while' menggunakan perintah 'break' dan menyelesaikan eksekusi.
        if (jawaban != 'y' && jawaban != 'Y') {
            break;
        }
    }
    // setelah loop 'while' selesai, program mencetak terimakasih telah menggunakan program ini.
    cout << "\nTerima kasih telah menggunakan program ini." << endl;

    cout << "\nNama  : Zahra Fadhilatusyifa";
    cout << "\nNPM   : 2310631170159";
    cout << "\nKelas : 2C-Informatika";
    cout << endl;

    return 0; // mengembalikan nilai 0 kepada sistem operasi untuk menandakan bahwa program sudah berakhir dengan sukses.
}
