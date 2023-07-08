#include <iostream>
#include <iomanip>
#include <stack>
using namespace std;

const int MaxBuku = 100;
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
    bool isLogin;
};

Member anggota[100];
stack<Book> bukuStack; // Menggunakan stack STL

void defaultAdmin(string username, string password, bool admin, bool isLogin);
void login();
void buatAkunMember();
void loginScreen();
void dasboardMember();
void dasboardAdmin();
void daftarBuku();
void pinjamBuku();
void kembalikanBuku();
void informasiAkun(string admin);
void statistikBuku();
void managementBuku();
void urutISBN();
void urutKategori();
void jumlahBukuTersedia();
void daftarBukuDipinjam();
void tambahBuku();
void hapusBuku();
void sortingBuku();
void ubahPassword(int index, string dashboard);
void informasiAkun(string admin);
void kembaliDashboard();
void sortingBuku();

// fungsi untuk mengisi data default admin pada array anggota index ke 0
// parameter: username, password, admin
void defaultAdmin(string username, string password, bool admin, bool isLogin)
{
    anggota[0].username = username;
    anggota[0].password = password;
    anggota[0].admin = admin;
    anggota[0].isLogin = isLogin; // Mengubah status login menjadi false untuk admin default
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
                anggota[i].isLogin = true;
                dasboardAdmin();
            }
            else
            {
                anggota[i].isLogin = true;
                dasboardMember();
            }
        }
    }
    cout << "Username atau password salah" << endl;
    loginScreen();
}

// fungsi untuk membuat akun member baru pada array anggota
void buatAkunMember()
{
    system("cls");
    // deklarasi variabel username dan password
    string username, password;

    // input username
    cout << "Masukkan username: ";
    cin >> username;

    // perulangan untuk mengecek apakah username sudah terdaftar atau belum
    bool usernameTerdaftar = false;
    for (int i = 0; i < 100; i++)
    {
        if (username == anggota[i].username)
        {
            cout << "Username sudah terdaftar" << endl;
            usernameTerdaftar = true;
            break;
        }
    }

    if (!usernameTerdaftar)
    {
        // input password
        cout << "Masukkan password: ";
        cin >> password;

        // perulangan untuk mengecek apakah array anggota index ke i kosong atau tidak
        for (int i = 0; i < 100; i++)
        {
            if (anggota[i].username == "")
            {
                anggota[i].username = username;
                anggota[i].password = password;
                anggota[i].admin = false;
                anggota[i].isLogin = true; // Mengubah status login menjadi true
                cout << "Akun berhasil dibuat" << endl;
              
                login(); // Memanggil fungsi login setelah membuat akun anggota baru
                break;
            }
        }
    }
}

// fungsi untuk membuat akun admin baru pada array anggota
void loginScreen()
{
    int pilihan;
    do
    {
        system("cls");
        cout << "1. Masuk" << endl;
        cout << "2. Daftar" << endl;
        cout << "3. Keluar" << endl;
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
                buatAkunMember();
                break;
            case 3:
                exit(0);
                break;
            default:
                cout << "Pilihan tidak tersedia" << endl;
                break;
            }
        }
    } while (pilihan != 3);
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
    cout << "5. Keluar" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();
    switch (pilihan)
    {
        {
        case 1:
            daftarBuku();
            break;
        case 2:
            pinjamBuku();
            break;
        case 3:
            kembalikanBuku();
            break;
        case 4:
            informasiAkun("member");
            break;
        case 5:
            for (int i = 0; i < 100; i++)
            {
                if (anggota[i].isLogin == true)
                {
                    anggota[i].isLogin = false;
                }
            }
            loginScreen();
            break;
        default:
            cout << "Pilihan tidak tersedia" << endl;
            break;
        }
    }
}

