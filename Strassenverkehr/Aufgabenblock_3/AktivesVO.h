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
	string getName();

protected:
	double p_dZeit;
	string p_sName;
	int p_iID;

private:
	static int p_iMaxID;
	void vInitialisierung();
};

