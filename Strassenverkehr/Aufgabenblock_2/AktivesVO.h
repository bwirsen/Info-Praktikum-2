#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "SimuClient.h"
using namespace std;

class AktivesVO //abstrakt
{
public:
	//Konstruktoren
	AktivesVO();
	AktivesVO(string name);
	//reiner Dekonstruktor
	virtual ~AktivesVO() = 0;
	//Funktion zur Ausgabe 
	virtual void vAusgabe();
	//reine Abfertigungsfunktion -> Implementierung innerhalb der erbenden Funktionen
	virtual void vAbfertigung() = 0;
	//Funktion zum Füllen des Streamoperators, Baustein der Oberatorenüberladung
	virtual ostream& ostreamAusgabe(ostream& out);
	//getter/setter
	string getName();

protected:
	//Zeit der letzen Abfertigung
	double p_dZeit;
	//Name des Objekts
	string p_sName;
	//eindeutige ID des Objekts
	int p_iID;

private:
	//statische ID zur eindeutigen Zuordnung einer ID -> Instanzenunabh.
	static int p_iMaxID;
	//Init.-Funktion, setzt im Prinzip nur die ID und inkrementiert die static
	void vInitialisierung();
};

