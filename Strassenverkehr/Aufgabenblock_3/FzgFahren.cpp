#include "FzgFahren.h"



FzgFahren::FzgFahren()
{
}

FzgFahren::FzgFahren(Weg* p_pWeg) : FzgVerhalten(p_pWeg)
{
}


FzgFahren::~FzgFahren()
{
}

double FzgFahren::dStrecke(Fahrzeug* pFahrzeug, double dZeit)
{
	if (this->p_pWeg->getUeberholverbot() == false)											//kein Ueberholverbot
	{
		double dRestStrecke = this->p_pWeg->getLänge() - pFahrzeug->getAbschnittStrecke();	//restliche Strecke bis zum Wegende

		if (pFahrzeug->getAbschnittStrecke() != this->p_pWeg->getLänge())					//falls noch nicht am Ende
		{
			double dStrecke = pFahrzeug->dGeschwindigkeit() * dZeit;						//hinzukommende gefahrene Strecke

			if (dStrecke >= dRestStrecke)													//falls Rest kleiner als zu fahrende Strecke...
			{
				return dRestStrecke; //...fahre nur bis zum Ende
			}
			else
				return dStrecke;															//sonst fahre so viel wie geht
		}
	}

	else
	{
		double dRestStrecke = this->p_pWeg->getLänge() - pFahrzeug->getAbschnittStrecke();	//restliche Strecke bis zum Wegende
		double dStrecke = pFahrzeug->dGeschwindigkeit() * dZeit;
		double dAbschnittNeu = pFahrzeug->getAbschnittStrecke() + dStrecke;					//potentiell neuer Streckenabschnitt nach Abfertigung
		double dSchranke = this->p_pWeg->getSchranke();
		if (pFahrzeug->getAbschnittStrecke() != this->p_pWeg->getLänge())					//falls noch nicht am Ende
		{
			if (dStrecke >= dRestStrecke && dAbschnittNeu < dSchranke)		//falls Rest kleiner als zu fahrende Strecke...
			{
				return dRestStrecke;										//...fahre nur bis zum Ende
			}
			else if (dAbschnittNeu > dSchranke)
			{
				return dSchranke - pFahrzeug->getAbschnittStrecke();		//...bzw bis zur Schranke, falls nötig		
			}
			else
				this->p_pWeg->setSchranke(pFahrzeug->getAbschnittStrecke() + dStrecke);		//sonst setze neue Schranke
				return dStrecke;															//und fahre so viel wie geht
		}
		
	}

	//Ausnahme werfen, da Strecke zu Ende
	throw new Streckenende(pFahrzeug, this->p_pWeg);  //pointer auf Fahrausnahme
}

