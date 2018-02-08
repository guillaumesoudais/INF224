//
//  main.cpp
//  

#include <iostream>
#include <list>
#include <unistd.h>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <sstream>
#include "tcpserver.h"
#include "datacenter.h"
#define PORT 3331

using namespace std;
using namespace cppu;

int main(void) {
    //instanciation de la base de donnée
    int t[3] = {5,3,4};
    DataCenter * datas = new DataCenter("those sweet datas");
    datas->createPic("photo_chat","./media/chat.jpg",5012,241);
    datas->createMov(3, t, "Chat_mignon","./media/cuteCat.mp4",12);

    //demarage du serveur
    // cree le TCPServer
    shared_ptr<TCPServer> serv (new TCPServer());
    // le serveur appelera cette méthode chaque fois qu'il y a une requête
    serv->setCallback(*datas, &DataCenter::processRequest);

    // lance la boucle infinie du serveur
    cout << "Starting Server on port " << PORT << endl;
    int status = serv->run(PORT);

    // en cas d'erreur
    if (status < 0) {
      cerr << "Could not start Server on port " << PORT << endl;
      return 1;
    }
    return 0;
}
