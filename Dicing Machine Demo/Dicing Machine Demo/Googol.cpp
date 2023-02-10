#include "stdafx.h"
#include "Googol.h"

Googol::Googol()
{
	SetIsOpen(false);

	prfPos = 0.0; 
	prfVel = 0.0; 
	encPos = 0.0;
	encVel = 0.0;
}

Googol::~Googol()
{
	GT_Stop(0xFF, 0xFF);		//��ͣ������
	for (int i = 1; i <= 4; ++i)
	{
		GT_AxisOff(i);
	}

	SetIsOpen(false);
	
}

int Googol::Open()
{
	short sRtn;
	sRtn = GT_Open();

	if (0 == sRtn)
	{
		SetIsOpen(true);
	}

	sRtn = GT_Reset();							// ��λ�˶�������
	sRtn = GT_LoadConfig("test.cfg");			// ���ؿ����������ļ�
	sRtn = GT_ClrSts(1, 4);						// ���1~4�����״̬

	for (int i = 1; i <= 4; ++i)
	{
		GT_StepDir(i);							// ����ӷ���ģʽ
		//GT_StepPulse(i);						// CW/CCW ģʽ
		sRtn = GT_AxisOn(i);					// ʹ���˶���0
	}

	return sRtn;
}

int Googol::GetState(int nAxis, double p_dPrfPos, double p_dPrfVel, double p_dPos, double p_dVel)
{
	if (GetIsOpen())
	{
		GT_GetPrfPos(nAxis, &p_dPrfPos, 1, NULL);	//��ȡ1��滮λ��

		GT_GetPrfVel(nAxis, &p_dPrfVel, 1, NULL);	//��ȡ1��滮�ٶ�
		
		GT_GetEncPos(nAxis, &p_dPos, 1, NULL);	//��ȡ1��ʵ��λ��

		GT_GetEncVel(nAxis, &p_dVel, 1, NULL);	//��ȡ1��ʵ���ٶ�
	}

	return 0;
}

int Googol::JogMove(int p_nAxis, double p_dAcc, double p_dDec, double p_dVel)
{
	GT_ZeroPos(p_nAxis, 4);							//λ������

	GT_PrfJog(p_nAxis);

	TJogPrm jog;
	GT_GetJogPrm(p_nAxis, &jog);
	jog.acc = 0.0625;
	jog.dec = 0.0625;
	GT_SetJogPrm(p_nAxis, &jog);
	GT_SetVel(p_nAxis, p_dVel);

	GT_Update(1 << (p_nAxis - 1));

	return 0;
}
int Googol::PosMove(int p_nAxis,double p_dAcc,double p_dDec,long p_nPos,double p_dVel)
{
	GT_SetPrfPos(p_nAxis, 0);		//������Ϊ��λģʽ
	GT_PrfTrap(p_nAxis);			//��ȡ��λ�˶�����
	TTrapPrm trap;
	GT_GetTrapPrm(p_nAxis, &trap);
	trap.acc = p_dAcc;
	trap.dec = p_dDec;
	trap.smoothTime = 1;		
	GT_SetTrapPrm(p_nAxis, &trap);	//���õ�λ�˶�����
	GT_SetPos(p_nAxis, p_nPos);		//������Ŀ��λ��
	GT_SetVel(p_nAxis, p_dVel);		//������Ŀ��λ��

	GT_Update(1 << 0);			//�������˶�

	return 0;
}
int Googol::StopAll()
{
	//GT_Stop(mask, option): mask-��λȡ�ᣬoption-��λȡ���ֹͣ��ʽ��1-��ͣ��0-ƽ��ͣ
	
	//GT_Stop(0xFF, 0);			//ƽ��ֹͣ�˶�
	GT_Stop(0xFF, 0xFF);		//��ͣ������
	return 0;
}

int Googol::StopAxis(int p_nAxis)
{
	GT_Stop(1 << (p_nAxis - 1), 1 << (p_nAxis - 1));	//ֹͣ�˶�
	return 0;
}

int Googol::AutoHome(int p_nAxis)
{
	short sRtn;
	short gAxis = p_nAxis;
	THomeStatus tHomeSts;
	/*sRtn = GT_Open();
	sRtn = GT_Reset();*/
	sRtn = GT_AlarmOff(gAxis);
	sRtn = GT_LmtsOn(gAxis); //���û�н���λ��������Ҫ����λȡ��
	sRtn = GT_LmtSns(3); //��λΪ�͵�ƽ��������ʵ��������ã�
	sRtn = GT_EncSns(1); //�������������ã���ʵ�ʱ��������ã���֤�滮λ����ʵ��λ�÷���һ�£�
	sRtn = GT_ClrSts(gAxis);
	sRtn = GT_ZeroPos(gAxis);
	//sRtn = GT_AxisOn(gAxis); //����ʹ����
	//���� Smart Home ��ԭ�����
	THomePrm tHomePrm;
	sRtn = GT_GetHomePrm(1, &tHomePrm);
	tHomePrm.mode = HOME_MODE_LIMIT_HOME_INDEX;
	tHomePrm.moveDir = 1;
	tHomePrm.indexDir = 1;
	tHomePrm.edge = 0;
	tHomePrm.velHigh = 5;
	tHomePrm.velLow = 1;
	tHomePrm.acc = 0.1;
	tHomePrm.dec = 0.1;
	tHomePrm.searchHomeDistance = 200000;
	tHomePrm.searchIndexDistance = 30000;
	tHomePrm.escapeStep = 1000;
	tHomePrm.homeOffset = 200;
	
	sRtn = GT_GoHome(1, &tHomePrm); //���� Smart Home ��ԭ��
	do
	{
		sRtn = GT_GetHomeStatus(1, &tHomeSts); //��ȡ��ԭ��״̬
	} while (tHomeSts.run); //�ȴ�����ԭ��ֹͣ

	return 0;
}