#pragma once
#include "Fahrzeug.h"

class PKW :
	public Fahrzeug
{
public:

	PKW(string name, double vMax, double vb, double vTank = 55);
	~PKW();
	double dTanken(double dMenge = -1);
	void vAbfertigung();
	void vAusgabe();
	double dGeschwindigkeit();
	void vZeichnen(Weg * pWeg);
	ostream& ostreamAusgabe(ostream& out);

private:
	double p_dVerbrauch;
	double p_dTankinhalt;
	double p_dTankvolumen;
};

