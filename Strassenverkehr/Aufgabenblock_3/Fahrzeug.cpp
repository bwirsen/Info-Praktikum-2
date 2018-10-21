#include "Fahrzeug.h"

inline bool bEqual(double x, double y)
{
	return (fabs(x - y) < 1e-6);
}

void Fahrzeug::vInitialisierung() {
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0;
	p_dMaxGeschwindigkeit = 0;
	p_dAbschnittStrecke = 0;
	p_pVerhalten = NULL;
}


Fahrzeug::Fahrzeug(string name) : AktivesVO(name)
{
	vInitialisierung();
}

Fahrzeug::Fahrzeug(string name, double vMax) : AktivesVO(name)
{
	vInitialisierung();
	p_dMaxGeschwindigkeit = vMax;
}


Fahrzeug::~Fahrzeug()
{
}

void Fahrzeug::vAusgabe()
{
	AktivesVO::vAusgabe();
	cout << setw(12) << this->p_dMaxGeschwindigkeit << setw(10) << this->dGeschwindigkeit() << setw(18) << this->p_dGesamtStrecke << setw(18) << this->p_dAbschnittStrecke
		<< setw(14) << this->p_dGesamtZeit << setw(8) << this->p_dZeit;
}

void Fahrzeug::vAusgabeKopf() {

	cout << setw(5) << setiosflags(ios::left) << "ID" << setw(12) << "Name"
		<< setw(4) << ":" << setw(12) << "MaxKm/h" << setw(10) << "Km/h" << setw(18) << "GesamtStrecke" << setw(18) << "StreckenAbschnitt"
		<< setw(14) << "GesamtZeit" << setw(8) << "Zeit" << setw(12) << "Verbrauch" << setw(12) << "Tankinhalt" << endl << endl;

}

void Fahrzeug::vAbfertigung()
{
	//Wenn schon abgefertigt, nichts machen, sonst abfertigen
	if (!bEqual(dGlobaleZeit, this->p_dZeit)) {

		double dDeltaZeit = dGlobaleZeit - this->p_dZeit;  // Zeitabschnitt

		double dDeltaStrecke = this->p_pVerhalten->dStrecke(this, dDeltaZeit);

		this->p_dGesamtStrecke += dDeltaStrecke;
		this->p_dAbschnittStrecke += dDeltaStrecke;

		this->p_dZeit = dGlobaleZeit;

		if (!bEqual(dDeltaStrecke, 0))								//Falls Wagen fährt, Fahrzeit aktualisieren
			this->p_dGesamtZeit += dDeltaZeit;
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

//Überladung von out für Fahrzeug
ostream& Fahrzeug::ostreamAusgabe(ostream& out)
{
	AktivesVO::ostreamAusgabe(out) << setw(12) << this->p_dMaxGeschwindigkeit << setw(10) << this->dGeschwindigkeit() << setw(18) << this->p_dGesamtStrecke << setw(18) << this->p_dAbschnittStrecke
		<< setw(14) << this->p_dGesamtZeit << setw(8) << this->p_dZeit;

	return out;
}

bool Fahrzeug::operator<(const Fahrzeug& fahrzeug)
{
	if (this->p_dGesamtStrecke < fahrzeug.p_dGesamtStrecke)
		return true;

	return false;
}

void Fahrzeug::vNeueStrecke(Weg* pWeg)
{
	delete p_pVerhalten;
	this->p_pVerhalten = new FzgFahren(pWeg);
	this->p_dAbschnittStrecke = 0;
}

void Fahrzeug::vNeueStrecke(Weg* pWeg, double dStartzeitpunkt)
{
	delete p_pVerhalten;
	this->p_pVerhalten = new FzgParken(pWeg, dStartzeitpunkt);
	this->p_dAbschnittStrecke = 0;
}

void Fahrzeug::vZeichnen(Weg* pWeg) {

}

Fahrzeug& Fahrzeug::operator=(const Fahrzeug& fahrzeug) 
{
	this->vInitialisierung();			//Fahrzeug zurücksetzen mit neuer ID, wichtig zur Identifikation
	this->p_sName = fahrzeug.p_sName;	//Namen kopieren (Es gibt ja mehrere gleiche Autos.. gleiche Modellnummer etc..)
	this->p_dMaxGeschwindigkeit = fahrzeug.p_dMaxGeschwindigkeit; //selbe Begründung wie Name
		
	return *this;	//This-Pointer, da Referenz
}

double Fahrzeug::getMaxGeschwindigkeit()
{
	return this->p_dMaxGeschwindigkeit;
}

double Fahrzeug::getAbschnittStrecke() {

	return this->p_dAbschnittStrecke;
}

void Fahrzeug::setTime(double dTime)
{
	this->p_dZeit = dTime;
}

void Fahrzeug::setGesamtTime(double dTime)
{
	this->p_dGesamtZeit = dTime;
}