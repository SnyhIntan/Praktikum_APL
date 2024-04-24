#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

const int maksimal = 50;

struct Nama {
    string depan;
    string belakang;
};

struct Nomortelepon {
    string nomor;
};

struct kontak {
    // penggunaan nested struct dan pointer
    Nama *nama; 
    Nomortelepon *telepon;
};

// penggunaan array of struct
kontak daftar_nomor_telepon[maksimal];
int banyak_data = 0;
int loginAttempt = 3;


// Prosedur dan penggunaan parameter deference
void read_nomor_hp(kontak *daftar_nomor_telepon, int banyak_data)
{
    system("cls");

    if (banyak_data > 0)
    {
        cout<<"+----------------------------+"<<endl;
        cout<<"|        Nomor Telepon       |"<<endl;
        cout<<"+----------------------------+"<<endl;
        for (int i = 0; i < banyak_data; i++)
        {
            cout << i+1 << ". " << (*daftar_nomor_telepon[i].nama).depan <<" "<< (*daftar_nomor_telepon[i].nama).belakang << " : " << (*daftar_nomor_telepon[i].telepon).nomor << endl;
        }
    }
    else
    {
        cout << "Daftar Kontak Telepon Kosong." << endl;
        return;
    }
}

// Prosedur dan penggunaan parameter deference
void create_nomor_hp(kontak *daftar_nomor_telepon, int *banyak_data)
{
    string ulang;
    do
    {
        if (*banyak_data < maksimal)
        {
            read_nomor_hp(daftar_nomor_telepon, *banyak_data);
            cout << endl;
            string depan, belakang, nomor;
            cin.ignore();
            cout << "Masukkan nama depan kontak     : ";
            getline(cin, depan);
            cout << "Masukkan nama belakang kontak  : ";
            getline(cin, belakang);
            cout << "Masukkan nomor kontak          : ";
            getline(cin, nomor);
            cout << endl;

            if(depan.empty() || nomor.empty()){
                cout<<"Nama depan dan nomor telepon wajib diisi. Kontak tidak ditambahkan."<<endl;
            }else{
                daftar_nomor_telepon[*banyak_data].nama = new Nama;
                daftar_nomor_telepon[*banyak_data].telepon = new Nomortelepon;

                daftar_nomor_telepon[*banyak_data].nama->depan = depan;
                daftar_nomor_telepon[*banyak_data].nama->belakang = belakang;
                daftar_nomor_telepon[*banyak_data].telepon->nomor = nomor;
                (*banyak_data)++;
                cout << "Nomor telepon berhasil ditambahkan." << endl;
            }
            
            cout << endl;
            cout << "Ulangi (y/t) : ";
            cin >> ulang;
        }
        else
        {
            cout << "<------Memori Penuh------>" << endl;
            cout << "Isi t untuk kembali : " << endl;
            cin >> ulang;
        }

    } while (ulang == "y");
}

// Prosedur dan penggunaan parameter deference
void update_nomor_telepon(kontak *daftar_nomor_telepon, int banyak_data)
{
    string ulang;
    do
    {
        int indexs;
        string namabarudepan, namabarubelakang, nomorbaru;

        system("cls");
        read_nomor_hp(daftar_nomor_telepon, banyak_data);
        if (banyak_data <= 0)
        {
            cout<<endl;
            cout << "ENTER untuk lanjut...";
            getche();
            return;
        }

        cout << endl;
        cout << "Pilih indeks yang ingin diubah : ";
        cin >> indexs;
        if (indexs >= 0 && indexs <= banyak_data)
        {
            cin.ignore();
            cout<<endl;
            cout << "Edit nama depan       : ";
            getline(cin,namabarudepan);
            fflush(stdin);
            if(!namabarudepan.empty()){
                daftar_nomor_telepon[indexs-1].nama->depan = namabarudepan;
            }

            cout << "Edit nama belakang    : ";
            getline(cin, namabarubelakang);
            fflush(stdin);
            if(!namabarubelakang.empty()){
                daftar_nomor_telepon[indexs-1].nama->belakang = namabarubelakang;
            }

            cout << "Edit nomor telepon    : ";
            getline(cin,nomorbaru);
            if(!nomorbaru.empty())
            {
                daftar_nomor_telepon[indexs-1].telepon->nomor = nomorbaru;
            }
            cout<<endl;
            cout << "Kontak berhasil diubah." << endl;
        }
        else
        {
            cout << "Indeks tidak ditemukan." << endl;
            cout<<endl;
            cout << "ENTER untuk lanjut...";
            getche();
            return;
        }

        cout << endl;
        cout << "Ulangi (y/t) : ";
        cin >> ulang;

    } while (ulang == "y");
}

