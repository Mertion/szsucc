#include "stdafx.h"
#include "ButtonEx.h"

//IMPLEMENT_DYNAMIC(CButtonEx, CButtonEx)
IMPLEMENT_DYNAMIC(CButtonEx, CMFCButton)

CButtonEx::CButtonEx(int nItem, int nSubItem, CRect rect, HWND hParent, void * pData)
{
	m_inItem = nItem;
	m_inSubItem = nSubItem;
	m_rect = rect;
	m_hParent = hParent;
	bEnable = TRUE;
	m_pData = pData;

	this->SetTextColor(RGB(255, 255, 255));
	this->SetFaceColor(mColor);
}

CButtonEx::~CButtonEx()
{
}

BEGIN_MESSAGE_MAP(CButtonEx, CButton)
	ON_CONTROL_REFLECT(BN_CLICKED, &CButtonEx::OnBnClicked)

END_MESSAGE_MAP()

// CButtonEx 消息处理程序
void CButtonEx::OnBnClicked()
{
	if (1 == *(int*)m_pData)
	{
		*(int*)m_pData = 0;
	}
	else
	{
		*(int*)m_pData = 1;
	}
	ChangeColor();

	// TODO: 在此添加控件通知处理程序代码
	::SendMessage(m_hParent, WM_BN_CLICK, m_inItem, m_inSubItem);   //

}
void CButtonEx::ChangeColor()
{
	COLORREF Color = RGB(0, 0, 0);
	if (1 == *(int*)m_pData)
	{
		//this->SetFaceColor(RGB(0, 0, 255));
		Color = RGB(0, 0, 255);
	}
	else
	{
		//this->SetFaceColor(RGB(0, 0, 0));
		Color = RGB(0, 0, 0);
	}

	if (mColor != Color)
	{
		mColor = Color;
		this->SetFaceColor(mColor);
	}
	
}