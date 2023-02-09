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

	//动态创建Button
	void createItemButton(int nItem, int nSubItem, HWND hMain, CWnd *pCWnd, CString strCaption, void * pData);
	
	//释放创建的Button

	void release();

	void deleteItemEx(int nItem);
	void deleteItemEx(int iCount, int nItem);
	button_map m_mButton;

public:

	UINT m_uID;

	int m_nCount = 0;

	CFont font;    //按钮上面的字体

	void updateListCtrlButtonPos(); //更新按钮的位置

	//void enableButton( BOOL bFlag, int iItem );

	//重载水平滚动条滚动函数

	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

};


#endif