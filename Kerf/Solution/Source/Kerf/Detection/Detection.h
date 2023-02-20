#pragma once

#include "GeneralSolution.h"

class CDetection
{
public:
	CDetection();
	~CDetection();

	int KerfDetection(byte* p_pSrcData, int p_nWidth, int p_nHeigh);
	int DetectionProcess();
	int ExtractKnifeEdge(Mat& p_matBinarizationDst, Rect p_Rect);
	int ExtractKerfDefects(Mat& src, int p_nTop, int p_nBottom);


private:
	//ԭʼͼ�񣬴˴��迼���Ƿ񿪹̶��ռ䡣
	Mat src;
	int m_nSize = 0;
};

