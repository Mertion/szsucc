
// Dicing Machine Demo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDicingMachineDemoApp: 
// �йش����ʵ�֣������ Dicing Machine Demo.cpp
//

class CDicingMachineDemoApp : public CWinApp
{
public:
	CDicingMachineDemoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDicingMachineDemoApp theApp;