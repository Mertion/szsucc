// Kerf.h : Kerf DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CKerfApp
// �йش���ʵ�ֵ���Ϣ������� Kerf.cpp
//

class CKerfApp : public CWinApp
{
public:
	CKerfApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
