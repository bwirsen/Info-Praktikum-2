#pragma once
#include "Fahrzeug.h"

class PKW :
	public Fahrzeug
{
public:

	PKW(string name, double vMax, double vb, double vTank = 55);
	~PKW();
	//Funktion zum Auftanken der PKWs. Defaultwert dMenge = -1 -> PKW wird vollgetankt
	double dTanken(double dMenge = -1);
	//Funktionsaufruf zum Abfertigen(Aktualisieren) der PKWs, �berladung der Fahrzeug Memberfunktion
	void vAbfertigung();
	//Ausgabe der PKW Daten, ebenfalls �berladen
	void vAusgabe();
	//gibt die maximale Geschwindigkeit zur�ck
	double dGeschwindigkeit();
	//Funktion zum Zeichnen des PKWs auf dem Server
	void vZeichnen(Weg* pWeg);
	//�berladung des Steamoperators out (Ausgabe mit cout <<)
	ostream& ostreamAusgabe(ostream& out);

private:
	double p_dVerbrauch;
	double p_dTankinhalt;
	double p_dTankvolumen;
};

