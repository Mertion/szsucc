
// KerfTestDlgDlg.h : ͷ�ļ�
//

#pragma once


// CKerfTestDlgDlg �Ի���
class CKerfTestDlgDlg : public CDialogEx
{
// ����
public:
	CKerfTestDlgDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_KERFTESTDLG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSetpara();
	afx_msg void OnBnClickedButtonInstance();
	afx_msg void OnBnClickedButtonTest();
	afx_msg void OnBnClickedButtonDestroy();
};
