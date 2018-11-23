#include "AktivesVO.h"

int AktivesVO::p_iMaxID = 0;
AktivesVO::AktivesVO() 
{
	vInitialisierung();
}

AktivesVO::AktivesVO(string name)
{
	vInitialisierung();
	p_sName = name;
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
	if (this->p_sName != "") throw string("Exception: Name des Verkerhsobjekt war nicht leer!");
	
	in >> this->p_sName;

	return in;
}

string AktivesVO::getName() {
	return this->p_sName;
}
