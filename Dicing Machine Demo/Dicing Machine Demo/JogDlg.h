#pragma once
#include "afxdialogex.h"
#include "Googol.h"

// JogDlg 对话框

class JogDlg : public CDialogEx
{
	DECLARE_DYNAMIC(JogDlg)

public:
	JogDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~JogDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_JOG };
#endif

	Googol* GetGoogol() const { return mGoogol; }
	void SetGoogol(Googol* val) { mGoogol = val; }
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	

private:
	Googol* mGoogol = nullptr;

	int m_nAxis = 0;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonStop();
	CComboBox mComboAxis;
	CEdit mEditAcc;
	CEdit mEditDec;
	CEdit mEditVel;
	CEdit mEditGetPrfVel;
	CEdit mEditGetPrfPos;
	CEdit mEditGetVel;
	CEdit mEditGetPos;
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
