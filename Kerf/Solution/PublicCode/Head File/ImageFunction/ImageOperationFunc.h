#pragma once
#pragma warning(disable:4996)

#include "opencv2\highgui\highgui.hpp"
#include "opencv.hpp"
#include "cxcore.hpp"
#include "opencv2\core\core.hpp"
#include "cxcore.h"
#include "opencv2/core/core_c.h"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/ml/ml.hpp"

using namespace cv;

//图像翻转方式枚举
typedef enum
{
	ReversalModeHorizontal, // 水平翻转  
	ReversalModeVertical    // 垂直翻转  
}ReversalMode;

// 图像翻转(镜像)  
VOID ImageReversal(IN OUT IplImage **p_iplImage, IN ReversalMode mode);

//转换iplimage到bmp图像
void iplImageToBmp(IN IplImage *ipl, IN int nBpp, OUT byte* p_pbyteBmp, OUT int& p_nBmpSize);

//提取二值图
int Binarization(Mat p_mat, int p_nBinarizationThreshold, Mat* p_matDst);

//16位灰度图均值，以5*5矩阵进行图像均值处理
int ImageMatrixAvg16(Mat &src);

//16位灰度图均值，以3*3矩阵进行图像均值处理
int ImageMatrixAvg163X3(Mat& src, int p_nStep = 1);

//16位灰度图均值，以矩阵形式进行图像均值处理
//p_nStep:0 3*3,2 5*5 表示以当前点向x、y方向延伸的步长
int ImageMatrixAvg16Step(Mat& src, int p_nStep = 1);

//判断缺陷面积是否复合
int IsGreaterMinimumBrightness(Mat* p_src, Mat& p_Make, std::vector<std::vector<cv::Point> >::iterator itc
	, int m_nMinBrightness, int m_nMaxGrayscale, int m_nMinBrightnessPixelsTotal, int m_nDefectAreaMin, int m_nDefectAreaMax);

//判断缺陷是否符合条件
int DefectRecognition(Mat* p_mat, Mat* p_matBinaryvalue, const int p_nOffsetX, const int p_nOffsetY, int p_nMin, int p_nMax);

