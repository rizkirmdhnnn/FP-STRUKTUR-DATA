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
    bool status;
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

// deklarasi array buku
Member anggota[100];

// deklarasi stack buku
stack<Book> bukuStack; // Menggunakan stack STL

void defaultAdmin(string username, string password, bool admin, bool isLogin);
void login();
void buatAkunMember();
void loginScreen();
void dasboardMember();
void dasboardAdmin();
void daftarBuku();
void pinjamBuku();
void sortingBuku();
void kembalikanBuku();
void informasiAkun(string admin);
void statistikBuku(); // agung
void managementBuku();
void urutISBN();           // agung
void urutKategori();       // agung
void daftarBukuTersedia(); // khoirul
void daftarBukuDipinjam();
void tambahBuku(); // alex
void hapusBuku();  // khoirul
void ubahPassword(int index, string dashboard);
void informasiAkun(string admin); // khoirul
void kembaliDashboard();
void daftarBuku(); // alex

// fungsi untuk mengisi data default admin pada array anggota index ke 0
// parameter: username, password, admin
void defaultAdmin(string username, string password, bool admin, bool isLogin)
{
    anggota[0].username = username; // Mengisi username
    anggota[0].password = password; // Mengisi password
    anggota[0].admin = admin;       // Mengisi status admin
    anggota[0].isLogin = isLogin;   // Mengisi status login
}

