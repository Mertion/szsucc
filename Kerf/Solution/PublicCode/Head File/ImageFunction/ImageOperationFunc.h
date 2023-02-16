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

//ͼ��ת��ʽö��
typedef enum
{
	ReversalModeHorizontal, // ˮƽ��ת  
	ReversalModeVertical    // ��ֱ��ת  
}ReversalMode;

// ͼ��ת(����)  
VOID ImageReversal(IN OUT IplImage **p_iplImage, IN ReversalMode mode);

//ת��iplimage��bmpͼ��
void iplImageToBmp(IN IplImage *ipl, IN int nBpp, OUT byte* p_pbyteBmp, OUT int& p_nBmpSize);

//��ȡ��ֵͼ
int Binarization(Mat p_mat, int p_nBinarizationThreshold, Mat* p_matDst);

//16λ�Ҷ�ͼ��ֵ����5*5�������ͼ���ֵ����
int ImageMatrixAvg16(Mat &src);

//16λ�Ҷ�ͼ��ֵ����3*3�������ͼ���ֵ����
int ImageMatrixAvg163X3(Mat& src, int p_nStep = 1);

//16λ�Ҷ�ͼ��ֵ���Ծ�����ʽ����ͼ���ֵ����
//p_nStep:0 3*3,2 5*5 ��ʾ�Ե�ǰ����x��y��������Ĳ���
int ImageMatrixAvg16Step(Mat& src, int p_nStep = 1);

//�ж�ȱ������Ƿ񸴺�
int IsGreaterMinimumBrightness(Mat* p_src, Mat& p_Make, std::vector<std::vector<cv::Point> >::iterator itc
	, int m_nMinBrightness, int m_nMaxGrayscale, int m_nMinBrightnessPixelsTotal, int m_nDefectAreaMin, int m_nDefectAreaMax);

//�ж�ȱ���Ƿ��������
int DefectRecognition(Mat* p_mat, Mat* p_matBinaryvalue, const int p_nOffsetX, const int p_nOffsetY, int p_nMin, int p_nMax);

