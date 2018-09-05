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

}
