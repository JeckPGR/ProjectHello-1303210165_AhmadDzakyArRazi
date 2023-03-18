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
        while(q != nil && infoP(q).nama != X){
            q = nextP(q);
        }
        return q;
    }
}

void RelasiPnA(ListR &LR, ListA LA, ListP LP, string nama, string judul){
    adrR r = new ElmRelasi;
    RPenulis(r) = CariDataPenulis(LP, nama);
    RArtikel(r) = FindArtikel(LA, judul);
    nextR(r) = firstR(LR);
    firstR(LR) = r;
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
    adrP p = CariDataPenulis(LP, nama);
    if(p==nil){
        cout << "Penulis tidak ditemukan";
    } else {
        // MENGHAPUS RELASI
        adrR R = firstR(LR);
        while(R != nil){
            if(RPenulis(R) == p){
                if(R == firstR(LR) && nextR(R) == nil){
                    firstR(LR) = nil;
                    R = firstR(LR);
                } else if(R == firstR(LR)) {
                    firstR(LR) = nextR(R);
                    nextR(R) = nil;
                    R = firstR(LR);
                } else {
                    adrR beforeR = firstR(LR);
                    while(nextR(beforeR)!=R){
                        beforeR = nextR(beforeR);
                    }
                    if(nextR(R) == nil){
                        nextR(beforeR) = nil;
                        R = firstR(LR);
                    } else {
                        nextR(beforeR) = nextR(R);
                        nextR(R) = nil;
                        R = firstR(LR);
                    }
                }
            }
            R = nextR(R);
        }
        // MENGHAPUS PENULIS
        adrP P = firstP(LP);
        while(P != nil){
            if(infoP(P).nama == nama){
                if(P == firstP(LP) && P == LastP(LP)){
                    firstP(LP) = nil; LastP(LP) = nil;
                } else if(P == firstP(LP)) {
                    firstP(LP) = nextP(P);
                    nextP(P) = nil;
                    prev(firstP(LP)) = nil;
                } else if(P == LastP(LP)) {
                    LastP(LP) = prev(P);
                    prev(P) = nil;
                    nextP(LastP(LP)) = nil;
                } else {
                    nextP(prev(P)) = nextP(P);
                    prev(nextP(P)) = prev(P);
                    nextP(P) = nil;
                    prev(P) = nil;
                }
            }
            P = nextP(P);
        }
    }
}

void DeleteArtikelPenulis(ListP LP, ListA LA, ListR &LR, string nama,string judul){
    adrP p = CariDataPenulis(LP, nama);
    adrA a = FindArtikel(LA, judul);
    if(p==nil || a==nil){
        cout << "Penulis / Artikel tidak ditemukan";
    } else {
        adrR R = firstR(LR);
        while(R != nil){
            if(RPenulis(R) == p && RArtikel(R) == a){
                if(R == firstR(LR) && nextR(R) == nil){
                    firstR(LR) = nil;
                } else if(R == firstR(LR)) {
                    firstR(LR) = nextR(R);
                    nextR(R) = nil;
                } else {
                    adrR beforeR = firstR(LR);
                    while(nextR(beforeR)!=R){
                        beforeR = nextR(beforeR);
                    }
                    if(nextR(R) == nil){
                        nextR(beforeR) = nil;;
                    } else {
                        nextR(beforeR) = nextR(R);
                        nextR(R) = nil;
                    }
                }
            }
            R = nextR(R);
        }
    }
}

int CountAuthors(ListR LR, string judull){
    int i = 0;
    adrR p = firstR(LR);
    while(p != nil){
        if(infoA(RArtikel(p)).judul == judull){
            i++;
        }
        p = nextR(p);
    }
    return i;
}

void showRelasi(ListR LR){
    int i=0;
    adrR p = firstR(LR);
    if(p!=nil){
        while(p!=nil){
            i++;
            cout<<"Penulis Ke-"<<i<<endl;
            cout << "Nama: "<<infoP(RPenulis(p)).nama <<endl;
            cout << "Judul: "<<infoA(RArtikel(p)).judul << endl;
            p = nextR(p);
            cout<<endl;
        }
    } else {
        cout << "Relasi kosong";
    }
}

void Produktif(ListR &LR, ListP &LP) {
  int maxCount = 0;
  string namaa;

  for (adrP P = firstP(LP); P != nil; P = nextP(P)) {
    string nama = infoP(P).nama;
    int count = 0;

    for (adrR R = firstR(LR); R != nil; R = nextR(R)) {
      if (RPenulis(R) == P) {
        count++;
      }
    }

    if (count > maxCount) {
      maxCount = count;
      namaa = nama;
    }
  }
  adrP P = CariDataPenulis(LP, namaa);
  cout << "Nama: " << infoP(P).nama << endl;
  cout << "Usia: " << infoP(P).usia << endl;
  cout << "NIM: " << infoP(P).nim << endl;
  cout << "Jumlah Artikel: " << maxCount << endl;
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
    cout<<"9.Menampilkan penulis beserta relasinya"<<endl;
    cout<<"10.Menampilkan penulis paling produktif"<<endl;


    int input = 0;
    cout<<endl;
    cout<<"Pilih Menu: ";
    cin>>input;

    return input;
}
