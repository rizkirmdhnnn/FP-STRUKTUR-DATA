#include "menu.cpp"
#include "xycolor.h"

void all();
void firstLogin();
void incomeDetail(string kategori);
void spendDetail(string kategori);
void addSpend();
void addIncome();
void loadingAnimation(int panjang, int x, int y, int fc, int bc);
void searchKategori(string str);
void ulang(string menu, string atr);
void saveSpend(string nama, string kategori, string harga, string date);
void saveIncome(string nominal, string kategori, string date);
void textSuccess(int x, int y, int string);
void ulangBaru(int x, int y, string str, int color);
void loadDataIncome();
void loadDataSpend();
void getData(string data, string category);
void categoryIncome();
void categorySpend();

void removeData();

int totalNominal(string total);

string randomQuote();
string date();

struct DataPengeluaran
{
    string nama;
    string kategori;
    string harga;
    string date;
};
struct DataPemasukan
{
    string nominal;
    string kategori;
    string date;
};
vector<DataPengeluaran> dataOut;
vector<DataPemasukan> dataIn;

// Fungsi Utama
int main()
{

    Menu menu;
    firstLogin();
    int input;
    menu.set_xy(21, 12);
    menu.set_color(menu.RED);
    input = menu.Gmenu("Lihat Semua Catatan", "Tambah Catatan Pemasukan", "Tambah Catatan Pengeluaran", "Keluar");
    switch (input)
    {
    case 0:
        all();
        break;
    case 1:
        addIncome();
        break;
    case 2:
        addSpend();
    case 3:
        return 0;
    }
    return 0;
}

// Fungsi Menamapilkan Total nominal
// Arg  : string total -> string total yang ingin ditampilkan (pemasukan/pengeluaran)
int totalNominal(string total)
{
    int nominal = 0;
    if (total == "pemasukan")
    {
        for (auto in : dataIn)
        {

            int harga = stoi(in.nominal);
            nominal += harga;
        }
        return nominal;
    }
    else if (total == "pengeluaran")
    {
        for (auto out : dataOut)
        {
            int harga = stoi(out.harga);
            nominal += harga;
        }
        return nominal;
    }
    return 0;
}

// Fungsi untuk melihat semua catatan
void all()
{
    system("cls");
    xyColor(21, 10, 0, 10);
    cout << "Income: " << totalNominal("pemasukan") << " | Spending: " << totalNominal("pengeluaran") << endl;

    Menu menu;
    int input;
    menu.set_xy(21, 12);
    menu.set_color(menu.GREEN);
    input = menu.Gmenu("Income Details", "Spend Details", "Remove Data", "Back");
    switch (input)
    {
    case 0:
        incomeDetail("viewAll");
        break;
    case 1:
        spendDetail("viewAll");
        break;
    case 2:
        removeData();
    case 3:
        main();
    }
}
// fungsi untuk menampilakan detail dari pemasukan
// arg  : string kategori -> untuk menampilkan data lebih spesifik berdasarkan kategori
void incomeDetail(string kategori)
{
    system("cls");
    xyColor(25, 1, 7, 12);
    cout << " Total Pemasukan Rp." << totalNominal("pemasukan") << " " << endl;

    xyColor(10, 3, 7, 0);
    cout << "---------------------------------------------------------" << endl;
    cout << setw(17) << "Nominal" << setw(25) << "Kategori" << setw(25) << "tanggal" << endl;

    xyColor(10, 5, 7, 0);
    cout << "---------------------------------------------------------" << endl;

    if (kategori == "viewAll")
    {
        xyColor(80, 4, 7, 12);
        cout << " Menu " << endl;
        int input;
        Menu menu;
        menu.clear_screen(false);
        menu.set_xy(80, 6);
        menu.set_color(menu.RED);
        getData("income", "all");
        input = menu.Gmenu("Cari berdasarkan kategori", "Kembali");
        switch (input)
        {
        case 0:
            cout << "Cari berdasarkan Kategori" << endl;
            incomeDetail("category");
            break;
        case 1:
            all();
            break;
        }
    }
    if (kategori == "category")
    {
        xyColor(80, 4, 7, 12);
        cout << " Kategori " << endl;
        getData("income", "all");
        categoryIncome();
    }
    if (kategori == "Investasi")
    {
        xyColor(80, 4, 7, 12);
        cout << " Kategori " << endl;
        getData("income", "Investasi");
        categoryIncome();
    }
    if (kategori == "Sumbangan")
    {
        xyColor(80, 4, 7, 12);
        cout << " Kategori " << endl;
        getData("income", "Sumbangan");
        categoryIncome();
    }
    if (kategori == "Upah")
    {
        xyColor(80, 4, 7, 12);
        cout << " Kategori " << endl;
        getData("income", "Upah");
        categoryIncome();
    }
    if (kategori == "Penjualan")
    {
        xyColor(80, 4, 7, 12);
        cout << " Kategori " << endl;
        getData("income", "Penjualan");
        categoryIncome();
    }
    if (kategori == "Bonus")
    {
        xyColor(80, 4, 7, 12);
        cout << " Kategori " << endl;
        getData("income", "Bonus");
        categoryIncome();
    }
    if (kategori == "Lainnya")
    {
        xyColor(80, 4, 7, 12);
        cout << " Kategori " << endl;
        getData("income", "Lainnya");
        categoryIncome();
    }
}

