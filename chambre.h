#ifndef CHAMBRE_H_INCLUDED
#define CHAMBRE_H_INCLUDED
#include<iostream>
 #include<iomanip>
#include "Entite.h"
using namespace std ;

class Chambre : public Entite
{
private:
	char type;				//suite confortable ou chambre normale
	char taille;				//la chambre est de grande G ou petite taille P
	char vue ;				//vue sur mer M ou gazon G


public:
	friend class Hotel;
	virtual void accepter_entite(int num);		//ajouter la chambre
	friend istream& operator>>(istream& ,Chambre& );
	friend ostream& operator<<(ostream& ,Chambre& );		//afficher la chambre sur l'eraan
	friend ostream& operator<<(ostream& ,Chambre* );//ecrire dand le fichier
	friend istream& operator>>(istream& ,Chambre* );//lecture chambre du fichier
	Chambre(int =0,double =0,int =0,char='\0' , char='\0',char='\0');
	~Chambre();


};
#endif // CHAMBRE_H
