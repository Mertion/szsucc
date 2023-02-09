#pragma once

#ifndef _ListCrtlEx_H
#define _ListCrtlEx_H

#include "afxcmn.h"
#include "ButtonEx.h"
#include <map>

using namespace std;

typedef map<int, CButtonEx*> button_map;

// CListCtrlEx

class CListCtrlEx : public CListCtrl

{

	DECLARE_DYNAMIC(CListCtrlEx)

public:
	CListCtrlEx();
	virtual ~CListCtrlEx();

protected:

	DECLARE_MESSAGE_MAP()

public:

	//��̬����Button
	void createItemButton(int nItem, int nSubItem, HWND hMain, CWnd *pCWnd, CString strCaption, void * pData);
	
	//�ͷŴ�����Button

	void release();

	void deleteItemEx(int nItem);
	void deleteItemEx(int iCount, int nItem);
	button_map m_mButton;

public:

	UINT m_uID;

	int m_nCount = 0;

	CFont font;    //��ť���������

	void updateListCtrlButtonPos(); //���°�ť��λ��

	//void enableButton( BOOL bFlag, int iItem );

	//����ˮƽ��������������

	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

};


#endif