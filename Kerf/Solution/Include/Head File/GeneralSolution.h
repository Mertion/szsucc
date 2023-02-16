#pragma once
#pragma warning(disable:4996)

#include "stdafx.h"
#include "IFMainControl.h"

#include "opencv2\highgui\highgui.hpp"
#include "opencv.hpp"
#include "cxcore.hpp"
#include "opencv2\core\core.hpp"
#include "cxcore.h"
#include "opencv2/core/core_c.h"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/ml/ml.hpp"

//opencv 2.4.13.7�ڱ���ʱ������vfw32�⣬���Դ˴�Ҳ�������ô˿⣬�������ʱ�ᱨ��
#pragma comment(lib, "vfw32")
#ifdef DEBUG
#pragma comment(lib,"IlmImfd") 
#pragma comment(lib,"libjasperd") 
#pragma comment(lib,"libjpegd") 
#pragma comment(lib,"libpngd") 
#pragma comment(lib,"libtiffd") 
#pragma comment(lib,"opencv_calib3d2413d") 
#pragma comment(lib,"opencv_contrib2413d") 
#pragma comment(lib,"opencv_core2413d") 
#pragma comment(lib,"opencv_features2d2413d") 
#pragma comment(lib,"opencv_flann2413d") 
#pragma comment(lib,"opencv_gpu2413d") 
#pragma comment(lib,"opencv_highgui2413d") 
#pragma comment(lib,"opencv_imgproc2413d") 
#pragma comment(lib,"opencv_legacy2413d") 
#pragma comment(lib,"opencv_ml2413d") 
#pragma comment(lib,"opencv_nonfree2413d") 
#pragma comment(lib,"opencv_objdetect2413d") 
#pragma comment(lib,"opencv_ocl2413d") 
#pragma comment(lib,"opencv_photo2413d") 
#pragma comment(lib,"opencv_stitching2413d") 
#pragma comment(lib,"opencv_superres2413d") 
#pragma comment(lib,"opencv_ts2413d") 
#pragma comment(lib,"opencv_video2413d") 
#pragma comment(lib,"opencv_videostab2413d") 
#pragma comment(lib,"zlibd") 

//��Ϊopencv���ɵ�world�����ݲ�ȫ������Ҫ��������������������ݣ����Դ˴�����world��ģʽ
//#pragma comment(lib,"opencv_world2413d") 

#else

#pragma comment(lib,"IlmImf") 
#pragma comment(lib,"libjasper") 
#pragma comment(lib,"libjpeg") 
#pragma comment(lib,"libpng") 
#pragma comment(lib,"libtiff") 
#pragma comment(lib,"opencv_calib3d2413") 
#pragma comment(lib,"opencv_contrib2413") 
#pragma comment(lib,"opencv_core2413") 
#pragma comment(lib,"opencv_features2d2413") 
#pragma comment(lib,"opencv_flann2413") 
#pragma comment(lib,"opencv_gpu2413") 
#pragma comment(lib,"opencv_highgui2413") 
#pragma comment(lib,"opencv_imgproc2413") 
#pragma comment(lib,"opencv_legacy2413") 
#pragma comment(lib,"opencv_ml2413") 
#pragma comment(lib,"opencv_nonfree2413") 
#pragma comment(lib,"opencv_objdetect2413") 
#pragma comment(lib,"opencv_ocl2413") 
#pragma comment(lib,"opencv_photo2413") 
#pragma comment(lib,"opencv_stitching2413") 
#pragma comment(lib,"opencv_superres2413") 
#pragma comment(lib,"opencv_ts2413") 
#pragma comment(lib,"opencv_video2413") 
#pragma comment(lib,"opencv_videostab2413") 
#pragma comment(lib,"zlib") 

//��Ϊopencv���ɵ�world�����ݲ�ȫ������Ҫ��������������������ݣ����Դ˴�����world��ģʽ
//#pragma comment(lib,"opencv_world2413") 
#endif // DEBUG

#include "./MainFramework/Recognition/Detection/CtrlPoint.h"

using namespace std;
using namespace cv;

////ģ�ⷽʽ 0-�豸���У�1-ͼ���ļ�ģʽ��2-�豸�ֶ�ģʽ
//#define SIMULATIONMODE 0;

