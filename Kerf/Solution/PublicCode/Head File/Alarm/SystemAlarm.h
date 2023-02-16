#pragma once
#include "log/CSingletonLoger.h"
#include "log/CThreadLoger.h"
#include "FileOperation/CINIObject.h"
#include "General.h"

//�����ñ�����Ϣ
typedef struct _AlarmInfo
{
	CONST static int CONST_MAX_ALARMINFOLEN = 1024;
	//�������
	int AlarmNo;
	char arrchrAlarmInfo[CONST_MAX_ALARMINFOLEN];
	_AlarmInfo()
	{
		AlarmNo = 0;
		memset(arrchrAlarmInfo, 0, CONST_MAX_ALARMINFOLEN);
	}

}AlarmInfo;

//�ײ��ñ�����Ϣ
typedef struct _AlarmUnit :public AlarmInfo
{
	//����״̬�Ƿ��������һ������״̬δ������ñ��������ٴ�����淢��
	BOOL bRelease;
	_AlarmUnit()
	{
		bRelease = TRUE;
	}
}AlarmUnit;

//���ñ�����Ϣ�ص�����
//typedef void(WINAPI *pfuncSetAlarmInfo) (AlarmInfo);
typedef void( *pfuncSetAlarmInfo) (AlarmInfo);
//������
class SystemAlarm
{
public:
	enum class ENUM_LANGUAGE
	{
		//Ӣ��
		ENUM_LANGUAGE_EN = 0,
		//����
		ENUM_LANGUAGE_CN,
		//��������
		ENUM_LANGUAGE_LOCAL,
	};

protected:
	SystemAlarm();

public:
	static SystemAlarm* initance();
	//�Զ��������״̬���������Զ��������״̬���ٴε��ÿ�ֱ������淢�ͱ���
	void AutomReleaseAlarm(AlarmUnit* p_AlarmUnit);
	//�ֶ��������״̬������������ý������״̬�������ٴα���ʱ�Ż�����淢�ͱ���
	void NormalReleaseAlarm(AlarmUnit* p_AlarmUnit);
	//�������״̬
	void ReleaseAlarm(AlarmUnit* p_AlarmUnit);
	//���ñ����ص�����
	void SetAlarmCallBackFunction(void* p_pFun);

	//�ַ�������
	void Warning(int p_nWarningNo, CString p_strWarning);
	//���ݱ�����ű���
	void Warning(int P_nWarningNo);
	//���ݵ�Ԫ�ű���
	void Warning(int P_nWarningNo, int p_nUnitNo);
	//����վ�ű���
	void Warning(int P_nWarningNo, int p_nUnitNo,int p_nStationNo);
	//��������
	void UpdateLanguage();

private:
	CString getWarningStr(int p_nWarningNo);
private:
	//����ָ��
	static SystemAlarm* m_pSystemAlarm;
	//�Ƿ�ʵ������־
	static bool m_bISInitance;
	//ȫ����־����
	//CSingletonLoger* m_pCSingletonLogger;
	CThreadLoger * m_pCThreadLoger = NULL;
	//���汨���ص�����ָ��
	pfuncSetAlarmInfo m_pfuncSetAlarmInfo = NULL;
	//����
	ENUM_LANGUAGE m_Language = ENUM_LANGUAGE::ENUM_LANGUAGE_EN;

	//������Ϣ�����ļ���
	CString m_strWarningFilePatch;
	//������Ϣ�����ļ���������
	CINIObject * m_pWarningIni = NULL;

	//�ض��ַ�
	CString m_strUnit;
	CString m_strStation;
};


