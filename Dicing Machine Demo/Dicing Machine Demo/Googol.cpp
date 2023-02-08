#include "stdafx.h"
#include "Googol.h"

Googol::Googol()
{

}

Googol::~Googol()
{

}

int Googol::Open()
{
	short sRtn;
	sRtn = GT_Open();
	return sRtn;
}
