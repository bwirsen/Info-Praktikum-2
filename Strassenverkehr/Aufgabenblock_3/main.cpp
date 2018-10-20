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
#include "Kreuzung.h"

void vWait();
void vAufgabe_1();
void vAufgabe_1_deb();
void vAufgabe_2();
void vAufgabe_3();
void vAufgabe_4();
void vAufgabe_5();
void vAufgabe_6();
void vAufgabe_6a();
void vAufgabe_7();
void vAufgabe_8();

/*Überladung des Streamoperators << um Fahrzeuge und Subklassen davon direkt ausgeben zu können. Allgemeine Definition 
in der main.cpp, da jede Überladung speziell in jeder Subklasse definiert werden muss */
ostream& operator << (ostream& out, AktivesVO& aVO);

extern double dGlobaleZeit = 0.0;

inline bool bEqual(double x, double y)
{
	return (fabs(x - y) < 1e-6);
}


int main(void) {

	char cAuswahl;
	while (true) {

		cout << "Aufgabe 1, 2, 3, 4, 5, 6, 6a (a), 7, 8? Beenden (q). Warnung: Aufgabenblock 3" << endl;
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
		case 'a' : vAufgabe_6a();
			break;
		case '7' : vAufgabe_7();
			break;
		case '8': vAufgabe_8();
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

void vAufgabe_7()
{
	Weg weg1("B63", 120, Landstraße);
	Weg weg2("B63z", 120, Landstraße);

	PKW pkw1("Audi", 220, 4);
	Fahrrad fr2("Kawasaki", 40);
	Fahrrad fr1("KTM", 50);

	weg1.vAnnahme(&pkw1, 3);
	weg1.vAnnahme(&fr1, 1.2);

	bInitialisiereGrafik(900, 900); //Server starten
	int iKoordinaten[] = { 800, 800, 200, 150 };
	bZeichneStrasse(weg1.getName(), weg2.getName(), 500, 2, iKoordinaten);

	Fahrzeug::vAusgabeKopf();
	for (dGlobaleZeit = 0; dGlobaleZeit <= 10; dGlobaleZeit += 0.1)
	{			
		if (bEqual(dGlobaleZeit, 5)) 
		{
			weg1.vAnnahme(&fr2, 5.5);
		}

		weg1.vAbfertigung();

		vSetzeZeit(dGlobaleZeit);

		pkw1.vZeichnen(&weg1);
		fr1.vZeichnen(&weg1);
		fr2.vZeichnen(&weg1);


		cout << pkw1 << endl << fr1 << endl << fr2 << endl << weg1 << endl << endl;

		vSleep(50);		//warten 50ms

	}
	vWait();

	vBeendeGrafik();
}

void vAufgabe_8()
{
	
	Kreuzung kr1("Kr1");
	Kreuzung kr2("Kr2", 1000);
	Kreuzung kr3("Kr3");
	Kreuzung kr4("Kr4");

	kr1.vVerbinde("W12", "W21", 40, &kr2, true, Innerorts);
	kr2.vVerbinde("W23a", "W32a", 115, &kr3, false);
	kr2.vVerbinde("W23b", "W32b", 40, &kr3, true, Innerorts);
	kr2.vVerbinde("W24", "W42", 55, &kr4, true, Innerorts);
	kr3.vVerbinde("W34", "W43", 85, &kr4, false);
	kr4.vVerbinde("W44a", "W44b", 130, &kr4, false, Landstraße);

	//TODO: Fahrzeuge erstellen, von kr1 annehmen lassen, Routine wie gehabt erstellen, alles ausgeben

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


