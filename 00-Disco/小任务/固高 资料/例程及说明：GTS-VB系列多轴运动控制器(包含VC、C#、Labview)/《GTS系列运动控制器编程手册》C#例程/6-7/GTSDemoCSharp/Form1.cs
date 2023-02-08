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
    public partial class Form1 : Form
    {
        short MasterAxis;//主轴当前轴号
        short SlaveAxis;//从轴当前轴号
        bool[] en = new bool[8];//各轴的伺服使能状态
        uint clk;//时钟参数
        double MasterPrfvel, MasterEncvel, MasterPrfpos, MasterEncpos;//主轴运动状态参数
        double SlavePrfvel, SlaveEncvel, SlavePrfpos, SlaveEncpos;//从轴运动状态参数

        gts.mc.TJogPrm jog;

        int masterPos;
        double slavePos;

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
            this.comboBox2.SelectedIndex = 1;

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

            //将主轴设为 Jog 模式，并设置Jog运动参数
            gts.mc.GT_PrfJog(MasterAxis);
            gts.mc.GT_GetJogPrm(MasterAxis,out jog);
            jog.acc = 1;
            gts.mc.GT_SetJogPrm(MasterAxis,ref jog);
            gts.mc.GT_SetVel(MasterAxis,50);

            //设置从轴为Follow模式
            gts.mc.GT_PrfFollow(SlaveAxis, 0);// 将从轴设为Follow模式，双向跟随
            gts.mc.GT_FollowClear(SlaveAxis, 0);// 清空从轴FIFO1
            gts.mc.GT_SetFollowMaster(SlaveAxis, MasterAxis, gts.mc.FOLLOW_MASTER_PROFILE, 0);// 设置主轴，默认跟随主轴规划位置
            gts.mc.GT_SetFollowLoop(SlaveAxis, 0);// 设置循环次数为无限循环
            gts.mc.GT_SetFollowEvent(SlaveAxis, gts.mc.FOLLOW_EVENT_PASS, 1, 50000);// 设置启动跟随条件
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
            MasterAxis = Convert.ToInt16(this.comboBox1.SelectedIndex + 1);
            SlaveAxis = Convert.ToInt16(this.comboBox2.SelectedIndex + 1);
            //同时使能主轴和从轴
            if (!en[MasterAxis - 1])
            {
                gts.mc.GT_AxisOn(MasterAxis);//上伺服
                gts.mc.GT_AxisOn(SlaveAxis);//上伺服
                this.button3.Text = "伺服关闭";
            }
            //主轴和从轴同时下伺服
            if (en[MasterAxis - 1])
            {
                gts.mc.GT_AxisOff(MasterAxis);//下伺服
                gts.mc.GT_AxisOff(SlaveAxis);//下伺服
                this.button3.Text = "伺服使能";
            }

            en[MasterAxis - 1] = !en[MasterAxis - 1];
            en[SlaveAxis - 1] = !en[SlaveAxis - 1];
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
            MasterAxis = Convert.ToInt16(this.comboBox1.SelectedIndex + 1);//读取轴号
            SlaveAxis = Convert.ToInt16(this.comboBox2.SelectedIndex + 1);//读取轴号

            if (!en[Convert.ToInt32(this.comboBox1.Text) - 1])
            {
                this.button3.Text = "伺服使能";
            }
            if (en[Convert.ToInt32(this.comboBox1.Text) - 1])
            {
                this.button3.Text = "伺服关闭";
            }
            //主轴状态
            //读取规划速度并显示
            gts.mc.GT_GetPrfVel(MasterAxis, out MasterPrfvel, 1, out clk);
            this.textBox1.Text = Math.Round(MasterPrfvel, 6).ToString();
            //读取规划位置并显示
            gts.mc.GT_GetPrfPos(MasterAxis, out MasterPrfpos, 1, out clk);
            this.textBox2.Text = Math.Round(MasterPrfpos, 1).ToString();
            //读取实际速度并显示
            gts.mc.GT_GetEncVel(MasterAxis, out MasterEncvel, 1, out clk);
            this.textBox3.Text = Math.Round(MasterEncvel, 6).ToString();
            //读取实际位置并显示
            gts.mc.GT_GetEncPos(MasterAxis, out MasterEncpos, 1, out clk);
            this.textBox4.Text = Math.Round(MasterEncpos, 1).ToString();
            //从轴状态
            //读取规划速度并显示
            gts.mc.GT_GetPrfVel(SlaveAxis, out SlavePrfvel, 1, out clk);
            this.textBox5.Text = Math.Round(SlavePrfvel, 6).ToString();
            //读取规划位置并显示
            gts.mc.GT_GetPrfPos(SlaveAxis, out SlavePrfpos, 1, out clk);
            this.textBox6.Text = Math.Round(SlavePrfpos, 1).ToString();
            //读取实际速度并显示
            gts.mc.GT_GetEncVel(SlaveAxis, out SlaveEncvel, 1, out clk);
            this.textBox7.Text = Math.Round(SlaveEncvel, 6).ToString();
            //读取实际位置并显示
            gts.mc.GT_GetEncPos(SlaveAxis, out SlaveEncpos, 1, out clk);
            this.textBox8.Text = Math.Round(SlaveEncpos, 1).ToString();
        }
        /// <summary>
        /// 停止运动
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button5_Click(object sender, EventArgs e)
        {
            gts.mc.GT_Stop(1 << (MasterAxis - 1), 0);
            gts.mc.GT_Stop(1 << (SlaveAxis - 1), 0);
        }

        /// <summary>
        /// 向FIFO增加Follow运动数据
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button6_Click(object sender, EventArgs e)
        {
            //也可以通过在文本控件输入位置数据再添加到FIFO
            //获取主从轴位置数据
            //masterPos = Convert.ToInt32(this.textBox9.Text);
            //slavePos = Convert.ToDouble(this.textBox10.Text);
            //gts.mc.GT_FollowData(SlaveAxis,masterPos,slavePos,gts.mc.FOLLOW_SEGMENT_NORMAL,0);//以普通段方式向FIFO1增加数据
            masterPos = 20000;
            slavePos = 10000;
            gts.mc.GT_FollowData(SlaveAxis, masterPos, slavePos, gts.mc.FOLLOW_SEGMENT_NORMAL, 0);//以普通段方式向FIFO1增加数据
            masterPos += 20000;
            slavePos += 20000;
            gts.mc.GT_FollowData(SlaveAxis, masterPos, slavePos, gts.mc.FOLLOW_SEGMENT_NORMAL, 0);//以普通段方式向FIFO1增加数据
            masterPos += 20000;
            slavePos += 10000;
            gts.mc.GT_FollowData(SlaveAxis, masterPos, slavePos, gts.mc.FOLLOW_SEGMENT_NORMAL, 0);//以普通段方式向FIFO1增加数据

        }
        /// <summary>
        /// 启动主轴Jog运动及从轴Follow运动
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button7_Click(object sender, EventArgs e)
        {
            gts.mc.GT_Update(1<<(MasterAxis-1));//启动主轴Jog运动
            gts.mc.GT_FollowStart(1 << (SlaveAxis - 1), 0);// 启动从轴Follow运动
        }

        
    }
}
