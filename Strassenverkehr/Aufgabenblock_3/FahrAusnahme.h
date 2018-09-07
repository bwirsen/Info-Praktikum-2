#pragma once
#include "Weg.h"
#include "AktivesVO.h"

class FahrAusnahme
{
public:
	FahrAusnahme();
	FahrAusnahme(Fahrzeug* p_pFahrzeug, Weg* p_pWeg);
	virtual ~FahrAusnahme();
	virtual void vBearbeiten() = 0;

protected:
	Fahrzeug* p_pFahrzeug;
	Weg* p_pWeg;
};

