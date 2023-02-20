
// Dicing Machine DemoDlg.h : ͷ�ļ�
//

#pragma once
#include ".\Fundation\SerialPort.h"
#include "bdaqctrl.h"
#include "Googol.h"
#include "ListCtrlEx.h"

using namespace Automation::BDaq;

// CConfigDlg 
typedef struct tagConfigParam {
	int			deviceNumber;
	int			channelCount;
	int			channelStart;
	int			vrgType;
	WCHAR 		profilePath[256];
}DevConfParam;

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

	CButton mButtonInit;
	CButton mButtonEnable;
	CButton mButtonStart;
	CButton mButtonStop;
	CButton mButtonDisable;
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

	CComboBox m_comboBox_Device;
	CComboBox m_comboBox_ChannelStart;
	CComboBox m_comboBox_ChannelCount;
	CComboBox m_comboBox_ValueRange;
	InstantAiCtrl* m_instantAiCtrl;
	DevConfParam        m_confParam;
	CEdit mEditChannel1;
	CEdit mEditChannel2;

	Googol mGoogol;
	
	const static int m_const_nIOCount = 16;
	CListCtrlEx mListGTSDI;
	CListCtrlEx mListGTSDO;
	int m_ListIODataDI[m_const_nIOCount] = { 0 };
	int m_ListIODataDO[m_const_nIOCount] = { 0 };

	int m_nTestCounter = 0;
public:
	
	
	afx_msg void OnBnClickedButtonEnable();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonStop();
	afx_msg void OnBnClickedButtonChangespeed();
	afx_msg void OnBnClickedButtonDisable();
	afx_msg void OnBnClickedButtonInit();

	//��ȡ1816������
	int GetCardInfo1816();
	afx_msg void OnCbnSelchangeComboDevice();
	void ConfigurateDevice();
	void CheckError(ErrorCode error);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButtonRun();
	afx_msg void OnClose();
	afx_msg void OnBnClickedButtonOpenGTS();
	afx_msg void OnBnClickedButtonOpen1816();

	//��ʼ��GTS I/O �б�ؼ�
	int InitGTSIOList();
	afx_msg LRESULT onBnCLick(WPARAM wParam, LPARAM lParam);


	int RefreshIO();
	afx_msg void OnBnClickedButtonJog();
	afx_msg void OnBnClickedButtonPos();
	afx_msg void OnBnClickedButtonClicktest();
	CEdit mEDIT2;
};
