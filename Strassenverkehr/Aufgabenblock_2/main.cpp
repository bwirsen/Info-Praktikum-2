#include <iostream>
#include <string>
#include <stdlib.h> 
#include <vector>

#include "Fahrrad.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Weg.h"
#include "SimuClient.h"

void vWait();
void vAufgabe_1();
void vAufgabe_1_deb();
void vAufgabe_2();
void vAufgabe_3();
void vAufgabe_4();
void vAufgabe_5();
void vAufgabe_6();

/*Überladung des Streamoperators << um Fahrzeuge und Subklassen davon direkt ausgeben zu können. Allgemeine Definition 
in der main.cpp, da jede Überladung speziell in jeder Subklasse definiert werden muss */
ostream& operator << (ostream& out, AktivesVO& aVO);

extern double dGlobaleZeit = 0.0;


int main(void) {

	char cAuswahl;
	while (true) {

		cout << "Aufgabe 1, 2, 3, 4 oder 5? Beenden (q). Warnung: Aufgabenblock 2" << endl;
		cin >> cAuswahl;

		switch (cAuswahl) {

		case '1': vAufgabe_1();
			break;
		case '2': vAufgabe_2();
			break;
		case '3': vAufgabe_3();
			break;
		case '4' : vAufgabe_4();
			break;
		case '5' : vAufgabe_5();
			break;
		case '6' : vAufgabe_6();
			break;
		case 'q':
			return 0;
		default:
			return 0;
		}
		vWait();

	}

	return 0;

}

void vAufgabe_1()
{
	Fahrzeug* f1 = new Fahrzeug("BMW", 220);
	Fahrzeug* f2 = new Fahrzeug("Mercedes", 250);
	Fahrzeug* f3 = new Fahrzeug("Porsche", 300);

	double dTakt = 1.13;
	f1->vAusgabeKopf();
	cout << endl;
	for (int i = 0; i < 10; i++) {
		
		dGlobaleZeit = dGlobaleZeit + dTakt;

		f1->vAbfertigung();
		f1->vAusgabe();
		cout << endl;
		f2->vAbfertigung();
		f2->vAusgabe();
		cout << endl;
		f3->vAbfertigung();
		f3->vAusgabe();
		cout << endl;
	}

}

void vAufgabe_1_deb() {

	Fahrzeug* f1 = new Fahrzeug("BMW", 235);
	Fahrzeug* f2 = new Fahrzeug("Mercedes", 250);
	Fahrzeug* f3 = new Fahrzeug("Porsche", 300);
	Fahrzeug* f4 = new Fahrzeug("Opel", 187);

	Fahrzeug* fArray[] = { f1, f2, f3, f4 };

	for (int i = 0; i < 4; i++) {
		fArray[i]->vAusgabe();
	}

	fArray[2] = 0; //Nullpointer oops

	for (int i = 0; i < 4; i++) {
		fArray[i]->vAusgabe();
	}


}

void vAufgabe_2()
{	
	//Deklaration aller benötigten Variablen, Vektoren
	vector<Fahrzeug*> vektor;
	string sPKW, sFahrrad;
	int iPKWs, iFahrraeder;
	double dVMax, dVerbrauch;

	//Abfrage
	cout << "Geben Sie die Anzahl der zu erzeugenden PKWs ein" << endl;
	cin >> iPKWs;
	cout << "Geben Sie die Anzahl der zu erzeugenden Fahrraeder ein" << endl;
	cin >> iFahrraeder;

	//Einlesen PKWs
	cout << "Erstellung der PKWs:" << endl;
	for (int i = 0; i < iPKWs; i++) {
		cout << "Name?" << endl;
		cin >> sPKW;
		cout << "maximale Geschwindigkeit?" << endl;
		cin >> dVMax;
		cout << "Verbrauch?" << endl;
		cin >> dVerbrauch;
		PKW* pkw = new PKW(sPKW, dVMax, dVerbrauch);
		vektor.push_back(pkw);
	}

	//Einlesen Fahrraeder
	cout << "Erstellung der Fahrraeder:" << endl;
	for (int i = 0; i < iFahrraeder; i++) {
		cout << "Name?" << endl;
		cin >> sFahrrad;
		cout << "maximale Geschwindigkeit?" << endl;
		cin >> dVMax;
		Fahrrad* fahrrad = new Fahrrad(sFahrrad, dVMax);
		vektor.push_back(fahrrad);
	}

	//Routine
	double dTakt = 0.5;
	cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	Fahrzeug::vAusgabeKopf();

	for (int i = 0; i < 8; i++) {

		dGlobaleZeit += dTakt;
		
		for (vector<Fahrzeug*>::iterator it = vektor.begin(); it != vektor.end(); it++) {

			(*it)->vAbfertigung();
			
			//Auftanken nach 3 Stunden
			if (dGlobaleZeit == 3) {
				(*it)->dTanken();
			}
				
			(*it)->vAusgabe();
		}

	}

	
}

void vAufgabe_3() {

	//Verwenden von allen überladenen Operatoren

	PKW* pkw_a = new PKW("Audi", 250, 10);
	PKW* pkw_b = new PKW("test", 0, 0);

	Fahrzeug::vAusgabeKopf();
	cout << *pkw_a << endl << *pkw_b << endl << endl;

	dGlobaleZeit = 1;
	//Audi fahren lassen...
	pkw_a->vAbfertigung();

	cout << "Vergleichsoperator testen: pkw_b < pkw_a sollte true (1) liefern:	" << (*pkw_b < *pkw_a ) << endl << endl;

	*pkw_b = *pkw_a; //auf die Pointer achten, ohne Sternchen werden nur die Adressen getauscht.

	cout << "test-wagen zum _neuen_ Audi ueberschreiben. Ausgabe sollte ID 3 haben : " << endl;

	Fahrzeug::vAusgabeKopf();
	cout << *pkw_b << endl;
	cout << *pkw_a << endl;

}

void vAufgabe_4()
{
	Weg* weg1 = new Weg("weg1", 1719, Landstraße);   
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
	vAufgabe_5();
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