//����ģʽ
//#define DEBUG_MODE 1
//���Զ��μ����ÿ��ȱ�ݿ�Ĺ���ͼ��
//#define DEBUG_SECOND 1
//��ʶ��������
#define DEBUG_ANGLE 1
//���Դ���ģʽ
#define DEBUGCODE_MODE 1
//���߳�ģʽ
#define MULTITHREADMODE 1
//ģ�����
#define DEBUG_TEMPLATE 1
//У������
//#define DEBUG_CORRECTION 1
//��ƽ���ֵ
//#define DEBUG_BASEPLANEDIFFERENCE1 1
//#define DEBUG_BASEPLANEDIFFERENCE2 1

//#define DEBUG_BASEPHorizontalEdge 1
//��������ģ�����
#define DEBUG_ARBITRARYCURVE 1


//����������
#define DEBUG_JLHACCEPTANCE 0

//�������
#define CAMERA_COUNTER 2
//����ɼ�ͼ����
#define MAX_LINECOUNTER 10000
//����ɼ�ͼ����
#define CAMERA_WIDTH 4096
//����ɼ�ͼ��߶�
#define CAMERA_HIGH 30000
//��ȡͼ�����ݿ��
#define DEFULTIMAGE_WIDTH 3000
//��ȡͼ�����ݸ߶�
#define DEFULTIMAGE_HIGH 3000
//���������
//#define DETECTION_OBJS 6
//#define DETECTION_OBJS 1
#define DETECTION_OBJS 0
//ͼ��λ�������
#define MAXPOSITIONNUMBER 12

//PIԲ����
const float const_PI = (float)3.1415926;
//�뾶����
const int const_nRadiusEx = 20;

extern const int const_nStep_x;
//΢������ƫ����
extern const int const_nZeroLineOffset;
//y�������ݹ�����
extern const int const_nDifScale;
//��������ƫ����
extern const int const_nDataLineOffset;
//ϵͳ����ö��
enum ENUM_WARNING
{
	//�����ʧ��
	ENUM_WARNING_CAMERA_OPENFAILED = 50,
	//��ȡ�������ʧ��
	ENUM_WARNING_CAMERA_GETCONFIGFAILED = 51,
	//�ر����ʧ��
	ENUM_WARNING_CAMERA_CLOSEFAILED = 52,
	//��������ͼ��ߴ粻��ȷ
	ENUM_WARNING_CAMERA_IMAGESIZEINCORRECT = 53,
	//������У���ļ���ȡ����
	ENUM_ERRORCODE_CAMERACORRECTION_READFAILED = 55,
	//������У���ļ���ʧ��
	ENUM_ERRORCODE_CAMERACORRECTION_OPENFAILED = 56,
	//��ȡģ���ļ�ʧ��
	ENUM_ERRORCODE_TEMPLATECONFIG_READFAILED = 131,
	//��ģ���ļ�ʧ��
	ENUM_ERRORCODE_TEMPLATECONFIG_OPENFAILED = 132,
	//����ģ���ļ�ʧ��
	ENUM_ERRORCODE_TEMPLATE_CREATEFAILED = 133,
	//�Ŵ������������ȷ���������
	ENUM_ERRORCODE_RECOPARA_RATIOFAILED = 134,
	

};



//ͼ������ݽṹ
typedef struct _PointInfo
{
	int x;
	int y;
	int val;
	_PointInfo()
	{
		x = 0;
		y = 0;
		val = 0;
	}
}PointInfo;

//����������
typedef deque<PointInfo> DQPointLine;

//���������ݽṹ
typedef struct _LineVector
{
	//������
	DQPointLine DQLine;
	//������
	DQPointLine HighlightPoints;
}LineVector;

//������
typedef deque<LineVector> DQLines;

typedef struct _structSection
{
	int nBlockS;
	deque<CtrlPoint>** dqCtrlPoints;
	_structSection()
	{
		nBlockS = 0;
		dqCtrlPoints = NULL;
	}
	~_structSection()
	{
		if (dqCtrlPoints)
		{
			for (int i = 0; i < nBlockS; i++)
			{
				if (dqCtrlPoints[i])
				{
					delete[] dqCtrlPoints[i];
				}
			}

			delete[] dqCtrlPoints;
			dqCtrlPoints = NULL;
		}
	}
	
}structSection;
//ʶ������
typedef struct _structDetecionType
{
	CStringA strDetecionName;
	int nType;
	int nSectionS;
	structSection* struSection;
	_structDetecionType()
	{
		strDetecionName = "";
		nType = -1;
		nSectionS = 0;
		struSection = NULL;
	}
	~_structDetecionType()
	{
		if (struSection)
		{
			delete[] struSection;
			struSection = NULL;
		}
	}
}structDetecionType;

