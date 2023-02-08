using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace GTSDemoCSharp
{
    //例程6-9~16 插补运动
    public partial class Form1 : Form
    {

        bool[] en = new bool[8];//各轴的伺服使能状态
        uint clk;//时钟参数

        public Form1()
        {
            InitializeComponent();
        }
        /// <summary>
        /// 界面加载
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Form1_Load(object sender, EventArgs e)
        {
            //按钮状态
            BUTTON_INITIAL_COORDINATE.Enabled = false;
            BUTTON_LINEAR_MOTION.Enabled = false;
            BUTTON_ARC_MOTION.Enabled = false;
            BUTTON_LOOK_AHEAD.Enabled = false;
            BUTTON_BUF_GEAR.Enabled = false;
            BUTTON_FIFO_MANAGE.Enabled = false;
            BUTTON_BUF_MOVE.Enabled = false;
            BUTTON_REAL_MACHINING.Enabled = false;

            //启动定时器刷新状态
            timer1.Start();
        }
        /// <summary>
        /// 运动状态刷新
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void timer1_Tick(object sender, EventArgs e)
        {
            short sRtn;
            double[] prfPos=new double[3];
	        short run;
	        int segment;

            sRtn=gts.mc.GT_GetPrfPos(1, out prfPos[0], 3, out clk);       // 读1~3轴的规划位置
            sRtn = gts.mc.GT_CrdStatus(1, out run, out segment, 0);          // 读取坐标系运动状态

            //X轴规划位置
            this.textBox_PrfPos1.Text = Math.Round(prfPos[0], 1).ToString();
            //Y轴规划位置
            this.textBox_PrfPos2.Text = Math.Round(prfPos[1], 1).ToString();
            //Z轴规划位置
            this.textBox_PrfPos3.Text = Math.Round(prfPos[2], 1).ToString();
            //坐标系运动状态
            if(run==1)
                this.textBox_CrdStatus.Text = "运动";
            else if(run==0)
                this.textBox_CrdStatus.Text = "静止";
            //Z轴规划位置
            this.textBox_Segment.Text = segment.ToString();

        }
        /// <summary>
        /// 初始化
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BUTTON_INITIAL_Click(object sender, EventArgs e)
        {
            short sRtn;
            sRtn = gts.mc.GT_Open(0,1);                             // 打开运动控制器
            sRtn = gts.mc.GT_Reset();                            // 复位运动控制器
            sRtn = gts.mc.GT_LoadConfig("GT800_test.cfg");       // 下载控制器配置文件
            sRtn = gts.mc.GT_ClrSts(1, 4);                       // 清除1~4轴的轴状态

            for (short i = 1; i <= 4; ++i)
            {
                sRtn = gts.mc.GT_AxisOn(i);                      // 使能运动轴
            }
            //按钮状态
            BUTTON_INITIAL_COORDINATE.Enabled = true;

        }
        /// <summary>
        /// 例程 5-9 建立坐标系
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BUTTON_INITIAL_COORDINATE_Click(object sender, EventArgs e)
        {
            short sRtn;
            gts.mc.TCrdPrm crdPrm;

            crdPrm.dimension = 3;                        // 建立三维的坐标系
            crdPrm.synVelMax = 500;                      // 坐标系的最大合成速度是: 500 pulse/ms
            crdPrm.synAccMax = 2;                        // 坐标系的最大合成加速度是: 2 pulse/ms^2
            crdPrm.evenTime = 0;                         // 坐标系的最小匀速时间为0
            crdPrm.profile1 = 1;                       // 规划器1对应到X轴                       
            crdPrm.profile2 = 2;                       // 规划器2对应到Y轴
            crdPrm.profile3 = 3;                       // 规划器3对应到Z轴
            crdPrm.profile4 = 0;
            crdPrm.profile5 = 0;
            crdPrm.profile6 = 0;
            crdPrm.profile7 = 0;
            crdPrm.profile8 = 0;
            crdPrm.setOriginFlag = 1;                    // 需要设置加工坐标系原点位置
            crdPrm.originPos1 = 0;                     // 加工坐标系原点位置在(0,0,0)，即与机床坐标系原点重合
            crdPrm.originPos2 = 0;
            crdPrm.originPos3 = 0;
            crdPrm.originPos4 = 0;
            crdPrm.originPos5 = 0;
            crdPrm.originPos6 = 0;
            crdPrm.originPos7 = 0;
            crdPrm.originPos8 = 0;

            sRtn = gts.mc.GT_SetCrdPrm(1, ref crdPrm);
            
            //按钮状态
            BUTTON_LINEAR_MOTION.Enabled = true;
            BUTTON_ARC_MOTION.Enabled = true;
            BUTTON_LOOK_AHEAD.Enabled = true;
            BUTTON_BUF_GEAR.Enabled = true;
            BUTTON_FIFO_MANAGE.Enabled = true;
            BUTTON_BUF_MOVE.Enabled = true;
            BUTTON_REAL_MACHINING.Enabled = true;

        }
        /// <summary>
        /// 停止运动
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BUTTON_CLOSE_Click(object sender, EventArgs e)
        {
            for (int i = 1; i <=4;++i )
                gts.mc.GT_Stop(1 << (i- 1), 0);//停止运动1~4轴
        }
        /// <summary>
        /// 例程 5-10 直线插补例程
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BUTTON_LINEAR_MOTION_Click(object sender, EventArgs e)
        {
            short sRtn;// 指令返回值变量

            // 即将把数据存入坐标系1的FIFO0中，所以要首先清除此缓存区中的数据
            sRtn = gts.mc.GT_CrdClear(1, 0);
            // 向缓存区写入第一段插补数据
            sRtn = gts.mc.GT_LnXY(
                1,				// 该插补段的坐标系是坐标系1
                200000, 0,		// 该插补段的终点坐标(200000, 0)
                100,				// 该插补段的目标速度：100pulse/ms
                0.1,				// 插补段的加速度：0.1pulse/ms^2
                0,				// 终点速度为0
                0);				// 向坐标系1的FIFO0缓存区传递该直线插补数据

            // 向缓存区写入第二段插补数据
            sRtn = gts.mc.GT_LnXY(1, 100000, 173205, 100, 0.1, 0, 0);
            // 缓存区数字量输出
            sRtn = gts.mc.GT_BufIO(
                1,				// 坐标系是坐标系1
                (ushort)gts.mc.MC_GPO,		// 数字量输出类型：通用输出
                0xffff,			// bit0~bit15全部都输出
                0x55,			// 输出的数值为0x55
                0);				// 向坐标系1的FIFO0缓存区传递该数字量输出
            // 第三段插补数据
            sRtn = gts.mc.GT_LnXY(1, -100000, 173205, 100, 0.1, 0, 0);
            // 缓存区数字量输出
            sRtn = gts.mc.GT_BufIO(1, (ushort)gts.mc.MC_GPO, 0xffff, 0xaa, 0);
            // 第四段插补数据
            sRtn = gts.mc.GT_LnXY(1, -200000, 0, 100, 0.1, 0, 0);
            // 缓存区延时指令
            sRtn = gts.mc.GT_BufDelay(
                1,				// 坐标系是坐标系1
                400,				// 延时400ms
                0);				// 向坐标系1的FIFO0缓存区传递该延时
            // 第五段插补数据
            sRtn = gts.mc.GT_LnXY(1, -100000, -173205, 100, 0.1, 0, 0);
            // 缓存区数字量输出
            sRtn = gts.mc.GT_BufIO(1, (ushort)gts.mc.MC_GPO, 0xffff, 0x55, 0);
            // 缓存区延时指令
            sRtn = gts.mc.GT_BufDelay(1, 100, 0);
            // 第六段插补数据
            sRtn = gts.mc.GT_LnXY(1, 100000, -173205, 100, 0.1, 0, 0);
            // 第七段插补数据
            sRtn = gts.mc.GT_LnXY(1, 200000, 0, 100, 0.1, 0, 0);

            // 启动坐标系1的FIFO0的插补运动
            sRtn = gts.mc.GT_CrdStart(1, 0); 
        }
        /// <summary>
        /// 例程 5-11 圆弧插补例程
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BUTTON_ARC_MOTION_Click(object sender, EventArgs e)
        {
            // 指令返回值变量
            short sRtn;
            // 即将把数据存入坐标系1的FIFO0中，所以要首先清除此缓存区中的数据
            sRtn = gts.mc.GT_CrdClear(1, 0);
            // 向缓存区写入第一段插补数据
            sRtn = gts.mc.GT_LnXY(
                1,					// 该插补段的坐标系是坐标系1
                200000, 0,			// 该插补段的终点坐标(200000, 0)
                100,					// 该插补段的目标速度：100pulse/ms
                0.1,					// 插补段的加速度：0.1pulse/ms^2
                0,					// 终点速度为0
                0);					// 向坐标系1的FIFO0缓存区传递该直线插补数据

            // 向缓存区写入第二段插补数据，该段数据是以圆心描述方法描述了一个整圆
            sRtn = gts.mc.GT_ArcXYC(
                1,					// 坐标系是坐标系1
                200000, 0,			// 该圆弧的终点坐标(200000, 0)
                -100000, 0,			// 圆弧插补的圆心相对于起点位置的偏移量(-100000, 0)
                0,					// 该圆弧是顺时针圆弧
                100,					// 该插补段的目标速度：100pulse/ms
                0.1,					// 该插补段的加速度：0.1pulse/ms^2
                0,					// 终点速度为0
                0);					// 向坐标系1的FIFO0缓存区传递该直线插补数据

            // 向缓存区写入第三段插补数据，该段数据是以半径描述方法描述了一个1/4圆弧
            sRtn = gts.mc.GT_ArcXYR(
                1,					// 坐标系是坐标系1
                0, 200000,			// 该圆弧的终点坐标(0, 200000)
                200000,				// 半径：200000pulse
                1,					// 该圆弧是逆时针圆弧
                100,					// 该插补段的目标速度：100pulse/ms
                0.1,					// 该插补段的加速度：0.1pulse/ms^2
                0,					// 终点速度为0
                0);					// 向坐标系1的FIFO0缓存区传递该直线插补数据

            // 向缓存区写入第四段插补数据，回到原点位置
            sRtn = gts.mc.GT_LnXY(1, 0, 0, 100, 0.1, 0, 0);

            // 启动坐标系1的FIFO0的插补运动
            sRtn = gts.mc.GT_CrdStart(1, 0);
        }
        /// <summary>
        /// 例程 5-13 前瞻预处理例程
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BUTTON_LOOK_AHEAD_Click(object sender, EventArgs e)
        {
            // 指令返回值
            short sRtn; 
            int space;
            // 定义前瞻缓存区内存区
	        gts.mc.TCrdData[] crdData=new gts.mc.TCrdData[200] ;
	        int[] posTest=new int[2];

            // 初始化坐标系1的FIFO0的前瞻模块
            sRtn = gts.mc.GT_InitLookAhead(1, 0, 5, 1, 200, ref crdData[0]);
            // 压插补数据：小线段加工
            posTest[0] = 0;
            posTest[1] = 0;
            for (int i = 0; i < 300; ++i)
            {
                sRtn = gts.mc.GT_LnXY(1, 8000 + posTest[0], 9000 + posTest[1], 100, 0.8, 0, 0);
                // 查询返回值是否成功
                if (0 != sRtn)
                {
                    do
                    {
                        // 查询运动缓存区空间，直至空间不为0
                        sRtn = gts.mc.GT_CrdSpace(1, out space, 0);
                    } while (0 == space);
                    // 重新调用上次失败的插补指令
                    sRtn = gts.mc.GT_LnXY(1, 8000 + posTest[0], 9000 + posTest[1], 100, 0.8, 0, 0);
                }
                posTest[0] += 1600;
                posTest[1] += 1852;
            }

            gts.mc.TCrdData crdDataNULL=new gts.mc.TCrdData();
            // 将前瞻缓存区中的数据压入控制器
            sRtn = gts.mc.GT_CrdData(1, ref crdDataNULL, 0);
            // 启动运动
            sRtn = gts.mc.GT_CrdStart(1, 0);
        }
        /// <summary>
        /// 例程 5-15 刀向跟随功能GT_BufGear()
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BUTTON_BUF_GEAR_Click(object sender, EventArgs e)
        {
            // 定义指令返回值变量
            short sRtn;

            // 清除坐标系1的FIFO0中的数据
            sRtn = gts.mc.GT_CrdClear(1, 0);
            // 向FIFO0缓存区写入一段直线插补数据
            sRtn = gts.mc.GT_LnXY(
                1,				// 该插补段的坐标系是坐标系1
                200000, 200000,	// 该插补段的终点坐标(200000, 200000)
                100,				// 该插补段的目标速度：100pulse/ms
                0.1,				// 插补段的加速度：0.1pulse/ms^2
                0,				// 终点速度为0
                0);				// 向坐标系1的FIFO0缓存区传递该直线插补数据
            // 向FIFO0缓存区写入一段跟随运动数据，
            // GT_BufGear()指令需要在所要跟随的插补段前
            sRtn = gts.mc.GT_BufGear(
                1,				// 该插补段的坐标系是坐标系1
                4,				// 跟随运动的轴号：第4轴
                50000,			// 跟随运动的位移量：50000 pulse。这里的位置参数是相对位置。
                0);				// 向坐标系1的FIFO0缓存区传递该直线插补数据
            // 向FIFO0缓存区写入一段直线插补数据
            sRtn = gts.mc.GT_LnXY(1, 200000, 0, 100, 0.1, 0, 0);
            // 向FIFO0缓存区写入一段跟随运动数据
            sRtn = gts.mc.GT_BufGear(
                1,				// 该插补段的坐标系是坐标系1
                4,				// 跟随运动的轴号：第4轴
                50000,			// 跟随运动的位移量：50000 pulse。这里的位置参数是相对位置。
                0);				// 向坐标系1的FIFO0缓存区传递该直线插补数据
            // 向缓存区写入一段圆弧插补数据，该段数据是以圆心描述方法描述了一个半圆
            sRtn = gts.mc.GT_ArcXYC(
                1,				// 坐标系是坐标系1
                -200000, 0,		// 该圆弧的终点坐标(-200000, 0)
                -200000, 0,		// 圆弧插补的圆心相对于起点位置的偏移量(-200000, 0)
                0,				// 该圆弧是顺时针圆弧
                100,				// 该插补段的目标速度：100pulse/ms
                0.1,				// 该插补段的加速度：0.1pulse/ms^2
                0,				// 终点速度为0
                0);				// 向坐标系1的FIFO0缓存区传递该直线插补数据

            // 启动运动
            sRtn = gts.mc.GT_CrdStart(1, 0);
        }
        /// <summary>
        /// 例程 5-12 插补FIFO管理
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BUTTON_FIFO_MANAGE_Click(object sender, EventArgs e)
        {

        }
        /// <summary>
        /// 例程 5-14 刀向跟随功能GT_BufMove()
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BUTTON_BUF_MOVE_Click(object sender, EventArgs e)
        {
            // 定义指令返回值变量
            short sRtn;

            // 清除坐标系1的FIFO0中的数据
            sRtn = gts.mc.GT_CrdClear(1, 0);
            // 向FIFO0缓存区写入一段直线插补数据
            sRtn = gts.mc.GT_LnXY(
                1,					// 该插补段的坐标系是坐标系1
                200000, 200000,		// 该插补段的终点坐标(200000, 200000)
                100,					// 该插补段的目标速度：100pulse/ms
                0.1,					// 插补段的加速度：0.1pulse/ms^2
                0,					// 终点速度为0
                0);					// 向坐标系1的FIFO0缓存区传递该直线插补数据
            // 向FIFO0缓存区写入一段非模态点位运动数据
            sRtn = gts.mc.GT_BufMove(
                1,					// 该插补段的坐标系是坐标系1
                4,					// 点位运动的轴号：第4轴
                50000,				// 点位运动的目标位置：50000 pulse
                30,					// 点位运动的目标速度：30 pulse/ms
                0.1,					// 点位运动的目标加速度：0.1 pulse/(ms*ms)
                0,					// 该点位运动是非模态指令
                0);					// 向坐标系1的FIFO0缓存区传递该直线插补数据
            // 向FIFO0缓存区写入一段直线插补数据
            sRtn = gts.mc.GT_LnXY(1, 200000, 0, 100, 0.1, 0, 0);   // 直线插补指令
            // 向FIFO0缓存区写入一段模态点位运动数据
            sRtn = gts.mc.GT_BufMove(
                1,					// 该插补段的坐标系是坐标系1
                4,					// 点位运动的轴号：第4轴
                100000,				// 点位运动的目标位置：100000 pulse
                30,					// 点位运动的目标速度：30 pulse/ms
                0.1,					// 点位运动的目标加速度：0.1 pulse/(ms*ms)
                1,					// 该点位运动是模态指令
                0);					// 向坐标系1的FIFO0缓存区传递该直线插补数据
            // 向缓存区写入一段圆弧插补数据，该段数据是以圆心描述方法描述了一个半圆
            sRtn = gts.mc.GT_ArcXYC(
                1,					// 坐标系是坐标系1
                -200000, 0,			// 该圆弧的终点坐标(-200000, 0)
                -200000, 0,			// 圆弧插补的圆心相对于起点位置的偏移量(-200000, 0)
                0,					// 该圆弧是顺时针圆弧
                100,					// 该插补段的目标速度：100pulse/ms
                0.1,					// 该插补段的加速度：0.1pulse/ms^2
                0,					// 终点速度为0
                0);					// 向坐标系1的FIFO0缓存区传递该直线插补数据

            // 启动运动
            sRtn = gts.mc.GT_CrdStart(1, 0);
        }
        /// <summary>
        /// 例程 5-16 刀向跟随功能--实际工件加工
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BUTTON_REAL_MACHINING_Click(object sender, EventArgs e)
        {
            // 定义指令返回值变量
            short sRtn;

            // 清除坐标系1的FIFO0中的数据
            sRtn = gts.mc.GT_CrdClear(1, 0);
            // 向FIFO0缓存区写入一段直线插补数据
            sRtn = gts.mc.GT_BufMove(
                1,			// 该插补段的坐标系是坐标系1
                3,			// 点位运动的轴号：第3轴
                500,			// 点位运动的目标位置：500 pulse
                10,			// 点位运动的目标速度：10 pulse/ms
                0.1,			// 点位运动的目标加速度：0.1 pulse/(ms*ms)
                1,			// 该点位运动是模态指令，等砂轮抬高后才执行下面的指令
                0);			// 向坐标系1的FIFO0缓存区传递该直线插补数据
            // 直线插补指令，到达A点
            sRtn = gts.mc.GT_LnXY(1, 6000, 6000, 50, 0.1, 0, 0);
            sRtn = gts.mc.GT_BufMove(
                1,			// 该插补段的坐标系是坐标系1
                4,			// 点位运动的轴号：第4轴
                -1250,		// 使其逆时针旋转45°与BA方向一致
                10,			// 点位运动的目标速度：10 pulse/ms
                0.1,			// 点位运动的目标加速度：0.1 pulse/(ms*ms)
                1,			// 该点位运动是模态指令，等角度到位才后才执行下面的指令
                0);			// 向坐标系1的FIFO0缓存区传递该直线插补数据
            // 模态指令，将砂轮放下到加工高度位置
            sRtn = gts.mc.GT_BufMove(1, 3, -100, 10, 0.1, 1, 0);
            // 直线插补指令，到达B点
            sRtn = gts.mc.GT_LnXY(1, 6000, 12000, 50, 0.1, 0, 0);
            sRtn = gts.mc.GT_BufGear(
                1,			// 该插补段的坐标系是坐标系1
                4,			// 跟随运动的轴号：第4轴
                2500,		// 跟随运动的位移量：2500 pulse（相应为90°）
                0);			// 向坐标系1的FIFO0缓存区传递该直线插补数据
            // 到达C点位置
            sRtn = gts.mc.GT_ArcXYR(
                1,			// 坐标系是坐标系1
                0, 14000,		// 该圆弧的终点坐标(0, 200000)
                8000,		// 半径：8000pulse
                0,			// 该圆弧是顺时针圆弧
                50,			// 该插补段的目标速度：50pulse/ms
                0.1,			// 该插补段的加速度：0.1pulse/ms^2
                0,			// 终点速度为0
                0);			// 向坐标系1的FIFO0缓存区传递该直线插补数据
            // 直线插补指令，到达D点
            sRtn = gts.mc.GT_LnXY(1, 24000, 20000, 50, 0.1, 0, 0);
            // 跟随运动的位移量：2500 pulse（相应为90°）
            sRtn = gts.mc.GT_BufGear(1, 4, 2500, 0);
            // 到达F点
            sRtn = gts.mc.GT_ArcXYR(1, 38000, 6000, 14000, 0, 50, 0.1, 0, 0);
            // 模态指令，将砂轮抬高到安全高度位置
            sRtn = gts.mc.GT_BufMove(1, 3, 500, 10, 0.1, 1, 0);
            // 模态指令，将砂轮抬旋转至与FA方向一致
            //该位置相对初始位置为225°，即目标位置6250
            sRtn = gts.mc.GT_BufMove(1, 4, 6250, 10, 0.1, 1, 0);
            // 模态指令，将砂轮放下到加工高度位置
            sRtn = gts.mc.GT_BufMove(1, 3, -100, 10, 0.1, 1, 0);
            // 直线插补指令，到达A点
            sRtn = gts.mc.GT_LnXY(1, 6000, 6000, 50, 0.1, 0, 0);
            // 启动运动
            sRtn = gts.mc.GT_CrdStart(1, 0);
        }


    }
}
