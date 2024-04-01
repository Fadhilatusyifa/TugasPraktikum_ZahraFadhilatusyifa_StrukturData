#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <iomanip>

using namespace std;

// struktur data untuk merepresentasikan barang
struct Barang {
    int kodeBarang;
    char namaBarang[20];
    char namaPemesan[20];
    int stok;
    Barang* next; // pointer ke barang berikutnya
};

Barang* head = nullptr; // pointer ke kepala daftar barang
Barang** barangdata; // array pointer ke barang
int count = 0; // jumlah barang yang ada

// struktur data untuk merepresentasikan pemesanan 
struct Pemesanan {
    int kodePesanan;
    char namaPemesan[20];
    char namaBarang[20];
    int KodeBarangpesan;
    int jumlahPesanan;
    int tanggal;
    int bulan;
    int tahun;
    string Kota_asalpemesanan;
    string kota_tujuanpemesanan;
    int tanggal_pengiriman;
    int bulan_pengiriman;
    int tahun_pengiriman;
    int tanggal_sampai;
    int bulan_sampai;
    int tahun_sampai;
    Pemesanan* next; // pointer ke pemesanan berikutnya
};

Pemesanan* headPemesanan = nullptr; // pointer ke kepala daftar berikutnya

// struktur data untuk merepresentasikan akun pengguna
struct Akun {
    char username[50];
    char password[50];
};

// fungsi-fungsi untuk manajemen barang
void tambahbarang();
void updatebarang();
void lihatbarang();
void hapusbarang();

// fungsi-fungsi untuk manajemen pemesanan
void tambahPemesanan();
void lihatprosespengiriman();

// fungsi-fungsi untuk manajemen akun
void lihatAkun(Akun* user);
void ubahAkun(Akun* user);

// fungsi untuk menu informasi barang.
void tampilkanmenuinformasibarang(){
    system("cls");
    system("color 71"); // untuk mengatur warna latar belakang dan teks 
    cout << "\n\t===========================================================================" << endl;
    cout << "\t                             MENU INFORMASI BARANG                         " << endl;
    cout << "\t===========================================================================" << endl;
    cout << "\t[1] Tambah Barang" << endl;
    cout << "\t[2] Ubah barang" << endl;
    cout << "\t[3] Lihat barang" << endl;
    cout << "\t[4] Hapus barang" << endl;
    cout << "\t[5] Lihat detail barang" << endl;
    cout << "\t==========================================================================" << endl;
    cout << "\tMasukkan pilihan anda : " ;

    char pilihan;
    cin >> pilihan;

    switch (pilihan){
        case '1' : 
            tambahbarang();
            break;
        case '2' :
            updatebarang();
            break;
        case '3' :
            lihatbarang();
            break;
        case '4' :
            hapusbarang();
            break;
    }
}

// fungsi untuk menu informasi pemesanan
void tampilkanmenuinformasipemesanan(){
    system("cls");
    system("color 71");
    cout << "\n\t===========================================================================" << endl;
    cout << "\t                           MENU INFORMASI PEMESANAN                        " << endl;
    cout << "\t===========================================================================" << endl;
    cout << "\t[1] Pemesanan Barang" << endl;
    cout << "\t[2] Lihat Proses Pengiriman" << endl;
    cout << "\t===========================================================================" << endl;
    cout << "\tMasukkan Pilihan Anda : " ;

    char pilihan;
    cin >> pilihan;

    switch (pilihan){
        case '1' : 
            tambahPemesanan();
            break;
        case '2' : 
            lihatprosespengiriman();
            break;
    }
}

// fungsi untuk menu informasi akun
void tampilkanmenuinformasiakun(Akun* user){
    system("cls");
    system("color 71");
    cout << "\n\t===========================================================================" << endl;
    cout << "\t                             MENU INFORMASI AKUN                           " << endl;
    cout << "\t===========================================================================" << endl;
    cout << "\t[1] Lihat akun saya" << endl;
    cout << "\t[2] Ubah akun saya" << endl;
    cout << "\t===========================================================================" << endl;
    cout << "\tMasukkan Pilihan Anda : ";

    char pilihan;
    cin >> pilihan;

    switch (pilihan){
        case '1' : 
            lihatAkun(user);
            break;
            system("cls");
        case '2' :
            ubahAkun(user);
            break;
            system("cls");
    }
}

