using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Test
{
    //例程6-1 点位运动
    public partial class Form1 : Form
    {
        short axis;
        bool[] en=new bool[8];
        int pos;
        uint clk;
        double vel, prfvel, encvel, prfpos, encpos;
        gts.mc.TTrapPrm trap;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            gts.mc.GT_Open(0,1);//打开运动控制卡
            this.comboBox1.SelectedIndex = 0;
        }
        //复位
        private void button6_Click(object sender, EventArgs e)
        {
            gts.mc.GT_Reset();
        }
        //初始化
        private void button1_Click(object sender, EventArgs e)
        {
            gts.mc.GT_LoadConfig("GT800_test.cfg");//下载配置文件
            gts.mc.GT_ClrSts(1,8);//清除各轴报警和限位
            pos = 0;
        }
        //伺服使能
        private void button5_Click(object sender, EventArgs e)
        {
            axis = Convert.ToInt16(this.comboBox1.SelectedIndex + 1);
                if (!en[axis-1])
                {
                    gts.mc.GT_AxisOn(axis);//上伺服
                    this.button5.Text = "伺服关闭";
                }
                if (en[axis-1])
                {
                    gts.mc.GT_AxisOff(axis);//下伺服
                    this.button5.Text = "伺服使能";
                }
                en[axis - 1] = !en[axis - 1];
          
        }
        //启动点位运动
        private void button2_Click(object sender, EventArgs e)
        {
            //读取数据
            axis = Convert.ToInt16(this.comboBox1.SelectedIndex + 1);
            vel = Convert.ToDouble(this.textBox1.Text);
            pos += Convert.ToInt32(this.textBox2.Text);
            trap.acc = Convert.ToDouble(this.textBox3.Text);
            trap.dec = Convert.ToDouble(this.textBox4.Text);
            trap.smoothTime = Convert.ToInt16(this.textBox5.Text);
            trap.velStart = 0;

            gts.mc.GT_SetTrapPrm(axis,ref trap);//设置点位运动参数
            gts.mc.GT_SetVel(axis,vel);//设置目标速度
            gts.mc.GT_SetPos(axis,pos);//设置目标位置
            gts.mc.GT_Update(1<<(axis-1));//更新轴运动
        }
        //刷新状态
        private void timer1_Tick(object sender, EventArgs e)
        {
            axis = Convert.ToInt16(this.comboBox1.SelectedIndex + 1);
            if (!en[Convert.ToInt32(this.comboBox1.Text)-1])
            {
                this.button5.Text = "伺服使能";
            }
            if (en[Convert.ToInt32(this.comboBox1.Text)-1])
            {
                this.button5.Text = "伺服关闭";
            }
            gts.mc.GT_GetPrfPos(axis,out prfpos,1,out clk);
            this.textBox6.Text = Math.Round(prfpos,1).ToString();
            gts.mc.GT_GetPrfVel(axis,out prfvel,1,out clk);
            this.textBox7.Text = Math.Round(prfvel,1).ToString();
            gts.mc.GT_GetEncPos(axis,out encpos,1,out clk);
            this.textBox8.Text = Math.Round(encpos, 1).ToString();
            gts.mc.GT_GetEncVel(axis,out encvel,1,out clk);
            this.textBox9.Text = Math.Round(encvel, 1).ToString();
        }
        //平滑停止
        private void button3_Click(object sender, EventArgs e)
        {
            gts.mc.GT_Stop(1<<(axis-1),0);
            pos = 0;
        }
        //位置清零
        private void button4_Click(object sender, EventArgs e)
        {
            gts.mc.GT_ZeroPos(1,8);
            pos = 0;
        }

        
    }
}
