#include "studentas.h"
#include <algorithm>
#include <numeric>

Studentas::Studentas(std::istream& is) : egz(0) {
    readStudent(is);
}
Studentas::Studentas(const Studentas& other){
        var=other.var;
        pav=other.pav;
        paz=other.paz;
        egz=other.egz;
    }
std::istream& Studentas::readStudent(std::istream& is){
        is>>var>>pav;
        paz.clear();
        int p;
        while (is>>p){
            paz.push_back(p);
        }
        if (!paz.empty()){
            egz=paz.back();
            paz.pop_back();
        }
        is.clear();
        return is;
}

double Studentas::skaiciuotiVid() const{
    if (paz.empty()){ //Kad nebutu dalybos is nulio
        return 0;
    }
    double vid = std::accumulate(paz.begin(), paz.end(), 0.0) / paz.size();
    return 0.4 * vid + 0.6 * egz;
}

double Studentas::skaiciuotiMed() const{
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
