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

	//�������ָ��
	if (nullptr == p_pSrcData)
	{
		return (int)enumDetectionResult::DataPointerIsNull;
	}

	//���ͼ��ߴ�
	if (m_nSize <= 0)
	{
		return (int)enumDetectionResult::InputDataError;
	}

	//��������
	Mat matTmp = Mat::zeros(cvSize(p_nWidth, p_nHeigh), CV_8UC1);
	memcpy(matTmp.data, p_pSrcData, m_nSize);

	src.release();
	Rect tRect(0,800,matTmp.cols,400);

	src = matTmp(tRect).clone();

	//������
	DetectionProcess();

	return (int)enumDetectionResult::Done;
}

int CDetection::DetectionProcess()
{
	//���б�Ե
	Mat t_matBinaryScharr;
	//���۶�ֵ��
	Mat matBinarization;

	Mat matBinarization1;

	Mat matBinarization2;

	Mat matBinarizationDst;

	//ͼ���ֵ�����ݶȴ���
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
	
			

		//�պ������ڲ��ڵ�
		Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
		morphologyEx(matBinarization, matBinarization, MORPH_CLOSE, element);
		////����Сȱ��
		Mat element1 = getStructuringElement(MORPH_RECT, Size(3, 3));
		morphologyEx(matBinarization, matBinarization, MORPH_OPEN, element1);

		threshold(matBinarization, matBinarizationDst, 100, 255, CV_THRESH_BINARY_INV);
	}
	
	//��ȡ�м�λ�õĵ�������

	{
		Mat matTmp = matBinarizationDst.clone();
		std::vector<std::vector<cv::Point> >contours;
		//Mat Src(t_matThreshold, true);
		findContours(matTmp, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

		////��������,ȥ��С����С�ߴ������
		std::vector<std::vector<cv::Point> >::iterator itc = contours.begin();
		int tnIndex = 0;
		while (itc != contours.end())
		{
			//����С����
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

//�����Եλ�� 
int CDetection::ExtractKnifeEdge(Mat& src, Rect p_Rect)
{
	//���±�Ե��ɢ�㼯��
	int* parrUpPoints = new int[src.cols];
	int* parrDownPoints = new int[src.cols];
	//���±�Ե��ɢ��ͳ�Ƽ���
	int* parrUp = new int[src.rows];
	int* parrDown = new int[src.rows];

	memset(parrUpPoints, 0, sizeof(int) * src.cols);
	memset(parrDownPoints, 0, sizeof(int) * src.cols);
	memset(parrUp, 0, sizeof(int) * src.rows);
	memset(parrDown, 0, sizeof(int) * src.rows);

	int nHeightCenter = p_Rect.y + p_Rect.height / 2;
	int nHeightCenterOffset = nHeightCenter * (int)src.step;
	//��ȡ�������±�Ե
	int nStep = 1;

	//������ߵ�
	int nUpMin = src.rows;
	//������͵�
	int nUpMax = 0;
	//������ߵ�
	int nDownMin = src.rows;
	//������͵�
	int nDownMax = 0;

	//�����ϱ�Ե
	int nKerfUpperEdge = 0;
	//�����±�Ե
	int nKerfLowerEdge = 0;

	int nAvgUp = 0, nAvgDown = 0;
	int nCount = 0;
	int nOffset = 0;
	for (int x = 0; x < src.cols; x += nStep)
	{
		//���ϱ�Ե
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

		//���±�Ե
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

	//������ɢ��ֲ�ͳ�Ƽ������±�Ե
	{
		int nMax = 0;
		//�ϱ�Ե
		for (int y = nHeightCenter; y > -1; y--)
		{
			if (parrUp[y] > nMax)
			{
				nMax = parrUp[y];
				nKerfUpperEdge = y;
			}
		}

		//�±�Ե
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

	//��ϵ������±�Ե
	{
		DetectionFunction tDetectionFunction;
		tDetectionFunction.FitLineLeastSquareMethodHorizontal(parrUpPoints, src.cols, parrUpPoints);
		tDetectionFunction.FitLineLeastSquareMethodHorizontal(parrDownPoints, src.cols, parrDownPoints);

		tDetectionFunction.ExtractCurveBottomPoints(parrUpPoints, src.cols, src.rows, nAvgUp, nKerfUpperEdge);
		tDetectionFunction.ExtractCurveTopPoints(parrDownPoints, src.cols, src.rows, nAvgDown, nKerfLowerEdge);
	}
	
	//��ȡ����ȱ��
	ExtractKerfDefects(src, nKerfUpperEdge, nKerfLowerEdge);

	delete[] parrUpPoints;
	delete[] parrDownPoints;
	delete[] parrUp;
	delete[] parrDown;
	return 0;
}

//��ȡ����ȱ��
int CDetection::ExtractKerfDefects(Mat& src,int p_nTop,int p_nBottom)
{
	Mat tMark = src.clone();
	Rect tRect;
	tRect.x = 0;
	tRect.y = p_nTop;
	tRect.width = src.cols;
	tRect.height = p_nBottom - p_nTop;

	//��ȡ������������֮���ȱ��
	{
		cv::rectangle(tMark, tRect, cv::Scalar(0), CV_FILLED, 8, 0);
	}

	//��ȡ������������֮�ڵ�ȱ��
	{
		Mat matBinarization;
		threshold(src, matBinarization, 100, 255, CV_THRESH_BINARY_INV);

		tRect.y = 0;
		tRect.height = p_nTop;
		cv::rectangle(matBinarization, tRect, cv::Scalar(0), CV_FILLED, 8, 0);

		tRect.y = p_nBottom;
		tRect.height = src.rows - p_nBottom;
		cv::rectangle(matBinarization, tRect, cv::Scalar(0), CV_FILLED, 8, 0);

		//�����ͼ����Markͼ�����

	}

	//����ͼ����ȱ�����ֵ����ȡ������


	return 0;
}