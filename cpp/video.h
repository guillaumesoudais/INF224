#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>
#include "objetmult.h"
#include "datacenter.h"


class Video : public Objetmult{
friend class DataCenter;
protected:
    int duree;
    Video();
    Video(const std::string &n, const std::string &pn,int d) : Objetmult(n, pn){
        this->duree= d;
    }


public:
    ~Video(){std::cout << this->name + " détruit\n";}
    virtual void showObj(std::ostream& os) const override {
        os << "video name: "+this->name+"\n"+"video file path: "+
              this->pathname+"\n"+ "video length: " +
              std::to_string(this->duree) +"\n" << std::endl;;
    }
    virtual std::string strshowObj() const override{
        return ("video name: "+this->name+"@"+"video file path: "+
                this->pathname+"@"+ "video length: " +
                std::to_string(this->duree) +"\n");
    }

    int getDuree() const{
        return this->duree;
    }

    void setDuree(int d){
        this->duree = d;
    }

    void play() const override{
        system(("mpv '"+this->pathname + "' &").c_str());
    }
};

#endif // VIDEO_H
