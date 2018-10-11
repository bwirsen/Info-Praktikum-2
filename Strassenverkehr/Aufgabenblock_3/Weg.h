#pragma once
#include "AktivesVO.h"
#include <list>
#include "LazyListe.h"
class Fahrzeug;
using namespace std;
enum Begrenzung { Innerorts, Landstraße, Autobahn }; //50 , 100 , unbegrenzt


class Weg :
	public AktivesVO
{
public:
	Weg();
	Weg(string name, double länge, Begrenzung limit = Autobahn, bool uVerbot = true);
	virtual ~Weg();
	ostream& ostreamAusgabe(ostream& out);
	void vAbfertigung();
	void vAnnahme(Fahrzeug * pFahrzeug);
	void vAnnahme(Fahrzeug* pFahrzeug, double dStartzeitpunkt);
	void vAbgabe(Fahrzeug * pFahrzeug);
	double getLänge();
	double getSchranke();
	bool getUeberholverbot();
	void setSchranke(double schranke);
	Begrenzung getBegrenzung();
	

private:
	double p_dLänge; //Länge in kM
	double p_dSchranke; //virtuelle Schranke für das Überholverbotfeature
	LazyListe<Fahrzeug*> p_pFahrzeuge; //LazyListe mit Fahrzeugen
	//list<Fahrzeug*> p_pFahrzeuge;	//Liste mit Fahrzeugen
	Begrenzung p_eLimit;			//v-Limit
	bool p_bUeberholverbot;
	
};

