#ifndef SALLE_H
#define SALLE_H


#include <iomanip>
#include"Entite.h"
#include<string>
#include<iostream>
using namespace std;

class Salle: public Entite
{
    public:
        Salle();
        virtual ~Salle();
    friend ostream& operator<<(ostream&  ,Salle& );
    friend istream& operator>>(istream&  ,Salle& );
    friend ostream& operator<<(ostream&  ,Salle* );
    friend istream& operator>>(istream&  ,Salle* );
    virtual void accepter_entite(int num);



private:
        int capacite;
        char type;
        string nom;
};

#endif // SALLE_H
