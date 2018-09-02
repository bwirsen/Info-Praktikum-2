#include <iostream>
#include <string>
#include <stdlib.h> 
#include "Fahrzeug.h"
#include "PKW.h"
void vAufgabe_1();
void vAufgabe_1_deb();

extern double dGlobaleZeit = 0.0;

int main() {

	//Aufruf der Testfunktion

	vAufgabe_1();

	//vAufgabe_1_deb();

	

	return 0;

}

void vAufgabe_1()
{
	Fahrzeug* f1 = new Fahrzeug("BMW", 220);
	Fahrzeug* f2 = new Fahrzeug("Mercedes", 250);
	Fahrzeug* f3 = new Fahrzeug("Porsche", 300);

	double dTakt = 1.13;
	f1->vAusgabeKopf();
	for (int i = 0; i < 10; i++) {
		
		dGlobaleZeit = dGlobaleZeit + dTakt;

		f1->vAbfertigung();
		f1->vAusgabe();
		f2->vAbfertigung();
		f2->vAusgabe();
		f3->vAbfertigung();
		f3->vAusgabe();
	}

	PKW* p1 = new PKW("Audi", 250, 9);
	cout << p1->dTanken();

	cin.ignore();
	cin.ignore();
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
