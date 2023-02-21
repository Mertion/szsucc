// PressTriggerDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Dicing Machine Demo.h"
#include "afxdialogex.h"
#include "PressTriggerDlg.h"


// PressTriggerDlg 对话框

IMPLEMENT_DYNAMIC(PressTriggerDlg, CDialogEx)

PressTriggerDlg::PressTriggerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_PRESSTRIGGER, pParent)
{

}

PressTriggerDlg::~PressTriggerDlg()
{
}

void PressTriggerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_Counter, mEditCounter);
}


BEGIN_MESSAGE_MAP(PressTriggerDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &PressTriggerDlg::OnBnClickedOk)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON_TEST, &PressTriggerDlg::OnBnClickedButtonTest)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// PressTriggerDlg 消息处理程序


void PressTriggerDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void PressTriggerDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnLButtonDown(nFlags, point);
}


BOOL PressTriggerDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_LBUTTONDOWN )
	{
		CPoint pnt;
		GetCursorPos(&pnt);//光标位置
		CRect rectBtn;
		GetDlgItem(IDC_BUTTON_TEST)->GetWindowRect(&rectBtn);
		if (rectBtn.PtInRect(pnt)) //光标是否在按钮范围内  
		{
			SetTimer(7, 100, NULL);
		}
	}
	if (pMsg->message == WM_LBUTTONUP)
	{
		CPoint pnt;
		GetCursorPos(&pnt);//光标位置
		CRect rectBtn;
		GetDlgItem(IDC_BUTTON_TEST)->GetWindowRect(&rectBtn);
		if (rectBtn.PtInRect(pnt)) //光标是否在按钮范围内  
		{
			KillTimer(7);
			m_nCounter2 = 0;
			m_nCounter3 = 10;
		}
	}


	return CDialogEx::PreTranslateMessage(pMsg);
}


void PressTriggerDlg::OnBnClickedButtonTest()
{
	// TODO: 在此添加控件通知处理程序代码

	
}


void PressTriggerDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent)
	{
	case 7:
	{
		Test();
	}
		break;
	default:
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}

void PressTriggerDlg::Test()
{
	if ((m_nCounter3 <= 0)||(m_nCounter2% m_nCounter3 ==0))
	{
		m_nCounter++;
		CString str;
		str.Format(_T("%d"), m_nCounter);

		mEditCounter.SetWindowTextW(str);

		m_nCounter3--;
	}
	
	m_nCounter2++;
}