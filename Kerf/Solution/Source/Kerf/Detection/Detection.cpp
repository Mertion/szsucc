#include "stdafx.h"
#include "Detection.h"

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
				Rect rect = boundingRect(*itc);
				ExtractKnifeEdge(matBinarizationDst, rect);
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
	int nHeightCenter = p_Rect.y + p_Rect.height / 2;
	int nHeightCenterOffset = nHeightCenter * src.step;
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
				break;
			}
			nOffset -= src.step;
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
				break;
			}
			nOffset += src.step;
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

	nKerfUpperEdge = nUpMax;
	nKerfLowerEdge = nDownMin;


	return 0;
}