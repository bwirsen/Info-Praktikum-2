#pragma once
#include "FahrAusnahme.h"
#include "Weg.h"
class Losfahren :
	public FahrAusnahme
{
public:
	//Konstruktor und Destruktor
	Losfahren(Fahrzeug* p_pFahrzeug, Weg* p_pWeg);
	~Losfahren();
	//Funktion zum Abarbeiten der Exception
	void vBearbeiten();
};

