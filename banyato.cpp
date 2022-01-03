#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int m[2001]; //1-től indexelt
int db=0;
int tav;


void f1() {
    cout << "1. Feladat" << endl;
    ifstream fbe("melyseg.txt");  
    while(fbe >> m[db+1]) db++;

    fbe.close();
    cout << "A fájl adatainak száma: " << db << endl;

}
void f2() {
    cout << "2. Feladat" << endl;
    cout << "Adja meg a távolságot: " << endl;
    cin >> tav;
    cout << "Ezen a helyszinen "<<m[tav]<<"m mély van" << endl;

}
void f3() {
    cout << "3. Feladat" << endl;
    int g=0;
    for(int i=1;i<=db;i++) {
        if(m[i]==0) g++;
    }
    cout<<"Az érintett terület aránya: "<<round(100*100*g/(double)db)/100<<"%"<<endl;
}

void f4() {
    cout << "4. Feladat" << endl;
    ofstream fki("godrok.txt");
    for(int i=1; i<db; i++) {
        if(m[i]>0) {
            fki<<m[i]<<" ";
            if (m[i+1]==0) fki<<endl;
        }
    }
}
void f5() {
    cout << "5. Feladat" << endl;
    int g = 0;
    for(int i=2; i<db; i++) {
        if(m[i]>0 && m[i-1]==0 ) g++;
    }
    cout<<"A gödrök száma:"<<g<<endl;
}
void f6() {
    cout << "6. Feladat" << endl;
    int gk = 0;
    int gv = 0;
    int i;
    if (m[tav]==0) {
        cout<<"A távolságban nincs gödör"<<endl;
    }
    else {
        i = tav;
        while(!(m[i-1]==0) && m[i]!=0) {
            i--;
        }
        gk = i;
        i = tav;
        while(!(m[i]>0 && m[i+1]==0))i++;
        gv = i;
        cout<< "Gödör kezdete: "<<gk<<" gödör vége: "<<gv<<endl;

        cout << "(b" << endl;
        i = gk+1;
        while (m[i-1]<=m[i]&& i<=gv) i++;
        while (m[i-1]>=m[i]&& i<=gv) i++;
        if (i>gv) cout <<"folyamatosan melyul" << endl;
        else cout <<"nem folyamatosan melyül" << endl;


        cout << "(c" << endl;
        int max = m[gk];
        for (i=gk+1; i<=gv; i++) {
            if (m[i]>max) max = m[i];
        }
        cout << "A legnagyobb mély: " << max << endl;


        cout << "(d" << endl;
        int t = 0;
        for (i=gk; i<=gv; i++) {
            t+=m[i];
        }
        cout << "térfogata: " << t*10 <<"m^3" << endl;

        cout << "(e" << endl;
         t = 0;
        for (i=gk; i<=gv; i++) {
            t+=m[i]-1;
        }
        cout << "vízmélysége: " << t*10 <<"m^3" << endl;
    }
    
    
}
int main() {
    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
    return 0;
}