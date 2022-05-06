#include<iostream>
#include<string.h>
#include <iomanip>
#include <ctime>
#include<stdlib.h>
#include "hotel.h"
using namespace std;

int main()
{
    string nom;
    cout<<"Saisir le nom de l'hotel: ";
    cin>>nom;
	Hotel hotel(nom);		//CREATING OBJECT OF CLASS HOTEL

	char ch;
	int f=hotel.ouvrir();
	if(f==0)//il existe un hotel avec ce nom
    {
        cout<<"Il existe un fichier"<<endl;
        hotel.recuperer_entites();
    }
	cout<<endl<<"======================================================================================BIENVENUE DANS LA CHAINE D'HOTELS FIVE SEASONS========================================================================================";
	do
	{		//MENU TO USE AS EITHER ADMIN OR WHEN A CUSTOMER ENTERS
		cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t"
				"MENU:\n\t\t\t\t\t\t\t\t\t\t\t"
				"1.TRAITEMENT HOTEL\n\t\t\t\t\t\t\t\t\t\t\t"
				"2.TRAITEMENT CLIENT\n\t\t\t\t\t\t\t\t\t\t\t"
				"3.EXIT\n\t\t\t\t\t\t\t\t\t\t\t"
				"Enter your choice:";
		cin>>ch;
		switch(ch)
		{
		case '1':
			cout<<"----Ajout des chambres:----"<<endl;
			hotel.addChambre();
			cout<<"----Chambres ajoutees.----"<<endl;
			cout<<"----Ajout des salles:----"<<endl;
            hotel.addSalle();
			cout<<"----Salles ajoutees. Retour au menu principal.----"<<endl;
			break;
		case '2':
			char ch1;
			do
			{
			    Chambre chambre;
				//MENU 2 TO USE WHEN A CUSTOMER WANTS TO CHECK IN
				cout<<endl<<"*************************************************************************************************************************************************************************************************"<<endl;
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~BIENVENUE DANS LA CHAINE D'HOTELS FIVE SEASONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cout<<"\n\t\t\t\t\t\t\t\t\t\t\t"
						"Menu:\n\t\t\t\t\t\t\t\t\t\t\t"
						"1.Verifier disponibilte des chambres.\n\t\t\t\t\t\t\t\t\t\t\t"
						"2.Verifier disponibilte des salles.\n\t\t\t\t\t\t\t\t\t\t\t"
						"3.Search Room\n\t\t\t\t\t\t\t\t\t\t\t"
						"4.Check In\n\t\t\t\t\t\t\t\t\t\t\t"
						"5.Chercher Client\n\t\t\t\t\t\t\t\t\t\t\t"
						"6.Resume des clients\n\t\t\t\t\t\t\t\t\t\t\t"
						"7.Checkout.\n\t\t\t\t\t\t\t\t\t\t\t"
						"8.Retour au menu principa.\n\t\t\t\t\t\t\t\t\t\t\t"
						"Entrer votre choix: ";
				cin>>ch1;
				switch(ch1)
				{
				case '1':
					hotel.disponibiliteChambre();
					break;
                case '2':
                    hotel.disponibiliteSalle();
                    break;
				case '3':
					hotel.RechercheChambre();
					break;
				case '4':
				    char c_ent;
				    choix_ent:
				    cout<<"Chambre ou Salle? (C/S) ";
				    cin>>c_ent;
				    if(c_ent=='C')
					hotel.CheckIn<Chambre>();
					else if (c_ent=='S') hotel.CheckIn<Salle>();
					else {
                        cout<<"Choix invalide!\n";
                        goto choix_ent;
					}
					break;
				case '5':
					hotel.rechercheClient();
					break;
				case '6':
					hotel.resumeClient();
					break;
				case '7':
					hotel.CheckOut();
					break;
				case '8':
					break;
				default:
					cout<<"Choix invalide."<<endl;
					break;
				}
			}while(ch1!='8');
			break;
		case '3':
			cout<<"Thank you!";
            hotel.enregistrer_fichier();
			exit(0);
		default:
			cout<<"Choix invalide."<<endl;
			break;
		}
	}while(ch!='3');
	return 0;
}
