#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "doublelink_List.cpp"
#include "relasi.cpp"

using namespace std;

int main()
{
    int pil;
    list_departemen Ldepartemen;
    list_pegawai Lpegawai;
    list_relasi Lrelasi;
    CreateDepartemen(Ldepartemen);
    CreatePegawai(Lpegawai);
    CreateListRelasi(Lrelasi);
    infotype_departemen A;
    A.alamat = "asd";
    A.nama_departemen = "dsa";
    infotype_pegawai B;
    B.nama = "asd";
    B.nip = "dsa";
    insertDepartemen(Ldepartemen, alokasiDepartemen(A));
    insertPegawai(Lpegawai, alokasiPegawai(B));
    insertRelasi(Lrelasi, alokasiRelasi(first(Lpegawai), first(Ldepartemen)));
    mulai:
    system("cls");
    cout<<"--------------------------------------"<<endl;
    cout<<"|          Sistem Kepegawaian         |"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"|               ' Menu  '             "<<endl;
    cout<<"| 1. Tambah Pegawai                   "<<endl;
    cout<<"| 2. Tambah Departemen                "<<endl;
    cout<<"| 3. View Daftar List Pegawai         "<<endl;
    cout<<"| 4. View Daftar List Departemen      "<<endl;
    cout<<"| 5. Cari Pegawai                     "<<endl;
    cout<<"| 6. Cari Departemen                  "<<endl;
    cout<<"| 7. Hapus Pegawai                    "<<endl;
    cout<<"| 8. Hapus Departemen                 "<<endl;
    cout<<"| 9. Masukkan Pegawai Ke Departemen    "<<endl;
    cout<<"| 10. Tambahkan Pegawai Ke Sebuah Departemen"<<endl;
    cout<<"| 11. Hapus Pegawai Yang Masuk Ke Sebuah Departemen "<<endl;
    cout<<"| 12. View Departemen Yang Telah Dimasuki Pegawai"<<endl;
    cout<<"| 13. View Departemen Dengan Pegawai Terbanyak"<<endl;
    cout<<"| 14. View Departemen Dengan Pegawai Paling Sedikit "<<endl;
    cout<<"| 15. Keluar Aplikasi                 "<<endl;
    cout<<"-====================================-"<<endl;
    cout<<"Pilihan anda --> ";cin>>pil;cout<<endl;;
    switch(pil){
        case 1:{
            cout<<"Menambah Data Pegawai\n";
            cout<<endl;
            cout<<"Masukkan Nama           : ";cin>>B.nama;
            cout<<"Masukkan NIP            : ";cin>>B.nip;
            insertPegawai(Lpegawai, alokasiPegawai(B));
            cout<<"Data Berhasil Dimasukkan...";getche();
            goto mulai;
        }
        case 2:{
            cout<<"Menambah Data Departemen\n";
            cout<<endl;
            cout<<"Masukkan Nama Departemen : ";cin>>A.nama_departemen;
            cout<<"Masukkan Alamat          : ";cin>>A.alamat;
            insertDepartemen(Ldepartemen, alokasiDepartemen(A));
            cout<<"Data Berhasil Dimasukkan...";getche();
            goto mulai;
        }
        case 3:{
            cout<<"Melihat Data Pegawai\n";
            printPegawai(Lpegawai);getche();
            goto mulai;
        }
        case 4:{
            cout<<"Melihat Data Departemen\n";
            printDepartemen(Ldepartemen);getche();
            goto mulai;
        }
        case 5:{
            cout<<"Mencari Data Pegawai\n";
            cout<<endl;
            cout<<"Masukkan NIP            : ";cin>>B.nip;
            address_pegawai P = findPegawai(Lpegawai, B);
            if(P != NULL){
                cout<<"Nama Pegawai      :"<<info(P).nama<<endl;
                cout<<"NIP Pegawai       :"<<info(P).nip<<endl;
                cout<<endl<<"Back to menu...";getch();
            }
            else{
                cout<<"Data Tidak Ditemukan atau List Kosong...";getch();
            }
            goto mulai;
        }
        case 6:{
            cout<<"Mencari Data Departemen\n";
            cout<<endl;
            cout<<"Masukkan Nama Departemen : ";cin>>A.nama_departemen;
            address_departemen D = findDepartemen(Ldepartemen, A);
            if(D != NULL){
                cout<<"Nama Departemen      :"<<info(D).nama_departemen<<endl;
                cout<<"Alamat Departemen       :"<<info(D).alamat<<endl;
                cout<<endl<<"Back to menu...";getch();
            }
            else{
                cout<<"Data Tidak Ditemukan atau List Kosong...";getch();
            }
            goto mulai;
        }
        case 7:{
            cout<<"Menghapus Data Pegawai\n";
            cout<<endl;
            string a;
            cout<<"Masukkan NIP Pegawai : ";cin>>B.nip;
            address_pegawai P = findPegawai(Lpegawai, B);
            if(P != NULL){
                cout<<"Nama Pegawai      :"<<info(P).nama<<endl;
                cout<<"NIP Pegawai       :"<<info(P).nip<<endl;
                pilyesno:
                cout<<"Anda mau menghapus data ini [y/n]?";cin>>a;
                if(a != "n" and a != "y"){
                    goto pilyesno;
                }
                deletePegawai(Lpegawai, P);
                cout<<endl<<"Data Berhasil Dihapus"<<endl;
                cout<<endl<<"Back to menu...";getch();
            }
            else{
                cout<<"Data Tidak Ditemukan atau List Kosong...";getch();
            }
            goto mulai;
        }
        case 8:{
            cout<<"Menghapus Data Departemen\n";
            cout<<endl;
            string a;
            cout<<"Masukkan Nama Departemen : ";cin>>A.nama_departemen;
            address_departemen D = findDepartemen(Ldepartemen, A);
            if(D != NULL){
                cout<<"Nama Departemen         :"<<info(D).nama_departemen<<endl;
                cout<<"Alamat Departemen       :"<<info(D).alamat<<endl;
                pilyesno:
                cout<<"Anda mau menghapus data ini [y/n]?";cin>>a;
                if(a != "n" and a != "y"){
                    goto pilyesno;
                }
                deleteDepartemen(Ldepartemen, D);
                cout<<endl<<"Data Berhasil Dihapus"<<endl;
                cout<<endl<<"Back to menu...";getch();
            }
            else{
                cout<<"Data Tidak Ditemukan atau List Kosong...";getch();
            }
            goto mulai;
        }
    }
}
