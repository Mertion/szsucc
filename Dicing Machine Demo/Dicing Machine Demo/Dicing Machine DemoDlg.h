
// Dicing Machine DemoDlg.h : 头文件
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

// CDicingMachineDemoDlg 对话框
class CDicingMachineDemoDlg : public CDialogEx
{
// 构造
public:
	CDicingMachineDemoDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CDicingMachineDemoDlg();
// 对话框数据
	enum { IDD = IDD_DICINGMACHINEDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()




public:
	afx_msg void OnBnClickedOk();
	
	afx_msg void OnBnClickedButtonClearlog();
	void InitSerialConfig();
	//获取计算机中的所有串口
	BOOL GetSystemSerialComport(); 
	

	afx_msg void OnBnClickedButtonOpenSerialPort();

	//启动串口接收线程
	int StartRecThread();
	//停止接收线程
	int StopRecThread();
	//串口接收线程回调函数
	unsigned  static __stdcall exRecThreadTaskSerialPort(LPVOID lpParam);
	//串口接收线程
	unsigned RecThreadTaskSerialPort();

	int SendDNCCMD(byte *p_pbyteDate,int p_nLen);

	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButtonSerialPortSend();
private:

	//串口对象
	CSerialPort mSerialPort;
	//退出线程标志
	bool m_bExitThread = false;
	//线程句柄
	HANDLE m_hThredHandle = NULL;
	//线程初始状态: 0-立即运行,CREATE_SUSPEND-创建后挂起
	unsigned m_uiInitFlag = 0;
	//线程ID
	unsigned  m_uiThreadID = 0;
	//线程状态码
	DWORD   dwExitCode = 0;
	//DNC指令
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

	//获取1816卡参数
	int GetCardInfo1816();
	afx_msg void OnCbnSelchangeComboDevice();
	void ConfigurateDevice();
	void CheckError(ErrorCode error);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButtonRun();
	afx_msg void OnClose();
	afx_msg void OnBnClickedButtonOpenGTS();
	afx_msg void OnBnClickedButtonOpen1816();

	//初始化GTS I/O 列表控件
	int InitGTSIOList();
	afx_msg LRESULT onBnCLick(WPARAM wParam, LPARAM lParam);


	int RefreshIO();
	afx_msg void OnBnClickedButtonJog();
	afx_msg void OnBnClickedButtonPos();
	afx_msg void OnBnClickedButtonClicktest();
	CEdit mEDIT2;
};
