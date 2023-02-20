#pragma once

#include "GeneralSolution.h"

//��������㷨��
class DetectionFunction
{
public:
	DetectionFunction();
	~DetectionFunction();

	/*��С���˷�ˮƽ����ֱ����ϣ����������ݴ�С���ͬ�ȴ�С���
	���ֱ�ߣ����㷨���ڽ���ˮƽ�����ֱ�����*/
	int FitLineLeastSquareMethodHorizontal(int* p_parrLineSrc, int nLen, int* p_parrLineDst);
	//��ȡ���ߵײ��㼯��λ�� 
	int ExtractCurveBottomPoints(int* p_parrLineSrc, int p_nLen, int p_nHeight, int p_nAvg, int p_nPos);
	//��ȡ���߶����㼯��λ��
	int ExtractCurveTopPoints(int* p_parrLineSrc, int p_nLen, int p_nHeight, int p_nAvg, int p_nPos);

	//��ȡ����ͼ��
	int ExtractContourImage(Mat& src, std::vector<cv::Point>& p_itc, Mat& Dst);
	//��ȡ���������ص����
	int ExtractContourCount(Mat& src, std::vector<cv::Point>& p_itc, Rect& p_Rect, int& p_pnCount);
};

