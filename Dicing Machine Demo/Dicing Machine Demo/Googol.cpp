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
	GT_Stop(0xFF, 0xFF);		//急停所有轴
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

	sRtn = GT_Reset();							// 复位运动控制器
	sRtn = GT_LoadConfig("test.cfg");			// 下载控制器配置文件
	sRtn = GT_ClrSts(1, 4);						// 清除1~4轴的轴状态

	for (int i = 1; i <= 4; ++i)
	{
		GT_StepDir(i);							// 脉冲加方向模式
		//GT_StepPulse(i);						// CW/CCW 模式
		sRtn = GT_AxisOn(i);					// 使能运动轴0
	}

	return sRtn;
}

int Googol::GetState(int nAxis, double p_dPrfPos, double p_dPrfVel, double p_dPos, double p_dVel)
{
	if (GetIsOpen())
	{
		GT_GetPrfPos(nAxis, &p_dPrfPos, 1, NULL);	//读取1轴规划位置

		GT_GetPrfVel(nAxis, &p_dPrfVel, 1, NULL);	//读取1轴规划速度
		
		GT_GetEncPos(nAxis, &p_dPos, 1, NULL);	//读取1轴实际位置

		GT_GetEncVel(nAxis, &p_dVel, 1, NULL);	//读取1轴实际速度
	}

	return 0;
}

int Googol::JogMove(int p_nAxis, double p_dAcc, double p_dDec, double p_dVel)
{
	GT_ZeroPos(p_nAxis, 4);							//位置清零

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
int Googol::StopAll()
{
	//GT_Stop(mask, option): mask-按位取轴，option-按位取轴的停止方式，1-急停、0-平滑停
	
	//GT_Stop(0xFF, 0);			//平滑停止运动
	GT_Stop(0xFF, 0xFF);		//急停所有轴
	return 0;
}

int Googol::StopAxis(int p_nAxis)
{
	GT_Stop(1 << (p_nAxis - 1), 1 << (p_nAxis - 1));	//停止运动
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
	sRtn = GT_LmtsOn(gAxis); //如果没有接限位开关则需要把限位取消
	sRtn = GT_LmtSns(3); //限位为低电平触发（按实际情况设置）
	sRtn = GT_EncSns(1); //编码器方向设置（按实际编码器设置，保证规划位置与实际位置方向一致）
	sRtn = GT_ClrSts(gAxis);
	sRtn = GT_ZeroPos(gAxis);
	//sRtn = GT_AxisOn(gAxis); //必须使能轴
	//设置 Smart Home 回原点参数
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
	
	sRtn = GT_GoHome(1, &tHomePrm); //启动 Smart Home 回原点
	do
	{
		sRtn = GT_GetHomeStatus(1, &tHomeSts); //获取回原点状态
	} while (tHomeSts.run); //等待搜索原点停止

	return 0;
}