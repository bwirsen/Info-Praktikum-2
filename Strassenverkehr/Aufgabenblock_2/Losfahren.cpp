#include "Losfahren.h"
#include "Fahrzeug.h"




Losfahren::Losfahren(Fahrzeug* p_pFahrzeug, Weg* p_pWeg) : FahrAusnahme(p_pFahrzeug, p_pWeg)
{
}


Losfahren::~Losfahren()
{
}

void Losfahren::vBearbeiten()
{
	cout << endl <<"Ausnahme vom Typ: LOSFAHREN. Ausgeloest durch: " << p_pFahrzeug->getName() << " auf: " << p_pWeg->getName() << endl <<endl;
	
	this->p_pWeg->vAnnahme(this->p_pFahrzeug);

}
