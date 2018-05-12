namespace Host
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.guestControl1 = new Host.GuestControl();
            this.SuspendLayout();
            // 
            // guestControl1
            // 
            this.guestControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.guestControl1.Location = new System.Drawing.Point(0, 0);
            this.guestControl1.Name = "guestControl1";
            this.guestControl1.Size = new System.Drawing.Size(1256, 270);
            this.guestControl1.TabIndex = 0;
            this.guestControl1.Text = "guestControl1";
            // 
            // Form1
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1256, 270);
            this.Controls.Add(this.guestControl1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private GuestControl guestControl1;
    }
}

