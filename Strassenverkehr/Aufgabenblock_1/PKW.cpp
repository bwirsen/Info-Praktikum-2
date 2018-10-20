#include "PKW.h"



PKW::PKW(string name, double vMax, double vb, double vTank) : Fahrzeug(name, vMax),
p_dVerbrauch(vb), p_dTankvolumen(vTank)
{	//init. mit halbem Tankvolumen
	p_dTankinhalt = p_dTankvolumen / 2;
}


PKW::~PKW()
{
}

double PKW::dTanken(double dMenge)
{
	double dFüllmenge;
	// default Param, oder zu viel Tanken - > komplett füllen
	if (dMenge == -1 || (this->p_dTankinhalt + dMenge > this->p_dTankinhalt)) {
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
	//tank leer?
	if (this->p_dTankinhalt != 0) {
		// Strecke vor Abfertigung zwischenspeichern. VA == vor Abfertigung
		double dGesamtStreckeVA = this->p_dGesamtStrecke;

		Fahrzeug::vAbfertigung();

		// Delta-Variable für die benötigte Streckendifferenz bzgl der Tankfüllung
		double dDeltaStrecke = this->p_dGesamtStrecke - dGesamtStreckeVA;

		//Tankinhalt aktualisieren
		this->p_dTankinhalt -= dDeltaStrecke * this->p_dVerbrauch / 100;

		//Tankinhalt normalisieren, falls PKW liegenbleibt
		if (this->p_dTankinhalt < 0) {

			this->p_dTankinhalt = 0;

		}
	}

	this->p_dZeit = dGlobaleZeit;
	
}

void PKW::vAusgabe() {

	Fahrzeug::vAusgabe();
	cout << setprecision(2) << fixed << setw(12) << setiosflags(ios::left) << this->p_dVerbrauch << setw(12) << this->p_dTankinhalt << endl;
}

double PKW::dGeschwindigkeit() {
	
	//PKW fährt immer mit vMax
	return this->p_dMaxGeschwindigkeit;

}

ostream& PKW::ostreamAusgabe(ostream& out) {
	//nutzen der virtuellen Funktion aus Fahrzeug und weiteres Füllen mit Daten von PKW
	Fahrzeug::ostreamAusgabe(out) << setprecision(2) << fixed << setw(12) << setiosflags(ios::left) << this->p_dVerbrauch << setw(12) << this->p_dTankinhalt;

	return out;
}