// Prosedur dan penggunaan parameter deference
void delete_nomor_telepon(kontak *daftar_nomor_telepon, int *banyak_data)
{
    string ulang;
    do
    {
        int indexs;
        int indexs_asli;

        system("cls");
        read_nomor_hp(daftar_nomor_telepon, *banyak_data);
        if (*banyak_data <= 0)
        {
            cout<<endl;
            cout << "ENTER untuk lanjut...";
            getche();
            return;
        }

        cout << endl;
        cout << "Pilih indeks yang ingin dihapus : ";
        cin >> indexs;

        if (indexs >= 1 && indexs <= *banyak_data) 
        {
            delete daftar_nomor_telepon[indexs-1].nama;
            delete daftar_nomor_telepon[indexs-1].telepon;

            for (int i = indexs - 1; i < *banyak_data - 1; i++) {
                daftar_nomor_telepon[i] = daftar_nomor_telepon[i + 1];
            }
            (*banyak_data)--;
            cout << "Kontak berhasil dihapus." << endl;
        }
        else
        {
            cout << "Indeks tidak ditemukan." << endl;
            cout<<endl;
            cout << "ENTER untuk lanjut...";
            getche();
            return;
        }
        
        cout << endl;
        cout << "Ulangi (y/t) : ";
        cin >> ulang;

    } while (ulang == "y");
}

void bubbleSortDescending(kontak *daftar_nomor_telepon, int banyak_data) {
    for (int i = 0; i < banyak_data - 1; i++) {
        for (int j = 0; j < banyak_data - i - 1; j++) {
            if (daftar_nomor_telepon[j].nama->depan < daftar_nomor_telepon[j + 1].nama->depan) {
                swap(daftar_nomor_telepon[j], daftar_nomor_telepon[j + 1]);
            }
        }
    }
}

int partition(kontak *daftar_nomor_telepon, int low, int high) {
    string pivot = daftar_nomor_telepon[high].telepon->nomor;
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (daftar_nomor_telepon[j].telepon->nomor < pivot) {
            i++;
            swap(daftar_nomor_telepon[i], daftar_nomor_telepon[j]);
        }
    }
    swap(daftar_nomor_telepon[i + 1], daftar_nomor_telepon[high]);
    return (i + 1);
}

void quickSortAscending(kontak *daftar_nomor_telepon, int low, int high) {
    if (low < high) {
        int pi = partition(daftar_nomor_telepon, low, high);
        quickSortAscending(daftar_nomor_telepon, low, pi - 1);
        quickSortAscending(daftar_nomor_telepon, pi + 1, high);
    }
}

void insertionSortAscending(kontak *daftar_nomor_telepon, int banyak_data) {
    for (int i = 1; i < banyak_data; i++) {
        kontak key = daftar_nomor_telepon[i];
        int j = i - 1;
        while (j >= 0 && daftar_nomor_telepon[j].nama->depan > key.nama->depan) {
            daftar_nomor_telepon[j + 1] = daftar_nomor_telepon[j];
            j = j - 1;
        }
        daftar_nomor_telepon[j + 1] = key;
    }
}

int binarySearchAscending(kontak *daftar_nomor_telepon, int left, int right, string nomor) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (daftar_nomor_telepon[mid].telepon->nomor == nomor)
            return mid + 1;
        if (daftar_nomor_telepon[mid].telepon->nomor < nomor)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int sequentialSearchDescending(kontak *daftar_nomor_telepon, int banyak_data, string nama) {
    for (int i = 0; i < banyak_data; i++) {
        if (daftar_nomor_telepon[i].nama->depan == nama || daftar_nomor_telepon[i].nama->belakang == nama) {
            return i + 1;
        }
    }
    return -1;
}


