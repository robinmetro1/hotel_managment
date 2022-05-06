#include "Salle.h"
#include<iostream>
using namespace std;
Salle::Salle()
{
    //ctor
}

Salle::~Salle()
{
    //dtor
}
ostream& operator<<(ostream& o ,Salle& s)
{
   //  o<<endl<<"nom :"<<s.nom<<endl<<"capacite :"<<s.capacite<<endl<<"prix :"<<s.montant<<endl<<s.statut<<endl;

   // o<<"| "<<s.num<<".\t\t|\t\t"<<s.nom<<"\t\t|\t\t"<<s.type<<"\t\t|\t"<<s.capacite<<"\t\t|\t"<<s.montant<<"\t\t|\t";

    o<<"| "<<s.num<<"\t\t\t";
	o<<"| "<<left<<setfill(' ')<<setw(30)<<s.nom;
	o<<"| "<<s.type<<"\t\t\t";
	o<<"| "<<s.capacite<<"\t\t\t";
	o<<"| "<<s.montant<<"\t\t\t";
    if(s.statut==0){o<<"|\tDisponible.\t\t";}
    else{o<<"|\tReservee.\t\t";}
	o<<endl;

	return o;
}
ostream& operator<<(ostream& o,Salle* s)
{
    o<<s->num<<setw(10)<<s->nom<<setw(10)<<s->type<<setw(10)<<s->capacite<<setw(10)<<s->montant<<setw(10)<<s->statut<<endl;

	return o;
}

istream& operator>>(istream& in  ,Salle* s){
    in>>s->num>>s->nom>>s->type>>s->capacite>>s->montant>>s->statut;
    return in;
}


istream& operator>>(istream& in  ,Salle& s)
{
        //cout <<"\n num chambre "<<endl;
        //in>>c.numC;

    cout<<"Nom de la salle : ";
	in>>s.nom;
	cout<<"Type salle Conference/Mariage (C/M) : ";
	in>>s.type;
	while(s.type!='C' && s.type!='M')
	{
		cout<<"Type salle Conference/Mariage (C/M) : ";
		in>>s.type;
	}
	cout<<"Capacite (en personne): ";
	in>>s.capacite;
	cout<<"Prix location: ";
	in>>s.montant;
	while(s.montant<0 || s.montant>20000)
	{
		cout<<"Resaisir le prix ";
		in>>s.montant;
	}
	s.statut=0;	//l'état de la salle
	cout<<"\n La salle est ajoutee!"<<endl;
	return in;
}

void Salle::accepter_entite(int num)
{

    this->num = num;
    cin>>*this;
}
