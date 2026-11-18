#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
using std::string;
using std::vector;

class Studentas {
private:
    string var, pav;
    vector<int> paz;
    int egz;

public:
    //konstruktoriai
    Studentas() : egz(0) {}
    Studentas(std::istream& is);
    Studentas(const Studentas& other);
    //destruktorius
    ~Studentas(){}

    std::istream& readStudent(std::istream& is);

    //geteriai
    inline string Vardas() const {return var;}
    inline string Pavarde() const {return pav;}
    inline vector<int> Pazymiai() const {return paz;}
    inline int Egzaminas() const {return egz;}

    //seteriai
    void setVardas(string v) {var=v;}
    void setPavarde(string p) {pav=p;}
    void setPazymiai(vector<int> p) {paz=p;}
    void setEgzaminas(int e) {egz=e;}

    double skaiciuotiVid() const;
    double skaiciuotiMed() const;
    };

#endif // STUDENTAS_H_INCLUDED
