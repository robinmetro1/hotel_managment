#ifndef ENTITE_H
#define ENTITE_H
#include<iostream>

using namespace std;

class Entite
{
    public:
        friend class Hotel;
        Entite(int=0,double=0,int=0);
        virtual ~Entite();
        virtual void accepter_entite(int num);
        friend istream& operator>>(istream& ,Entite& );

protected:
    int num;
    double montant; //montant d'une nuite
	int statut; //entite est reservee ou pas
};

#endif // ENTITE_H
