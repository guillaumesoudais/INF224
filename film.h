#ifndef FILM_H
#define FILM_H

#include <iostream>
#include <string>
#include "video.h"


class Film : public Video{
private:
    int nb_chap;
    int * chap_len;
public:
    Film();
    Film(int nb, std::string n,  std::string pn,int d) : Video(n, pn, d){
        this->nb_chap= nb;
    ~Film;
    }

    virtual void showObj(std::ostream& os) const override {
        os <<  "There are " + std::to_string(this->nb_chap)
               +" chapters in this movie" << std::endl;
        for(int i =0;i < nb_chap;i++){
            os <<  "Chapter " + std::to_string(i)
                   +" : "+ std::to_string(chap_len[i]) + "s"<< std::endl;
        }
        os <<  "\n" << std::endl;
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
