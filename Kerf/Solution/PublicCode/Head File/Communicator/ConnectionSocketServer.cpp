
#include "stdafx.h"
#include "ConnectionSocketServer.h"

ConnectionSocketServer::ConnectionSocketServer()
{
	init();
}

ConnectionSocketServer::ConnectionSocketServer(int p_nPort, CString p_strAddress, int p_nProtocolType /*= 0*/)
{
	init();
	m_serAddr.sin_port = htons(p_nPort);
	//m_serAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	m_serAddr.sin_addr.S_un.S_addr = inet_addr((CStringA)p_strAddress);

	m_nProtocolType = p_nProtocolType;

	//���������߳�
	m_ClassEventThread->Start();
	//�������
	m_ClassEventThread->TriggerThread();
}

ConnectionSocketServer::~ConnectionSocketServer()
{
	//�ر�����
	DisConnectServer();

	if (NULL != m_hQureConnect)
	{
		CloseHandle(m_hQureConnect);
	}
	if (NULL != m_hExitListen)
	{
		CloseHandle(m_hExitListen);
	}
}

int ConnectionSocketServer::init()
{
	m_serAddr.sin_family = AF_INET;
	m_serAddr.sin_port = htons(0);
	m_serAddr.sin_addr.S_un.S_addr = INADDR_ANY;

	/*m_slisten = INVALID_SOCKET;*/
	m_sclient = INVALID_SOCKET;
	m_bConnectState = false;

	//ConnectionSocketClient::ConnectionSocketClient();
	m_slisten = INVALID_SOCKET;

	if (NULL == m_hQureConnect)
	{
		m_hQureConnect = CreateEvent(NULL, TRUE, FALSE, NULL);
		ResetEvent(m_hQureConnect);
	}
	if (NULL == m_hExitListen)
	{
		m_hExitListen = CreateEvent(NULL, TRUE, FALSE, NULL);
		ResetEvent(m_hExitListen);
	}

	m_hHandles[0] = m_hExitListen;
	m_hHandles[1] = m_hQureConnect;

	if (NULL == m_ClassEventThread)
	{
		m_ClassEventThread = new ClassEventThread();
		m_ClassEventThread->SetFunction(_exListen);
		m_ClassEventThread->SetArg(this);
	}

	return 0;
}

int ConnectionSocketServer::Connect()
{
	//����Ӧ��
	SetEvent(m_hQureConnect);

	return ENUM_MESSAGE_SUCCESS;
}

int ConnectionSocketServer::DisConnectServer()
{
	//�˳�����
	SetEvent(m_hExitListen);

	//�رտͻ����׽���
	//DisConnect();
	if (m_sclient != INVALID_SOCKET)
	{
		//shutdown(m_sclient, SD_BOTH);
		closesocket(m_sclient);
		//�˴����ܳ�ʼ���ͻ����׽��֣�����ᵼ�¿ͻ����޷����ж������ӡ�
		//m_sclient = INVALID_SOCKET;
	}
	//�رշ�����׽���
	if (m_slisten != INVALID_SOCKET)
	{
		closesocket(m_slisten);
		m_slisten = INVALID_SOCKET;
	}
	//�������
	WSACleanup();
	//ֹͣ�����߳�
	m_ClassEventThread->Stop();

	m_pThreadLoger->Wirtelog(CLoger::ENUM_LOGSWITCH_INFO, "Network server connection disconnected !");
	return ENUM_MESSAGE_SUCCESS;
}
int ConnectionSocketServer::DisConnect()
{
	m_bConnectState = false;
	//����Ӧ��
	SetEvent(m_hQureConnect);
	m_pThreadLoger->Wirtelog(CLoger::ENUM_LOGSWITCH_INFO, "Network client connection disconnected !");
	return ENUM_MESSAGE_SUCCESS;
}

bool ConnectionSocketServer::ISConnect()
{
	return m_bConnectState;
}

