#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include <stdio.h>
#include <iostream>

#define Pegawai(P) (P)->Pegawai
#define nextRelasi(P) (P)->nextRelasi

#define Departemen(P) (P)->Departemen

#include "doublelink_List.h"

struct elmlist_relasi{
    address_pegawai Pegawai;
    address_relasi nextRelasi;
    address_departemen Departemen;
};

struct list_relasi{
    address_relasi first;
    address_relasi last;
};

address_relasi alokasiRelasi(address_pegawai P, address_departemen D);
void dealokasiRelasi(address_relasi R);

void insertRelasi(list_relasi &L, address_relasi R);
address_relasi findRelasi(list_relasi, address_pegawai P, address_departemen D);

void deletefirstRelasi(list_relasi &Lrelasi);
void deletelastRelasi(list_relasi &Lrelasi);
void deleteafterRelasi(list_relasi &Lrelasi, address_relasi &R);
void deleteSemuaRelasiPegawai(list_relasi &Lrelasi, address_pegawai P);
void deleteSemuaRelasiDepartemen(list_relasi &Lrelasi, address_departemen D);

void printPegawaidenganDepartemen(list_relasi Lrelasi, list_pegawai Lpegawai);
void printDepartemendenganPegawai(list_relasi Lrelasi, list_departemen Ldepartemen);
void printDepartemendenganPegawaiTertentu(list_relasi Lrelasi, list_departemen Ldepartemen, address_pegawai P);
void printPegawaidenganDepartemenTertentu(list_relasi Lrelasi, list_pegawai Lpegawai, address_departemen D);

#endif // RELASI_H_INCLUDED