void spendDetail(string kategori)
{
    system("cls");
    xyColor(30, 1, 7, 12);
    cout << " Total Pengeluaran Rp." << totalNominal("pengeluaran") << " " << endl;

    xyColor(10, 3, 7, 0);
    cout << "----------------------------------------------------------------------" << endl;
    cout << setw(17) << "Nama" << setw(20) << "Nominal" << setw(20) << "Kategori" << setw(20) << "tanggal" << endl;

    xyColor(10, 5, 7, 0);
    cout << "----------------------------------------------------------------------" << endl;

    if (kategori == "viewAll")
    {
        xyColor(90, 4, 7, 12);
        cout << " Menu " << endl;
        int input;
        Menu menu;
        menu.clear_screen(false);
        menu.set_xy(90, 6);
        menu.set_color(menu.RED);
        getData("spend", "all");
        input = menu.Gmenu("Cari berdasarkan kategori", "Kembali");
        switch (input)
        {
        case 0:
            cout << "Cari berdasarkan Kategori" << endl;
            spendDetail("category");
            break;
        case 1:
            all();
            break;
        }
    }
    if (kategori == "category")
    {
        xyColor(90, 4, 7, 12);
        cout << " Kategori " << endl;
        getData("spend", "all");
        categorySpend();
    }
    if (kategori == "Transportasi")
    {
        xyColor(90, 4, 7, 12);
        cout << " Kategori " << endl;
        getData("spend", "Transportasi");
        categorySpend();
    }
    if (kategori == "Tagihan")
    {
        xyColor(90, 4, 7, 12);
        cout << " Kategori " << endl;
        getData("spend", "Tagihan");
        categorySpend();
    }
    if (kategori == "Liburan")
    {
        xyColor(90, 4, 7, 12);
        cout << " Kategori " << endl;
        getData("spend", "Liburan");
        categorySpend();
    }
    if (kategori == "Pakaian")
    {
        xyColor(90, 4, 7, 12);
        cout << " Kategori " << endl;
        getData("spend", "Pakaian");
        categorySpend();
    }
    if (kategori == "Pajak")
    {
        xyColor(90, 4, 7, 12);
        cout << " Kategori " << endl;
        getData("spend", "Pajak");
        categorySpend();
    }
    if (kategori == "Pendidikan")
    {
        xyColor(90, 4, 7, 12);
        cout << " Kategori " << endl;
        getData("spend", "Pendidikan");
        categorySpend();
    }
    if (kategori == "Kesehatan")
    {
        xyColor(90, 4, 7, 12);
        cout << " Kategori " << endl;
        getData("spend", "Kesehatan");
        categorySpend();
    }
    if (kategori == "Konsumsi")
    {
        xyColor(90, 4, 7, 12);
        cout << " Kategori " << endl;
        getData("spend", "Konsumsi");
        categorySpend();
    }
    if (kategori == "Lainnya")
    {
        xyColor(90, 4, 7, 12);
        cout << " Kategori " << endl;
        getData("spend", "Lainnya");
        categorySpend();
    }
}

void categoryIncome()
{
    int input;
    Menu menu;
    menu.clear_screen(false);
    menu.set_xy(80, 6);
    menu.set_color(menu.RED);
    input = menu.Gmenu("Investasi", "Sumbangan", "Upah", "Penjualan", "Bonus", "Lainnya", "Kembali");
    switch (input)
    {
    case 0:
        incomeDetail("Investasi");
        break;
    case 1:
        incomeDetail("Sumbangan");
        break;
    case 2:
        incomeDetail("Upah");
        break;
    case 3:
        incomeDetail("Penjualan");
        break;
    case 4:
        incomeDetail("Bonus");
        break;
    case 5:
        incomeDetail("Lainnya");
        break;
    case 6:
        incomeDetail("viewAll");
        break;
    }
}

