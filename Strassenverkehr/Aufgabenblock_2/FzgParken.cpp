#include "FzgParken.h"



FzgParken::FzgParken()
{
}

FzgParken::FzgParken(Weg * p_pWeg, double dStartZeit) : FzgVerhalten(p_pWeg), dStartzeitpunkt(dStartZeit)
{
}




FzgParken::~FzgParken()
{
}

double FzgParken::dStrecke(Fahrzeug * pFahrzeug, double dZeit)
{
	if (dGlobaleZeit <= this->dStartzeitpunkt)
		return 0.0;
	else
	{
		cout << "WARNUNG: EXCEPTION EXIT 2";
		cin.ignore();
		cin.ignore();
		exit(2);
	}
		
}


