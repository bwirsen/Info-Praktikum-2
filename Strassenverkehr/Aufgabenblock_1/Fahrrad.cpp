#include "Fahrrad.h"

Fahrrad::Fahrrad(string name, double vMax): Fahrzeug(name, vMax)
{
}


Fahrrad::~Fahrrad()
{
}

void Fahrrad::vAusgabe() {
	Fahrzeug::vAusgabe();
	cout << endl;
}

double Fahrrad::dGeschwindigkeit() {

	// v = vMax * 0,9^(Strecke/20)
	double	dV = this->p_dMaxGeschwindigkeit * pow(0.9, this->p_dGesamtStrecke / 20);
	
	if (dV > 12) {
		return dV;
	}

	else
		return 12;

}
