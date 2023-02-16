#pragma once
#include "stdafx.h"
#include <afxmt.h>

using namespace std;
class CLoger
{
public:
	//��־�ȼ�
	enum class ENUM_LOGSWITCH
	{
		//����¼
		ENUM_LOGSWITCH_NONE = 0,
		//��ͨ��Ϣ
		ENUM_LOGSWITCH_INFO = 0x01,
		//������Ϣ
		ENUM_LOGSWITCH_DEBUG = 0x02,
		//������Ϣ
		ENUM_LOGSWITCH_WARNING = 0x04,
	};

public:
	CLoger();
	CLoger(CString strLogPath);
	~CLoger();

	//������־·��
	void setLogPath(CString strLogPath);
	//������־Ŀ¼
	void setLogDir(CString p_strLogDir);
	//������־��¼���������Ŀ¼��
	void setSubLogDir(CString p_strLogDir);
	//������־�ȼ�
	void SetLogSwitch(int p_nLogSwitch);
	//д��־
	virtual int Wirtelog(ENUM_LOGSWITCH p_ENUM_LOGSWITCH, const char *fmt, ...);
protected:
	//��ʽ����־�ַ���
	CStringA Format(const char *fmt, va_list& ap);
	//д����־�ļ�
	void WirteToFile(CStringA p_strLogInfo);
	//��õ�ǰʱ���ַ���
	CStringA GetTimeStr();
protected:
	//��־�ļ�·��
	CString m_strLogPath;
	//��־�ļ���
	CString m_strLogName;
	CString m_strLogDir;

	//��ǰ��־�����ȼ�
	int m_nLogSwitch;
private:
	CCriticalSection critical_section;
};


