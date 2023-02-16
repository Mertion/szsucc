#pragma once

#include "stdafx.h"

//���ݻ����С
#define MAX_DATABUFFERSIZE 8192

enum ENUM_PROTOCOLPACkAGE
{
	ENUM_PROTOCOLPACkAGE_SUCCESS = 0,		//�ɹ�������ݰ�
	ENUM_PROTOCOLPACkAGE_FAILED,			//����ʧ��
	ENUM_PROTOCOLPACkAGE_NONE,				//û������ݰ�
	ENUM_PROTOCOLPACkAGE_ERROR_HEAD,		//���ݰ�ͷ��ʽ����
	ENUM_PROTOCOLPACkAGE_ERROR_END,			//���ݰ�β��ʽ����
	ENUM_PROTOCOLPACkAGE_ERROR_DATALEN,		//���ݰ�β��ʽ����
	ENUM_PROTOCOLPACkAGE_ERROR_CRC,			//CRCУ�����
};

//************************************
// Method:    ProtocolPackage
// FullName:  ProtocolPackage
// Access:    public 
// Returns:   int
// Qualifier: Э����
// Parameter: IN const byte p_byteSourceData[] ��������
// Parameter: IN int p_nSourceDataLen �������ݳ���
// Parameter: OUT byte * p_bytearrCMD ����ָ��
// Parameter: OUT int * p_pCMDLen ����ָ���
//************************************
int __stdcall ProtocolPackage(IN const byte* p_byteSourceData, IN int p_nSourceDataLen, OUT byte* p_bytearrCMD, OUT int* p_pCMDLen);
typedef int (*funProtocolPackage)(IN const byte* p_byteSourceData, IN int p_nSourceDataLen, OUT byte* p_bytearrCMD, OUT int* p_pCMDLen);

//************************************
// Method:    ProtocolUnpacking
// FullName:  ProtocolUnpacking
// Access:    public 
// Returns:   int
// Qualifier: Э����
// Parameter: IN const byte p_byteSourceData[]
// Parameter: IN int p_nSourceDataLen
// Parameter: OUT byte * p_bytearrCMD
// Parameter: OUT int * p_pCMDLen
//************************************
int __stdcall ProtocolUnpacking(IN OUT byte* p_pbyteSourceData, IN OUT int* p_pnSourceDataLen, OUT byte* p_bytearrCMD, OUT int* p_pCMDLen);
typedef int(*funProtocolUnpacking)(IN OUT byte* p_pbyteSourceData, IN OUT int* p_pnSourceDataLen, OUT byte* p_bytearrCMD, OUT int* p_pCMDLen);