// fungsi untuk login ke sistem
void login()
{
    system("cls");
    string username, password;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    // perulangan untuk mengecek apakah username dan password yang dimasukkan sesuai dengan data yang ada pada array anggota
    for (int i = 0; i < 100; i++)
    {
        // jika username dan password yang dimasukkan sesuai dengan data yang ada pada array anggota
        if (username == anggota[i].username && password == anggota[i].password)
        {
            // jika status admin pada array anggota index ke i bernilai true
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
    _sleep(2000);
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
        // jika username yang dimasukkan sudah terdaftar
        if (username == anggota[i].username)
        {
            cout << "Username sudah terdaftar" << endl;
            usernameTerdaftar = true;
            break;
        }
    }

    // jika username yang dimasukkan belum terdaftar
    if (!usernameTerdaftar)
    {
        // input password
        cout << "Masukkan password: ";
        cin >> password;

        // perulangan untuk mengecek apakah array anggota index ke i kosong atau tidak
        for (int i = 0; i < 100; i++)
        {
            // jika array anggota index ke i kosong
            if (anggota[i].username == "")
            {
                anggota[i].username = username; // Mengisi username
                anggota[i].password = password; // Mengisi password
                anggota[i].admin = false;       // Mengisi status admin menjadi false
                anggota[i].isLogin = true;      // Mengubah status login menjadi true
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
    } while (pilihan != 3); // perulangan untuk mengecek apakah pilihan yang dimasukkan tidak sama dengan 3
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
            // perulangan untuk mengubah status login menjadi false pada semua array anggota
            for (int i = 0; i < 100; i++)
            {
                // jika status login pada array anggota index ke i bernilai true
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
            // perulangan untuk mengubah status login menjadi false pada semua array anggota
            for (int i = 0; i < 100; i++)
            {
                // jika status login pada array anggota index ke i bernilai true
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

// fungsi untuk manajemen buku oleh admin
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

// fungsi untuk menampilkan daftar buku yang tersedia
void daftarBukuTersedia()
{
    system("cls");
    cout << "daftar Buku Tersedia" << endl;

    // pengecekan apakah stack buku kosong
     if (bukuStack.empty())
    {
        cout << "\nTidak ada buku yang tersedia." << endl;
        string konfir;
        cout << "[Y] Untuk Kembali : ";
        cin >> konfir;
        if (konfir == "Y" || konfir == "y")
        {
            kembaliDashboard();
        }
        else
        {
            cout << "Anda Masukkan perintah yang salah";
            _sleep(1000);
            statistikBuku();
        }
    }
    else
    {
        // Stack sementara untuk mengembalikan buku-buku ke stack asli dengan urutan semula
        stack<Book> tempStack;

        // perulangan untuk menampilkan buku yang tersedia
        while (!bukuStack.empty())
        {
            // mengambil buku dari stack
            Book buku = bukuStack.top();
            bukuStack.pop();
            tempStack.push(buku);

            // menampilkan buku jika statusnya true
            if (buku.status)
            {
                cout << "============================================" << endl;
                cout << "Judul: " << buku.judul << endl;
                cout << "Penulis: " << buku.penulis << endl;
                cout << "Kategori: " << buku.kategori << endl;
                cout << "ISBN: " << buku.isbn << endl;
                cout << "Tahun Terbit: " << buku.tahun << endl;
            }
            cout << "============================================" << endl;
        }

        // mengembalikan buku-buku ke stack asli dengan urutan semula
        while (!tempStack.empty())
        {
            Book buku = tempStack.top();
            tempStack.pop();
            bukuStack.push(buku);
        }
        sortingBuku();
    }
}

// fungsi untuk menampilkan daftar buku yang dipinjam
void daftarBukuDipinjam()
{
    system("cls");
    cout << "Daftar Buku" << endl;

    // pengecekan apakah stack buku kosong
    if (bukuStack.empty())
    {
        cout << "Tidak ada buku yang tersedia." << endl;
        kembaliDashboard();
    }
    else
    {
        // Stack sementara untuk mengembalikan buku-buku ke stack asli dengan urutan semula
        stack<Book> tempStack;

        // perulangan untuk menampilkan buku yang tersedia
        while (!bukuStack.empty())
        {
            // mengambil buku dari stack
            Book buku = bukuStack.top();
            bukuStack.pop();
            tempStack.push(buku);

            // menampilkan buku jika statusnya false
            if (!buku.status)
            {
                cout << "============================================" << endl;
                cout << "Judul: " << buku.judul << endl;
                cout << "Penulis: " << buku.penulis << endl;
                cout << "Kategori: " << buku.kategori << endl;
                cout << "ISBN: " << buku.isbn << endl;
                cout << "Tahun Terbit: " << buku.tahun << endl;
            }
            cout << "============================================" << endl;
        }

        // mengembalikan buku-buku ke stack asli dengan urutan semula
        while (!tempStack.empty())
        {
            Book buku = tempStack.top();
            tempStack.pop();
            bukuStack.push(buku);
        }
        sortingBuku();
    }
}

// fungsi unttuk kembali ke dashboard
void kembaliDashboard()
{
    // perulangan untuk mengecek status login pada array anggota
    for (int i = 0; i < 100; i++)
    {
        // jika status login pada array anggota index ke i bernilai true
        if (anggota[i].isLogin == true)
        {
            // jika status admin pada array anggota index ke i bernilai true
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
    // pengecekan apakah stack buku penuh
    if (bukuStack.size() == MaxBuku)
    {
        cout << "Stack penuh. Tidak dapat menambahkan buku." << endl;
        system("pause");
        managementBuku();
    }
    else
    {
        // menambahkan buku ke dalam stack
        Book buku;
        cin.ignore(); // membersihkan newline
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
        buku.status = true;

        // menambahkan buku ke dalam stack
        bukuStack.push(buku);
        cout << "Buku berhasil ditambahkan ke dalam stack." << endl;
        system("pause");
        managementBuku();
    }
}

// fungsi untuk menghapus buku dari stack buku
void hapusBuku()
{
    system("cls");
    cout << setw(60) << "<<<<< Hapus Buku >>>>>" << endl;

    // pengecekan apakah stack buku kosong
    if (bukuStack.empty())
    {
        cout << "Tidak ada buku yang tersedia." << endl;
    }
    else
    {
        // Stack sementara untuk mengembalikan buku-buku ke stack asli dengan urutan semula
        stack<Book> tempStack;

        int counter = 1;
        cout
            << " NO || " << setw(15) << left << "Judul Buku"
            << " || " << setw(15) << left << "Kategori Buku"
            << " || " << setw(15) << left << "Penulis Buku"
            << " || " << setw(15) << left << "Tahun Buku"
            << " || " << setw(15) << left << "Nomor ISBN"
            << " ||" << endl;

        // perulangan untuk menampilkan buku yang tersedia
        while (!bukuStack.empty())
        {
            // mengambil buku dari stack
            Book buku = bukuStack.top();
            bukuStack.pop();
            cout
                << setw(3) << right << counter << " || " << setw(15) << left << buku.judul
                << " || " << setw(15) << left << buku.kategori
                << " || " << setw(15) << left << buku.penulis
                << " || " << setw(15) << left << buku.tahun
                << " || " << setw(15) << left << buku.isbn << " ||" << endl;
            counter++;
        }

        int pilihan;
        cout << "Pilih nomor buku yang ingin dihapus (0 untuk batalkan): ";
        cin >> pilihan;
        cin.ignore();

        // pengecekan apakah pilihan buku yang ingin dihapus valid
        if (pilihan >= 1 && pilihan < counter)
        {
            counter = 1;
            // Stack sementara untuk mengembalikan buku-buku ke stack asli dengan urutan semula
            stack<Book> tempStack2;

            // perulangan untuk menghapus buku yang dipilih
            while (!tempStack.empty())
            {
                // mengambil buku dari stack
                Book buku = tempStack.top();
                // menghapus buku dari stack
                tempStack.pop();
                // pengecekan apakah buku yang diambil merupakan buku yang ingin dihapus
                if (counter != pilihan)
                {
                    // menambahkan buku ke dalam stack sementara
                    tempStack2.push(buku);
                }
                counter++;
            }

            // mengembalikan buku-buku ke stack asli dengan urutan semula
            while (!tempStack2.empty())
            {
                // mengambil buku dari stack sementara
                Book buku = tempStack2.top();
                // menghapus buku dari stack sementara
                tempStack2.pop();
                // menambahkan buku ke dalam stack asli
                bukuStack.push(buku);
            }

            cout << "Buku berhasil dihapus." << endl;
        }
        // pengecekan apakah pilihan buku yang ingin dihapus adalah 0
        else if (pilihan != 0)
        {
            cout << "Nomor buku tidak valid." << endl;
        }
    }

    system("pause");
    managementBuku();
}
// fungsi untuk mengurutkan buku berdasarkan kategori secara ascending
void urutKategori()
{
    system("cls");
    cout << "Urutkan Buku berdasarkan Kategori (Ascending)" << endl;

    // Membuat salinan stack buku
    stack<Book> tempStack = bukuStack;

    // Menghitung jumlah buku dalam stack
    int size = tempStack.size();

    // Array sementara untuk menyimpan buku-buku dalam stack
    Book *bukuArray = new Book[size];

    // Memindahkan buku-buku dari stack ke array
    for (int i = 0; i < size; i++)
    {
        bukuArray[i] = tempStack.top();
        tempStack.pop();
    }

    // Sorting bubble sort secara ascending berdasarkan kategori
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            // Membandingkan kategori buku pada posisi j dan j+1
            if (bukuArray[j].kategori > bukuArray[j + 1].kategori)
            {
                // Menukar posisi buku jika kategori pada posisi j lebih besar dari kategori pada posisi j+1
                Book temp = bukuArray[j];
                bukuArray[j] = bukuArray[j + 1];
                bukuArray[j + 1] = temp;
            }
        }
    }

    // Menampilkan buku-buku setelah diurutkan
    for (int i = 0; i < size; i++)
    {
        cout << "============================================" << endl;
        cout << "Judul: " << bukuArray[i].judul << endl;
        cout << "Penulis: " << bukuArray[i].penulis << endl;
        cout << "Kategori: " << bukuArray[i].kategori << endl;
        cout << "ISBN: " << bukuArray[i].isbn << endl;
        cout << "Tahun Terbit: " << bukuArray[i].tahun << endl;
    }
    cout << "============================================" << endl;

    // Memasukkan buku-buku dari array ke stack kembali
    for (int i = size - 1; i >= 0; i--)
    {
        tempStack.push(bukuArray[i]);
    }

    // Mengembalikan stack buku ke stack asli
    bukuStack = tempStack;

    delete[] bukuArray;

    system("pause");
    kembaliDashboard();
}

// fungsi untuk mengurutkan buku berdasarkan nomor ISBN secara ascending
void urutISBN()
{
    system("cls");
    cout << "Urutkan Buku berdasarkan ISBN (Ascending)" << endl;

    // Membuat salinan stack buku
    stack<Book> tempStack = bukuStack;

    // Menghitung jumlah buku dalam stack
    int size = tempStack.size();

    // Array sementara untuk menyimpan buku-buku dalam stack
    Book *bukuArray = new Book[size];

    // Memindahkan buku-buku dari stack ke array
    for (int i = 0; i < size; i++)
    {
        bukuArray[i] = tempStack.top();
        tempStack.pop();
    }

    // Sorting bubble sort secara ascending berdasarkan ISBN
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            // Membandingkan ISBN buku pada posisi j dan j+1
            if (bukuArray[j].isbn > bukuArray[j + 1].isbn)
            {
                // Menukar posisi buku jika ISBN pada posisi j lebih besar dari ISBN pada posisi j+1
                Book temp = bukuArray[j];
                bukuArray[j] = bukuArray[j + 1];
                bukuArray[j + 1] = temp;
            }
        }
    }

    // Menampilkan buku-buku setelah diurutkan
    for (int i = 0; i < size; i++)
    {
        cout << "============================================" << endl;
        cout << "Judul: " << bukuArray[i].judul << endl;
        cout << "Penulis: " << bukuArray[i].penulis << endl;
        cout << "Kategori: " << bukuArray[i].kategori << endl;
        cout << "ISBN: " << bukuArray[i].isbn << endl;
        cout << "Tahun Terbit: " << bukuArray[i].tahun << endl;
    }
    cout << "============================================" << endl;

    // Memasukkan buku-buku dari array ke stack kembali
    for (int i = size - 1; i >= 0; i--)
    {
        tempStack.push(bukuArray[i]);
    }

    // Mengembalikan stack buku ke stack asli
    bukuStack = tempStack;

    delete[] bukuArray;

    system("pause");
    kembaliDashboard();
}

// fungsi untuk menampilkan daftar buku
void daftarBuku()
{
    system("cls");
    cout << "Daftar Buku" << endl;

    // pengecekan apakah stack buku kosong
    if (bukuStack.empty())
    {
        cout << "\nTidak ada buku yang tersedia." << endl;
        string konfir;
        cout << "[Y] Untuk Kembali : ";
        cin >> konfir;
        if (konfir == "Y" || konfir == "y")
        {
            kembaliDashboard();
        }
        else
        {
            cout << "Anda Masukkan perintah yang salah";
            _sleep(1000);
            daftarBuku();
        }
    }
    else
    {
        // Stack sementara untuk mengembalikan buku-buku ke stack asli dengan urutan semula
        stack<Book> tempStack;

        // perulangan untuk menampilkan buku yang tersedia
        while (!bukuStack.empty())
        {
            // mengambil buku dari stack
            Book buku = bukuStack.top();
            bukuStack.pop();
            tempStack.push(buku);
            cout << "============================================" << endl;
            cout << "Judul: " << buku.judul << endl;
            cout << "Penulis: " << buku.penulis << endl;
            cout << "Kategori: " << buku.kategori << endl;
            cout << "ISBN: " << buku.isbn << endl;
            cout << "Tahun Terbit: " << buku.tahun << endl;
            cout << "Status: ";

            // pengecekan status buku
            if (buku.status == true)
            {
                cout << "Tersedia" << endl;
            }
            else
            {
                cout << "Dipinjam" << endl;
            }
            cout << "============================================" << endl;
        }

        // mengembalikan buku-buku ke stack asli dengan urutan semula
        while (!tempStack.empty())
        {
            Book buku = tempStack.top();
            tempStack.pop();
            bukuStack.push(buku);
        }
        sortingBuku();
    }
}

// fungsi untuk sorting buku
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
    system("cls");
    daftarBukuTersedia();
    cout << "Pinjam Buku" << endl;
    cout << "Masukkan Judul buku yang ingin dipinjam: ";
    string judul;
    cin >> judul;
    cin.ignore();

    stack<Book> tempStack; // Stack sementara untuk mengembalikan buku-buku ke stack asli dengan urutan semula

    while (!bukuStack.empty())
    {
        Book buku = bukuStack.top();
        bukuStack.pop();
        if (buku.judul == judul)
        {
            if (buku.status == true)
            {
                buku.status = false;
                cout << "Buku berhasil dipinjam." << endl;
            }
            else
            {
                cout << "Buku sedang dipinjam." << endl;
            }
        }
        tempStack.push(buku);
    }

    while (!tempStack.empty())
    {
        Book buku = tempStack.top();
        tempStack.pop();
        bukuStack.push(buku);
    }

    system("pause");
    kembaliDashboard();
}

void kembalikanBuku()
{
    system("cls");
    cout << "Kembalikan Buku" << endl;
    cout << "Masukkan Judul buku yang ingin dikembalikan: ";
    string judul;
    cin >> judul;
    cin.ignore();

    stack<Book> tempStack; // Stack sementara untuk mengembalikan buku-buku ke stack asli dengan urutan semula

    while (!bukuStack.empty())
    {
        Book buku = bukuStack.top();
        bukuStack.pop();
        if (buku.judul == judul)
        {
            if (buku.status == false)
            {
                buku.status = true;
                cout << "Buku berhasil dikembalikan." << endl;
            }
            else
            {
                cout << "Buku tidak sedang dipinjam." << endl;
            }
        }
        tempStack.push(buku);
    }

    while (!tempStack.empty())
    {
        Book buku = tempStack.top();
        tempStack.pop();
        bukuStack.push(buku);
    }

    system("pause");
    kembaliDashboard();
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
                    kembaliDashboard();
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
    cout << "1. Daftar Buku Tersedia" << endl;
    cout << "2. Daftar Buku Dipinjam" << endl;
    cout << "3. Kembali" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();
    switch (pilihan)
    {
        {
        case 1:
            daftarBukuTersedia();
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

// fungsi utama
int main()
{
    defaultAdmin("admin", "admin", true, false);
    loginScreen();
    return 0;
}
