#pragma once

#ifndef _Googol_H
#define _Googol_H

#include "gts.h"

#pragma comment (lib, "gts.lib")

class Googol
{
public:
	Googol();
	~Googol();

	int Open();

	int GetState(int nAxis, double p_dPrfPos, double p_dPrfVel, double p_dPos, double p_dVel);
	int JogMove(int p_nAxis, double p_dAcc, double p_dDec, double p_dVel);
	int PosMove(int p_nAxis, double p_dAcc, double p_dDec, long p_nPos, double p_dVel);
	int StopAll();
	int StopAxis(int p_nAxis);
	int AutoHome(int p_nAxis);
	bool GetIsOpen() const { return mIsOpen; }
	void SetIsOpen(bool val) { mIsOpen = val; }
private:
	bool mIsOpen = false;

	short sRtn = 0;
	CString strTmp = _T("");
	double prfPos = 0.0, prfVel = 0.0, encPos = 0.0, encVel = 0.0;
};

#endif
