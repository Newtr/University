using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Serialization;

namespace _2_Lab
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void flowLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)  //кнопка сохранить 2 форма
        {
            Author MyAuthor = new Author();
            MyAuthor.FIO = maskedTextBox1.Text;
            if(radioButton1.Checked)
            {
                MyAuthor.country = "Belarus";
            }
            if (radioButton2.Checked)
            {
                MyAuthor.country = "Lithuania";
            }
            if (radioButton3.Checked)
            {
                MyAuthor.country = "Russia";
            }
            if (radioButton4.Checked)
            {
                MyAuthor.country = "Poland";
            }
            MyAuthor.ID = Convert.ToInt32(numericUpDown1.Text);
            MyAuthor.age= Convert.ToInt32(numericUpDown2.Text);
            XmlSerializer xml_Formatter = new XmlSerializer(typeof(Author));
            using (FileStream FS = new FileStream("D://Документы БГТУ//1.ООП//2 Lab//2 Lab//2 Lab//XML_Ser.xml", FileMode.OpenOrCreate))
            {
                xml_Formatter.Serialize(FS, MyAuthor);

                MessageBox.Show("Объект сериализован!");
            }
            this.Close();
        }

        private void maskedTextBox1_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }

        private void radioButton4_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void numericUpDown2_ValueChanged(object sender, EventArgs e)
        {

        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {

        }
    }
}
