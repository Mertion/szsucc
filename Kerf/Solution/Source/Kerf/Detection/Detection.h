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
	//原始图像，此处需考虑是否开固定空间。
	Mat src;
	int m_nSize = 0;
};

