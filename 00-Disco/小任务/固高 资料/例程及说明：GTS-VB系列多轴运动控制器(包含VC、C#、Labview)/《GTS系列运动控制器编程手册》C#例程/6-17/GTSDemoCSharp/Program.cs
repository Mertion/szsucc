using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GTSDemoCSharp
{
    //例程6-17 PVT描述方式
    class Program
    {
        const short AXIS = 1;
        const short TABLE = 1;

        // 该函数检测某条GT指令的执行结果，command为指令名称，error为指令执行返回值
        static void commandhandler(string command, short error)
        {
            // 如果指令执行返回值为非0，说明指令执行错误，向屏幕输出错误结果
            if (error!=0)
            {
                Console.WriteLine("{0}={1}\n",command,error);
            }
        }

        static void Main(string[] args)
        {
            short sRtn;
            int mask;
            uint clk;
            // X轴的数据点参数
	        double[] time=new double[6]{0, 1200, 2000, 3000, 3800, 5000};
            double[] pos = new double[6] { 0, 9750, 24483, 44483, 59216, 68966 };
            double[] vel = new double[6] { 1, 15.25, 20, 20, 15.25, 1 };
            double prfVel, prfPos, t;
	        short tableId;

	        // 打开运动控制器
	        sRtn = gts.mc.GT_Open(0,1);
	        commandhandler("GT_Open", sRtn);
	        // 复位运动控制器
            sRtn = gts.mc.GT_Reset();
	        commandhandler("GT_Reset", sRtn);
	        // 配置运动控制器
	        // 注意：配置文件取消了各轴的报警和限位
            sRtn = gts.mc.GT_LoadConfig("GT800_test.cfg");
	        commandhandler("GT_LoadConfig", sRtn);
	        // 清除各轴报警和限位
            sRtn = gts.mc.GT_ClrSts(1, 8);
	        commandhandler("GT_ClrSts", sRtn);
            sRtn = gts.mc.GT_AxisOn(AXIS);
	        commandhandler("GT_AxisOn", sRtn);
	        // 等待伺服使能就绪
	        System.Threading.Thread.Sleep(1000);
	        // 设置为PVT模式
            sRtn = gts.mc.GT_PrfPvt(AXIS);
	        commandhandler("GT_PrfPvt", sRtn);
	        // 发送数据
            sRtn = gts.mc.GT_PvtTable(TABLE, 6, ref time[0], ref pos[0], ref vel[0]);
	        commandhandler("GT_PvtTable", sRtn);
	        // 选择数据表
            sRtn = gts.mc.GT_PvtTableSelect(AXIS, TABLE);
	        commandhandler("GT_PvtTableSelect", sRtn);
	        mask = 1<<(AXIS-1);
            sRtn = gts.mc.GT_PvtStart(mask);
	        commandhandler("GT_PvtStart", sRtn);
            
            ConsoleKeyInfo ki=new ConsoleKeyInfo();//按键变量
            //按下空格键后退出循环
	        while(true)
	        {
                //有按键输入退出循环
                if (System.Console.KeyAvailable)
                    break;
		        // 读取数据表和运动时间
                sRtn = gts.mc.GT_PvtStatus(AXIS, out tableId, out t,1);
		        // 读取规划速度
                sRtn = gts.mc.GT_GetPrfVel(AXIS, out prfVel,1,out clk);
		        // 读取规划位置
                sRtn = gts.mc.GT_GetPrfPos(AXIS, out prfPos,1,out clk);
		        
                Console.WriteLine("数据表ID={0},时间={1},规划速度={2},规划位置={3}\n", tableId, t, prfVel, prfPos);

                System.Threading.Thread.Sleep(100);//降低控制台刷新速率
	        }

        }
    }
}
