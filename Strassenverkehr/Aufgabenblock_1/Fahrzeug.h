#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
extern double dGlobaleZeit;
class Fahrzeug
{
public:
	Fahrzeug();
	Fahrzeug(string name);
	Fahrzeug(string name, double vMax);
	virtual ~Fahrzeug();

	void vAusgabeKopf();
	virtual void vAusgabe();
	virtual void vAbfertigung();
	virtual double dTanken();

protected:
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;
	string p_sName;
	int p_iID;

private:
	void vInitialisierung();
	static int p_iMaxID;
	
};

