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
		sRtn = GT_AxisOn(i);					// ʹ���˶���0
	}

	GT_ZeroPos(1, 4);							//λ������

	return sRtn;
}

int Googol::GetState()
{
	if (GetIsOpen())
	{
		GT_GetPrfPos(1, &prfPos, 1, NULL);	//��ȡ1��滮λ��
		strTmp.Format(_T("%.3f"), prfPos);

		GT_GetPrfVel(1, &prfVel, 1, NULL);	//��ȡ1��滮�ٶ�

		GT_GetEncPos(1, &encPos, 1, NULL);	//��ȡ1��ʵ��λ��

		GT_GetEncVel(1, &encVel, 1, NULL);	//��ȡ1��ʵ���ٶ�
	}

	return 0;
}

int Googol::run(int p_nAxis,double p_dAcc,double p_dDec,int p_nPos,double p_dVel)
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
int Googol::Stop()
{
	GT_Stop(1, 4);	//ֹͣ�˶�

	return 0;
}