// fungsi untuk mengubah kata sandi 
void ubahPassword(Akun* akun, const char* newPassword){
    int i = 0;
    char password[50];
    while (newPassword[i] != '\0' && i < 49){
        akun->password[i] = newPassword[i];
        ++i;
    }
    akun->password[i] = '\0';
}

// fungsi untuk login ke akun dengan validasi username dan password
Akun* login(Akun* daftarAkun, int jumlahAkun, int percobaan) {
    char username[50];
    char userPassword[50];
    char enter;
    
    for(int k = 0; k < percobaan; ++k){
        system("cls");
        system("color 71");
        cout << "\n\t===========================================================================" << endl;
        cout << "\t                                  LOGIN AKUN                               " << endl;
        cout << "\t===========================================================================" << endl;
        cout << "\tUSERNAME : ";
        cin >> username;
        cout << "\tPASSWORD : ";
        cin >> userPassword;
    
    
        for (int i = 0; i < jumlahAkun; ++i){
            bool usernameMatch = true;
            bool passwordMatch = true;
            for (int j = 0; daftarAkun[i].username[j] != '\0' || username[j] != '\0'; ++j) {
                if (daftarAkun[i].username[j] != username[j]){
                    usernameMatch = false;
                    break;
                }
            }
            for (int j = 0; daftarAkun[i].password[j] != '\0' || userPassword[j] != '\0'; ++j){
                if (daftarAkun[i].password[j] != userPassword[j]){
                    passwordMatch = false;
                    break;
                }
            }
            if (usernameMatch && passwordMatch) {
                return &daftarAkun[i];
            }
        }

        if (k == percobaan - 2){
            system("cls");
            cout << "\n\n\n\n\n\t\t=========================================================================" << endl;
            cout << "\n\t\t  Password yang anda masukkan salah. Anda memiliki satu percobaan lagi.  " << endl;
            cout << "\n\t\t=========================================================================" << endl; 
            cout << "\t\tTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter' 
        }
        
        if (k < percobaan - 2 ){
            system("cls");
            char lanjut;
            cout << "\n\n\n\n\n\t\tPassword yang anda masukkan salah. Apakah anda ingin mencoba lagi? (y/n) : " ;
            cin >> lanjut;
            if (lanjut != 'y' && lanjut != 'Y') {
                return nullptr;
            }
        }

    }

    char pilihan;
    system("cls");
    cout << "\n\n\n\n\n\t\tApakah anda lupa password? (y) : ";
    cin >> pilihan;

    if (pilihan == 'y' || pilihan == 'Y'){
        char newPassword[50];
        system("cls");
        cout << "\n\t===========================================================================" << endl;
        cout << "\t                               PASSWORD BARU                               " << endl;
        cout << "\t===========================================================================" << endl;
        cout << "\tMasukkan Password Baru : ";
        cin >> newPassword;

        for (int i = 0; i < jumlahAkun; i++){
            bool usernameMatch = true;
            for (int j = 0; daftarAkun[i].username[j] != '\0' || username[j] != '\0'; j++){
                if (daftarAkun[i].username[j] != username[j]){
                    usernameMatch = false;
                    break;
                }
            }
            if (usernameMatch){
                ubahPassword(&daftarAkun[i], newPassword);
                system("cls");
                cout << "\n\n\n\n\n\t\t=====================================================" << endl;

                cout <<"\n\t\t   Password berhasil diubah. Silahkan login kembali.  " << endl;
                cout << "\n\t\t======================================================" << endl;
                cout << "\t\t*Tekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'
                return nullptr;
            }
        }

    }
    return nullptr;
}

// fungsi untuk mendaftar akun
void daftar(Akun* daftarAkun, int& jumlahAkun){
    system("cls");
    system ("color 71");
    cout << "\n\t===========================================================================" << endl;
    cout << "\t                                   DAFTAR AKUN                             " << endl;
    cout << "\t===========================================================================" << endl;
    cout << "\tMasukkan username : " ;
    cin >> daftarAkun[jumlahAkun].username;
    cout << "\tMasukkan password : ";
    cin >> daftarAkun[jumlahAkun].password;
    jumlahAkun++;
}

// fungsi untuk melihat akun
void lihatAkun(Akun* user) {
    system("cls");
    system("color 71");
    char enter;
    cout << "\n\t===========================================================================" << endl;
    cout << "\t                                LIHAT AKUN SAYA                            " << endl;
    cout << "\t===========================================================================" << endl;
    cout << "\tUSERNAME : " << user->username;
    cout << "\n\tPASSWORD : " << user->password << endl;
    cout << "\t===========================================================================" << endl;
    cout << "\tTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'
}

