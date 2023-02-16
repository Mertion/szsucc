#pragma once
#include <afxmt.h>
//�����ļ��࣬���ڲ������������ļ�
//�÷�:
//1. ͨ��SetINIFileName��SetINIFilePath�������������ļ���Ϣ��
//2. ͨ����Ӧ��get/set�������û��ȡ�����ļ��е���Ϣ��
class CINIObject
{
public:
	enum ENUM_INIERR
	{
		//�����ɹ�
		ENUM_INIERR_SUCCESS = 0,
		//����ļ�·��ʧ�ܣ�����·��������ļ�������
		ENUM_INIERR_GETMODULEPATCH_FAIL,
		//�ļ�������
		ENUM_INIERR_FILENOTFIND
	};
private:
	CString m_strINIFilePatch;
	CString m_strINIFileName;

	CCriticalSection critical_section;
public:
	CINIObject(void);
	~CINIObject(void);


	//���������ļ�����
	int SetINIFileName(IN CString p_strINIFileName);
	//��ȡ�ļ�·��
	void SetINIFilePath(IN CString p_strINIFilePatch);
	//��ȡint������
	int GetINIFileInt(IN CString p_strAppName, IN CString p_strKEY, IN int p_nDefultVal, OUT int &p_nVal);
	//��ȡstring������
	int GetINIFileString(IN CString p_strAppName, IN CString p_strKEY, IN CString p_strDefult, IN int p_nSize, OUT CString &p_strReturnedString);
	//��ȡstring������
	int GetINIFileString(IN CString p_strAppName, IN CString p_strKEY, IN CString p_strDefult, IN int p_nSize, OUT TCHAR *p_strReturnedString);
	//����int������
	int SetINIFileInt(IN CString p_strAppName, IN CString p_strKEY, IN int p_nVal);
	//����string������
	int SetINIFileString(IN CString p_strAppName, IN CString p_strKEY, IN CString p_strVal);

private:
	//��ȡ�ļ�·��
	int GetINIFilePatch(IN CString p_strIniFileName, OUT CString &p_strIniPath);
};