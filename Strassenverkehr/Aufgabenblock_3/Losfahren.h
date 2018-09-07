#pragma once
#include "FahrAusnahme.h"
#include "Weg.h"
class Losfahren :
	public FahrAusnahme
{
public:
	Losfahren(Fahrzeug* p_pFahrzeug, Weg* p_pWeg);
	~Losfahren();
	void vBearbeiten();
};

