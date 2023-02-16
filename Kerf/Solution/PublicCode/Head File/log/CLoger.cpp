#include "stdafx.h"
#include "CLoger.h"
#include "../FileOperation/CFileOpertion.h"
#include <direct.h>


CLoger::CLoger(void)
{
	 m_strLogPath =_T("");
	 m_strLogName =_T("");
	 m_strLogDir = _T("");

	 //Ĭ��λ�ó����Ŀ¼ 
	 m_strLogDir = CFileOpertion::GetModuleFileDir();
	 m_strLogName = CFileOpertion::BuildTimeFileName() + _T(".txt");
	 m_strLogPath = m_strLogDir + _T("Log\\") + m_strLogName;

	 m_nLogSwitch = 0;
}


CLoger::CLoger(CString strLogPath)
{
	CLoger();
	setLogPath(strLogPath);
}

CLoger::~CLoger(void)
{
}

void CLoger::setLogPath(CString strLogPath)
{
	int t_nPos = strLogPath.ReverseFind('\\') + 1;
	int t_nNameLen = strLogPath.GetLength() - t_nPos;
	
	m_strLogPath = strLogPath;
	m_strLogDir = strLogPath.Left(t_nPos);
	m_strLogName = strLogPath.Mid(t_nPos, t_nNameLen);
};


void CLoger::setLogDir(CString p_strLogDir)
{
	m_strLogDir = p_strLogDir;
	m_strLogPath = m_strLogDir + m_strLogName;
}

void CLoger::setSubLogDir(CString p_strLogDir)
{
	m_strLogDir = m_strLogDir + p_strLogDir + _T("\\");
	setLogDir(m_strLogDir);
}

void CLoger::SetLogSwitch(int p_nLogSwitch)
{
	m_nLogSwitch = p_nLogSwitch;
}
//�˷����������ڶ����ƴ�ӣ�ֻ�������������е�һ������
CStringA CLoger::Format(const char *fmt, va_list& ap)
{
	CStringA strTmp;

	//��ÿɱ�����б�,����fmt���ó��������������ͣ�Ҳ�Ƿ������������ơ�%d %s�����ַ���
	//�˴����޷��ں����ڲ�ʹ��va_start��������ap�����б�����Ϊ�޷�ʹ��...���������ж�
	//��ר�ݣ�����ʹ�ú����Կɱ�������з�װ�޷�ʵ��
	//va_start(ap, fmt);
	strTmp.FormatV(fmt, ap);
	va_arg(ap, int);//����va_list�е�һ������
	//�ͷ���Դ,������va_start�ɶԵ���
	//va_end(ap);
	AfxMessageBox(_T("This is test code for va_list !"));
	CStringA strReturn = GetTimeStr() + strTmp;
	return "";
}

/*==============C++���������÷�ʾ��===========================

char s[1000];
int log(char *s, int size, const char *fmt, ...) //���Զ��庯������ϵͳ�ṩ��snprintf()������ͬ��
{
va_list ap;
int n=0,size=1000;
va_start(ap, fmt); //��ÿɱ�����б�,����fmt���ó��������������ͣ�Ҳ�Ƿ������������ơ�%d%s�����ַ���
n=vsnprintf (s, size, fmt, ap); //д���ַ���s
va_end(ap); //�ͷ���Դ,������va_start�ɶԵ���
return n; //����д����ַ�����
}
===============================================================*/

//************************************
// Method:    Wirtelog
// FullName:  CLoger::Wirtelog
// Access:    public 
// Returns:   int �����ַ�������
// Qualifier: ��¼��־��Ϣ
// Parameter: ENUM_LOGSWITCH p_ENUM_LOGSWITCH ��־�ȼ�
//			  �������������÷���sprintf()��ͬ
// Parameter: const char * fmt 
// Parameter: ...
//************************************
int CLoger::Wirtelog(ENUM_LOGSWITCH p_ENUM_LOGSWITCH, const char *fmt, ...)
{
	int n = 0;
	va_list ap;
	//�ж���־����
	if ((m_nLogSwitch & (int)p_ENUM_LOGSWITCH) > 0)
	{
		CStringA strTmp;

		//��ÿɱ�����б�,����fmt���ó��������������ͣ�Ҳ�Ƿ������������ơ�%d %s�����ַ���
		va_start(ap, fmt);
		strTmp.FormatV(fmt, ap);
		//�ͷ���Դ,������va_start�ɶԵ���
		va_end(ap);

		CStringA strReturn = GetTimeStr() + strTmp;
		n = strReturn.GetLength();
		WirteToFile(strReturn);
	}
	
	return n; //����д����ַ�����	
}

void CLoger::WirteToFile(CStringA p_strLogInfo)
{
	FILE *WFile = NULL;
	//����Ŀ¼
	int status = _mkdir((CStringA)m_strLogDir);

	critical_section.Lock();
	//���ļ�
	//WFile = fopen((CStringA)m_strLogPath, "a");
	fopen_s(&WFile, (CStringA)m_strLogPath, "a");
	if (NULL != WFile)
	{
		fwrite(p_strLogInfo, 1, p_strLogInfo.GetLength(), WFile);
		fwrite("\n", 1, 1, WFile);
		fclose(WFile);
	}
	critical_section.Unlock();
}

CStringA CLoger::GetTimeStr()
{
	SYSTEMTIME sysTm;
	CStringA strTimeTag;//ʱ����
	GetLocalTime(&sysTm);
	strTimeTag.Format("%4d-%02d-%02d %02d:%02d:%02d.%03d: ", sysTm.wYear, sysTm.wMonth, sysTm.wDay, sysTm.wHour, sysTm.wMinute, sysTm.wSecond, sysTm.wMilliseconds);

	return strTimeTag;
}
