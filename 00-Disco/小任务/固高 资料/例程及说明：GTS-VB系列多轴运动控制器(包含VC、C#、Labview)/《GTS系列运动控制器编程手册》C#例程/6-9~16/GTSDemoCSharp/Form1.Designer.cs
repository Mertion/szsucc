namespace GTSDemoCSharp
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.BUTTON_REAL_MACHINING = new System.Windows.Forms.Button();
            this.BUTTON_BUF_MOVE = new System.Windows.Forms.Button();
            this.BUTTON_FIFO_MANAGE = new System.Windows.Forms.Button();
            this.BUTTON_BUF_GEAR = new System.Windows.Forms.Button();
            this.BUTTON_LOOK_AHEAD = new System.Windows.Forms.Button();
            this.BUTTON_ARC_MOTION = new System.Windows.Forms.Button();
            this.BUTTON_LINEAR_MOTION = new System.Windows.Forms.Button();
            this.BUTTON_CLOSE = new System.Windows.Forms.Button();
            this.BUTTON_INITIAL_COORDINATE = new System.Windows.Forms.Button();
            this.BUTTON_INITIAL = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.textBox_Segment = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.textBox_CrdStatus = new System.Windows.Forms.TextBox();
            this.textBox_PrfPos3 = new System.Windows.Forms.TextBox();
            this.textBox_PrfPos2 = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.textBox_PrfPos1 = new System.Windows.Forms.TextBox();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.BUTTON_REAL_MACHINING);
            this.groupBox1.Controls.Add(this.BUTTON_BUF_MOVE);
            this.groupBox1.Controls.Add(this.BUTTON_FIFO_MANAGE);
            this.groupBox1.Controls.Add(this.BUTTON_BUF_GEAR);
            this.groupBox1.Controls.Add(this.BUTTON_LOOK_AHEAD);
            this.groupBox1.Controls.Add(this.BUTTON_ARC_MOTION);
            this.groupBox1.Controls.Add(this.BUTTON_LINEAR_MOTION);
            this.groupBox1.Controls.Add(this.BUTTON_CLOSE);
            this.groupBox1.Controls.Add(this.BUTTON_INITIAL_COORDINATE);
            this.groupBox1.Controls.Add(this.BUTTON_INITIAL);
            this.groupBox1.Location = new System.Drawing.Point(13, 13);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(298, 279);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "操作区";
            // 
            // BUTTON_REAL_MACHINING
            // 
            this.BUTTON_REAL_MACHINING.Location = new System.Drawing.Point(138, 237);
            this.BUTTON_REAL_MACHINING.Name = "BUTTON_REAL_MACHINING";
            this.BUTTON_REAL_MACHINING.Size = new System.Drawing.Size(154, 32);
            this.BUTTON_REAL_MACHINING.TabIndex = 9;
            this.BUTTON_REAL_MACHINING.Text = "刀向跟随-实际加工";
            this.BUTTON_REAL_MACHINING.UseVisualStyleBackColor = true;
            this.BUTTON_REAL_MACHINING.Click += new System.EventHandler(this.BUTTON_REAL_MACHINING_Click);
            // 
            // BUTTON_BUF_MOVE
            // 
            this.BUTTON_BUF_MOVE.Location = new System.Drawing.Point(138, 200);
            this.BUTTON_BUF_MOVE.Name = "BUTTON_BUF_MOVE";
            this.BUTTON_BUF_MOVE.Size = new System.Drawing.Size(154, 32);
            this.BUTTON_BUF_MOVE.TabIndex = 8;
            this.BUTTON_BUF_MOVE.Text = "刀向跟随BufMove";
            this.BUTTON_BUF_MOVE.UseVisualStyleBackColor = true;
            this.BUTTON_BUF_MOVE.Click += new System.EventHandler(this.BUTTON_BUF_MOVE_Click);
            // 
            // BUTTON_FIFO_MANAGE
            // 
            this.BUTTON_FIFO_MANAGE.Location = new System.Drawing.Point(138, 163);
            this.BUTTON_FIFO_MANAGE.Name = "BUTTON_FIFO_MANAGE";
            this.BUTTON_FIFO_MANAGE.Size = new System.Drawing.Size(154, 32);
            this.BUTTON_FIFO_MANAGE.TabIndex = 7;
            this.BUTTON_FIFO_MANAGE.Text = "FIFO管理";
            this.BUTTON_FIFO_MANAGE.UseVisualStyleBackColor = true;
            this.BUTTON_FIFO_MANAGE.Click += new System.EventHandler(this.BUTTON_FIFO_MANAGE_Click);
            // 
            // BUTTON_BUF_GEAR
            // 
            this.BUTTON_BUF_GEAR.Location = new System.Drawing.Point(138, 126);
            this.BUTTON_BUF_GEAR.Name = "BUTTON_BUF_GEAR";
            this.BUTTON_BUF_GEAR.Size = new System.Drawing.Size(154, 32);
            this.BUTTON_BUF_GEAR.TabIndex = 6;
            this.BUTTON_BUF_GEAR.Text = "刀向跟随BufGear";
            this.BUTTON_BUF_GEAR.UseVisualStyleBackColor = true;
            this.BUTTON_BUF_GEAR.Click += new System.EventHandler(this.BUTTON_BUF_GEAR_Click);
            // 
            // BUTTON_LOOK_AHEAD
            // 
            this.BUTTON_LOOK_AHEAD.Location = new System.Drawing.Point(138, 89);
            this.BUTTON_LOOK_AHEAD.Name = "BUTTON_LOOK_AHEAD";
            this.BUTTON_LOOK_AHEAD.Size = new System.Drawing.Size(154, 32);
            this.BUTTON_LOOK_AHEAD.TabIndex = 5;
            this.BUTTON_LOOK_AHEAD.Text = "前瞻处理";
            this.BUTTON_LOOK_AHEAD.UseVisualStyleBackColor = true;
            this.BUTTON_LOOK_AHEAD.Click += new System.EventHandler(this.BUTTON_LOOK_AHEAD_Click);
            // 
            // BUTTON_ARC_MOTION
            // 
            this.BUTTON_ARC_MOTION.Location = new System.Drawing.Point(138, 52);
            this.BUTTON_ARC_MOTION.Name = "BUTTON_ARC_MOTION";
            this.BUTTON_ARC_MOTION.Size = new System.Drawing.Size(154, 32);
            this.BUTTON_ARC_MOTION.TabIndex = 4;
            this.BUTTON_ARC_MOTION.Text = "圆弧插补";
            this.BUTTON_ARC_MOTION.UseVisualStyleBackColor = true;
            this.BUTTON_ARC_MOTION.Click += new System.EventHandler(this.BUTTON_ARC_MOTION_Click);
            // 
            // BUTTON_LINEAR_MOTION
            // 
            this.BUTTON_LINEAR_MOTION.Location = new System.Drawing.Point(138, 15);
            this.BUTTON_LINEAR_MOTION.Name = "BUTTON_LINEAR_MOTION";
            this.BUTTON_LINEAR_MOTION.Size = new System.Drawing.Size(154, 32);
            this.BUTTON_LINEAR_MOTION.TabIndex = 3;
            this.BUTTON_LINEAR_MOTION.Text = "直线插补";
            this.BUTTON_LINEAR_MOTION.UseVisualStyleBackColor = true;
            this.BUTTON_LINEAR_MOTION.Click += new System.EventHandler(this.BUTTON_LINEAR_MOTION_Click);
            // 
            // BUTTON_CLOSE
            // 
            this.BUTTON_CLOSE.Location = new System.Drawing.Point(7, 200);
            this.BUTTON_CLOSE.Name = "BUTTON_CLOSE";
            this.BUTTON_CLOSE.Size = new System.Drawing.Size(112, 32);
            this.BUTTON_CLOSE.TabIndex = 2;
            this.BUTTON_CLOSE.Text = "停止运动";
            this.BUTTON_CLOSE.UseVisualStyleBackColor = true;
            this.BUTTON_CLOSE.Click += new System.EventHandler(this.BUTTON_CLOSE_Click);
            // 
            // BUTTON_INITIAL_COORDINATE
            // 
            this.BUTTON_INITIAL_COORDINATE.Location = new System.Drawing.Point(7, 126);
            this.BUTTON_INITIAL_COORDINATE.Name = "BUTTON_INITIAL_COORDINATE";
            this.BUTTON_INITIAL_COORDINATE.Size = new System.Drawing.Size(112, 32);
            this.BUTTON_INITIAL_COORDINATE.TabIndex = 1;
            this.BUTTON_INITIAL_COORDINATE.Text = "建立坐标系";
            this.BUTTON_INITIAL_COORDINATE.UseVisualStyleBackColor = true;
            this.BUTTON_INITIAL_COORDINATE.Click += new System.EventHandler(this.BUTTON_INITIAL_COORDINATE_Click);
            // 
            // BUTTON_INITIAL
            // 
            this.BUTTON_INITIAL.Location = new System.Drawing.Point(6, 52);
            this.BUTTON_INITIAL.Name = "BUTTON_INITIAL";
            this.BUTTON_INITIAL.Size = new System.Drawing.Size(112, 32);
            this.BUTTON_INITIAL.TabIndex = 0;
            this.BUTTON_INITIAL.Text = "初始化";
            this.BUTTON_INITIAL.UseVisualStyleBackColor = true;
            this.BUTTON_INITIAL.Click += new System.EventHandler(this.BUTTON_INITIAL_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.textBox_Segment);
            this.groupBox2.Controls.Add(this.label5);
            this.groupBox2.Controls.Add(this.textBox_CrdStatus);
            this.groupBox2.Controls.Add(this.textBox_PrfPos3);
            this.groupBox2.Controls.Add(this.textBox_PrfPos2);
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Controls.Add(this.label1);
            this.groupBox2.Controls.Add(this.textBox_PrfPos1);
            this.groupBox2.Location = new System.Drawing.Point(317, 13);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(154, 279);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "运动状态";
            // 
            // textBox_Segment
            // 
            this.textBox_Segment.Location = new System.Drawing.Point(82, 180);
            this.textBox_Segment.Name = "textBox_Segment";
            this.textBox_Segment.ReadOnly = true;
            this.textBox_Segment.Size = new System.Drawing.Size(66, 21);
            this.textBox_Segment.TabIndex = 9;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(6, 183);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(77, 12);
            this.label5.TabIndex = 8;
            this.label5.Text = "当前运动段号";
            // 
            // textBox_CrdStatus
            // 
            this.textBox_CrdStatus.Location = new System.Drawing.Point(82, 141);
            this.textBox_CrdStatus.Name = "textBox_CrdStatus";
            this.textBox_CrdStatus.ReadOnly = true;
            this.textBox_CrdStatus.Size = new System.Drawing.Size(66, 21);
            this.textBox_CrdStatus.TabIndex = 7;
            // 
            // textBox_PrfPos3
            // 
            this.textBox_PrfPos3.Location = new System.Drawing.Point(82, 100);
            this.textBox_PrfPos3.Name = "textBox_PrfPos3";
            this.textBox_PrfPos3.ReadOnly = true;
            this.textBox_PrfPos3.Size = new System.Drawing.Size(66, 21);
            this.textBox_PrfPos3.TabIndex = 6;
            // 
            // textBox_PrfPos2
            // 
            this.textBox_PrfPos2.Location = new System.Drawing.Point(82, 59);
            this.textBox_PrfPos2.Name = "textBox_PrfPos2";
            this.textBox_PrfPos2.ReadOnly = true;
            this.textBox_PrfPos2.Size = new System.Drawing.Size(66, 21);
            this.textBox_PrfPos2.TabIndex = 5;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(6, 144);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(65, 12);
            this.label4.TabIndex = 4;
            this.label4.Text = "坐标系状态";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(7, 105);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(71, 12);
            this.label3.TabIndex = 3;
            this.label3.Text = "Z轴规划位置";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(7, 62);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(71, 12);
            this.label2.TabIndex = 2;
            this.label2.Text = "Y轴规划位置";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(7, 21);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(71, 12);
            this.label1.TabIndex = 1;
            this.label1.Text = "X轴规划位置";
            // 
            // textBox_PrfPos1
            // 
            this.textBox_PrfPos1.Location = new System.Drawing.Point(82, 18);
            this.textBox_PrfPos1.Name = "textBox_PrfPos1";
            this.textBox_PrfPos1.ReadOnly = true;
            this.textBox_PrfPos1.Size = new System.Drawing.Size(66, 21);
            this.textBox_PrfPos1.TabIndex = 0;
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(483, 304);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "插补运动";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox textBox_CrdStatus;
        private System.Windows.Forms.TextBox textBox_PrfPos3;
        private System.Windows.Forms.TextBox textBox_PrfPos2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBox_PrfPos1;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button BUTTON_REAL_MACHINING;
        private System.Windows.Forms.Button BUTTON_BUF_MOVE;
        private System.Windows.Forms.Button BUTTON_FIFO_MANAGE;
        private System.Windows.Forms.Button BUTTON_BUF_GEAR;
        private System.Windows.Forms.Button BUTTON_LOOK_AHEAD;
        private System.Windows.Forms.Button BUTTON_ARC_MOTION;
        private System.Windows.Forms.Button BUTTON_LINEAR_MOTION;
        private System.Windows.Forms.Button BUTTON_CLOSE;
        private System.Windows.Forms.Button BUTTON_INITIAL_COORDINATE;
        private System.Windows.Forms.Button BUTTON_INITIAL;
        private System.Windows.Forms.TextBox textBox_Segment;
        private System.Windows.Forms.Label label5;
    }
}

