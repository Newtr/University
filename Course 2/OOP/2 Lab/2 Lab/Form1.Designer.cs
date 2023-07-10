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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
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
            this.button3 = new System.Windows.Forms.Button();
            this.Info_Box = new System.Windows.Forms.ListBox();
            this.Search_textbox = new System.Windows.Forms.TextBox();
            this.Search_button = new System.Windows.Forms.Button();
            this.sort_by_name = new System.Windows.Forms.Button();
            this.sort_by_date = new System.Windows.Forms.Button();
            this.Tool_bar = new System.Windows.Forms.ToolStrip();
            this.toolStripTextBox1 = new System.Windows.Forms.ToolStripTextBox();
            this.toolStripButton3 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton1 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton2 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton4 = new System.Windows.Forms.ToolStripButton();
            this.Vpered = new System.Windows.Forms.ToolStripButton();
            this.Nazad = new System.Windows.Forms.ToolStripButton();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.Last_Move = new System.Windows.Forms.ListBox();
            ((System.ComponentModel.ISupportInitialize)(this.Count_Of_Page_numericUpDown)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Year_Of_Creating_numericUpDown)).BeginInit();
            this.Tool_bar.SuspendLayout();
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
            this.Add_Author_button.Location = new System.Drawing.Point(422, 605);
            this.Add_Author_button.Name = "Add_Author_button";
            this.Add_Author_button.Size = new System.Drawing.Size(94, 106);
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
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(892, 100);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(156, 77);
            this.button3.TabIndex = 27;
            this.button3.Text = "О программе";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // Info_Box
            // 
            this.Info_Box.FormattingEnabled = true;
            this.Info_Box.HorizontalScrollbar = true;
            this.Info_Box.ItemHeight = 20;
            this.Info_Box.Location = new System.Drawing.Point(619, 404);
            this.Info_Box.Name = "Info_Box";
            this.Info_Box.Size = new System.Drawing.Size(1143, 304);
            this.Info_Box.TabIndex = 28;
            this.Info_Box.SelectedIndexChanged += new System.EventHandler(this.Info_Box_SelectedIndexChanged);
            // 
            // Search_textbox
            // 
            this.Search_textbox.Location = new System.Drawing.Point(618, 728);
            this.Search_textbox.Name = "Search_textbox";
            this.Search_textbox.Size = new System.Drawing.Size(190, 27);
            this.Search_textbox.TabIndex = 29;
            // 
            // Search_button
            // 
            this.Search_button.Location = new System.Drawing.Point(833, 728);
            this.Search_button.Name = "Search_button";
            this.Search_button.Size = new System.Drawing.Size(94, 29);
            this.Search_button.TabIndex = 30;
            this.Search_button.Text = "Поиск";
            this.Search_button.UseVisualStyleBackColor = true;
            this.Search_button.Click += new System.EventHandler(this.Search_button_Click);
            // 
            // sort_by_name
            // 
            this.sort_by_name.Location = new System.Drawing.Point(955, 728);
            this.sort_by_name.Name = "sort_by_name";
            this.sort_by_name.Size = new System.Drawing.Size(207, 29);
            this.sort_by_name.TabIndex = 31;
            this.sort_by_name.Text = "сортировка по названию";
            this.sort_by_name.UseVisualStyleBackColor = true;
            this.sort_by_name.Click += new System.EventHandler(this.sort_by_name_Click);
            // 
            // sort_by_date
            // 
            this.sort_by_date.Location = new System.Drawing.Point(1186, 728);
            this.sort_by_date.Name = "sort_by_date";
            this.sort_by_date.Size = new System.Drawing.Size(207, 29);
            this.sort_by_date.TabIndex = 32;
            this.sort_by_date.Text = "сортировка по дате";
            this.sort_by_date.UseVisualStyleBackColor = true;
            this.sort_by_date.Click += new System.EventHandler(this.sort_by_date_Click);
            // 
            // Tool_bar
            // 
            this.Tool_bar.BackColor = System.Drawing.SystemColors.AppWorkspace;
            this.Tool_bar.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.Tool_bar.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripTextBox1,
            this.toolStripButton3,
            this.toolStripButton1,
            this.toolStripButton2,
            this.toolStripButton4,
            this.Vpered,
            this.Nazad});
            this.Tool_bar.Location = new System.Drawing.Point(0, 0);
            this.Tool_bar.Name = "Tool_bar";
            this.Tool_bar.Size = new System.Drawing.Size(1789, 27);
            this.Tool_bar.TabIndex = 33;
            this.Tool_bar.Text = "toolStrip1";
            // 
            // toolStripTextBox1
            // 
            this.toolStripTextBox1.ForeColor = System.Drawing.Color.Black;
            this.toolStripTextBox1.Name = "toolStripTextBox1";
            this.toolStripTextBox1.Size = new System.Drawing.Size(100, 27);
            this.toolStripTextBox1.Text = "Поиск";
            this.toolStripTextBox1.Click += new System.EventHandler(this.toolStripTextBox1_Click);
            // 
            // toolStripButton3
            // 
            this.toolStripButton3.BackColor = System.Drawing.SystemColors.ControlLight;
            this.toolStripButton3.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.toolStripButton3.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton3.Image")));
            this.toolStripButton3.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton3.Name = "toolStripButton3";
            this.toolStripButton3.Size = new System.Drawing.Size(60, 24);
            this.toolStripButton3.Text = "Искать";
            this.toolStripButton3.Click += new System.EventHandler(this.toolStripButton3_Click);
            // 
            // toolStripButton1
            // 
            this.toolStripButton1.BackColor = System.Drawing.SystemColors.ControlLight;
            this.toolStripButton1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.toolStripButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton1.Image")));
            this.toolStripButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton1.Name = "toolStripButton1";
            this.toolStripButton1.Size = new System.Drawing.Size(192, 24);
            this.toolStripButton1.Text = "Сортировка по названию";
            this.toolStripButton1.Click += new System.EventHandler(this.toolStripButton1_Click);
            // 
            // toolStripButton2
            // 
            this.toolStripButton2.BackColor = System.Drawing.SystemColors.ControlLight;
            this.toolStripButton2.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.toolStripButton2.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton2.Image")));
            this.toolStripButton2.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton2.Name = "toolStripButton2";
            this.toolStripButton2.Size = new System.Drawing.Size(152, 24);
            this.toolStripButton2.Text = "Сортировка по дате";
            this.toolStripButton2.Click += new System.EventHandler(this.toolStripButton2_Click);
            // 
            // toolStripButton4
            // 
            this.toolStripButton4.BackColor = System.Drawing.SystemColors.ControlLight;
            this.toolStripButton4.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.toolStripButton4.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton4.Image")));
            this.toolStripButton4.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton4.Name = "toolStripButton4";
            this.toolStripButton4.Size = new System.Drawing.Size(77, 24);
            this.toolStripButton4.Text = "Очистить";
            this.toolStripButton4.Click += new System.EventHandler(this.toolStripButton4_Click);
            // 
            // Vpered
            // 
            this.Vpered.BackColor = System.Drawing.SystemColors.ControlLight;
            this.Vpered.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.Vpered.Image = ((System.Drawing.Image)(resources.GetObject("Vpered.Image")));
            this.Vpered.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.Vpered.Name = "Vpered";
            this.Vpered.Size = new System.Drawing.Size(64, 24);
            this.Vpered.Text = "Вперед";
            this.Vpered.Click += new System.EventHandler(this.toolStripButton5_Click);
            // 
            // Nazad
            // 
            this.Nazad.BackColor = System.Drawing.SystemColors.ControlLight;
            this.Nazad.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.Nazad.Image = ((System.Drawing.Image)(resources.GetObject("Nazad.Image")));
            this.Nazad.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.Nazad.Name = "Nazad";
            this.Nazad.Size = new System.Drawing.Size(55, 24);
            this.Nazad.Text = "Назад";
            this.Nazad.Click += new System.EventHandler(this.Nazad_Click);
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Location = new System.Drawing.Point(1660, 30);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(68, 24);
            this.radioButton1.TabIndex = 34;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "Выкл.";
            this.radioButton1.UseVisualStyleBackColor = true;
            this.radioButton1.CheckedChanged += new System.EventHandler(this.radioButton1_CheckedChanged);
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(1660, 66);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(57, 24);
            this.radioButton2.TabIndex = 35;
            this.radioButton2.TabStop = true;
            this.radioButton2.Text = "Вкл.";
            this.radioButton2.UseVisualStyleBackColor = true;
            this.radioButton2.CheckedChanged += new System.EventHandler(this.radioButton2_CheckedChanged);
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(1492, 114);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.Size = new System.Drawing.Size(285, 63);
            this.richTextBox1.TabIndex = 36;
            this.richTextBox1.Text = "";
            // 
            // Last_Move
            // 
            this.Last_Move.FormattingEnabled = true;
            this.Last_Move.ItemHeight = 20;
            this.Last_Move.Location = new System.Drawing.Point(1381, 197);
            this.Last_Move.Name = "Last_Move";
            this.Last_Move.Size = new System.Drawing.Size(396, 44);
            this.Last_Move.TabIndex = 37;
            this.Last_Move.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1789, 857);
            this.Controls.Add(this.Last_Move);
            this.Controls.Add(this.richTextBox1);
            this.Controls.Add(this.radioButton2);
            this.Controls.Add(this.radioButton1);
            this.Controls.Add(this.Tool_bar);
            this.Controls.Add(this.sort_by_date);
            this.Controls.Add(this.sort_by_name);
            this.Controls.Add(this.Search_button);
            this.Controls.Add(this.Search_textbox);
            this.Controls.Add(this.Info_Box);
            this.Controls.Add(this.button3);
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
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.Count_Of_Page_numericUpDown)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Year_Of_Creating_numericUpDown)).EndInit();
            this.Tool_bar.ResumeLayout(false);
            this.Tool_bar.PerformLayout();
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
        private Button button3;
        private ListBox Info_Box;
        private TextBox Search_textbox;
        private Button Search_button;
        private Button sort_by_name;
        private Button sort_by_date;
        private ToolStrip Tool_bar;
        private ToolStripTextBox toolStripTextBox1;
        private ToolStripButton toolStripButton1;
        private ToolStripButton toolStripButton2;
        private ToolStripButton toolStripButton3;
        private RadioButton radioButton1;
        private RadioButton radioButton2;
        private ToolStripButton toolStripButton4;
        private ToolStripButton Vpered;
        private ToolStripButton Nazad;
        private System.Windows.Forms.Timer timer1;
        private RichTextBox richTextBox1;
        private ListBox Last_Move;
    }
   
}