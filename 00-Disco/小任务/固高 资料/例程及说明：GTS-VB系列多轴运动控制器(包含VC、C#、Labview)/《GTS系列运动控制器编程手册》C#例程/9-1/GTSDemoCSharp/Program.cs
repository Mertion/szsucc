using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GTSDemoCSharp
{
    //例程9-1 软限位使用
    class Program
    {
        const short AXIS = 1;

        static void Main(string[] args)
        {
            // 指令返回值
            short sRtn;
            // 轴状态变量
            int sts;
            // 点位运动结构体变量
            gts.mc.TTrapPrm trap;
            // 规划位置
            double prfPos;

            uint clk;

            // 打开运动控制器
            sRtn = gts.mc.GT_Open(0,1);
            // 复位
            sRtn = gts.mc.GT_Reset();
            // 控制器配置
            sRtn = gts.mc.GT_LoadConfig("GT800_test.cfg");
            // 清除轴状态
            sRtn = gts.mc.GT_ClrSts(1, 8);
            //轴使能
            sRtn = gts.mc.GT_AxisOn(AXIS);
            // 设置软限位
            sRtn = gts.mc.GT_SetSoftLimit(AXIS, 20000, -20000);
            // 将第一轴设置为点位运动模式
            sRtn = gts.mc.GT_PrfTrap(AXIS);
            // 设置点位运动参数
            sRtn = gts.mc.GT_GetTrapPrm(AXIS, out trap);
            trap.acc = 0.125;
            trap.dec = 0.125;
            sRtn = gts.mc.GT_SetTrapPrm(AXIS, ref trap);
            // 设置点位运动目标速度
            sRtn = gts.mc.GT_SetVel(AXIS, 50);
            // 设置点位运动目标位置
            sRtn = gts.mc.GT_SetPos(AXIS, 1000000);
            // 启动点位运动
            sRtn = gts.mc.GT_Update(1 << (AXIS - 1));

            while (true)
            {
                //有按键输入退出循环
                if (System.Console.KeyAvailable)
                    break;

                // 读取第一轴轴状态
                sRtn = gts.mc.GT_GetSts(AXIS, out sts,1,out clk);
                // 读取第一轴规划位置
                sRtn = gts.mc.GT_GetPrfPos(AXIS, out prfPos,1,out clk);
                Console.WriteLine("sts={0} prfPos={1}\r", sts, prfPos);

                System.Threading.Thread.Sleep(100);//降低控制台刷新速率
            }
        }
    }
}
