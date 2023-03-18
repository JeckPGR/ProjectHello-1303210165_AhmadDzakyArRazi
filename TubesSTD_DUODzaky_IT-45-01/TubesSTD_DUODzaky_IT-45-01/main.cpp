#include "tubes.h"


int main()
{
    ListP LP;
    ListA LA;
    ListR LR;
    infoA x;
    adrP q;
    infoP y;
    string z;
    string NA;
    string tittle;
    int NUM = 0, pilihan = 0, D = 0, i = 0 ;
    int A = 0;
    int numAuthors;
    int NUMA = 0;

    CreateListA(LA);
    CreateListP(LP);
    CreateListR(LR);

    pilihan=Menu();
    while (pilihan != 0){
        switch(pilihan){
            case 1:
                cout<<"Jumlah data :";
                cin>>NUM;
                cout<<endl;
                while(i<NUM){
                    A++;
                    cout<<"Data ke-"<<A<<endl;
                    cout<<"input nama: ";
                    cin>>y.nama;
                    cout<<"input nim: ";
                    cin>>y.nim;
                    cout<<"input usia: ";
                    cin>>y.usia;
                    DataPenulis(LP, y);
                    i++;
                    cout<<endl;
                }
                break;
            case 2:
                cout<<"Jumlah Data : ";
                cin>>NUMA;
                while(D<NUMA){
                    cout<<"input judul: ";
                    cin>>x.judul;
                    cout<<"input tahun terbit:";
                    cin>>x.Tahun;
                    DataArtikel(LA, x);
                    D++;
                    cout<<endl;
                }
                break;
            case 3:
                PrintPenulis(LP);
                cout<<endl;
                PrintArtikel(LA);
                break;
            case 4:
                cout<<"Relasi antara Penulis dengan judul "<<endl;
                cout<<"Penulis :";
                cin>>z;
                cout<<"Judul Artikel :";
                cin>>NA;
                RelasiPnA(LR,LA,LP,z,NA);
                break;
            case 5 :
                cout<<"Data Penulis yang dicari : ";
                cin>>z;
                cout<<endl;
                q = CariDataPenulis(LP,z);
                cout<<"Nama Penulis: "<<infoP(q).nama<<endl;
                cout<<"NIM Penulis: " <<infoP(q).nim<<endl;
                cout<<"Umur Penulis: "<<infoP(q).usia<<endl;
                break;
            case 6 :
                cout<<"Penulis yang ingin dihapus: ";
                cin>>z;
                cout<<endl;
                DeletePenulis(LP,LR,z);
                break;
            case 7 :
                cout<<"input nama penulis: ";
                cin>>z;
                cout<<"input judul artikel: ";
                cin>>NA;
                cout<<endl;
                DeleteArtikelPenulis(LP,LA,LR,z,NA);
                break;
            case 8 :
                cout<<"Judul Artikel :";
                cin>>tittle;
                numAuthors = CountAuthors(LR,tittle);
                cout<<numAuthors;
                break;

        }
        cout<<endl;
        pilihan = Menu();
    }
}

;







