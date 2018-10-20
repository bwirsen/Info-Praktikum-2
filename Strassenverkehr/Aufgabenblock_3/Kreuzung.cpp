#include "Kreuzung.h"
#include "Fahrzeug.h"

inline bool bEqual(double x, double y)
{
	return (fabs(x - y) < 1e-6);
}

Kreuzung::Kreuzung(string sName, double dTankstelle) : AktivesVO(sName), p_dTankstelle(dTankstelle)
{
}

Kreuzung::~Kreuzung()
{
}

ostream& Kreuzung::ostreamAusgabe(ostream& out) 
{
	AktivesVO::ostreamAusgabe(out) << setprecision(2) << fixed // 2 Nachkommastellen
		<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(12) << this->p_dTankstelle // Tankstellenvolumen ausgeben
		<< resetiosflags(ios::right) << " ( ";

	//Durch Wegliste iterieren und out mit jedem Wegnamen f�llen 
	for (auto it = this->p_pWege.begin(); it != this->p_pWege.end(); it++)
	{
		out << (*it)->getName() << " "; 
	}
	out << ")";

	return out; //Streamvariable returnen 
}

void Kreuzung::vVerbinde(string sWegHin, string sWegRueck, double dWegLaenge, Kreuzung* pKreuzung, bool bUeberholverbot, Begrenzung eLimit)
{
	//dynamische Wege erstellen
	Weg* WegHin = new Weg(sWegHin, dWegLaenge, eLimit, bUeberholverbot);
	Weg* WegRueck = new Weg(sWegRueck, dWegLaenge, eLimit, bUeberholverbot);

	//Wege bekanntmachen
	WegHin->setRueckweg(WegRueck);
	WegRueck->setRueckweg(WegHin);

	//Wege und Kreuzungen bekanntmachen
	WegHin->setKreuzung(this);
	WegRueck->setKreuzung(pKreuzung);

	//Wege pushen
	this->p_pWege.push_back(WegRueck);
	pKreuzung->p_pWege.push_back(WegHin);
		
}

void Kreuzung::vTanken(Fahrzeug* pFahrzeug)
{
	//falls noch Sprit da, tanken
	if (!bEqual(this->p_dTankstelle, 0))
	{
		//und Inhalt aktualisieren
		this->p_dTankstelle -= pFahrzeug->dTanken();

		//und ggf. normalisieren
		if (this->p_dTankstelle < 0)
			this->p_dTankstelle = 0;
	}	
}

void Kreuzung::vAnnahme(Fahrzeug* pFahrzeug, double dParkzeit)
{
	//volltanken
	this->vTanken(pFahrzeug);
	//und an ersten Weg in der Liste �bergeben
	this->p_pWege.front()->vAnnahme(pFahrzeug, dParkzeit);
}

void Kreuzung::vAbfertigung()
{
	for (auto it = this->p_pWege.begin(); it != this->p_pWege.end(); it++)
	{
		(*it)->vAbfertigung();
	}
}

