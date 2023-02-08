using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GTSDemoCSharp
{
    // 例程 4-4 设置第1轴为闭环控制方式
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
            // PID结构体变量
            gts.mc.TPid pid;
            // 打开运动控制器
            sRtn = gts.mc.GT_Open(0,1);
            // 指令返回值检测，请查阅例2-1
            commandhandler("GT_Open", sRtn);
            // 系统复位
            sRtn = gts.mc.GT_Reset();
            commandhandler("GT_Reset", sRtn);
            // 配置轴1为模拟量输出模式
            sRtn = gts.mc.GT_CtrlMode(1, 0);
            commandhandler("GT_CtrlMode", sRtn);
            // 配置轴1报警输出无效
            sRtn = gts.mc.GT_AlarmOff(1);
            commandhandler("GT_AlarmOff", sRtn);
            // 配置轴1正负限位无效
            sRtn = gts.mc.GT_LmtsOff(1, -1);
            commandhandler("GT_LmtsOff", sRtn);
            // 配置完成后要更新状态
            sRtn = gts.mc.GT_ClrSts(1,1);
            commandhandler("GT_ClrSts", sRtn);
            // 获取当前pid参数
            sRtn = gts.mc.GT_GetPid(1, 1, out pid);
            commandhandler("GT_GetPid", sRtn);
            // 调试阶段，只需修改一下kp到一个较小的值
            pid.kp = 1;
            // 设置PID参数
            sRtn = gts.mc.GT_SetPid(1, 1, ref pid);
            commandhandler("GT_SetPid", sRtn);
            // 轴1伺服使能
            sRtn = gts.mc.GT_AxisOn(1);
            commandhandler("GT_AxisOn", sRtn);
            // 伺服使能后若出现飞车，则需要通过调用GT_EncSns()指令来修改编码器计数方向
            // 等待伺服稳定
            System.Threading.Thread.Sleep(200);

            Console.ReadLine();
        }
    }
}
