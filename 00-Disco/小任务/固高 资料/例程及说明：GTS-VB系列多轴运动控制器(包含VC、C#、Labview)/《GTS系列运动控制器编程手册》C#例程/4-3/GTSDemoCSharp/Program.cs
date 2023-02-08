using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GTSDemoCSharp
{
    // 例程 4-3 设置第1轴为脉冲控制"脉冲+方向"方式
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

        static void Main(string[] args)
        {
            // 指令返回值变量
            short sRtn;
            // 打开运动控制器
            sRtn = gts.mc.GT_Open(0,1);
            // 指令返回值检测，请查阅例2-1
            commandhandler("GT_Open", sRtn);
            // 系统复位
            sRtn = gts.mc.GT_Reset();
            commandhandler("GT_Reset", sRtn);
            // 配置轴1脉冲输出方式为脉冲+方向
            sRtn = gts.mc.GT_StepDir(1);
            commandhandler("GT_StepDir", sRtn);
            // 配置轴1报警输出无效
            sRtn = gts.mc.GT_AlarmOff(1);
            commandhandler("GT_AlarmOff", sRtn);
            // 配置轴1正负限位无效
            sRtn = gts.mc.GT_LmtsOff(1, -1);
            commandhandler("GT_LmtsOff", sRtn);
            // 配置完成后要更新状态
            sRtn = gts.mc.GT_ClrSts(1,1);
            commandhandler("GT_ClrSts", sRtn);
            // 轴1伺服使能
            sRtn = gts.mc.GT_AxisOn(1);
            commandhandler("GT_AxisOn", sRtn);

            Console.ReadLine();
        }
    }
}