// fungsi untuk mengubah akun
void ubahAkun(Akun* user){
    system("cls");
    system("color 71");
    char enter;
    cout << "\n\t===========================================================================" << endl;
    cout << "\t                                 UBAH AKUN SAYA                            " << endl;
    cout << "\t===========================================================================" << endl;
    cout << "\tMasukkan usesrname baru : ";
    cin >> user->username;
    cout << "\tMasukkan password baru  : ";
    cin >> user->password;
    
    system("cls");
    cout << "\n\n\n\n\n\t\t\t==================================" << endl;
    cout << "\n\t\t\t        AKUN BERHASIL DIUBAH!     " << endl;
    cout << "\n\t\t\t==================================" << endl;
    cout << "\t\t\tTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'
}

// fungsi untuk memasukkan pesanan ke dalam linked list
void masukpemesanan(int kodepes, const char* namapes, int kodbarpes, const char* nambar, int jumpes, int tgl, int bln, int thn, const string& asal, const string& tujuan, int tgl_pengiriman,
                    int bln_pengiriman, int thn_pengiriman, int tgl_sampai, int bln_sampai, int thn_sampai){
    Pemesanan* newPemesanan = new Pemesanan;

    newPemesanan->kodePesanan = kodepes;

    for (int i = 0; i < 20; i++){
        newPemesanan->namaPemesan[i] = namapes[i];
        if (namapes[i] == '\0') // jika sudah mencapai akhir string, keluar dari loop
            break;
    }

    newPemesanan->KodeBarangpesan = kodbarpes;

    for (int i = 0; i < 20; i++){
        newPemesanan->namaBarang[i] = nambar[i];
        if (nambar[i] == '\0') 
            break;
    }
    newPemesanan->jumlahPesanan = jumpes;
    newPemesanan->tanggal = tgl;
    newPemesanan->bulan = bln;
    newPemesanan->tahun = thn;
    newPemesanan->Kota_asalpemesanan = asal;
    newPemesanan->kota_tujuanpemesanan = tujuan;
    newPemesanan->tanggal_pengiriman = tgl_pengiriman;
    newPemesanan->bulan_pengiriman = bln_pengiriman;
    newPemesanan->tahun_pengiriman = thn_pengiriman;
    newPemesanan->tanggal_sampai = tgl_sampai;
    newPemesanan->bulan_sampai = bln_sampai;
    newPemesanan->tahun_sampai = thn_sampai;

    newPemesanan->next = headPemesanan;
    headPemesanan = newPemesanan;
}

