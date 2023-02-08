using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GTSDemoCSharp
{
    // 例程 11-4 比较位置输出
    //
    // 本例程演示如何使用位置比较输出功能，假设需要在-55000到65000等间距输出13个脉冲，并使用位置输出通道1的信号进行捕获
    // 由于位置比较功能接收的位置数据是输出位置相对于命令执行时编码器的位置数据，且仅接受递增正位置数据（或递减负位置数
    // 据），因此程序首先控制比较轴运动到-65000，再设置设置位置数据为10000到130000之间等间距的13个数（相对位置）
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

        const short AXIS = 1;
        const short POS_NUM = 13;
        const int START_POS = 10000;
        const int END_POS = 130000;

        static void Main(string[] args)
        {
            short sRtn;
	        gts.mc.TTrapPrm trap;
	        int sts;
	        double prfPos;
	        int[] Buf1=new int[20];
            int[] Buf2 = new int[20];
	        int i;
	        int interval;
	        short pSts;
	        int pCount;
            uint clk;
	        // 打开运动控制器
	        sRtn = gts.mc.GT_Open(0,1);
	        // 指令返回值检测，请查阅例2-1
	        commandhandler("GT_Open", sRtn);
	        // 配置运动控制器
	        // 注意：配置文件取消了各轴的报警和限位
	        sRtn = gts.mc.GT_LoadConfig("GT800_test.cfg");
	        commandhandler("GT_LoadConfig ", sRtn);
	        // 清除各轴的报警和限位
	        sRtn = gts.mc.GT_ClrSts(1, 8);
	        commandhandler("GT_ClrSts", sRtn);
	        // 位置清零
	        sRtn = gts.mc.GT_ZeroPos(AXIS,1);
	        commandhandler("GT_ZeroPos", sRtn);
	        // AXIS轴规划位置清零
	        sRtn = gts.mc.GT_SetPrfPos(AXIS, 0);
	        commandhandler("GT_SetPrfPos", sRtn);
	        // 将AXIS轴设为点位模式
	        sRtn = gts.mc.GT_PrfTrap(AXIS);
	        commandhandler("GT_PrfTrap", sRtn);
	        // 读取点位运动参数
	        sRtn = gts.mc.GT_GetTrapPrm(AXIS, out trap);
	        commandhandler("GT_GetTrapPrm", sRtn);
	        trap.acc = 0.25;
	        trap.dec = 0.125;
	        trap.smoothTime = 25;
	        // 设置点位运动参数
	        sRtn = gts.mc.GT_SetTrapPrm(AXIS, ref trap);
	        commandhandler("GT_SetTrapPrm", sRtn);
	        // 伺服使能
	        sRtn = gts.mc.GT_AxisOn(AXIS);
	        commandhandler("GT_AxisOn", sRtn);
	        // 设置AXIS轴的目标位置
	        sRtn = gts.mc.GT_SetPos(AXIS, -65000);
	        commandhandler("GT_SetPos", sRtn);
	        // 设置AXIS轴的目标速度
	        sRtn = gts.mc.GT_SetVel(AXIS, 50);
	        commandhandler("GT_SetVel", sRtn);
	        // 启动AXIS轴的运动
	        sRtn = gts.mc.GT_Update(1<<(AXIS-1));
	        commandhandler("GT_Update", sRtn);
	        do
	        {
		        // 读取AXIS轴的状态
		        sRtn = gts.mc.GT_GetSts(AXIS, out sts,1,out clk);
		        // 读取AXIS轴的规划位置
		        sRtn = gts.mc.GT_GetPrfPos(AXIS, out prfPos,1,out clk);
                Console.WriteLine("sts={0},prfPos={1}\r", sts, prfPos);

                System.Threading.Thread.Sleep(100);//降低控制台刷新速率

            } while ((sts & 0x400)!=0);	// 等待AXIS轴规划停止

	        // 计算比较位置
	        interval = (END_POS - START_POS) / (POS_NUM - 1);
	        Buf1[0] = START_POS;
	        for(i=1;i<POS_NUM;i++)
	        {
		        Buf1[i] = Buf1[i-1] + interval;
	        }
        	
	        // 设置位置比较数据，启动位置比较输出
	        sRtn = gts.mc.GT_CompareData(1, 1, 0, 0, 100, ref Buf1[0], POS_NUM, ref Buf2[0], 0);
	        commandhandler("GT_CompareData", sRtn);
	        // 设置AXIS轴的目标位置
	        sRtn = gts.mc.GT_SetPos(AXIS, 7000);
	        commandhandler("GT_SetPos", sRtn);
	        // 设置AXIS轴的目标速度
	        sRtn = gts.mc.GT_SetVel(AXIS, 50);
	        commandhandler("GT_SetVel", sRtn);
	        // 启动AXIS轴的运动
	        sRtn = gts.mc.GT_Update(1<<(AXIS-1));
	        commandhandler("GT_Update", sRtn);

	        do
	        {
		        // 读取AXIS轴的状态
		        sRtn = gts.mc.GT_GetSts(AXIS, out sts,1,out clk);
		        // 读取AXIS轴的规划位置
		        sRtn = gts.mc.GT_GetPrfPos(AXIS, out prfPos,1,out clk);
		        // 读取比较输出脉冲个数
		        sRtn = gts.mc.GT_CompareStatus(out pSts, out pCount);
                Console.WriteLine("sts={0},prfPos={1},outputed hsio={2}\r", sts, prfPos, pCount);

                System.Threading.Thread.Sleep(100);//降低控制台刷新速率

            } while ((sts & 0x400)!=0);	// 等待AXIS轴规划停止

	        // 伺服关闭
	        sRtn = gts.mc.GT_AxisOff(AXIS);
            commandhandler("GT_AxisOff", sRtn);

            Console.ReadLine();//持续显示控制台屏幕等待退出
        }
    }
}
