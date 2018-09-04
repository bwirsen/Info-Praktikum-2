#pragma once
#include "FzgVerhalten.h"

extern double dGlobaleZeit;

class FzgParken :
	public FzgVerhalten
{
public:
	FzgParken();
	FzgParken(Weg* p_pWeg, double dStartzeitpunkt);
	~FzgParken();
	double dStrecke(Fahrzeug * pFahrzeug, double dZeit);

private:
	double dStartzeitpunkt;
};