// fungsi untuk membuat tambah pesanan
void tambahPemesanan(){
    system("cls");
    system("color 71");
    int kodepes, kodbarpes, jumpes, tgl, bln, thn;
    char namapes[20], nambar[20];
    string asal, tujuan;
    char enter;


    cout << "\n\t===========================================================================" << endl;
    cout << "\t                            BUAT PEMESANAN BARANG                          " << endl;
    cout << "\t===========================================================================" << endl;
    cout << "\tMasukkan kode Pesanan        : ";
    cin >> kodepes;
    cout << "\tMasukkan Nama Pemesan        : ";
    cin >> namapes;
    cout << "\tMasukkan Kode Barang         : ";
    cin >> kodbarpes;

    // mencari barang dengan kode barang yang sesuai dalam daftar barang 
    Barang* current = head;
    bool barangDitemukan = false;
    while (current != nullptr){
        if(current->kodeBarang == kodbarpes){
            barangDitemukan = true;
            cout << "\tDetail Barang  " << endl;
            cout << "\t     Nama barang             : " << current->namaBarang << endl;
            cout << "\t     Stok                    : " << current->stok << endl;
            cout << "\t     Alamat barang           : " << &current->kodeBarang << endl;
            break;
        }
        current = current->next;
    }

    if (!barangDitemukan){
    system("cls");
    cout << "\n\n\n\n\n\t\t====================================================================" << endl;
    cout << "\n\t\t   Kode barang tidak ditemukan dalam daftar barang yang tersedia.   " << endl;
    cout << "\n\t\t====================================================================" << endl;
    cout << "\t\tTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'
    return;
    }
    cout << "\tMasukkan Nama Barang         : ";
    cin >> nambar;
    cout << "\tMasukkan Jumlah Pesanan      : ";
    cin >> jumpes;
    
    if (current->stok < jumpes){
        system("cls");
        cout << "\n\n\n\n\n\t\t===========================================================================" << endl;
        cout << "\n\t\tMaaf, stok barang tidak mencukupi untuk pesanan ini. Barang tidak tersedia." << endl;
        cout << "\n\t\tt===========================================================================" << endl;
        cout << "\t\tTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'
        return;
    }

    while(current != nullptr){
        if(current->kodeBarang == kodbarpes){
            // kurangi stok barang ssesuai dengan jumlah pesanan 
            current->stok -= jumpes;
            break;
        }
        current = current->next;
    }

    cout << "\tMasukkan Tanggal Pesanan     : ";
    cin >> tgl;
    cout << "\tMasukkan Bulan Pesanan       : ";
    cin >> bln;
    cout << "\tMasukkan Tahun Pesanan       : ";
    cin >> thn;
    cout << "\tMasukkan Kota Asal           : ";
    cin >> asal;
    cout << "\tMasukkan Kota Tujuan         : ";
    cin >> tujuan;

    //hitung tanggal pengiriman dan tanggal sampai (2 hari setelah tanggal pesanan)
    int tgl_pengiriman = tgl + 1;
    int bln_pengiriman = bln;
    int thn_pengiriman = thn;
    if (tgl_pengiriman > 30){
        tgl_pengiriman -= 30;
        bln_pengiriman++;
        if (bln_pengiriman > 12){
            bln_pengiriman -= 12;
            thn_pengiriman++;
        }
    }

    // tanggal sampai 3 hari setelah pengiriman 
    int tgl_sampai = tgl_pengiriman + 3;
    int bln_sampai = bln_pengiriman;
    int thn_sampai = thn_pengiriman;
    if (tgl_sampai > 30){
        tgl_sampai -= 30;
        bln_sampai++;
        if (bln_sampai > 12){
            bln_sampai -= 12;
            thn_sampai++;
        }
    }

    masukpemesanan(kodepes, namapes, kodbarpes, nambar, jumpes, tgl, bln, thn, asal, tujuan, tgl_pengiriman, bln_pengiriman, thn_pengiriman, tgl_sampai, bln_sampai, thn_sampai);
    system("cls");
    cout << "\n\n\n\n\n\t\t\t===================================" << endl;
    cout << "\n\t\t\t  PEMESANAN BERHASIL DITAMBAHKAN!  " << endl;
    cout << "\n\t\t\t===================================" << endl;
    cout << "\t\t\t*Tekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'
}

 
// fungsi untuk melihat proses pengiriman
void lihatprosespengiriman(){
    Pemesanan* current = headPemesanan;
    system("cls");
    system("color 71");
    char enter;

        if (current == nullptr){
            cout << "\n\n\n\n\n\t\t===========================================================================" << endl;
            cout << "\n\t\t   Tidak ada proses pemesanan barang/Belum ada pemesanan yang dilakukan    " << endl;
            cout << "\n\t\t===========================================================================" << endl;
            cout << "\t\tTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'
            return;
        }

        cout << "\n\t===========================================================================" << endl;
        cout << "\t                            PROSES PEMESANAN BARANG                        " << endl;
        cout << "\t===========================================================================" << endl;
        while (current != nullptr){
            cout << "\tKode Pesanan           : " << current->kodePesanan << endl;
            cout << "\tNama Pemesan           : " << current->namaPemesan << endl;
            cout << "\tKode Barang            : " << current->KodeBarangpesan << endl;
            cout << "\tNama Barang            : " << current->namaBarang << endl;
            
            // mencari alamat barang dengan kode barang yang sesuai dalam daftar barang
            Barang* currentBarang = head;
            while (currentBarang != nullptr){
                if(currentBarang->kodeBarang == current->KodeBarangpesan){
                    cout << "\tAlamat Barang            : " << &currentBarang->kodeBarang << endl;
                    break;
                }
                currentBarang = currentBarang->next;
            }

            cout << "\tJumlah Barang          : " << current->jumlahPesanan << endl;
            cout << "\tTanggal Pesan          : " << current->tanggal << "/" << current->bulan << "/" << current->tahun << endl;
            cout << "\tKota Asal              : " << current->Kota_asalpemesanan << endl;
            cout << "\tkota Tujuan            : " << current->kota_tujuanpemesanan << endl;
            cout << "\n\tInformasi Pengiriman " << endl;
            cout << "\tEstimasi Tanggal Pengiriman  : " << current->tanggal_pengiriman << "/" << current->bulan_pengiriman << "/" << current->tahun_pengiriman << endl;
            cout << "\tEstimasi Tanggal Sampai      : " << current->tanggal_sampai << "/" << current->bulan_sampai << "/" << current->tahun_sampai << endl;
            cout << "\t===========================================================================" << endl;
            current = current->next;
            }
            cout << "\t\tTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'
}

