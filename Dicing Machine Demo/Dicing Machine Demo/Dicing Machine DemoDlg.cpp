
// Dicing Machine DemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Dicing Machine Demo.h"
#include "Dicing Machine DemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//������ת����16�����ַ���,�磺0x01 0x02 0x03 -> "010203"
int BinToHexStr(unsigned char* HexStr, unsigned char* Bin, int  BinLen)
{
#pragma warning(disable:4996)
	char Temp1[3];
	char* result;
	int ret;
	int lens;
	int i = 0;
	lens = BinLen;
	if (lens <= 0) return 0;
	result = (char*)malloc((lens * 2 + 2) * sizeof(char));
	if (!result) return 0;
	memset(result, 0, sizeof(result));
	for (i = 0; i < lens; i++)
	{
		memset(Temp1, 0, sizeof(Temp1));
		ret = sprintf(Temp1, "%X", Bin[i]);
		if (strlen(Temp1) == 1) {
			Temp1[1] = Temp1[0];
			Temp1[0] = '0';
		}
		strcat(result, Temp1);

	}
	strcpy((char*)HexStr, result);

	free(result);
	return 2 * i;
#pragma warning(default: 4996)
}


int HexStrToBin(unsigned char* bin, unsigned char* asc, int len)
{
	char ucChar;
	int nSize = 0;
	len = len / 2 + len % 2;
	//npDest=(char *)bin;
	while (len--) {
		ucChar = (*asc <= '9' && *asc >= '0') ? *asc - '0' : *asc - 'A' + 10;
		ucChar <<= 4;
		asc++;
		ucChar |= ((*asc <= '9' && *asc >= '0') ? *asc - '0' : *asc - 'A' + 10) & 0x0F;
		asc++;
		*bin++ = ucChar;
		nSize++;
	}
	return nSize;
}

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CDicingMachineDemoDlg �Ի���



CDicingMachineDemoDlg::CDicingMachineDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDicingMachineDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	memset(byteDNC, 0, 16);
}

CDicingMachineDemoDlg::~CDicingMachineDemoDlg()
{
	
}

void CDicingMachineDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_INIT, mButtonInit);
	DDX_Control(pDX, IDC_BUTTON_START, mButtonStart);
	DDX_Control(pDX, IDC_BUTTON_ENABLE, mButtonEnable);
	DDX_Control(pDX, IDC_EDIT_SPEED, mEditSpeed);
	DDX_Control(pDX, IDC_BUTTON_CHANGESPEED, mButtonChangeSpeed);
	DDX_Control(pDX, IDC_BUTTON_DISABLE, mButtonDisable);
	DDX_Control(pDX, IDC_BUTTON_STOP, mButtonStop);
	DDX_Control(pDX, IDC_BUTTON_CLEARLOG, mButtonClrLog);
	DDX_Control(pDX, IDC_LIST_LOG, mListLog);
	DDX_Control(pDX, IDC_COMBO_PORTNAME, mComboPortName);
	DDX_Control(pDX, IDC_COMBO_BAUDRATE, mComboBaudrate);
	DDX_Control(pDX, IDC_COMBO_DATABIT, mComboDataBit);
	DDX_Control(pDX, IDC_COMBO_STOPBIT, mComboStopBit);
	DDX_Control(pDX, IDC_COMBO_PARITY, mComboParity);
	DDX_Control(pDX, IDC_BUTTON_OPENSERIALPORT, mButtonOpenSerialPort);
	DDX_Control(pDX, IDC_EDIT_SEND, mEditSend);
	
}

