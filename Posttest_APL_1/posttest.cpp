#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

int loginAttempt = 3;

void konversi()
{
    int menu;
    float uang, rupiah, dollar, euro, yen;
    float dollar1, rupiah1, euro1, yen1;
    float euro2, rupiah2, dollar2, yen2;
    float yen3, rupiah3, dollar3, euro3;

    cout<<"---------------Pilihan Menu--------------"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"1. Konversi Rupiah ke (Dollar, Euro, Yen)"<<endl;
    cout<<"2. Konversi Dollar ke (Rupiah, Euro, Yen)"<<endl;
    cout<<"3. Konversi Euro ke (Rupiah, Dollar, Yen)"<<endl;
    cout<<"4. Konversi Yen ke (Rupiah, Dollar, Euro)"<<endl;
    cout<<"5. Keluar"<<endl;
    cout<<endl;
    cout<<"Input Pilihan : "; cin>>menu;
    system("cls");

    if (menu==1)
    {
        cout<<"Masukkan nominal (Rupiah) : Rp. ";cin>>rupiah;
        dollar = rupiah*0.000064;
        euro = rupiah*0.000059;
        yen = rupiah*0.0096;

        cout<<"Rp."<<rupiah<< " = " <<dollar<< " Dollar"<<endl;
        cout<<"Rp."<<rupiah<< " = "<<euro<<" Euro"<<endl;
        cout<<"Rp."<<rupiah<< " = "<<yen<<" Yen"<<endl;
        cout<<endl;
        cout<<"ENTER untuk lanjut...";
        getche();
        system("cls");
        konversi();
    }
    else if (menu==2)
    {
        cout<<"Masukkan nominal (Dollar) : ";cin>>dollar1;
        rupiah1 = dollar1*15700;
        euro1 = dollar1*0.92;
        yen1 = dollar1*150.10;

        cout<<"(USD) "<<dollar1<< " = Rp." <<rupiah1<<endl;
        cout<<"(USD) "<<dollar1<< " = "<<euro1<<" Euro"<<endl;
        cout<<"(USD) "<<dollar1<< " = "<<yen1<<" Yen"<<endl;
        cout<<endl;
        cout<<"ENTER untuk lanjut...";
        getche();
        system("cls");
        konversi();
    }
    else if (menu==3)
    {
        cout<<"Masukkan nominal (Euro) :  ";cin>>euro2;
        rupiah2 = euro2*17000;
        dollar2 = euro2*1.09;
        yen2 = euro2*162.93;

        cout<<"(EU) "<<euro2<< " = Rp." <<rupiah2<<endl;
        cout<<"(EU) "<<euro2<< " = "<<dollar2<<" Dollar"<<endl;
        cout<<"(EU) "<<euro2<< " = "<<yen2<<" Yen"<<endl;
        cout<<endl;  
        cout<<"ENTER untuk lanjut...";
        getche();
        system("cls");  
        konversi();
    }
    else if (menu==4)
    {
        cout<<"Masukkan nominal (Yen) :  ";cin>>yen3;
        rupiah3 = yen3*104.61;
        dollar3 = yen3*0.0067;
        euro3 = yen3*0.0061;

        cout<<yen3<< " Yen = Rp." <<rupiah3<<endl;
        cout<<yen3<< " Yen = "<<dollar3<<" Dollar"<<endl;
        cout<<yen3<< " Yen = "<<euro3<<" Euro"<<endl;
        cout<<endl;
        cout<<"ENTER untuk lanjut...";
        getche();
        system("cls");
        konversi();
    }
    else if (menu==5)
    {
        cout<<"bye bye ...."<<endl;
        return;
    }
}


bool isLoggedIn()
{
    string username, password;
    string un,pw;

    cout<<"Username       : "; cin>>username;
    cout<<"Password (NIM) : "; cin>>password;

    if(password.length() !=10)
    {
        cout<<"Harap input NIM dengan benar."<<endl;
        return false;
    }

    ifstream read(username + ".txt");
    if (read.is_open())
        getline(read,un);
        getline(read,pw);
        read.close();
        if(un == username & pw == password)
        {
            return true;
        }
    return false;
}

int main ()
{   
    if (loginAttempt == 0) {
        cout << "Anda telah 3x gagal. Harap coba kembali dalam beberapa saat." << endl;
        return 0;
    }

    int pilihan;

    cout<<endl;
    cout<<"------------"<<endl;
    cout<<"Pilihan Menu"<<endl;
    cout<<"------------"<<endl;
    cout<<"1. Register"<<endl;
    cout<<"2. Login"<<endl;
    cout<<endl;
    cout<<"Pilih : ";
    cin>>pilihan;
    system("cls");

    if(pilihan == 1)
    {
        string username, password;

        cout<<"Buat username anda       : ";
        cin>>username;
        cout<<"Buat password anda (NIM) : ";
        cin>>password;

        if(password.length() !=10)
        {
        cout<<"Harap input NIM dengan benar."<<endl;
        return false;
        }

        ofstream file(username + ".txt");
        if (file.is_open())
        {
            file<<username<<endl<<password;
            file.close();
            cout<<endl;
            cout<<"Hello "<< username << "!" <<" Selamat Anda berhasil Register. Silahkan Login ke akun Anda."<<endl;
            cout<<endl;
            cout <<"ENTER untuk lanjut...";
            getche();
            main();
        }
        else
        {
            cout<<"Gagal memuat data."<<endl;
        }
    }

    else if (pilihan == 2)
    {
        bool status = isLoggedIn();
        if(!status)
        {   
            loginAttempt--;

            cout<<endl;
            cout<<"Invalid Login."<<endl;    
            cout <<"ENTER untuk lanjut...";
            getche(); 
            system("cls"); 
            main();
        }
        else 
        {
            cout<<endl;
            cout<<"Login Berhasil!"<<endl;
            cout <<"ENTER untuk lanjut...";
            getche();
            system("cls");
            cout<<endl;
            konversi();
        }
    }
}