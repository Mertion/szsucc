using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


namespace GTSDemoCSharp
{
    //例程 6-18 Complete描述方式
    class Program
    {
        const short AXIS = 1;
        const short TABLE1 = 1;
        const short TABLE2 = 2;
        const double PI = 3.1415926;
        
        // 该函数检测某条GT指令的执行结果，command为指令名称，error为指令执行返回值
        static void commandhandler(string command, short error)
        {
            // 如果指令执行返回值为非0，说明指令执行错误，向屏幕输出错误结果
            if (error!=0)
            {
                Console.WriteLine("{0}={1}\n",command,error);
            }
        }
        static void Calculate(double amplitude, long n, double[] pTime, double[] pPos)
        {
            long i;
            for (i = 0; i < n; ++i)
            {
                pPos[i] = amplitude * Math.Sin(PI / 2000 * pTime[i]) * Math.Sin(PI / 2000 * pTime[i]);
            }
        }
        static void Main(string[] args)
        {
            short sRtn;
	        int mask;
	        // X轴的数据点参数
	        double[] time=new double[5]{0, 500, 1000, 1500, 2000};
	        double[] pos=new double[5]{0,0,0,0,0};
            double[] a = new double[5] { 0, 0, 0, 0, 0 };
            double[] b = new double[5] { 0, 0, 0, 0, 0 };
            double[] c = new double[5] { 0, 0, 0, 0, 0 };
	        double prfVel, prfPos, t;
	        short tableId;
	        double amplitude = 40000;
	        short table = TABLE1;
            uint clk;
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
	        Calculate(amplitude, 5, time, pos);
	        // 发送数据
            sRtn = gts.mc.GT_PvtTableComplete(table, 5, ref time[0], ref pos[0], ref a[0], ref b[0], ref c[0], 0, 0);
	        commandhandler("GT_PvtTableComplete", sRtn);
	        // 选择数据表
            sRtn = gts.mc.GT_PvtTableSelect(AXIS, table);
	        commandhandler("GT_PvtTableSelect", sRtn);
	        // 设置为循环执行
            sRtn = gts.mc.GT_SetPvtLoop(AXIS, 0);
	        commandhandler("GT_SetPvtLoop", sRtn);
	        mask = 1<<(AXIS-1);
            sRtn = gts.mc.GT_PvtStart(mask);
	        commandhandler("GT_PvtStart", sRtn);

            ConsoleKeyInfo ki = new ConsoleKeyInfo();//获取按键

	        while(true)
	        {
                //有按键输入
                if (System.Console.KeyAvailable)
                {
                    ki = Console.ReadKey(true);
                }

		        // 读取数据表和运动时间
                sRtn = gts.mc.GT_PvtStatus(AXIS, out tableId, out t,1);
		        // 读取规划速度
                sRtn = gts.mc.GT_GetPrfVel(AXIS, out prfVel,1,out clk);
		        // 读取规划位置
                sRtn = gts.mc.GT_GetPrfPos(AXIS, out prfPos,1,out clk);
                
		        if( ki!=null)
		        {
			        if( ki.Key==ConsoleKey.A )
			        {
				        amplitude *= 1.5;
			        }
                    if (ki.Key == ConsoleKey.B)
			        {
				        amplitude *= 0.5;	
			        }
                    if ((ki.Key == ConsoleKey.A) || (ki.Key==ConsoleKey.B))
			        {
				        Calculate(amplitude, 5, time, pos);
                        table = (short)(TABLE1 + TABLE2 - tableId);
				        // 发送数据
                        sRtn = gts.mc.GT_PvtTableComplete(table, 5, ref time[0], ref pos[0], ref a[0], 
						        ref b[0], ref c[0], 0, 0);
				        if( 0 != sRtn )
				        {
					        commandhandler("GT_PvtTableComplete", sRtn);
                            Environment.Exit(0);
				        }
				        // 选择数据表
                        sRtn = gts.mc.GT_PvtTableSelect(AXIS, table);
				        if( 0 != sRtn )
				        {
					        commandhandler("\nGT_PvtTableSelect", sRtn);
                            Environment.Exit(0);
				        }
			        }

                    if (ki.Key == ConsoleKey.Q)
			        {
				        mask = 1 << (AXIS-1);
                        sRtn = gts.mc.GT_Stop(mask, 0);
                        Environment.Exit(0);
			        }
		        }
                Console.WriteLine("数据表ID={0},时间={1},规划速度={2},规划位置={3}\n", tableId, t, prfVel, prfPos);

                System.Threading.Thread.Sleep(100);//降低控制台刷新速率
	        }
        }
    }
}
