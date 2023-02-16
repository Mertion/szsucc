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

//opencv 2.4.13.7在编译时引用了vfw32库，所以此处也必须引用此库，否则编译时会报错。
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

//因为opencv生成的world库内容不全，还需要连接上面多个独立库的内容，所以此处放弃world库模式
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

//因为opencv生成的world库内容不全，还需要连接上面多个独立库的内容，所以此处放弃world库模式
//#pragma comment(lib,"opencv_world2413") 
#endif // DEBUG

#include "./MainFramework/Recognition/Detection/CtrlPoint.h"

using namespace std;
using namespace cv;

////模拟方式 0-设备运行，1-图像文件模式，2-设备手动模式
//#define SIMULATIONMODE 0;

//调试模式
//#define DEBUG_MODE 1
//调试二次检测中每个缺陷块的过程图像
//#define DEBUG_SECOND 1
//角识别结果调试
#define DEBUG_ANGLE 1
//调试代码模式
#define DEBUGCODE_MODE 1
//多线程模式
#define MULTITHREADMODE 1
//模板调试
#define DEBUG_TEMPLATE 1
//校正调试
//#define DEBUG_CORRECTION 1
//基平面差值
//#define DEBUG_BASEPLANEDIFFERENCE1 1
//#define DEBUG_BASEPLANEDIFFERENCE2 1

//#define DEBUG_BASEPHorizontalEdge 1
//任意曲线模板调试
#define DEBUG_ARBITRARYCURVE 1


//金龙浩验收
#define DEBUG_JLHACCEPTANCE 0

//相机个数
#define CAMERA_COUNTER 2
//相机采集图像宽度
#define MAX_LINECOUNTER 10000
//相机采集图像宽度
#define CAMERA_WIDTH 4096
//相机采集图像高度
#define CAMERA_HIGH 30000
//获取图像数据宽度
#define DEFULTIMAGE_WIDTH 3000
//获取图像数据高度
#define DEFULTIMAGE_HIGH 3000
//检测对象个数
//#define DETECTION_OBJS 6
//#define DETECTION_OBJS 1
#define DETECTION_OBJS 0
//图像工位缓存个数
#define MAXPOSITIONNUMBER 12

//PI圆周率
const float const_PI = (float)3.1415926;
//半径外扩
const int const_nRadiusEx = 20;

extern const int const_nStep_x;
//微分曲线偏移量
extern const int const_nZeroLineOffset;
//y方向数据广大比例
extern const int const_nDifScale;
//数据曲线偏移量
extern const int const_nDataLineOffset;
//系统报警枚举
enum ENUM_WARNING
{
	//打开相机失败
	ENUM_WARNING_CAMERA_OPENFAILED = 50,
	//获取相机配置失败
	ENUM_WARNING_CAMERA_GETCONFIGFAILED = 51,
	//关闭相机失败
	ENUM_WARNING_CAMERA_CLOSEFAILED = 52,
	//从相机获得图像尺寸不正确
	ENUM_WARNING_CAMERA_IMAGESIZEINCORRECT = 53,
	//传感器校正文件读取出错
	ENUM_ERRORCODE_CAMERACORRECTION_READFAILED = 55,
	//传感器校正文件打开失败
	ENUM_ERRORCODE_CAMERACORRECTION_OPENFAILED = 56,
	//读取模板文件失败
	ENUM_ERRORCODE_TEMPLATECONFIG_READFAILED = 131,
	//打开模板文件失败
	ENUM_ERRORCODE_TEMPLATECONFIG_OPENFAILED = 132,
	//创建模板文件失败
	ENUM_ERRORCODE_TEMPLATE_CREATEFAILED = 133,
	//放大比例参数不正确，需大于零
	ENUM_ERRORCODE_RECOPARA_RATIOFAILED = 134,
	

};



//图像点数据结构
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

//线数据类型
typedef deque<PointInfo> DQPointLine;

//线向量数据结构
typedef struct _LineVector
{
	//向量线
	DQPointLine DQLine;
	//高亮线
	DQPointLine HighlightPoints;
}LineVector;

//向量集
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
//识别区块
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

//模板类型枚举
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

//模板控制点类型
typedef struct _structTemplateCtrlPoint
{
	//识别类型：面积、左竖边、右竖边、横边、角、孔
	structDetecionType Detection[(unsigned long long)enumDetectionType::enumDetectionType_Count];
}structTemplateCtrlPoint;

class TempLateCtrlPointOperation
{
public:
	TempLateCtrlPointOperation() {}
	~TempLateCtrlPointOperation() {}
	//返回识别类型索引，-1表示未找到
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
		//趋势方向：0-水平、1-上升(里沿)、-1-下降(外沿)、2-未知,需要在滤波时判断、3-真突变
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

//识别结果
typedef struct _RecognitionResult
{
	//缺陷外接矩形
	Rect mRect;
	//缺陷轮廓点集合
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

//曲线变换坐标对照表
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



