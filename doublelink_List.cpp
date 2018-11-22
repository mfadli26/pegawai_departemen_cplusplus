#include <cstdlib>
#include <iostream>
#include <conio.h>
#include "doublelink_List.h"
#include "relasi.h"


void CreatePegawai(list_pegawai &Lpegawai){
    first(Lpegawai) = NULL;
    last(Lpegawai) = NULL;
};

void CreateDepartemen(list_departemen &Ldepartement){
    first(Ldepartement) = NULL;
    last(Ldepartement) = NULL;
};

void Lpegawai(list_departemen &Ldepartemen){
    first(Ldepartemen) = NULL;
    last(Ldepartemen) = NULL;
};
address_pegawai alokasiPegawai(infotype_pegawai X){
    address_pegawai P = new elmlist_pegawai;
    info(P).nama = X.nama;
    info(P).nip = X.nip;
    next(P) = NULL;
    prev(P) = NULL;
    relasi(P) = NULL;
    return P;
};
address_departemen alokasiDepartemen(infotype_departemen X){
    address_departemen P = new elmlist_departemen;
    info(P).nama_departemen = X.nama_departemen;
    info(P).alamat = X.alamat;
    next(P) = NULL;
    prev(P) = NULL;
    relasi(P) = NULL;
    return P;
};
void dealokasiPegawai(address_pegawai P){
    delete P;
};

void dealokasiDepartemen(address_departemen P){
    delete P;
};

address_pegawai findPegawai(list_pegawai Lpegawai, infotype_pegawai X){
    address_pegawai P = first(Lpegawai);
    if (first(Lpegawai) == NULL){
        cout<<"Error Data Tidak Ditemukan"<<endl;
        P = NULL;
        return P;
    }
    else {
        while (info(P).nama != X.nama and next(P) != NULL){
            P = next(P);
        }
        if (info(P).nama == X.nama){
            return P;
        }
        else {
            P = NULL;
            return P;
        }
    }
};

address_departemen findDepartemen (list_departemen Ldepartemen, infotype_departemen X){
    address_departemen P = first(Ldepartemen);
    if (first(Ldepartemen) == NULL){
        cout<<"Error Data Tidak Ditemukan"<<endl;
        P = NULL;
        return P;
    }
    else {
        while (info(P).nama_departemen != X.nama_departemen and next(P) != NULL){
            P = next(P);
        }
        if (info(P).nama_departemen == X.nama_departemen){
            return P;
        }
        else {
            P = NULL;
            return P;
        }
    }
};

void insertPegawai(list_pegawai &Lpegawai, address_pegawai P){
    if(first(Lpegawai) == NULL){
        first(Lpegawai) = P;
        last(Lpegawai) = P;
    }
    else {
        next(P) = first(Lpegawai);
        prev(first(Lpegawai)) = P;
        first(Lpegawai) = P;
    }
};

void insertDepartemen(list_departemen &Ldepartemen, address_departemen P){
    if(first(Ldepartemen) == NULL){
        first(Ldepartemen) = P;
        last(Ldepartemen) = P;
    }
    else {
        next(P) = first(Ldepartemen);
        prev(first(Ldepartemen)) = P;
        first(Ldepartemen) = P;
    }
};

