#pragma once
#include "Weg.h"

class FzgVerhalten
{
public:
	FzgVerhalten();
	FzgVerhalten(Weg* p_pWeg);
	~FzgVerhalten();
	virtual double dStrecke(Fahrzeug* pFahrzeug, double dZeit);

private:
	Weg* p_pWeg;

};

