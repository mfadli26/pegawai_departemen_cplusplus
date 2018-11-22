#include <cstdlib>
#include <iostream>
#include <conio.h>
#include "relasi.h"
#include "doublelink_List.h

void CreateListRelasi(list_relasi &L){
    first(L) = NULL;
    last(L) = NULL;
};

address_relasi alokasiRelasi(address_pegawai P, address_departemen D){
    address_relasi R = new elmlist_relasi;
    Pegawai(R) = R;
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
        nextRelasi(first(L)) = R;
        last(L) = R;
    }
};