// fungsi untuk memasukkan barang ke dalam linked list
void masukbarang (int kodbar, const char nambar[], int stok){
    Barang* newnode = new Barang; // membuat node baru

    // mengisi data barang ke dalam node 
    newnode->kodeBarang = kodbar;

    //menyalin string namaBarang
    int i = 0;
    for (i = 0; nambar[i] != '\0' && i < 19; i++) {
        newnode->namaBarang[i] = nambar[i];    
    }
    newnode->namaBarang[i] = '\0'; // menambahkan null-terminator pada akhir string.

    newnode->stok = stok;
    newnode->next = head;

    //menjadikan node baru sebagai head 
    head = newnode;
}

// fungsi untuk menambah barang
void tambahbarang(){
    system("cls");
    system("color 71");
    int kodbar;
    char nambar[20];
    int stok;
    char enter;
    //meminta input untuk kode barang
    cout << "\n\t===========================================================================" << endl;
    cout << "\t                                TAMBAH BARANG                              " << endl;
    cout << "\t===========================================================================" << endl;
    cout << "\tMasukkan Kode Barang     : ";
    cin >> kodbar;

    // meminta input untuk nama barang 
    cout << "\tmasukkan Nama Barang     : ";
    cin >> nambar;

    // meminta input untuk stok barang
    cout << "\tmasukkakn Stok Barang    : ";
    cin >> stok;

    //memanggil fungsi masukbarang untuk menambahkan barang ke dalam linked list
    masukbarang(kodbar,nambar,stok);

    system("cls");
    cout << "\n\n\n\n\n\t\t\t================================" << endl;
    cout << "\n\t\t\t  BARANG BERHASIL DITAMBAHKAN!  " << endl;
    cout << "\n\t\t\t================================" << endl;
    cout << "\t\t\tTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'   
}

// fungsi untuk mengubah barang
void updatebarang(){
    system("cls");
    system("color 71");
    char enter;
    int newkodbar;
    cout << "\n\t===========================================================================" << endl;
    cout << "\t                                UPDATE BARANG                              " << endl;
    cout << "\t===========================================================================" << endl;
    cout << "\tMasukkan kode barang untuk barang yang ingin diperbarui : ";
    cin >> newkodbar;

    Barang* current = head;

    // mencari barang dengan kode barang yang sesuai dalam linked list
    while (current != nullptr){
        if (current->kodeBarang == newkodbar) {
            char newnambar[20];
            int newstok;

            // meminta input untuk nama barang baru
            cout << "\tMasukkan nama barang baru    : ";
            cin.ignore(); // membersihkan buffer sebelum menggunakan getline()
            cin.getline(newnambar, 20);

            // memperbarui informasi barang
            int i = 0;
            for (i = 0; newnambar[i] != '\0' && i < 19; i++) {
            current->namaBarang[i] = newnambar[i];
            }
            
            current->namaBarang[i] = '\0'; 

                    
                // meminta input untuk stok barang baru 
                cout << "\tMasukkan stok barang baru    : ";
                cin >> newstok;

                current->stok = newstok;
                system("cls");
                cout << "\n\n\n\n\n\t\t===========================================================================" << endl;
                cout << "\n\t\t                     INFORMASI BARANG BERHASIL DIPERBARUI!                 " << endl;  
                cout << "\n\t\t===========================================================================" << endl;
                cout << "\t\tTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'

                // membebaskan memori yang dialokasikan untuk array barangdata
                lihatbarang();
                
                return;
            }
            current = current->next;
        }

        // jika kode tidak ditemukan 
    system("cls");
    cout << "\n\n\n\n\n\t\t==================================================================" << endl;
    cout << "\n\t\t  Kode barang tidak ditemukan dalam daftar barang yang tersedia.  " << endl;
    cout << "\n\t\t==================================================================" << endl;   
    cout << "\t\tTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter' 
    return;   
}

