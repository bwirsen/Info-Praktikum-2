#include <iostream>
#include <string>
#include <stdlib.h> 
#include <vector>

#include "Fahrrad.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Weg.h"
#include "SimuClient.h"
#include "LazyAktion.h"
#include "LazyListe.h"

void vWait();
void vAufgabe_4();
void vAufgabe_5();
void vAufgabe_6();
void vAufgabe_6a();

/*Überladung des Streamoperators << um Fahrzeuge und Subklassen davon direkt ausgeben zu können. Allgemeine Definition 
in der main.cpp, da jede Überladung speziell in jeder Subklasse definiert werden muss */
ostream& operator << (ostream& out, AktivesVO& aVO);

extern double dGlobaleZeit = 0.0;


int main(void) {

	char cAuswahl;
	while (true) {

		cout << "Aufgabe 4, 5, 6, 6a? Beenden (q). Warnung: Aufgabenblock 2" << endl;
		cin >> cAuswahl;

		switch (cAuswahl) {

		case '4' : vAufgabe_4();
			break;
		case '5' : vAufgabe_5();
			break;
		case '6' : vAufgabe_6();
			break;
		case 'a': vAufgabe_6a();
		case 'q':
			return 0;
		default:
			return 0;
		}
		vWait();

	}

	return 0;

}


void vAufgabe_4()
{
	Weg* weg1 = new Weg("weg1", 800, Landstraße);   
	PKW* pkw = new PKW("Audi", 300, 2);
	PKW* pkw2 = new PKW("BMW", 250, 3);
	Fahrrad* fr = new Fahrrad("KTM", 25);
	
	weg1->vAnnahme(pkw);	//Audi fährt mit Begrenzung
	weg1->vAnnahme(fr);		
	weg1->vAnnahme(pkw2, 2);	//BMW wartet 2 Stunden
	cout << *weg1 << endl;
	double dTakt = 0.5;
	Fahrzeug::vAusgabeKopf();
	for (int i = 0; i < 20; i++) 
	{
		dGlobaleZeit += dTakt;
		weg1->vAbfertigung();
		cout << *pkw << endl << *pkw2 << endl << *fr << endl;
	}

	delete weg1, pkw, pkw2, fr;
	
}

void vAufgabe_5()
{
	Weg* weg1 = new Weg("B63", 500, Landstraße);
	Weg* weg2 = new Weg("A1", 500);

	PKW* pkw1 = new PKW("Audi", 220 , 4);
	PKW* pkw2 = new PKW("BMW", 240, 5);
	Fahrrad* fr1 = new Fahrrad("KTM", 30);
	PKW* pkw3 = new PKW("Porsche", 250, 6);
	PKW* pkw4 = new PKW("Tesla", 220, 0);

	weg1->vAnnahme(pkw1);
	weg1->vAnnahme(pkw2, 2);
	weg1->vAnnahme(fr1);
	weg2->vAnnahme(pkw3);
	weg2->vAnnahme(pkw4, 4);

	bInitialisiereGrafik(900, 900); //Server starten
	int iKoordinaten[] = { 800, 800, 200, 150};
	bZeichneStrasse(weg1->getName(), weg2->getName(), 500, 2, iKoordinaten);

	double dTakt = 0.25;
	//double dTakt = 0.3;
	Fahrzeug::vAusgabeKopf();
	for (int i = 0; i < 30; i++)
	{
		dGlobaleZeit += dTakt;		//Uhr laufen ...
		vSetzeZeit(dGlobaleZeit);	//...und anzeigen lassen

		weg1->vAbfertigung();
		weg2->vAbfertigung();

		cout << *pkw1 << endl << *pkw2 << endl << *pkw3 << endl << *pkw4 << endl << *fr1 << endl;

		pkw1->vZeichnen(weg1);
		pkw2->vZeichnen(weg1);
		pkw3->vZeichnen(weg2);
		pkw4->vZeichnen(weg2);
		fr1->vZeichnen(weg1);

		vSleep(500);		//warten 500ms

	}

	vWait();
	vBeendeGrafik();

}

void vAufgabe_6()
{
	Weg* weg1 = new Weg("B63", 500, Landstraße);
	Weg* weg2 = new Weg("A1", 500);

	PKW* pkw1 = new PKW("Audi", 220, 4);
	PKW* pkw2 = new PKW("BMW", 240, 5);
	//Fahrrad* fr1 = new Fahrrad("KTM", 30);
	PKW* pkw3 = new PKW("Porsche", 250, 6);
	PKW* pkw4 = new PKW("Tesla", 220, 0);

	weg1->vAnnahme(pkw1);
	weg1->vAnnahme(pkw2, 2);
	//weg1->vAnnahme(fr1);
	weg2->vAnnahme(pkw3);
	weg2->vAnnahme(pkw4, 4);


	bInitialisiereGrafik(900, 900); //Server starten
	int iKoordinaten[] = { 800, 800, 200, 150 };
	bZeichneStrasse(weg1->getName(), weg2->getName(), 500, 2, iKoordinaten);

	double dTakt = 0.25;
	//double dTakt = 0.3;
	Fahrzeug::vAusgabeKopf();
	for (int i = 0; i < 30; i++)
	{
		dGlobaleZeit += dTakt;		//Uhr laufen ...
		vSetzeZeit(dGlobaleZeit);	//...und anzeigen lassen

		weg1->vAbfertigung();
		weg2->vAbfertigung();

		cout <<*pkw1 << endl << *pkw2 << endl << *pkw3 << endl << *pkw4 << endl << endl;

		pkw1->vZeichnen(weg1);
		pkw2->vZeichnen(weg1);
		pkw3->vZeichnen(weg2);
		pkw4->vZeichnen(weg2);
		//fr1->vZeichnen(weg1);

		vSleep(500);		//warten 500ms

	}

	vWait();
	vBeendeGrafik();
}

void vAufgabe_6a()
{
	LazyListe<int> lazy;		//Liste vom Typ Int erzeugen
	for (int i = 0; i < 20; i++)
	{
		lazy.push_back(1 + rand() % 10);
	}
	lazy.vAktualisieren();	//aktualisieren, um Elemente aus LazyAktionen in die Objektliste zu übertragen
	cout << "Liste: " << endl << endl;
	lazy.vAusgeben();

	//Elemente < 5 löschen
	for (auto it = lazy.begin(); it != lazy.end(); it++)
	{
		if (*it < 5)
			lazy.erase(it);
	}

	cout << "Liste nach löschen, aber vor aktualisieren: " << endl;
	lazy.vAusgeben();
	lazy.vAktualisieren();

	cout << "Liste nach löschen und aktualisieren: " << endl;
	lazy.vAusgeben();

	lazy.push_front(100);
	lazy.push_front(99);
	lazy.push_back(99);
	lazy.push_back(100);
	lazy.vAktualisieren();

	cout << "Liste mit anderem Anfang/Ende : " << endl;
	lazy.vAusgeben();
	


	vWait();
}


ostream& operator << (std::ostream& out, AktivesVO& aVO)
{
	//übergabe von out an die Memberüberladungen, damit out gefüllt wird
	return aVO.ostreamAusgabe(out);
}

void vWait() {

	cin.ignore();
	cin.ignore();
}


