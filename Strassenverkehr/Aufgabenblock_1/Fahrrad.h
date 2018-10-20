#pragma once
#include "Fahrzeug.h"
#include <math.h>

class Fahrrad : public Fahrzeug
{
public:
	//Konstruktor und Dekonstruktor
	Fahrrad(string name, double vMax);
	~Fahrrad();
	//�berladene Ausgabedunktion
	void vAusgabe();
	//Geschwindigkeitsfunktion, welche den aktuellen Geschwindigkeitswert returned
	double dGeschwindigkeit();
};

