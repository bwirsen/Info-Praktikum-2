#pragma once
#include "AktivesVO.h"
#include <list>
class Fahrzeug;
using namespace std;
enum Begrenzung { Innerorts, Landstraﬂe, Autobahn }; //50 , 100 , unbegrenzt


class Weg :
	public AktivesVO
{
public:
	Weg();
	Weg(string name, double l‰nge, Begrenzung limit = Autobahn);
	virtual ~Weg();
	ostream& ostreamAusgabe(ostream& out);
	void vAbfertigung();
	void vAnnahme(Fahrzeug * pFahrzeug);
	void vAnnahme(Fahrzeug* pFahrzeug, double dStartzeitpunkt);
	double getL‰nge();
	Begrenzung getBegrenzung();
	

private:
	double p_dL‰nge; //L‰nge in kM
	list<Fahrzeug*> p_pFahrzeuge;	//Liste mit Fahrzeugen
	Begrenzung p_eLimit;			//v-Limit
	
};

