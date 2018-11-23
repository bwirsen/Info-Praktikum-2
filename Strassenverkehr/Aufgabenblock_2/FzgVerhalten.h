#pragma once
#include "Weg.h"


class FzgVerhalten
{
public:
	//Konstruktor und Destruktor
	FzgVerhalten();
	FzgVerhalten(Weg* p_pWeg);
	virtual ~FzgVerhalten();
	//reine Funktion, implementiert in erbenden Klasen. Soll Streckendifferenz seit der letzten Abfertigung zur�ckgeben
	virtual double dStrecke(Fahrzeug* pFahrzeug, double dZeit) = 0;
	//getter Funktion f�r den Weg*
	virtual Weg* getWegPointer();

protected:
	Weg* p_pWeg;

};

