using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GTSDemoCSharp
{
    //例程 6-19 Percent描述方式
    class Program
    {
        const short AXIS_X = 1;
        const short AXIS_Y = 2;
        const short TABLE_X = 1;
        const short TABLE_Y = 2;
        const int LOOP_COUNT = 2;

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
	        double[] time_x =new double[7] {0, 1000, 2000, 3000, 4000, 5000, 6000};
            double[] pos_x = new double[7] { 0, 5000, 15000, 20000, 15000, 5000, 0 };
            double[] percent_x = new double[7] { 60, 0, 60, 60, 0, 60, 0 };
	        // Y轴的数据点参数
            double[] time_y = new double[5] { 2000, 2500, 3500, 4000, 5000 };
            double[] pos_y = new double[5] { 0, 2500, 12500, 15000, 15000 };
            double[] percent_y = new double[5] { 60, 0, 60, 0, 0 };
	        double[] prfVel=new double[2], prfPos=new double[2], time=new double[2];

            short[] tableId = new short[2];
        	
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
            sRtn = gts.mc.GT_AxisOn(AXIS_X);
	        commandhandler("GT_AxisOn", sRtn);
            sRtn = gts.mc.GT_AxisOn(AXIS_Y);
	        commandhandler("GT_AxisOn", sRtn);
	        // 等待伺服使能就绪
	        System.Threading.Thread.Sleep(1000);
	        // 将X轴设置为PVT模式
            sRtn = gts.mc.GT_PrfPvt(AXIS_X);
	        commandhandler("GT_PrfPvt", sRtn);
	        // 将Y轴设置为PVT模式
            sRtn = gts.mc.GT_PrfPvt(AXIS_Y);
	        commandhandler("GT_PrfPvt", sRtn);
	        // 向X轴的数据表发送数据
            sRtn = gts.mc.GT_PvtTablePercent(TABLE_X, 7, ref time_x[0], ref pos_x[0], ref percent_x[0], 0);
	        commandhandler("GT_PvtTablePercent", sRtn);
	        // 向Y轴的数据表发送数据
            sRtn = gts.mc.GT_PvtTablePercent(TABLE_Y, 5, ref time_y[0], ref pos_y[0], ref percent_y[0], 0);
	        commandhandler("GT_PvtTablePercent", sRtn);
	        // X轴选择数据表TABLE_X
            sRtn = gts.mc.GT_PvtTableSelect(AXIS_X, TABLE_X);
	        commandhandler("GT_PvtTableSelect", sRtn);
	        // Y轴选择数据表TABLE_Y
            sRtn = gts.mc.GT_PvtTableSelect(AXIS_Y, TABLE_Y);
	        commandhandler("GT_PvtTableSelect", sRtn);
	        // 设置循环次数
            sRtn = gts.mc.GT_SetPvtLoop(AXIS_X, LOOP_COUNT);
	        commandhandler("GT_SetPvtLoop", sRtn);
	        // 设置循环次数
            sRtn = gts.mc.GT_SetPvtLoop(AXIS_Y, 2 * LOOP_COUNT - 1);
	        commandhandler("GT_SetPvtLoop", sRtn);
	        // 同时启动X轴和Y轴
	        // 由于Y轴的第1个数据点时间为2000ms
	        // 因此X轴启动2000ms以后，Y轴才开始运动
	        mask = 1<<(AXIS_X-1);
	        mask |= 1<<(AXIS_Y-1);
            sRtn = gts.mc.GT_PvtStart(mask);
	        commandhandler("GT_PvtStart", sRtn);


            while (true)
	        {
                //有按键输入退出循环
                if (System.Console.KeyAvailable)
                    break;
		        // 读取数据表和运动时间
                sRtn = gts.mc.GT_PvtStatus(AXIS_X, out tableId[0], out time[0],1);
                sRtn = gts.mc.GT_PvtStatus(AXIS_Y, out tableId[1], out time[1],1);
		        // 读取规划速度
                sRtn = gts.mc.GT_GetPrfVel(AXIS_X, out prfVel[0],1,out clk);
                sRtn = gts.mc.GT_GetPrfVel(AXIS_Y, out prfVel[1],1,out clk);
		        // 读取规划位置
                sRtn = gts.mc.GT_GetPrfPos(AXIS_X, out prfPos[0],1,out clk);
                sRtn = gts.mc.GT_GetPrfPos(AXIS_Y, out prfPos[1],1,out clk);
		
                Console.WriteLine("数据表1={0},时间1={1},规划速度1={2},规划位置1={3},数据表2={0},时间2={1},规划速度2={2},规划位置2={3}\n",
                    tableId[0], time[0], prfVel[0], prfPos[0], tableId[1], time[1], prfVel[1], prfPos[1]);

                System.Threading.Thread.Sleep(100);//降低控制台刷新速率
	        }
	        
        }
    }
}
