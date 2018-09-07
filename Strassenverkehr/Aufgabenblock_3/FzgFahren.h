#pragma once
#include "FzgVerhalten.h"
#include "Fahrzeug.h"
#include "Streckenende.h"

class FzgFahren :
	public FzgVerhalten
{
public:
	FzgFahren();
	FzgFahren(Weg* p_pWeg);
	~FzgFahren();
	double dStrecke(Fahrzeug * pFahrzeug, double dZeit);
};

