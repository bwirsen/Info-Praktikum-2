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
	//�bergibt die Streckendifferenz, die das Fahrzeug zum Abfertigungsschritt zur�ckgelegt hat
	//wirft auch eine Exception, falls das Streckenende erreicht wurde. dZeit ist die Zeitdifferenz seit der letzen Abfertigung
	double dStrecke(Fahrzeug* pFahrzeug, double dZeit);
};

