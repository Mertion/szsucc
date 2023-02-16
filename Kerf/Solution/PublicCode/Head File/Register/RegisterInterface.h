#pragma  once
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MATUREAPPROACH_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MATUREAPPROACH_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.



#include "./PUB/DataEncryption/CSecurityVerification.h"
#include "stdafx.h"

//#define PTREGISTER_EXPORTS
#ifdef PTREGISTER_EXPORTS
#define PTREGISTER_API __declspec(dllexport)
#else
#define PTREGISTER_API __declspec(dllimport)
#endif

enum EnumRegisterMessage	//��Ϣö��
{
	EnumRegisterMessage_OK = 0x00,			//�ɹ�
	EnumRegisterMessage_Failed, 			//ʧ��
	EnumRegisterMessage_NoVerifi,			//δ���÷�α�ӿ�
	EnumRegisterMessage_ProcessError,		//���̴��󣬸ô��󲻸�����ȷ��ʾ��Ϣ����ֹ�����ƽ�
};

enum EnumStage		//��¼��������ʱ��ò�������
{
	ST_PROD = 0x00,	//������
	ST_END = 0x01,	//��������
};

typedef int (_stdcall* pSysRegister)(unsigned long& lChipsCount,unsigned char* ucChipsCount);
typedef int (_stdcall* pInitDongle)(int p_cSoftwareVer);
typedef int (_stdcall* pShowDongleDlg)(void);
typedef int (_stdcall* pUnInitDongle)(void);
typedef int (_stdcall* pSetChipsCount)(unsigned char* ucChipsCount,int ilen,unsigned long lChipsCount,EnumStage nSTAGE);
typedef int (_stdcall* pCreatResetCountSN)(unsigned char* HardwareID,unsigned char* CountSN,int& ilen,unsigned long lCount);
typedef int (_stdcall* pCheckChipsCount)(unsigned long lChipsCount,unsigned char* HardwareID,unsigned char* ChipsCountSN,int ilen);
typedef int (_stdcall* pExecuteDongleApp)(char* p_strAppName,
										  BYTE *p_cInBuf,DWORD p_lInBufLen,
										  BYTE *p_cOutBuf,DWORD p_lOutBufLen);
typedef int(_stdcall* pExgetVerifi)(struVerifiParameter &p_VerifiParameter);
typedef int(_stdcall* pExgetFunctionInfo)(IN int p_nFunctionID, OUT int p_nFunctionState, OUT BYTE *p_pFunctionInfo);

extern "C" PTREGISTER_API int  __stdcall  exSysRegister(unsigned long& lChipsCount,unsigned char* ucChipsCount);	//ע����������
extern "C" PTREGISTER_API int  __stdcall  exInitDongle(int p_cSoftwareVer);	//��ʼ�������ӣ�����������ͺ�
extern "C" PTREGISTER_API int  __stdcall  exUnInitDongle();					//ж�ؼ��ܹ�
extern "C" PTREGISTER_API int  __stdcall  exShowDongleDlg();				//������Ȩ��Ϣ����
extern "C" PTREGISTER_API int  __stdcall  exSetChipsCount(unsigned char* ucChipsCount,int ilen,unsigned long lChipsCount,EnumStage nSTAGE);//������������
extern "C" PTREGISTER_API int  __stdcall  exCreatResetCountSN(unsigned char* HardwareID,unsigned char* CountSN,int& ilen,unsigned long lCount);//�����������������
extern "C" PTREGISTER_API int  __stdcall  exCheckChipsCount(unsigned long lChipsCount,unsigned char* HardwareID,unsigned char* ChipsCountSN,int ilen);//���оƬ����
extern "C" PTREGISTER_API int  __stdcall  exExecuteDongleApp(char* p_strAppName,
															 BYTE *p_cInBuf,DWORD p_lInBufLen,
															 BYTE *p_cOutBuf,DWORD p_lOutBufLen);		//ִ�й��ڳ���

extern "C" PTREGISTER_API int  __stdcall  exgetVerifi(struVerifiParameter &p_VerifiParameter);			//��ȡ�������֤��
extern "C" PTREGISTER_API int  __stdcall  exgetFunctionInfo(IN int p_nFunctionID,OUT int &p_nFunctionState,OUT BYTE *p_pFunctionInfo);	//��ȡ������Ȩ������Ϣ

