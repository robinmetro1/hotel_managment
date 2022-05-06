#include "hotel.h"

using namespace std;

Hotel::Hotel(string n):nom(n){
}


Hotel::~Hotel()
{
    entites.clear();
    clients.clear();
}

ostream& operator<<(ostream& o ,Hotel& h)
{
    o<<"Nom hotel :"<<h.nom<<endl;
    return o;
}
istream& operator>>(istream& i  ,Hotel& h)
{

    cout<<"Saisir nom Hotel :";
    i>>h.nom;

    return i;
}
void Hotel::addChambre()
{
	int cnum;
	cout<<"Entrer le nombre de chambres: ";
	cin>>nbChambres;		//ACCEPTING NUMBER OF ROOMS
	while(nbChambres<=0)
	{
		cout<<"Invalide. Entrer un nombre valide.";
		cin>>nbChambres;
	}

	for(int i=0;i<nbChambres;i++)
	{
	    Chambre *chambre=new Chambre();
		cout<<"CHAMBRE "<<(i+1)<<endl;
		flag:
		cout<<endl<<"Entrer numero Chambre : ";
		cin>>cnum;
		if(cnum<=0)		//VALIDATIONS
		{
			cout<<endl<<"Ce numero est invalide! SVP Re-entrer un numero valide  : ";
			goto flag;
		}


		for(int i=0; i<entites.size();i++)	//VALIDATIONS FOR REPETITIVE ROOM NUMBERS
		{
			if(entites[i]->num==cnum)
			{
				cout<<"Invalide.numero de chambre repetif."<<endl;
				goto flag;
			}
		}

		chambre->accepter_entite(cnum);		//CALLING FUNCTION ACCEPT ROOM FROM CLASS ROOM
		entites.push_back(chambre);
	}
}
void Hotel::addSalle()
{
	int cnum;
	cout<<"Entrer le nombre de Salles: ";
	cin>>nbSalles;		//ACCEPTING NUMBER OF ROOMS
	while(nbSalles<=0)
	{
		cout<<"Invalide. Entrer un nombre valide.";
		cin>>nbSalles;
	}

	for(int i=0;i<nbSalles;i++)
	{
	    Salle *salle=new Salle();
		cout<<"Salle "<<(i+1)<<endl;
		flag:
		cout<<endl<<"Entrer numero Salle : ";
		cin>>cnum;
		if(cnum<=0)		//VALIDATIONS
		{
			cout<<endl<<"Ce numero est invalide! SVP Re-entrer un numero valide  : ";
			goto flag;
		}


		for(int i=0; i<entites.size();i++)	//VALIDATIONS FOR REPETITIVE ROOM NUMBERS
		{

		   // Salle ch(static_cast<Salle&>(*entites[i]));
			if(entites[i]->num==cnum)
			{
				cout<<"Invalide.numero de Salle repetif."<<endl;
				goto flag;
			}
		}
		//cout <<"\n num Salle "<<cnum<<endl;
		salle->accepter_entite(cnum);		//CALLING FUNCTION ACCEPT ROOM FROM CLASS ROOM
		entites.push_back(salle);
		//nbSalles--;
	}
}



void Hotel::disponibiliteChambre()		//CHECKING AVAILABILITY OF THE ROOMS
{
	if(nbChambres==0)
	{
		cout<<"SVP ajouter des chambres."<<endl;
		return ;
	}
	cout<<"La liste de toutes les chambres:"<<endl;
	cout<<"| Chambre No.\t|\t Vue sur Mer/Gazon\t|\tType\t\t|\tTaille\t\t|\tPRIX\t\t|\tDisponibilite  \t"<<endl;
	for(int i=0;i<nbChambres;i++)
	{
	    Chambre ch(static_cast<Chambre&>(*entites[i]));
		cout<<ch;	//DISPLAYING ROOM DETAILS
	}
}
void Hotel::disponibiliteSalle()		//CHECKING AVAILABILITY OF THE ROOMS
{
	if(nbSalles==0)
	{
		cout<<"SVP ajouter des salles."<<endl;
		return ;
	}
	cout<<"La liste de toutes les salles:"<<endl;
	cout<<"|Salle No.\t\t";
	cout<<"|	Nom 	\t\t";
	cout<<"|	Type 	\t";
	cout<<"|	Capacite\t";
	cout<<"|	PRIX:     \t";
	cout<<"|	Statut	\t\t|"<<endl;
	for(int i=nbChambres;i<nbChambres+nbSalles;i++)
	{
	    Salle sa(static_cast<Salle&>(*entites[i]));
		cout<<sa;	//AFFICHAGE SALLE DETAILS
	}
}
void Hotel::RechercheChambre()	//SEARCH FOR A PARTICULAR TYPE OF A ROOM
{
	if(nbChambres==0)
	{
		cout<<"SVP ajouter des chambres."<<endl;
		return;
	}
	int flag=0;
	char vue1, type1, taille1;
	cout<<"Vue sur Mer ou Gazon ? (M/G): "<<endl;
	cin>>vue1;
	cout<<"Suite ou Chambre Normale (S/N)?"<<endl;
	cin>>type1;
	cout<<"Taille (G/P)"<<endl;
	cin>>taille1;
	for(int i=0;i<nbChambres;i++)
	{
	    Chambre ch(static_cast<Chambre&>(*entites[i]));
		if(ch.vue==vue1 && ch.type==type1 && ch.taille==taille1)		//MAKING SURE ALL CONDITIONS ARE SATISFIED
		{
			flag=1;
			cout<<"Chambre trouvee"<<endl;
			cout<<ch;
		}
	}
	if(flag==0)
	{
		cout<<"Aucune chambre n'est disponible."<<endl;
	}
}





