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

	//Ausnahme werfen, da Strecke zu Ende

	throw new Streckenende(pFahrzeug, this->p_pWeg);  //pointer auf Fahrausnahme

	/*
	cout << endl << "WARNING: EXIT EXCEPTION" << endl;
	cin.ignore();
	cin.ignore();
	exit(1);	//falls kein return, also der Weg zu Ende ist, beende das Programm 
	*/
}