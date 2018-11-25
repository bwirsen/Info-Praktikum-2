#pragma once
#include "Kreuzung.h"
class Welt
{
public:
	Welt();
	~Welt();
	void vEinlesen(istream& in);
	void vEinlesenMitGrafik(istream& in);
	void vSimulation();

private:

	list<Kreuzung*> p_pKreuzungen;
};

