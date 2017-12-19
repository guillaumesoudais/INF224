#ifndef OBJETMULT_H
#define OBJETMULT_H

#include <iostream>

class Objetmult
{
protected:
    std::string name; // nom de l'objet multimédia.
    std::string pathname; // nom du fichier associé à l'objet.
public:
    Objetmult(); // Constructeur sans argument.
    Objetmult(std::string n, std::string pn); // Constructeur avec arguments.
    ~Objetmult(); // Déstructeur.
    std::string getName() const; // Accesseur pour le nom de l'objet.
    std::string getPathName() const; // Accesseur pour le fichier associé à l'objet.
    void setName( std::string ) ; //Modifieur du nom de l'objet.
    void setPathName( std::string ) ; // Modifieur du fichier associé à l'objet.
    virtual void showObj(std::ostream&) const; //Affiche les variables de l'objet.
    virtual void play() const;
};

#endif // OBJETMULT_H