// Fungsi
int crud(kontak *daftar_nomor_telepon, int *banyak_data)
{
    string ulang;
    int pilihan;
    do
    {
        system("cls");
        cout << "+----------------------------+" << endl;
        cout<<  "|           MENU             |"<< endl;
        cout << "+----------------------------+" << endl;
        cout << "| 1. Create Nomor Telepon    |" << endl;
        cout << "| 2. Read Nomor Telepon      |" << endl;
        cout << "| 3. Update Nomor Telepon    |" << endl;
        cout << "| 4. Delete Nomor Telepon    |" << endl;
        cout << "| 5. Sorting Nomor Telepon   |" << endl;
        cout << "| 6. Searching Nomor Telepon |" << endl;
        cout << "| 7. Keluar                  |"<< endl;
        cout << "+----------------------------+" << endl;
        cout << endl;

        cout << "Pilih Menu : ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                create_nomor_hp(daftar_nomor_telepon, banyak_data);
                break;

            case 2:
                read_nomor_hp(daftar_nomor_telepon, *banyak_data);
                cout << endl;
                cout << "ENTER untuk lanjut...";
                getche();
                break;

            case 3:
                update_nomor_telepon(daftar_nomor_telepon, *banyak_data);
                break;

            case 4:
                delete_nomor_telepon(daftar_nomor_telepon, banyak_data);
                break;

            case 5:
                int sort_menu;
                do {

                    system("cls");

                    cout << "+--------------------------+" << endl;
                    cout << "|       Sort Options       |" << endl;
                    cout << "+--------------------------+" << endl;
                    cout << "| 1. Bubble Sort           |" << endl;
                    cout << "| 2. Quick Sort            |" << endl;
                    cout << "| 3. Insertion Sort        |" << endl;
                    cout << "+--------------------------+" << endl;
                    cout << endl;
                    cout << "Pilih metode sorting: ";
                    cin >> sort_menu;

                    // Memilih metode sorting sesuai dengan pilihan pengguna
                    switch (sort_menu) {
                        case 1:
                            bubbleSortDescending(daftar_nomor_telepon, *banyak_data);
                            read_nomor_hp(daftar_nomor_telepon, *banyak_data);
                            cout << "\nMetode sorting huruf secara descending menggunakan Bubble Sort." << endl;
                            break;
                        case 2:
                            quickSortAscending(daftar_nomor_telepon, 0, *banyak_data - 1);
                            read_nomor_hp(daftar_nomor_telepon, *banyak_data);
                            cout << "\nMetode sorting angka secara ascending menggunakan Quick Sort." << endl;
                            break;
                        case 3:
                            insertionSortAscending(daftar_nomor_telepon, *banyak_data);
                            read_nomor_hp(daftar_nomor_telepon, *banyak_data);
                            cout << "\nMetode bebas. Dimana sorting huruf secara ascending menggunakan insertion Sort." << endl;
                            break;
                        default:
                            cout << "Pilihan tidak valid." << endl;
                            break;
                    }
                    cout << endl;
                    cout << "Ulangi (y/t) : ";
                    cin >> ulang;

                } while (ulang == "y");
                crud(daftar_nomor_telepon,banyak_data);
                break;

            case 6:
                int search_menu;
                do {
                    int search_menu;

                    system("cls");

                    cout << "+--------------------------+" << endl;
                    cout << "|      Search Options      |" << endl;
                    cout << "+--------------------------+" << endl;
                    cout << "| 1. Binary Search         |" << endl;
                    cout << "| 2. Sequential Search     |" << endl;
                    cout << "+--------------------------+" << endl;
                    cout << endl;
                    cout << "Pilih metode searching: ";
                    cin >> search_menu;

                    // Memilih metode searching sesuai dengan pilihan pengguna
                    switch (search_menu) {
                        case 1: {
                            string nomor_cari;
                            quickSortAscending(daftar_nomor_telepon, 0, *banyak_data - 1);
                            read_nomor_hp(daftar_nomor_telepon, *banyak_data);
                            cout << endl;
                            cout << "Masukkan nomor telepon yang ingin dicari: ";
                            cin >> nomor_cari;
                            int result_binary = binarySearchAscending(daftar_nomor_telepon, 0, *banyak_data - 1, nomor_cari);
                            if (result_binary != -1)
                                cout << "Nomor telepon ditemukan pada indeks ke-" << result_binary << endl;
                            else
                                cout << "Nomor telepon tidak ditemukan." << endl;
                            break;
                        }
                        case 2: {
                            string nama_cari;
                            bubbleSortDescending(daftar_nomor_telepon, *banyak_data);
                            read_nomor_hp(daftar_nomor_telepon, *banyak_data);
                            cout << "\nMasukkan nama yang ingin dicari: ";
                            cin.ignore();
                            getline(cin, nama_cari);
                            int result_sequential = sequentialSearchDescending(daftar_nomor_telepon, *banyak_data, nama_cari);
                            if (result_sequential != -1)
                                cout << "Nama ditemukan pada indeks ke- " << result_sequential << endl;
                            else
                                cout << "Nama tidak ditemukan." << endl;
                            break;
                        }
                        default:
                            cout << "Pilihan tidak valid." << endl;
                            break;
                    }
                    cout << endl;
                    cout << "Ulangi (y/t) : ";
                    cin >> ulang;

                } while (ulang == "y");
                crud(daftar_nomor_telepon,banyak_data);
                break;

            case 7:
                system("cls");
                cout << endl;
                cout << "Bye bye...." << endl;
                cout << endl;
                return 0;

            default:
                cout << "Pilihan tidak valid." << endl;
                getche();
                break;
        }
    } while (pilihan != 6);
}

