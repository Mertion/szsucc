// Kerf.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "afxmt.h"
#include "Kerf.h"
#include "InterFace.h"
#include "Detection/Detection.h"
#include "GeneralSolution.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static CDetection* g_Detection = nullptr;
static bool g_bIsinit = false;
CCriticalSection g_critical_section;
byte* g_TestImageSrc = nullptr;

//
//TODO:  ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ��  ����ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CKerfApp

BEGIN_MESSAGE_MAP(CKerfApp, CWinApp)
END_MESSAGE_MAP()


// CKerfApp ����

CKerfApp::CKerfApp()
{
	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CKerfApp ����

CKerfApp theApp;


// CKerfApp ��ʼ��

BOOL CKerfApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

//�ͷŲ��Խӿ�ͼ��ռ�
void ReleaseTestSrc()
{
	if (nullptr != g_TestImageSrc)
	{
		delete[] g_TestImageSrc;
		g_TestImageSrc = nullptr;
	}
}

//��ʼ�����DLL
void __stdcall InstanceDll()
{
	g_critical_section.Lock();
	if ((nullptr == g_Detection) && !g_bIsinit)
	{
		g_bIsinit = true;
		g_Detection = new CDetection();
	}
	g_critical_section.Unlock();

	ReleaseTestSrc();
}

//ж��DLL
void __stdcall DestroyDLL()
{
	if (nullptr != g_Detection)
	{
		delete g_Detection;

		g_Detection = nullptr;
	}

	ReleaseTestSrc();
}

void __stdcall SetDetectionParameters(StructDetectionParameters& p_StructDetectionParameters)
{

}

//���
int __stdcall Detection(byte * p_pSrcData, int p_nWidth, int p_nHeigh)
{
	int nRet = (int)enumDetectionResult::DLLNotInitialized;
	if (nullptr != g_Detection)
	{
		g_Detection->KerfDetection(p_pSrcData, p_nWidth, p_nHeigh);
	}

	return nRet;
}

//����
void __stdcall Test()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strFilter("�����ļ�(*.dat; *.bmp)|*.dat;*.bmp|�����ļ�(*.*)|*.*||");
	CFileDialog fd(TRUE, NULL, NULL, 0, strFilter);
	/*CFileDialog dlg(TRUE, _T("DLL"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		dwFilter);*/

	if (IDOK == fd.DoModal())
	{
		CString strPathDst = fd.GetPathName();
		//���ļ�
		Mat tmatSrcRead = imread(string((CStringA)strPathDst), CV_LOAD_IMAGE_UNCHANGED);
		
		if ((tmatSrcRead.cols>0)&&(tmatSrcRead.rows>0))
		{
			int nSize = tmatSrcRead.rows * (int)tmatSrcRead.step;
			g_TestImageSrc = new byte[nSize];

			memcpy(g_TestImageSrc, tmatSrcRead.data, nSize);
			Detection(g_TestImageSrc, tmatSrcRead.cols, tmatSrcRead.rows);
		}
		
	}
	else
	{
		
		return;
	}
}