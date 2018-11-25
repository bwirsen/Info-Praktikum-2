#pragma once
#include <iostream>
#include <string>
#include <iomanip>

#include "AktivesVO.h"
#include "FzgFahren.h"
#include "FzgParken.h"

using namespace std;
extern double dGlobaleZeit;
class Fahrzeug : public AktivesVO
{
public:

	Fahrzeug(string name);
	Fahrzeug(string name, double vMax);
	Fahrzeug();
	virtual ~Fahrzeug();
	static void vAusgabeKopf();
	virtual void vAusgabe();
	virtual void vAbfertigung();
	virtual double dTanken(double dMenge = -1);
	virtual double dGeschwindigkeit();
	virtual ostream& ostreamAusgabe(ostream& out);
	virtual istream& istreamEingabe(istream& in);
	virtual bool operator<(const Fahrzeug& fahrzeug);
	virtual void vNeueStrecke(Weg* pWeg);
	virtual void vNeueStrecke(Weg* pWeg, double dStartzeitpunkt);
	virtual void vZeichnen(Weg* pWeg);
	Fahrzeug& operator=(const Fahrzeug & fahrzeug);
	double getMaxGeschwindigkeit();
	double getAbschnittStrecke();
	void setTime(double dTime);
	void setGesamtTime(double dTime);


protected:
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dAbschnittStrecke;		//aktuelle zurückgelegte Strecke
	FzgVerhalten* p_pVerhalten;

private:
	void vInitialisierung();
};