#include "tubes.h"

void CreateListP(ListP &LP){
    firstP(LP) = NULL;
    LastP(LP) = NULL;
}
void CreateListR(ListR &LR){
    firstR(LR) = NULL;
}

void CreateListA(ListA &LA){
    firstA(LA) = NULL;
}

void DataPenulis(ListP &LP, infoP x){
    adrP p = new ElmPenulis;
    infoP(p) = x;
    nextP(p) = nil;
    prev(p) = nil;
    if(firstP(LP) == nil){
        firstP(LP) = p;
        LastP(LP) = p;
    } else {
        nextP(LastP(LP)) = p;
        prev(p) = LastP(LP);
        LastP(LP) = p;
    }

}
void DataArtikel(ListA &LA, infoA x){
    adrA p = new ElmArtikel;
    infoA(p) = x;
    nextA(p) = nil;
    if(firstA(LA) == nil){
        firstA(LA) = p;
        nextA(p) = p;
    } else {
        adrA q = firstA(LA);
        while(nextA(q) != firstA(LA)){
            q = nextA(q);
        }
        nextA(p) = firstA(LA);
        firstA(LA) = p;
        nextA(q) = p;
    }
}

void PrintPenulis(ListP LP){
    adrP P;
    int i=0;
    if(firstP(LP)!=nil && LastP(LP)!=nil){
        P = firstP(LP);
        while(P != nil){
            i++;
            cout<<"Data penulis ke-"<<i<<endl;
            cout<<"Nama: "<<infoP(P).nama<<endl;
            cout<<"NIM: "<<infoP(P).nim<<endl;
            cout<<"Usia: "<<infoP(P).usia;
            cout<<endl;
            P = nextP(P);
            cout<<endl;
        }
        cout<<endl;
    }else{
        cout<<"List kosong";
    }
}

void PrintArtikel(ListA LA){
    adrA A;
    int i = 0;
    if(firstA(LA)!=nil){
        A = firstA(LA);
        while(nextA(A) != firstA(LA)){
            i++;
            cout<<"Data artikel ke-"<<i<<endl;
            cout<<"Judul: "<<infoA(A).judul<<endl;
            cout<<"Tahun Terbit: "<<infoA(A).Tahun<<endl;
            A = nextA(A);
            cout<<endl;
        }
        i++;
        cout<<"Data artikel ke-"<<i<<endl;
        cout<<"Judul: "<<infoA(A).judul<<endl;
        cout<<"Tahun terbit: "<<infoA(A).Tahun<<endl;
        A = nextA(A);
        cout<<endl;
    }else{
        cout<<"List kosong";
    }
}

adrA FindArtikel(ListA LA, string judul){
    adrA q;
    q = firstA(LA);
    while(nextA(q)!=firstA(LA)&& infoA(q).judul != judul){
        q = nextA(q);
    }
    return q;
}

adrP CariDataPenulis(ListP LP, string X){
    adrP q;
    if(firstP(LP)!= nil && LastP(LP) != nil){
        q = firstP(LP);
        while(q == nil && infoP(q).nama != X){
        q = nextP(q);
        }
    }
    return q;
}

void RelasiPnA(ListR &LR, ListA LA, ListP LP, string nama, string judul){
    adrR r = new ElmRelasi;
    RPenulis(r) = CariDataPenulis(LP, nama);
    RArtikel(r) = FindArtikel(LA, judul);
    if(firstR(LR)==nil){
        firstR(LR)=r;
    }else{
        nextR(r) = firstR(LR);
        firstR(LR) = r;
    }
}

adrA MencariDAYPT(ListR LR, string nama, string judul){
    adrR r;
    adrA a = nil;
    r = firstR(LR);
    while(r != nil){
        if(infoP(RPenulis(r)).nama == nama){
            if(infoA(RArtikel(r)).judul == judul){
                a = RArtikel(r);
            }
        }
        r = nextR(r);
    }
    return a;
}