void categorySpend()
{
    int input;
    Menu menu;
    menu.clear_screen(false);
    menu.set_xy(90, 6);
    menu.set_color(menu.RED);
    input = menu.Gmenu("Transportasi", "Tagihan", "Liburan", "Pakaian", "Pajak", "Pendidikan", "Kesehatan", "Konsumsi", "Lainnya", "Kembali");
    switch (input)
    {
    case 0:
        spendDetail("Transportasi");
        break;
    case 1:
        spendDetail("Tagihan");
        break;
    case 2:
        spendDetail("Liburan");
        break;
    case 3:
        spendDetail("Pakaian");
        break;
    case 4:
        spendDetail("Pajak");
        break;
    case 5:
        spendDetail("Pendidikan");
        break;
    case 6:
        spendDetail("Kesehatan");
        break;
    case 7:
        spendDetail("Konsumsi");
        break;
    case 8:
        spendDetail("Lainnya");
        break;
    case 9:
        spendDetail("viewAll");
        break;
    }
}

// fungsi untuk menampilkan data income
// arg  : string category -> menampilakan data bedasarkan kategori yang dipilih
void getData(string data, string category)
{

    xyColor(0, 6, 7, 0);
    if (data == "income")
    {
        for (int i = 0; i < dataIn.size(); i++)
        {
            if (category == "all")
            {
                cout << setw(17) << dataIn[i].nominal;
                cout << setw(25) << dataIn[i].kategori;
                cout << setw(25) << dataIn[i].date;
                cout << endl;
            }
            else
            {
                if (category == dataIn[i].kategori)
                {
                    cout << setw(17) << dataIn[i].nominal;
                    cout << setw(25) << dataIn[i].kategori;
                    cout << setw(25) << dataIn[i].date;
                    cout << endl;
                }
            }
        }
    }
    else if (data == "spend")
    {
        for (int i = 0; i < dataOut.size(); i++)
        {
            if (category == "all")
            {
                cout << setw(17) << dataOut[i].nama;
                cout << setw(20) << dataOut[i].harga;
                cout << setw(20) << dataOut[i].kategori;
                cout << setw(20) << dataOut[i].date;
                cout << endl;
            }
            else
            {
                if (category == dataOut[i].kategori)
                {
                    cout << setw(17) << dataOut[i].nama;
                    cout << setw(20) << dataOut[i].harga;
                    cout << setw(20) << dataOut[i].kategori;
                    cout << setw(20) << dataOut[i].date;
                    cout << endl;
                }
            }
        }
    }
}

// Fungsi Tambah Pemasukan
void addIncome()
{
    system("cls");
    string nominal, kategori;
    int inputKategori;

    xyColor(21, 11, 0, 14);
    cout << " Nominal " << endl;

    xyColor(21, 13, 14, 0);
    cin >> nominal;

    xyColor(35, 11, 0, 14);
    cout << " Pilih Kategori " << endl;

    Menu menu;
    menu.clear_screen(false);
    menu.set_xy(35, 13);
    menu.set_color(menu.YELLOW);
    inputKategori = menu.Gmenu("Investasi", "Sumbangan", "Upah", "Penjualan", "Bonus", "Lainnya");
    switch (inputKategori)
    {
    case 0:
        kategori = "Investasi";
        break;
    case 1:
        kategori = "Sumbangan";
        break;
    case 2:
        kategori = "Upah";
        break;
    case 3:
        kategori = "Penjualan";
        break;
    case 4:
        kategori = "Bonus";
        break;
    case 5:
        kategori = "Lainnya";
        break;
    }
    saveIncome(nominal, kategori, date());
    loadingAnimation(30, 21, 20, 14, 14);
    textSuccess(57, 11, 14);
    ulangBaru(57, 13, "addIncome", 14);
}

// Fungsi Tambah Pengeluaran
void addSpend()
{
    system("cls");
    string nama, kategori, harga;
    int inputKategori;

    xyColor(21, 11, 0, 10);
    cout << " Nama " << endl;

    xyColor(21, 13, 10, 0);
    // cin.ignore();
    // getline(cin, nama);
    cin >> nama;

    xyColor(35, 11, 0, 10);
    cout << " Pilih Kategori " << endl;

    Menu menu;
    menu.clear_screen(false);
    menu.set_xy(35, 13);
    menu.set_color(menu.GREEN);

    inputKategori = menu.Gmenu("Transportasi", "Tagihan", "Liburan", "Pakaian", "Pajak", "Pendidikan", "Kesehatan", "Konsumsi", "Lainnya");

    switch (inputKategori)
    {
    case 0:
        kategori = "Transportasi";
        break;
    case 1:
        kategori = "Tagihan";
        break;
    case 2:
        kategori = "Liburan";
        break;
    case 3:
        kategori = "Pakaian";
        break;
    case 4:
        kategori = "Pajak";
        break;
    case 5:
        kategori = "Pendidikan";
        break;
    case 6:
        kategori = "Kesehatan";
        break;
    case 7:
        kategori = "Konsumsi";
        break;
    case 8:
        kategori = "Lainnya";
        break;
    }
    xyColor(60, 11, 0, 10);
    cout << " Harga " << endl;

    xyColor(60, 13, 10, 0);
    cin >> harga;

    saveSpend(nama, kategori, harga, date());
    loadingAnimation(45, 21, 23, 10, 10);
    textSuccess(75, 11, 10);
    ulangBaru(75, 13, "addSpend", 10);
}

