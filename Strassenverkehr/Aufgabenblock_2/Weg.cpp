#include "Weg.h"
#include "Fahrzeug.h"




Weg::Weg()
{
}

Weg::Weg(string name, double l�nge, Begrenzung limit) : AktivesVO(name), p_dL�nge(l�nge), p_eLimit(limit)
{
}


Weg::~Weg()
{
}

ostream & Weg::ostreamAusgabe(ostream & out)
{
	AktivesVO::ostreamAusgabe(out) << this->p_dL�nge << " ( ";
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
	for (auto it = this->p_pFahrzeuge.begin(); it != this->p_pFahrzeuge.end(); it++)
	{
		try {
			(*it)->vAbfertigung();
		}
		catch (FahrAusnahme* exception) //ein catch reicht: FahrAushname erh�lt pointer der Subklassen
		{
			exception->vBearbeiten(); //Ausnahme abarbeiten
		}
	}
	this->p_pFahrzeuge.vAktualisieren();
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

double Weg::getL�nge()
{
	return this->p_dL�nge;
}

Begrenzung Weg::getBegrenzung()
{
	return p_eLimit;
}

