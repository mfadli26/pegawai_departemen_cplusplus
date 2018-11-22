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
    return P;
};
address_departemen alokasiDepartemen(infotype_departemen X){
    address_departemen P = new elmlist_departemen;
    info(P).nama_departemen = X.nama_departemen;
    info(P).alamat = X.alamat;
    next(P) = NULL;
    prev(P) = NULL;
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
    while (P != NULL){
        if(info(P).nip == X.nip){
            return P;
        }
        P = next(P);
    }
    return NULL;
};

address_departemen findDepartemen (list_departemen Ldepartemen, infotype_departemen X){
    address_departemen D = first(Ldepartemen);
    while (D != NULL){
        if(info(D).nama_departemen == X.nama_departemen){
            return D;
        }
        D = next(D);
    }
    return NULL;
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
        int a = 1;
        address_pegawai P = first(Lpegawai);
        while (P != NULL){
            cout<<endl;
            cout<<"Index = "<<a++<<endl;
            cout<<"Nama Pegawai = "<<info(P).nama<<endl;
            cout<<"Nip = "<<info(P).nip<<endl;
            P = next(P);
        }
    }
    cout<<endl<<"Back to menu...";
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
        int a = 1;
        address_departemen P = first(Ldepartemen);
        while (P != NULL){
            cout<<endl;
            cout<<"Index = "<<a++<<endl;
            cout<<"Nama Departemen = "<<info(P).nama_departemen<<endl;
            cout<<"Alamat = "<<info(P).alamat<<endl;
            P = next(P);
        }
    }
    cout<<endl<<"Back to menu...";
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

void deletePegawai(list_pegawai &Lpegawai, address_pegawai P){
    if (P == first(Lpegawai)){
        deleteFirstPegawai(Lpegawai, P);
    }
    else if (P == last(Lpegawai)){
        deleteLastPegawai(Lpegawai, P);
    }
    else{
        deleteAfterPegawai(Lpegawai, P);
    }
};

void deleteDepartemen(list_departemen &Ldepartemen, address_departemen D){
    if (D == first(Ldepartemen)){
        deleteFirstDepartemen(Ldepartemen, D);
    }
    else if (D == last(Ldepartemen)){
        deleteLastDepartemen(Ldepartemen, D);
    }
    else{
        deleteAfterDepartemen(Ldepartemen, D);
    }
};

