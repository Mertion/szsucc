#pragma once

#ifndef _INTERFACE_H
#define _INTERFACE_H

typedef struct _StructDetectionParameters
{

}StructDetectionParameters;


//��ʼ�����DLL
void __stdcall InstanceDll();

//ж��DLL
void __stdcall DestroyDLL();

void __stdcall SetDetectionParameters(StructDetectionParameters &p_StructDetectionParameters);

//���
void __stdcall Detection(byte * p_pSrcData, int p_nWidth, int p_nHeigh);

//����
void __stdcall Test();

#endif