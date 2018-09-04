#include "Weg.h"
#include "Fahrzeug.h"



Weg::Weg()
{
}

Weg::Weg(string name, double länge, Begrenzung limit) : AktivesVO(name), p_dLänge(länge), p_eLimit(limit)
{
}


Weg::~Weg()
{
}

ostream & Weg::ostreamAusgabe(ostream & out)
{
	AktivesVO::ostreamAusgabe(out) << this->p_dLänge << " ( ";
	//Liste der angenommen Fahrzeuge in out laden:
	for (list<Fahrzeug*>::iterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		out << (*it)->getName() <<", " ;
	}

	out << " )";

	return out;
}

void Weg::vAbfertigung()
{
	for (list<Fahrzeug*>::iterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		(*it)->vAbfertigung();
	}
}

void Weg::vAnnahme(Fahrzeug* pFahrzeug)
{
	this->p_pFahrzeuge.push_back(pFahrzeug);
	pFahrzeug->vNeueStrecke(this);
}

void Weg::vAnnahme(Fahrzeug* pFahrzeug, double dStartzeitpunkt)
{
	this->p_pFahrzeuge.push_back(pFahrzeug);
	pFahrzeug->vNeueStrecke(this, dStartzeitpunkt);
}

double Weg::getLänge()
{
	return this->p_dLänge;
}

Begrenzung Weg::getBegrenzung()
{
	return p_eLimit;
}
