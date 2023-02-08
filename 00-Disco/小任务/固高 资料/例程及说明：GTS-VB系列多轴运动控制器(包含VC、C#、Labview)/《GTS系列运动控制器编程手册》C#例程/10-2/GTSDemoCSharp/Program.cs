using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GTSDemoCSharp
{
    //例程10-2 运动程序多线程累加求和
    class Program
    {
        static void Main(string[] args)
        {
            short rtn;
            //gts.mc.TCompileInfo compile;
            short funId;
            gts.mc.TVarInfo sum, begin, end;
            double value;
            gts.mc.TThreadSts thread;

            // 打开运动控制器
            rtn = gts.mc.GT_Open(0,1);
            Console.WriteLine("GT_Open()={0}\n", rtn);

            // 复位运动控制器
            rtn = gts.mc.GT_Reset();
            Console.WriteLine("GT_Reset()={0}\n", rtn); 

            // 编译运动程序sum.c
            // 编译成功以后生成sum.bin和sum.ini
            // 必须保证error.ini文件位于工程文件夹中
            //rtn = gts.mc.GT_Compile("sum.c", &compile);
            //Console.WriteLine("GT_Compile()={0}\n", rtn);

            // 下载运动程序sum.bin
            rtn = gts.mc.GT_Download("sum.bin");
            Console.WriteLine("GT_Download()={0}\n", rtn);

            // 获取函数ID
            rtn = gts.mc.GT_GetFunId("add", out funId);
            Console.WriteLine("GT_GetFunId()={0}\n", rtn);

            // 获取全局变量sum的ID
            rtn = gts.mc.GT_GetVarId(null, "sum", out sum);
            Console.WriteLine("GT_GetVarId()={0}\n", rtn);

            // 获取局部变量begin的ID
            rtn = gts.mc.GT_GetVarId("add", "begin", out begin);
            Console.WriteLine("GT_GetVarId()={0}\n", rtn);

            // 获取局部变量end的ID
            rtn = gts.mc.GT_GetVarId("add", "end", out end);
            Console.WriteLine("GT_GetVarId()={0}\n", rtn);

            // 绑定线程，函数，数据页
            rtn = gts.mc.GT_Bind(0, funId, 0);
            Console.WriteLine("GT_Bind()={0}\n", rtn);
            // 绑定线程，函数，数据页
            rtn = gts.mc.GT_Bind(1, funId, 1);
            Console.WriteLine("GT_Bind()={0}\n", rtn);

            value = 0;
            // 初始化运动程序的全局变量sum
            rtn = gts.mc.GT_SetVarValue(-1, ref sum,ref value,1);
            Console.WriteLine("GT_SetVarValue()={0}\n", rtn);

            value = 1;
            // 初始化运动程序的局部变量begin
            rtn = gts.mc.GT_SetVarValue(0, ref begin, ref value,1);
            Console.WriteLine("GT_SetVarValue()={0}\n", rtn); 

            value = 50;
            // 初始化运动程序的局部变量end
            rtn = gts.mc.GT_SetVarValue(0, ref end, ref value,1);
            Console.WriteLine("GT_SetVarValue()={0}\n", rtn);

            value = 51;
            // 初始化运动程序的局部变量begin
            rtn = gts.mc.GT_SetVarValue(1, ref begin, ref value, 1);
            Console.WriteLine("GT_SetVarValue()={0}\n", rtn);

            value = 100;
            // 初始化运动程序的局部变量end
            rtn = gts.mc.GT_SetVarValue(1, ref end, ref value, 1);
            Console.WriteLine("GT_SetVarValue()={0}\n", rtn); 
            // 启动线程
            rtn = gts.mc.GT_RunThread(0);
            Console.WriteLine("GT_RunThread()={0}\n", rtn);
            // 启动线程
            rtn = gts.mc.GT_RunThread(1);
            Console.WriteLine("GT_RunThread()={0}\n", rtn); 

            do
            {
                // 查询线程状态
                rtn = gts.mc.GT_GetThreadSts(0, out thread);
                Console.WriteLine("GT_GetThreadSts()={0}\n", rtn); 
            } while (1 == thread.run);	// 等待线程运行结束

            do
            {
                // 查询线程状态
                rtn = gts.mc.GT_GetThreadSts(1, out thread);
                Console.WriteLine("GT_GetThreadSts()={0}\n", rtn); 
            } while (1 == thread.run);

            // 查询全局变量sum的值
            rtn = gts.mc.GT_GetVarValue(-1, ref sum, out value, 1);
            Console.WriteLine("sum={0}\n", value); 

            Console.ReadLine();
        }
    }
}
