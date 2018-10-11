#pragma once
#include "AktivesVO.h"
#include <list>
#include "LazyListe.h"
class Fahrzeug;
using namespace std;
enum Begrenzung { Innerorts, Landstra�e, Autobahn }; //50 , 100 , unbegrenzt


class Weg :
	public AktivesVO
{
public:
	Weg();
	Weg(string name, double l�nge, Begrenzung limit = Autobahn, bool uVerbot = true);
	virtual ~Weg();
	ostream& ostreamAusgabe(ostream& out);
	void vAbfertigung();
	void vAnnahme(Fahrzeug * pFahrzeug);
	void vAnnahme(Fahrzeug* pFahrzeug, double dStartzeitpunkt);
	void vAbgabe(Fahrzeug * pFahrzeug);
	double getL�nge();
	double getSchranke();
	bool getUeberholverbot();
	void setSchranke(double schranke);
	Begrenzung getBegrenzung();
	

private:
	double p_dL�nge; //L�nge in kM
	double p_dSchranke; //virtuelle Schranke f�r das �berholverbotfeature
	LazyListe<Fahrzeug*> p_pFahrzeuge; //LazyListe mit Fahrzeugen
	//list<Fahrzeug*> p_pFahrzeuge;	//Liste mit Fahrzeugen
	Begrenzung p_eLimit;			//v-Limit
	bool p_bUeberholverbot;
	
};

