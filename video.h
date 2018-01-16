#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>
#include "objetmult.h"

class Video : public Objetmult{
private:
    int duree;
public:
    Video();
    Video(const std::string &n, const std::string &pn,int d) : Objetmult(n, pn){
        this->duree= d;
    }
    ~Video(){std::cout << this->name + " détruit\n";}

    virtual void showObj(std::ostream& os) const override {
        os << "video name: "+this->name+"\n"+"video file path: "+
              this->pathname+"\n"+ "video length: " +
              std::to_string(this->duree) +"\n" << std::endl;;
    }

    int getDuree() const{
        return this->duree;
    }

    void setDuree(int d){
        this->duree = d;
    }

    void play() const override{
        system(("mpv "+this->pathname + " &").c_str());
    }
};

#endif // VIDEO_H
