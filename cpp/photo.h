#ifndef PHOTO_H
#define PHOTO_H


#include <iostream>
#include <string>
#include "objetmult.h"
#include "datacenter.h"


class Photo : public Objetmult{
friend class DataCenter;
protected:
    long latitude;
    long longitude;
    Photo();
    Photo( const std::string &n, const std::string &pn,long lat, long lon) : Objetmult(n, pn){
        this->latitude = lat;
        this->longitude = lon;
    }


public:
    ~Photo(){std::cout << this->name + " détruit\n";}
    virtual void showObj(std::ostream& os) const override {
        os << "Photo name: "+this->name+"\n"+"Photo file path: "+
              this->pathname+"\n"+ "Photo latitude and longitude: " +
              std::to_string(this->latitude) +", "+
              std::to_string(this->longitude)+"\n" << std::endl;;
    }
    virtual std::string strshowObj() const override{
        return ("       -> "+this->name+"@"+ "latitude :" +
        std::to_string(this->latitude) +"@longitude : " +
                std::to_string(this->longitude))+"@";
    }


    void setLatitude(long l){
        this->latitude = l;
    }
    void setLongitude(long l){
        this->longitude = l;
    }
    long getLatitude() const{
        return this->latitude;
    }
    long getLongitude() const{
        return this->longitude;
    }

    void play() const {
        system(("imagej '"+this->pathname + "' &").c_str());
    }
};
#endif // PHOTO_H
