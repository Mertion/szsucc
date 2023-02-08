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
    //例程6-3 PT静态FIFO
    public partial class Form1 : Form
    {
        short axis;//当前轴号
        bool[] en = new bool[8];//各轴的伺服使能状态
        uint clk;//时钟参数
        double prfvel, encvel, prfpos, encpos;//运动状态参数

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

            //控件初始化
            this.comboBox1.SelectedIndex = 0;

            timer1.Start();//启动定时器刷新状态
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

            gts.mc.GT_PrfPt(axis,gts.mc.PT_MODE_STATIC);//设置静态PT运动模式
            gts.mc.GT_PtClear(axis,0);//清空FIFO0
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
        }
        /// <summary>
        /// 添加PT数据
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button5_Click(object sender, EventArgs e)
        {
            double pos;
            int time;
            //可以通过界面输入PT数据
            //读取PT数据
            //pos = Convert.ToDouble(this.textBox5.Text);
            //time = Convert.ToInt32(this.textBox6.Text);
            //gts.mc.GT_PtData(axis,pos,time,gts.mc.PT_SEGMENT_NORMAL,0);//以普通段方式向0号FIFO增加数据

            pos = 1024;
            time = 1024;
            gts.mc.GT_PtData(axis, pos, time, gts.mc.PT_SEGMENT_NORMAL, 0);
            pos += 2048;
            time += 1024;
            gts.mc.GT_PtData(axis, pos, time, gts.mc.PT_SEGMENT_NORMAL, 0);
            pos += 1024;
            time += 1024;
            gts.mc.GT_PtData(axis, pos, time, gts.mc.PT_SEGMENT_NORMAL, 0);

        }
        /// <summary>
        /// 启动PT运动
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button6_Click(object sender, EventArgs e)
        {
            gts.mc.GT_PtStart(1<<(axis-1),0);//启动0号FIFO的PT运动
        }
        /// <summary>
        /// 停止运动
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button7_Click(object sender, EventArgs e)
        {
            gts.mc.GT_Stop(1 << (axis - 1), 0);
        }
        
    }
}
