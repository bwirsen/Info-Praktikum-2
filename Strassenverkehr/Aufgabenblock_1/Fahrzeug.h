#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//Bekanntmachung der globalen Zeit f�r die Klasse Fahrzeug
extern double dGlobaleZeit;
class Fahrzeug
{
public:
	//Konstruktoren und Dekonstruktor
	Fahrzeug();
	Fahrzeug(string name);
	Fahrzeug(string name, double vMax);
	virtual ~Fahrzeug();
	//Ausgabefunktion des Tabellenheaders. Static, damit er Intanzenunabh�ngig aufgerufen werden kann
	static void vAusgabeKopf();
	//Ausgabefunktion mit sp�ter Bindung
	virtual void vAusgabe();
	//Abfertigungsfunktion mit sp�ter Bindung
	virtual void vAbfertigung();
	//Funktion zum Tanken der Fahrzeuge. Defaultwert tankt den Wagen voll
	virtual double dTanken(double dMenge = -1);
	//Funktion zur R�ckgabe der Geschwindigkeit mit sp�ter Bindung
	virtual double dGeschwindigkeit();
	//�berladung des Streamoperators out
	virtual ostream& ostreamAusgabe(ostream& out);
	//�berladung des Vergleichoperators
	virtual bool operator<(const Fahrzeug& fahrzeug);
	//�berladung des Zuweisungsoperators. Wichtig: R�ckgabe als Referenz, um dem Kopierkonstruktor nicht in die Wege zu kommen
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
	//statische (instanzenunabh�ngige) Variable zum nummerieren der Fahrzeuge mit eindeutiger ID
	static int p_iMaxID;
	
};

