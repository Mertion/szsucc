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
	//��ȡ���ߵײ��㼯��
	int ExtractCurveBottomPoints(int* p_parrLineSrc, int p_nLen, int p_nHeight);
};

