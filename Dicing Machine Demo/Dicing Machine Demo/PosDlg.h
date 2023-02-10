#pragma once
#include "afxdialogex.h"
#include "Googol.h"

// PosDlg 对话框

class PosDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PosDlg)

public:
	PosDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~PosDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_POS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonStart();
	CComboBox mComboAxis;
	CEdit mEditAcc;
	CEdit mEditDec;
	CEdit mEditVel;
	CEdit mEditPos;
	CEdit mEditGetPrfVel;
	CEdit mEditGetPrfPos;
	CEdit mEditGetVel;
	CEdit mEditGetPos;
	afx_msg void OnBnClickedButtonStop();
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

private:
	Googol* mGoogol = nullptr;

	int m_nAxis = 0;
};
