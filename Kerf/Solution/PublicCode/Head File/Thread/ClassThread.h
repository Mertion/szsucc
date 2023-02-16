#pragma once

//����ѭ���߳���
class ClassThread
{
public:
	enum ENUM_THREADINFO
	{
		ENUM_THREADINFO_SUCCESS = 0,
		ENUM_THREADINFO_CREATTHREADFAILD,	//�����߳�ʧ��
		ENUM_THREADINFO_FUNCISEMPYT,		//����ָ��Ϊ��
		ENUM_THREADINFO_THREADISRUN,		//�߳��Ѿ�������

	};
	
	
public:
	ClassThread();
	~ClassThread();

	//�̻߳ص�����
	unsigned  static __stdcall exThreadTask(LPVOID lpParam);
	//�߳�ִ�к���
	unsigned ThreadTask();
	//static unsigned __stdcall ThreadStaticEntryPoint(void * pThis);

	//�����߳�
	int Start();
	//ֹͣ�߳�
	void Stop();
	//��ͣ�߳�����
	void SuspendThread();
	//�ָ��߳�����
	void ResumeThread();
	//���ûص�����
	void SetFunction(AFX_THREADPROC p_pFunc);
	//�����̲߳���
	void SetArg(void* p_pArg);
	//�����̳߳�ʼ״̬:Ĭ��Ϊ��
	void SetInitFlag(unsigned p_uiInitFlag);
	//����ɨ��ʱ����
	void SetInterval(int p_nInterval);
protected:
	//�߳���ͣ��־
	bool m_bSuspendThread = false;
	//�˳��̱߳�־
	bool m_bExitThread = false;
	//�߳̿�ʼ�ź�
	HANDLE m_hStartEvent = NULL;
	//�߳̽����ź�
	HANDLE m_hFinishEvent = NULL;
	//�߳̾��
	HANDLE m_hThredHandle = NULL;
	//�̳߳�ʼ״̬: 0-��������,CREATE_SUSPEND-���������
	unsigned m_uiInitFlag = 0;
	//�߳�ID
	unsigned  m_uiThreadID = 0;
	//�̺߳���ָ��
	AFX_THREADPROC m_pFunc = NULL;
	//�̲߳����б�
	void* m_pArg = NULL;
	//�߳�״̬��
	DWORD   dwExitCode = 0;

	//�߳�ɨ����
	int m_nInterval = 10;
	
};

