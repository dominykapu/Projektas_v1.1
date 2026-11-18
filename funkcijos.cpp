#include "funkcijos.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <chrono>
#include <list>
using std::cin;
using std::cout;
using std::left;
using std::right;
using std::setw;
using std::setprecision;
using std::accumulate;
using std::sort;
using std::fixed;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::stringstream;
using std::list;

void Skirstyti3Strat(vector<Studentas>& grupe, vector<Studentas>& vargsiukai, vector<Studentas>& galvociai){
    auto it=std::stable_partition(grupe.begin(), grupe.end(), [](const Studentas& s) {return s.skaiciuotiVid()>=5.0; });
            vargsiukai.assign(it, grupe.end());
            grupe.erase(it, grupe.end());
            galvociai=grupe;
}
void Skirstyti3Strat(list<Studentas>& grupe, list<Studentas>& vargsiukai, list<Studentas>& galvociai){
//    auto it=grupe.begin();
//            while (it!=grupe.end()){
//                if (it->skaiciuotiVid()<5.0){
//                    vargsiukai.splice(vargsiukai.end(), grupe, it++);
//                }
//                else{
//                    ++it;
//                }
//            }
//            galvociai=grupe;
auto it=std::stable_partition(grupe.begin(), grupe.end(), [](const Studentas& s) {return s.skaiciuotiVid()>=5.0; });
            vargsiukai.assign(it, grupe.end());
            grupe.erase(it, grupe.end());
            galvociai=grupe;

}
void Rikiuoti(vector<Studentas>& grupe, int rikiuoti){
    if (rikiuoti == 1){
        sort(grupe.begin(), grupe.end(), [](const Studentas& a, const Studentas& b){
        return a.Pavarde() < b.Pavarde();
    });
    }
    if (rikiuoti == 2){
        sort(grupe.begin(), grupe.end(), [](const Studentas& a, const Studentas& b){
        return a.Vardas() < b.Vardas();
    });
    }
    if (rikiuoti == 3){
        sort(grupe.begin(), grupe.end(), [](const Studentas& a, const Studentas& b){
        return a.skaiciuotiVid() < b.skaiciuotiVid();
    });
    }
}

void Rikiuoti(list<Studentas>& grupe, int rikiuoti){
    if (rikiuoti == 1){
        grupe.sort([](const Studentas& a, const Studentas& b){
        return a.Pavarde() < b.Pavarde();
    });
    }
    if (rikiuoti == 2){
        grupe.sort([](const Studentas& a, const Studentas& b){
        return a.Vardas() < b.Vardas();
    });
    }
    if (rikiuoti == 3){
        grupe.sort([](const Studentas& a, const Studentas& b){
        return a.skaiciuotiVid() < b.skaiciuotiVid();
    });
    }
}
void GeneruotiFaila(int kiek){
    auto pradzia=std::chrono::high_resolution_clock::now();

    string failoPav = "studentai" + std::to_string(kiek) + ".txt";
    ofstream f(failoPav);

    int nd=5;
    f<<"Vardas Pavarde";
    for (int i=1; i<=nd; i++) f<<" ND"<<i;
    f<<" Egz.\n";
    for (int i=1; i<=kiek; i++){
        f<<"Vardas"<<i<<" Pavarde"<<i;
        for (int j=0; j<nd; j++) f<<" "<<rand()%10+1;
        f<<" "<<rand()%10+1 <<"\n";
    }
    f.close();

    auto pabaiga=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas=pabaiga-pradzia;

    cout<<"Failo kurimo laikas: "<<laikas.count()<<"\n";
}

