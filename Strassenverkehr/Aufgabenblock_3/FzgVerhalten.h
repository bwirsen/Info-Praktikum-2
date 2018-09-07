#pragma once
#include "Weg.h"


class FzgVerhalten
{
public:
	FzgVerhalten();
	FzgVerhalten(Weg* p_pWeg);
	virtual ~FzgVerhalten();
	virtual double dStrecke(Fahrzeug* pFahrzeug, double dZeit) = 0;
	virtual Weg* getWegPointer();

protected:
	Weg* p_pWeg;

};

