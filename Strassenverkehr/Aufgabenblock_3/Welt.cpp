#include "Welt.h"
#include "AktivesVO.h"
#include "PKW.h"
#include "Fahrrad.h"
#define ANZAHL_KOORDINATEN 12



Welt::Welt()
{
}


Welt::~Welt()
{
}

void Welt::vEinlesen(istream& in)
{
	string key;
	in >> key;
	do
	{
		if (key == "KREUZUNG")
		{	
			Kreuzung* kr = new Kreuzung();
			in >> *kr;
			this->p_pKreuzungen.push_back(kr);
		}
		else if (key == "STRASSE")
		{
			//Hilsvariablen
			string sWegHin, sWegRueck, sQuellKreuzung, sZielKreuzung;
			double dWegLaenge;
			Kreuzung *pQuellKreuzung, *pZielKreuzung;
			bool bUeberholverbot;
			int iLimit;

			in >> sQuellKreuzung >> sZielKreuzung >> sWegHin >> sWegRueck >> dWegLaenge >> iLimit >> bUeberholverbot;

			if (iLimit > 3 || iLimit < 0) throw string("Exception: Begrenzung!");

			pQuellKreuzung = (Kreuzung*)AktivesVO::ptObjekt(sQuellKreuzung); //typecast, damit kein Fehler entsteht
			pZielKreuzung = (Kreuzung*)AktivesVO::ptObjekt(sZielKreuzung);

			pQuellKreuzung->vVerbinde(sWegHin, sWegRueck, dWegLaenge, pZielKreuzung, bUeberholverbot, (Begrenzung)(iLimit-1));	 
		}
		else if (key == "PKW")
		{
			PKW* pkw = new PKW();
			string sStartKreuzung;
			Kreuzung *pStartKreuzung;
			double dStartzeit;
			in >> *pkw >> sStartKreuzung >> dStartzeit;
			pStartKreuzung = (Kreuzung*)AktivesVO::ptObjekt(sStartKreuzung);
			pStartKreuzung->vAnnahme(pkw, dStartzeit);	
		}
		else if (key == "FAHRRAD")
		{
			Fahrrad* fr = new Fahrrad();
			string sStartKreuzung;
			Kreuzung *pStartKreuzung;
			double dStartzeit;
			in >> *fr >> sStartKreuzung >> dStartzeit;
			pStartKreuzung = (Kreuzung*)AktivesVO::ptObjekt(sStartKreuzung);
			pStartKreuzung->vAnnahme(fr, dStartzeit);
		}
		else
		{
			throw string("Exception: '") + string(key) + string("' ist kein Schlüsselwort");
		}
			
		key = "";
		in >> key;
		cout << key << endl;

	}	
	while (key != "");
}

void Welt::vEinlesenMitGrafik(istream & in)
{
	string key;
	in >> key;
	do
	{
		if (key == "KREUZUNG")
		{
			Kreuzung* kr = new Kreuzung();
			int iCoordsKreuzung[2];
			in >> *kr >> iCoordsKreuzung[0] >> iCoordsKreuzung[1];
			this->p_pKreuzungen.push_back(kr);
			bZeichneKreuzung(iCoordsKreuzung[0], iCoordsKreuzung[1]);
		}
		else if (key == "STRASSE")
		{
			//Hilsvariablen
			string sWegHin, sWegRueck, sQuellKreuzung, sZielKreuzung;
			double dWegLaenge;
			Kreuzung *pQuellKreuzung, *pZielKreuzung;
			bool bUeberholverbot;
			int iAnzahlKoordinaten, iLimit;
			int iCoords[ANZAHL_KOORDINATEN] = { 0 };
			
			in >> sQuellKreuzung >> sZielKreuzung >> sWegHin >> sWegRueck >> dWegLaenge >> iLimit >> bUeberholverbot >> iAnzahlKoordinaten;

			if (iLimit > 3 || iLimit < 0) throw string("Exception: Begrenzung!");
		
			pQuellKreuzung = (Kreuzung*)AktivesVO::ptObjekt(sQuellKreuzung); //typecast, damit kein Fehler entsteht
			pZielKreuzung = (Kreuzung*)AktivesVO::ptObjekt(sZielKreuzung);
			pQuellKreuzung->vVerbinde(sWegHin, sWegRueck, dWegLaenge, pZielKreuzung, bUeberholverbot, (Begrenzung)(iLimit-1));
			
			//Array der Koordinaten füllen
			for (int i = 0; i < 2*iAnzahlKoordinaten; i++)
			{
				in >> iCoords[i];
			}

			bZeichneStrasse(sWegHin, sWegRueck, dWegLaenge, iAnzahlKoordinaten, iCoords);
		
		}
		else if (key == "PKW")
		{
			PKW* pkw = new PKW();
			string sStartKreuzung;
			Kreuzung *pStartKreuzung;
			double dStartzeit;
			in >> *pkw >> sStartKreuzung >> dStartzeit;
			pStartKreuzung = (Kreuzung*)AktivesVO::ptObjekt(sStartKreuzung);
			pStartKreuzung->vAnnahme(pkw, dStartzeit);
			cout << *pStartKreuzung << endl;
		}
		else if (key == "FAHRRAD")
		{
			Fahrrad* fr = new Fahrrad();
			string sStartKreuzung;
			Kreuzung *pStartKreuzung;
			double dStartzeit;
			in >> *fr >> sStartKreuzung >> dStartzeit;
			pStartKreuzung = (Kreuzung*)AktivesVO::ptObjekt(sStartKreuzung);
			pStartKreuzung->vAnnahme(fr, dStartzeit);
		}
		else
		{
			throw string("Exception: '") + string(key) + string("' ist kein Schlüsselwort");
		}

		key = "";
		in >> key;

	} while (key != "");
}

void Welt::vSimulation()
{
	for (auto it = this->p_pKreuzungen.begin(); it != this->p_pKreuzungen.end(); it++)
	{
		(*it)->vAbfertigung();
		(*it)->vZeichnen();
		vSetzeZeit(dGlobaleZeit);
		//cout << *(this->p_pKreuzungen.front()) << endl;
	}
}
