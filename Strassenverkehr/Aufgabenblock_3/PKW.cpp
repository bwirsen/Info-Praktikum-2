#include "PKW.h"



PKW::PKW(string name, double vMax, double vb, double vTank) : Fahrzeug(name, vMax),
p_dVerbrauch(vb), p_dTankvolumen(vTank)
{
	p_dTankinhalt = p_dTankvolumen / 2;
}


PKW::~PKW()
{
}

double PKW::dTanken(double dMenge)
{
	double dF�llmenge;
	// default Param, oder zu viel Tanken - > komplett f�llen
	if (dMenge == -1 || (this->p_dTankinhalt + dMenge > this->p_dTankinhalt)) {
		dF�llmenge = this->p_dTankvolumen - this->p_dTankinhalt;
		this->p_dTankinhalt = this->p_dTankvolumen;
		return dF�llmenge;
	}// sonst wie gew�nscht f�llen
	else {
		this->p_dTankinhalt += dMenge;
		return dMenge;
	}
}

void PKW::vAbfertigung()
{	
	if (this->p_dTankinhalt != 0) {
		// Strecke vor Abfertigung zwischenspeichern.
		double dGesamtStreckeVA = this->p_dGesamtStrecke;

		Fahrzeug::vAbfertigung();

		// Delta-Variable f�r die ben�tigte Streckendifferenz bzgl der Tankf�llung
		double dDeltaStrecke = this->p_dGesamtStrecke - dGesamtStreckeVA;

		//Tankinhalt aktualisieren
		this->p_dTankinhalt -= dDeltaStrecke * this->p_dVerbrauch / 100;

		//Tankinhalt normalisieren, falls PKW liegenbleibt
		if (this->p_dTankinhalt < 0) {

			this->p_dTankinhalt = 0;

			/*	
				Wichtig, auch hier noch mal eventuell eine Exception werfen.
				Szenario: Fahrzeug f�hrt mit letzem Tankinhalt bis zum Streckenende. Erst mal wird die restliche Strecke returnt.
				Die Exception aus dStrecke wird nur geworfen, falls kein wert returnt wird, also der Wagen bereits bei Abfertigung
				am Ende steht, also quasi eine Abfertigung sp�ter.
				Diese kann aber nur aufgerufen werden, falls noch Sprit im Tank ist.
				Deshalb, falls Tank leer und Wagen am Ende auch Exception werfen!
			*/

			if (this->getAbschnittStrecke() == this->p_pVerhalten->getWegPointer()->getL�nge()) {
				throw new Streckenende(this, this->p_pVerhalten->getWegPointer());
			}

		}
	}

	this->p_dZeit = dGlobaleZeit;
	
}

void PKW::vAusgabe() {

	Fahrzeug::vAusgabe();
	cout << setprecision(2) << fixed << setw(12) << setiosflags(ios::left) << this->p_dVerbrauch << setw(12) << this->p_dTankinhalt << endl;
}

double PKW::dGeschwindigkeit() {
	
	//Geschwindigkietslimit aus dem Verhalten, bzw dem Weg im Verhalten ziehen - wichtig enum, daher switch m�glich.
	Begrenzung p_eLimit = this->p_pVerhalten->getWegPointer()->getBegrenzung();
	
	switch (p_eLimit) {

	case 0: return 50; //Innerorts
		break;
	case 1: return 100;	//Landstra�e
		break;
	case 2:	return this->p_dMaxGeschwindigkeit;	//Autobahn
		break;
	default:			//Tritt nicht auf, aber zu Fehlererkennung n�tzlich
		return 0;

	}
}

void PKW::vZeichnen(Weg* pWeg) {

	double dRelPosition = this->getAbschnittStrecke() / pWeg->getL�nge(); //berechnet relativ zur L�nge zur�ckgelegte Strecke
	bZeichnePKW(this->getName(), pWeg->getName(), dRelPosition, this->dGeschwindigkeit(), this->p_dTankinhalt );

}

ostream& PKW::ostreamAusgabe(ostream& out) {
	//nutzen der virtuellen Funktion aus Fahrzeug und weiteres F�llen mit Daten von PKW
	Fahrzeug::ostreamAusgabe(out) << setprecision(2) << fixed << setw(12) << setiosflags(ios::left) << this->p_dVerbrauch << setw(12) << this->p_dTankinhalt;

	return out;
}