// fungsi untuk menampilkan dasboard admin setelah login
void dasboardAdmin()
{
    system("cls");
    int pilihan;
    cout << "Selamat Datang " << endl;
    cout << "1. Daftar Buku" << endl;
    cout << "2. Kelola Buku" << endl;
    cout << "3. Statistik Buku" << endl;
    cout << "4. Informasi Akun" << endl;
    cout << "5. Keluar Aplikasi" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();
    switch (pilihan)
    {
        {
        case 1:
            daftarBuku();
            break;
        case 2:
            managementBuku();
            break;
        case 3:
            statistikBuku();
            break;
        case 4:
            informasiAkun("admin");
            break;
        case 5:
            for (int i = 0; i < 100; i++)
            {
                if (anggota[i].isLogin == true)
                {
                    anggota[i].isLogin = false; // Mengubah status login menjadi false
                }
            }
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
            break;
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

void kembaliDashboard()
{
    for (int i = 0; i < 100; i++)
    {
        if (anggota[i].isLogin == true)
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
}

// fungsi untuk menambahkan buku ke dalam stack buku
void tambahBuku()
{
    if (bukuStack.size() == MaxBuku)
    {
        cout << "Stack penuh. Tidak dapat menambahkan buku." << endl;
        system("pause");
        kembaliDashboard();
    }
    else
    {
        Book buku;
        cin.ignore(); // membersihkan newline sebelumnya
        cout << "Masukkan judul buku: ";
        getline(cin, buku.judul);

        cout << "Masukkan penulis buku: ";
        getline(cin, buku.penulis);

        cout << "Masukkan kategori buku: ";
        getline(cin, buku.kategori);

        cout << "Masukkan ISBN buku: ";
        cin >> buku.isbn;
        cin.ignore(); // membersihkan newline

        cout << "Masukkan tahun terbit buku: ";
        cin >> buku.tahun;

        bukuStack.push(buku);
        cout << "Buku berhasil ditambahkan ke dalam stack." << endl;
        system("pause");
        kembaliDashboard();
    }
}
void hapusBuku()

{
    system("cls");
    int pilihan;
    cout <<setw(60)<< "<<<<< Hapus Buku >>>>>" << endl;


    if (bukuStack.empty())
    {
        cout << "Tidak ada buku yang tersedia." << endl;
    }
    else
    {
        stack<Book> tempStack; // Stack sementara untuk mengembalikan buku-buku ke stack asli dengan urutan semula

        int counter =1 ;
    cout << " NO || " << setw(15) << left << "Judul Buku"
         << " || " << setw(15) << left << "Kategori Buku"
         << " || " << setw(15) << left << "Penulis Buku"
         << " || " << setw(15) << left << "Tahun Buku"
         << " || " << setw(15) << left << "Nomor ISBN" << " ||" << endl;

    while (!bukuStack.empty())
    {
        Book buku = bukuStack.top();
        bukuStack.pop();

        cout << setw(3) << right << counter << " || " << setw(15) << left << buku.judul
             << " || " << setw(15) << left << buku.kategori
             << " || " << setw(15) << left << buku.penulis
             << " || " << setw(15) << left << buku.tahun
             << " || " << setw(15) << left << buku.isbn << " ||" << endl;

        counter++;
        }

        cout << "Pilih nomor buku yang ingin dihapus (0 untuk batalkan): ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan >= 1 && pilihan < counter)
        {
            counter = 1;
            stack<Book> tempStack2; // Stack sementara untuk mengembalikan buku-buku ke stack asli dengan urutan semula

            while (!tempStack.empty())
            {
                Book buku = tempStack.top();
                tempStack.pop();
                if (counter != pilihan)
                {
                    tempStack2.push(buku);
                }
                counter++;
            }

            while (!tempStack2.empty())
            {
                Book buku = tempStack2.top();
                tempStack2.pop();
                bukuStack.push(buku);
            }

            cout << "Buku berhasil dihapus." << endl;
        }
        else if (pilihan != 0)
        {
            cout << "Nomor buku tidak valid." << endl;
        }
    }

    system("pause");
    kembaliDashboard();


}
void urutKategori()
{
}
void urutISBN()
{
}

// fungsi untuk menampilkan daftar buku
void daftarBuku()
{
    system("cls");
    cout << "Daftar Buku" << endl;

    if (bukuStack.empty())
    {
        cout << "Tidak ada buku yang tersedia." << endl;
    }
    else
    {
        stack<Book> tempStack; // Stack sementara untuk mengembalikan buku-buku ke stack asli dengan urutan semula

        while (!bukuStack.empty())
        {
            Book buku = bukuStack.top();
            bukuStack.pop();
            tempStack.push(buku);
            cout << "============================================" << endl;
            cout << "Judul: " << buku.judul << endl;
            cout << "Penulis: " << buku.penulis << endl;
            cout << "Kategori: " << buku.kategori << endl;
            cout << "ISBN: " << buku.isbn << endl;
            cout << "Tahun Terbit: " << buku.tahun << endl;
            cout << "============================================" << endl;
        }

        while (!tempStack.empty())
        {
            Book buku = tempStack.top();
            tempStack.pop();
            bukuStack.push(buku);
        }
    }
    sortingBuku();
}

void sortingBuku()
{
    cout << "Menu Sorting" << endl;
    cout << "1. Urutkan berdasarkan kategori" << endl;
    cout << "2. Urutkan berdasarkan ISBN" << endl;
    cout << "3. Kembali" << endl;
    cout << "Pilihan: ";
    int pilihan;
    cin >> pilihan;
    cin.ignore();
    switch (pilihan)
    {
        {
        case 1:
            urutKategori();
            break;
        case 2:
            urutISBN();
            break;
        case 3:
            kembaliDashboard();
            break;
        default:
            cout << "Pilihan tidak tersedia" << endl;
            break;
        }
    }
}
// fungsi untuk menampilkan statistik buku
void pinjamBuku()
{
}

void kembalikanBuku()
{
}

// fungsi untuk merubah password
void ubahPassword(int index, string dashboard)
{
    system("cls");
    string password;
    cout << "Masukkan password baru: ";
    cin >> password;
    anggota[index].password = password;
    cout << "Password berhasil diubah" << endl;
   
    if (dashboard == "admin")
    {
        dasboardAdmin();
    }
    else
    {
        dasboardMember();
    }
}

// fungi untuk menampilkan informasi akun
void informasiAkun(string akun)
{
    system("cls");

    for (int i = 0; i < 100; i++)
    {
        if (anggota[i].isLogin == true)
        {
            // menyimpan data username dan password pada array anggota

            cout << "Informasi Akun" << endl;
            cout << "Username : " << anggota[i].username << endl;
            cout << "Password  : " << anggota[i].password << endl;

            if (anggota[i].admin == true)
            {
                cout << "Jenis Akun : Admin" << endl;
            }
            else
            {
                cout << "Jenis Akun : Member" << endl;
            }

            int pilihan;
            cout << "1. Ubah Password" << endl;
            cout << "2. Kembali" << endl;
            cout << "Pilihan: ";
            cin >> pilihan;
            cin.ignore();
            switch (pilihan)
            {
                {
                case 1:
                    if (akun == "admin")
                    {
                        ubahPassword(i, "admin");
                        dasboardAdmin(); // Tambahkan pemanggilan dasboardAdmin() setelah perubahan password
                    }
                    else
                    {
                        ubahPassword(i, "member");
                        dasboardMember(); // Tambahkan pemanggilan dasboardMember() setelah perubahan password
                    }
                    break;
                case 2:
                    dasboardMember();
                default:
                    cout << "Pilihan tidak tersedia" << endl;
                    break;
                }
            }
        }
    }
    cout << "Akun tidak ditemukan" << endl;
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
            break;
        default:
            cout << "Pilihan tidak tersedia" << endl;
            break;
        }
    }
}

void sortingBuku()
{
    system("cls");
    int pilMenu;
    cout << "MengurutkanDaftar Buku" << endl;
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
        break;
    default:
        cout << "Pilihan tidak tersedia" << endl;
        break;
    }
}

// fungsi utama
int main()
{
    defaultAdmin("admin", "admin", true, false);
    loginScreen();
    return 0;
}
