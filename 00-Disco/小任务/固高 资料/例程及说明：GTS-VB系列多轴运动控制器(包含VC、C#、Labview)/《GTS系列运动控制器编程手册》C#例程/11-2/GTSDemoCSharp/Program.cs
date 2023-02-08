using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GTSDemoCSharp
{
    // 例程 11-2 电机到位检测功能
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
        const short AXIS_X = 1;
        const short AXIS_Y = 2;

        static void Main(string[] args)
        {
            short sRtn;
            gts.mc.TPid pid;
            gts.mc.TTrapPrm trap;
            int sts;
            int posX, posY;
            double prfPos, prfVel;

            uint clk;

            // 打开运动控制器
            sRtn = gts.mc.GT_Open(0,1);
            commandhandler("GT_Open", sRtn);
            // 复位控制器
            sRtn = gts.mc.GT_Reset();
            commandhandler("GT_Reset", sRtn);
            // 配置运动控制器为伺服模式
            sRtn = gts.mc.GT_LoadConfig("GT800_test.cfg");
            commandhandler("GT_LoadConfig", sRtn);
            // 延时一段时间
            System.Threading.Thread.Sleep(100);
            // 清除各轴的报警和限位
            sRtn = gts.mc.GT_ClrSts(1, 8);
            commandhandler("GT_ClrSts", sRtn);
            // 读取X轴PID参数
            sRtn = gts.mc.GT_GetPid(AXIS_X, 1, out pid);
            commandhandler("GT_GetPid", sRtn);
            pid.kp = 10;
            // 更新X轴PID参数
            sRtn = gts.mc.GT_SetPid(AXIS_X, 1, ref pid);
            commandhandler("GT_SetPid", sRtn);
            // 读取Y轴PID参数
            sRtn = gts.mc.GT_GetPid(AXIS_Y, 1, out pid);
            commandhandler("GT_GetPid", sRtn);
            pid.kp = 10;
            // 更新Y轴PID参数
            sRtn = gts.mc.GT_SetPid(AXIS_Y, 1, ref pid);
            commandhandler("GT_SetPid", sRtn);
            // X轴伺服使能
            sRtn = gts.mc.GT_AxisOn(AXIS_X);
            commandhandler("GT_AxisOn", sRtn);
            // Y轴伺服使能
            sRtn = gts.mc.GT_AxisOn(AXIS_Y);
            commandhandler("GT_AxisOn", sRtn);
            // 延时一段时间，等待伺服稳定
            System.Threading.Thread.Sleep(200);
            // 位置清零, 并进行自动零漂补偿
            sRtn = gts.mc.GT_ZeroPos(AXIS_X,1);
            commandhandler("GT_ZeroPos", sRtn);
            // 设置X轴到位误差带
            sRtn = gts.mc.GT_SetAxisBand(AXIS_X, 20, 5);
            commandhandler("GT_SetAxisBand", sRtn);
            // 位置清零, 并进行自动零漂补偿
            sRtn = gts.mc.GT_ZeroPos(AXIS_Y,1);
            commandhandler("GT_ZeroPos", sRtn);
            // 设置Y轴到位误差带
            sRtn = gts.mc.GT_SetAxisBand(AXIS_Y, 20, 5);
            commandhandler("GT_SetAxisBand", sRtn);
            // X轴设为点位模式
            sRtn = gts.mc.GT_PrfTrap(AXIS_X);
            commandhandler("GT_PrfTrap", sRtn);
            // 读取X轴点位运动参数
            sRtn = gts.mc.GT_GetTrapPrm(AXIS_X, out trap);
            commandhandler("GT_GetTrapPrm", sRtn);
            trap.acc = 1;
            trap.dec = 0.5;
            // 设置X轴点位运动参数
            sRtn = gts.mc.GT_SetTrapPrm(AXIS_X, ref trap);
            commandhandler("GT_SetTrapPrm", sRtn);
            // 设置X轴的目标速度
            sRtn = gts.mc.GT_SetVel(AXIS_X, 10);
            commandhandler("GT_SetVel", sRtn);
            // Y轴设为点位模式
            sRtn = gts.mc.GT_PrfTrap(AXIS_Y);
            commandhandler("GT_PrfTrap", sRtn);
            // 读取Y轴点位运动参数
            sRtn = gts.mc.GT_GetTrapPrm(AXIS_Y, out trap);
            commandhandler("GT_GetTrapPrm", sRtn);
            trap.acc = 1;
            trap.dec = 0.5;
            // 设置Y轴点位运动参数
            sRtn = gts.mc.GT_SetTrapPrm(AXIS_Y, ref trap);
            commandhandler("GT_SetTrapPrm", sRtn);
            // 设置Y轴的目标速度
            sRtn = gts.mc.GT_SetVel(AXIS_Y, 10);
            commandhandler("GT_SetVel", sRtn);

            posX = 10000;
            posY = 20000;

            while (true)
            {
                //有按键输入退出循环
                if (System.Console.KeyAvailable)
                    break;

                // 设置X轴目标位置
                sRtn = gts.mc.GT_SetPos(AXIS_X, posX);
                commandhandler("GT_SetPos", sRtn);
                // 启动X轴的运动
                sRtn = gts.mc.GT_Update(1 << (AXIS_X - 1));
                commandhandler("GT_Update", sRtn);

                posX = -posX;

                // 等待X轴进入误差带
                do
                {
                    gts.mc.GT_GetSts(AXIS_X, out sts,1,out clk);
                    gts.mc.GT_GetPrfPos(AXIS_X, out prfPos,1,out clk);
                    gts.mc.GT_GetPrfVel(AXIS_X, out prfVel,1,out clk);
                    Console.WriteLine("x pos={0} vel={1}\r", prfPos, prfVel);

                    System.Threading.Thread.Sleep(100);//降低控制台刷新速率

                } while (0x800 != (sts & 0x800));

                Console.WriteLine("\n");
                // 设置Y轴目标位置
                sRtn = gts.mc.GT_SetPos(AXIS_Y, posY);
                commandhandler("GT_SetPos", sRtn);
                // 启动Y轴的运动
                sRtn = gts.mc.GT_Update(1 << (AXIS_Y - 1));
                commandhandler("GT_Update", sRtn);

                posY = -posY;
                // 等待Y轴进入误差带
                do
                {
                    gts.mc.GT_GetSts(AXIS_Y, out sts,1,out clk);
                    gts.mc.GT_GetPrfPos(AXIS_Y, out prfPos,1,out clk);
                    gts.mc.GT_GetPrfVel(AXIS_Y, out prfVel,1,out clk);
                    Console.WriteLine("x pos={0} vel={1}\r", prfPos, prfVel);

                    System.Threading.Thread.Sleep(100);//降低控制台刷新速率

                } while (0x800 != (sts & 0x800));
                Console.WriteLine("\n");

                Console.ReadLine();//持续显示控制台屏幕等待退出
            }

            
        }
    }
}
