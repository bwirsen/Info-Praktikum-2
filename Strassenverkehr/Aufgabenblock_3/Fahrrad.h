#pragma once
#include "Fahrzeug.h"
#include <math.h>

class Fahrrad : public Fahrzeug
{
public:
	Fahrrad(string name, double vMax);
	Fahrrad();
	~Fahrrad();
	void vAusgabe();
	double dGeschwindigkeit();
	void vZeichnen(Weg * pWeg);
	istream& istreamEingabe(istream& in);
};

