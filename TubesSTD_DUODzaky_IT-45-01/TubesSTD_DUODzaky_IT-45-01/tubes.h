#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

#define firstP(LP) ((LP).firstP)
#define firstA(LA) ((LA).firstA)
#define firstR(LR) ((LR).firstR)

#define LastP(P) (P).LastP
#define nextA(P) P->nextA
#define nextP(P) P->nextP
#define nextR(P) P->nextR
#define infoA(A) A->infoA
#define infoP(P) P->infoP
#define RPenulis(R) R->RPenulis
#define RArtikel(R) R->RArtikel

#define prev(P) P->prev
#define nil NULL

typedef struct ElmPenulis *adrP;
typedef struct ElmArtikel *adrA;
typedef struct ElmRelasi *adrR;

struct penulis{
    string nama;
    int usia;
    string nim;
};

typedef struct penulis infoP;

struct ElmPenulis{
    infoP infoP;
    adrP nextP;
    adrP prev;
};

struct ElmRelasi{
    adrP RPenulis;
    adrA RArtikel;
    adrR nextR;
};

struct artikel{
    string judul;
    int Tahun;
};

typedef artikel infoA;

struct ElmArtikel {
    infoA infoA;
    adrA nextA;
};

struct ListP {
   adrP firstP,LastP;
};

struct ListR {
    adrR firstR;
};

struct ListA {
    adrA firstA;
};


void DataPenulis(ListP &LP, infoP x);
void DataArtikel(ListA &LA, infoA x);

void CreateListP(ListP &LP);
void CreateListA(ListA &LA);
void CreateListR(ListR &LR);

adrA FindArtikel(ListA LA, string judul);
adrP CariDataPenulis(ListP LP, string X);
void RelasiPnA(ListR &LR, ListA LA, ListP LP, string nama, string judul);

void PrintPenulis(ListP LP);
void PrintArtikel(ListA LA);
void ShowAll(ListP LP, ListR LR);

adrA MencariDAYPT(ListR LR, string nama, string judul);


void DeletePenulis(ListP &LP, ListR &LR, string nama);
void DeleteArtikelPenulis(ListP LP, ListA LA, ListR &LR, string nama, string judul);
void deleteRelasi(ListR &LR, adrR R);

int CountAuthors(ListR LR, string judul);
int Menu();



#endif // TUBES_H_INCLUDED
