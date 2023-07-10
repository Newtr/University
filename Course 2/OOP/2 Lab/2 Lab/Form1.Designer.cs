namespace _2_Lab
{
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
            this.Book_Info_Label = new System.Windows.Forms.Label();
            this.Book_Size_Label = new System.Windows.Forms.Label();
            this.Book_Type_Label = new System.Windows.Forms.Label();
            this.Book_Name_textBox = new System.Windows.Forms.TextBox();
            this.Book_Name_Label = new System.Windows.Forms.Label();
            this.Book_Size_domainUpDown = new System.Windows.Forms.DomainUpDown();
            this.UDK_textBox = new System.Windows.Forms.TextBox();
            this.UDK_Label = new System.Windows.Forms.Label();
            this.Page_Count_Label = new System.Windows.Forms.Label();
            this.Count_Of_Page_numericUpDown = new System.Windows.Forms.NumericUpDown();
            this.PublishHouse_Label = new System.Windows.Forms.Label();
            this.Publisher_checkedListBox = new System.Windows.Forms.CheckedListBox();
            this.Year_Of_Creating_Label = new System.Windows.Forms.Label();
            this.Year_Of_Creating_numericUpDown = new System.Windows.Forms.NumericUpDown();
            this.Authors_Label = new System.Windows.Forms.Label();
            this.Authors_listBox = new System.Windows.Forms.ListBox();
            this.Add_Author_button = new System.Windows.Forms.Button();
            this.Save_info_button = new System.Windows.Forms.Button();
            this.Science_RadioButton = new System.Windows.Forms.RadioButton();
            this.Artistic_RadioButton = new System.Windows.Forms.RadioButton();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.Count_Of_Page_numericUpDown)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Year_Of_Creating_numericUpDown)).BeginInit();
            this.SuspendLayout();
            // 
            // Book_Info_Label
            // 
            this.Book_Info_Label.AutoSize = true;
            this.Book_Info_Label.Font = new System.Drawing.Font("Segoe UI", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.Book_Info_Label.Location = new System.Drawing.Point(11, 27);
            this.Book_Info_Label.Name = "Book_Info_Label";
            this.Book_Info_Label.Size = new System.Drawing.Size(369, 46);
            this.Book_Info_Label.TabIndex = 0;
            this.Book_Info_Label.Text = "Характеристики книги";
            this.Book_Info_Label.Click += new System.EventHandler(this.label1_Click);
            // 
            // Book_Size_Label
            // 
            this.Book_Size_Label.AutoSize = true;
            this.Book_Size_Label.Location = new System.Drawing.Point(11, 157);
            this.Book_Size_Label.Name = "Book_Size_Label";
            this.Book_Size_Label.Size = new System.Drawing.Size(137, 20);
            this.Book_Size_Label.TabIndex = 1;
            this.Book_Size_Label.Text = "Размер книги(мб):";
            // 
            // Book_Type_Label
            // 
            this.Book_Type_Label.AutoSize = true;
            this.Book_Type_Label.Location = new System.Drawing.Point(11, 100);
            this.Book_Type_Label.Name = "Book_Type_Label";
            this.Book_Type_Label.Size = new System.Drawing.Size(82, 20);
            this.Book_Type_Label.TabIndex = 3;
            this.Book_Type_Label.Text = "Тип книги:";
            // 
            // Book_Name_textBox
            // 
            this.Book_Name_textBox.Location = new System.Drawing.Point(221, 221);
            this.Book_Name_textBox.Name = "Book_Name_textBox";
            this.Book_Name_textBox.Size = new System.Drawing.Size(246, 27);
            this.Book_Name_textBox.TabIndex = 6;
            this.Book_Name_textBox.TextChanged += new System.EventHandler(this.Book_Name_textBox_TextChanged);
            // 
            // Book_Name_Label
            // 
            this.Book_Name_Label.AutoSize = true;
            this.Book_Name_Label.Location = new System.Drawing.Point(11, 221);
            this.Book_Name_Label.Name = "Book_Name_Label";
            this.Book_Name_Label.Size = new System.Drawing.Size(124, 20);
            this.Book_Name_Label.TabIndex = 5;
            this.Book_Name_Label.Text = "Название книги:";
            // 
            // Book_Size_domainUpDown
            // 
            this.Book_Size_domainUpDown.Items.Add("10");
            this.Book_Size_domainUpDown.Items.Add("20");
            this.Book_Size_domainUpDown.Items.Add("30");
            this.Book_Size_domainUpDown.Items.Add("40");
            this.Book_Size_domainUpDown.Items.Add("50");
            this.Book_Size_domainUpDown.Location = new System.Drawing.Point(221, 156);
            this.Book_Size_domainUpDown.Name = "Book_Size_domainUpDown";
            this.Book_Size_domainUpDown.Size = new System.Drawing.Size(246, 27);
            this.Book_Size_domainUpDown.TabIndex = 7;
            this.Book_Size_domainUpDown.Text = "Выберите размер";
            this.Book_Size_domainUpDown.SelectedItemChanged += new System.EventHandler(this.domainUpDown1_SelectedItemChanged);
            // 
            // UDK_textBox
            // 
            this.UDK_textBox.Location = new System.Drawing.Point(221, 291);
            this.UDK_textBox.Name = "UDK_textBox";
            this.UDK_textBox.Size = new System.Drawing.Size(246, 27);
            this.UDK_textBox.TabIndex = 9;
            this.UDK_textBox.TextChanged += new System.EventHandler(this.UDK_textBox_TextChanged);
            // 
            // UDK_Label
            // 
            this.UDK_Label.AutoSize = true;
            this.UDK_Label.Location = new System.Drawing.Point(11, 291);
            this.UDK_Label.Name = "UDK_Label";
            this.UDK_Label.Size = new System.Drawing.Size(84, 20);
            this.UDK_Label.TabIndex = 8;
            this.UDK_Label.Text = "УДК книги:";
            // 
            // Page_Count_Label
            // 
            this.Page_Count_Label.AutoSize = true;
            this.Page_Count_Label.Location = new System.Drawing.Point(11, 364);
            this.Page_Count_Label.Name = "Page_Count_Label";
            this.Page_Count_Label.Size = new System.Drawing.Size(154, 20);
            this.Page_Count_Label.TabIndex = 10;
            this.Page_Count_Label.Text = "Количество страниц:";
            // 
            // Count_Of_Page_numericUpDown
            // 
            this.Count_Of_Page_numericUpDown.Location = new System.Drawing.Point(221, 364);
            this.Count_Of_Page_numericUpDown.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.Count_Of_Page_numericUpDown.Name = "Count_Of_Page_numericUpDown";
            this.Count_Of_Page_numericUpDown.Size = new System.Drawing.Size(246, 27);
            this.Count_Of_Page_numericUpDown.TabIndex = 11;
            this.Count_Of_Page_numericUpDown.ValueChanged += new System.EventHandler(this.Count_Of_Page_numericUpDown_ValueChanged);
            // 
            // PublishHouse_Label
            // 
            this.PublishHouse_Label.AutoSize = true;
            this.PublishHouse_Label.Location = new System.Drawing.Point(11, 435);
            this.PublishHouse_Label.Name = "PublishHouse_Label";
            this.PublishHouse_Label.Size = new System.Drawing.Size(150, 20);
            this.PublishHouse_Label.TabIndex = 12;
            this.PublishHouse_Label.Text = "Издательство книги:";
            // 
            // Publisher_checkedListBox
            // 
            this.Publisher_checkedListBox.FormattingEnabled = true;
            this.Publisher_checkedListBox.Items.AddRange(new object[] {
            "Беларусь",
            "Россия",
            "Польша",
            "Литва"});
            this.Publisher_checkedListBox.Location = new System.Drawing.Point(221, 435);
            this.Publisher_checkedListBox.Name = "Publisher_checkedListBox";
            this.Publisher_checkedListBox.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.Publisher_checkedListBox.Size = new System.Drawing.Size(246, 26);
            this.Publisher_checkedListBox.TabIndex = 13;
            this.Publisher_checkedListBox.Tag = "";
            this.Publisher_checkedListBox.SelectedIndexChanged += new System.EventHandler(this.Publisher_checkedListBox_SelectedIndexChanged);
            // 
            // Year_Of_Creating_Label
            // 
            this.Year_Of_Creating_Label.AutoSize = true;
            this.Year_Of_Creating_Label.Location = new System.Drawing.Point(11, 499);
            this.Year_Of_Creating_Label.Name = "Year_Of_Creating_Label";
            this.Year_Of_Creating_Label.Size = new System.Drawing.Size(193, 20);
            this.Year_Of_Creating_Label.TabIndex = 14;
            this.Year_Of_Creating_Label.Text = "Год создания книги книги:";
            // 
            // Year_Of_Creating_numericUpDown
            // 
            this.Year_Of_Creating_numericUpDown.Location = new System.Drawing.Point(221, 499);
            this.Year_Of_Creating_numericUpDown.Maximum = new decimal(new int[] {
            2023,
            0,
            0,
            0});
            this.Year_Of_Creating_numericUpDown.Minimum = new decimal(new int[] {
            2000,
            0,
            0,
            0});
            this.Year_Of_Creating_numericUpDown.Name = "Year_Of_Creating_numericUpDown";
            this.Year_Of_Creating_numericUpDown.Size = new System.Drawing.Size(246, 27);
            this.Year_Of_Creating_numericUpDown.TabIndex = 15;
            this.Year_Of_Creating_numericUpDown.Value = new decimal(new int[] {
            2000,
            0,
            0,
            0});
            this.Year_Of_Creating_numericUpDown.ValueChanged += new System.EventHandler(this.Year_Of_Creating_numericUpDown_ValueChanged);
            // 
            // Authors_Label
            // 
            this.Authors_Label.AutoSize = true;
            this.Authors_Label.Location = new System.Drawing.Point(11, 605);
            this.Authors_Label.Name = "Authors_Label";
            this.Authors_Label.Size = new System.Drawing.Size(65, 20);
            this.Authors_Label.TabIndex = 16;
            this.Authors_Label.Text = "Авторы:";
            // 
            // Authors_listBox
            // 
            this.Authors_listBox.FormattingEnabled = true;
            this.Authors_listBox.ItemHeight = 20;
            this.Authors_listBox.Location = new System.Drawing.Point(122, 605);
            this.Authors_listBox.Name = "Authors_listBox";
            this.Authors_listBox.Size = new System.Drawing.Size(292, 104);
            this.Authors_listBox.TabIndex = 17;
            this.Authors_listBox.SelectedIndexChanged += new System.EventHandler(this.Authors_listBox_SelectedIndexChanged);
            // 
            // Add_Author_button
            // 
            this.Add_Author_button.Location = new System.Drawing.Point(422, 607);
            this.Add_Author_button.Name = "Add_Author_button";
            this.Add_Author_button.Size = new System.Drawing.Size(94, 104);
            this.Add_Author_button.TabIndex = 18;
            this.Add_Author_button.Text = "Добавить";
            this.Add_Author_button.UseVisualStyleBackColor = true;
            this.Add_Author_button.Click += new System.EventHandler(this.Add_Author_button_Click);
            // 
            // Save_info_button
            // 
            this.Save_info_button.Location = new System.Drawing.Point(619, 96);
            this.Save_info_button.Name = "Save_info_button";
            this.Save_info_button.Size = new System.Drawing.Size(211, 83);
            this.Save_info_button.TabIndex = 19;
            this.Save_info_button.Text = "Сохранить данные";
            this.Save_info_button.UseVisualStyleBackColor = true;
            this.Save_info_button.Click += new System.EventHandler(this.Save_info_button_Click);
            // 
            // Science_RadioButton
            // 
            this.Science_RadioButton.AutoSize = true;
            this.Science_RadioButton.Location = new System.Drawing.Point(221, 100);
            this.Science_RadioButton.Name = "Science_RadioButton";
            this.Science_RadioButton.Size = new System.Drawing.Size(89, 24);
            this.Science_RadioButton.TabIndex = 23;
            this.Science_RadioButton.TabStop = true;
            this.Science_RadioButton.Text = "Научная";
            this.Science_RadioButton.UseVisualStyleBackColor = true;
            this.Science_RadioButton.CheckedChanged += new System.EventHandler(this.Science_RadioButton_CheckedChanged);
            // 
            // Artistic_RadioButton
            // 
            this.Artistic_RadioButton.AutoSize = true;
            this.Artistic_RadioButton.Location = new System.Drawing.Point(322, 100);
            this.Artistic_RadioButton.Name = "Artistic_RadioButton";
            this.Artistic_RadioButton.Size = new System.Drawing.Size(145, 24);
            this.Artistic_RadioButton.TabIndex = 24;
            this.Artistic_RadioButton.TabStop = true;
            this.Artistic_RadioButton.Text = "Художественная";
            this.Artistic_RadioButton.UseVisualStyleBackColor = true;
            this.Artistic_RadioButton.CheckedChanged += new System.EventHandler(this.Artistic_RadioButton_CheckedChanged);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(618, 208);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(212, 60);
            this.button1.TabIndex = 25;
            this.button1.Text = "Вывести данные";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(618, 297);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(212, 74);
            this.button2.TabIndex = 26;
            this.button2.Text = "Добавить книгу";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1541, 753);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.Artistic_RadioButton);
            this.Controls.Add(this.Science_RadioButton);
            this.Controls.Add(this.Save_info_button);
            this.Controls.Add(this.Add_Author_button);
            this.Controls.Add(this.Authors_listBox);
            this.Controls.Add(this.Authors_Label);
            this.Controls.Add(this.Year_Of_Creating_numericUpDown);
            this.Controls.Add(this.Year_Of_Creating_Label);
            this.Controls.Add(this.Publisher_checkedListBox);
            this.Controls.Add(this.PublishHouse_Label);
            this.Controls.Add(this.Count_Of_Page_numericUpDown);
            this.Controls.Add(this.Page_Count_Label);
            this.Controls.Add(this.UDK_textBox);
            this.Controls.Add(this.UDK_Label);
            this.Controls.Add(this.Book_Size_domainUpDown);
            this.Controls.Add(this.Book_Name_textBox);
            this.Controls.Add(this.Book_Name_Label);
            this.Controls.Add(this.Book_Type_Label);
            this.Controls.Add(this.Book_Size_Label);
            this.Controls.Add(this.Book_Info_Label);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.Count_Of_Page_numericUpDown)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Year_Of_Creating_numericUpDown)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Label Book_Info_Label;
        private Label Book_Size_Label;
        private Label Book_Type_Label;
        private TextBox Book_Name_textBox;
        private Label Book_Name_Label;
        private DomainUpDown Book_Size_domainUpDown;
        private TextBox UDK_textBox;
        private Label UDK_Label;
        private Label Page_Count_Label;
        private NumericUpDown Count_Of_Page_numericUpDown;
        private Label PublishHouse_Label;
        private CheckedListBox Publisher_checkedListBox;
        private Label Year_Of_Creating_Label;
        private NumericUpDown Year_Of_Creating_numericUpDown;
        private Label Authors_Label;
        private ListBox Authors_listBox;
        private Button Add_Author_button;
        private Button Save_info_button;
        private RadioButton Science_RadioButton;
        private RadioButton Artistic_RadioButton;
        private Button button1;
        private Button button2;
    }
   
}