// fungsi untuk menampilkan semua barang 
void lihatbarang(){
    system("cls");
    system("color 71");
    char enter;

    if (head == nullptr) {
        cout << "\n\n\n\n\n\t\t=========================================================" << endl;
        cout << "\n\t\t  Data Barang Kosong/belum ada barang yang ditambahkan   " << endl;
        cout << "\n\t\t=========================================================" << endl;
        cout << "\t\tTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'   
        return;
    }

    // menghitung jumlah barang 
    int count = 0;
    Barang* current = head;
    while (current != nullptr){
        count ++;
        current = current->next;
    }

    // membuat array untuk menyimpan data barang
    Barang** barangdata = new Barang*[count];
    int index = 0;
    current = head;
    while (current != nullptr) {
        barangdata[index++] = current;
        current = current->next;
    }

    // mengurutkan data barang berdasarkan kode barang
    for (int i = 0; i < count - 1; i++){
        for (int j = 0; j < count - i - 1; j++){
            if (barangdata[j]->kodeBarang > barangdata[j + 1]->kodeBarang){
                Barang* temp = barangdata[j];
                barangdata[j] = barangdata [j + 1];
                barangdata[j + 1] = temp;
            }
        }
    }
    

    cout << "\n\t============================================================================" << endl;
    cout << "\t|                               DAFTAR BARANG                              |" << endl;
    cout << "\t|==========================================================================|" << endl;  
    cout << "\t|  Kode Barang  |  Nama Barang          |  Stok Barang   |  Alamat Barang  | "<< endl;
    cout << "\t|==========================================================================|" << endl;

    // menampilkan barang sesuai dengan urutan penginputan
    for (int i = 0; i < count; i++){
        cout << "\t|  " << setiosflags(ios::left) << setw(11) << barangdata[i]->kodeBarang ;
        cout << "\t|  " << setiosflags(ios::left) << setw(15) << barangdata[i]->namaBarang ;
        cout << "\t|  " << setiosflags(ios::left) << setw(7) << barangdata[i]->stok ;
        cout << "\t |  " << &barangdata[i]->kodeBarang << "  |";
        cout << endl;
        }
        cout << "\t============================================================================" << endl;
        cout << "\tTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'

        // membersihkan memori yang dialokasikakn untuk array barangdata
        delete[] barangdata;

}

// fungsi untuk menghapus data barang
void hapusbarang(){
    system("cls");
    system("color 71");
    int kodbar;
    char enter;

    cout << "\n\t===========================================================================" << endl;
    cout << "\t                               HAPUS BARANG                                " << endl;
    cout << "\t===========================================================================" << endl;
    cout << "\tMasukkan kode barang yang ingin dihapus  : ";
    cin >> kodbar;

    Barang* current = head;
    Barang* prev = nullptr;

    //cari barang dengan kode yang sesuai
    while (current != nullptr){
        if (current->kodeBarang == kodbar){
            // jika barang ditemukan, lepas dari linked list
            if (prev == nullptr){
                head = current->next;
                delete current;
            } else {
                prev->next = current->next;
                delete current;
            }
            system("cls");
            cout << "\n\n\n\n\n\t\t=========================================================" << endl;
            cout << "\n\t\t  Barang dengan kode " << kodbar << " berhasil dihapus.  " << endl;
            cout << "\n\t\t=========================================================" << endl;
            cout << "\t\tTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter' 

            // membebaskan memori yang dialokasikan untuk array barang data
            delete[] barangdata;
            
            // memperbarui tampilan barang setelah menghapus barang 
            lihatbarang();
            return;
        }
        prev = current;
        current = current->next;
    }
    // barang tidak ditemukan
    system("cls");
    cout << "\n\n\n\n\n\t\t=========================================================" << endl;
            cout << "\n\t\t  Barang dengan kode " << kodbar << " tidak ditemukan.   " << endl;
            cout << "\n\t\t=========================================================" << endl;
    cout << "\t\tTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'  
}

