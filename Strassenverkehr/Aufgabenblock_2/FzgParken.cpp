#include "FzgParken.h"
#include "Fahrzeug.h"



FzgParken::FzgParken()
{
}

FzgParken::FzgParken(Weg* p_pWeg, double dStartZeit) : FzgVerhalten(p_pWeg), dStartzeitpunkt(dStartZeit)
{
}




FzgParken::~FzgParken()
{
}

double FzgParken::dStrecke(Fahrzeug * pFahrzeug, double dZeit)
{
	if (dGlobaleZeit <= this->dStartzeitpunkt) {
		//pFahrzeug->setGesamtTime(0);
		return 0.0;
	}
	else
	{
		pFahrzeug->setTime(dGlobaleZeit);
		throw new Losfahren(pFahrzeug, this->p_pWeg); //fährt los, exception werfen
	}
		
}


