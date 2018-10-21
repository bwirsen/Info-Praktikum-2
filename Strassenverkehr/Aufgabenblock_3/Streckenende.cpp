#include "Streckenende.h"
#include "Fahrzeug.h"


Streckenende::Streckenende(Fahrzeug* p_pFahrzeug, Weg* p_pWeg) : FahrAusnahme(p_pFahrzeug, p_pWeg)
{
}

Streckenende::~Streckenende()
{
}

void Streckenende::vBearbeiten()
{
	// cout << endl << "Ausnahme vom Typ: STRECKENEDE. Ausgeloest durch: " << p_pFahrzeug->getName() << " auf: " << p_pWeg->getName() << endl << endl;

	Kreuzung* pKreuzung = this->p_pWeg->getKreuzung();
	Weg* pWegNeu = pKreuzung->pZufaelligerWeg(this->p_pWeg);

	//Abgabe vom aktuellen Weg und auftanken
	this->p_pWeg->vAbgabe(this->p_pFahrzeug);
	pKreuzung->vTanken(this->p_pFahrzeug);
	
	//Fahrzeug auf fahrend neuen Weg setzen
	pWegNeu->vAnnahme(this->p_pFahrzeug);

	//geforderte Ausgabe
	cout << "ZEIT		: " << dGlobaleZeit << endl
		<< "KREUZUNG	: " << pKreuzung->getName() << " " << pKreuzung->getTankstellenInhalt() << endl
		<< "WECHSEL		: " << this->p_pWeg->getName() << " -> " << pWegNeu->getName() << endl
		<< "FAHRZEUG	: " << this->p_pFahrzeug->getName() << endl;

}