int ConnectionSocketServer::Receive(char* p_pchrData, const int p_nDataSize, int& p_nRecDatalen)
{
	//char t_arrchrRecvData[const_nMaxReceiveDataLen] = { 0 };

	char* t_pchrRecvData = new char[p_nDataSize];
	memset(t_pchrRecvData, 0, p_nDataSize);
	int ret = recv(m_sclient, t_pchrRecvData, (p_nDataSize - 1), 0);

	memset(p_pchrData, 0, p_nDataSize);
	p_nRecDatalen = 0;
	switch (ret)
	{
	case 0:
	{
		DisConnect();
		ret = ENUM_MESSAGE_DISCONNECT;
	}
	break;
	case SOCKET_ERROR:
	{
		if (10035 == WSAGetLastError())
		{
			m_pThreadLoger->Wirtelog(CLoger::ENUM_LOGSWITCH_INFO, "Network connection error, error number: 10035!");
		}
		if (10060 == WSAGetLastError())
		{
			m_pThreadLoger->Wirtelog(CLoger::ENUM_LOGSWITCH_INFO, "Network connection error, error number: 10060 !");
		}

		ret = ENUM_MESSAGE_CONNECTFAILED;
		DisConnect();
	}
	break;
	default:
	{
		if (ret < p_nDataSize)
		{
			memcpy(p_pchrData, t_pchrRecvData, ret);
			p_nRecDatalen = ret;
			ret = ENUM_MESSAGE_SUCCESS;
			m_pThreadLoger->Wirtelog(CLoger::ENUM_LOGSWITCH_INFO, "Success rec: %s", p_pchrData);
		}
		else
		{
			ret = ENUM_MESSAGE_ERROR;
			m_pThreadLoger->Wirtelog(CLoger::ENUM_LOGSWITCH_INFO, "Failed to receive data !");
		}
	}
	break;
	}

	return ret;
}


int ConnectionSocketServer::Send(char* p_pchrData, int p_nDatalen)
{
	int ret = send(m_sclient, p_pchrData, p_nDatalen, 0);
	if (ret > 0)
	{
		ret = ENUM_MESSAGE_SUCCESS;
		m_pThreadLoger->Wirtelog(CLoger::ENUM_LOGSWITCH_INFO, "Success send: %s", p_pchrData);
	}
	else
	{
		ret = ENUM_MESSAGE_FAILED;
		m_pThreadLoger->Wirtelog(CLoger::ENUM_LOGSWITCH_INFO, "Failed send: %s", p_pchrData);
	}
	return ret;
}

UINT ConnectionSocketServer::_exListen(LPVOID lpParam)
{
	ConnectionSocketServer* t_pConnectionSocketServer = (ConnectionSocketServer *)lpParam;
	t_pConnectionSocketServer->Listen();
	return 0;
}

int ConnectionSocketServer::Listen()
{
	//��ʼ��WSA  
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	DWORD dwEvent;

	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		AfxMessageBox(_T("Init WAS is Failed !"));
		return 0;
	}

	//�����׽���  
	m_slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_slisten == INVALID_SOCKET)
	{
		AfxMessageBox(_T("Init socket is Failed !"));
		return 0;
	}

	if (bind(m_slisten, (LPSOCKADDR)&m_serAddr, sizeof(m_serAddr)) == SOCKET_ERROR)
	{
		AfxMessageBox(_T("Bind net address is Failed !"));
		return 0;
	}

	//��ʼ����  
	if (listen(m_slisten, 5) == SOCKET_ERROR)//���еڶ������������ܹ����յ����������� 
	{
		AfxMessageBox(_T("Creat listen is Failed !"));
		return 0;
	}

	int nAddrlen = sizeof(m_remoteAddr);

	while (true)
	{
		dwEvent = WaitForMultipleObjects(2, m_hHandles, FALSE, INFINITE);
		switch (dwEvent)
		{
		case WAIT_OBJECT_0 + 0://�˳������ź�
		{
			ResetEvent(m_hExitListen);
			return 0;
		}
		break;
		case WAIT_OBJECT_0 + 1://���������ź�
		{
			m_sclient = accept(m_slisten, (SOCKADDR *)&(m_remoteAddr), &nAddrlen);//������ﲻ��accept����conection�Ļ������ͻ᲻�ϵļ���
			CStringA t_strIP;
			t_strIP.Format("%s", inet_ntoa(m_remoteAddr.sin_addr));
			int t_nPort = m_remoteAddr.sin_port;
			if (m_sclient == INVALID_SOCKET)
			{
				m_pThreadLoger->Wirtelog(CLoger::ENUM_LOGSWITCH_INFO, "Network connection failed, Remote IP: %s Port=%d ", t_strIP, t_nPort);
				//��ͻ��˽�������ʧ��,�ȴ�10ms�����¿�ʼ����
				Sleep(10);
				continue;

			}
			else
			{
				ResetEvent(m_hQureConnect);
				m_bConnectState = true;
				m_pThreadLoger->Wirtelog(CLoger::ENUM_LOGSWITCH_INFO, "Network is connected, Remote IP: %s Port=%d ", t_strIP, t_nPort);
				//��ͻ��˽������ӳɹ�,�ȴ�10ms�����¿�ʼ����
				Sleep(10);
			}
		}
		break;
		default:
			break;
		}

	}

}
