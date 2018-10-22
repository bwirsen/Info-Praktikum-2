#pragma once
#include "Fahrzeug.h"
#include <math.h>

class Fahrrad : public Fahrzeug
{
public:
	//Konstruktor und Destruktoren
	Fahrrad(string name, double vMax);
	~Fahrrad();
	//Ausgabefunktion
	void vAusgabe();
	//Funktion zur Rückgabe der Geschwindigkeit
	double dGeschwindigkeit();
	//Funktion zum Zeichnen des Fahrrads im Server, übergibt relative Position
	void vZeichnen(Weg * pWeg);
};

