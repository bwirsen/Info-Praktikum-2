#include <iostream>
#include <string>
#include <stdlib.h> 
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include <vector>

void wait();
void vAufgabe_1();
void vAufgabe_1_deb();
void vAufgabe_2();
void vAufgabe_3();

//Überladung des Streamoperators << um Fahrzeuge und Subklassen davon direkt ausgeben zu können. Allgemeine Definition 
//in der main.cpp, da jede Überladung speziell in jeder Subklasse definiert werden muss
ostream& operator << (ostream& out, Fahrzeug& fahrzeug);

extern double dGlobaleZeit = 0.0;


int main(void) {

	char cAuswahl;
	while (true) {

		cout << "Aufgabe 1, 2, 3 oder 1deb (4)? Beenden (q)" << endl;
		cin >> cAuswahl;

		switch (cAuswahl) {

		case '1': vAufgabe_1();
			break;
		case '2': vAufgabe_2();
			break;
		case '3': vAufgabe_3();
			break;
		case '4': vAufgabe_1_deb();
			break;
		case 'q':
			return 0;
		default:
			return 0;
		}
		wait();

	}

	return 0;

}

void vAufgabe_1()
{
	Fahrzeug* f1 = new Fahrzeug("BMW", 220);
	Fahrzeug* f2 = new Fahrzeug("Mercedes", 250);
	Fahrzeug* f3 = new Fahrzeug("Porsche", 300);

	f1->vAusgabeKopf();
	cout << endl;
	for (dGlobaleZeit = 0; dGlobaleZeit < 10; dGlobaleZeit++) {
		
		

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
	Fahrzeug::vAusgabeKopf();
	for (int i = 0; i < 4; i++) {
		fArray[i]->vAusgabe();
		cout << endl;
	}

	fArray[2] = 0; //Nullpointer oops

	for (int i = 0; i < 4; i++) {
		fArray[i]->vAusgabe();
		cout << endl;
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

		dGlobaleZeit = dGlobaleZeit + dTakt;
		
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
ostream& operator << (std::ostream& out, Fahrzeug& fahrzeug)
{
	//übergabe von out an die Memberüberladungen, damit out gefüllt wird
	return fahrzeug.ostreamAusgabe(out);
}

void wait() {

	cin.ignore();
	cin.ignore();
}


