#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "doublelink_List.cpp"

using namespace std;

int main()
{
    int pil;
    list_departemen LD;
    list_pegawai LP;
    list_relasi LR;
    CreateDepartemen(LD);
    CreatePegawai(LP);
    infotype_departemen A;
    A.alamat = "asd";
    A.nama_departemen = "dsa";
    insertDepartemen(LD, alokasiDepartemen(A));
    insertDepartemen(LD, alokasiDepartemen(A));
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
    cout<<"| 9. Masukkan Pegawai Ke Departeme    "<<endl;
    cout<<"| 10. Tambahkan Pegawai Ke Sebuah Departemen"<<endl;
    cout<<"| 11. Hapus Pegawai Yang Masuk Ke Sebuah Departemen "<<endl;
    cout<<"| 12. View Departemen Yang Telah Dimasuki Pegawai"<<endl;
    cout<<"| 13. View Departemen Dengan Pegawai Terbanyak"<<endl;
    cout<<"| 14. View Departemen Dengan Pegawai Paling Sedikit "<<endl;
    cout<<"| 15. Keluar Aplikasi                 "<<endl;
    cout<<"-====================================-"<<endl;
    cout<<"Pilihan anda --> ";cin>>pil;
    switch(pil){
        case 1:{
            printDepartemen1(LD);
        }
    }
}
