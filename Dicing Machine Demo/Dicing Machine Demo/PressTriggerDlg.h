#pragma once
#include "afxdialogex.h"


// PressTriggerDlg 对话框

class PressTriggerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PressTriggerDlg)

public:
	PressTriggerDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~PressTriggerDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_PRESSTRIGGER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CEdit mEditCounter;
	afx_msg void OnBnClickedButtonTest();

private:
	int m_nCounter = 0;
	int m_nCounter2 = 0;
	int m_nCounter3 = 10;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void Test();
};
