#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "SimuClient.h"
using namespace std;

class AktivesVO
{
public:
	AktivesVO();
	AktivesVO(string name);
	virtual ~AktivesVO() = 0;
	virtual void vAusgabe();
	virtual void vAbfertigung() = 0;
	virtual ostream& ostreamAusgabe(ostream& out);
	virtual istream& istreamEingabe(istream& in);
	string getName();
protected:
	double p_dZeit;
	string p_sName;
	int p_iID;

private:
	static int p_iMaxID;
	void vInitialisierung();
};

/*�berladung des Streamoperators << um Fahrzeuge und Subklassen davon direkt ausgeben zu k�nnen. */
ostream& operator << (ostream& out, AktivesVO& aVO);
//�berladung istream - Operator >>
istream& operator >> (istream& in, AktivesVO& aVO);
