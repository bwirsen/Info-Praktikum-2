#pragma once
#include "FzgVerhalten.h"
#include "Fahrzeug.h"
#include "Streckenende.h"

class FzgFahren :
	public FzgVerhalten
{
public:
	//Konstruktor und Destruktor
	FzgFahren();
	FzgFahren(Weg* p_pWeg);
	~FzgFahren();
	//Übergibt die Streckendifferenz, die das Fahrzeug zum Abfertigungsschritt zurückgelegt hat
	//wirft auch eine Exception, falls das Streckenende erreicht wurde. dZeit ist die Zeitdifferenz seit der letzen Abfertigung
	double dStrecke(Fahrzeug* pFahrzeug, double dZeit);
};

