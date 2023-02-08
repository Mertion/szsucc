using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GTSDemoCSharp
{
    //例程 11-1 读取运动控制器版本号
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
            short sRtn;
            string pVersion;							// 定义指向版本号字符串的指针

            // 打开运动控制器
            sRtn = gts.mc.GT_Open(0,1);
            // 指令返回值检测，请查阅例2-1
            commandhandler("GT_Open", sRtn);
            // 系统复位
            sRtn = gts.mc.GT_Reset();
            commandhandler("GT_Reset", sRtn);
            sRtn = gts.mc.GT_GetVersion(out pVersion);			// 读取版本号
            commandhandler("GT_GetVersion", sRtn);
            Console.WriteLine("版本号为:{0}", pVersion);
            sRtn = gts.mc.GT_Close();
            commandhandler("GT_Close", sRtn);

            Console.ReadLine();
        }
    }
}