BEGIN_MESSAGE_MAP(CDicingMachineDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CDicingMachineDemoDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_CLEARLOG, &CDicingMachineDemoDlg::OnBnClickedButtonClearlog)
	ON_BN_CLICKED(IDC_BUTTON_OPENSERIALPORT, &CDicingMachineDemoDlg::OnBnClickedButtonOpenSerialPort)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_SERIALPORTSEND, &CDicingMachineDemoDlg::OnBnClickedButtonSerialPortSend)
	ON_BN_CLICKED(IDC_BUTTON_ENABLE, &CDicingMachineDemoDlg::OnBnClickedButtonEnable)
	ON_BN_CLICKED(IDC_BUTTON_START, &CDicingMachineDemoDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CDicingMachineDemoDlg::OnBnClickedButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_CHANGESPEED, &CDicingMachineDemoDlg::OnBnClickedButtonChangespeed)
	ON_BN_CLICKED(IDC_BUTTON_DISABLE, &CDicingMachineDemoDlg::OnBnClickedButtonDisable)
	ON_BN_CLICKED(IDC_BUTTON_INIT, &CDicingMachineDemoDlg::OnBnClickedButtonInit)
END_MESSAGE_MAP()


// CDicingMachineDemoDlg ��Ϣ�������

BOOL CDicingMachineDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	mEditSpeed.SetWindowTextW(_T("0"));

	InitSerialConfig();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDicingMachineDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDicingMachineDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDicingMachineDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDicingMachineDemoDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CDicingMachineDemoDlg::OnBnClickedButtonClearlog()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	mListLog.ResetContent();
}

//��ʼ����������
void CDicingMachineDemoDlg::InitSerialConfig()
{
	GetSystemSerialComport();

	CString str;
	str = "115200";
	mComboBaudrate.AddString(_T("9600"));
	mComboBaudrate.AddString(_T("57600"));
	mComboBaudrate.AddString(_T("115200"));

	mComboBaudrate.SetCurSel(2);
	
	mComboDataBit.AddString(_T("5"));
	mComboDataBit.AddString(_T("6"));
	mComboDataBit.AddString(_T("7"));
	mComboDataBit.AddString(_T("8"));
	mComboDataBit.SetCurSel(3);

	mComboStopBit.AddString(_T("1"));
	mComboStopBit.AddString(_T("1.5"));
	mComboStopBit.AddString(_T("2"));
	mComboStopBit.SetCurSel(0);

	mComboParity.AddString(_T("None"));
	mComboParity.AddString(_T("Odd"));
	mComboParity.AddString(_T("Even"));
	mComboParity.AddString(_T("Mark"));
	mComboParity.AddString(_T("Space"));
	mComboParity.SetCurSel(0);

	((CButton*)GetDlgItem(IDC_CHECK_CHKHEX))->SetCheck(1);
	StartRecThread();
}

//��ȡ������е����д���
BOOL CDicingMachineDemoDlg::GetSystemSerialComport() 
{
	HKEY hKey = NULL;
	CArray<CString, CString> comarray;
	comarray.RemoveAll();
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("HARDWARE\\DEVICEMAP\\SERIALCOMM"), 0, KEY_READ, &hKey) != ERROR_SUCCESS)
	{
		return FALSE;
	}
	CString valuename = _T("");
	CString databuffer = _T("");
	DWORD valuenamebufferlength = 200;
	DWORD valuetype = 0;
	DWORD databuddersize = 200;
	int i = 0;
	while (RegEnumValue(hKey, i++, valuename.GetBuffer(200), &valuenamebufferlength, NULL, &valuetype, (BYTE*)databuffer.GetBuffer(200), &databuddersize) != ERROR_NO_MORE_ITEMS)
	{
		comarray.Add(CString(databuffer));
		databuddersize = 200;
		valuenamebufferlength = 200;
	}
	if (comarray.GetSize() == 0)
	{
		MessageBox(_T("���������û�п��õĴ���"), _T("��ʾ"));
		return FALSE;
	}
	for (int i = 0; i < comarray.GetSize(); i++)
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_PORTNAME))->InsertString(i, comarray[i]);
	}

	//Ĭ��ѡ���һ������
	((CComboBox*)GetDlgItem(IDC_COMBO_PORTNAME))->SetCurSel(0);
	RegCloseKey(hKey);
	return TRUE;
}

