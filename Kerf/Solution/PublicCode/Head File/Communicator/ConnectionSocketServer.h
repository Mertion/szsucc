
#pragma once
#pragma warning(disable:4996)

#include "stdafx.h"
#include "ConnectionIF.h"
#include "Thread/ClassEventThread.h"
#include "log/CThreadLoger.h"

//Socket ���������ʵ�֣���ɵ��˿ڶԵ��ͻ������ӡ�
//һ�Զ�ͻ��˷�ʽ���ʺ�ĿǰϵͳӦ�ô����������⣺
//1. ���ݲ������ڸò���ʵ��Ӱ��Ŀǰϵͳ�ṹ��������ڸò���ʵ�ֻᵼ�����ݰ�������ʱ�޷�����
//2. ��ͻ���ÿ���ͻ���ҵ���ֲ���ͬ�޷���ȷ�����ĸ�������ʲôҵ�񣬵��·�����ڷ�������ʱ���ܻ������޷�ʹ����ȷ�ͻ��˵������
//   a. �����˼�¼���ĸ��ͻ��˷�����ָ���ڷ��أ�����������ѶϿ����������޷����ء�
//   b. ���������ͻ��˷��ػ����ӿͻ��˳������Ӷȡ�

class ConnectionSocketServer : public ConnectionIF
{
public:

public:
	ConnectionSocketServer();
	ConnectionSocketServer(int p_nPort, CString p_strAddress, int p_nProtocolType = 0);
	~ConnectionSocketServer();
	int init();
	int Connect();
	int DisConnect();
	bool ISConnect();
	int Receive(char* p_pchrData, const int p_nDataSize, int& p_nRecDatalen);
	int Send(char* p_pchrData, int p_nDatalen);
private:

	//�����̻߳ص�����
	UINT static _exListen(LPVOID lpParam);
	//�����ͻ��˽��벢�������ӣ����ͻ��˶Ͽ����Զ�������һ������
	int Listen();
protected:

	int DisConnectServer();
protected:
	//�ͻ����׽���
	SOCKET m_sclient;
	//���ӵ�ַ
	sockaddr_in m_serAddr;
	//Э������:0-TCP 1-UDP
	int m_nProtocolType = 0;
	//��ǰ����״̬ false-δ���� true-����
	bool m_bConnectState = false;

	//����˼����׽���  
	SOCKET m_slisten;
	//Զ�̿ͻ��˵�ַ
	sockaddr_in m_remoteAddr;
	//Ӧ��ͻ��������¼��ź�
	HANDLE m_hQureConnect = NULL;
	//�˳������ź�
	HANDLE m_hExitListen = NULL;
	HANDLE m_hHandles[2];
	//���������̶߳���
	ClassEventThread* m_ClassEventThread = NULL;

	CThreadLoger* m_pThreadLoger;
};
