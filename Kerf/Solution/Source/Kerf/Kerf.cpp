// Kerf.cpp : 定义 DLL 的初始化例程。
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
//TODO:  如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。  这意味着
//		它必须作为函数中的第一个语句
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//

// CKerfApp

BEGIN_MESSAGE_MAP(CKerfApp, CWinApp)
END_MESSAGE_MAP()


// CKerfApp 构造

CKerfApp::CKerfApp()
{
	// TODO:  在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CKerfApp 对象

CKerfApp theApp;


// CKerfApp 初始化

BOOL CKerfApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

//释放测试接口图像空间
void ReleaseTestSrc()
{
	if (nullptr != g_TestImageSrc)
	{
		delete[] g_TestImageSrc;
		g_TestImageSrc = nullptr;
	}
}

//初始化检测DLL
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

//卸载DLL
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

//检测
int __stdcall Detection(byte * p_pSrcData, int p_nWidth, int p_nHeigh)
{
	int nRet = (int)enumDetectionResult::DLLNotInitialized;
	if (nullptr != g_Detection)
	{
		g_Detection->KerfDetection(p_pSrcData, p_nWidth, p_nHeigh);
	}

	return nRet;
}

//测试
void __stdcall Test()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strFilter("数据文件(*.dat; *.bmp)|*.dat;*.bmp|任意文件(*.*)|*.*||");
	CFileDialog fd(TRUE, NULL, NULL, 0, strFilter);
	/*CFileDialog dlg(TRUE, _T("DLL"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		dwFilter);*/

	if (IDOK == fd.DoModal())
	{
		CString strPathDst = fd.GetPathName();
		//打开文件
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