void DeletePenulis(ListP &LP, ListR &LR, string nama){
    if(firstP(LP) == nil){ // jika List kosong
        cout<<"Tidak ada data"<<endl;
        return;
    }
    adrR r;
    adrP a = CariDataPenulis(LP,nama);
    if(a != nil){
        r = firstR(LR);
        if(r != nil){
            while(r != nil){
                if(RPenulis(r)==a){
                    if(r == firstR(LR)){
                        firstR(LR) = nextR(r);
                        nextR(r)=nil;
                        delete r;
                    }else{
                        adrR temp = firstR(LR);
                        while(nextR(temp)!=r){
                            temp = nextR(temp);
                        }
                        if(nextR(r)!= nil){
                            nextR(temp) = nextR(r);
                            nextR(r) = nil;
                        }else{
                            nextR(temp)=nil;
                        }
                    }
                }else{
                    r=nextR(r);
                }
            }
        }
        if(a == firstP(LP)){
            if(nextP(firstP(LP))==nil){
                firstP(LP)=nil;
                LastP(LP)=nil;
            }else{
                firstP(LP) = nextP(a);
                nextP(a) = nil;
                prev(firstP(LP)) = nil;
            }
        }else if(a == LastP(LP)){
            if(nextP(firstP(LP))==nil){
                firstP(LP)=nil;
                LastP(LP)=nil;
            }else{
                LastP(LP) = prev(a);
                nextP(LastP(LP)) = nil;
                prev(a)=nil;
            }
        }else{
            if(nextP(firstP(LP))==nil){
                firstP(LP)=nil;
                LastP(LP)=nil;
            }else{
                nextP(prev(a)) = nextP(a);
                prev(nextP(a)) = prev(a);
                nextP(a)=nil;
                prev(a)=nil;
            }
        }

    }else{
        cout<<"data tidak ditemukan";
    }
}
// Menghapus Relasi
    /*R = firstR(LR);
    adrR beforeR = firstR(LR);
    while(nextR(beforeR) != R){
        beforeR = nextR(beforeR);
    }
    while(R != nil){
        if(RPenulis(R) == P){
            if(R == firstR(LR) && nextR(firstR(LR))==nil){
                firstR(LR) = nil;
            } else if(R == firstR(LR)) {
                firstR(LR) = nextR(firstR(LR));
            } else {
                nextR(beforeR) = nextR(R);
            }
        } else {
            R = nextR(R);
        }
    }*/


void DeleteArtikelPenulis(ListP LP, ListA LA, ListR &LR, string nama,string judul){
    adrR R;
    adrP P = CariDataPenulis(LP,nama);
    adrA A = FindArtikel(LA,judul);
    adrR RP;

    RP = firstR(LR);
    R = firstR(LR);
    if(P!=nil && A != nil){

        while(R!= nil){

            if(R == firstR(LR) && nextR(R) == nil){
                firstR(LR)= nil;
            } else if( R == firstR(LR) ) {
                    firstR(LR) = nextR(R);
                    nextR(R) = nil;
            } else {
                    while(nextR(RP)!= R){
                        RP = nextR(RP);
                    }
                    if(nextR(R) == nil){
                        nextR(RP) = nil;
                    } else {
                        nextR(RP) = nextR(R);
                        nextR(R) = nil;
                    }

                }
            }
            R=nextR(R);
        }
    }


int CountAuthors(ListR LR, string judul)
{
    int i = 0;
    adrR p = firstR(LR);
    while (p != nil)
    {
        if (infoA(RArtikel(p)).judul == judul)
        {
            i = i +1;
        }
        p = nextR(p);
    }
    return i;
}

int Menu(){
    cout<<"========= MENU ========="<<endl;
    cout<<"1.Menambah data Penulis"<<endl;
    cout<<"2.Memasukan data Artikel ilmiah"<<endl;
    cout<<"3.Menampilkan Data penulis & Artikel ilmiah"<<endl;
    cout<<"4.Meyambungkan relasi data penulis dengan artikel ilmiah yang ditulis"<<endl;
    cout<<"5.Mencari penulis yang ingin dicari"<<endl;
    cout<<"6.Menghapus penulis"<<endl;
    cout<<"7.Menghapus artikel ilmiah penulis"<<endl;
    cout<<"8.Menghitung Author"<<endl;


    int input = 0;
    cout<<endl;
    cout<<"Pilih Menu: ";
    cin>>input;

    return input;
}



