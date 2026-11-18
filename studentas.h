#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using std::string;
using std::vector;

class studentas {
private:
    string var, pav;
    vector<int> paz;
    int egz;

public:
    studentas() : egz(0){}

    studentas(const studentas& other){
        var=other.var;
        pav=other.pav;
        paz=other.paz;
        egz=other.egz;
    }
    ~Studentas(){}

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

inline double studentas::skaiciuotiVid() const{
    if (paz.empty()){ //Kad nebutu dalybos is nulio
        return 0;
    }
    double vid = accumulate(paz.begin(), paz.end(), 0.0) / paz.size();
    return 0.4 * vid + 0.6 * egz;
}

inline double studentas::skaiciuotiMed() const{
    if (paz.empty()){ //Kad nebutu dalybos is nulio
        return 0;
    }
    std::vector<int> laikinas=paz;
    std::sort(laikinas.begin(), laikinas.end());

    double med;
    if (laikinas.size()%2 == 0) med = (laikinas[laikinas.size()/2-1]+laikinas[laikinas.size()/2])/2.0;
    else med = laikinas[laikinas.size()/2];
    return 0.4 * med + 0.6 * egz;
}

#endif // STUDENTAS_H_INCLUDED
