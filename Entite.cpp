#include "Entite.h"

Entite::Entite(int n,double m,int s):num(n),montant(m),statut(s)
{
}

Entite::~Entite()
{
    //dtor
}



void Entite::accepter_entite(int num)
{

    this->num = num;
    cin>>*this;
}
 istream& operator>>(istream& ,Entite& ){
}
