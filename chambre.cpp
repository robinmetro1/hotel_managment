#include "chambre.h"

Chambre::Chambre(int n,double m,int s,char ty , char t,char v ):Entite(n,m,s),type(ty),taille(t),vue(v)
	{
	}

istream& operator>>(istream& in ,Chambre& c )
{
        //cout <<"\n num chambre "<<endl;
        //in>>c.numC;

    cout<<"Type vue mer M ou gazon (M/G) : "; //type de la vue de la chambre
	in>>c.vue;
	while(c.vue!='M'&& c.vue!='G')
	{
		cout<<"resaisir le type de la vue: mer/gazon (M/G) : ";
		in>>c.vue;
	}
	cout<<"type suite confortable ou chambre normale(S/N) : ";
	in>>c.type;
	while(c.type!='S' && c.type!='N')
	{
		cout<<"type suite confortable ou chambre normale(S/N): ";
		in>>c.type;
	}
	cout<<"Type taille (G/P) : ";
	in>>c.taille;
	while(c.taille!='G'&& c.taille!='P')
	{
		cout<<"resaisir la taille (G/P): ";
		in>>c.taille;
	}
	cout<<"montant: ";
	in>>c.montant;
	while(c.montant<0 || c.montant>20000)
	{
		cout<<"resaisir le montant ";
		in>>c.montant;
	}
	c.statut=0;	//l'état de la chambre
	cout<<"\n la chambre est ajoutée!"<<endl;
	return in;
}

void Chambre::accepter_entite(int num) //saisie
{

    this->num = num;
    cin>>*this;
}


ostream& operator<<(ostream& o,Chambre& c )
{
    o<<"| "<<c.num<<"\t\t|\t\t"<<c.vue<<"\t\t|\t"<<c.type<<"\t\t|\t"<<c.taille<<"\t\t|\t"<<c.montant<<"\t\t|\t";
    if(c.statut==0){o<<"Disponible.\t\t";}
    else{o<<"Reservee.\t\t";}
	o<<endl;
	//o<<"| "<<c.numC<<setw(10)<<c.vue<<setw(10)<<c.type<<setw(10)<<c.taille<<setw(10)<<c.montant<<setw(10)<<c.statut<<endl;

	return o;
}
ostream& operator<<(ostream& o,Chambre* c)
{
    o<<c->num<<setw(10)<<c->vue<<setw(10)<<c->type<<setw(10)<<c->taille<<setw(10)<<c->montant<<setw(10)<<c->statut<<endl;

	return o;
}
istream& operator>>(istream& in ,Chambre* c)
{
    in>>c->num>>c->vue>>c->type>>c->taille>>c->montant>>c->statut;
    return in;
}



Chambre::~Chambre()
{
}
