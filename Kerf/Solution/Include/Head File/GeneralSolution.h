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


using namespace std;
using namespace cv;

////模拟方式 0-设备运行，1-图像文件模式，2-设备手动模式
//#define SIMULATIONMODE 0;

//调试模式
//#define DEBUG_MODE 1

//角识别结果调试
#define DEBUG_ANGLE 1
//调试代码模式
#define DEBUGCODE_MODE 1
//多线程模式
#define MULTITHREADMODE 1


//PI圆周率
const float const_PI = (float)3.1415926;

