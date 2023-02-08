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
    //例程 7-2 读取8个轴编码器和辅助编码器位置值
    public partial class Form1 : Form
    {
        uint clk;//时钟参数
        double[] enc=new double[9];

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
            
        }
        
        /// <summary>
        /// 运动状态刷新
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void timer1_Tick(object sender, EventArgs e)
        {
            //读取编码器位置并显示
            gts.mc.GT_GetEncPos(1, out enc[0], 8, out clk);
            this.textBox1.Text = Math.Round(enc[0], 1).ToString();
            this.textBox2.Text = Math.Round(enc[1], 1).ToString();
            this.textBox3.Text = Math.Round(enc[2], 1).ToString();
            this.textBox4.Text = Math.Round(enc[3], 1).ToString();
            this.textBox5.Text = Math.Round(enc[4], 1).ToString();
            this.textBox6.Text = Math.Round(enc[5], 1).ToString();
            this.textBox7.Text = Math.Round(enc[6], 1).ToString();
            this.textBox8.Text = Math.Round(enc[7], 1).ToString();
            gts.mc.GT_GetEncPos(9, out enc[8], 1, out clk);
        }
        /// <summary>
        /// 打开控制卡
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button1_Click(object sender, EventArgs e)
        {
            gts.mc.GT_Open(0,1);
        }
        /// <summary>
        /// 读取编码器位置值
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button2_Click(object sender, EventArgs e)
        {
            timer1.Start();//启动定时器，循环检测编码器位置值
        }
        
    }
}
