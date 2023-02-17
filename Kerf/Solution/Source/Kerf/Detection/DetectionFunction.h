#pragma once

#include "GeneralSolution.h"

//基础检测算法类
class DetectionFunction
{
public:
	DetectionFunction();
	~DetectionFunction();

	/*最小二乘法水平方向直线拟合，按输入数据大小输出同等大小拟合
	后的直线，该算法用于近视水平方向的直线拟合*/
	int FitLineLeastSquareMethodHorizontal(int* p_parrLineSrc, int nLen, int* p_parrLineDst);
	//提取曲线底部点集合
	int ExtractCurveBottomPoints(int* p_parrLineSrc, int p_nLen, int p_nHeight);
};

