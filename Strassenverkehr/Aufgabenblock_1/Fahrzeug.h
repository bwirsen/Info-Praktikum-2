#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//Bekanntmachung der globalen Zeit für die Klasse Fahrzeug
extern double dGlobaleZeit;
class Fahrzeug
{
public:
	//Konstruktoren und Dekonstruktor
	Fahrzeug();
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
	//Überladung des Zuweisungsoperators. Wichtig: Rückgabe als Referenz, um dem Kopierkonstruktor nicht in die Wege zu kommen
	Fahrzeug& operator=(const Fahrzeug & fahrzeug);

protected:
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;
	string p_sName;
	int p_iID;

private:
	//Standardinit. Wird im Konstruktor aufgerufen, daher private
	void vInitialisierung();
	//statische (instanzenunabhängige) Variable zum nummerieren der Fahrzeuge mit eindeutiger ID
	static int p_iMaxID;
	
};

