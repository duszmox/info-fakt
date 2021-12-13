#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <time.h>
#include <fstream>

using namespace std;

struct adat {
    string nev;
    int evfolyam;
    double penz;
};

const int elemszam = 100;
typedef adat tomb[100];
tomb t;
int tdb;

void beolvas() {
    ifstream fbe("adatok.txt");
    if (!fbe) {
        cout << "Nincs meg a fajl!" << endl;
    fbe>>tdb;
    for (int i = 0; i < tdb; i++) {
        string s;
        getline(fbe, s);
        getline(fbe, t[i].nev);
        fbe >> t[i].evfolyam;
        fbe >> t[i].penz;
    }
    fbe.close();
    }

}
int main() {
    beolvas();
    for(int i=0;i<tdb;i++){
        cout<<t[i].nev<<" "<<t[i].evfolyam<<" "<<t[i].penz<<endl;
    }
    ofstream fki("kiadatok.txt");
    for(int i=0;i<tdb;i++){
        fki<<t[i].nev<<" * "<<t[i].evfolyam<<" * "<<t[i].penz<<endl;
    }
    ofstream fki2("kiadatok2.txt",ios::app);
    fki2<<"Added Line"<<endl;
    fki2.close();
}