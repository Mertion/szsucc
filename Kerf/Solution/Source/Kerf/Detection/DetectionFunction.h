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
	//提取曲线底部点集合位置 
	int ExtractCurveBottomPoints(int* p_parrLineSrc, int p_nLen, int p_nHeight, int p_nAvg, int p_nPos);
	//提取曲线顶部点集合位置
	int ExtractCurveTopPoints(int* p_parrLineSrc, int p_nLen, int p_nHeight, int p_nAvg, int p_nPos);

	//提取轮廓图像
	int ExtractContourImage(Mat& src, std::vector<cv::Point>& p_itc, Mat& Dst);
	//提取轮廓内像素点个数
	int ExtractContourCount(Mat& src, std::vector<cv::Point>& p_itc, Rect& p_Rect, int& p_pnCount);
};

