#pragma once
#include <list>

#include "AktivesVO.h"
#include "Weg.h"
using namespace std;
class Fahrzeug;

class Kreuzung :
	public AktivesVO
{
public:
	Kreuzung(string sName, double dTankstelle = 0);

	~Kreuzung();

	ostream & ostreamAusgabe(ostream & out);

	void vVerbinde(string sWegHin, string sWegRueck, double dWegLaenge, Kreuzung* pKreuzung, bool bUeberholverbot = true, Begrenzung eLimit = Autobahn);

	void vTanken(Fahrzeug * pFahrzeug);

	void vAnnahme(Fahrzeug* pFahrzeug, double dParkzeit);

	void vAbfertigung();

private:
	double p_dTankstelle; //speichert das Volumen(Liter), dass einer Kreuzung zum Auftanken zur verfügung steht
	list<Weg*> p_pWege; //wegführende Wege
};
