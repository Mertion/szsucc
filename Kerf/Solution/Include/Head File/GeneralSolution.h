#pragma once
#pragma warning(disable:4996)

#include "stdafx.h"
#include "InterFace.h"

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


using namespace std;
using namespace cv;

////ģ�ⷽʽ 0-�豸���У�1-ͼ���ļ�ģʽ��2-�豸�ֶ�ģʽ
//#define SIMULATIONMODE 0;

//����ģʽ
//#define DEBUG_MODE 1

//��ʶ��������
#define DEBUG_ANGLE 1
//���Դ���ģʽ
#define DEBUGCODE_MODE 1
//���߳�ģʽ
#define MULTITHREADMODE 1


//PIԲ����
const float const_PI = (float)3.1415926;

