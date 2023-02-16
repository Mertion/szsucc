#include "stdafx.h"
#include "CThreadLoger.h"
#include <direct.h>

CThreadLoger::CThreadLoger(void)
{
	
}
CThreadLoger* CThreadLoger::m_pThreadLoger = new CThreadLoger;
CThreadLoger* CThreadLoger::initance()
{
	if (NULL == m_pThreadLoger->m_pClassEventThread)
	{
		m_pThreadLoger->m_pClassEventThread = new ClassSemaphoreThread(0,100);
		m_pThreadLoger->m_pClassEventThread->SetArg(m_pThreadLoger);
		m_pThreadLoger->m_pClassEventThread->SetFunction(_exThread);
		m_pThreadLoger->m_pClassEventThread->Start();
	}

	return m_pThreadLoger;
}

void CThreadLoger::Dispose()
{
	if (NULL != m_pClassEventThread)
	{
		m_pClassEventThread->Stop();
	}
}

int CThreadLoger::Wirtelog(CLoger::ENUM_LOGSWITCH p_ENUM_LOGSWITCH, const char *fmt, ...)
{
	int n = 0;
	va_list ap;
	//�ж���־����
	if ((m_nLogSwitch & (int)p_ENUM_LOGSWITCH) > 0)
	{
		//������־��Ϣ�ַ���
		CStringA strTmp;
		//��ÿɱ�����б�,����fmt���ó��������������ͣ�Ҳ�Ƿ������������ơ�%d %s�����ַ���
		va_start(ap, fmt);
		strTmp.FormatV(fmt, ap);
		//�ͷ���Դ,������va_start�ɶԵ���
		va_end(ap);
		CStringA strReturn = GetTimeStr() + strTmp;
		n = strReturn.GetLength();
		
		//����־�����������
		struLogInfo t_struLogInfo;
		t_struLogInfo.LOGSWITCH = p_ENUM_LOGSWITCH;
		t_struLogInfo.strLog = strReturn;
		m_csDQLog.Lock();
		m_DQLogInfo.push_back(t_struLogInfo);
		m_csDQLog.Unlock();

		m_pClassEventThread->TriggerThread();
	}

	return n; //����д����ַ�����	
}


UINT CThreadLoger::_exThread(LPVOID lpParam)
{
	CThreadLoger* t_CThreadLoger = (CThreadLoger*)lpParam;
	return ((CThreadLoger*)lpParam)->ThreadWriteLog();
}

void CThreadLoger::OnlyWirteToFile(CStringA p_strLogInfo)
{
	//����Ŀ¼
	if (NULL != WFile)
	{
		//fwrite(p_strLogInfo, 1, p_strLogInfo.GetLength(), WFile);
		
		char chr[512] = { 0 };
		char chr1[512] = { 0 };
		memcpy_s(chr1, 511, p_strLogInfo, p_strLogInfo.GetAllocLength());

		int nLen = sprintf_s(chr, 510, "%s", chr1);

		fwrite(chr, 1, nLen, WFile);
		fwrite("\n", 1, 1, WFile);
	}
}

void CThreadLoger::OpenFile()
{
	//����Ŀ¼
	int status = _mkdir((CStringA)m_strLogDir);
	//���ļ�
	if (fopen_s(&WFile, (CStringA)m_strLogPath, "a"))
	{
		WFile = NULL;
	}
}
void CThreadLoger::CloseFile()
{
	if (NULL != WFile)
	{
		fclose(WFile);
	}
}
int CThreadLoger::ThreadWriteLog()
{
	m_csFileLog.Lock();

	//����ʱ��Ϊ���������־���еĴ������ͬʱ��Ӷ�����Ϣ������߶��̲߳���ʱ��¼��־���ٶ�
	Sleep(10);

	//���ļ���Ϊ�����Ч�ʣ���־�ļ����д򿪺͹ر�
	//OpenFile();

	FILE* tWFile = NULL;
	if (fopen_s(&tWFile, (CStringA)m_strLogPath, "a"))
	{
		tWFile = NULL;
	}
	else
	{
		//���ļ���д����־��Ϣ
		m_csDQLog.Lock();
		while (m_DQLogInfo.size() > 0)
		{
			CStringA strLog = m_DQLogInfo.front().strLog;

			if ((m_nLogSwitch & (int)m_DQLogInfo.front().LOGSWITCH) > 0)
			{
				char chr[512] = { 0 };
				char chr1[512] = { 0 };
				memcpy_s(chr1,511,strLog,strLog.GetAllocLength());
				int nLen = sprintf_s(chr, 510, "%s", chr1);
				//fwrite("\n", 1, 1, tWFile);
				fwrite(chr, 1, nLen, tWFile);
				fwrite("\n", 1, 1, tWFile);
			}
			m_DQLogInfo.pop_front();
		}
		m_csDQLog.Unlock();

		fclose(tWFile);
	}

	m_csFileLog.Unlock();
	return 0;
}