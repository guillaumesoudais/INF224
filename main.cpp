//
//  main.cpp
//  

#include <iostream>
#include <list>
#include <unistd.h>
#include <stdio.h>
#include <memory.h>
#include "objetmult.h"
#include "video.h"
#include "photo.h"
#include "film.h"
#include "groupe.h"
#include "datacenter.h"


int main(int argc, char* argv[]) {

    std::cout << "Hello World" << std::endl;
    //    Objetmult *obj_t[4];
    //    obj_t[0] = new Photo("chat","./chat.jpg",700,394);
    //    obj_t[1] = new Video("surprised cat","cuteCat.mp4",12);
    //    obj_t[2] = new Photo("souris","/dev/null",1234,383);
    //    obj_t[3] = new Photo("chat","./chat.jpg",5012,241);
    //    for(int i = 0;i<4;i++){
    //        obj_t[i]->play();
    //        obj_t[i]->showObj(std::cout);
    //        sleep(1);
    //    }
    //    delete(obj_t);
//    Film *f = new Film( 3, "Chat","cuteCat.mp4",12);
//    Groupe *g = new Groupe("film_group");

//    int t[3] = {5,3,4};
//    f->setChap(t,3);
//    f->showObj(std::cout);
//        f->play();
//    g->displayName(std::cout);
//    g->push_front(std::make_shared<Objetmult>(*f));
//    g->push_front(std::make_shared<Objetmult>(*f));
//    g->push_front(std::make_shared<Objetmult>(*f));
//    g->displayAttribute(std::cout);
//    delete g;

    DataCenter * datas = new DataCenter("those sweet datas");

    return 0;
}
