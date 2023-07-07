#include <iostream>
using namespace std;

struct Book
{
    string judul;
    string penulis;
    string kategori;
    string dipinjamOleh;
    int isbn;
    int tahun;
};

struct Member
{
    string username;
    string password;
    bool admin;
};

Member anggota[100];

void defaultAdmin(string username, string password, bool admin);
void login();
void createAccountMember();
void createAccountAdmin();
void loginScreen();
void dasboardMember();
void dasboardAdmin();
void daftarBuku();
void pinjamBuku();
void kembalikanBuku();
void informasiAkun();
void statistikBuku();
void managementBuku();
void tambahAdminBaru();
void urutISBN();
void urutKategori();
void jumlahBukuTersedia();
void daftarBukuDipinjam();
void tambahBuku();
void hapusBuku();

// fungsi untuk mengisi data default admin pada array anggota index ke 0
// parameter: username, password, admin
void defaultAdmin(string username, string password, bool admin)
{
    anggota[0].username = username;
    anggota[0].password = password;
    anggota[0].admin = admin;
}

void login()
{
    system("cls");
    string username, password;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;
    for (int i = 0; i < 100; i++)
    {
        if (username == anggota[i].username && password == anggota[i].password)
        {
            if (anggota[i].admin == true)
            {
                dasboardAdmin();
            }
            else
            {
                dasboardMember();
            }
        }
    }
    cout << "Username atau password salah" << endl;
    loginScreen();
}

// fungsi untuk membuat akun member baru pada array anggota
void createAccountMember()
{
    system("cls");

    // deklarasi variabel username dan password
    string username, password;

    // input username
    cout << "Masukkan username: ";
    cin >> username;

    // perulangan untuk mengecek apakah username sudah terdaftar atau belum
    for (int i = 0; i < 100; i++)
    {
        if (username == anggota[i].username)
        {
            cout << "Username sudah terdaftar" << endl;
            break;
        }
    }

    // input password
    cout << "Masukkan password: ";
    cin >> password;

    // perulangan untuk mengecek apakah array anggota index ke i kosong atau tidak
    // perulangan untuk menimpan data username dan password pada array anggota
    for (int i = 0; i < 100; i++)
    {
        if (anggota[i].username == "")
        {
            // menyimpan data username dan password pada array anggota
            anggota[i].username = username;
            anggota[i].password = password;
            anggota[i].admin = false;
            cout << "Akun berhasil dibuat" << endl;
            dasboardMember();
            break;
        }
    }
}

// fungsi untuk membuat akun admin baru pada array anggota
void createAccountAdmin()
{
    system("cls");

    // deklarasi variabel username dan password
    string username, password;

    // input username
    cout << "Masukkan username: ";
    cin >> username;

    // perulangan untuk mengecek apakah username sudah terdaftar atau belum
    for (int i = 0; i < 100; i++)
    {
        if (username == anggota[i].username)
        {
            cout << "Username sudah terdaftar" << endl;
            createAccountAdmin();
        }
    }

    // input password
    cout << "Masukkan password: ";
    cin >> password;

    // perulangan untuk menimpan data username dan password pada array anggota
    // perulangan untuk mengecek apakah array anggota index ke i kosong atau tidak
    for (int i = 0; i < 100; i++)
    {
        if (anggota[i].username == "")
        {
            // menyimpan data username dan password pada array anggota
            anggota[i].username = username;
            anggota[i].password = password;
            anggota[i].admin = true;
            cout << "Akun berhasil dibuat" << endl;
            dasboardAdmin();
            break;
        }
    }
}

void loginScreen()
{
    system("cls");
    int pilihan;
    cout << "1. Masuk" << endl;
    cout << "2. Daftar" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();
    switch (pilihan)
    {
        {
        case 1:
            login();
            break;
        case 2:
            createAccountMember();
            break;
        default:
            break;
        }
    }
}

// fungsi untuk menampilkan dasboard member setelah login
void dasboardMember()
{
    system("cls");
    int pilihan;
    cout << "Selamat Datang " << endl;
    cout << "1. Daftar Buku" << endl;
    cout << "2. Pinjam Buku" << endl;
    cout << "3. Kembalikan Buku" << endl;
    cout << "4. Informasi Akun" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();
    switch (pilihan)
    {
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            cout << "Pilihan tidak tersedia" << endl;
            break;
        }
    }
}

void dasboardAdmin()
{
    system("cls");
    int pilihan;
    cout << "Selamat Datang " << endl;
    cout << "1. Kelola Buku" << endl;
    cout << "2. Statistik Buku" << endl;
    cout << "3. Tambah Admin Baru" << endl;
    cout << "4. Keluar Aplikasi" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();
    switch (pilihan)
    {
        {
        case 1:
            managementBuku();
            break;
        case 2:
            statistikBuku();
            break;
        case 3:
            break;
        case 4:
            loginScreen();
            break;
        default:
            cout << "Pilihan tidak tersedia" << endl;
            break;
        }
    }
}

void managementBuku()
{
    system("cls");
    int pilihan;
    cout << "Kelola Buku" << endl;
    cout << "1. Tambah Buku" << endl;
    cout << "2. Hapus Buku" << endl;
    cout << "3. Kembali" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();
    switch (pilihan)
    {
        {
        case 1:
            tambahBuku();
            break;
        case 2:
            hapusBuku();
            break;
        case 3:
            dasboardAdmin();
        default:
            cout << "Pilihan tidak tersedia" << endl;
            break;
        }
    }
}

void jumlahBukuTersedia()
{
}

void daftarBukuDipinjam()
{
}
void tambahBuku()
{
}

void hapusBuku()
{
}

void urutKategori()
{
}

void urutISBN()
{
}

void statistikBuku()
{
    system("cls");
    int pilihan;
    cout << "1. Jumlah Buku Tersedia" << endl;
    cout << "2. Daftar Buku Dipinjam" << endl;
    cout << "3. Kembali" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();
    switch (pilihan)
    {
        {
        case 1:
            jumlahBukuTersedia();
            break;
        case 2:
            daftarBukuDipinjam();
            break;
        case 3:
            dasboardAdmin();
        default:
            cout << "Pilihan tidak tersedia" << endl;
            break;
        }
    }
}

void daftarBuku() //
{
    system("cls");
    int pilMenu;
    cout << "Mengurutkan Daftar Buku" << endl;
    cout << "1. Berdasarkan Kategori " << endl;
    cout << "2. Berdasarkan ISBN " << endl;
    cout << "3. Kembali " << endl;
    cout << "\nPilihan : ";
    cin >> pilMenu;
    cin.ignore();
    switch (pilMenu)
    {
    case 1:
        urutKategori();
        break;
    case 2:
        urutISBN();
        break;
    case 3:
        dasboardAdmin();

    default:
        cout << "Pilihan tidak tersedia" << endl;
        break;
    }
}
int main()
{
    defaultAdmin("admin", "admin", true);
    loginScreen();
    return 0;
}
