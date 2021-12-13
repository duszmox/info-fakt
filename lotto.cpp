#include <iostream>
#include <fstream>

using namespace std;

int l[53][6]; // 1-től indexelés
int szam;
int stat[9];

void f1 () {
    cout << "1. feladat" << endl;
    cout << "Kérem az 52. hét lottószámait szóközzel elválasztva!" << endl;
    for(int i=1; i<=5; i++) {
        cin >> l[52][i];
    }

}

 void f2() {
     for(int i=1; i<5; i++) {
         for(int j=i+1; j<=5; j++) {
             if(l[52][i]>l[52][j]) {
                swap(l[52][i], l[52][j]);
             }
         }
     }

     cout << "2. feladat" << endl;
     cout << "Az 52. heti lottószámok sorbarendezve: " << endl;
     for(int i=1; i<=5; i++) {
         cout << l[52][i] << " ";
     }
     cout << endl;
 }
 
 void f3() {
     cout << "3. feladat" << endl;
     cout << "Kérek egy egész számot 1 és 51 között!" << endl;
    cin>> szam;
 }

void f4() {
    cout << "4. feladat" << endl;
    ifstream fbe("lottosz.dat");
    for(int i=1; i<=51; i++) {
        for(int j=1; j<=5; j++) {
            fbe >> l[i][j];
        }
    }
    fbe.close();
    for(int i=1; i<=5; i++) {
       cout<< l[szam][i] << " ";
    }
    cout << endl;
}

void f5() {
    cout << "5. feladat" << endl;
    for(int i=1; i<=90; i++) stat[i]=0;
    for(int i=1; i<=51; i++) {
        for(int j=1; j<=5; j++) {
            stat[l[i][j]]++;
        }
    }
    int i= 1;
    while(i<=90 && stat[i]!=0) i++;
    if(i<=90) cout<<"Van"<<endl;
    else cout<<"Nincs"<<endl;
}
void f6() {
    cout << "6. feladat" << endl;
    int db=0;
    for(int i=1; i<=51; i++) {
        int j=1;
        while(j<=5 && l[i][j]==l[i][j]%2==0) j++;
        if(j<=5) db++;
    }
    cout << db << " alkalommal volt a kíhúzott számok között páratlan" << endl;

}
void f7() {
    cout << "7. feladat" << endl;
    ofstream fki("lotto52.txt");
    for(int i=1; i<=52; i++) {
        for(int j=1; j<=5; j++) {
            if(j<5) fki << l[i][j] << " ";
            else fki << l[i][j] << endl;
        }
    }
    fki.close();
}

void f8() {
    cout << "8. feladat" << endl;
    for (int j=1; j<=5; j++) {
        stat[l[52][j]]++;
    }
    for (int i=1; i<=90; i++) {
       cout << stat[i] ;
       if(i%15==0) cout << endl;
       else cout << " ";

    }
}
void f9() {
    cout << "9. feladat" << endl;
    const int prim[24] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89};
    cout <<"Ki nem húzott prímek" << endl;
    for (int i=0; i<24; i++) {
        if(stat[prim[i]]==0) cout << prim[i] << " ";
    }
    cout << endl;
}
int main() {
    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
    f7();
    f8();
    f9();
    return 0;
}