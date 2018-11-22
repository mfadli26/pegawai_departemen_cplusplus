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
        nextRelasi(first(L)) = R;
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

void printinfoRelasi(list_relasi Lrelasi){
    cout<<"Data Laptop"<<endl;
    address_relasi Q = first(Lrelasi);
    while(Q != NULL){
        cout<<endl;
        cout<<"Nama Pegawai : "<<info(Pegawai(Q)).nama<<endl;
        cout<<"-----------------------"<<endl;
        cout<<"Nama Departemen : "<<info(Departemen(Q)).nama_departemen<<endl;
        cout<<"-----------------------"<<endl;
        Q = nextRelasi(Q);
    }
}
