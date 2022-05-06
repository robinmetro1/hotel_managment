#include"client.h"
Client::Client()
{
		dureeSejour=0;
		avance_payement=0;
		facture=0;
		num_reserv=0;
		statut=0;
		chambre=0;
}



istream& operator>>(istream& i, Client& c){
    cout<<"Entrer le nom complet du client: ";
	getline(i, c.nom);
	getline(i, c.nom);
	cout<<"Enter l'adresse du client: ";
	getline(i,c.adresse);
	flag:
	cout<<"Entrer le numero de telephone: ";
	i>>c.telephone;
	for(int i=0;i<(c.telephone.length());i++)	//PHONE NUMBER VALIDATIONS
  	{									//PHONE NUMBER NEEDS TO BE ALL DIGITS AND 10 IN LENGTH
		if(!isdigit(c.telephone[i]))
		{
			cout<<"Le numero doit etre en chiffre.\n";
			goto flag;
		}
  	}
  	if(c.telephone.length()!=8)		//PHONE LENGTH VALIDATIONS
  	{
  	  cout<<"Le numero doit avoir 8 chiffre.\n";
  	  goto flag;
 	 }
}

ostream& operator<<(ostream& o,Client& c){
    o<<c.num_reserv<<"\t\t";
	o<<"| "<<left<<setfill(' ')<<setw(30)<<c.nom;
	o<<"| "<<c.telephone<<"\t\t\t";
	o<<"| "<<left<<setfill(' ')<<setw(30)<<c.adresse;
	o<<"| "<<c.chambre<<"\t\t\t";
	if(c.statut==1){cout<<"|\t\t-\t\t|"<<endl;}
	else{cout<<"|\tCHECKED OUT.\t\t|"<<endl;}
}
ostream& operator<<(ostream& o,Client* c){
     o<<c->num_reserv<<setw(10)<<c->nom<<setw(10)<<c->telephone<<setw(10)<<c->adresse<<setw(10)<<c->chambre<<setw(10)<<c->statut<<endl;
	return o;
}

istream& operator>>(istream& i, Client* c)
{
    i>>c->num_reserv>>c->nom>>c->telephone>>c->adresse>>c->chambre>>c->statut;
    return i;
}
