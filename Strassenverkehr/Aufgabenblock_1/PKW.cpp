#include "PKW.h"



PKW::PKW(string name, double vMax, double vb, double vTank) : Fahrzeug(name, vMax),
p_dVerbrauch(vb), p_dTankvolumen(vTank) 
{
	p_dTankinhalt = p_dTankvolumen / 2;
}


PKW::~PKW()
{
}

double PKW::dTanken(double dMenge)
{
	double dFüllmenge;

	if (dMenge == -1 || this->p_dTankinhalt + dMenge > this->p_dTankinhalt) {
		dFüllmenge = this->p_dTankvolumen - this->p_dTankinhalt;
		this->p_dTankinhalt = this->p_dTankvolumen;
		return dFüllmenge;
	}
	else {
		this->p_dTankinhalt += dMenge;
		return dMenge;
	}
}

void PKW::vAbfertigung()
{
	Fahrzeug::vAbfertigung();


}
