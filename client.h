#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
#include<string>
#include<iostream>
#include <iomanip>

using namespace std;

class Client
{
	string nom;	   			 //CUSTOMER FULL NAME
	//string prenom;
	string adresse;				//CUSTOMER ADDRESS
	string telephone;				//CONTACT NUMBER
	int dureeSejour=0;	    			//DURATION OF STAY
	float avance_payement;		//ADVANCE PAYMENT
	double facture=0;				//BILL AMT
	int num_reserv;				//BOOKING ID
	int chambre;					//ROOM NO
	int statut;
public:
    Client();
	friend istream& operator>>(istream&, Client&);
	friend ostream& operator<<(ostream&,Client&);
	friend istream& operator>>(istream&, Client*);
	friend ostream& operator<<(ostream&,Client*);
	friend class Chambre;
	friend class Hotel;
};



#endif // CLIENT_H_INCLUDED
