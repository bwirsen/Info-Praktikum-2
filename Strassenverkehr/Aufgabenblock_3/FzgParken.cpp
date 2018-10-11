#include "FzgParken.h"
#include "Fahrzeug.h"

inline bool bEqual(double x, double y)
{
	return (fabs(x - y) < 1e-6);
}

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

	if (bEqual(dGlobaleZeit, this->dStartzeitpunkt)) //falls Starzeitpunkt erreicht
	{
		pFahrzeug->setTime(dGlobaleZeit);
		throw new Losfahren(pFahrzeug, this->p_pWeg); //fährt los, exception werfen als pointer
	}

	return 0;
		
}