void CDicingMachineDemoDlg::OnBnClickedButtonOpenSerialPort()
{
	//��ǰ����������
	if (mSerialPort.GetConnectionStatus())
	{
		mSerialPort.close();
		mButtonOpenSerialPort.SetWindowTextW(_T("��"));
	}
	else
	{
		CString strTmp;
		CString strPortName;
		mComboPortName.GetWindowTextW(strPortName);

		char chrPortName[1024] = { 0 };
		memcpy(chrPortName, (CStringA)strPortName, ((CStringA)strPortName).GetLength());

		int nBaudrate = 0;
		mComboBaudrate.GetWindowTextW(strTmp);
		nBaudrate = atoi((CStringA)strTmp);

		char cParity = 0;
		mComboParity.GetWindowTextW(strTmp);
		cParity = (char)atoi((CStringA)strTmp);

		char cDataBit = 0;
		mComboDataBit.GetWindowTextW(strTmp);
		cDataBit = (char)atoi((CStringA)strTmp);

		char cStopBit = (char)mComboStopBit.GetCurSel();

		mSerialPort.open(chrPortName, nBaudrate, cParity, cDataBit, cStopBit, 1);

		mButtonOpenSerialPort.SetWindowTextW(_T("�ر�"));
	}
}

//�������ڽ����߳�
int CDicingMachineDemoDlg::StartRecThread()
{
	m_bExitThread = false;
	m_hThredHandle = (HANDLE)_beginthreadex(NULL,         // security
		0,            // stack size
		exRecThreadTaskSerialPort,
		this,           // arg list
		m_uiInitFlag,
		&m_uiThreadID);
	if (NULL == m_hThredHandle)
	{
		 AfxMessageBox(_T("���ڽ����̴߳���ʧ�ܣ�"));
		 return 1;
	}

	return 0;
}

//ֹͣ�����߳�
int CDicingMachineDemoDlg::StopRecThread()
{
	m_bExitThread = true;

	if (NULL != m_hThredHandle)
	{
		while (true)
		{
			GetExitCodeThread(m_hThredHandle, &dwExitCode);  // should be STILL_ACTIVE = 0x00000103 = 259
			if (STILL_ACTIVE != dwExitCode)
			{
				CloseHandle(m_hThredHandle);
				m_hThredHandle = NULL;
				break;
			}
			Sleep(10);
		}
	}

	if (mSerialPort.GetConnectionStatus())
	{
		mSerialPort.close();
	}
	return 0;
}

//���ڽ����̻߳ص�����
unsigned __stdcall CDicingMachineDemoDlg::exRecThreadTaskSerialPort(LPVOID lpParam)
{
	CDicingMachineDemoDlg* t_ClassThread = (CDicingMachineDemoDlg*)lpParam;
	return t_ClassThread->RecThreadTaskSerialPort();
}

unsigned CDicingMachineDemoDlg::RecThreadTaskSerialPort()
{
	unsigned t_uiRet = 0;

	while (!m_bExitThread)
	{
		//��ǰ����������
		if (mSerialPort.GetConnectionStatus())
		{
			string strRec = mSerialPort.receive();

			if (m_bExitThread)
			{
				break;
			}

			if (strRec.size()>0)
			{
				CString strLog;
				if (((CButton*)GetDlgItem(IDC_CHECK_CHKHEX))->GetCheck())
				{
					for (int i = 0; i < (int)strRec.size(); i++)
					{
						char tChar = strRec[i];
						strLog.AppendFormat(_T("%.2x "), tChar);
					}
				}
				else
				{
					strLog = CString(strRec.c_str());
				}

				mListLog.AddString(strLog);

				//int nLen = strLog.GetLength();
				//int nCols = nLen > mListLog.GetHorizontalExtent();
				//nLen = nLen>mListLog.GetHorizontalExtent() ? nLen : mListLog.GetHorizontalExtent();
				////mListLog.SetHorizontalExtent(nLen);
				////SendDlgItemMessage(IDC_LIST_LOG, LB_SETHORIZONTALEXTENT, nLen);
				//if (nLen>0)
				//{
				//	mListLog.SetColumnWidth(nLen);
				//}
				
			}
			
		}
		Sleep(10);
	}

	return t_uiRet;
}


