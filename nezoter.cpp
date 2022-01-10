#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;
#define cock endl;

char f[16][21];
int k[16][21];
int ks[6];


void f1() {
    cout << "1. Feladat" << cock;

    ifstream fbe("foglaltsag.txt");
    for(int i = 1; i <= 15; i++) {
        for(int j = 1; j <= 20; j++) {
            fbe>>f[i][j];
        }
    }
    fbe.close();
    fbe.open("kategoria.txt");
    char c;
    stringstream ss;
    for(int i = 1; i <= 15; i++) {
        for(int j = 1; j <= 20; j++) {
            fbe>>c;
            ss<<c;
            ss>>k[i][j];
            ss.clear();
        }
    }
}
void f2() {
    cout << "2. Feladat" << cock;
    int s,o;
    cout << "  Sor szama: " << cock;
    cin>>s;
    cout << "  Oszlop szama: " << cock;
    cin>>o;
    if(f[s][o] == 'o') {
        cout << "  Nem foglalt" << cock;
    } else {
        cout << "  Foglalt" << cock;
    }
}

void f3() {
    cout << "3. Feladat" << cock;
    int db = 0;
    for(int i = 1; i <= 15; i++) {
        for(int j = 1; j <= 20; j++) {
            if(f[i][j] == 'x') {
                db++;
            }
        }
    }
    cout << "  Az eloadasra eddig " << db << " jegyet adtak el, ez a jegyek "<< round(((double)db/300)*100)<<"%-a." << cock;
}

void f4() {
    cout << "4. Feladat" << cock;
    for(int i = 1; i <= 15; i++) {
        for(int j = 1; j <= 20; j++) {
            if(f[i][j] == 'x') {
                ks[k[i][j]]++;
            }
        }
    }
    int m = 1;
    for(int i=2; i<=5; i++) {
        if(ks[i] > ks[m]) {
            m = i;
        }
    }
    cout <<"A legtobb jegyet a(z) "<<m <<". arkategoriaban ertekstettek"<< cock;
}

void f5() {
    cout << "5. Feladat" << cock;
    int e[6] = {0,5000,4000,3000,2000,1500};
    int bev=0;
    for(int i = 1; i <= 15; i++) {
        for(int j = 1; j <= 20; j++) {
            bev+=ks[i]*e[i];
        }
    }
    cout << "  A bevetel: " << bev << cock;
}

void f6() {
    cout << "6. Feladat" << cock;
    for(int i = 1; i<=15; i++) {
        f[i][0] = 'x';
        f[i][21] = 'x';
        
    }
    int egy = 0;
    for(int i = 1; i<=15; i++) {
        for(int j = 1; j<=20; j++) {
            if(f[i][j-1]=='x' && f[i][j+1]=='x' && f[i][j]=='o') {
                egy++;
            }
        }
    }
    cout << "  Ennyi egyedulallo szek van: " << egy << cock;
}

void f7() {
    cout << "7. Feladat" << cock;
    ofstream fki("szabad.txt");
    for(int i = 1; i<=15; i++) {
        for(int j = 1; j<=20; j++) {
            if(f[i][j]=='x') {
                fki<<'x';
            }
            else {
                fki<<k[i][j];
            }
        }
        fki<<'\n';

    }   
    fki.close();
}


int main() {
    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
    f7(); 
    return 0;
}