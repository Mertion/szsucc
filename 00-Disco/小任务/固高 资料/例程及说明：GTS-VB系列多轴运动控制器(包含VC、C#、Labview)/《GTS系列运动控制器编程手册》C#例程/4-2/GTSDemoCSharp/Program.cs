using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GTSDemoCSharp
{
    // 例程 4-2 修改限位开关触发电平
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
	        // 状态值变量
	        ushort sValue;

	        sRtn = gts.mc.GT_Open(0,1);
	        // 指令返回值校验
	        commandhandler("GT_Open", sRtn);
            sRtn = gts.mc.GT_Reset();
	        // 指令返回值校验
	        commandhandler("GT_Reset", sRtn);

	        // 初始化使所有位都为0
	        sValue = 0;
	        // 使第0, 1位为1，即轴1正负限位所对应的位
	        sValue |= 0x3;
	        // 使第6, 7位为1，即轴4正负限位所对应的位
	        sValue |= 1<<6;
	        sValue |= 1<<7;
	        // 设置限位开关触发电平
            sRtn = gts.mc.GT_LmtSns(sValue);
	        // 指令返回值校验
	        commandhandler("GT_LmtSns", sRtn);

        }
    }
}
