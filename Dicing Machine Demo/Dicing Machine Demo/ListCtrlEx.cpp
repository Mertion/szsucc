#include "stdafx.h"
#include "ListCtrlEx.h"

#include "resource.h"

IMPLEMENT_DYNAMIC(CListCtrlEx, CListCtrl)

CListCtrlEx::CListCtrlEx()
{
	m_uID = 1200;

	font.CreatePointFont(100, _T("����"));
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

	//�����¼�������������Ϊ���ܹ������ı���ɫ
	pButton->m_bTransparent = FALSE;
	pButton->m_bDontUseWinXPTheme = TRUE;
	pButton->m_bDrawFocus = FALSE;
	pButton->m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;
	pButton->SetFont(&font);

	// m_mButton.insert( make_pair( nItem, pButton ) );    //���������

	
	m_mButton.insert(make_pair(m_nCount, pButton)); //���к��������
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

	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ    
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
//	//���������
//
//	int posx = GetScrollPos(SB_HORZ);//ȡ��ˮƽ��������λ��
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

	//���������

	int posx = GetScrollPos(SB_HORZ);//ȡ��ˮƽ��������λ��
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

				//�����Ķ���������ʾ��Χ
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

