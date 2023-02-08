using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GTSDemoCSharp
{
    //例程 8-5 hsio捕获
    class Program
    {
        // 该函数检测某条GT指令的执行结果，command为指令名称，error为指令执行返回值
        static void commandhandler(string command, short error)
        {
            // 如果指令执行返回值为非0，说明指令执行错误，向屏幕输出错误结果
            if (error != 0)
            {
                Console.WriteLine("{0}={1}\n", command, error);
            }
        }

        const short AXIS = 1;//比较的轴

        static void Main(string[] args)
        {
            uint clk;
            short sRtn, capture; 
	        gts.mc.TTrapPrm trapPrm; 
	        int status, pos; 
	        double prfPos, encPos; 
	        int[] hsioOptPos=new int[4];
            int[] hsioOptPosNULL = new int[4] { 0,0,0,0};

            // 打开运动控制器 
            sRtn = gts.mc.GT_Open(0,1);
            // 复位运动控制器 
            sRtn = gts.mc.GT_Reset();
            // 配置运动控制器 
            sRtn = gts.mc.GT_LoadConfig("GT800_test.cfg");
            // 清除指定轴的报警和限位 
            sRtn = gts.mc.GT_ClrSts(AXIS,1);
            // 驱动器使能 
            sRtn = gts.mc.GT_AxisOn(AXIS);
            hsioOptPos[0] = 500;
            hsioOptPos[1] = 2000;
            hsioOptPos[2] = 4000;
            hsioOptPos[3] = 5000;
            // 设置位置比较数据，启动位置比较输出
            sRtn = gts.mc.GT_CompareData(1,						// 对1轴进行位置比较输出
                                    1,						// 需要进行比较的数据源为外部编码器
                                    0,						// 到达比较位置后输出脉冲
                                    0,	 					// 初始状态为低电平
                                    500,					// 脉冲宽度为500us
                                    ref hsioOptPos[0],				// HSIO0的比较位置缓冲区数据起始地址
                                    4,						// HSIO0的比较位置缓冲区数据长度
                                    ref hsioOptPosNULL[0],
                                    0);
            // 启动Hsio 捕获 
            sRtn = gts.mc.GT_SetCaptureMode(AXIS, gts.mc.CAPTURE_HSIO0);
            // 切换到点位运动模式 
            sRtn = gts.mc.GT_PrfTrap(AXIS);
            // 读取、设置点位模式运动参数
            sRtn = gts.mc.GT_GetTrapPrm(AXIS, out trapPrm);
            trapPrm.acc = 0.25;
            trapPrm.dec = 0.25;
            sRtn = gts.mc.GT_SetTrapPrm(AXIS, ref trapPrm);
            // 设置点位模式目标速度，即运动速度 
            sRtn = gts.mc.GT_SetVel(AXIS, 10);
            // 设置点位模式目标位置，使HSIO触发输出
            sRtn = gts.mc.GT_SetPos(AXIS, 10000);
            // 启动运动 
            sRtn = gts.mc.GT_Update(1 << (AXIS - 1));
            short cmp_st = 0;
            int pCount = 0;
            int ii = 0;
            sRtn = gts.mc.GT_CompareStatus(out cmp_st, out pCount);
            do
            {
                sRtn = gts.mc.GT_CompareStatus(out cmp_st, out pCount);
                // 读取轴状态 
                sRtn = gts.mc.GT_GetSts(AXIS, out status,1,out clk);
                // 读取捕获状态 
                sRtn = gts.mc.GT_GetCaptureStatus(AXIS, out capture, out pos,1,out clk);
                // 读取规划位置 
                sRtn = gts.mc.GT_GetPrfPos(AXIS, out prfPos,1,out clk);
                // 读取编码器位置 
                sRtn = gts.mc.GT_GetEncPos(AXIS, out encPos,1,out clk);
                if (1 == pCount && ii == 0)
                {
                    ++ii;
                    Console.WriteLine("capture={0} prfPos={1} encPos={2}\r\n", pCount, prfPos, encPos);
                }
                if (2 == pCount && ii == 1)
                {
                    ++ii;
                    Console.WriteLine("capture={0} prfPos={1} encPos={2}\r\n", pCount, prfPos, encPos);
                }
                if (3 == pCount && ii == 2)
                {
                    ++ii;
                    Console.WriteLine("capture={0} prfPos={1} encPos={2}\r\n", pCount, prfPos, encPos);
                }
                if (4 == pCount && ii == 3)
                {
                    ++ii;
                    Console.WriteLine("capture={0} prfPos={1} encPos={2}\r\n", pCount, prfPos, encPos);
                }
                Console.WriteLine("prfPos={0} encPos={1}\r\n", prfPos, encPos);
                // 等待捕获触发

                System.Threading.Thread.Sleep(100);//降低控制台刷新速率
            } while (pCount <= 3);
            // 显示捕获位置 
            Console.WriteLine("prfPos={0} encPos={1}\r\n", prfPos, encPos);
            Console.WriteLine("count=={0}\r\n", pCount);
            sRtn = gts.mc.GT_Stop(1, 1);






            /**********************第二次捕获*****************************/

            hsioOptPos[0] = 10500;
            hsioOptPos[1] = 12000;
            hsioOptPos[2] = 14000;
            hsioOptPos[3] = 15000;
            // 设置位置比较数据，启动位置比较输出
            sRtn = gts.mc.GT_CompareData(1,						// 对1轴进行位置比较输出
                                    1,						// 需要进行比较的数据源为外部编码器
                                    0,						// 到达比较位置后输出脉冲
                                    0,	 					// 初始状态为低电平
                                    500,					// 脉冲宽度为500us
                                    ref hsioOptPos[0],				// HSIO0的比较位置缓冲区数据起始地址
                                    3,						// HSIO0的比较位置缓冲区数据长度
                                    ref hsioOptPosNULL[0],
                                    0);
            // 启动Hsio 捕获 
            sRtn = gts.mc.GT_SetCaptureMode(AXIS, gts.mc.CAPTURE_HSIO0);
            //	sRtn = GT_AxisOff(AXIS);
            sRtn = gts.mc.GT_CompareStatus(out cmp_st, out pCount);
            ii = 0;

            // 切换到点位运动模式 
            sRtn = gts.mc.GT_PrfTrap(AXIS);
            // 读取、设置点位模式运动参数
            sRtn = gts.mc.GT_GetTrapPrm(AXIS, out trapPrm);
            trapPrm.acc = 0.25;
            trapPrm.dec = 0.25;
            sRtn = gts.mc.GT_SetTrapPrm(AXIS, ref trapPrm);
            // 设置点位模式目标速度，即运动速度 
            sRtn = gts.mc.GT_SetVel(AXIS, 10);
            sRtn = gts.mc.GT_SetPos(AXIS, 30000);
            // 启动运动 
            sRtn = gts.mc.GT_Update(1 << (AXIS - 1));
            
            do
            {
                Console.WriteLine("prfPos={0} encPos={1}\r", prfPos, encPos);
                sRtn = gts.mc.GT_CompareStatus(out cmp_st, out pCount);
                // 读取轴状态 
                sRtn = gts.mc.GT_GetSts(AXIS, out status, 1, out clk);
                // 读取捕获状态 
                sRtn = gts.mc.GT_GetCaptureStatus(AXIS, out capture, out pos, 1, out clk);
                // 读取规划位置 
                sRtn = gts.mc.GT_GetPrfPos(AXIS, out prfPos, 1, out clk);
                // 读取编码器位置 
                sRtn = gts.mc.GT_GetEncPos(AXIS, out encPos, 1, out clk);
                if (1 == pCount && ii == 0)
                {
                    ++ii;
                    Console.WriteLine("capture={0} prfPos={1} encPos={2}\r\n", pCount, prfPos, encPos);
                }
                if (2 == pCount && ii == 1)
                {
                    ++ii;
                    Console.WriteLine("capture={0} prfPos={1} encPos={2}\r\n", pCount, prfPos, encPos);
                }
                if (3 == pCount && ii == 2)
                {
                    ++ii;
                    Console.WriteLine("capture={0} prfPos={1} encPos={2}\r\n", pCount, prfPos, encPos);
                }
                if (4 == pCount && ii == 3)
                {
                    ++ii;
                    Console.WriteLine("capture={0} prfPos={1} encPos={2}\r\n", pCount, prfPos, encPos);
                }
                // 等待捕获触发

                System.Threading.Thread.Sleep(100);//降低控制台刷新速率
            } while (pCount <= 2);

            Console.WriteLine("prfPos={0} encPos={1}\r\n", prfPos, encPos);
            Console.WriteLine("count=={0}\r\n", pCount);

            Console.ReadLine();
        }
    }
}
