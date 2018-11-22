#ifndef DOUBLELINK_LIST_H_INCLUDED
#define DOUBLELINK_LIST_H_INCLUDED

#include <stdio.h>
#include <iostream>

#define first(Lpegawai) Lpegawai.first
#define last(Lpegawai) Lpegawai.last

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev

using namespace std;

struct infotype_pegawai{
    string nama;
    string nip;
};
struct infotype_departemen{
    string nama_departemen;
    string alamat;
};


typedef struct elmlist_pegawai *address_pegawai;
typedef struct elmlist_departemen *address_departemen;
typedef struct elmlist_relasi *address_relasi;

struct elmlist_pegawai{
    infotype_pegawai info;
    address_pegawai next;
    address_pegawai prev;
};

struct elmlist_departemen{
    infotype_departemen info;
    address_departemen next;
    address_departemen prev;
};

struct list_pegawai{
    address_pegawai first;
    address_pegawai last;
};

struct list_departemen{
    address_departemen first;
    address_departemen last;
};

void CreatePegawai(list_pegawai &Lpegawai);
void CreateDepartemen(list_departemen &Ldepartemen);

address_pegawai alokasiPegawai(infotype_pegawai X);
address_departemen alokasiDepartemen(infotype_departemen X);

void dealokasiPegawai(address_pegawai P);
void dealokasiDepartemen(address_departemen P);

address_pegawai findPegawai(list_pegawai Lpegawai, infotype_pegawai X);
address_departemen findDepartemen (list_departemen Ldepartemen, infotype_departemen X);

//* Insert *//
void insertPegawai(list_pegawai &Lpegawai, address_pegawai P);
void insertDepartemen(list_departemen &Ldepartemen, address_departemen P);
//*DELETE//*
void deleteFirstPegawai(list_pegawai &Lpegawai, address_pegawai &P);
void deleteAfterPegawai(list_pegawai &Lpegawai, address_pegawai &P);
void deleteLastPegawai(list_pegawai &Lpegawai, address_pegawai &P);

void deleteFirstDepartemen(list_departemen &Ldepartemen, address_departemen &P);
void deleteAfterDepartemen(list_departemen &Ldepartemen, address_departemen &P);
void deleteLastDepartemen(list_departemen &Ldepartemen, address_departemen &P);

void deletePegawai(list_pegawai &Lpegawai, address_pegawai P);
void deleteDepartemen(list_departemen &Ldepartemen, address_departemen D);

//*Proses*//
void printPegawai(list_pegawai Lpegawai);
void printDepartemen(list_departemen Ldepartemen);

void printPegawai1(list_pegawai Lpegawai);
void printDepartemen1(list_departemen Ldepartemen);
#endif // DOUBLELINK_LIST_H_INCLUDED
