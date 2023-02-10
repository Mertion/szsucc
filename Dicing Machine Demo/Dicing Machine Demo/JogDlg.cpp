// JogDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Dicing Machine Demo.h"
#include "afxdialogex.h"
#include "JogDlg.h"


// JogDlg 对话框

IMPLEMENT_DYNAMIC(JogDlg, CDialogEx)

JogDlg::JogDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_JOG, pParent)
{
	
}

JogDlg::~JogDlg()
{

}

void JogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_AXIS, mComboAxis);
	DDX_Control(pDX, IDC_EDIT_ACC, mEditAcc);
	DDX_Control(pDX, IDC_EDIT_DEC, mEditDec);
	DDX_Control(pDX, IDC_EDIT_VEL, mEditVel);
	DDX_Control(pDX, IDC_EDIT_GETPRFVEL, mEditGetPrfVel);
	DDX_Control(pDX, IDC_EDIT_GETPRFPOS, mEditGetPrfPos);
	DDX_Control(pDX, IDC_EDIT_GETVEL, mEditGetVel);
	DDX_Control(pDX, IDC_EDIT_GETPOS, mEditGetPos);
}


BEGIN_MESSAGE_MAP(JogDlg, CDialogEx)
	
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_START, &JogDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &JogDlg::OnBnClickedButtonStop)
	ON_WM_DESTROY()
	ON_WM_CREATE()
END_MESSAGE_MAP()


void JogDlg::OnTimer(UINT_PTR nIDEvent)
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


void JogDlg::OnPaint()
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

	mEditGetPrfVel.SetWindowTextW(_T("0.000"));
	mEditGetPrfPos.SetWindowTextW(_T("0.000"));
	mEditGetVel.SetWindowTextW(_T("0.000"));
	mEditGetPos.SetWindowTextW(_T("0.000"));

	SetTimer(0, 100, NULL);
}


void JogDlg::OnBnClickedButtonStart()
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

	if (mGoogol!=nullptr)
	{
		mGoogol->JogMove(m_nAxis, nAcc, nDec, nVel);
	}
	else
	{
		AfxMessageBox(_T("板上对象绑定错误！"));
	}
}


void JogDlg::OnBnClickedButtonStop()
{
	// TODO: 在此添加控件通知处理程序代码

	if (mGoogol != nullptr)
	{
		mGoogol->StopAxis(m_nAxis);
	}
}


void JogDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	if (mGoogol != nullptr)
	{
		mGoogol->StopAll();
	}
	KillTimer(0);
}


int JogDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	
	return 0;
}
