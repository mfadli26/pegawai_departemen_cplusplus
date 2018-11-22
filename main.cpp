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
    infotype_pegawai B;
    mulai:
    system("cls");
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"|                 Sistem Kepegawaian                 |"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"|                     ' Menu  '                      |"<<endl;
    cout<<"| 1. Tambah Pegawai                                  |"<<endl;
    cout<<"| 2. Tambah Departemen                               |"<<endl;
    cout<<"| 3. View Daftar List Pegawai                        |"<<endl;
    cout<<"| 4. View Daftar List Departemen                     |"<<endl;
    cout<<"| 5. Cari Pegawai                                    |"<<endl;
    cout<<"| 6. Cari Departemen                                 |"<<endl;
    cout<<"| 7. Hapus Pegawai                                   |"<<endl;
    cout<<"| 8. Hapus Departemen                                |"<<endl;
    cout<<"| 9. Masukkan Pegawai Ke Departemen                  |"<<endl;
    cout<<"| 10. Menambah Pegawai Di Departemen                 |"<<endl;
    cout<<"| 11. Hapus Departemen Di Seorang Pegawai            |"<<endl;
    cout<<"| 12. Hapus Pegawai Yang Masuk Ke Sebuah Departemen  |"<<endl;
    cout<<"| 13. View Departemen Yang Telah Dimasuki Pegawai    |"<<endl;
    cout<<"| 14. View Pegawai Yang Bekerja Di Departemen        |"<<endl;
    cout<<"| 15. View Departemen Dengan Pegawai Terbanyak       |"<<endl;
    cout<<"| 16. View Departemen Dengan Pegawai Paling Sedikit  |"<<endl;
    cout<<"| 17. Keluar Aplikasi                                |"<<endl;
    cout<<"-===================================================-"<<endl;
    cout<<"Pilihan anda --> ";cin>>pil;
    system("cls");
    switch(pil){
        case 1:{
            cout<<"Menambah Data Pegawai\n";
            cout<<endl;
            cout<<"Masukkan Nama           : ";cin>>B.nama;
            cout<<"Masukkan NIP            : ";cin>>B.nip;
            address_pegawai P = findPegawai(Lpegawai, B);
            if(P != NULL){
                cout<<endl<<"NIP telah digunakan...";getch();
                goto mulai;
            }
            insertPegawai(Lpegawai, alokasiPegawai(B));
            cout<<"Data Berhasil Dimasukkan...";getche();
            goto mulai;
        }
        case 2:{
            cout<<"Menambah Data Departemen\n";
            cout<<endl;
            cout<<"Masukkan Nama Departemen : ";cin>>A.nama_departemen;
            cout<<"Masukkan Alamat          : ";cin>>A.alamat;
            address_departemen D = findDepartemen(Ldepartemen, A);
            if(D != NULL){
                cout<<endl<<"Nama telah digunakan...";getch();
                goto mulai;
            }
            insertDepartemen(Ldepartemen, alokasiDepartemen(A));
            cout<<"Data Berhasil Dimasukkan...";getche();
            goto mulai;
        }
        case 3:{
            cout<<"Melihat Data Pegawai\n";
            printPegawai(Lpegawai);
            cout<<endl<<"Back to menu...";getche();
            goto mulai;
        }
        case 4:{
            cout<<"Melihat Data Departemen\n";
            printDepartemen(Ldepartemen);
            cout<<endl<<"Back to menu...";getche();
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
                cout<<"Anda mau menghapus data ini [y/n] ?";cin>>a;
                if(a != "n" and a != "y"){
                    goto pilyesno;
                }
                else if(a == "y"){
                    deleteSemuaRelasiPegawai(Lrelasi, P);
                    deletePegawai(Lpegawai, P);
                    cout<<endl<<"Data Berhasil Dihapus"<<endl;
                }
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
                pilyesno2:
                cout<<"Anda mau menghapus data ini [y/n]?";cin>>a;
                if(a != "n" and a != "y"){
                    goto pilyesno2;
                }
                else if(a == "y"){
                    deleteSemuaRelasiDepartemen(Lrelasi, D);
                    deleteDepartemen(Ldepartemen, D);
                    cout<<endl<<"Data Berhasil Dihapus"<<endl;
                }
                cout<<endl<<"Back to menu...";getch();
            }
            else{
                cout<<"Data Tidak Ditemukan atau List Kosong...";getch();
            }
            goto mulai;
        }
        case 9:{
            cout<<"Masukkan Pegawai Ke Departemen\n";
            cout<<endl;
            printPegawai(Lpegawai);
            string a;
            cout<<endl<<"Pegawai mana yang anda pilih (NIP)? : ";cin>>B.nip;
            address_pegawai P = findPegawai(Lpegawai, B);
            if(P != NULL){
                system("cls");
                cout<<endl<<"Pegawai yang telah dipilih"<<endl<<endl;
                cout<<"Nama Pegawai         :"<<info(P).nama<<endl;
                cout<<"NIP Pegawai          :"<<info(P).nip<<endl;
                cout<<endl<<"Menampilkan Departemen yang ada...";getch();cout<<endl;
                printDepartemen(Ldepartemen);
                cout<<endl<<"Departemen mana yang akan dipilih (Nama)? ";cin>>A.nama_departemen;
                    address_departemen D = findDepartemen(Ldepartemen, A);
                    if(D != NULL){
                        cout<<endl<<"Nama Departemen         :"<<info(D).nama_departemen<<endl;
                        cout<<"Alamat Departemen       :"<<info(D).alamat<<endl;
                        pilyesno9:
                        cout<<endl<<"Anda yakin data ini [y/n] ? ";cin>>a;
                        if(a != "n" and a != "y"){
                            goto pilyesno9;
                        }
                        else if(a == "y"){
                            if(findRelasi(Lrelasi, P, D)){
                                cout<<"Pegawai Telah Bekerja Di Departemen...";getch();
                                goto mulai;
                            }
                            insertRelasi(Lrelasi, alokasiRelasi(P, D));
                            cout<<"Hubungan antar Pegawai dan Department berhasil ditambahkan :)"<<endl;
                        }
                        cout<<endl<<"Back to menu...";getch();
                    }
                    else{
                        cout<<"Data Tidak Ditemukan atau List Kosong...";getch();
                    }
            }
            else{
                cout<<"Data Tidak Ditemukan atau List Kosong...";getch();
            }
            goto mulai;
        }
        case 10:{
            cout<<"Menambah Pegawai Di Departemen\n";
            cout<<endl;
            printDepartemen(Ldepartemen);
            string a;
            cout<<endl<<"Departemen mana yang anda pilih (Nama)? : ";cin>>A.nama_departemen;
            address_departemen D = findDepartemen(Ldepartemen, A);
            if(D != NULL){
                system("cls");
                cout<<endl<<"Departemen yang telah dipilih"<<endl<<endl;
                cout<<"Nama Departemen         :"<<info(D).nama_departemen<<endl;
                cout<<"Alamat Departemen       :"<<info(D).alamat<<endl;
                cout<<endl<<"Menampilkan Pegawai yang terdaftar...";getch();cout<<endl;
                printPegawai(Lpegawai);
                cout<<endl<<"Pegawai mana yang akan dipilih (NIP)? ";cin>>B.nip;
                    address_pegawai P = findPegawai(Lpegawai, B);
                    if(P != NULL){
                        cout<<endl<<"Nama Pegawai         :"<<info(P).nama<<endl;
                        cout<<"NIP Pegawai          :"<<info(P).nip<<endl;
                        pilyesno10:
                        cout<<endl<<"Anda yakin data ini [y/n] ? ";cin>>a;
                        if(a != "n" and a != "y"){
                            goto pilyesno10;
                        }
                        else if(a == "y"){
                            if(findRelasi(Lrelasi, P, D)){
                                cout<<"Departemen Telah Memiliki Pegawai Ini...";getch();
                                goto mulai;
                            }
                            insertRelasi(Lrelasi, alokasiRelasi(P, D));
                            cout<<"Hubungan antar Pegawai dan Department berhasil ditambahkan :)"<<endl;
                        }
                        cout<<endl<<"Back to menu...";getch();
                    }
                    else{
                        cout<<"Data Tidak Ditemukan atau List Kosong...";getch();
                    }
            }
            else{
                cout<<"Data Tidak Ditemukan atau List Kosong...";getch();
            }
            goto mulai;
        }
        case 11:{
            cout<<"Hapus Departemen Di Seorang Pegawai\n";
            printDepartemen(Ldepartemen);
            string a;
            cout<<endl<<"Departemen mana yang akan dipilih (Nama)? ";cin>>A.nama_departemen;
            address_departemen D = findDepartemen(Ldepartemen, A);
            if(D != NULL){
                system("cls");
                cout<<endl<<"Departemen yang telah dipilih"<<endl<<endl;
                cout<<"Nama Departemen            :"<<info(D).nama_departemen<<endl;
                cout<<"Alamat Departemen          :"<<info(D).alamat<<endl;
                cout<<endl<<"Menampilkan Pegawai yang bekerja...";getch();cout<<endl;
                printPegawaidenganDepartemenTertentu(Lrelasi, Lpegawai, D);
                cout<<endl<<"Pegawai mana yang akan dipilih (NIP)? ";cin>>B.nip;
                address_pegawai P = findPegawai(Lpegawai, B);
                    if(P != NULL){
                        cout<<endl<<"Nama Pegawai         :"<<info(P).nama<<endl;
                        cout<<"NIP Pegawai          :"<<info(P).nip<<endl;
                        pilyesno11:
                        cout<<endl<<"Hapus Relasi data ini [y/n] ? ";cin>>a;
                        if(a != "n" and a != "y"){
                            goto pilyesno11;
                        }
                        else if(a == "y"){
                            deleteRelasi(Lrelasi, findRelasi(Lrelasi, P, D));
                            cout<<"Hubungan antar Pegawai dan Department berhasil dirusak :("<<endl;
                        }
                        cout<<endl<<"Back to menu...";getch();
                    }
                    else{
                        cout<<"Data Tidak Ditemukan atau List Kosong...";getch();
                    }
            }
            else{
                cout<<"Data Tidak Ditemukan atau List Kosong...";getch();
            }
            goto mulai;
        }
        case 12:{
            cout<<"Hapus Pegawai Yang Masuk Ke Sebuah Departemen\n";
            printPegawai(Lpegawai);
            string a;
            cout<<endl<<"Pegawai mana yang anda pilih (NIP)? : ";cin>>B.nip;
            address_pegawai P = findPegawai(Lpegawai, B);
            if(P != NULL){
                system("cls");
                cout<<endl<<"Pegawai yang telah dipilih"<<endl<<endl;
                cout<<"Nama Pegawai         :"<<info(P).nama<<endl;
                cout<<"NIP Pegawai          :"<<info(P).nip<<endl;
                cout<<endl<<"Menampilkan Departemen yang terhubung...";getch();cout<<endl;
                printDepartemendenganPegawaiTertentu(Lrelasi, Ldepartemen, P);
                cout<<endl<<"Departemen mana yang akan dipilih (Nama)? ";cin>>A.nama_departemen;
                address_departemen D = findDepartemen(Ldepartemen, A);
                    if(D != NULL){
                        cout<<endl<<"Nama Departemen         :"<<info(D).nama_departemen<<endl;
                        cout<<"Alamat Departemen       :"<<info(D).alamat<<endl;
                        pilyesno12:
                        cout<<endl<<"Hapus Relasi data ini [y/n] ? ";cin>>a;
                        if(a != "n" and a != "y"){
                            goto pilyesno12;
                        }
                        else if(a == "y"){
                            deleteRelasi(Lrelasi, findRelasi(Lrelasi, P, D));
                            cout<<"Hubungan antar Pegawai dan Department berhasil dirusak :("<<endl;
                        }
                        cout<<endl<<"Back to menu...";getch();
                    }
                    else{
                        cout<<"Data Tidak Ditemukan atau List Kosong...";getch();
                    }
            }
            else{
                cout<<"Data Tidak Ditemukan atau List Kosong...";getch();
            }
            goto mulai;
        }
        case 13:{
            cout<<"Melihat Departemen Yang Telah Dimasuki Pegawai\n";
            printDepartemendenganPegawai(Lrelasi, Ldepartemen);
            cout<<endl<<endl<<"Back to menu...";getche();
            goto mulai;
        }
        case 14:{
            cout<<"Melihat Pegawai Yang Bekerja Di Departemen\n";
            printPegawaidenganDepartemen(Lrelasi, Lpegawai);
            cout<<endl<<endl<<"Back to menu...";getche();
            goto mulai;
        }
        case 15:{
            cout<<"Departemen Dengan Pegawai Terbanyak\n";
            printDepartemenPegawaiTerbanyak(Lrelasi, Ldepartemen);
            cout<<endl<<endl<<"Back to menu...";getche();
            goto mulai;
        }
        case 16:{
            cout<<"Departemen Dengan Pegawai Tersedikit\n";
            printDepartemenPegawaiTersedikit(Lrelasi, Ldepartemen);
            cout<<endl<<endl<<"Back to menu...";getche();
            goto mulai;
        }
    }
}
