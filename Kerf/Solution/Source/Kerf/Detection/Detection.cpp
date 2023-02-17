#include "stdafx.h"
#include "Detection.h"
#include "DetectionFunction.h"

CDetection::CDetection()
{

}

CDetection::~CDetection()
{

}

int CDetection::KerfDetection(byte* p_pSrcData, int p_nWidth, int p_nHeigh)
{
	m_nSize = p_nWidth * p_nHeigh;

	//检查数据指针
	if (nullptr == p_pSrcData)
	{
		return (int)enumDetectionResult::DataPointerIsNull;
	}

	//检查图像尺寸
	if (m_nSize <= 0)
	{
		return (int)enumDetectionResult::InputDataError;
	}

	//拷贝数据
	Mat matTmp = Mat::zeros(cvSize(p_nWidth, p_nHeigh), CV_8UC1);
	memcpy(matTmp.data, p_pSrcData, m_nSize);

	src.release();
	Rect tRect(0,800,matTmp.cols,400);

	src = matTmp(tRect).clone();

	//检测过程
	DetectionProcess();

	return (int)enumDetectionResult::Done;
}

int CDetection::DetectionProcess()
{
	//刀刃边缘
	Mat t_matBinaryScharr;
	//刀痕二值化
	Mat matBinarization;

	Mat matBinarization1;

	Mat matBinarization2;

	Mat matBinarizationDst;

	//图像二值化、梯度处理
	{
		Mat grad_x, grad_y;
		Mat abs_grad_x, abs_grad_y;

		GaussianBlur(src, src, Size(5, 5), 0, 0, BORDER_DEFAULT);
		cv::Scharr(src, grad_x, CV_32F, 1, 0, 1, 1, BORDER_DEFAULT);
		convertScaleAbs(grad_x, abs_grad_x);
		cv::Scharr(src, grad_y, CV_32F, 0, 1, 1, 1, BORDER_DEFAULT);
		convertScaleAbs(grad_y, abs_grad_y);
		addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, t_matBinaryScharr);
		
		threshold(src, matBinarization, 100, 255, CV_THRESH_BINARY);
		adaptiveThreshold(src, matBinarization1, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 11, 2);
		adaptiveThreshold(src, matBinarization2, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 2);
	
			

		//闭合轮廓内部黑点
		Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
		morphologyEx(matBinarization, matBinarization, MORPH_CLOSE, element);
		////过滤小缺陷
		Mat element1 = getStructuringElement(MORPH_RECT, Size(3, 3));
		morphologyEx(matBinarization, matBinarization, MORPH_OPEN, element1);

		threshold(matBinarization, matBinarizationDst, 100, 255, CV_THRESH_BINARY_INV);
	}
	
	//提取中间位置的刀痕区域

	{
		Mat matTmp = matBinarizationDst.clone();
		std::vector<std::vector<cv::Point> >contours;
		//Mat Src(t_matThreshold, true);
		findContours(matTmp, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

		////轮廓过滤,去掉小于最小尺寸的轮廓
		std::vector<std::vector<cv::Point> >::iterator itc = contours.begin();
		int tnIndex = 0;
		while (itc != contours.end())
		{
			//按大小分离
			if (itc->size()>matBinarizationDst.cols)
			{
				Mat dst;
				Rect rect = boundingRect(*itc);
				DetectionFunction tDetectionFunction;
				tDetectionFunction.ExtractContourImage(matBinarizationDst, contours[tnIndex], dst);
				ExtractKnifeEdge(dst, rect);
				break;
			}

			itc++;
			tnIndex++;
		}
	}

	return 0;
}

