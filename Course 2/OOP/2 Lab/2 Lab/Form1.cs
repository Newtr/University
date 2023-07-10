using System.Text.Json;
using System.Xml.Serialization;

namespace _2_Lab
{

    public partial class Form1 : Form
    {
        protected Book MyBook = new();
        public string str = "";
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void domainUpDown1_SelectedItemChanged(object sender, EventArgs e)
        {

        }

        private void Save_info_button_Click(object sender, EventArgs e)
        {
            try
            {
                if(Science_RadioButton.Checked) 
                {
                    MyBook.type = Science_RadioButton.Text;
                }
                if(Artistic_RadioButton.Checked)
                {
                    MyBook.type = Artistic_RadioButton.Text;
                }
                MyBook.book_size = Convert.ToDouble(Book_Size_domainUpDown.Text);
                MyBook.name = Book_Name_textBox.Text;
                MyBook.UDK = Convert.ToInt32(UDK_textBox.Text);
                MyBook.count_of_page = Convert.ToInt32(Count_Of_Page_numericUpDown.Text);
                MyBook.publishing_house = Publisher_checkedListBox.Text;
                MyBook.year = Convert.ToInt32(Year_Of_Creating_numericUpDown.Text);
                Author MyAuthor = new Author();
                Author MyAuthor2 = new Author();
                XmlSerializer xml_Formatter = new XmlSerializer(typeof(Author));
                using (FileStream FS = new FileStream("D://��������� ����//1.���//2 Lab//2 Lab//2 Lab//XML_Ser.xml", FileMode.OpenOrCreate))
                {
                    MyAuthor = xml_Formatter.Deserialize(FS) as Author;

                    MessageBox.Show("������ ��������������!");

                }
                //File.Delete("D://��������� ����//1.���//2 Lab//2 Lab//2 Lab//XML_Ser.xml");
                MyBook.authors.Add(MyAuthor);
                Authors_listBox.Items.Add(MyAuthor.FIO);
                str = $"���: {MyBook.type} \n ������: {MyBook.book_size} \n ��������: {MyBook.name} \n ���: {MyBook.UDK} \n ���������� �������: {MyBook.count_of_page} \n ��������: {MyBook.publishing_house} \n ���: {MyBook.year} \n �����: {MyBook.year}";
                foreach(var example in MyBook.authors)
                {
                    str += $"\n �����: {example.FIO}\n";
                }
                    StreamWriter sw = new StreamWriter("D://��������� ����//1.���//2 Lab//2 Lab//2 Lab//Book_info.txt", true);
                    sw.WriteLine(str);
                    sw.Close();
            }
            catch
            {
                MessageBox.Show("������ ���� ������� �����������!");
            }
        }

        private void Science_RadioButton_CheckedChanged(object sender, EventArgs e)
        {
            
        }

        private void Artistic_RadioButton_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void UDK_textBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void Book_Name_textBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void Count_Of_Page_numericUpDown_ValueChanged(object sender, EventArgs e)
        {

        }

        private void Publisher_checkedListBox_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Year_Of_Creating_numericUpDown_ValueChanged(object sender, EventArgs e)
        {

        }
        private void Add_Author_button_Click(object sender, EventArgs e)
        {
            Form2 F2 = new Form2();
            F2.ShowDialog();
        }

        private void Authors_listBox_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            StreamReader sr = new StreamReader("D://��������� ����//1.���//2 Lab//2 Lab//2 Lab//Book_info.txt");
            string line = sr.ReadLine();
            string result = "";
            while (line != null)
            {
                line = sr.ReadLine();
                result += line;
                result += "\n";
            }
            MessageBox.Show(result);
            sr.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form3 F3 = new Form3();
            F3.ShowDialog();
            this.Close();
        }
    }
}