int main(){
    const int MAX_AKUN = 100;

    Akun daftarAkun[MAX_AKUN];
    int jumlahAkun = 0;

    char pilihan;
    char enter;
    bool loggedIn = false;
    Akun* user = nullptr;
    
    system("cls");
    system("color 71");
    cout << "\n\t\t======================================================" << endl;
    cout << "\t\t|             FINAL PROJECT STRUKTUR DATA A          |" << endl;
	cout << "\t\t|  SISTEM INFORMASI PEMESANAN BARANG DAN PENGIRIMAN  |" << endl;
	cout << "\t\t|====================================================|" << endl;
	cout << "\t\t|       Zahra Fadhilatusyifa   [2310631170159]       |" << endl;
	cout << "\t\t======================================================" << endl;
    cout << "\t\tTekan 'Enter' untuk melanjutkan...."; 
                cin.get(enter); // menunggu 'Enter


    do{
        if (!loggedIn){
            system("cls");
            system("color 71");
            cout << "\n\t===========================================================================" << endl;
            cout << "\t         Selamat Datang di Aplikasi Pemesanan dan Pengiriman Barang        " << endl;
            cout << "\t===========================================================================" << endl;
            cout << "\n\tSilahkan login terlebih dahulu!" << endl;
            cout << "\n\t[1] Login" << endl;
            cout << "\t[2] Daftar akun baru" << endl;
            cout << "\t[3] Keluar " << endl;
            cout << "\t===========================================================================" << endl;
            cout << "\tmasukkan pilihan anda : " ;
            cin >> pilihan;
            
            switch (pilihan){
                case '1' :  {
                    user = login(daftarAkun, jumlahAkun, 4);
                    if (user != nullptr){
                        loggedIn = true;
                    }
                    break;
                }
                case '2' :
                    daftar(daftarAkun, jumlahAkun);
                    system("cls"); 
                    cout << "\n\n\n\n\n\t\t\t=====================================" << endl; 
                    cout << "\n\t\t\t   Akun baru berhasil didaftarkan!   " << endl;
                    cout << "\n\t\t\t=====================================" << endl;
                    cout << "\t\t\tTekan 'Enter' untuk melanjutkan...."; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'
                    break;
                case '3' :
                    system("cls");
                    cout << "\n\n\n\n\n\t\t==================================================================" << endl;
                    cout << "\n\t\t  Terimakasih telah menggunakan layanan kami. Sampai jumpa lagi!  " << endl; 
                    cout << "\n\t\t==================================================================" << endl; 
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'
                    return 0;
                default :
                    system("cls");
                    cout << "\n\n\n\n\t\t\t=============================" << endl;
                    cout << "\n\t\t\t  Pilihan anda tidak valid!  " << endl;
                    cout << "\n\t\t\t=============================" << endl;
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'

                    cout << endl;
                    return 0;
            }
        }
        else {
            system("cls");
            cout << "\n\n\n\tHalo "<< user->username << "! Selamat Datang di Aplikasi Pemesanan dan Pengiriman Barang" << endl;
            cout << "\n\t===========================================================================" << endl;
            cout << "\t                                  MENU UTAMA                               " << endl;
            cout << "\t===========================================================================" << endl;  
            cout << "\t[1] informasi barang " << endl;
            cout << "\t[2] informasi Pemesanan " << endl;
            cout << "\t[3] informasi akun" << endl;
            cout << "\t[4] keluar " << endl;
            cout << "\t==========================================================================" << endl;
            cout << "\tMasukkan pilihan anda    : ";
            cin >> pilihan;

            switch (pilihan){
                case '1' : 
                    tampilkanmenuinformasibarang();
                    break;
                case '2' :
                    tampilkanmenuinformasipemesanan();
                    break;
                case '3' : 
                    tampilkanmenuinformasiakun(user);
                    break;
                case '4' :
                    system("cls");
                    cout << "\n\n\n\n\n\t\t==================================================================" << endl;
                    cout << "\n\t\t  Terimakasih telah menggunakan layanan kami. Sampai jumpa lagi!  " << endl; 
                    cout << "\n\t\t==================================================================" << endl;
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'
 
                    return 0;
                default :
                    system("cls");
                    cout << "\n\n\n\\n\t\t\t=============================" << endl;
                    cout << "\n\t\t\t  Pilihan anda tidak valid!  " << endl;
                    cout << "\n\t\t\t=============================" << endl;
                    cin.ignore(); // membersihkan buffer masukan
                    cin.get(enter); // menunggu 'Enter'
                    
                    cout << endl;
                    return 0;
            }
        }

    }   while (true);

    return 0;

}