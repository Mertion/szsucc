#pragma once
#include "CLoger.h"
#include "Thread/ClassEventThread.h"
#include "Thread/ClassSemaphoreThread.h"
#include <deque>

using namespace std;
//�߳���־��
//����ģ�飬���̷߳�����¼��־
//������д��־�ӿ�ʱ���Ƚ�Ҫ��¼�����ݴ�����־���У�
//Ȼ�󴥷�д��־��������д���߳̽���Ϣд����־�ļ���
//ʹ�÷�����
//1. �ڳ����ʼʱʵ����һ����־�����ں�������λ��ʹ��ʱ�����Գ�ʼ������Ϊ׼��
//2. ��ʵ��������ʱĬ��λ��Ϊ�����Ŀ¼�£�����ı�λ������ʵ�����������趨��
//3. �ļ�Ĭ��������ʱ��Ϊ���ơ�
//4. �˳�ϵͳʱ�����Dispose()�������ٶ���
class CThreadLoger :public CLoger
{
protected:
	typedef struct _struLogInfo
	{
		ENUM_LOGSWITCH LOGSWITCH;
		CStringA strLog;
	}struLogInfo;
	typedef deque<struLogInfo> DQLogInfo;
protected:
	CThreadLoger();

public:
	//ʵ������־����
	static CThreadLoger* initance();
	//������־����
	void Dispose();
	//д��־
	virtual int Wirtelog(ENUM_LOGSWITCH p_ENUM_LOGSWITCH, const char *fmt, ...);

private:
	UINT static _exThread(LPVOID lpParam);
	int ThreadWriteLog();
	void OnlyWirteToFile(CStringA p_strLogInfo);
	void OpenFile();
	
	void CloseFile();
private:
	//������ָ��
	static CThreadLoger* m_pThreadLoger;
	//��־��¼�߳�
	ClassSemaphoreThread* m_pClassEventThread = NULL;
	//��־���ݶ���
	DQLogInfo m_DQLogInfo;
	//���������ٽ���
	CCriticalSection m_csDQLog;
	//�ļ��ٽ���
	CCriticalSection m_csFileLog;
	//��־�ļ�
	FILE *WFile = NULL;
};


