#pragma once
#pragma warning(disable:4996)
#include "stdafx.h"

#include "opencv2\highgui\highgui.hpp"
#include "opencv.hpp"
#include "cxcore.hpp"
#include "opencv2\core\core.hpp"
#include "cxcore.h"
#include "opencv2/core/core_c.h"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/ml/ml.hpp"

#include<deque>

using namespace std;
using namespace cv;

typedef struct _GrayRings
{
	//内圆半径
	int InsideCirclReadius;
	//外圆半径
	int OuterCircleReadius;
	//平均灰度
	int AvgGray;
	//像素个数
	int PixelCount;
	//中心点
	CvPoint Center;
	//圆环实体灰度图
	Mat RingsGrayImage;
	//高亮面积
	int HighLightArea;

	_GrayRings()
	{
		InsideCirclReadius = 0;
		OuterCircleReadius = 0;
		AvgGray = 0;
		PixelCount = 0;
		HighLightArea = 0;

		Center.x = 0;
		Center.y = 0;
	}
}GrayRings;



class RecognitionFunction
{
public:
	RecognitionFunction();
	~RecognitionFunction();

	//计算图像中多个中心圆环各自的灰度
	int GetMultiRingsGray(Mat p_matSrc, GrayRings** p_arrGrayRings, int p_RingsCount, Mat* p_pmatDebug);

	//计算图像内正方型内切圆以外部分亮度，并返回内切圆图像
	static int GetAvgLight(IN Mat p_mRecognitionImage, OUT Mat* p_pCircleImage);

	//计算两点间距离
	static int CalculateDistance2Point(Point p_pointA,Point p_pointB,Point& p_pointOutput);

	//生成向量能量曲线
	static int BuildEnergyCurve(Mat p_matDataSrc, Mat& p_matDst, Mat& p_matDstDisplay, Scalar p_colorDisplay, deque<Point>& lines);
};

