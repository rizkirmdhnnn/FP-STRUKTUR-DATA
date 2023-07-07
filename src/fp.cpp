#include <iostream>
using namespace std;

struct Book
{
    string judul;
    string penulis;
    string kategori;
    string isbn;
    int tahun;
    bool dipinjam;
};

struct Member
{
    string username;
    string password;
    bool admin;
};

Member anggota[100];

void defaultAdmin(string username, string password, bool admin)
{
    anggota[0].username = username;
    anggota[0].password = password;
    anggota[0].admin = admin;
}

void login()
{
    string username, password;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;
}

void createAccountMember()
{
    string username, password;
    cout << "Masukkan username: ";
    cin >> username;
    for (int i = 0; i < 100; i++)
    {
        if (username == anggota[i].username)
        {
            cout << "Username sudah terdaftar" << endl;
            createAccountMember();
        }
    }
    cout << "Masukkan password: ";
    cin >> password;
    for (int i = 0; i < 100; i++)
    {
        if (anggota[i].username == "")
        {
            anggota[i].username = username;
            anggota[i].password = password;
            anggota[i].admin = false;
            cout << "Akun berhasil dibuat" << endl;
            break;
        }
    }
}

void createAccountAdmin()
{
    string username, password;
    cout << "Masukkan username: ";
    cin >> username;
    for (int i = 0; i < 100; i++)
    {
        if (username == anggota[i].username)
        {
            cout << "Username sudah terdaftar" << endl;
            createAccountAdmin();
        }
    }

    cout << "Masukkan password: ";
    cin >> password;
    for (int i = 0; i < 100; i++)
    {
        if (anggota[i].username == "")
        {
            anggota[i].username = username;
            anggota[i].password = password;
            anggota[i].admin = true;
            cout << "Akun berhasil dibuat" << endl;
            break;
        }
    }
}

void loginScreen()
{
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

int main()
{
    defaultAdmin("admin", "admin", true);
    loginScreen();
    return 0;
}
