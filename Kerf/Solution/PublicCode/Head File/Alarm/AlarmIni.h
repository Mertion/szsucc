#pragma once

#include "FileOperation/CINIObject.h"

class AlarmIni
{
public:
private:
	AlarmIni();
public:
	static AlarmIni* initance();
	
	//��ȡ��־����
	int getLogSwitch();
	// ��ȡ��ǰ����
	int getLanguage();
	//���õ�ǰ����
	void setLanguage(int p_nLanguage);
private:
	static AlarmIni* m_psysini;
	CINIObject* m_pCINIObject = NULL;
};

