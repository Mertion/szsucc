
#pragma once
#include "IFProtocolAnalysis.h"
#include "FileOperation/LoadDLLFunction.h"
#include "FileOperation/CFileOpertion.h"

//Э�������
//���Э�����DLL���ؼ���غ������� 
class ProtocolAnalysis
{
public:
	ProtocolAnalysis();
	~ProtocolAnalysis();

	int exProtocolPackage(IN const byte* p_byteSourceData, IN int p_nSourceDataLen, OUT byte* p_bytearrCMD, OUT int* p_pCMDLen);
	int exProtocolUnpacking(IN OUT byte* p_pbyteSourceData, IN OUT int* p_pnSourceDataLen, OUT byte* p_bytearrCMD, OUT int* p_pCMDLen);
private:
	HINSTANCE m_pHINSTANCE;
	CString m_strDllDir;
	CString m_strDllName;

	funProtocolPackage m_pfunProtocolPackage;
	funProtocolUnpacking m_pfunProtocolUnpacking;

	//const static CString m_strProtocolPackage(_T("ProtocolPackage"));
	//const static CString m_strProtocolUnpacking(_T("ProtocolUnpacking"));

	CString m_strProtocolPackage;
	CString m_strProtocolUnpacking;
};