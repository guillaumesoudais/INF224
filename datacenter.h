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

#include <sstream>
#include "tcpserver.h"

using namespace std;
using namespace cppu;

using ObjetmultPtr = shared_ptr<Objetmult>;
typedef shared_ptr<Objetmult> ObjetmultPtr;

class DataCenter
{
protected:
    string name;
    map<string  , ObjetmultPtr > objets;
    map<string  , shared_ptr<Groupe>> groupes;
public:
    DataCenter(const string &n){this->name = n;}

    shared_ptr<Photo>  createPic(const string &name, const string &pathname,long lat, long lon){
        shared_ptr<Photo> p (new Photo(name, pathname, lat, lon));
        objets[name] = p;
        return p;
    }

    shared_ptr<Video> createVid(const string &name, const string &pathname,int d){
        shared_ptr<Video> v (new Video(name,pathname, d));
        objets[name] = v;
        return v;
    }

    shared_ptr<Film> createMov(int nb, int *chap_len,const string &name, const string &pathname,int d){
        shared_ptr<Film> f (new Film(nb, chap_len, name,pathname, d));
        objets[name] = f;
        return f;
    }

    shared_ptr<Groupe> createGr(const string &name){
        shared_ptr<Groupe> g (new Groupe(name));
        groupes[name] = g;
        return g;
    }

    ObjetmultPtr searchO(const string n){
        if(this->objets.count(n)!=0){
            return this->objets[n];
        }
        else return nullptr;
    }

    shared_ptr<Groupe> searchG(const string &name){
        if(this->groupes.count(name)!=0){
            return groupes[name];
        }
        else return nullptr;
    }

    void play(const string &name){
        ObjetmultPtr op = searchO(name);
        if(op != nullptr) op->play();
    }
    void showObj(const string &name){
        ObjetmultPtr op = searchO(name);
        if(op != nullptr) op->showObj(std::cerr);
    }
    string strshowObj(const string &name){
        ObjetmultPtr op = searchO(name);
        if(op != nullptr) return(op->strshowObj());
        return "";
    }


    bool processRequest(TCPConnection& cnx, const string& request, string& response)
    {
      cerr << "\nRequest: '" << request << "'" << endl;
      stringstream ss;
      ss << request;

      // 1) pour decouper la requête:
      // on peut par exemple utiliser stringstream et getline()
        string c;
        string obj;


      getline(ss, c, ' ');
      getline(ss, obj, ' ');
      // 2) faire le traitement:
      // - si le traitement modifie les donnees inclure: TCPLock lock(cnx, true);
      // - sinon juste: TCPLock lock(cnx);
      if(c=="play"){
          play(obj);
          cerr<<obj<<"lu"<<endl;
      }
      if (c=="look"){
            response = strshowObj(obj);
            showObj(obj);
            cerr<<obj<<"montré"<<endl;
      }
      if (c=="quit"){
            cerr<<false<<endl;
      }

      // 3) retourner la reponse au client:
      // - pour l'instant ca retourne juste OK suivi de la requête
      // - pour retourner quelque chose de plus utile on peut appeler la methode print()
      //   des objets ou des groupes en lui passant en argument un stringstream
      // - attention, la requête NE DOIT PAS contenir les caractères \n ou \r car
      //   ils servent à délimiter les messages entre le serveur et le client

      // renvoyer false si on veut clore la connexion avec le client
      return true;
    }
};

#endif // DATACENTER_H
