#include "Fahrrad.h"

Fahrrad::Fahrrad(string name, double vMax): Fahrzeug(name, vMax)
{
}

Fahrrad::Fahrrad() : Fahrzeug()
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

void Fahrrad::vZeichnen(Weg* pWeg) {

	double dRelPosition = this->getAbschnittStrecke() / pWeg->getL�nge(); //berechnet relativ zur L�nge zur�ckgelegte Strecke
	bZeichneFahrrad(this->getName(), pWeg->getName(), dRelPosition, this->dGeschwindigkeit());

}

istream & Fahrrad::istreamEingabe(istream & in)
{
	AktivesVO::istreamEingabe(in) >> this->p_dMaxGeschwindigkeit;
	return in;
}
