#pragma once
#include "AktivesVO.h"
#include <list>
#include "LazyListe.h"
class Fahrzeug;
using namespace std;
enum Begrenzung { Innerorts, Landstraﬂe, Autobahn }; //50 , 100 , unbegrenzt


class Weg :
	public AktivesVO
{
public:
	//Konstruktor und Destruktor
	Weg();
	Weg(string name, double l‰nge, Begrenzung limit = Autobahn);
	virtual ~Weg();
	//‹berladung des Ausgabe-Streamoperators
	ostream& ostreamAusgabe(ostream& out);
	//Funktion zum Abfertigen aller Fahrzeuge auf dem Weg
	void vAbfertigung();
	//Annahme von fahrenden Fahrzeugen
	void vAnnahme(Fahrzeug* pFahrzeug);
	//Annahme von parkenden Fahrzeugen
	void vAnnahme(Fahrzeug* pFahrzeug, double dStartzeitpunkt);
	//Funktion zur Abgabe von Fahrzeugen
	void vAbgabe(Fahrzeug* pFahrzeug);
	//getter und setter
	double getL‰nge();
	Begrenzung getBegrenzung();
	

private:
	double p_dL‰nge; //L‰nge in kM
	LazyListe<Fahrzeug*> p_pFahrzeuge; //LazyListe mit Fahrzeugen
	//list<Fahrzeug*> p_pFahrzeuge;	//Liste mit Fahrzeugen
	Begrenzung p_eLimit;			//v-Limit
	
};

