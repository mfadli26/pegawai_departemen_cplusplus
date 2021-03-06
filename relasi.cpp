#include <cstdlib>
#include <iostream>
#include <conio.h>
#include "relasi.h"
#include "doublelink_List.h"

void CreateListRelasi(list_relasi &L){
    first(L) = NULL;
    last(L) = NULL;
};

address_relasi alokasiRelasi(address_pegawai P, address_departemen D){
    address_relasi R = new elmlist_relasi;
    Pegawai(R) = P;
    nextRelasi(R) = NULL;
    Departemen(R) =  D;
    return R;
};

void dealokasiRelasi(address_relasi R){
    delete(R);
};

void insertRelasi(list_relasi &L, address_relasi R){
    if(first(L) == NULL && last(L) == NULL){
        first(L) = R;
        last(L) = R;
    }
    else {
        nextRelasi(last(L)) = R;
        last(L) = R;
    }
};

void deletefirstRelasi(list_relasi &Lrelasi){
    address_relasi R = first(Lrelasi);
    if(first(Lrelasi) == last(Lrelasi)){
        first(Lrelasi) = NULL;
        last(Lrelasi) = NULL;
        dealokasiRelasi(R);
    }
    else{
        first(Lrelasi) = nextRelasi(first(Lrelasi));
        nextRelasi(R) = NULL;
        dealokasiRelasi(R);
    }
}

void deletelastRelasi(list_relasi &Lrelasi){
    address_relasi R = first(Lrelasi);
    if(first(Lrelasi) == last(Lrelasi)){
        first(Lrelasi) = NULL;
        last(Lrelasi) = NULL;
        dealokasiRelasi(R);
    }
    else{
        while(nextRelasi(R) != last(Lrelasi)){
            R = nextRelasi(R);
        }
        last(Lrelasi) = R;
        R = nextRelasi(R);
        nextRelasi(last(Lrelasi)) = NULL;
        dealokasiRelasi(R);
    }
}

void deleteafterRelasi(list_relasi &Lrelasi, address_relasi &R){
    address_relasi R2 = first(Lrelasi);
    while(nextRelasi(R2) != R){
        R = nextRelasi(R);
    }
    nextRelasi(R2) = nextRelasi(R);
    nextRelasi(R) = NULL;
    dealokasiRelasi(R);
}

void deleteRelasi(list_relasi &Lrelasi, address_relasi R){
    if (R == first(Lrelasi)){
        deletefirstRelasi(Lrelasi);
    }
    else if (R == last(Lrelasi)){
        deletelastRelasi(Lrelasi);
    }
    else{
        deleteafterRelasi(Lrelasi, R);
    }
};

address_relasi findRelasi(list_relasi Lrelasi, address_pegawai P, address_departemen D){
    address_relasi R = first(Lrelasi);
    while (R != NULL){
        if(Pegawai(R) == P and Departemen(R) == D){
            return R;
        }
        R = nextRelasi(R);
    }
    return NULL;
};

void printPegawaidenganDepartemen(list_relasi Lrelasi, list_pegawai Lpegawai){
    if(first(Lpegawai) == NULL){
        cout<<"Daftar Pegawai Kosong"<<endl;
    }
    else {
        int a = 1;
        address_pegawai P = first(Lpegawai);
        while (P != NULL){
            cout<<endl;
            cout<<"Index = "<<a++<<endl;
            cout<<"Nama Pegawai = "<<info(P).nama<<endl;
            cout<<"Nip = "<<info(P).nip<<endl;
            cout<<"Bekerja di Departemen = ";
            address_relasi R = first(Lrelasi);
            while(R != NULL){
                if(P == Pegawai(R)){
                    cout<<info(Departemen(R)).nama_departemen<<", ";
                }
                R = nextRelasi(R);
            }
            cout<<endl;
            P = next(P);
        }
    }
};

void printPegawaidenganDepartemenTertentu(list_relasi Lrelasi, list_pegawai Lpegawai, address_departemen D){
    if(first(Lpegawai) == NULL){
        cout<<"Daftar Pegawai Kosong"<<endl;
    }
    else {
        address_relasi R = first(Lrelasi);
        while (R != NULL){
            if(Departemen(R) == D){
                cout<<endl;
                cout<<"Nama Pegawai   = "<<info(Pegawai(R)).nama<<endl;
                cout<<"NIP Pegawai    = "<<info(Pegawai(R)).nip<<endl;
            }
            R = nextRelasi(R);
        }
    }
};

void printDepartemendenganPegawai(list_relasi Lrelasi, list_departemen Ldepartemen){
    if(first(Ldepartemen) == NULL){
        cout<<"Daftar Departemen Kosong"<<endl;
    }
    else {
        int a = 1;
        address_departemen D = first(Ldepartemen);
        while (D != NULL){
            cout<<endl;
            cout<<"Index = "<<a++<<endl;
            cout<<"Nama Departemen   = "<<info(D).nama_departemen<<endl;
            cout<<"Alamat Departemen = "<<info(D).alamat<<endl;
            cout<<"Memiliki Pegawai = ";
            address_relasi R = first(Lrelasi);
            while(R != NULL){
                if(D == Departemen(R)){
                    cout<<info(Pegawai(R)).nama<<", ";
                }
                R = nextRelasi(R);
            }
            cout<<endl;
            D = next(D);
        }
    }
};

void printDepartemendenganPegawaiTertentu(list_relasi Lrelasi, list_departemen Ldepartemen, address_pegawai P){
    if(first(Ldepartemen) == NULL){
        cout<<"Daftar Departemen Kosong"<<endl;
    }
    else {
        address_relasi R = first(Lrelasi);
        while (R != NULL){
            if(Pegawai(R) == P){
                cout<<endl;
                cout<<"Nama Departemen   = "<<info(Departemen(R)).nama_departemen<<endl;
                cout<<"Alamat Departemen = "<<info(Departemen(R)).alamat<<endl;
            }
            R = nextRelasi(R);
        }
    }
};

void deleteSemuaRelasiDepartemen(list_relasi &Lrelasi, address_departemen D){
    address_relasi R = first(Lrelasi);
    while(R != NULL){
        if(Departemen(R) == D){
            address_relasi T = nextRelasi(R);
            deleteRelasi(Lrelasi, R);
            R = T;
        }
        else{
            R = nextRelasi(R);
        }
    }
};

void deleteSemuaRelasiPegawai(list_relasi &Lrelasi, address_pegawai P){
    address_relasi R = first(Lrelasi);
    while(R != NULL){
        if(Pegawai(R) == P){
            address_relasi T = nextRelasi(R);
            deleteRelasi(Lrelasi, R);
            R = T;
        }
        else{
            R = nextRelasi(R);
        }
    }
};

void updateRelasi(address_relasi &R, address_departemen D, address_pegawai P){
    Pegawai(R) = P;
    Departemen(R) = D;
};

