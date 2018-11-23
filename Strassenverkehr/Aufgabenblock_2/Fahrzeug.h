#pragma once
#include <iostream>
#include <string>
#include <iomanip>

#include "AktivesVO.h"
#include "FzgFahren.h"
#include "FzgParken.h"

using namespace std;
extern double dGlobaleZeit;
class Fahrzeug : public AktivesVO
{
public:
	//Konstruktoren und Dekonstruktor
	Fahrzeug(string name);
	Fahrzeug(string name, double vMax);
	virtual ~Fahrzeug();
	//Ausgabefunktion des Tabellenheaders. Static, damit er Intanzenunabhängig aufgerufen werden kann
	static void vAusgabeKopf();
	//Ausgabefunktion mit später Bindung
	virtual void vAusgabe();
	//Abfertigungsfunktion mit später Bindung
	virtual void vAbfertigung();
	//Funktion zum Tanken der Fahrzeuge. Defaultwert tankt den Wagen voll
	virtual double dTanken(double dMenge = -1);
	//Funktion zur Rückgabe der Geschwindigkeit mit später Bindung
	virtual double dGeschwindigkeit();
	//Überladung des Streamoperators out
	virtual ostream& ostreamAusgabe(ostream& out);
	//Überladung des Vergleichoperators
	virtual bool operator<(const Fahrzeug& fahrzeug);
	//Funktion zur Übergabe des Fahrverhaltens an das Fahrzeug: FAHREN
	virtual void vNeueStrecke(Weg* pWeg);
	//Funktion zur Übergabe des Fahrverhaltens an das Fahrzeug: PARKEN
	virtual void vNeueStrecke(Weg* pWeg, double dStartzeitpunkt);
	//leere Funktion, Überladung in Subklassen
	virtual void vZeichnen(Weg * pWeg);
	//Überladung des Zuweisungsoperators.Wichtig: Rückgabe als Referenz, um dem Kopierkonstruktor nicht in die Wege zu kommen
	Fahrzeug& operator=(const Fahrzeug & fahrzeug);
	//getter und setter
	double getMaxGeschwindigkeit();
	double getAbschnittStrecke();
	void setTime(double dTime);
	void setGesamtTime(double dTime);


protected:
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dAbschnittStrecke;		//aktuelle zurückgelegte Strecke
	FzgVerhalten* p_pVerhalten;

private:
	void vInitialisierung();
};