//计算边缘位置 
int CDetection::ExtractKnifeEdge(Mat& src, Rect p_Rect)
{
	//上下边缘离散点集合
	int* parrUpPoints = new int[src.cols];
	int* parrDownPoints = new int[src.cols];
	//上下边缘离散点统计集合
	int* parrUp = new int[src.rows];
	int* parrDown = new int[src.rows];

	memset(parrUpPoints, 0, sizeof(int) * src.cols);
	memset(parrDownPoints, 0, sizeof(int) * src.cols);
	memset(parrUp, 0, sizeof(int) * src.rows);
	memset(parrDown, 0, sizeof(int) * src.rows);

	int nHeightCenter = p_Rect.y + p_Rect.height / 2;
	int nHeightCenterOffset = nHeightCenter * (int)src.step;
	//提取刀痕上下边缘
	int nStep = 1;

	//上沿最高点
	int nUpMin = src.rows;
	//上沿最低点
	int nUpMax = 0;
	//下沿最高点
	int nDownMin = src.rows;
	//下沿最低点
	int nDownMax = 0;

	//刀痕上边缘
	int nKerfUpperEdge = 0;
	//刀痕下边缘
	int nKerfLowerEdge = 0;

	int nAvgUp = 0, nAvgDown = 0;
	int nCount = 0;
	int nOffset = 0;
	for (int x = 0; x < src.cols; x += nStep)
	{
		//找上边缘
		nOffset = nHeightCenterOffset + x;
		for (int y = nHeightCenter; y > -1; y--)
		{
			uchar t_nVal1 = (*(uchar*)(src.data + nOffset));
			if (0 == t_nVal1)
			{
				nAvgUp += y;
				nUpMin = nUpMin < y ? nUpMin : y;
				nUpMax = nUpMax > y ? nUpMax : y;

				parrUp[y]++;

				parrUpPoints[x] = y;
				break;
			}
			nOffset -= (int)src.step;
		}

		//找下边缘
		nOffset = nHeightCenterOffset + x;
		for (int y = nHeightCenter; y < src.rows; y++)
		{
			uchar t_nVal1 = (*(uchar*)(src.data + nOffset));
			if (0 == t_nVal1)
			{
				nAvgDown += y;
				nDownMin = nDownMin < y ? nDownMin : y;
				nDownMax = nDownMax > y ? nDownMax : y;

				parrDown[y]++;

				parrDownPoints[x] = y;
				break;
			}
			nOffset += (int)src.step;
		}


		nCount++;
	}

	if (nCount>0)
	{
		nAvgUp = nAvgUp / nCount;
		nAvgDown = nAvgDown / nCount;
	}
	else
	{
		nAvgUp = 0;
		nAvgDown = src.rows - 1;
	}

	//跟据离散点分布统计计算上下边缘
	{
		int nMax = 0;
		//上边缘
		for (int y = nHeightCenter; y > -1; y--)
		{
			if (parrUp[y] > nMax)
			{
				nMax = parrUp[y];
				nKerfUpperEdge = y;
			}
		}

		//下边缘
		nMax = 0;
		for (int y = nHeightCenter; y < src.rows; y++)
		{
			if (parrDown[y] > nMax)
			{
				nMax = parrDown[y];
				nKerfLowerEdge = y;
			}
		}
	}

	//拟合刀痕上下边缘
	{
		DetectionFunction tDetectionFunction;
		tDetectionFunction.FitLineLeastSquareMethodHorizontal(parrUpPoints, src.cols, parrUpPoints);
		tDetectionFunction.FitLineLeastSquareMethodHorizontal(parrDownPoints, src.cols, parrDownPoints);

		tDetectionFunction.ExtractCurveBottomPoints(parrUpPoints, src.cols, src.rows, nAvgUp, nKerfUpperEdge);
		tDetectionFunction.ExtractCurveTopPoints(parrDownPoints, src.cols, src.rows, nAvgDown, nKerfLowerEdge);
	}
	
	//提取刀痕缺陷
	ExtractKerfDefects(src, nKerfUpperEdge, nKerfLowerEdge);

	delete[] parrUpPoints;
	delete[] parrDownPoints;
	delete[] parrUp;
	delete[] parrDown;
	return 0;
}

//提取刀痕缺陷
int CDetection::ExtractKerfDefects(Mat& src,int p_nTop,int p_nBottom)
{
	Mat tMark = src.clone();
	Rect tRect;
	tRect.x = 0;
	tRect.y = p_nTop;
	tRect.width = src.cols;
	tRect.height = p_nBottom - p_nTop;

	//提取刀痕上下两端之外的缺陷
	{
		cv::rectangle(tMark, tRect, cv::Scalar(0), CV_FILLED, 8, 0);
	}

	//提取刀痕上下两端之内的缺陷
	{
		Mat matBinarization;
		threshold(src, matBinarization, 100, 255, CV_THRESH_BINARY_INV);

		tRect.y = 0;
		tRect.height = p_nTop;
		cv::rectangle(matBinarization, tRect, cv::Scalar(0), CV_FILLED, 8, 0);

		tRect.y = p_nBottom;
		tRect.height = src.rows - p_nBottom;
		cv::rectangle(matBinarization, tRect, cv::Scalar(0), CV_FILLED, 8, 0);

		//将结果图像与Mark图像各并

	}

	//查找图像中缺陷最大值：宽度、面积等


	return 0;
}