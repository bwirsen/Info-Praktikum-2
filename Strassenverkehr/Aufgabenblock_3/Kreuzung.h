#pragma once
#include <list>

#include "AktivesVO.h"
#include "Weg.h"
using namespace std;
class Fahrzeug;

class Kreuzung :
	public AktivesVO
{
public:
	//Konstruktor und Dekonstruktor
	Kreuzung(string sName, double dTankstelle = 0);
	~Kreuzung();
	//Stream-Überladung zur Ausgabe der Kreuzung mit cout
	ostream & ostreamAusgabe(ostream & out);
	//Funktion zum Verbinden zweier Kreuzungen, Straßen werden automatisch erzeugt
	void vVerbinde(string sWegHin, string sWegRueck, double dWegLaenge, Kreuzung* pKreuzung, bool bUeberholverbot = true, Begrenzung eLimit = Autobahn);
	//Funktion zum (voll)tanken der Fahrzeuge
	void vTanken(Fahrzeug * pFahrzeug);
	//Funktion zur Annahme der Fahrzeuge an eine Kreuzung
	void vAnnahme(Fahrzeug* pFahrzeug, double dParkzeit);
	//Fertigt alle abgehende Wege der Kreuzung ab
	void vAbfertigung();
	//Funktion: wählt einen zufälligen abführenden Weg der Kreuzung aus
	Weg* pZufaelligerWeg(Weg* pWegHin);

	double getTankstellenInhalt();

	void vZeichnen();



private:
	double p_dTankstelle; //speichert das Volumen(Liter), dass einer Kreuzung zum Auftanken zur verfügung steht
	list<Weg*> p_pWege; //wegführende Wege
};
