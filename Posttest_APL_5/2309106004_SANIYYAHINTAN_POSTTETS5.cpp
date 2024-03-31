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

// Prosedur
void search_nomor_telepon(kontak *daftar_nomor_telepon, int banyak_data)
{
    string ulang;
    do
    {
        string nama;
        bool kondisi = false;
        system("cls");
        read_nomor_hp(daftar_nomor_telepon, banyak_data);
        cout<<endl;
        cout << "Masukkan nama depan/belakang yang ingin di cari : ";
        cin.ignore();
        getline(cin, nama);
        for (int i = 0; i < banyak_data; i++)
        {
            if (daftar_nomor_telepon[i].nama->depan == nama || daftar_nomor_telepon[i].nama->belakang == nama )
            {
                cout << daftar_nomor_telepon[i].nama->depan <<" "<< daftar_nomor_telepon[i].nama->belakang << " : " << daftar_nomor_telepon[i].telepon->nomor<< endl;
                kondisi = true;
            }
        }
        if(!kondisi)
        {
            cout<<"Nama kontak tidak ditemukan."<<endl;
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

// Fungsi
int crud(kontak *daftar_nomor_telepon, int *banyak_data)
{
    string ulang;
    int pilihan;
    do
    {
        system("cls");
        cout << "+--------------------------+" << endl;
        cout<<  "|           MENU           |"<< endl;
        cout << "+--------------------------+" << endl;
        cout << "| 1. Create Nomor Telepon  |" << endl;
        cout << "| 2. Read Nomor Telepon    |" << endl;
        cout << "| 3. Update Nomor Telepon  |" << endl;
        cout << "| 4. Delete Nomor Telepon  |" << endl;
        cout << "| 5. Search Nomor Telepon  |" << endl;
        cout << "| 6. Keluar                |"<< endl;
        cout << "+--------------------------+" << endl;
        cout << endl;

        cout << "Pilih Menu : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            create_nomor_hp(daftar_nomor_telepon, banyak_data);
            break;
            // Rekursif

        case 2:
            read_nomor_hp(daftar_nomor_telepon, *banyak_data);
            cout << endl;
            cout << "ENTER untuk lanjut...";
            getche();
            crud(daftar_nomor_telepon, banyak_data);
            // Rekursif

        case 3:
            update_nomor_telepon(daftar_nomor_telepon, *banyak_data);
            break;
            // Rekursif

        case 4:
            delete_nomor_telepon(daftar_nomor_telepon, banyak_data);
            break;
            // Rekursif

        case 5:
            search_nomor_telepon(daftar_nomor_telepon, *banyak_data);
            break;
            // Rekursif

        case 6:
            system("cls");
            cout << endl;
            cout << "Bye bye...." << endl;
            cout << endl;
            break;

        default:
            cout << "Pilihan tidak valid." << endl;
            getche();
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
