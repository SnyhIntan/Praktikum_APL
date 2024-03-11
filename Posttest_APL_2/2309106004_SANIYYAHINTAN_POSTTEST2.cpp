#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

string daftar_nomor_telepon[50][2];
int banyak_data = 0;
int loginAttempt = 3;

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

void read_nomor_hp()
{
    system("cls");

    if (banyak_data > 0)
    {
        cout<<"+----------------------------+"<<endl;
        cout<<"|        Nomor Telepon       |"<<endl;
        cout<<"+----------------------------+"<<endl;
        for (int i = 0; i < banyak_data; i++)
        {
            cout << i+1 << ". " << daftar_nomor_telepon[i][0] << " : " << daftar_nomor_telepon[i][1] << endl;
        }
    }
    else
    {
        cout << "Daftar Kontak Telepon Kosong." << endl;
        return;
    }
}

void create_nomor_hp()
{
    string ulang;
    do
    {
        if (banyak_data < 50)
        {
            read_nomor_hp();
            cout << endl;
            string nama, nomor;
            cin.ignore();
            cout << "Masukkan nama kontak  : ";
            getline(cin, nama);
            cout << "Masukkan nomor kontak : ";
            getline(cin, nomor);
            cout << endl;
            daftar_nomor_telepon[banyak_data][0] = nama;
            daftar_nomor_telepon[banyak_data][1] = nomor;
            banyak_data++;
            cout << "Nomor telepon berhasil ditambahkan." << endl;

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

void update_nomor_telepon()
{
    string ulang;
    do
    {
        int indexs;

        system("cls");
        read_nomor_hp();
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
            cout << "Edit nama\t   : ";
            getline(cin, daftar_nomor_telepon[indexs-1][0]);
            fflush(stdin);
            cout << "Edit nomor telepon : ";
            getline(cin, daftar_nomor_telepon[indexs-1][1]);
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

void delete_nomor_telepon()
{
    string ulang;
    do
    {
        int indexs;
        int indexs_asli;

        system("cls");
        read_nomor_hp();
        if (banyak_data <= 0)
        {
            cout<<endl;
            cout << "ENTER untuk lanjut...";
            getche();
            return;
        }

        cout << endl;
        cout << "Pilih indeks yang ingin dihapus : ";
        cin >> indexs;

        if (indexs >= 0 && indexs <= banyak_data)
        {
            indexs_asli = indexs - 1;
            daftar_nomor_telepon[indexs_asli][0] = daftar_nomor_telepon[indexs_asli + 1][0];
            daftar_nomor_telepon[indexs_asli][1] = daftar_nomor_telepon[indexs_asli + 1][1];
            banyak_data--;
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

void search_nomor_telepon()
{
    string ulang;
    do
    {
        string nama;
        bool kondisi = false;
        system("cls");
        // read_nomor_hp();
        cout<<endl;
        cout << "Masukkan nama yang ingin di cari : ";
        cin.ignore();
        getline(cin, nama);
        for (int i = 0; i < banyak_data; i++)
        {
            if (daftar_nomor_telepon[i][0] == nama)
            {
                cout << daftar_nomor_telepon[i][0] << " : " << daftar_nomor_telepon[i][1] << endl;
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

int crud()
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
            create_nomor_hp();
            if (ulang != "y")
            {
                crud();
            }

        case 2:
            read_nomor_hp();
            cout << endl;
            cout << "ENTER untuk lanjut...";
            getche();
            crud();

        case 3:
            update_nomor_telepon();
            if (ulang != "y")
            {
                crud();
            }

        case 4:
            delete_nomor_telepon();
            if (ulang != "y")
            {
                crud();
            }

        case 5:
            search_nomor_telepon();
            if (ulang != "y")
            {
                crud();
            }

        case 6:
            system("cls");
            cout << endl;
            cout << "Bye bye...." << endl;
            cout << endl;
            break;

        default:
            cout << "Pilihan tidak valid." << endl;
            cout << endl;
            cout << "ENTER untuk lanjut...";
            getche();
        }
    } while (pilihan != 6);
}

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
            crud();
        }
    }
}