// fungsi
bool isLoggedIn()       
{
    string username, password;
    string un, pw;

    cout << "Username       : ";
    cin >> username;
    cout << "Password (NIM) : ";
    cin >> password;

    ifstream read(username + ".txt");
    if (read.is_open())
        getline(read, un);
    getline(read, pw);
    read.close();
    if (un == username & pw == password)
    {
        return true;
    }
    return false;
}

// Fungsi
int main()
{
    if (loginAttempt == 0)
    {
        cout << "Anda telah 3x gagal. Harap coba kembali dalam beberapa saat..." << endl;
        cout << endl;
        return 0;
    }

    int pilihan;

    system("cls");
    cout << endl;
    cout << "+--------------+" << endl;
    cout << "| Pilihan Menu |" << endl;
    cout << "+--------------+" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << endl;
    cout << "Pilih : ";
    cin >> pilihan;
    system("cls");

    if (pilihan == 1)
    {
        string username, password;

        cout << "Buat username anda      : ";
        cin >> username;
        cout << "Buat password anda (NIM): ";
        cin >> password;

        if(password.length() !=10)
        {
            cout<<"Harap input NIM dengan benar."<<endl;
            cout << "ENTER untuk lanjut...";
            getche();
            main ();
            return false;
        }

        ofstream file(username + ".txt");
        if (file.is_open())
        {
            file << username << endl
                 << password;
            file.close();
            cout << endl;
            cout << "Hello " << username << "!"
                 << " Selamat Anda berhasil Register. Silahkan Login ke akun Anda." << endl;
            cout << endl;
            cout << "ENTER untuk lanjut...";
            getche();
            system("cls");
            main();
        }
        else
        {
            cout << "Gagal memuat data." << endl;
        }
    }

    else if (pilihan == 2)
    {
        bool status = isLoggedIn();
        if (!status)
        {
            loginAttempt--;

            cout << endl;
            cout << "Invalid Login." << endl;
            cout << "ENTER untuk lanjut...";
            getche();
            system("cls");
            main();
        }
        else
        {
            cout << endl;
            cout << "Login Berhasil!" << endl;
            cout<<endl;
            cout << "ENTER untuk lanjut...";
            getche();
            system("cls");
            cout << endl;
            // penggunaan parameter address-of
            crud(daftar_nomor_telepon, &banyak_data);
        }
    }
}
