#include <iostream>
#include <string>
#include <stdlib.h> 
#include <vector>
#include <fstream>
#include "Fahrrad.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Weg.h"
#include "SimuClient.h"
#include "LazyAktion.h"
#include "LazyListe.h"
#include "Kreuzung.h"
#include "Welt.h"

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
void vAufgabe_9();
void vAufgabe_9sim();

extern double dGlobaleZeit = 0.0;

inline bool bEqual(double x, double y)
{
	return (fabs(x - y) < 1e-6);
}

int main(void) {

	char cAuswahl;
	while (true) {

		cout << "Aufgabe 1, 2, 3, 4, 5, 6, 6a (a), 7, 8, 9, 9sim (s)? Beenden (q). Warnung: Aufgabenblock 3" << endl;
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
		case '8' : vAufgabe_8();
			break;
		case '9' : vAufgabe_9();
			break;
		case 's': vAufgabe_9sim();
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
	//Deklaration aller ben�tigten Variablen, Vektoren
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

	//Verwenden von allen �berladenen Operatoren

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
	Weg* weg1 = new Weg("weg1", 1719, Landstra�e);   
	PKW* pkw = new PKW("Audi", 300, 2);
	PKW* pkw2 = new PKW("BMW", 250, 3);
	Fahrrad* fr = new Fahrrad("KTM", 25);
	
	weg1->vAnnahme(pkw);	//Audi f�hrt mit Begrenzung
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
	Weg* weg1 = new Weg("B63", 500, Landstra�e);
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
	Weg* weg1 = new Weg("B63", 500, Landstra�e);
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
	lazy.vAktualisieren();	//aktualisieren, um Elemente aus LazyAktionen in die Objektliste zu �bertragen
	cout << "Liste: " << endl << endl;
	lazy.vAusgeben();

	//Elemente < 5 l�schen
	for (auto it = lazy.begin(); it != lazy.end(); it++)
	{
		if (*it < 5)
			lazy.erase(it);
	}

	cout << "Liste nach l�schen, aber vor aktualisieren: " << endl;
	lazy.vAusgeben();
	lazy.vAktualisieren();

	cout << "Liste nach l�schen und aktualisieren: " << endl;
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
	Weg weg1("B63", 120, Landstra�e);
	Weg weg2("B63z", 120, Landstra�e);

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

	PKW pkw1("Audi", 110, 6);
	PKW pkw2("BMW", 225, 6.5);
	PKW pkw3("Tesla", 250, 0);
	Fahrrad fr1("KTM", 35);
	Fahrrad fr2("BMC", 50);
	bInitialisiereGrafik(1200, 720); //starte Server

	kr1.vVerbinde("W12", "W21", 40, &kr2, true, Innerorts);		    // 1
	kr2.vVerbinde("W23a", "W32a", 115, &kr3, false);				// 2
	kr2.vVerbinde("W23b", "W32b", 40, &kr3, true, Innerorts);		// 3
	kr2.vVerbinde("W24", "W42", 55, &kr4, true, Innerorts);			// 4
	kr3.vVerbinde("W34", "W43", 85, &kr4, false);					// 5
	kr4.vVerbinde("W44a", "W44b", 130, &kr4, false, Landstra�e);	// 6

	kr1.vAnnahme(&pkw1, 0);
	
	kr1.vAnnahme(&pkw2, 1.7);
	kr1.vAnnahme(&pkw3, 2.2);
	kr1.vAnnahme(&fr1, 3);
	kr1.vAnnahme(&fr2, 0.3);
	
	int iKoord1[] = { 680, 40, 680, 300 };
	int iKoord2[] = { 680, 300, 850, 300, 970, 390, 970, 500, 850, 570, 680, 570 };
	int iKoord3[] = { 680, 300, 680, 570 };
	int iKoord4[] = { 680, 300, 320, 300 };
	int iKoord5[] = { 680, 570, 500, 570, 350, 510, 320, 420, 320, 300 };
	int iKoord6[] = { 320, 300, 320, 150, 200, 60, 80, 90, 70, 250, 170, 300, 320, 300 };

	bZeichneKreuzung(680, 40);  // 1
	bZeichneKreuzung(680, 300); // 2
	bZeichneKreuzung(680, 570); // 3
	bZeichneKreuzung(320, 300); // 4

	bZeichneStrasse("W12", "W21", 40, 2, iKoord1);		// 1
	bZeichneStrasse("W23a", "W32a", 115, 6, iKoord2);	// 2
	bZeichneStrasse("W23b", "W32b", 40, 2, iKoord3);	// 3
	bZeichneStrasse("W24", "W42", 55, 2, iKoord4);		// 4
	bZeichneStrasse("W34", "W43", 85, 5, iKoord5);		// 5
	bZeichneStrasse("W44a", "W44b", 130, 7, iKoord6);	// 6

	Fahrzeug::vAusgabeKopf();
	for (dGlobaleZeit = 0; dGlobaleZeit <= 5; dGlobaleZeit += 0.1)
	{
		vSetzeZeit(dGlobaleZeit);

		kr1.vAbfertigung();
		kr2.vAbfertigung();
		kr3.vAbfertigung();
		kr4.vAbfertigung();

		kr1.vZeichnen();
		kr2.vZeichnen();
		kr3.vZeichnen();
		kr4.vZeichnen();

		cout << "**********************************************************************************************************************************************************" << endl;
		cout << pkw1 << endl << pkw2 << endl << pkw3 << endl << fr1 << endl << fr2 << endl << kr1 << endl << kr2 << endl << kr3 << endl << kr4 << endl << endl ;
		cout << "**********************************************************************************************************************************************************" << endl;

		vSleep(100);		
	}
	vWait();

	vBeendeGrafik();
}

void vAufgabe_9()
{
	ifstream infile("VO.dat");

	PKW pkw1;
	Fahrrad fr1;
	Kreuzung kr1;
	Kreuzung kr2;
	
	try
	{
		infile >> pkw1;
		infile >> fr1;
		infile >> kr1;
		Fahrzeug::vAusgabeKopf();
		cout << pkw1 << endl << fr1 << endl << kr1 << endl << kr2 << endl;
		
	}
	catch (string caught)
	{
		cout << caught << endl;
	}

}

void vAufgabe_9sim()
{
	Welt welt;
	char c;
	cout << "Grafik? j/n" << endl;
	cin >> c;

	switch (c)
	{
		case 'n' : 
		{
			ifstream infile("Simu.dat");

			try
			{
				welt.vEinlesen(infile);
				Fahrzeug::vAusgabeKopf();
				for (dGlobaleZeit = 0; dGlobaleZeit <= 100; dGlobaleZeit += 0.05)
				{
					welt.vSimulation();
					
				}
				cout << "Loesche map..." << endl;
				AktivesVO::clearMap();
				
			}

			catch (string caught)
			{
				cout << caught << endl;
				cout << "Loesche map..." << endl;
				AktivesVO::clearMap();
			}
		}
		break;

		case 'j':
		{
			ifstream infile("SimuDisplay.dat");

			try
			{
				bInitialisiereGrafik(1200, 1000);
				welt.vEinlesenMitGrafik(infile);
				Fahrzeug::vAusgabeKopf();
				for (dGlobaleZeit = 0; dGlobaleZeit <= 100; dGlobaleZeit += 0.05)
				{
					welt.vSimulation();
					cout << *(AktivesVO::ptObjekt("Trabant")) << endl << *(AktivesVO::ptObjekt("Mercedes")) <<
						endl << *(AktivesVO::ptObjekt("Ferrari")) << endl << *(AktivesVO::ptObjekt("Porsche")) << endl
						<< *(AktivesVO::ptObjekt("BMX")) << endl << *(AktivesVO::ptObjekt("Peugeot")) << endl;
				}
				cout << "Loesche map..." << endl;
				AktivesVO::clearMap();
				
			}

			catch (string caught)
			{
				cout << caught << endl;
				cout << "Loesche map..." << endl;
				AktivesVO::clearMap();
			}
		}
		break;
	}
	
}
	
void vWait()
{
	cin.ignore();
	cin.ignore();
}