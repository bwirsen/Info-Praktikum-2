#include "FzgVerhalten.h"
#include "Fahrzeug.h"



FzgVerhalten::FzgVerhalten()
{
}

FzgVerhalten::FzgVerhalten(Weg* p_pWeg) : p_pWeg(p_pWeg)
{
}


FzgVerhalten::~FzgVerhalten()
{
}

double FzgVerhalten::dStrecke(Fahrzeug* pFahrzeug, double dZeit)
{
	double dRestStrecke = this->p_pWeg->getLänge() - pFahrzeug->getAbschnittStrecke();	//restliche Strecke bis zum Wegende

	if (pFahrzeug->getAbschnittStrecke() != this->p_pWeg->getLänge())						//falls noch nicht am Ende
	{
		double dStrecke = pFahrzeug->getMaxGeschwindigkeit() * dZeit;					//hinzukommende gefahrene Strecke

		if (dStrecke >= dRestStrecke)													//falls Rest kleiner als zu fahrende Strecke...
		{
			return dRestStrecke;														//...fahre nur bis zum Ende
		}
		else
			return dStrecke;															//sonst fahre so viel wie geht
	}


	cout << endl << "WARNING: EXIT EXCEPTION" << endl;
	cin.ignore();
	cin.ignore();

	exit(1);	//falls kein return, also der Weg zu Ende ist, beende das Programm
}