// Fungsi Save Pemasukan
// Arg  :   - string nominal -> jumlah jumlah nominal pemasukan
//          - string kategori -> kategori pemasukan
//          - string date -> tanggal waktu save pemasukan
void saveIncome(string nominal, string kategori, string date)
{
    // Push data ke vector
    DataPemasukan temp;
    temp.nominal = nominal;
    temp.kategori = kategori;
    temp.date = date;
    dataIn.push_back(temp);

    ofstream out("dataIncome.txt");
    for (auto in : dataIn)
    {
        out << in.nominal << ' ';
        out << in.kategori << ' ';
        out << in.date << ' ';
        out << '\n';
    }
    out.close();
}

// Fungsi Save Pengeluaran
// Arg  :   - string nama -> nama pengeluaran
//          - string kategori -> kategori pengeluaran
//          - string harga -> nominal pengeluaran
//          - string date -> tanggal waktu save pengeluaran
void saveSpend(string nama, string kategori, string harga, string date)
{
    // Push data ke vector
    dataOut.push_back({nama, kategori, harga, date});
    ofstream out("dataSpend.txt");
    for (auto dataOut : dataOut)
    {
        out << dataOut.nama << ' ';
        out << dataOut.kategori << ' ';
        out << dataOut.harga << ' ';
        out << dataOut.date << ' ';
        out << '\n';
    }
    out.close();
}

// Fungsi Untuk Mengecek Apakah User Ingin Mengulangi
// Arg  : string menu -> untuk ulang ke fungsi pengeluaran/pemasukan/menu
//      : string str -> kalimat yang ingin ditampilkan
void ulang(string menu, string str)
{
    cout << str;
    char ulang;
    cin >> ulang;
    if (ulang == 'y')
    {
        if (menu == "pengeluaran")
        {
            addSpend();
        }
        if (menu == "pemasukan")
        {
            addIncome();
        }
        if (menu == "main")
        {
            main();
        }
    }
    if (ulang != 'y' | ulang != 'n' | ulang == 'n')
    {
        if (menu == "pengeluaran" | menu == "pemasukan")
        {
            main();
        }
        if (menu == "main")
        {
            return;
        }
    }
}

// Fungsi Untuk Mengecek User Apakah Pertama Kali Login
bool first = true;
void firstLogin()
{
    Menu menu;
    if (first == true)
    {
        system("cls");
        xyColor(21, 10, 0, 12);
        cout << "Selamat Datang Di Catat.in" << endl;
        xyColor(21, 17, 0, 12);
        cout << "Guanakan tombol arrow untuk berpindah menu. " << endl;
        first = false;
        loadDataIncome();
        loadDataSpend();
    }
    else
    {
        system("cls");
        xyColor(21, 10, 0, 12);
        cout << "Menu Catat.in" << endl;
        xyColor(21, 17, 0, 12);
        cout << randomQuote() << endl;
    }
}

string randomQuote()
{
    srand(time(NULL));
    string text[4] = {
        "Tidak menghabiskan uang adalah cara terbaik untuk menabung",
        "Jika kamu ingin kaya, pikirkanlah menabung dan menghasilkan",
        "Jangan pernah menghabiskan uang Anda sebelum Anda memilikinya",
        "Dalam berhemat, kamu akan belajar untuk memprioritaskan hal yang lebih penting"};
    int idx = rand() % 4;
    return text[idx];
}

string date()
{
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    string date = to_string(local_time->tm_hour) + ":" + to_string(local_time->tm_min) + "-" + to_string(local_time->tm_mday) + "-" + to_string(1 + local_time->tm_mon) + "-" + to_string(1900 + local_time->tm_year);
    return date;
}

