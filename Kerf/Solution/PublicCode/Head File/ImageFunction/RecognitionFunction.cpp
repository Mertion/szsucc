#include "stdafx.h"
#include "RecognitionFunction.h"


RecognitionFunction::RecognitionFunction()
{
}


RecognitionFunction::~RecognitionFunction()
{
}

//************************************
// Method:    GetMultiRingsGray
// FullName:  RecognitionFunction::GetMultiRingsGray
// Access:    public 
// Returns:   int Ԥ��
// Qualifier:
// Parameter: Mat p_matSrc	����Դͼ��
// Parameter: GrayRings * * p_arrGrayRings	Բ������
// Parameter: int p_RingsCount	Բ������
//************************************
int RecognitionFunction::GetMultiRingsGray(Mat p_matSrc, GrayRings** p_arrGrayRings, int p_RingsCount, Mat* p_pmatDebug)
{
	//���ص㵽Բ��X�������
	int t_nDistanceX = 0;
	//���ص㵽Բ��Y�������
	int t_nDistanceY = 0;


	GrayRings* t_GrayRings = NULL;

	//�������
	for (int i = 0; i < p_RingsCount; i++)
	{
		t_GrayRings = p_arrGrayRings[i];
		t_GrayRings->AvgGray = 0;
		t_GrayRings->PixelCount = 0;
	}

	//�����Բ�������н��ػҶ��ܺ�
	for (int i = 0; i < p_matSrc.cols; i++)
	{
		//ˮƽ����������Ϊ׼������ȡһ������������㣬��Ϊ���㵽��ͼ������Բ�ġ�
		for (int j = 0; j < p_matSrc.rows; j++)
		{
			for (int k = 0; k < p_RingsCount; k++)
			{
				t_GrayRings = p_arrGrayRings[k];

				t_nDistanceX = abs(i - t_GrayRings->Center.x);
				t_nDistanceY = abs(j - t_GrayRings->Center.y);

				int t_nX = (t_nDistanceX * t_nDistanceX + t_nDistanceY * t_nDistanceY);
				if (((t_GrayRings->OuterCircleReadius * t_GrayRings->OuterCircleReadius) > t_nX)
					&& (t_nX > (t_GrayRings->InsideCirclReadius * t_GrayRings->InsideCirclReadius))
					)
				{
					t_GrayRings->AvgGray += p_matSrc.at<uchar>(j, i);
					t_GrayRings->PixelCount++;
					p_pmatDebug->at<uchar>(j, i) = p_matSrc.at<uchar>(j, i);

					int x = i - (t_GrayRings->Center.x - t_GrayRings->OuterCircleReadius);
					int y = j - (t_GrayRings->Center.y - t_GrayRings->OuterCircleReadius);
					t_GrayRings->RingsGrayImage.at<uchar>(y,x) = p_matSrc.at<uchar>(j, i);
				}
			}
			
		}
	}

	//����Ҷ�ƽ��ֵ
	for (int i = 0; i < p_RingsCount; i++)
	{
		t_GrayRings = p_arrGrayRings[i];
		if (0 != t_GrayRings->PixelCount)
		{
			t_GrayRings->AvgGray /= t_GrayRings->PixelCount;
		}
	}

	return 0;
}

int RecognitionFunction::GetAvgLight(IN Mat p_mRecognitionImage, OUT Mat* p_pCircleImage)
{
	//ƽ������
	int t_nAvgLight = 0;
	//�������ص�������
	int t_nSumLight = 0;
	//����������ص����
	int t_nPixelCount = 0;
	//����Բ�뾶
	int t_nRadius = (p_mRecognitionImage.cols / 2);
	//����Բ�뾶ƽ��
	int t_nRadius2 = t_nRadius * t_nRadius;
	//���ص㵽Բ��X�������
	int t_nDistanceX = 0;
	//���ص㵽Բ��Y�������
	int t_nDistanceY = 0;

	p_pCircleImage->release();
	*p_pCircleImage = Mat::zeros(p_mRecognitionImage.size(), CV_8UC1);

	for (int i = 0; i < p_mRecognitionImage.cols; i++)
	{
		t_nDistanceX = abs(i - t_nRadius);
		for (int j = 0; j < p_mRecognitionImage.rows; j++)
		{
			t_nDistanceY = abs(j - t_nRadius);
			if ((t_nDistanceX * t_nDistanceX + t_nDistanceY * t_nDistanceY) > t_nRadius2)
			{
				t_nSumLight += p_mRecognitionImage.at<uchar>(i, j);
				t_nPixelCount++;
			}
			else
			{
				p_pCircleImage->at<uchar>(i, j) = p_mRecognitionImage.at<uchar>(i, j);
			}
		}
	}
	t_nAvgLight = t_nSumLight / t_nPixelCount;

	return t_nAvgLight;
}

int RecognitionFunction::CalculateDistance2Point(Point p_pointA, Point p_pointB, Point& p_pointOutput)
{
	int x = 0;
	int y = 0;
	int Distance = 0;
	p_pointOutput = p_pointB - p_pointA;

	x = p_pointOutput.x;
	y = p_pointOutput.y;

	Distance = (int)sqrt(x * x + y * y);
	return Distance;
}

int RecognitionFunction::BuildEnergyCurve(Mat p_matDataSrc, Mat& p_matDst, Mat& p_matDstDisplay, Scalar p_colorDisplay, deque<Point>& lines)
{
	for (int i = 0; i < lines.size(); i++)
	{
		Point t_Point = lines.at(i);
		//draw_img.at<Vec3b>(lines[i][j]) = Vec3b(p_colorDisplay[0], p_colorDisplay[1], p_colorDisplay[2]);
		int t_nVal = p_matDataSrc.at<ushort>(t_Point.y, t_Point.x);
		//t_nVal /= 100;
		//t_nVal *= 30;
		//t_nVal /= 255;
		p_matDst.at<uchar>(t_nVal, t_Point.x) = 255;
		p_matDstDisplay.at<Vec3b>(t_nVal, t_Point.x) = Vec3b((uchar)p_colorDisplay[0], (uchar)p_colorDisplay[1], (uchar)p_colorDisplay[2]);
	}
	return 0;
}
