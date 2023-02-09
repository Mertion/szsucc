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

	sRtn = GT_Reset();							// 复位运动控制器
	sRtn = GT_LoadConfig("test.cfg");			// 下载控制器配置文件
	sRtn = GT_ClrSts(1, 4);						// 清除1~4轴的轴状态

	for (int i = 1; i <= 4; ++i)
	{
		sRtn = GT_AxisOn(i);					// 使能运动轴0
	}

	GT_ZeroPos(1, 4);							//位置清零

	return sRtn;
}

int Googol::GetState()
{
	if (GetIsOpen())
	{
		GT_GetPrfPos(1, &prfPos, 1, NULL);	//读取1轴规划位置
		strTmp.Format(_T("%.3f"), prfPos);

		GT_GetPrfVel(1, &prfVel, 1, NULL);	//读取1轴规划速度

		GT_GetEncPos(1, &encPos, 1, NULL);	//读取1轴实际位置

		GT_GetEncVel(1, &encVel, 1, NULL);	//读取1轴实际速度
	}

	return 0;
}

int Googol::run(int p_nAxis,double p_dAcc,double p_dDec,int p_nPos,double p_dVel)
{
	GT_SetPrfPos(p_nAxis, 0);		//将轴设为点位模式
	GT_PrfTrap(p_nAxis);			//读取点位运动参数
	TTrapPrm trap;
	GT_GetTrapPrm(p_nAxis, &trap);
	trap.acc = p_dAcc;
	trap.dec = p_dDec;
	trap.smoothTime = 1;		
	GT_SetTrapPrm(p_nAxis, &trap);	//设置点位运动参数
	GT_SetPos(p_nAxis, p_nPos);		//设置轴目标位置
	GT_SetVel(p_nAxis, p_dVel);		//设置轴目标位置

	GT_Update(1 << 0);			//启动轴运动

	return 0;
}
int Googol::Stop()
{
	GT_Stop(1, 4);	//停止运动

	return 0;
}
