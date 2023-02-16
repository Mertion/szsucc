#pragma once
enum ERROR_LOADDLLFILE
{
	//DLLδ��ʼ��
	ERROR_LOADDLLFILE_NOTINIT = -1,	
	//DLL���سɹ�
	ERROR_LOADDLLFILE_SUCCESS = 0,
	//DLLl����ʧ��
	ERROR_LOADDLLFILE_LOADDLLFAILED,
	//��������ʧ��
	ERROR_LOADDLLFILE_LOADFUNCTIONFAILED
};


//��̬����DLL��
//ʹ�÷���
//  1. �ȵ���LoadDllFile����DLL
//  2. ʹ��LoadFuncAddress��������Ҫ�õ��ĺ���
//  3. ��ִ��DLL�ڵķ���ʱ���ȵ���CheckFuncPinterISNULLУ�鷽���Ƿ񱻼��أ�Ȼ���ٵ�����Ӧ����
class CLoadDLLFunction
{
public:
	//CLoadDLLFunction();
	//~CLoadDLLFunction();

	/*static CString GetModuleFileDir();*/
	static int LoadDllFile(IN CString strFileDir, IN CString strFileName, OUT HINSTANCE &pHINSTANCE);
	static int LoadDllFile(IN CString strFilePatch, OUT HINSTANCE &pHINSTANCE);
	static int FreeDLLFile(IN OUT HINSTANCE &pHINSTANCE);
	static int LoadFuncAddress(IN HINSTANCE &pHINSTANCE, IN CString p_strDescription, OUT void ** pFunc);
	static int CheckFuncPinterISNULL(IN void * p_pFunc, IN CString p_strDescription);
};