int CDicingMachineDemoDlg::SendDNCCMD(byte* p_pbyteDate, int p_nLen)
{
	if (mSerialPort.GetConnectionStatus())
	{
		string strSend;
		byte byteSum = 0xff;
		int nLen1 = p_nLen - 1;

		for (int i = 0; i < nLen1; i++)
		{
			strSend += p_pbyteDate[i];
			byteSum -= p_pbyteDate[i];
		}

		strSend += byteSum;
		mSerialPort.send(strSend);
	}
	else
	{
		AfxMessageBox(_T("���ȴ򿪴��ڣ�"));
	}
	return 0;
}

void CDicingMachineDemoDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//mSerialPort.close();
	StopRecThread();
}


void CDicingMachineDemoDlg::OnBnClickedButtonSerialPortSend()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (mSerialPort.GetConnectionStatus())
	{
		string strSend;
		CString strText;
		mEditSend.GetWindowTextW(strText);

		if (((CButton*)GetDlgItem(IDC_CHECK_CHKHEX))->GetCheck())
		{
			byte* byteData = nullptr;
			int nLen = 0;

			//ȥ���ַ����еĿո�
			strText.Replace(' ',NULL);
			strText.MakeUpper();
			if (strText.GetLength()%2)
			{
				strText = _T("0") + strText;
			}

			strSend = (CStringA)strText.GetBuffer();
			nLen = (int)strSend.size();
			byteData = new byte[nLen];
			memset(byteData, 0, nLen);
			
			nLen = HexStrToBin(byteData, (UCHAR*)strSend.data(), nLen);
			strSend = "";
			for (int i = 0;i<nLen;i++)
			{
				strSend += byteData[i];
			}
			delete[] byteData;
		}
		else
		{
			strSend = (CStringA)(strText).GetBuffer();
		}
		mSerialPort.send(strSend);
		
	}
	else
	{
		AfxMessageBox(_T("���ȴ򿪴��ڣ�"));
	}
}


void CDicingMachineDemoDlg::OnBnClickedButtonEnable()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//s:00 0d 02 01 10 01 00 0f 00 ff 1f 00 00 00 00 b1
	//r:00 0D 01 02 90 01 00 37 72 ff 1f 00 00 21 43 ??

	byteDNC[0] = 0x00;
	byteDNC[1] = 0x0d;
	byteDNC[2] = 0x02;
	byteDNC[3] = 0x01;
	byteDNC[4] = 0x10;
	byteDNC[5] = 0x01;
	byteDNC[6] = 0x00;
	byteDNC[7] = 0x0f;
	byteDNC[8] = 0x00;
	byteDNC[9] = 0xff;
	byteDNC[10] = 0x1f;
	byteDNC[11] = 0x00;
	byteDNC[12] = 0x00;
	byteDNC[13] = 0x00;
	byteDNC[14] = 0x00;

	SendDNCCMD(byteDNC, 16);
}

//����
void CDicingMachineDemoDlg::OnBnClickedButtonStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//s:00 0d 02 01 10 05 00 07 00 ff 1f 00 00 00 00 b5
	//r:00 0D 01 02 90 05 00 33 72 00 00 00 00 21 43 ??
	byteDNC[0] = 0x00;
	byteDNC[1] = 0x0d;
	byteDNC[2] = 0x02;
	byteDNC[3] = 0x01;
	byteDNC[4] = 0x10;
	byteDNC[5] = 0x05;
	byteDNC[6] = 0x00;
	byteDNC[7] = 0x07;
	byteDNC[8] = 0x00;
	byteDNC[9] = 0xff;
	byteDNC[10] = 0x1f;
	byteDNC[11] = 0x00;
	byteDNC[12] = 0x00;
	byteDNC[13] = 0x00;
	byteDNC[14] = 0x00;

	SendDNCCMD(byteDNC, 16);
}


