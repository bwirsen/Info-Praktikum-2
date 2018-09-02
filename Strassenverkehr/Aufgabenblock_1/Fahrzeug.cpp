#include "Fahrzeug.h"

//static Variable zur Durchnumerierung definieren
int Fahrzeug::p_iMaxID = 0;

void Fahrzeug::vInitialisierung() {
	p_iID = ++p_iMaxID;
	p_sName = "";
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0;
	p_dMaxGeschwindigkeit = 0;
	p_dZeit = 0;
}

Fahrzeug::Fahrzeug() : p_sName("")
{
	vInitialisierung();
	//cout << "ERZEUGE" << endl << "Name: kein Name" << endl << "ID:" << p_iID << endl;
}

Fahrzeug::Fahrzeug(string name)
{
	vInitialisierung();
	p_sName = name;
	//cout << "ERZEUGE" << endl << "Name:" << p_sName << endl << "ID:" << p_iID << endl;

}

Fahrzeug::Fahrzeug(string name, double vMax)
{
	vInitialisierung();
	p_sName = name;
	p_dMaxGeschwindigkeit = vMax;
}


Fahrzeug::~Fahrzeug()
{
	cout << "ENTFERNE" << endl << "Name:" << p_sName << endl << "ID:" << p_iID << endl;
}

void Fahrzeug::vAusgabe()
{

	cout << setprecision(2) << fixed << setw(5) << setiosflags(ios::left) << this->p_iID << setw(12) << this->p_sName
		<< setw(4) << ":" << setw(12) << this->p_dMaxGeschwindigkeit << setw(18) << this->p_dGesamtStrecke
		<< setw(12) << this->p_dGesamtZeit << setw(12) << this->p_dZeit << endl;
}

void Fahrzeug::vAusgabeKopf() {

	cout << setw(5) << setiosflags(ios::left) << "ID" << setw(12) << "Name"
		<< setw(4) << ":" << setw(12) << "MaxKmh" << setw(18) << "GesamtStrecke"
		<< setw(12) << "GesamtZeit" << setw(12) << "Zeit" << endl << endl;

}

void Fahrzeug::vAbfertigung()
{
	if (dGlobaleZeit == this->p_dZeit) {

	}
	else {

		this->p_dGesamtStrecke += this->p_dMaxGeschwindigkeit * (dGlobaleZeit - this->p_dZeit);
		this->p_dZeit = dGlobaleZeit;
		this->p_dGesamtZeit = dGlobaleZeit;
	}
}

double Fahrzeug::dTanken()
{
	return 0.0;
}
