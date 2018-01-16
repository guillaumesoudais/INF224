#ifndef DATACENTER_H
#define DATACENTER_H

#include <iostream>
#include <unistd.h>
#include <string>
#include <list>
#include <memory>
#include <vector>
#include "objetmult.h"
#include "video.h"
#include "photo.h"
#include "film.h"

using ObjetmultPtr = std::shared_ptr<Objetmult>;
typedef std::shared_ptr<Objetmult> ObjetmultPtr;

class dataCenter
{
private:
    std::string name;
    std::map<std::string name , ObjetmultPtr obj> objets;
    std::map<std::string name , Group gr> groupes;
public:
    dataCenter();

    void createPic(const std::string &n, const std::string &pn,long lat, long lon){
    }
    void createVid(const std::string &n, const std::string &pn,int d){
    }
    void createMov(int nb, const std::string &n, const std::string &pn,int d){
    }
    void createGr(const std::string &n){
    }

};

#endif // DATACENTER_H
