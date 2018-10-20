#pragma once
#include "FahrAusnahme.h"
#include "Kreuzung.h"

class Streckenende :
	public FahrAusnahme
{
public:
	Streckenende(Fahrzeug* p_pFahrzeug, Weg* p_pWeg);
	~Streckenende();
	void vBearbeiten();
};

