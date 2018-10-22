#pragma once
#include "Weg.h"
#include "AktivesVO.h"

class FahrAusnahme
{
public:
	//Konstruktoren und Destruktoren
	FahrAusnahme();
	FahrAusnahme(Fahrzeug* p_pFahrzeug, Weg* p_pWeg);
	virtual ~FahrAusnahme();
	//reine Funktion zum Exception-Handling
	virtual void vBearbeiten() = 0;

protected:
	//Pointer auf das Fahrzeug, welches Exception wirft
	Fahrzeug* p_pFahrzeug;
	//Pointer auf Weg, auf dem das Fahrzeug steht
	Weg* p_pWeg;
};

