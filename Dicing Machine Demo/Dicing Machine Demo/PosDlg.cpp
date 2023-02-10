// PosDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Dicing Machine Demo.h"
#include "afxdialogex.h"
#include "PosDlg.h"


// PosDlg 对话框

IMPLEMENT_DYNAMIC(PosDlg, CDialogEx)

PosDlg::PosDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_POS, pParent)
{

}

PosDlg::~PosDlg()
{
}

void PosDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_AXIS, mComboAxis);
	DDX_Control(pDX, IDC_EDIT_ACC, mEditAcc);
	DDX_Control(pDX, IDC_EDIT_DEC, mEditDec);
	DDX_Control(pDX, IDC_EDIT_VEL, mEditVel);
	DDX_Control(pDX, IDC_EDIT_POS, mEditPos);
	DDX_Control(pDX, IDC_EDIT_GETPRFVEL, mEditGetPrfVel);
	DDX_Control(pDX, IDC_EDIT_GETPRFPOS, mEditGetPrfPos);
	DDX_Control(pDX, IDC_EDIT_GETVEL, mEditGetVel);
	DDX_Control(pDX, IDC_EDIT_GETPOS, mEditGetPos);
}


BEGIN_MESSAGE_MAP(PosDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_START, &PosDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &PosDlg::OnBnClickedButtonStop)
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// PosDlg 消息处理程序


void PosDlg::OnBnClickedButtonStart()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strTmp;
	mComboAxis.GetWindowTextW(strTmp);
	m_nAxis = atoi((CStringA)strTmp);

	mEditAcc.GetWindowTextW(strTmp);
	double nAcc = atof((CStringA)strTmp);

	mEditDec.GetWindowTextW(strTmp);
	double nDec = atof((CStringA)strTmp);

	mEditVel.GetWindowTextW(strTmp);
	double nVel = atof((CStringA)strTmp);

	mEditPos.GetWindowTextW(strTmp);
	long nPos = atol((CStringA)strTmp);

	if (mGoogol != nullptr)
	{
		mGoogol->PosMove(m_nAxis, nAcc, nDec, nPos,nVel);
	}
	else
	{
		AfxMessageBox(_T("板上对象绑定错误！"));
	}
}


void PosDlg::OnBnClickedButtonStop()
{
	// TODO: 在此添加控件通知处理程序代码
	if (mGoogol != nullptr)
	{
		mGoogol->StopAxis(m_nAxis);
	}
}


void PosDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	if (mGoogol != nullptr)
	{
		mGoogol->StopAll();
	}
	KillTimer(0);
}


void PosDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()

	mComboAxis.AddString(_T("1"));
	mComboAxis.AddString(_T("2"));
	mComboAxis.AddString(_T("3"));
	mComboAxis.AddString(_T("4"));

	mComboAxis.SetCurSel(0);

	mEditAcc.SetWindowTextW(_T("0.000"));
	mEditDec.SetWindowTextW(_T("0.000"));
	mEditVel.SetWindowTextW(_T("0.000"));
	mEditPos.SetWindowTextW(_T("0.000"));

	mEditGetPrfVel.SetWindowTextW(_T("0.000"));
	mEditGetPrfPos.SetWindowTextW(_T("0.000"));
	mEditGetVel.SetWindowTextW(_T("0.000"));
	mEditGetPos.SetWindowTextW(_T("0.000"));

	SetTimer(0, 100, NULL);
}


void PosDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	switch (nIDEvent)
	{
	case 0:
	{
		if (mGoogol != nullptr)
		{
			double dPrfPos = 0.0;
			double dPrfVel = 0.0;
			double dPos = 0.0;
			double dVel = 0.0;
			mGoogol->GetState(m_nAxis, dPrfPos, dPrfVel, dPos, dVel);

			CString strTmp;
			strTmp.Format(_T("%.3f"), dPrfVel);
			mEditGetPrfVel.SetWindowTextW(strTmp);
			strTmp.Format(_T("%.3f"), dPrfPos);
			mEditGetPrfPos.SetWindowTextW(strTmp);
			strTmp.Format(_T("%.3f"), dVel);
			mEditGetVel.SetWindowTextW(strTmp);
			strTmp.Format(_T("%.3f"), dPrfPos);
			mEditGetPos.SetWindowTextW(strTmp);
		}
	}
	break;
	default:
		break;
	}


	CDialogEx::OnTimer(nIDEvent);
}
