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
    //例程6-4 PT动态FIFO
    public partial class Form1 : Form
    {
        short axis;//当前轴号
        bool[] en = new bool[8];//各轴的伺服使能状态
        uint clk;//时钟参数
        double prfvel, encvel, prfpos, encpos;//运动状态参数

        bool ptState;//PT状态，true表示执行PT运动，false表示不执行PT运动
        double pos, vel, velPre, time;
        short start,loop;
        const short A = 50;//正弦曲线幅值
        const short T = 1;//正弦曲线周期
        const double DELTA = 0.016;//正弦曲线时间段
        const short LOOP = 2;//正弦曲线循环次数
        const double PI = 3.1415926;//圆周率
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
            gts.mc.GT_Open(0, 1);//打开运动控制卡

            //控件和变量初始化
            this.comboBox1.SelectedIndex = 0;
            ptState = false;

            //启动定时器刷新状态
            timer1.Start();
        }
        /// <summary>
        /// 初始化
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button1_Click(object sender, EventArgs e)
        {
            gts.mc.GT_LoadConfig("GT800_test.cfg");//下载配置文件
            gts.mc.GT_ClrSts(1, 8);//清除各轴报警和限位

            gts.mc.GT_PrfPt(axis,gts.mc.PT_MODE_DYNAMIC);//设置动态PT运动模式
            gts.mc.GT_PtClear(axis,0);//清空FIFO
        }
        /// <summary>
        /// 位置清零
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button2_Click(object sender, EventArgs e)
        {
            gts.mc.GT_ZeroPos(1, 8);
        }
        /// <summary>
        /// 伺服使能
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button3_Click(object sender, EventArgs e)
        {
            axis = Convert.ToInt16(this.comboBox1.SelectedIndex + 1);
            if (!en[axis - 1])
            {
                gts.mc.GT_AxisOn(axis);//上伺服
                this.button3.Text = "伺服关闭";
            }
            if (en[axis - 1])
            {
                gts.mc.GT_AxisOff(axis);//下伺服
                this.button3.Text = "伺服使能";
            }
            en[axis - 1] = !en[axis - 1];
        }
        /// <summary>
        /// 复位
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button4_Click(object sender, EventArgs e)
        {
            gts.mc.GT_Reset();
        }
        /// <summary>
        /// 运动状态刷新
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void timer1_Tick(object sender, EventArgs e)
        {
            axis = Convert.ToInt16(this.comboBox1.SelectedIndex + 1);//读取轴号

            if (!en[Convert.ToInt32(this.comboBox1.Text) - 1])
            {
                this.button3.Text = "伺服使能";
            }
            if (en[Convert.ToInt32(this.comboBox1.Text) - 1])
            {
                this.button3.Text = "伺服关闭";
            }
            
            //读取规划速度并显示
            gts.mc.GT_GetPrfVel(axis, out prfvel, 1, out clk);
            this.textBox1.Text = Math.Round(prfvel, 6).ToString();
            //读取规划位置并显示
            gts.mc.GT_GetPrfPos(axis, out prfpos, 1, out clk);
            this.textBox2.Text = Math.Round(prfpos, 1).ToString();
            //读取实际速度并显示
            gts.mc.GT_GetEncVel(axis, out encvel, 1, out clk);
            this.textBox3.Text = Math.Round(encvel, 6).ToString();
            //读取实际位置并显示
            gts.mc.GT_GetEncPos(axis, out encpos, 1, out clk);
            this.textBox4.Text = Math.Round(encpos, 1).ToString();

            //动态PT，压入正弦曲线速度规划数据，并启动PT运动
            if(ptState)
            {
                short space;
                gts.mc.GT_PtSpace(axis, out space, 0);// 查询PT模式FIFO的剩余空间
                if (space > 0)
                {
                    time += DELTA;
                    // 计算段末速度
                    vel = A * Math.Sin((2 * PI) / T * time);
                    // 计算段内位移
                    pos += 1000 * (vel + velPre) * DELTA / 2;
                    velPre = vel;
                    if (time < loop * T)
                    {
                        // 发送新数据
                        gts.mc.GT_PtData(axis, pos, (int)(time * 1000),gts.mc.PT_SEGMENT_NORMAL,0);
                    }
                    else
                    {
                        // 发送终点数据
                        gts.mc.GT_PtData(axis, 0, (int)(loop * T * 1000), gts.mc.PT_SEGMENT_STOP, 0);
                        pos = 0;
                        time = loop * T;
                        velPre = 0;
                        ++loop;
                        if (loop > LOOP)
                        {
                            ptState=false;
                        }
                    }
                }
                else if (start == 0)
                {
                    gts.mc.GT_PtStart(1<<(axis-1),0);//启动PT运动
                    start = 1;
                }
            }
        }
        /// <summary>
        /// 停止运动
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button5_Click(object sender, EventArgs e)
        {
            gts.mc.GT_Stop(1 << (axis - 1), 0);
        }
        /// <summary>
        /// 执行PT运动
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button6_Click(object sender, EventArgs e)
        {
            ptState = true;
            pos = 0;
            time = 0;
            start = 0;
            loop = 0;
        }

        
    }
}
