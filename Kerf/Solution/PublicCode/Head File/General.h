#pragma once
//���й���ͨ��ͷ�ļ�

enum ENUM_LANGUAGE
{
	//Ӣ��
	ENUM_LANGUAGE_EN = 0,
	//����
	ENUM_LANGUAGE_CN,
	//��������
	ENUM_LANGUAGE_LOCAL,
};
//ִ�н��
enum ENUM_RESULT
{
	//δִ��
	ENUM_RESULT_NONE = -1,
	//�ɹ�
	ENUM_RESULT_SUCCESS,
	//ʧ��
	ENUM_RESULT_FAILED,
};


//ִ�н���ṹ��
typedef struct _structResult
{
	//�Ƿ���� 
	bool bIsDone;
	//�Ƿ�ɹ�
	bool bIsSuccess;
	_structResult()
	{
		bIsDone = false;
		bIsSuccess = false;
	}
}structResult;


