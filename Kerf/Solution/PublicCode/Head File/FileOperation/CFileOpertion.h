#pragma once

#include <afxmt.h>
//enum ERROR_LOADDLLFILE
//{
//	ERROR_LOADDLLFILE_NOTINIT = -1,
//	ERROR_LOADDLLFILE_SUCCESS = 0,
//	ERROR_LOADDLLFILE_LOADDLLFAILED,
//	ERROR_LOADDLLFILE_LOADFUNCTIONFAILED
//};



class CFileOpertion
{
public:
	//CFileOpertion();
	//~CFileOpertion();

	//������г���Ŀ¼
	static CString GetModuleFileDir();
	//�����ļ��Ƿ����
	static bool FindFile(char * p_cstrFilePath);
	//��ʱ�������ļ���
	static CString BuildTimeFileName();
	//���������ļ�
	static void ClearFile(CString p_strDir, int p_nDays);
	//д���ݵ��ļ�
	void WirteToFile(CStringA p_strLogPath, CStringA p_strLogInfo);

private:
	CCriticalSection critical_section;
};

