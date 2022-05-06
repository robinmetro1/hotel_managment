#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED

#include "chambre.h"
#include"client.h"
#include "salle.h"
#include<vector>
#include <string>
#include<fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <typeinfo>

using namespace std;
//class Hotel
class Hotel
{
    string nom;
	vector<Entite*> entites; //ARRAY OF ENTITES
	vector<Client> clients;	//ARRAY OF CLIENTS
	int nbChambres=0, nClient=0, nbSalles=0;	//NO OF ROOMS AND CUSTOMERS
    fstream fhotel;


public:
    ~Hotel();
    Hotel();
    friend ostream& operator<<(ostream&  ,Hotel&);
    friend istream& operator>>(istream&  ,Hotel&);
	void addChambre();		//ADD ROOMS TO DATABASE
	void addSalle();
	void RechercheChambre();		//SEARCH FOR A PARTICULAR ROOM
	template <class T>
	void CheckIn();			//FOR CUSTOMER CHECKIN
	void rechercheClient();		//SEARCH WHETHER A PARTICULAR CUSTOMER IS STAYING AT THE HOTEL
	void disponibiliteChambre();	//CHECK AVAILABILITY OF ROOMS
	void disponibiliteSalle();
	void CheckOut();		//CHECKOUT AND BILLING PROCEDURE
	void resumeClient();			//GUEST SUMMARY
	friend ostream& operator<<(ostream& o,Hotel*);



	//creating hotel files
     int ouvrir();
	 void enregistrer_fichier();
	 void recuperer_entites();//recuperer toutes les chambres du fichier dans vector





};

template<class T> void Hotel::CheckIn()		//CHECK IN OF A CUSTOMER
{
    int nb=0;
    string ent;
    if(typeid(T)==typeid(Chambre)) {
            nb =nbChambres;
            ent="Chambre";
    }else if(typeid(T)==typeid(Salle)){
            nb =nbSalles;
            ent="Salle";
    }
	if(nb==0)
	{
		cout<<"SVP ajoutez des entites ."<<endl;
		return;
	}
	int i, cnum;
	if(nClient<=nb){	//CHECKING CONDITION IF HOTEL HAS EMPTY CHAMBRE OU SALLE
        Client client;
		client.num_reserv=nClient+1;	//ALLOTING CUSTOMER ID TO THE CUSTOMER
		flag:
		int flag1=0;
		cout<<"Entrer num "<<ent<<"= ";		//ASKING WHAT ROOM NUMBER CUSTOMER WANTS TO STAY IN
		cin>>cnum;
		for(i=0;i<entites.size(); i++){

			if(cnum==entites[i]->num)
			{
				flag1=1;
				break;
			}
		}
		if(flag1==0){
			cout<<"Numero de "<<ent<<" invalide. Re-essayez SVP.\n";
			goto flag;
		}
		if(typeid(T)!=typeid(*entites[i])) {
                cout<<"Numero incorrect\n";
                goto flag;
        }
		if(entites[i]->statut==0)		//CHECKING IF CHAMBRE OU SALLE IS UNOCCUPIED
		{

			char ch2;
			cout<<ent<<" disponible."<<endl;
			cout<<static_cast<T&>(*entites[i]);
			cout<<"Voulez-vous continuer? Appuyez(O/o)";		//CONFIRMATION
			cin>>ch2;
			if(ch2=='O'||ch2=='o')
			{
				cin>>client;//ACCEPTING CUSTOMER DETAILS
				cout<<"Entrer la duree du sejour (en jours si chambre/en heures si salle): ";
				cin>>client.dureeSejour;
				client.facture = client.dureeSejour*entites[i]->montant;		//generating bill. bill= No. of days * rent per day.
				cout<<"Votre facture totale est de "<<(client.facture)<<"DT."<<endl<<". Min avance= "<<client.facture/4<<"DT; Combien allez-vous payer? ";
				cin>>client.avance_payement;
				while(client.avance_payement<client.facture/4||client.avance_payement>client.facture)
				{
					cout<<"Entrer un montant valide.";
					cin>>client.avance_payement;
				}
				cout<<"Merci. Reservation confirmee."<<endl;		//confirmed booking
				cout<<"--------------------------------------------------------------"<<endl;		//printing booking details
				cout<<"Reservation No. : "<<client.num_reserv<<"\nNom: "<<client.nom<<"\n"<<ent<<" no.: "<<cnum<<"\nDate: ";
				time_t my_time = time(NULL);
						// ctime() used to give the present time
				printf("%s", ctime(&my_time));
				entites[i]->statut=1;		//changing room status to booked
				client.chambre=cnum;		//alloting room to customer
				client.statut=1;
				clients.push_back(client); //ajouter client dans le vetor des clients
				nClient++;
			}
			else		//if needs to change room number
			{
				goto flag;
			}
		}
		else		//if room is occupied
		{
			cout<<"Chambre occupee. Veuillez choisir une autre chambre."<<endl;
		}
	}
	else		//CONDITION ALL ROOMS ARE BOOKED
	{
		cout<<"Desole! Hotel complet."<<endl;
	}
}


#endif // HOTEL_H_INCLUDED