void Hotel::CheckOut()		//CHECKOUT AND BILLING PROCEDURE
{
    int cnum, i, j;
	cout<<"Entrer numero chambre= ";
	cin>>cnum;
	for(j=0;j<nbChambres; j++){
		if(cnum==entites[j]->num)
		{
			break;
		}
	}
	if(entites[j]->statut==0)		//IF ROOM NOT FOUND OCCUPIED
	{
		cout<<"Invalide."<<endl;
	}
	for(i=0;i<nClient;i++)	//CHECKING CUSTOMER DETAILS
	{
		if(clients[i].chambre==cnum)
		{
			cout<<"CHECKING OUT."<<endl;
			cout<<clients[i];		//CUSTOMER DETAILS
			cout<<"Votre facture totale est "<<clients[i].facture<<endl;
			cout<<"Avance payement: "<<clients[i].avance_payement;
			cout<<endl<<"Reste a payer= "<<clients[i].facture-clients[i].avance_payement<<"DT.";		//PENDING PAYMENTS
			cout<<endl<<"Merci! A bientot :)"<<endl;
			entites[j]->statut=0;	//CHANGING STATUS OF ROOM TO UNOCCUPIED
			clients[i].statut=0;	//CHECKED OUT
			break;
		}
	}
}
void Hotel::resumeClient()		//PRINTING LIST OF ALL CUSTOMERS
{
	if(nbChambres==0)
	{
		cout<<"Pas de clients."<<endl;
		return;
	}
	cout<<"Resume Clients:"<<endl;
	cout<<"Id.\t\t";
	cout<<"|	Nom 	\t\t";
	cout<<"|	Tel 	\t\t";
	cout<<"|	Adresse	\t\t";
	cout<<"|	Entite no:\t";
	cout<<"|	Statut	\t\t|"<<endl;
	for(int i=0;i<nClient;i++)
	{
		cout<<clients[i];
	}
}
void Hotel::rechercheClient()		//SEARCH WHETHER A PARTICULAR CUSTOMER IS STAYING AT THE HOTEL
{
    int id, flag=0;
	cout<<"Entrer num reservation du client.";
	cin>>id;
	for(int i=0;i<=nClient;i++)		//SEARCHING FOR CUSTOMER
	{
		if(clients[i].num_reserv==id)
		{
			cout<<"\t\t\t Nom"<<setw(20);
			cout<<"\t\t\t Tel"<<setw(20);
			cout<<"\t\t\t Addresse"<<setw(20);
			cout<<"\t\t\tChamb no: "<<setw(20)<<endl;
			cout<<clients[i];
			flag=1;
		}
	}
	if(flag==0)		//case not found
	{
		cout<<"Aucun client trouve."<<endl;
	}
}
int Hotel::ouvrir( )
{
    int rslt=0; //retourner 1 si il existe des fichiers de cet hotel 0 si c'est un nouveau hotel
    string nom_fhotel = ".\\fichiers\\"+nom + ".txt";

    fhotel.open(nom_fhotel.c_str(),ios::in | ios::out );

    if(!fhotel)  //Si le fichier n'existent pas alors=>creer un nouveau fichier
    {
        rslt=1;
        cout<<"Un nouveau hotel va etre creer! \n";
        fhotel.open(nom_fhotel.c_str(),ios::in | ios::out | ios::trunc);
        if(!fhotel) cout << "ERREUR: Impossible d'ouvrir les fichier." << endl;
     }
    return rslt;

}
void Hotel::enregistrer_fichier(){
    string nom_fhotel = ".\\fichiers\\"+nom + ".txt";
    fhotel.close();
    fhotel.open(nom_fhotel.c_str(),ios::out | ios::trunc);
    if(!fhotel)
    {cout<<"L'enregistrement a echoue! "<<endl;
    }

    fhotel<<this;
}


ostream& operator<<(ostream& o,Hotel*h)
{
    o<<h->nbChambres<<endl;
    for(int i=0;i<h->nbChambres;i++){
            Chambre *ch = new Chambre(static_cast<Chambre&>(*h->entites[i]));
        o<<ch<<endl;
    }
    o<<h->nbSalles<<endl;

    for(int i=h->nbChambres;i<h->entites.size();i++){
            Salle *sa = new Salle(static_cast<Salle&>(*h->entites[i]));
        o<<sa<<endl;
    }
    o<<h->nClient<<endl;
    for(int i=0;i<h->nClient;i++){
        o<<&h->clients[i]<<endl;
    }
}

void Hotel::recuperer_entites()
{
    fhotel.seekp(0);
    //lecture des chambres
    fhotel>>nbChambres;
    cout<<"Le nbr de chambre est "<<nbChambres<<endl;
    for(int i=0;i<nbChambres;i++){
    Chambre *ch = new Chambre();
    fhotel>>ch;
    entites.push_back(ch);
    }
    //lecture des salles
    fhotel>>nbSalles;
    cout<<"Le nbr de salles est "<<nbSalles<<endl;
    for(int i=0;i<nbSalles;i++){
    Salle *sa = new Salle();
    fhotel>>sa;
    entites.push_back(sa);
    }
    //lecture des clients
    fhotel>>nClient;
    cout<<"Le nbr de clients est "<<nClient<<endl;
    for(int i=0;i<nClient;i++){
    Client *cl = new Client();
    fhotel>>cl;
    clients.push_back(*cl);
    }

}

