#include <iostream>
#include <fstream>

using namespace std;

struct aminotip {
    string name_short;
    char betu;
    int C;
    int H;
    int O;
    int N;
    int S;
    int tomeg;
};


const int AMINODB = 20;
typedef aminotip aminotombtip[AMINODB+1];
aminotombtip a;
int bsadb;
ofstream fki;



void f1() {
    cout << "Első feladat" << endl;
    //read data from aminosav.txt and store it in a aminotombtip
    ifstream file("aminosav.txt");
    if (file.is_open()) {
        for (int i = 0; i < AMINODB; i++) {
            file >> a[i].name_short >> a[i].betu >> a[i].C >> a[i].H >> a[i].O >> a[i].N >> a[i].S;
        }
    }
    file.close();
    //print the data
    for (int i = 0; i < AMINODB; i++) {
        cout << a[i].name_short << " " << a[i].betu << " " << a[i].C << " " << a[i].H << " " << a[i].O << " " << a[i].N << " " << a[i].S << endl;
    }
}
void f2() {
    cout << "Második feladat" << endl;
    for (int i = 0; i < AMINODB; i++) {
        a[i].tomeg = a[i].C*12 + a[i].H*1 + a[i].O*16 + a[i].N*14 + a[i].S*32;
    }
}
void f3() {
    cout << "Harmadik feladat" << endl;
    //sort the aminotip by tomeg
    for (int i = 0; i < AMINODB; i++) {
        for (int j = i+1; j < AMINODB; j++) {
            if (a[i].tomeg > a[j].tomeg) {
                aminotip temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "Negyedik feladat" << endl;
    //print aminotip name_short and tomeg
    for (int i = 0; i < AMINODB; i++) {
        cout << a[i].name_short << " " << a[i].tomeg << endl;
    }
    //print aminotip name_short and tomeg to eredmeny.txt with fstream
    if (fki.is_open()) {
        for (int i = 0; i < AMINODB; i++) {
            fki << a[i].name_short << " " << a[i].tomeg << endl;
        }
    }
    
}

void f4() {
    cout << "Negyedik feladat" << endl;
    int C = 0;
    int H = 0;
    int O = 0;
    int N = 0;
    int S = 0;
    ifstream file("bsa.txt");
    //get the length of the file
    file.seekg(0, ios::end);
    bsadb = file.tellg();
    
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            //find the aminotip corresponding to the line and substract one O and two H AMINODB-1 times

            for (int i = 0; i < AMINODB; i++) {
                if (line.find(a[i].betu) != string::npos) {
                    C += a[i].C;
                    H += a[i].H-2;
                    O += a[i].O-1;
                    N += a[i].N;
                    S += a[i].S;

                }

            }
            
        }
        H++;
        H++;
        O--;
    }
    file.close();
    cout << "C: " << C << " H: " << H << " O: " << O << " N: " << N << " S: " << S << endl;
    if (fki.is_open()) {
        fki << "C: " << C << " H: " << H << " O: " << O << " N: " << N << " S: " << S << endl;
    }
}

void f5() {
   cout << "Ötödik feladat" << endl;
   int i=0, lu, le, lh=-1, e=1;
   while (i<=bsadb) {
       if(bsa[i]=='Y' || bsa[i]=='W' || bsa[i] == "F") {
           if(i-e+1>lh) {
               le=e; lu=i; lh=i-e+1;
           }
           e=i+1;
        
       }
         i++;

   }
   if(lh == -1) cout << "Nem hasadott meg bsa-t" << endl;
   else cout << "A legnagyobb hasadasi hossz: " << lh << " a hasadasi pontok: " << lu << "-" << le << endl;
   if (lh == -1) cout << "Nem hasadott meg bsa-t" << endl;
   else fki << "A legnagyobb hasadasi hossz: " << lh << " a hasadasi pontok: " << lu << "-" << le << endl;
}

int main()
{
    f1();
    f2();
    fki.open("eredmeny.txt");
    f3();
    f4();
    f5();
    fki.close();

    return 0;
}