
#pragma once
#pragma warning(disable:4996)

#include "stdafx.h"
#include "ConnectionIF.h"
#include "log/CThreadLoger.h"

//Socket �ͻ����࣬ʵ�ֿͻ��˵�������������
class ConnectionSocketClient : public ConnectionIF
{

public:
	ConnectionSocketClient();
	ConnectionSocketClient(int p_nPort, CString p_strAddress, int p_nProtocolType = 0);
	int Connect();
	int DisConnect();
	bool ISConnect();
	int Receive(char* p_pchrData, const int p_nDataSize, int& p_nRecDatalen);
	int Send(char* p_pchrData, int p_nDatalen);

public:
	~ConnectionSocketClient();
	void init();
protected:
	//�ͻ����׽���
	SOCKET m_sclient;
	//���ӵ�ַ
	sockaddr_in m_serAddr;
	//Э������:0-TCP 1-UDP
	int m_nProtocolType = 0;
	//��ǰ����״̬ false-δ���� true-����
	bool m_bConnectState = false;

	CString m_strIP;
	int m_nPort = 0;
	CThreadLoger* m_pThreadLoger;
};

