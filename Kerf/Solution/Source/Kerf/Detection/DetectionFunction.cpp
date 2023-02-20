#include "stdafx.h"
#include "DetectionFunction.h"

DetectionFunction::DetectionFunction()
{

}

DetectionFunction::~DetectionFunction()
{

}

//计算直线拟合度
float myLinearity(CvSeq* seq)
{
	int i;
	CvPoint2D32f* p;
	float* x = new float[seq->total];
	float* y = new float[seq->total];
	float x_bar = 0.0, y_bar = 0.0;
	float u11 = 0.0, u20 = 0.0, u02 = 0.0;
	float linearity = 0.0;

	for (i = 0; i < seq->total; i++) 
	{
		p = (CvPoint2D32f*)cvGetSeqElem(seq, i);
		x[i] = p->x;
		y[i] = p->y;
	}
	//x_bar, y_bar

	for (i = 0; i < seq->total; i++) 
	{
		x_bar += x[i];
		y_bar += y[i];
	}

	x_bar /= seq->total;
	y_bar /= seq->total;

	for (i = 0; i < seq->total; i++) 
	{
		u11 += ((x[i] - x_bar) * (y[i] - y_bar));
		u20 += pow(x[i] - x_bar, 2.0f);
		u02 += pow(y[i] - y_bar, 2.0f);
	}

	u11 /= seq->total;
	u20 /= seq->total;
	u02 /= seq->total;

	//计算直线度
	linearity = sqrt(4 * pow(u11, 2.0f) + pow(u20 - u02, 2.0f)) / (u20 + u02);
	delete[] x;
	delete[] y;
	return linearity;
}

int DetectionFunction::FitLineLeastSquareMethodHorizontal(int* p_parrLineSrc, int nLen, int* p_parrLineDst)
{
	//Sequence的容器
	CvMemStorage* storage = cvCreateMemStorage(0);
	//三维空间的话，把CV_32FC2改为CV_32FC3、 把CvPoint2D32f 改为CvPoint3D32f
	CvSeq* point_seq = cvCreateSeq(CV_32FC2, sizeof(CvSeq), sizeof(CvPoint2D32f), storage);

	float* line = new float[4];

	
	
	for (int i = 0; i < nLen; i++)
	{
		//向Sequence中追加元素
		cvSeqPush(point_seq, &cvPoint2D32f(i, p_parrLineSrc[i]));
	}

	//求直线度
	// float linearity = 0.0f;
	//linearity = myLinearity(point_seq);

	cvFitLine(point_seq, CV_DIST_L2, 0, 0.01, 0.01, line);

	//fprintf(stdout, "v=(%f,%f),vy/vx=%f,(x,y)=(%f,%f),Linearity=%f/n", line[0], line[1], line[1] / line[0], line[2], line[3], linearity);

	//vx vy x y
	Point A(0, (int)(line[3] - (line[2] * line[1] / line[0])));
	Point B(nLen, (int)((nLen - line[2]) * line[1] / line[0] + line[3]));

	cvClearSeq(point_seq);
	cvReleaseMemStorage(&storage);
	delete[] line;

	return 0;
}

int DetectionFunction::ExtractCurveBottomPoints(int* p_parrLineSrc, int p_nLen, int p_nHeight, int p_nAvg,int p_nPos)
{
	int nDir = 0;//-1、向下、0水平、1向上
	int nLastDir = 0;
	bool bIsBottom = false;
	int* parrPointCounter = new int[p_nHeight];
	memset(parrPointCounter, 0, sizeof(int) * p_nHeight);

	if (p_parrLineSrc[1]> p_parrLineSrc[0])
	{
		nDir = -1;
		nLastDir = -1;
	}
	if (p_parrLineSrc[1] < p_parrLineSrc[0])
	{
		nDir = 1;
		nLastDir = 1;
	}
	if (p_parrLineSrc[1] == p_parrLineSrc[0])
	{
		nDir = 0;
		nLastDir = 0;

		parrPointCounter[p_parrLineSrc[0]] = 2;
	}

	for (int i = 2;i<p_nLen;i++)
	{
		if (p_parrLineSrc[i] > p_parrLineSrc[i-1])
		{
			nDir = -1;
			nLastDir = -1;
		}

		if (p_parrLineSrc[i] == p_parrLineSrc[i - 1])
		{
			nDir = 0;
			nLastDir = 0;

			//取平均数或权重点是为了过滤掉顶部的点
			if (p_parrLineSrc[i] > p_nAvg)
			{
				//暂时当波浪形处理，不考虑平顶的情况
				//parrPointCounter[p_parrLineSrc[i]] ++;
			}
		}

		if (p_parrLineSrc[i] < p_parrLineSrc[i - 1])
		{
			if (nLastDir != 1)
			{
				parrPointCounter[p_parrLineSrc[i-1]]++;
			}

			nDir = 1;
			nLastDir = 1;
			
		}
	}

	int nMax = 0;
	int nKerfUpperEdge = 0;
	//上边缘
	for (int y = p_nHeight; y > 0; y--)
	{
		if (*(parrPointCounter + y) > nMax)
		{
			nMax = *(parrPointCounter + y);
			nKerfUpperEdge = y;
		}
	}

	p_nPos = nKerfUpperEdge;
	delete[] parrPointCounter;
	return 0;
}


