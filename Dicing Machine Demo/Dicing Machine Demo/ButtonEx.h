#pragma once

#ifndef _ButtonEx_H
#define _ButtonEx_H

#include "stdafx.h"
#include "afxwin.h"
#define  WM_BN_CLICK  WM_USER + 100

class CButtonEx :
	public CMFCButton
{
	DECLARE_DYNAMIC(CButtonEx)
public:
	
	CButtonEx(int nItem, int nSubitem, CRect rect ,HWND hParent, void * pData);
	
	virtual ~CButtonEx();

protected:

	DECLARE_MESSAGE_MAP()
	//点击响应函数
	afx_msg void OnBnClicked();

public:

	void ChangeColor();
public:
	//所属listctrl的行
	int m_inItem;
	//所属listctrl的列
	int m_inSubItem;
	//按钮所在的位置
	CRect m_rect;
	//按钮的父窗口
	HWND m_hParent;

	BOOL bEnable;
	//按钮带的用户自定义数据
	void * m_pData;

	COLORREF mColor = RGB(0, 0, 0);
};

#endif