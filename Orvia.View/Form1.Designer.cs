namespace Orvia;

partial class Form1
{
    /// <summary>
    ///  Required designer variable.
    /// </summary>
    private System.ComponentModel.IContainer components = null;

    /// <summary>
    ///  Clean up any resources being used.
    /// </summary>
    /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
    protected override void Dispose(bool disposing)
    {
        if (disposing && (components != null))
        {
            components.Dispose();
        }

        base.Dispose(disposing);
    }

    #region Windows Form Designer generated code

    /// <summary>
    ///  Required method for Designer support - do not modify
    ///  the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent()
    {
            this.components = new System.ComponentModel.Container();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripComboBox1 = new System.Windows.Forms.ToolStripComboBox();
            this.config_tabControl = new System.Windows.Forms.TabControl();
            this.Config_tP = new System.Windows.Forms.TabPage();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label1 = new System.Windows.Forms.Label();
            this.nidConfig_lb = new System.Windows.Forms.ListBox();
            this.saveConfig_btn = new System.Windows.Forms.Button();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.contextMenuStrip1.SuspendLayout();
            this.config_tabControl.SuspendLayout();
            this.Config_tP.SuspendLayout();
            this.SuspendLayout();
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItem1,
            this.toolStripComboBox1});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(212, 60);
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(211, 24);
            this.toolStripMenuItem1.Text = "toolStripMenuItem1";
            // 
            // toolStripComboBox1
            // 
            this.toolStripComboBox1.Name = "toolStripComboBox1";
            this.toolStripComboBox1.Size = new System.Drawing.Size(121, 28);
            // 
            // config_tabControl
            // 
            this.config_tabControl.Controls.Add(this.Config_tP);
            this.config_tabControl.Controls.Add(this.tabPage2);
            this.config_tabControl.Dock = System.Windows.Forms.DockStyle.Fill;
            this.config_tabControl.Location = new System.Drawing.Point(0, 0);
            this.config_tabControl.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.config_tabControl.Name = "config_tabControl";
            this.config_tabControl.SelectedIndex = 0;
            this.config_tabControl.Size = new System.Drawing.Size(914, 600);
            this.config_tabControl.TabIndex = 1;
            // 
            // Config_tP
            // 
            this.Config_tP.Controls.Add(this.groupBox1);
            this.Config_tP.Controls.Add(this.label1);
            this.Config_tP.Controls.Add(this.nidConfig_lb);
            this.Config_tP.Controls.Add(this.saveConfig_btn);
            this.Config_tP.Location = new System.Drawing.Point(4, 29);
            this.Config_tP.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Config_tP.Name = "Config_tP";
            this.Config_tP.Padding = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Config_tP.Size = new System.Drawing.Size(906, 567);
            this.Config_tP.TabIndex = 0;
            this.Config_tP.Text = "Config";
            this.Config_tP.UseVisualStyleBackColor = true;
            // 
            // groupBox1
            // 
            this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox1.Location = new System.Drawing.Point(17, 42);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(438, 515);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Configuration du nid";
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label1.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label1.Location = new System.Drawing.Point(548, 8);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(277, 42);
            this.label1.TabIndex = 2;
            this.label1.Text = "Nids non configurés";
            this.label1.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // nidConfig_lb
            // 
            this.nidConfig_lb.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.nidConfig_lb.FormattingEnabled = true;
            this.nidConfig_lb.IntegralHeight = false;
            this.nidConfig_lb.ItemHeight = 20;
            this.nidConfig_lb.Location = new System.Drawing.Point(461, 53);
            this.nidConfig_lb.Name = "nidConfig_lb";
            this.nidConfig_lb.Size = new System.Drawing.Size(437, 432);
            this.nidConfig_lb.TabIndex = 1;
            this.nidConfig_lb.SelectedIndexChanged += new System.EventHandler(this.nidConfig_lb_SelectedIndexChanged);
            // 
            // saveConfig_btn
            // 
            this.saveConfig_btn.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.saveConfig_btn.AutoSize = true;
            this.saveConfig_btn.Location = new System.Drawing.Point(461, 500);
            this.saveConfig_btn.Name = "saveConfig_btn";
            this.saveConfig_btn.Size = new System.Drawing.Size(437, 57);
            this.saveConfig_btn.TabIndex = 0;
            this.saveConfig_btn.Text = "Save config";
            this.saveConfig_btn.UseVisualStyleBackColor = true;
            // 
            // tabPage2
            // 
            this.tabPage2.Location = new System.Drawing.Point(4, 29);
            this.tabPage2.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.tabPage2.Size = new System.Drawing.Size(906, 567);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "State";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(914, 600);
            this.Controls.Add(this.config_tabControl);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.Text = "Orvia_VueTechnicien";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.contextMenuStrip1.ResumeLayout(false);
            this.config_tabControl.ResumeLayout(false);
            this.Config_tP.ResumeLayout(false);
            this.Config_tP.PerformLayout();
            this.ResumeLayout(false);

    }

    #endregion

    private ContextMenuStrip contextMenuStrip1;
    private ToolStripMenuItem toolStripMenuItem1;
    private ToolStripComboBox toolStripComboBox1;
    private TabControl config_tabControl;
    private TabPage Config_tP;
    private TabPage tabPage2;
    private Button saveConfig_btn;
    private ListBox nidConfig_lb;
    private Label label1;
    private GroupBox groupBox1;
}