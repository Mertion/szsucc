
// Dicing Machine DemoDlg.h : ͷ�ļ�
//

#pragma once
#include ".\Fundation\SerialPort.h"

// CDicingMachineDemoDlg �Ի���
class CDicingMachineDemoDlg : public CDialogEx
{
// ����
public:
	CDicingMachineDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CDicingMachineDemoDlg();
// �Ի�������
	enum { IDD = IDD_DICINGMACHINEDEMO_DIALOG };

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
	afx_msg void OnBnClickedOk();
	
	afx_msg void OnBnClickedButtonClearlog();
	void InitSerialConfig();
	//��ȡ������е����д���
	BOOL GetSystemSerialComport(); 
	

	afx_msg void OnBnClickedButtonOpenSerialPort();

	//�������ڽ����߳�
	int StartRecThread();
	//ֹͣ�����߳�
	int StopRecThread();
	//���ڽ����̻߳ص�����
	unsigned  static __stdcall exRecThreadTaskSerialPort(LPVOID lpParam);
	//���ڽ����߳�
	unsigned RecThreadTaskSerialPort();

	int SendDNCCMD(byte *p_pbyteDate,int p_nLen);

	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButtonSerialPortSend();
private:

	//���ڶ���
	CSerialPort mSerialPort;
	//�˳��̱߳�־
	bool m_bExitThread = false;
	//�߳̾��
	HANDLE m_hThredHandle = NULL;
	//�̳߳�ʼ״̬: 0-��������,CREATE_SUSPEND-���������
	unsigned m_uiInitFlag = 0;
	//�߳�ID
	unsigned  m_uiThreadID = 0;
	//�߳�״̬��
	DWORD   dwExitCode = 0;
	//DNCָ��
	byte byteDNC[16];
	CEdit mEditSpeed;
	CButton mButtonEnable;
	CButton mButtonStart;
	CButton mButtonStop;
	CButton mButtonInit;
	CButton mButtonChangeSpeed;
	CButton mButtonClrLog;
	CListBox mListLog;
	CComboBox mComboPortName;
	CComboBox mComboBaudrate;
	CComboBox mComboDataBit;
	CComboBox mComboStopBit;
	CComboBox mComboParity;
	CButton mButtonOpenSerialPort;

	CEdit mEditSend;


public:
	
	
	afx_msg void OnBnClickedButtonEnable();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonStop();
	CButton mButtonDisable;
	afx_msg void OnBnClickedButtonChangespeed();
	afx_msg void OnBnClickedButtonDisable();
	afx_msg void OnBnClickedButtonInit();
};
