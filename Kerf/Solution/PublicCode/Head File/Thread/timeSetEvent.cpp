///////////////////////////////////////////////////////////
//  timeSetEvent.cpp
//  
//  Created on:      01-11��-2017 18:19:00
//  Original author: Lzg
///////////////////////////////////////////////////////////
#include "stdafx.h"
#include "timeSetEvent.h"
//#include <minwindef.h>

#pragma comment(lib,"comctl32.lib") 
#pragma comment(lib,"winmm.lib")
#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif
//***************************************************************************************
//                             ****��ý�嶨ʱ����������****                            **
//***************************************************************************************
//����1msʱ�Ӽ������msΪ��λ 
//# define ONE_MILLI_SECOND 1  
//����ʱ�ӷֱ��ʣ���msΪ��λ 
# define TIMER_ACCURACY 1  
UINT wTimerRes_1ms;//����ʱ����
UINT wAccuracy;//����ֱ��� 
//20120822
UINT TimerID_DepressCard_Up, TimerID_DepressCard_Down;
const int SOFTWARETYPE = 1;    //1:ԭ�ܹ�����汾��0���¼ܹ�����汾
//ʹ���߳�ģʽ����
#define  MC_MY_DEBUG  1
//****************************************************************************************


//*********************************************************************************
//*                                                                              **
//*                         �������̲߳�����ϵͳ������                           **
//*                                                                              **
//*********************************************************************************
 void SYS_BeginTimeEvent(_In_ LPTIMECALLBACK fptc, _Out_ UINT& p_pTimeEventID
	, _In_ LPTHREAD_START_ROUTINE lpStartAddress, _Out_ HANDLE& m_MainThread
	, _In_ int p_pMilliSecond = 1)
{
	//ģ�����ʱʹ���߳�ģʽ
	if (MC_MY_DEBUG == 1)
	{
		//�������߳� ��ʹ�ö�ý�嶨ʱ��
		m_MainThread = CreateThread(NULL, 0, lpStartAddress, NULL, 0, NULL);
	}
	else
	{
		wTimerRes_1ms = p_pMilliSecond;// ��ʱ����������ֵ 
		TIMECAPS tc;
		//���ú���timeGetDevCapsȡ��ϵͳ�ֱ��ʵ�ȡֵ��Χ������޴������ 
		if (timeGetDevCaps(&tc, sizeof(TIMECAPS)) == TIMERR_NOERROR)
		{
			// �ֱ��ʵ�ֵ���ܳ���ϵͳ��ȡֵ��Χ 
			wAccuracy = min(max(tc.wPeriodMin, TIMER_ACCURACY), tc.wPeriodMax);
			//����timeBeginPeriod�������ö�ʱ���ķֱ��� 
			timeBeginPeriod(wAccuracy);
		}

		if (1 == SOFTWARETYPE)
		{
			//������ý�嶨ʱ��
			/*p_pTimeEventID = timeSetEvent(wTimerRes_1ms, wAccuracy,
				fptc,
				(DWORD)SYS_BeginTimeEvent, TIME_PERIODIC);*/
			p_pTimeEventID = timeSetEvent(wTimerRes_1ms, wAccuracy,
				fptc,
				(DWORD_PTR)SYS_BeginTimeEvent, TIME_PERIODIC);
		}

	}

}


//�������߳�
void SYS_EndTimeEvent(_In_ UINT p_pTimeEventID)
{
	//ģ�����ʱʹ���߳�ģʽ
	if (MC_MY_DEBUG == 1)
	{
		//m_bTreadCtl = true;
	}
	else
	{
		timeKillEvent(p_pTimeEventID);
	}
}
