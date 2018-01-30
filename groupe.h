#ifndef GROUPE_H
#define GROUPE_H

#include <iostream>
#include <unistd.h>
#include <string>
#include <list>
#include <memory>
#include "objetmult.h"
#include "video.h"
#include "photo.h"
#include "film.h"
#include "datacenter.h"

using ObjetmultPtr = std::shared_ptr<Objetmult>;
typedef std::shared_ptr<Objetmult> ObjetmultPtr;


class Groupe : public std::list<ObjetmultPtr>{
friend class DataCenter;
private:
    std::string name;
    Groupe();
    Groupe(const std::string &n){
        this->name = n;
    }
    ~Groupe() {std::cout << this->name + " détruit\n";}

public:

    std::string getName() const{
        return this->name;
    }

    void displayName(std::ostream& os){
        os << "~~~~~"+this->name+"~~~~~\n";
    }

    void displayAttribute(std::ostream& os){
        std::list<ObjetmultPtr>::iterator i = this->begin();
        while (i != this->end())
        {
            (*i)->showObj(os);
            i++;        }
    }

};

#endif // GROUPE_H
