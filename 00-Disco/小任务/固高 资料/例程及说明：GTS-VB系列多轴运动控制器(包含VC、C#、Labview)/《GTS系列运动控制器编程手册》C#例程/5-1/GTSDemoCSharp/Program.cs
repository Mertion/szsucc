using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GTSDemoCSharp
{
    // 例程 5-1 获取轴1的轴状态、运动模式、位置、速度和加速度
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

        //轴号
        const short AXIS = 1;

        static void Main(string[] args)
        {
            bool bFlagAlarm = false;			// 伺服报警标志
            bool bFlagMError = false;			// 跟随误差越限标志
            bool bFlagPosLimit = false;		// 正限位触发标志
            bool bFlagNegLimit = false;		// 负限位触发标志
            bool bFlagSmoothStop = false;		// 平滑停止标志
            bool bFlagAbruptStop = false;		// 急停标志
            bool bFlagServoOn = false;		// 伺服使能标志
            bool bFlagMotion = false;			// 规划器运动标志
	        double dPrfPos;					// 规划位置
	        double dPrfVel;					// 规划速度
	        double dPrfAcc;					// 规划加速度
	        int lPrfMode;					// 运动模式
	        short sRtn;						// 指令返回值变量
	        int lAxisStatus;					// 轴状态

            uint clk;

	        // 打开运动控制器
	        sRtn = gts.mc.GT_Open(0,1);
	        // 指令返回值检测，请查阅例2-1
	        commandhandler("GT_Open", sRtn);
	        // 系统复位
	        sRtn = gts.mc.GT_Reset();
	        commandhandler("GT_Reset", sRtn);
            //加载配置文件
            //sRtn = gts.mc.GT_LoadConfig("GTS800_test.cfg");
            //commandhandler("GT_LoadConfig", sRtn);
	        // 读取轴状态
	        sRtn = gts.mc.GT_GetSts(AXIS, out lAxisStatus,1,out clk);
	        commandhandler("GT_GetSts" , sRtn);

	        // 伺服报警标志
            if ((lAxisStatus & 0x2)!=0)
	        {
		        bFlagAlarm = true;
		        Console.WriteLine("伺服报警\n");
	        }
	        else
	        {
		        bFlagAlarm = false;
		        Console.WriteLine("伺服正常\n");
	        }
	        // 跟随误差越限标志
            if ((lAxisStatus & 0x10)!=0)
	        {
		        bFlagMError = true;
		        Console.WriteLine("运动出错\n");
	        }
	        else
	        {
		        bFlagMError = false;
		        Console.WriteLine("运动正常\n");
	        }
	        // 正向限位
            if ((lAxisStatus & 0x20)!=0)
	        {
		        bFlagPosLimit = true;
		        Console.WriteLine("正限位触发\n");
	        }
	        else
	        {
		        bFlagPosLimit = false;
		        Console.WriteLine("正限位未触发\n");
	        }
	        // 负向限位
            if ((lAxisStatus & 0x40)!=0)
	        {
		        bFlagNegLimit = true;
		        Console.WriteLine("负限位触发\n");
	        }
	        else
	        {
		        bFlagNegLimit = false;
		        Console.WriteLine("负限位未触发\n");
	        }
	        // 平滑停止
            if ((lAxisStatus & 0x80)!=0)
	        {
		        bFlagSmoothStop = true;
		        Console.WriteLine("平滑停止触发\n");
	        }
	        else
	        {
		        bFlagSmoothStop = false;
		        Console.WriteLine("平滑停止未触发\n");
	        }
	        // 急停标志
            if ((lAxisStatus & 0x100)!=0)
	        {
		        bFlagAbruptStop = true;
		        Console.WriteLine("急停触发\n");
	        }
	        else
	        {
		        bFlagAbruptStop = false;
		        Console.WriteLine("急停未触发\n");
	        }
	        // 伺服使能标志
            if ((lAxisStatus & 0x200)!=0)
	        {
		        bFlagServoOn = true;
		        Console.WriteLine("伺服使能\n");
	        }
	        else
	        {
		        bFlagServoOn = false;
		        Console.WriteLine("伺服关闭\n");
	        }
	        // 规划器正在运动标志
            if ((lAxisStatus & 0x400)!=0)
	        {
		        bFlagMotion = true;
		        Console.WriteLine("规划器正在运动\n");
	        }
	        else
	        {
		        bFlagMotion = false;
		        Console.WriteLine("规划器已停止\n");
	        } 

	        // 读取运动数据
	        sRtn = gts.mc.GT_GetPrfPos(AXIS, out dPrfPos,1,out clk);
	        commandhandler("GT_GetPrfPos", sRtn); 
	        Console.WriteLine("规划位置{0}\n", dPrfPos);
	        sRtn = gts.mc.GT_GetPrfVel(AXIS, out dPrfVel,1,out clk);
	        commandhandler("GT_GetPrfVel", sRtn);
	        Console.WriteLine("规划速度{0}\n", dPrfVel);
	        sRtn=gts.mc.GT_GetPrfAcc(AXIS, out dPrfAcc,1,out clk);
	        commandhandler("GT_GetPrfAcc", sRtn);
	        Console.WriteLine("规划加速度{0}\n", dPrfAcc);

	        // 读取运动模式
	        sRtn = gts.mc.GT_GetPrfMode(AXIS, out lPrfMode,1,out clk);
	        commandhandler("GT_GetPrfMode", sRtn);

	        switch(lPrfMode) 
	        {
		        case 0:
                    Console.WriteLine("Trap");
		        break;
		        case 1:
                    Console.WriteLine("Jog");
		        break;
		        case 2:
                    Console.WriteLine("PT");
		        break;
		        case 3:
                    Console.WriteLine("Gear");
		        break;
		        case 4:
                    Console.WriteLine("Follow");
		        break;
		        case 5:
                    Console.WriteLine("Interpolation");
		        break;
		        case 6:
                    Console.WriteLine("PVT");
		        break;
		        default:
		        break;
	        }

            Console.ReadLine();
        }
    }
}
