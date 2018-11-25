#include "AktivesVO.h"

int AktivesVO::p_iMaxID = 0;
map<string, AktivesVO*> AktivesVO::VOMap;

AktivesVO::AktivesVO() 
{
	vInitialisierung();
}

AktivesVO::AktivesVO(string name)
{
	vInitialisierung();
	p_sName = name;

	//Objekt in VOMap ablegen, falls Name noch nicht vorhanden. Sonst ebenfalls Exception werfen
	if (VOMap.find(this->p_sName) != VOMap.end()) throw string("Exception: Es gibt bereits ein VO mit gleichem Namen! (") + string(this->p_sName) + string(")");
	VOMap[this->p_sName] = this;
}

AktivesVO::~AktivesVO()
{
}

void AktivesVO::vInitialisierung() {
	p_iID = ++p_iMaxID;
	p_sName = "";
	p_dZeit = 0;

}

void AktivesVO::vAusgabe()
{
	cout << setprecision(2) << fixed << setw(5) << setiosflags(ios::left) << this->p_iID << setw(12) << this->p_sName
		<< setw(4) << ":";
}

ostream& AktivesVO::ostreamAusgabe(ostream & out)
{
	out << setprecision(2) << fixed << setw(5) << setiosflags(ios::left) << this->p_iID << setw(12) << this->p_sName
		<< setw(4) << ":";

	return out;
}

ostream& operator << (std::ostream& out, AktivesVO& aVO)
{
	//übergabe von out an die Memberüberladungen, damit out gefüllt wird
	return aVO.ostreamAusgabe(out);
}

istream & operator >> (istream & in, AktivesVO & aVO)
{
	return aVO.istreamEingabe(in);
}

istream & AktivesVO::istreamEingabe(istream & in)
{
	// Überprüfen, ob Name leer. Sonst Exception werfen.
	if (this->p_sName != "") throw string("Exception: Name des Verkerhsobjekts war nicht leer!");
	
	in >> this->p_sName;

	//Objekt in VOMap ablegen, falls Name noch nicht vorhanden. Sonst ebenfalls Exception werfen
	if (VOMap.find(this->p_sName) != VOMap.end()) throw string("Exception: Es gibt bereits ein VO mit gleichem Namen! (") + string(this->p_sName) + string(")");

	VOMap[this->p_sName] = this;

	return in;
}

string AktivesVO::getName() {
	return this->p_sName;
}

AktivesVO * AktivesVO::ptObjekt(string sName)
{
	if (VOMap.find(sName) == VOMap.end()) throw string("Exception: Es ist kein Element mit dem Namen '") + string(sName) + string("' vorhanden");

	return VOMap[sName];
}

void AktivesVO::clearMap()
{
	VOMap.clear();
}
