
#pragma once

#include "stdafx.h"

//��׼���ӽӿڣ�������ͨѶ���ӷ�ʽ����Socket��232��485��
class ConnectionIF
{
public:
	enum ENUM_MESSAGE
	{
		ENUM_MESSAGE_SUCCESS = 0,
		ENUM_MESSAGE_CONNECTFAILED,
		ENUM_MESSAGE_DISCONNECT,
		ENUM_MESSAGE_ERROR,
		ENUM_MESSAGE_FAILED,
	};
public:
	virtual int Connect() = 0;
	virtual int DisConnect() = 0;
	virtual bool ISConnect() = 0;
	virtual int Receive(char* p_pchrData, const int p_nDataSize, int& p_nRecDatalen) = 0;
	virtual int Send(char* p_pchrData, int p_nDatalen) = 0;
};

