#include "stdafx.h"
#include "ListCtrlEx.h"

#include "resource.h"

IMPLEMENT_DYNAMIC(CListCtrlEx, CListCtrl)

CListCtrlEx::CListCtrlEx()
{
	m_uID = 1200;

	font.CreatePointFont(100, _T("宋体"));
}

CListCtrlEx::~CListCtrlEx()
{
	release();
}
BEGIN_MESSAGE_MAP(CListCtrlEx, CListCtrl)

	//ON_MESSAGE(WM_BN_CLICK, &CListCtrlEx::onBnCLick)
END_MESSAGE_MAP()
void CListCtrlEx::createItemButton(int nItem, int nSubItem, HWND hMain, CWnd *pCWnd, CString strCaption, void * pData)
{
	CRect rect;
	/*if( !EnsureVisible(nItem, TRUE))
	return ;*/
	GetSubItemRect(nItem, nSubItem, LVIR_BOUNDS, rect);
	rect.left = 10 + nSubItem * 50;
	rect.top = 10 + nItem * 50;

	rect.bottom = rect.top + 30;
	rect.right = rect.left + 30;
	DWORD dwStyle = WS_CHILD | WS_VISIBLE | BS_MULTILINE;
	CButtonEx *pButton = new CButtonEx(nItem, nSubItem, rect, hMain, pData);
	m_uID++;
	CString t_ca = _T("1");
	pButton->Create(strCaption, dwStyle, rect, this, m_uID);

	//加以下几个属性设置是为了能够正常改变颜色
	pButton->m_bTransparent = FALSE;
	pButton->m_bDontUseWinXPTheme = TRUE;
	pButton->m_bDrawFocus = FALSE;
	pButton->m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;
	pButton->SetFont(&font);

	// m_mButton.insert( make_pair( nItem, pButton ) );    //纵向添加用

	
	m_mButton.insert(make_pair(m_nCount, pButton)); //单行横向添加用
	m_nCount++;
	return;

}

void CListCtrlEx::release()
{
	//button_map::iterator iter = m_mButton.begin();
	//while (iter != m_mButton.end())
	//{
	//	delete iter->second;
	//	iter->second = NULL;
	//	iter++;
	//}

	//m_mButton.clear();

	button_map::iterator iter;
	iter = m_mButton.begin();
	while (iter != m_mButton.end())
	{
		delete iter->second;
		iter->second = NULL;
		iter++;
	}
}

void CListCtrlEx::deleteItemEx(int iCount, int nItem)
{
	//int iCount = GetItemCount();
	DeleteItem(nItem);
	button_map::iterator iter;
	button_map::iterator iterNext;
#ifdef USE_TOPINDEX_BUTTON
	//add-----------------------------------
	iter = m_mButton.find(nItem);
	iterNext = iter;
	iterNext++;
	while (iterNext != m_mButton.end())
	{
		iter->second->bEnable = iterNext->second->bEnable;
		iterNext++;
		iter++;
	}
	//------------------------------
#endif
	iter = m_mButton.find(iCount - 1);
	if (iter != m_mButton.end())
	{
		delete iter->second;
		iter->second = NULL;
		m_mButton.erase(iter);
		//updateListCtrlButtonPos();
	}
}

void CListCtrlEx::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)

{

	// TODO: 在此添加消息处理程序代码和/或调用默认值    
	CListCtrl::OnHScroll(nSBCode, nPos, pScrollBar);

	updateListCtrlButtonPos();
	//Invalidate(FALSE);

}

//
//void CListCtrlEx::updateListCtrlButtonPos()
//{
//
//	button_map::iterator iter = m_mButton.begin();
//
//	button_map::iterator itrEnd = m_mButton.end();
//
//	//调整横向的
//
//	int posx = GetScrollPos(SB_HORZ);//取得水平滚动条的位置
//
//	for (; iter != itrEnd; ++iter)
//
//	{
//
//		CRect rect;
//
//		rect = iter->second->m_rect;
//
//		rect.left -= posx;
//
//		rect.right -= posx;
//
//		iter->second->ShowWindow(SW_HIDE);
//
//		iter->second->MoveWindow(&rect);
//
//		iter->second->ShowWindow(SW_SHOW);
//		/*if( iLine < iTopIndex )
//
//		{
//
//		iterUp->second->ShowWindow( SW_HIDE );
//
//		}*/
//
//	}
//
//	return;
//
//}

void CListCtrlEx::updateListCtrlButtonPos()

{

	button_map::iterator iter = m_mButton.begin();

	button_map::iterator itrEnd = m_mButton.end();

	CRect rect;

	GetClientRect(rect);

	LONG width = rect.right;

	//调整横向的

	int posx = GetScrollPos(SB_HORZ);//取得水平滚动条的位置
	for (; iter != itrEnd; ++iter)

	{

		iter->second->ShowWindow(SW_HIDE);

		rect = iter->second->m_rect;
		rect.left -= posx;

		rect.right -= posx;

		if (rect.right > 0)
		{
			if (rect.left > width)

			{

				//其他的都超出了显示范围
				break;

			}

			iter->second->MoveWindow(&rect);

			iter->second->ShowWindow(SW_SHOW);
		}


		/*if( iLine < iTopIndex )
		{

		iterUp->second->ShowWindow( SW_HIDE );
		}*/

	}
	return;

}

