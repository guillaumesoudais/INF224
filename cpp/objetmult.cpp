#include <string>
#include "objetmult.h"
using std::string;
using std::ostream;

Objetmult::Objetmult(){}

Objetmult::Objetmult(const string &n, const string &pn){
    this->name = n;
    this->pathname = pn;
}

std::string Objetmult::getName() const{
    return this->name;
}
std::string Objetmult::getPathName() const{
    return this->pathname;
}
void Objetmult::setName(const string &n){
    this->name = n;
}
void Objetmult::setPathName(const string &pn){
    this->pathname = pn;
}

void Objetmult::showObj(ostream& os) const{
    os << "object name: "+this->name+"@"+"object file path: "+
          this->pathname+"\n" << std::endl;;
}
std::string Objetmult::strshowObj() const{
    return ("object name: "+this->name+"\n"+"object file path: "+
          this->pathname+"\n");
}


void Objetmult::play() const{}
