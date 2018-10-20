#pragma once
#include "Fahrzeug.h"
class PKW :
	public Fahrzeug
{
public:
	//Konstruktor mit Defaultwert f�r den Tankinhalt
	PKW(string name, double vMax, double vb, double vTank = 55);
	//Dekonstruktor
	~PKW();
	//Funktion zum Auftanken der PKWs. Defaultwert dMenge = -1 -> PKW wird vollgetankt
	double dTanken(double dMenge = -1);
	//Funktionsaufruf zum Abfertigen(Aktualisieren) der PKWs, �berladung der Fahrzeug Memberfunktion
	void vAbfertigung();
	//Ausgabe der PKW Daten, ebenfalls �berladen
	void vAusgabe();
	//gibt die maximale Geschwindigkeit zur�ck
	double dGeschwindigkeit();
	//�berladung des Steamoperators out (Ausgabe mit cout <<)
	ostream& ostreamAusgabe(ostream & out);

private:
	double p_dVerbrauch;
	double p_dTankinhalt;
	double p_dTankvolumen;
};

