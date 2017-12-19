//
//  main.cpp
//  

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include "objetmult.h"
#include "video.h"
#include "photo.h"
#include "film.h"


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
    Film *f = new Film( 3, "chat","cuteCat.mp4",12);
    int t[3] ={5,3,4};

    f->setChap(t,3);
    f->showObj(std::cout);
    f->play();
    return 0;
}
