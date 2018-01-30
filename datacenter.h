#ifndef DATACENTER_H
#define DATACENTER_H

#include <iostream>
#include <unistd.h>
#include <string>
#include <list>
#include <memory>
#include <vector>
#include <map>

#include "objetmult.h"
#include "video.h"
#include "photo.h"
#include "film.h"
#include "groupe.h"

using ObjetmultPtr = std::shared_ptr<Objetmult>;
typedef std::shared_ptr<Objetmult> ObjetmultPtr;

class DataCenter
{
private:
    std::string name;
    std::map<std::string  , ObjetmultPtr > objets;
    std::map<std::string  , Groupe *> groupes;
public:
    DataCenter(const std::string &n){this->name = n;}

    std::shared_ptr<Photo>  createPic(const std::string &name, const std::string &pathname,long lat, long lon){
        std::shared_ptr<Photo> p (new Photo(name, pathname, lat, lon));
        objets[name] = p;
        return p;
    }

    std::shared_ptr<Video> createVid(const std::string &name, const std::string &pathname,int d){
        std::shared_ptr<Video> v (new Video(name,pathname, d));
        objets[name] = v;
        return v;
    }

    std::shared_ptr<Film> createMov(int nb, const std::string &name, const std::string &pathname,int d){

         this->objets[n] = (new Film( nb, name, pathname, d));
    }
    std::shared_ptr<Groupe> createGr(const std::string &name){
         this->groupes[n] = (new Group(name));


    ObjetmultPtr searchO(const std::string n){
        if(this->objets.count(n)!=0){
            return this->objets[n];
        }
        else return nullptr;
    }

    Groupe * searchG(const std::string n){
        if(this->groupes.count(n)!=0){
            return groupes[n];
        }
        else return nullptr;
    }

    void play(const std::string n){
        ObjetmultPtr * op = searchO(n);
        if(op != nullptr) op->play();
    }
};

#endif // DATACENTER_H
