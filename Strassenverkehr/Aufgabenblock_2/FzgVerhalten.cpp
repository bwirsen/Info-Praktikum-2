#include "FzgVerhalten.h"
#include "Fahrzeug.h"



FzgVerhalten::FzgVerhalten()
{
}

FzgVerhalten::FzgVerhalten(Weg* p_pWeg) : p_pWeg(p_pWeg)
{
}


FzgVerhalten::~FzgVerhalten()
{
}

Weg* FzgVerhalten::getWegPointer()
{
	return this->p_pWeg;
}



