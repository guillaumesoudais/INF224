#ifndef FILM_H
#define FILM_H

#include <iostream>
#include <string>
#include "video.h"
#include "datacenter.h"



class Film : public Video{
friend class DataCenter;
protected:
    int nb_chap;
    int * chap_len;
    Film();
    Film(int nb, int * _chap_len,const std::string &n, const std::string &pn,int d) : Video(n, pn, d){
        this->nb_chap= nb;
        this->chap_len = _chap_len;
    }

public:
    ~Film() {delete[] this->chap_len;
            std::cout << this->name + " détruit\n";}

    virtual void showObj(std::ostream& os) const override {
        os <<  "->" +this->getName()+"@ il y a " + std::to_string(this->nb_chap)
               +" chapitres dans ce film" << std::endl;
        for(int i =0;i < nb_chap;i++){
            os <<  "Chapitre " + std::to_string(i)
                   +" : "+ std::to_string(chap_len[i]) + "s"<< std::endl;
        }
        os <<  "\n" << std::endl;
    }
    virtual std::string strshowObj() const override{
        std::string s = "      ->" +this->getName()+"@il y a " + std::to_string(this->nb_chap)
                        +" chapitres dans ce film@" ;
        for(int i =0;i < nb_chap;i++){
                     s+="Chapitre " + std::to_string(i+1)
                                   +" : "+ std::to_string(chap_len[i]) + "s@";
        }
        return (s);
    }

    void setNbChap(int n){
        this->nb_chap = n;
    }

    void setChap(int * t, int n){
        if (n!=0){
            this->nb_chap = n;
            this->chap_len = t;
        }
        else{
            if(t!=nullptr){
                throw std::string("ERREUR : Le nombre de chapitre ne convient pas.");
            }
        }
    }

    int getNbChap(){
        return this->nb_chap;
    }

    int * getChap() {
        return this->chap_len;
    }
};

#endif // FILM_H
