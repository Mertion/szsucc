#pragma once

//��Ȩ����
enum enum_AuthorizationType
{
	enum_AuthorizationType_None = 0,					//0-����Ȩ
	enum_AuthorizationType_Normal,						//��ͨ��Ȩ
	enum_AuthorizationType_Emergency,					//Ӧ����Ȩ
	enum_AuthorizationType_ProductionAuthorization,		//������Ȩ
	enum_AuthorizationType_DemoMode,					//��ʾ��Ȩ


};

//��Ʒ��Ȩ��
enum enum_ProductCode
{
	enum_ProductCode_PersoPDM = 1,		//���˻����ݻ���������5500ϵ�С�8500ϵ�У�
	enum_ProductCode_120,				//120ϵ��
};
//������Ȩ��
enum enum_FunctonCode
{
	enum_FunctonCode_IC = 1,			//IC
	enum_FunctonCode_Laser,				//����
	enum_FunctonCode_Contactless,		//�ǽ�
	enum_FunctonCode_OCR,				//OCRʶ��
	enum_FunctonCode_8500Laser,			//8500���ټ���
};

//����״̬��
enum enum_FunctionstatusCode
{
	enum_FunctionstatusCode_None = 0,	//������
	enum_FunctionstatusCode_Normal,		//��ͨ�����ȡ����
	enum_FunctionstatusCode_Unlimited,	//������
};