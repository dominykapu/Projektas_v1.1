#ifndef FUNKCIJOS_H_INCLUDED
#define FUNKCIJOS_H_INCLUDED

#include <vector>
#include <list>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <algorithm>
#include "studentas.h"
using std::vector;
using std::list;
using std::cin;
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::stringstream;
using std::left;
using std::right;
using std::setw;
using std::fixed;
using std::setprecision;

void Rikiuoti(vector<Studentas>& grupe, int rikiuoti);
void Rikiuoti(list<Studentas>& grupe, int rikiuoti);
void GeneruotiFaila(int kiek);
void Skirstyti3Strat(vector<Studentas>& grupe, vector<Studentas>& vargsiukai, vector<Studentas>& galvociai);
void Skirstyti3Strat(list<Studentas>& grupe, list<Studentas>& vargsiukai, list<Studentas>& galvociai);

template <class T>
void IvestiStudenta(T& grupe){
    Studentas A;
    string v;
    string p;
    int n;
    int e;
    vector<int> paz;

    cout << "Iveskite varda: ";
    cin >> v;
    A.setVardas(v);
    cout << "Iveskite pavarde: ";
    cin >> p;
    A.setPavarde(p);

    while (true){
        char kl;
        while (true){
            cout << "Iveskite semestro pazymi: ";
            cin >> n;

            if (cin.fail()){
                cout << "Klaida! Iveskite skaiciu.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if (n < 1 || n > 10){
                cout << "Klaida! Pazymys turi buti nuo 1 iki 10.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else{
                paz.push_back(n);
                break;
            }
        }
        cout << "Ar studentas turi dar pazymiu? t/n ";
        cin >> kl;
        if (kl == 'n' || kl == 'N'){
            break;
        }
    }
    A.setPazymiai(paz);

    while (true){
        cout <<"Iveskite egzamina: ";
        cin >> e;

        if (cin.fail()){
            cout <<"Klaida! Iveskite skaiciu.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (e<1 || e>10){
            cout <<"Klaida! Pazymys turi buti nuo 1 iki 10.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else{
            A.setEgzaminas(e);
            break;
        }
    }
    grupe.push_back(A);

    cout<<"Studentas: "<<A.Vardas()<<" "<<A.Pavarde()<<"\n";
    cout<<"Atminties adresas: "<<&grupe.back()<<"\n";
}
template <class T>
void GeneruotiPazymi(T& grupe){
    Studentas A;
    string v, p;
    int kiek;
    vector<int> paz;

    cout <<"Iveskite varda: ";
    cin >> v;
    A.setVardas(v);
    cout <<"Iveskite pavarde: ";
    cin >> p;
    A.setPavarde(p);

    while (true){
        cout <<"Kiek generuoti pazymiu?: ";
        cin >> kiek;

        if (cin.fail()){
            cout <<"Klaida! Iveskite skaiciu.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (kiek<1){
            cout <<"Klaida! Pazymiu turi buti bent vienas.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else{
            break;
        }
    }
    for (int i=0; i<kiek; i++){
        int pazymys=rand()%10+1;
        paz.push_back(pazymys);
    }

    A.setPazymiai(paz);
    A.setEgzaminas(rand()%10+1);
    grupe.push_back(A);
}
template <class T>
void Nuskaitymas(T& grupe){
    string failoPav;
    cout << "Iveskite failo pavadinima: ";
    cin >> failoPav;
    ifstream f(failoPav);

    auto pradzia=std::chrono::high_resolution_clock::now();

    if (!f){
        cout << "Nepavyko atidaryti failo.\n";
        return;
    }
    grupe.clear();

    string antraste;
    getline(f, antraste);

    string eilute;
    while (getline(f, eilute)){
        stringstream ss(eilute);
        Studentas A(ss);
        if (A.Pazymiai().empty()){
                cout<<"Klaida faile, eilute praleista: "<<eilute<<"\n";
        continue;
        }
        grupe.push_back(A);
    }
    auto pabaiga=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas=pabaiga-pradzia;

    cout<<"Nuskaityta studentu: "<<grupe.size()<<"\n";
    cout<<"Nuskaitymo laikas: "<<laikas.count()<<"\n";
    f.close();
}
template <class T>
void Spausdinti(T& grupe, int pasirinkimas, int rikiuoti){
    auto pradzia=std::chrono::high_resolution_clock::now();

    Rikiuoti(grupe, rikiuoti);

    auto pabaiga=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas=pabaiga-pradzia;
    cout<<"Rikiavimo laikas: "<<laikas.count()<<"\n";

    bool RodytiVid = (pasirinkimas == 1 || pasirinkimas == 3);
    bool RodytiMed = (pasirinkimas == 2 || pasirinkimas == 3);

    cout <<"\nStudento duomenys: \n";
    cout <<"|"<<left<<setw(15)<<"Vardas"<<"|"<<left<<setw(20)<<"Pavarde";
    if (RodytiVid == true) cout<<"|"<<right<<setw(17)<<"Galutinis (Vid.)";
    if (RodytiMed == true) cout<<"|"<<right<<setw(17)<<"Galutinis (Med.)";
    cout <<"|\n";

    int br=15+20+1; // Bruksniai
    if (RodytiVid == true) br+=17+1;
    if (RodytiMed == true) br+=17+1;

    cout <<"|";for (int i=0; i<br; i++) cout<<"-"; cout<<"|\n";

    for (auto B : grupe)
    {
        cout <<"|"<<left<<setw(15)<<B.Vardas()<<"|"<<left<<setw(20)<<B.Pavarde();
        if (RodytiVid == true) cout <<"|"<<right<<setw(17)<<fixed<<setprecision(2)<<B.skaiciuotiVid();
        if (RodytiMed == true) cout <<"|"<<right<<setw(17)<<fixed<<setprecision(2)<<B.skaiciuotiMed();
        cout <<"|\n";
    }
}
template <class T>
void SkirstytiStudentus(T& grupe, int rikiuoti, string konteineris, int strategija){

    T vargsiukai;
    T galvociai;
    //Skirstymo laiko skaiciavimas
    auto pradzia=std::chrono::high_resolution_clock::now();

    //1 strategija
    if (strategija==1){
        for (auto A : grupe){
        if (A.skaiciuotiVid()<5.0) vargsiukai.push_back(A);
        else galvociai.push_back(A);
        }
    }
    //2 strategija
    else if (strategija==2){
        for (auto it=grupe.begin(); it!=grupe.end();){
            if (it->skaiciuotiVid()<5.0){
                vargsiukai.push_back(*it);
                it=grupe.erase(it);
            }
            else{
                ++it;
            }
        }
        galvociai=grupe; //like studentai galvociai
    }
    //3 strategija
    else if (strategija==3){
        Skirstyti3Strat(grupe, vargsiukai, galvociai);
    }
    auto pabaiga=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> skirstymoLaikas=pabaiga-pradzia;

    //Rusiavimo laiko skaiciavimas
    pradzia=std::chrono::high_resolution_clock::now();

    Rikiuoti(vargsiukai, rikiuoti);
    Rikiuoti(galvociai, rikiuoti);

    pabaiga=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> rikiavimoLaikas=pabaiga-pradzia;

    //Isvedimo i failus laiko skaiciavimas
    pradzia=std::chrono::high_resolution_clock::now();

    string vargsiukaiPav="vargsiukai_"+konteineris+".txt";
    string galvociaiPav="galvociai_"+konteineris+".txt";

    ofstream vargsiukaiFailas(vargsiukaiPav);
    ofstream galvociaiFailas(galvociaiPav);

    vargsiukaiFailas<<left<<setw(15)<<"Vardas"<<setw(20)<<"Pavarde"<<"Galutinis\n";
    galvociaiFailas<<left<<setw(15)<<"Vardas"<<setw(20)<<"Pavarde"<<"Galutinis\n";

    for (auto A : vargsiukai){
        vargsiukaiFailas<<left<<setw(15)<<A.Vardas()<<setw(20)<<A.Pavarde()<<fixed<<setprecision(2)<<A.skaiciuotiVid()<<"\n";
    }
    for (auto A : galvociai){
        galvociaiFailas<<left<<setw(15)<<A.Vardas()<<setw(20)<<A.Pavarde()<<fixed<<setprecision(2)<<A.skaiciuotiVid()<<"\n";
    }
    vargsiukaiFailas.close();
    galvociaiFailas.close();

    pabaiga=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> isvedimoLaikas=pabaiga-pradzia;

    cout<<"Studentai suskirstyti.\n";
    cout<<" Irasu skirstymo i dvi grupes laikas: "<<skirstymoLaikas.count()<<"\n";
    cout<<" Irasu rikiavimo laikas: "<<rikiavimoLaikas.count()<<"\n";
    cout<<" Irasu isvedimo i failus laikas: "<<isvedimoLaikas.count()<<"\n";
}

#endif // FUNKCIJOS_H_INCLUDED
