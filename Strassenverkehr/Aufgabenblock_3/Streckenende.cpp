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
	cout << endl << "Ausnahme vom Typ: STRECKENEDE. Ausgeloest durch: " << p_pFahrzeug->getName() << " auf: " << p_pWeg->getName() << endl << endl;

	//Abgabe vom aktuellen Weg
	this->p_pWeg->vAbgabe(this->p_pFahrzeug);
	//und Annahme von der Zielkreuzung
	this->p_pWeg->getKreuzung()->vAnnahme(this->p_pFahrzeug, dGlobaleZeit + 0.1);
}