void CDicingMachineDemoDlg::OnBnClickedButtonStop()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//s:00 0d 02 01 10 05 00 06 00 ff 0f 00 00 00 00 c6
	//r:00 0D 01 02 90 05 00 31 72 00 00 00 00 21 43 ??

	byteDNC[0] = 0x00;
	byteDNC[1] = 0x0d;
	byteDNC[2] = 0x02;
	byteDNC[3] = 0x01;
	byteDNC[4] = 0x10;
	byteDNC[5] = 0x05;
	byteDNC[6] = 0x00;
	byteDNC[7] = 0x06;
	byteDNC[8] = 0x00;
	byteDNC[9] = 0xff;
	byteDNC[10] = 0x0f;
	byteDNC[11] = 0x00;
	byteDNC[12] = 0x00;
	byteDNC[13] = 0x00;
	byteDNC[14] = 0x00;

	SendDNCCMD(byteDNC, 16);
}


void CDicingMachineDemoDlg::OnBnClickedButtonChangespeed()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//s:00 0d 02 01 10 05 00 0f 00 ff 0f 00 00 00 00 bd
	//r:00 0D 01 02 90 05 00 37 72 ff 0f 00 00 21 43 ??

	byteDNC[0] = 0x00;
	byteDNC[1] = 0x0d;
	byteDNC[2] = 0x02;
	byteDNC[3] = 0x01;
	byteDNC[4] = 0x10;
	byteDNC[5] = 0x05;
	byteDNC[6] = 0x00;
	byteDNC[7] = 0x0f;
	byteDNC[8] = 0x00;
	byteDNC[9] = 0xff;
	byteDNC[10] = 0x0f;
	byteDNC[11] = 0x00;
	byteDNC[12] = 0x00;
	byteDNC[13] = 0x00;
	byteDNC[14] = 0x00;

	SendDNCCMD(byteDNC, 16);
}


void CDicingMachineDemoDlg::OnBnClickedButtonDisable()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//s:00 0d 02 01 10 01 00 07 00 ff 0f 00 00 00 00 c9
	//r:00 0D 01 02 90 05 00 33 72 00 00 00 00 21 43 ??

	byteDNC[0] = 0x00;
	byteDNC[1] = 0x0d;
	byteDNC[2] = 0x02;
	byteDNC[3] = 0x01;
	byteDNC[4] = 0x10;
	byteDNC[5] = 0x01;
	byteDNC[6] = 0x00;
	byteDNC[7] = 0x06;
	byteDNC[8] = 0x00;
	byteDNC[9] = 0xff;
	byteDNC[10] = 0x1f;
	byteDNC[11] = 0x00;
	byteDNC[12] = 0x00;
	byteDNC[13] = 0x00;
	byteDNC[14] = 0x00;

	SendDNCCMD(byteDNC, 16);
}


void CDicingMachineDemoDlg::OnBnClickedButtonInit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//s:00 0d 02 01 10 01 00 06 00 ff 1f 00 00 00 00 ba
	//r:00 0D 01 02 90 01 00 31 72 00 00 00 00 00 00 ??
	byteDNC[0] = 0x00;
	byteDNC[1] = 0x0d;
	byteDNC[2] = 0x02;
	byteDNC[3] = 0x01;
	byteDNC[4] = 0x10;
	byteDNC[5] = 0x01;
	byteDNC[6] = 0x00;
	byteDNC[7] = 0x06;
	byteDNC[8] = 0x00;
	byteDNC[9] = 0xff;
	byteDNC[10] = 0x1f;
	byteDNC[11] = 0x00;
	byteDNC[12] = 0x00;
	byteDNC[13] = 0x00;
	byteDNC[14] = 0x00;

	SendDNCCMD(byteDNC, 16);
}

