#include "stdafx.h"
#include "ClassSemaphoreThread.h"
/*
������	lInitialCount �źŵĳ�ʼʹ�ü����������Ǵ��ڻ����0������С�ڻ����lMaxCount��
		lMaxCount �źŵ�ʹ�ü��������ֵ���������0��
		pstrName �źŵ����֡�
		lpsaAttributes ���źŶ���İ�ȫ��־���й�����ṹ����ϸ�������μ���Win32 SDK����Ա�ο����е�SECURITY_ATTRIBUTES��
˵���� �˳�Ա������������һ�������ֻ�û�����ֵ�CSemaphore����Ҫ���ʻ��ͷ�һ��CSemaphore���󣬿��Դ���һ��CMultiLock��CSingleLock���󣬲��������ǵ�Lock��Unlock������
*/
ClassSemaphoreThread::ClassSemaphoreThread(LONG lInitialCount, LONG lMaxCount,
	LPCTSTR pstrName, LPSECURITY_ATTRIBUTES lpsaAttributes)
{
	m_CSemaphore = new CSemaphore(lInitialCount, lMaxCount, pstrName, lpsaAttributes);
}


ClassSemaphoreThread::~ClassSemaphoreThread()
{
	Stop();

	if (NULL != m_CSemaphore)
	{
		delete m_CSemaphore;
		m_CSemaphore = NULL;
	}
	

}

unsigned ClassSemaphoreThread::exThreadTask(LPVOID lpParam)
{
	ClassSemaphoreThread* t_ClassThread = (ClassSemaphoreThread*)lpParam;
	return t_ClassThread->ThreadTask();
}
unsigned ClassSemaphoreThread::ThreadTask()
{
	unsigned t_uiRet = 0;

	do
	{
		m_CSemaphore->Lock();
		if (m_bExit)
		{
			return 0;
		}
		else
		{
			t_uiRet = (m_pFunc)(m_pArg);
		}

		Sleep(GetInterval());
	} while (true);

	return t_uiRet;
}

int ClassSemaphoreThread::Start()
{
	//�ж��Ƿ��лص�����
	if (m_pFunc)
	{
		//�ж��Ƿ��и���TASK������
		if (m_hThredHandle)
		{
			return ENUM_THREADINFO_THREADISRUN;
		}
		else
		{
			m_hThredHandle = (HANDLE)_beginthreadex(NULL,         // security ��ȫ�� NULL ��ʾĬ�ϰ�ȫ��
				m_nMemorySize,	// stack size �̵߳Ķ�ջ��С��Ĭ��Ϊ0
				exThreadTask,	//�̻߳ص�����
				this,           // arg list	�̲߳���
				m_uiInitFlag,	//��ʼ״̬��0��ʾ����ִ��
				&m_uiThreadID);	//�߳̾��
			if (NULL == m_hThredHandle)
			{
				return ENUM_THREADINFO_CREATTHREADFAILD;
			}
			else
			{

			}
		}
	}
	else
	{
		return ENUM_THREADINFO_FUNCISEMPYT;
	}

	return ENUM_THREADINFO_SUCCESS;
}

void ClassSemaphoreThread::Stop()
{
	m_bExit = true;
	if (NULL != m_CSemaphore)
	{
		m_CSemaphore->Unlock();
	}

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

}

void ClassSemaphoreThread::SetFunction(AFX_THREADPROC p_pFunc)
{
	m_pFunc = p_pFunc;
}

void ClassSemaphoreThread::SetArg(LPVOID p_pArg)
{
	m_pArg = p_pArg;
}

void ClassSemaphoreThread::SetInitFlag(unsigned p_uiInitFlag)
{
	m_uiInitFlag = p_uiInitFlag;
}

void ClassSemaphoreThread::TriggerThread()
{
	m_CSemaphore->Unlock();
}

void ClassSemaphoreThread::SetMemorySize(int p_nMemorySize)
{
	m_nMemorySize = p_nMemorySize;
}
