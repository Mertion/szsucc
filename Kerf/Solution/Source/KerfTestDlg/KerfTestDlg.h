
// KerfTestDlg.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CKerfTestDlgApp: 
// �йش����ʵ�֣������ KerfTestDlg.cpp
//

class CKerfTestDlgApp : public CWinApp
{
public:
	CKerfTestDlgApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CKerfTestDlgApp theApp;