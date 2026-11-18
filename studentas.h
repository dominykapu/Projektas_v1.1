#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED
#include <string>
#include <vector>
using std::string;
using std::vector;

class studentas {
private:
    string var, pav;
    vector<int> paz;
    int egz;

public:
    double galutinis;

    inline string Vardas() const {return var;}
    inline string Pavarde() const {return pav;}
    inline vector<int> Pazymiai() const {return paz;}
    inline int Egzaminas() const {return egz;}

    void setVardas(string v) {var=v;}
    void setPavarde(string p) {pav=p;}
    void setPazymiai(vector<int> p) {paz=p;}
    void setEgzaminas(int e) {egz=e;}
    };

#endif // STUDENTAS_H_INCLUDED
