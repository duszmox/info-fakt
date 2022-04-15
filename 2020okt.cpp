#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>


using namespace std;

struct sorozat {
    string date;
    string title;
    string episode;
    int length;
    int isWatched;
};
sorozat sorozatok[400];
int fe = 0;
void f1() {
    ifstream in("lista.txt");
    if (!in) {
        cout << "File not found" << endl;
        return;
    }
    string s;
    int i = 0;
    int j = 1;
    while (getline(in,s)) {
        switch (j % 5)
        {
        case 1:
            sorozatok[i].date = s;
            break;
        case 2:
            sorozatok[i].title = s;
            break;
        case 3:
            sorozatok[i].episode = s;
            break;
        case 4:
            sorozatok[i].length = stoi(s.c_str());
            break;
        case 0:
            sorozatok[i].isWatched = stoi(s.c_str());
            i++;
            break;
        
        default:
            break;
        }

        j++;
    }
    in.close();
    for (int i = 0; i < 400; i++) {
        if (sorozatok[i].date == "") {
            fe = i;
            break;
        }
    }
}
void f2() {
    cout << "2. feladat" << fe <<endl;
    int db = 0;
    for (int i = 0; i < fe; i++) {
        if (sorozatok[i].date != "NI") {
            db++;
        }
    }
    cout << "Az ismert datummal rendelkezo epizodok szama: " << db << endl;
}
void f3() {
    cout << "3. feladat" << endl;
    int db = 0;
    for (int i = 0; i < fe; i++) {
        if (sorozatok[i].isWatched == 1) {
            db++;
        }
    }
    cout << "A listaban levo epizodok "<< round(((double)db/fe)*100*100)/100 <<"%-at latta." << endl;
}
void f4() {
    cout << "4. feladat" << endl;
    int perc = 0;
    int ora = 0;
    int nap = 0;
    for (int i = 0; i < fe; i++) {
        if (sorozatok[i].isWatched == 1) {
            perc += sorozatok[i].length;
            while (perc > 60) {
                perc -= 60;
                ora++;
            }            
            while (ora > 24) {
                ora -= 24;
                nap++;
            }
        }
    }

    cout << "A listaban levo epizodok megnezesevel: " << nap << " napot, " << ora << " orat, " << perc << " percet toltott" << endl;
}
void f5() {
    cout << "5. feladat" << endl;
    cout << "Adjon meg egy datumot! Datum= ";
    string d;
    cin >> d;
    for (int i = 0; i < fe; i++) {
        //split date 
        if (sorozatok[i].isWatched != 1  && sorozatok[i].date != "NI") {
            string s = sorozatok[i].date;
            string ev = s.substr(0,4);
            string ho = s.substr(5,2);
            string nap = s.substr(8,2);        
            string ss = d;
            string sev = ss.substr(0,4);
            string sho = ss.substr(5,2);
            string snap = ss.substr(8,2);
            string sss  = sorozatok[i].episode + "      " + sorozatok[i].title;
            if (ev==sev) {
                if (ho==sho) {
                    if (nap==snap) {
                        cout << sss << endl;
                    } else if (nap<snap) {
                        cout << sss << endl;
                    }
                } else if (ho<sho) {
                    cout <<  sss<< endl;
                }
            } else if (ev<sev) {
                cout << sss << endl;
            }
        }
    }
}

void f8() {
    cout << "8. feladat" << endl;
    string s[fe];
    for (int i = 0; i < fe; i++) {
        s[i] = ""sorozatok[i].date;
    }

}

int main( ) {
    f1();
    f2();
    f3();
    f4();
    f5();
    return 0;
}
