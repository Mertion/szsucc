#pragma once

#include "stdafx.h"
#include <Mmsystem.h>

//������ý�嶨ʱ��
 void SYS_BeginTimeEvent(_In_ LPTIMECALLBACK fptc
	, _Out_ UINT& p_pTimeEventID
	, _In_ LPTHREAD_START_ROUTINE lpStartAddress
	, _Out_ HANDLE& m_MainThread
	, _In_ int p_pMilliSecond);

//������ý�嶨ʱ��
void SYS_EndTimeEvent(_In_ UINT p_pTimeEventID);