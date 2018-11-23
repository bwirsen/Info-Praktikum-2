#pragma once
#include "FzgVerhalten.h"
#include "Losfahren.h"

extern double dGlobaleZeit;

class FzgParken :
	public FzgVerhalten
{
public:
	//Konstruktor und Destruktor
	FzgParken();
	FzgParken(Weg* p_pWeg, double dStartzeitpunkt);
	~FzgParken();
	//Übergibt die Streckendifferenz, die das Fahrzeug zum Abfertigungsschritt zurückgelegt hat
	//wirft auch eine Exception, falls die Zeit zum Starten erreicht wurde. dZeit ist die Zeitdifferenz seit der letzen Abfertigung
	double dStrecke(Fahrzeug* pFahrzeug, double dZeit);

private:
	//Zeitpunkt, bei dem das Fahrzeug starten soll
	double dStartzeitpunkt;
};

