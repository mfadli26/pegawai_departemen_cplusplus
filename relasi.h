#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include <stdio.h>
#include <iostream>

#define Pegawai(P) (P)->Pegawai
#define nextRelasi(P) (P)->nextRelasi

#define Departemen(P) (P)->Departemen
#define nextDepartemen(P) (P)->nextDepartemen

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

void deletefirstRelasi(list_relasi &Lrelasi);


#endif // RELASI_H_INCLUDED
