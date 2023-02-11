#pragma once
#include "afxdialogex.h"
#include "Googol.h"

// PosDlg 对话框
#define  WM_RUNSTATE  WM_USER + 100
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

	Googol* GetGoogol() const { return mGoogol; }
	void SetGoogol(Googol* val) { mGoogol = val; }
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

	int PosMove();

	afx_msg LRESULT GetRunState(WPARAM wParam, LPARAM lParam);
private:
	Googol* mGoogol = nullptr;

	int m_nAxis = 0;
	int m_nPosRunCtrl = -1;
	unsigned int m_nTime = 0;
public:
	CButton mButtonStart;
	afx_msg void OnBnClickedButtonZero();
	afx_msg void OnCbnSelchangeComboAxis();
	CButton mButtonZero;
};
