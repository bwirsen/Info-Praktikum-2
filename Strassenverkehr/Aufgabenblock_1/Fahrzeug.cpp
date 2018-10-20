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
		<< setw(4) << ":" << setw(12) << this->p_dMaxGeschwindigkeit << setw(10) << this->dGeschwindigkeit() << setw(18) << this->p_dGesamtStrecke
		<< setw(14) << this->p_dGesamtZeit << setw(8) << this->p_dZeit;
}

void Fahrzeug::vAusgabeKopf() {

	cout << setw(5) << setiosflags(ios::left) << "ID" << setw(12) << "Name"
		<< setw(4) << ":" << setw(12) << "MaxKm/h" << setw(10) << "Km/h" << setw(18) << "GesamtStrecke"
		<< setw(14) << "GesamtZeit" << setw(8) << "Zeit" << setw(12) << "Verbrauch" << setw(12) << "Tankinhalt" << endl << endl;

}

void Fahrzeug::vAbfertigung()
{
	//Wenn schon abgefertigt, nicht machen
	if (dGlobaleZeit == this->p_dZeit) {

	}
	// sonst abfertigen
	else {
		double dDelta = dGlobaleZeit - this->p_dZeit;
		this->p_dGesamtStrecke += this->dGeschwindigkeit() * dDelta;	// s = v*t
		this->p_dZeit = dGlobaleZeit;
		this->p_dGesamtZeit += dDelta;									// +ZeitDiff	 
	}
}

double Fahrzeug::dTanken(double dMenge)
{
	// Defaultwert für alle Subklassen. Falls Überladung vorhanden, wird diese verwendet, da virtual.
	return 0.0;
}

double Fahrzeug::dGeschwindigkeit() {

	return 0;
}

//Überladung vom Streamoperator für die Fahrzeuge
ostream& Fahrzeug::ostreamAusgabe(ostream& out)
{
	out << setprecision(2) << fixed << setw(5) << setiosflags(ios::left) << this->p_iID << setw(12) << this->p_sName
		<< setw(4) << ":" << setw(12) << this->p_dMaxGeschwindigkeit << setw(10) << this->dGeschwindigkeit() << setw(18) << this->p_dGesamtStrecke
		<< setw(14) << this->p_dGesamtZeit << setw(8) << this->p_dZeit;

	return out;
}

bool Fahrzeug::operator<(const Fahrzeug& fahrzeug)
{
	if (this->p_dGesamtStrecke < fahrzeug.p_dGesamtStrecke)
		return true;

	return false;
}

Fahrzeug& Fahrzeug::operator=(const Fahrzeug& fahrzeug) 
{
	this->vInitialisierung();			//Fahrzeug zurücksetzen mit neuer ID, wichtig zur Identifikation
	this->p_sName = fahrzeug.p_sName;	//Namen kopieren (Es gibt ja mehrere gleiche Autos.. gleiche Modellnummer etc..)
	this->p_dMaxGeschwindigkeit = fahrzeug.p_dMaxGeschwindigkeit; //selbe Begründung wie Name
		
	return *this;	//This-Pointer, da Referenz
}
