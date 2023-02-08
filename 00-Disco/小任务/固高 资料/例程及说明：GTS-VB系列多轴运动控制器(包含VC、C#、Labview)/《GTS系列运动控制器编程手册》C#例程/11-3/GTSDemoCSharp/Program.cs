using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GTSDemoCSharp
{
    // 例程 11-3 自动回原点
    class Program
    {
        
        static void Main(string[] args)
        {
            short rtn;
	        ushort sts1, sts2;
            double prfPos1, prfPos2;
            uint clk;
	        rtn = gts.mc.GT_Open(0,1);						// 打开运动控制器
            rtn = gts.mc.GT_Reset();						// 复位运动控制器
            rtn = gts.mc.GT_LoadConfig("GT800_test.cfg");			// 下载配置文件
            rtn = gts.mc.GT_ClrSts(1, 8);					// 清除状态
            rtn = gts.mc.GT_HomeInit();					// 初始化自动回原点功能
            rtn = gts.mc.GT_AxisOn(1);					// 使能轴1
            rtn = gts.mc.GT_AxisOn(2);					// 使能轴2
            rtn = gts.mc.GT_Index(1, 20000, 2000);			// 轴1为Home+Index回零模式
            rtn = gts.mc.GT_Home(1, 200000, 10, 0.5, 2000);
            rtn = gts.mc.GT_Home(2, 200000, 10, 0.5, 3000);	// 轴2为Home回零模式

	        while (true)
	        {
                //有按键输入退出循环
                if (System.Console.KeyAvailable)
                    break;

                rtn = gts.mc.GT_HomeSts(1, out sts1);			// 查询返回状态
                rtn = gts.mc.GT_HomeSts(2, out sts2);
                Console.WriteLine("1轴捕获状态={0} 2轴捕获状态={1}\r", sts1, sts2);

                rtn = gts.mc.GT_GetPrfPos(1, out prfPos1, 1, out clk);
                rtn = gts.mc.GT_GetPrfPos(2, out prfPos2, 1, out clk);
                Console.WriteLine("1轴规划位置={0} 2轴规划位置={1}\r", prfPos1, prfPos2);

                System.Threading.Thread.Sleep(100);//降低控制台刷新速率
	        }

            Console.ReadLine();//持续显示控制台屏幕等待退出
        }
    }
}