int DetectionFunction::ExtractCurveTopPoints(int* p_parrLineSrc, int p_nLen, int p_nHeight, int p_nAvg, int p_nPos)
{
	int nDir = 0;//-1、向下、0水平、1向上
	int nLastDir = 0;
	bool bIsBottom = false;
	int* parrPointCounter = new int[p_nHeight];
	memset(parrPointCounter, 0, sizeof(int) * p_nHeight);

	if (p_parrLineSrc[1] > p_parrLineSrc[0])
	{
		nDir = -1;
		nLastDir = -1;
	}
	if (p_parrLineSrc[1] < p_parrLineSrc[0])
	{
		nDir = 1;
		nLastDir = 1;
	}
	if (p_parrLineSrc[1] == p_parrLineSrc[0])
	{
		nDir = 0;
		nLastDir = 0;

		parrPointCounter[p_parrLineSrc[0]] = 2;
	}

	for (int i = 2; i < p_nLen; i++)
	{
		if (p_parrLineSrc[i] > p_parrLineSrc[i - 1])
		{
			if (nLastDir != -1)
			{
				parrPointCounter[p_parrLineSrc[i - 1]]++;
			}
			nDir = -1;
			nLastDir = -1;
		}

		if (p_parrLineSrc[i] == p_parrLineSrc[i - 1])
		{
			nDir = 0;
			nLastDir = 0;

			//取平均数或权重点是为了过滤掉顶部的点
			if (p_parrLineSrc[i] < p_nAvg)
			{
				//暂时当波浪形处理，不考虑平顶的情况
				//parrPointCounter[p_parrLineSrc[i]] ++;
			}
		}

		if (p_parrLineSrc[i] < p_parrLineSrc[i - 1])
		{
			nDir = 1;
			nLastDir = 1;
		}
	}

	int nMax = 0;
	int nKerfLowerEdge = 0;
	//上边缘
	for (int y = 0; y < p_nHeight; y++)
	{
		if (*(parrPointCounter + y) > nMax)
		{
			nMax = *(parrPointCounter + y);
			nKerfLowerEdge = y;
		}
	}

	p_nPos = nKerfLowerEdge;
	delete[] parrPointCounter;
	return 0;
}

int DetectionFunction::ExtractContourImage(Mat& src, std::vector<cv::Point>& p_itc, Mat& Dst)
{
	//Mat matMark = Mat::zeros(cvSize(src.cols, src.rows), CV_8UC1);
	Mat matMark = Mat::zeros(src.size(), CV_8UC1);
	std::vector<std::vector<cv::Point> >contours;
	contours.push_back(p_itc);

	cv::drawContours(matMark, contours, 0, cv::Scalar(255), CV_FILLED, 8);

	src.copyTo(Dst, matMark);
	return 0;
}

int DetectionFunction::ExtractContourCount(Mat& src, std::vector<cv::Point>& p_itc, Rect& p_Rect, int& p_pnCount)
{
	Mat matMark = Mat::zeros(src.size(), CV_8UC1);
	std::vector<std::vector<cv::Point> >contours;
	contours.push_back(p_itc);

	cv::drawContours(matMark, contours, 0, cv::Scalar(255), CV_FILLED, 8);

	int nCount = 0;
	int nEndX = p_Rect.br().x;
	int nEndY = p_Rect.br().y;
	int nOffset = 0;

	for (int y = p_Rect.y; y < nEndY; ++y)
	{
		nOffset = y * (int)src.step + p_Rect.x;
		for (int x = p_Rect.x; x < nEndX; ++x)
		{
			uchar t_nVal1 = (*(uchar*)(src.data + nOffset));
			if (t_nVal1 > 0)
			{
				++nCount;
			}
			nOffset++;
		}
	}

	p_pnCount = nCount;

	return 0;
}
