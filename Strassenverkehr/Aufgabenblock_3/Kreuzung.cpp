#include "Kreuzung.h"
#include "Fahrzeug.h"

inline bool bEqual(double x, double y)
{
	return (fabs(x - y) < 1e-6);
}

Kreuzung::Kreuzung(string sName, double dTankstelle) : AktivesVO(sName), p_dTankstelle(dTankstelle)
{
}

Kreuzung::Kreuzung() : AktivesVO(), p_dTankstelle(0)
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

	//Durch Wegliste iterieren und out mit jedem Wegnamen füllen 
	for (auto it = this->p_pWege.begin(); it != this->p_pWege.end(); it++)
	{
		out << (*it)->getName() << " "; 
	}
	out << ")";

	return out; //Streamvariable returnen 
}

istream & Kreuzung::istreamEingabe(istream & in)
{
	AktivesVO::istreamEingabe(in) >> this->p_dTankstelle;
	return in;
}

void Kreuzung::vVerbinde(string sWegHin, string sWegRueck, double dWegLaenge, Kreuzung* pKreuzung, bool bUeberholverbot, Begrenzung eLimit)
{
	//dynamische Wege erstellen
	Weg* WegHin = new Weg(sWegHin, dWegLaenge, eLimit, bUeberholverbot);
	Weg* WegRueck = new Weg(sWegRueck, dWegLaenge, eLimit, bUeberholverbot);

	//TODO: Wege bekanntmachen
	WegHin->setRueckweg(WegRueck);
	WegRueck->setRueckweg(WegHin);

	//Wege und Kreuzungen bekanntmachen
	WegHin->setKreuzung(pKreuzung);
	WegRueck->setKreuzung(this);

	//Wege pushen
	this->p_pWege.push_back(WegHin);
	pKreuzung->p_pWege.push_back(WegRueck);
		
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
	//und an ersten Weg in der Liste übergeben
	this->p_pWege.front()->vAnnahme(pFahrzeug, dParkzeit);
}

void Kreuzung::vAbfertigung()
{
	for (auto it = this->p_pWege.begin(); it != this->p_pWege.end(); it++)
	{
		(*it)->vAbfertigung();
	}
}

Weg* Kreuzung::pZufaelligerWeg(Weg* pWegHin)
{
	//Falls es mehrere Wege gibt, wähle zufälligen
	if (this->p_pWege.size() != 1)
	{
		//Endlosschleife bis ein möglicher Weg gefunden wird. Vgl. Zeile 101
		while (true)
		{	
			//Zufallszahl zwischen 0 und size() der Liste
			int iRand = rand() % p_pWege.size();
			//setze Iterator auf Anfang der Liste
			auto it = p_pWege.begin();
			//inkr. bis zum gewünschten Index
			for (int i = 0; i < iRand; i++)
			{
				it++;
			}
			//teste auf unterschiedlichen Weg und gebe zurück, falls nicht, noch mal von vorn
			if ((*it)->getName() != pWegHin->getRueckweg()->getName())
				return *it;
		}
	}

	//sonst wähle Rückweg
	return pWegHin->getRueckweg();

}

double Kreuzung::getTankstellenInhalt() 
{
	return this->p_dTankstelle;
}

void Kreuzung::vZeichnen() 
{
	for (auto it = this->p_pWege.begin(); it != this->p_pWege.end(); it++)
	{
		(*it)->vZeichnen();
	}
}

