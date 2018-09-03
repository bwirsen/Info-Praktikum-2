#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "AktivesVO.h"
#include "FzgVerhalten.h"

using namespace std;
extern double dGlobaleZeit;
class Fahrzeug : public AktivesVO
{
public:

	Fahrzeug(string name);
	Fahrzeug(string name, double vMax);
	virtual ~Fahrzeug();
	static void vAusgabeKopf();
	virtual void vAusgabe();
	virtual void vAbfertigung();
	virtual double dTanken(double dMenge = -1);
	virtual double dGeschwindigkeit();
	virtual ostream& ostreamAusgabe(ostream& out);
	virtual bool operator<(const Fahrzeug& fahrzeug);
	virtual void vNeueStrecke(Weg* pWeg);
	Fahrzeug& operator=(const Fahrzeug & fahrzeug);
	double getMaxGeschwindigkeit();
	double getAbschnittStrecke();


protected:
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dAbschnittStrecke;		//aktuelle zur�ckgelegte Strecke
	FzgVerhalten* p_pVerhalten;

private:
	void vInitialisierung();
};