// Fungsi untuk mencari data berdasarkan kategori
// Arg  : string str -> data yang ingin dicari "Pemasukan | Pengeluaran"
void searchKategori(string str)
{
    cout << "Input Kategori : ";
    string kategori;
    cin >> kategori;
    if (str == "Pemasukan")
    {
        for (int i = 0; i < dataIn.size(); i++)
        {
            if (kategori == dataIn[i].kategori)
            {
                cout << dataIn[i].kategori << endl;
                cout << dataIn[i].nominal << endl;
                cout << dataIn[i].date << endl;
            }
        }
    }
    if (str == "Pengeluaran")
    {
        for (int i = 0; i < dataOut.size(); i++)
        {
            if (kategori == dataIn[i].kategori)
            {
                cout << dataOut[i].nama << endl;
                cout << dataOut[i].harga << endl;
                cout << dataOut[i].kategori << endl;
                cout << dataOut[i].date << endl;
            }
        }
    }
}

void loadingAnimation(int panjang, int x, int y, int fc, int bc)
{
    char a = 177, b = 219;
    xyColor(x, y, fc, bc);
    for (int i = 0; i <= panjang; i++)
    {
        cout << b;
        for (int j = 0; j <= 2e7; j++)
            ;
    }
}

// Fungsi untuk mmenampilkan keterangan sukses
// Arg : int x -> posisi x
//       int y -> posisi y
//       int color -> untuk merubah warna text (12 = red; 10 = green; 11 = turquoise; 14 = yellow; 13 = purle)
void textSuccess(int x, int y, int color)
{
    xyColor(x, y, 0, color);
    cout << " Sukses disimpan " << endl;
}

// Fungsi untuk menapilkan piliha ulang
// Arg : int x -> posisi x
//       int y -> posisi y
//       string str -> untuk pindah kemenu mana apa bila user konfirmasi ulang (addIncome/addSpend)
//       int color -> untuk merubah warna text (12 = red; 10 = green; 11 = turquoise; 14 = yellow; 13 = purle)
void ulangBaru(int x, int y, string str, int color)
{
    int input;
    Menu menu;
    menu.clear_screen(false);
    menu.set_xy(x, y);
    menu.set_color(menu.GREEN);
    if (color == 12)
        menu.set_color(menu.RED);
    if (color == 10)
        menu.set_color(menu.GREEN);
    if (color == 11)
        menu.set_color(menu.TURQUOISE);
    if (color == 14)
        menu.set_color(menu.YELLOW);
    if (color == 13)
        menu.set_color(menu.PURPLE);
    input = menu.Gmenu("Ulang", "Kembali");
    switch (input)
    {
    case 0:
        if (str == "addIncome")
        {
            addIncome();
            break;
        }
        if (str == "addSpend")
        {
            addSpend();
            break;
        }
        if (str == "all")
        {
            all();
            break;
        }

    case 1:
        main();
        break;
    }
}

// fungsi untuk membuka file dataIncome.txt yang kemudian akan dimasukan data tersebut ke dalam vector.
// fungsi ini menggunakan liblary fstream.
void loadDataIncome()
{
    // membuka file dataIncome.txt
    ifstream file("dataIncome.txt");
    // apabila file belum ada makan akan dibuat file tersebut
    if (!file)
    {
        ofstream outfile("dataIncome.txt");
        outfile.close();
    }
    string nominal, kategori, tanggal;
    while (file >> nominal >> kategori >> tanggal)
    {
        DataPemasukan temp;
        temp.nominal = nominal;
        temp.kategori = kategori;
        temp.date = tanggal;
        dataIn.push_back(temp);
    }
    file.close();
}

// fungsi untuk membuka file dataOut.txt yang kemudian akan dimasukan data tersebut ke dalam vector.
// fungsi ini menggunakan liblary fstream.
void loadDataSpend()
{
    // membuka file dataSpend.txt
    ifstream file("dataSpend.txt");
    // apabila file belum ada makan akan dibuat file tersebut
    if (!file)
    {
        ofstream outfile("dataSpend.txt");
        outfile.close();
    }
    string nama, kategori, harga, date;
    while (file >> nama >> kategori >> harga >> date)
    {
        DataPengeluaran temp;
        temp.nama = nama;
        temp.kategori = kategori;
        temp.harga = harga;
        temp.date = date;
        dataOut.push_back(temp);
    }
    file.close();
}

// fungsi remove data untuk menghapus file dataIncome.txt, dataSpend.txt dan data vector yang kemudian di regenerate berupa data kosong
void removeData()
{
    remove("dataIncome.txt");
    remove("dataSpend.txt");
    dataIn.clear();
    dataOut.clear();
    loadDataIncome();
    loadDataSpend();
    all();
}
