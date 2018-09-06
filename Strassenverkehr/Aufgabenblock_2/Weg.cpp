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
	for (list<Fahrzeug*>::iterator it = this->p_pFahrzeuge.begin(); it != this->p_pFahrzeuge.end(); it++)
	{
		try {
			(*it)->vAbfertigung();
		}
		catch (FahrAusnahme* exception) //ein catch reicht: FahrAushname erhält pointer der Subklassen
		{
			exception->vBearbeiten(); //Ausnahme abarbeiten
		}
	}
}

void Weg::vAnnahme(Fahrzeug* pFahrzeug)
{
	this->p_pFahrzeuge.push_back(pFahrzeug);		//fahrende Fahrzeuge hinten
	pFahrzeug->vNeueStrecke(this);
}

void Weg::vAnnahme(Fahrzeug* pFahrzeug, double dStartzeitpunkt)
{
	this->p_pFahrzeuge.push_front(pFahrzeug);		//parkende Fahrzeuge hinten
	pFahrzeug->vNeueStrecke(this, dStartzeitpunkt);
}

void Weg::vAbgabe(Fahrzeug* pFahrzeug)
{
	list<Fahrzeug*>::iterator it = find(this->p_pFahrzeuge.begin(), this->p_pFahrzeuge.end(), pFahrzeug);
	
	if (it != this->p_pFahrzeuge.end()) //Falls it == end(), ist das Element nicht vorhanden
		this->p_pFahrzeuge.erase(it);

}

double Weg::getLänge()
{
	return this->p_dLänge;
}

Begrenzung Weg::getBegrenzung()
{
	return p_eLimit;
}
