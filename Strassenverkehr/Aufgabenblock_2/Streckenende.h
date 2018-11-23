#pragma once
#include "FahrAusnahme.h"
class Streckenende :
	public FahrAusnahme
{
public:
	//Konstruktor und Destruktor
	Streckenende(Fahrzeug* p_pFahrzeug, Weg* p_pWeg);
	~Streckenende();
	//Funktion zum Abarbeiten der Exception
	void vBearbeiten();
};

