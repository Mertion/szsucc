#pragma once

#ifndef _INTERFACE_H
#define _INTERFACE_H

typedef struct _StructDetectionParameters
{

}StructDetectionParameters;


//≥ı ºªØºÏ≤‚DLL
void __stdcall InstanceDll();

//–∂‘ÿDLL
void __stdcall DestroyDLL();

void __stdcall SetDetectionParameters(StructDetectionParameters &p_StructDetectionParameters);

//ºÏ≤‚
void __stdcall Detection(byte * p_pSrcData, int p_nWidth, int p_nHeigh);

//≤‚ ‘
void __stdcall Test();

#endif