void deleteFirstPegawai(list_pegawai &Lpegawai, address_pegawai &P){
    if (first(Lpegawai) == last(Lpegawai)) {
        first(Lpegawai) = NULL;
        last(Lpegawai) = NULL;
    }
    else {
        P = first(Lpegawai);
        first(Lpegawai) = next(P);
        next(P) = NULL;
        prev(first(Lpegawai)) = NULL;
    }
};
void deleteAfterPegawai(list_pegawai &Lpegawai, address_pegawai &P){
    if (first(Lpegawai) == last(Lpegawai)) {
        first(Lpegawai) = NULL;
        last(Lpegawai) = NULL;
    }
    else {
        address_pegawai Prec = prev(P);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
};
void deleteLastPegawai(list_pegawai &Lpegawai, address_pegawai &P){
    if (first(Lpegawai) == last(Lpegawai)) {
        first(Lpegawai) = NULL;
        last(Lpegawai) = NULL;
    }
    else {
        P = last(Lpegawai);
        last(Lpegawai) = prev(P);
        next(last(Lpegawai)) = NULL;
        prev(P) = NULL;
    }

};
void deleteFirstDepartemen(list_departemen &Ldepartemen, address_departemen &P){
    if (first(Ldepartemen) == last(Ldepartemen)) {
        first(Ldepartemen) = NULL;
        last(Ldepartemen) = NULL;
    }
    else {
        P = first(Ldepartemen);
        first(Ldepartemen) = next(P);
        next(P) = NULL;
        prev(first(Ldepartemen)) = NULL;
    }
};
void deleteAfterDepartemen(list_departemen &Ldepartemen, address_departemen &P){
    if (first(Ldepartemen) == last(Ldepartemen)) {
        first(Ldepartemen) = NULL;
        last(Ldepartemen) = NULL;
    }
    else {
        address_departemen Prec = prev(P);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
};
void deleteLastDepartemen(list_departemen &Ldepartemen, address_departemen &P){
    if (first(Ldepartemen) == last(Ldepartemen)) {
        first(Ldepartemen) = NULL;
        last(Ldepartemen) = NULL;
    }
    else {
        P = last(Ldepartemen);
        last(Ldepartemen) = prev(P);
        next(last(Ldepartemen)) = NULL;
        prev(P) = NULL;
    }

};

void printPegawai(list_pegawai Lpegawai){
    if(first(Lpegawai) == NULL){
        cout<<"Daftar Pegawai Kosong"<<endl;
    }
    else {
        address_pegawai P = first(Lpegawai);
        while (P != NULL){
            cout<<endl;
            cout<<"Nama Pegawai = "<<info(P).nama<<endl;
            cout<<"Nip = "<<info(P).nip<<endl;
            cout<<"Departemen = ";
            address_relasi Q = relasi(P);
            while (Q != NULL){
                cout<<info(Departemen(Q)).nama_departemen<<" ,";
                Q = nextRelasi(Q);
            }
            P = next(P);
            cout<<endl;
        }
    }
    cout<<endl;
};

void printPegawai1(list_pegawai Lpegawai){
    if(first(Lpegawai) == NULL){
        cout<<"Daftar Pegawai Kosong"<<endl;
    }
    else {
        address_pegawai P = first(Lpegawai);
        while (P != NULL){
            cout<<endl;
            cout<<"Nama Pegawai = "<<info(P).nama<<endl;
            cout<<"Nip = "<<info(P).nip<<endl;
            cout<<"Departemen = ";
            P = next(P);
            cout<<endl;
        }
    }
    cout<<endl;
};

void printDepartemen(list_departemen Ldepartemen){
    if(first(Ldepartemen) == NULL){
        cout<<"Daftar Departemen Kosong"<<endl;
    }
    else {
        address_departemen P = first(Ldepartemen);
        while (P != NULL){
            cout<<endl;
            cout<<"Nama Departemen = "<<info(P).nama_departemen<<endl;
            cout<<"Alamat = "<<info(P).alamat<<endl;
            cout<<"Pegawai = ";
            address_relasi Q = relasi(P);
            while (Q != NULL){
                cout<<info(Pegawai(Q)).nama<<" ,";
                Q = nextRelasi(Q);
            }
            P = next(P);
            cout<<endl;
        }
    }
    cout<<endl;
};

void printDepartemen1(list_departemen Ldepartemen){
    if(first(Ldepartemen) == NULL){
        cout<<"Daftar Departemen Kosong"<<endl;
    }
    else {
        address_departemen P = first(Ldepartemen);
        while (P != NULL){
            cout<<endl;
            cout<<"Nama Departemen = "<<info(P).nama_departemen<<endl;
            cout<<"Alamat = "<<info(P).alamat<<endl;
            P = next(P);
            cout<<endl;
        }
    }
    cout<<endl;
};

void deletePegawai(list_pegawai &Lpegawai, infotype_pegawai X){
        if (first(Lpegawai) == NULL){
        cout<<"Error Data Kosong"<<endl;
    }
    else {
        address_pegawai P = findPegawai(Lpegawai, X);
        if (P == first(Lpegawai)){
            deleteFirstPegawai(Lpegawai, P);
        }
        else if (P == last(Lpegawai)){
            deleteLastPegawai(Lpegawai, P);
        }
        else if (P != NULL){
            deleteAfterPegawai(Lpegawai, P);
        }
        else {
            cout<<"Data Tidak Ditemukan"<<endl;
        }
    }
};

void deleteDepartemen(list_departemen &Ldepartemen,infotype_departemen X){
        if (first(Ldepartemen) == NULL){
        cout<<"Error Data Kosong"<<endl;
    }
    else {
        address_departemen P = findDepartemen(Ldepartemen, X);
        while (info(P).nama_departemen != X.nama_departemen and P != NULL){
            P = next(P);
        }
        if (P == first(Ldepartemen)){
            deleteFirstDepartemen(Ldepartemen, P);
        }
        else if (P == last(Ldepartemen)){
            deleteAfterDepartemen(Ldepartemen, P);
        }
        else if (P != last(Ldepartemen) or P != first(Ldepartemen)){
            deleteLastDepartemen(Ldepartemen, P);
        }
        else {
            cout<<"Data Tidak Ditemukan"<<endl;
        }
    }
};