//ģ������ö��
enum class enumDetectionType
{
	enumDetectionType_Area = 0,
	enumDetectionType_LVS,
	enumDetectionType_RVS,
	enumDetectionType_HS,
	enumDetectionType_Angle,
	enumDetectionType_Hole,
	enumDetectionType_Count
};

#define STRAREA "Area"
#define STRLVS "Lvs"
#define STRRVS "Rvs"
#define STRHS "Hs"
#define STRANGLE "Angle"
#define STRHOLE "Hole"

//ģ����Ƶ�����
typedef struct _structTemplateCtrlPoint
{
	//ʶ�����ͣ�����������ߡ������ߡ���ߡ��ǡ���
	structDetecionType Detection[(unsigned long long)enumDetectionType::enumDetectionType_Count];
}structTemplateCtrlPoint;

class TempLateCtrlPointOperation
{
public:
	TempLateCtrlPointOperation() {}
	~TempLateCtrlPointOperation() {}
	//����ʶ������������-1��ʾδ�ҵ�
	static int GetTypeIndex(CStringA p_strTypeName)
	{
		CStringA strType = "";
		for (int i = 0; i < (int)enumDetectionType::enumDetectionType_Count; i++)
		{
			enumDetectionType tDetectionType = (enumDetectionType)(i);
			switch (tDetectionType)
			{
			case enumDetectionType::enumDetectionType_Area:
			{
				strType = STRAREA;
			}
			break;
			case enumDetectionType::enumDetectionType_LVS:
			{
				strType = STRLVS;
			}
			break;
			case enumDetectionType::enumDetectionType_RVS:
			{
				strType = STRRVS;
			}
			break;
			case enumDetectionType::enumDetectionType_HS:
			{
				strType = STRHS;
			}
			break;
			case enumDetectionType::enumDetectionType_Angle:
			{
				strType = STRANGLE;
			}
			break;
			case enumDetectionType::enumDetectionType_Hole:
			{
				strType = STRHOLE;
			}
			break;
			case enumDetectionType::enumDetectionType_Count:
				break;
			default:
				break;
			}

			if (p_strTypeName == strType)
			{
				return i;
			}
		}

		return -1;
	}

	static CStringA GetTypeName(enumDetectionType p_DetectionType)
	{
		CStringA strTypeName = "";
		switch (p_DetectionType)
		{
		case enumDetectionType::enumDetectionType_Area:
		{strTypeName = STRAREA; }
			break;
		case enumDetectionType::enumDetectionType_LVS:
		{strTypeName = STRLVS; }
			break;
		case enumDetectionType::enumDetectionType_RVS:
		{strTypeName = STRRVS; }
			break;
		case enumDetectionType::enumDetectionType_HS:
		{strTypeName = STRHS; }
			break;
		case enumDetectionType::enumDetectionType_Angle:
		{strTypeName = STRANGLE; }
			break;
		case enumDetectionType::enumDetectionType_Hole:
		{strTypeName = STRHOLE; }
			break;
		case enumDetectionType::enumDetectionType_Count:
			break;
		default:
			break;
		}

		return strTypeName;
	}
private:

};

typedef struct _CurveSplit
{
	int nStart;
	int nEnd;
	int nLen;
	int nFlag;

	_CurveSplit()
	{
		nStart = -1;
		nEnd = -1;
		nLen = 0;
		//���Ʒ���0-ˮƽ��1-����(����)��-1-�½�(����)��2-δ֪,��Ҫ���˲�ʱ�жϡ�3-��ͻ��
		nFlag = -1;
	}

	int GetLen()
	{
		return (nEnd - nStart);
	}
}CurveSplit;



typedef struct _MutationPoint :public _CurveSplit
{
	bool bIsSplitPoint = false;
	int nSum = 0;
	int nSharpPointIndex = 0;
}MutationPoint;

typedef struct _structSharpPoint
{
	int nIndex = 0;
	int nType = 0;
}structSharpPoint;

//ʶ����
typedef struct _RecognitionResult
{
	//ȱ����Ӿ���
	Rect mRect;
	//ȱ�������㼯��
	std::vector<cv::Point> ptr;
	~_RecognitionResult()
	{
		ptr.clear();
	}
}RecognitionResult;



//typedef struct  _Position
//{
//	
//
//	_Position()
//	{
//		
//	}
//	
//}Position;

//���߱任������ձ�
typedef struct _CoordinateContrast
{
	Point mPoint;
	float fGrayscale;
	_CoordinateContrast()
	{
		mPoint.x = 0;
		mPoint.y = 0;
		fGrayscale = 0.0;
	}
}CoordinateContrast;



