using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace gear
{
    //例程6-5 电子齿轮跟随
    public partial class Form1 : Form
    {
        /// <summary>
        /// 参数定义
        /// </summary>
        short master, slave, geartype;
        double vel,prfvel_m, prfvel_s, encvel_m, encvel_s;
        double prfpos_m, prfpos_s, encpos_m, encpos_s;
        uint clk;
        int masterSlope,masterEven,slaveEven;
        gts.mc.TJogPrm jog;

        public Form1()
        {
            InitializeComponent();
        }
        //
        //界面加载
        //
        private void Form1_Load(object sender, EventArgs e)
        {
            //初始化控件
            this.comboBox1.SelectedIndex = 0;
            this.comboBox2.SelectedIndex = 1;
            this.comboBox3.SelectedIndex = 0;

        }
        //
        //初始化
        //
        private void button1_Click(object sender, EventArgs e)
        {
            gts.mc.GT_Open(0, 1);//打开运动控制卡
            gts.mc.GT_Reset();
            gts.mc.GT_LoadConfig("GT800_test.cfg");//下载配置文件，若配置文件不在当前目录可加绝对路径
            gts.mc.GT_ClrSts(1, 8);//清除各轴报警和限位
            for (short i = 1; i < 9; i++)
            {
                gts.mc.GT_AxisOn(i);//轴使能
            }
        }
        //
        //复位
        //
        private void button2_Click(object sender, EventArgs e)
        {
            gts.mc.GT_Reset();
        }
        //
        //启动主轴
        //
        private void button5_Click(object sender, EventArgs e)
        {
            gts.mc.GT_PrfJog(master);//设置主轴为jog模式
            ///参数设置
            jog.acc = 1;
            jog.dec = 1;
            gts.mc.GT_SetJogPrm(master, ref jog);
            vel = Convert.ToDouble(textBox1.Text);

            gts.mc.GT_SetVel(master, vel);//设置速度
            gts.mc.GT_Update(1 << (master - 1));//启动运动
        }
        //
        //启动gear
        //
        private void button3_Click(object sender, EventArgs e)
        {
            //读取输入数据
            geartype = Convert.ToInt16(comboBox3.SelectedIndex);
            masterSlope = Convert.ToInt32(textBox4.Text);
            masterEven = Convert.ToInt32(textBox2.Text);
            slaveEven = Convert.ToInt32(textBox3.Text);

            gts.mc.GT_PrfGear(slave, 0);//设置从轴为gear模式

            if (comboBox3.SelectedItem.ToString() == "规划轴")
                gts.mc.GT_SetGearMaster(slave, master, gts.mc.GEAR_MASTER_PROFILE, 0);//设置跟随主轴和模式
            if (comboBox3.SelectedItem.ToString() == "编码器")
                gts.mc.GT_SetGearMaster(slave, master, gts.mc.GEAR_MASTER_ENCODER, 0);//设置跟随主轴和模式
            
            gts.mc.GT_SetGearRatio(slave, masterEven, slaveEven, masterSlope);//设置齿轮比

            gts.mc.GT_GearStart(1 << (slave - 1));//启动gear
        }
        //
        //停止运动
        //
        private void button4_Click(object sender, EventArgs e)
        {
            gts.mc.GT_Stop(255, 0);
        }
        //
        //显示运动状态
        //
        private void timer1_Tick(object sender, EventArgs e)
        {
            master = Convert.ToInt16(comboBox1.SelectedIndex + 1);
            slave = Convert.ToInt16(comboBox2.SelectedIndex + 1);//取轴号
            //读取主轴规划速度、显示
            gts.mc.GT_GetPrfVel(master, out prfvel_m, 1, out clk);
            this.textBox5.Text = prfvel_m.ToString();
            //读取主轴实际速度、显示
            gts.mc.GT_GetEncVel(master, out encvel_m, 1, out clk);
            this.textBox6.Text = encvel_m.ToString();
            //读取从轴规划速度、显示
            gts.mc.GT_GetPrfVel(slave, out prfvel_s, 1, out clk);
            this.textBox7.Text = prfvel_s.ToString();
            //读取从轴实际速度、显示
            gts.mc.GT_GetEncVel(slave, out encvel_s, 1, out clk);
            this.textBox8.Text = encvel_s.ToString();

            //读取主轴规划位置
            gts.mc.GT_GetPrfPos(master, out prfpos_m, 1, out clk);
            this.textBox9.Text = prfpos_m.ToString();
            //读取主轴实际位置
            gts.mc.GT_GetEncPos(master, out encpos_m, 1, out clk);
            this.textBox10.Text = encpos_m.ToString();
            //读取从轴规划位置
            gts.mc.GT_GetPrfPos(slave, out prfpos_s, 1, out clk);
            this.textBox11.Text = prfpos_s.ToString();
            //读取从轴实际位置
            gts.mc.GT_GetEncPos(slave, out encpos_s, 1, out clk);
            this.textBox12.Text = encpos_s.ToString();
        }

    }
}
