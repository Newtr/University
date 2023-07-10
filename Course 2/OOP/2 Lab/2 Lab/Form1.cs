using System.ComponentModel.DataAnnotations;
using System.Configuration;
using System.Security;
using System.Text.Json;
using System.Web;
using System.Xml.Linq;
using System.Xml.Serialization;

namespace _2_Lab
{

    public partial class Form1 : Form
    {
        protected Book MyBook = new();
        public string[] new_infoYYY = new string[5];
        public string str = "";
        public int last_move = 0;
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
            Last_Move.Items.Clear();
            Last_Move.Items.Add("Была нажата кнопка [СОХРАНИТЬ ДАННЫЕ]");
            UDK udk = new();
            try
            {
                udk.ID = Convert.ToInt32(UDK_textBox.Text);
            }
            catch (Exception)
            {
                MessageBox.Show("УДК книги может быть только число");
                return;
            }
            var results = new List<ValidationResult>();
            var context = new ValidationContext(udk);
            if (!Validator.TryValidateObject(udk, context, results, true))
            {
                string errors = "";
                foreach (var error in results)
                {
                    errors += error.ErrorMessage + "\n";
                }
                MessageBox.Show(errors, "УДК книги может быть только число");

                return;
            }

            if (Science_RadioButton.Checked) 
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
                using (FileStream FS = new FileStream("D://Документы БГТУ//1.ООП//3 Lab//2 Lab//2 Lab//XML_Ser.xml", FileMode.OpenOrCreate))
                {
                    MyAuthor = xml_Formatter.Deserialize(FS) as Author;

                    MessageBox.Show("Объект десириализован!");

                }
                File.Delete("D://Документы БГТУ//1.ООП//3 Lab//2 Lab//2 Lab//XML_Ser.xml");
                MyBook.authors.Add(MyAuthor);
                Authors_listBox.Items.Add(MyAuthor.FIO);
                str = $"[тип: {MyBook.type}] \n[размер: {MyBook.book_size}] \n[название: {MyBook.name}] \n[УДК: {MyBook.UDK}] \n[количество страниц: {MyBook.count_of_page}] \n[издатель: {MyBook.publishing_house}] \n[год: {MyBook.year}] \n[время: {MyBook.upload_date}]";
                Info_Box.Items.Add(str);
                foreach(var example in MyBook.authors)
                {
                    str += $"\n[автор: {example.FIO}]\n";
                }
                    StreamWriter sw = new StreamWriter("D://Документы БГТУ//1.ООП//3 Lab//2 Lab//2 Lab//Book_info.txt", true);
                    sw.WriteLine(str);
                   sw.Close();

                
        }

        private void Science_RadioButton_CheckedChanged(object sender, EventArgs e)
        {
            
        }

        private void Artistic_RadioButton_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void UDK_textBox_TextChanged(object sender, KeyPressEventArgs e)
        {
            char number = e.KeyChar;
            if(!Char.IsDigit(number))
            {
                MessageBox.Show("POKA DURA");
            }
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
            Last_Move.Items.Clear();
            Last_Move.Items.Add("Была нажата кнопка [ВЫВЕСТИ ДАННЫЕ]");
            StreamReader sr = new StreamReader("D://Документы БГТУ//1.ООП//3 Lab//2 Lab//2 Lab//Book_info.txt");
            string line = "";
            string result = "";
            string for_info = "";
            while (line != null)
            {
                line = sr.ReadLine();
                result += line;
                for_info += line;
                if (line == "" || line == null)
                {
                    Info_Box.Items.Add(for_info);
                    for_info = "";
                }
                result += "\n";
            }
            last_move += 1;
            string info = "";
            info = $"#{last_move}\n";
            string line1 = "";
            StreamWriter wr = new StreamWriter("D://Документы БГТУ//1.ООП//3 Lab//2 Lab//2 Lab//info.txt", true);
            string result1 = "";
            string for_info1 = "";
            for (int i = 0; i < Info_Box.Items.Count; ++i)
            {
                line1 = Info_Box.Items[i].ToString();
                result1 += line1;
                for_info1 += line1;
                if (line1 == "" || line1 == null)
                {
                    Info_Box.Items.Add(for_info1);
                    for_info1 = "";
                }
                result1 += "\n";
            }
            info += result1;
            //MessageBox.Show(result);
            wr.WriteLine(info);
            wr.Close();
            sr.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Last_Move.Items.Clear();
            Last_Move.Items.Add("Была нажата кнопка [ДОБАВИТЬ КНИГУ]");
            Authors_listBox.Items.Clear();
/*            Form3 F3 = new Form3();
            F3.ShowDialog();
            this.Close();*/
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Last_Move.Items.Clear();
            Last_Move.Items.Add("Была нажата кнопка [О ПРОГРАММЕ]");
            MessageBox.Show("Версия: 3.0\nРазработчик: Тышкевич Роман Антонович");
        }

        private void Info_Box_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Search_button_Click(object sender, EventArgs e)
        {
            Last_Move.Items.Clear();
            Last_Move.Items.Add("Была нажата кнопка [ПОИСК]");
            string search = Search_textbox.Text;
            string search_result = "";
            if (search.Contains("-"))
            {
                int index1 = search.IndexOf("-");
                int first, second, newnumb, index2;
                first = Convert.ToInt32(search.Substring(0, index1));
                second = Convert.ToInt32((search.Substring(index1 + 1)));
                for (int j = 0; j < Info_Box.Items.Count; j++)
                {
                    index1 = Info_Box.Items[j].ToString().IndexOf("количество страниц: ");
                    index1 += 20;
                    index2 = Info_Box.Items[j].ToString().IndexOf("[издатель:");
                    index2 -= 2;
                    newnumb = Convert.ToInt32(Info_Box.Items[j].ToString().Substring(index1,index2-index1));
                    if(newnumb >= first && newnumb <= second)
                    {
                        search_result += Info_Box.Items[j].ToString();
                        search_result += "\n";
                    }
                }
                MessageBox.Show($"[ПО ИТОГАМ ПОИСКА]\n{search_result}");
            }
            for (int i = 0; i < Info_Box.Items.Count; i++)
            {
                if (Info_Box.Items[i].ToString().Contains(search))
                {
                    search_result += Info_Box.Items[i].ToString();
                    search_result += "\n";
                }
            }
            MessageBox.Show($"[ПО ИТОГАМ ПОИСКА]\n{search_result}");
        }

        private void sort_by_name_Click(object sender, EventArgs e)
        {
            Last_Move.Items.Clear();
            Last_Move.Items.Add("Была нажата кнопка [СОРТИРОВКА ПО НАЗВАНИЮ]");
            string[] all_info = new string[Info_Box.Items.Count];
            for (int i = 0; i < Info_Box.Items.Count; i++)
            {
                all_info[i] = Info_Box.Items[i].ToString();
            }
            string[] names = new string[all_info.Length];
            int index1, index2;
            for (int i = 0; i < Info_Box.Items.Count; i++)
            {
                index1 = Info_Box.Items[i].ToString().IndexOf("[название: ");
                index1 += 11;
                index2 = Info_Box.Items[i].ToString().IndexOf("] [УДК");
                names[i] = all_info[i].ToString().Substring(index1, index2 - index1);
            }
            var sorted_names = from name in names
                               orderby name
                               select name;
            string[] right_info = new string[all_info.Length];
            for (int i = 0; i < Info_Box.Items.Count; i++)
            {
                for (int j = 0; j < Info_Box.Items.Count; j++)
                {
                    if (Info_Box.Items[j].ToString().Contains(sorted_names.ElementAt(i).ToString()))
                    {
                        right_info[i] = all_info[j].ToString();
                        
                    }
                }
            }
            Info_Box.Items.Clear();
            for (int i = 0; i < right_info.Length; i++)
            {
                Info_Box.Items.Add(right_info[i]);
                
            }
            last_move += 1;
            string info = "";
            info = $"#{last_move}\n";
            string line = "";
            StreamWriter wr = new StreamWriter("D://Документы БГТУ//1.ООП//3 Lab//2 Lab//2 Lab//info.txt", true);
            string result = "";
            string for_info = "";
            for(int i = 0; i < Info_Box.Items.Count;++i) 
            {
                line = Info_Box.Items[i].ToString();
                result += line;
                for_info += line;
                if (line == "" || line == null)
                {
                    Info_Box.Items.Add(for_info);
                    for_info = "";
                }
                result += "\n";
            }
            info += result;
            //MessageBox.Show(result);
            wr.WriteLine(info);
            wr.Close();
        }

        private void sort_by_date_Click(object sender, EventArgs e)
        {
            Last_Move.Items.Clear();
            Last_Move.Items.Add("Была нажата кнопка [СОРТИРОВКА ПО ДАТЕ]");
            string[] all_info = new string[Info_Box.Items.Count];
            for (int i = 0; i < Info_Box.Items.Count; i++)
            {
                all_info[i] = Info_Box.Items[i].ToString();
            }
            string[] dates = new string[all_info.Length];
            string prom1 = "", prom2 = "";
            int index1, index2;
            for (int i = 0; i < Info_Box.Items.Count; i++)
            {
                index1 = Info_Box.Items[i].ToString().IndexOf("[время: ");
                index1 += 8;
                index2 = Info_Box.Items[i].ToString().IndexOf("][автор");
                prom1 = all_info[i].ToString().Substring(index1, index2 - index1);
                prom2 += prom1.Substring(0, 3);
                prom2 += prom1.Substring(3, 3);
                prom2 += prom1.Substring(6, 4);
                dates[i] = prom2;
                prom2 = "";
            }
            var sorted_dates = from date in dates
                               orderby date
                               select date;
            string[] right_info = new string[all_info.Length];
            for (int i = 0; i < Info_Box.Items.Count; i++)
            {
                for (int j = 0; j < Info_Box.Items.Count; j++)
                {
                    if (Info_Box.Items[j].ToString().Contains(sorted_dates.ElementAt(i).ToString()))
                    {
                        right_info[i] = all_info[j].ToString();
                    }
                }
            }
            Info_Box.Items.Clear();
            for (int i = 0; i < right_info.Length; i++)
            {
                Info_Box.Items.Add(right_info[i]);
            }
            last_move += 1;
            string info = "";
            info = $"#{last_move}\n";
            string line = "";
            StreamWriter wr = new StreamWriter("D://Документы БГТУ//1.ООП//3 Lab//2 Lab//2 Lab//info.txt", true);
            string result = "";
            string for_info = "";
            for (int i = 0; i < Info_Box.Items.Count; ++i)
            {
                line = Info_Box.Items[i].ToString();
                result += line;
                for_info += line;
                if (line == "" || line == null)
                {
                    Info_Box.Items.Add(for_info);
                    for_info = "";
                }
                result += "\n";
            }
            info += result;
            //MessageBox.Show(result);
            wr.WriteLine(info);
            wr.Close();
        }

        private void toolStripTextBox1_Click(object sender, EventArgs e)
        {
            
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            Last_Move.Items.Clear();
            Last_Move.Items.Add("Была нажата кнопка [СОРТИРОВКА ПО НАЗВАНИЮ]");
            string[] all_info = new string[Info_Box.Items.Count];
            for (int i = 0; i < Info_Box.Items.Count; i++)
            {
                all_info[i] = Info_Box.Items[i].ToString();
            }
            string[] names = new string[all_info.Length];
            int index1, index2;
            for (int i = 0; i < Info_Box.Items.Count; i++)
            {
                index1 = Info_Box.Items[i].ToString().IndexOf("[название: ");
                index1 += 11;
                index2 = Info_Box.Items[i].ToString().IndexOf("] [УДК");
                names[i] = all_info[i].ToString().Substring(index1, index2 - index1);
            }
            var sorted_names = from name in names
                               orderby name
                               select name;
            string[] right_info = new string[all_info.Length];
            for (int i = 0; i < Info_Box.Items.Count; i++)
            {
                for (int j = 0; j < Info_Box.Items.Count; j++)
                {
                    if (Info_Box.Items[j].ToString().Contains(sorted_names.ElementAt(i).ToString()))
                    {
                        right_info[i] = all_info[j].ToString();
                    }
                }
            }
            Info_Box.Items.Clear();
            for (int i = 0; i < right_info.Length; i++)
            {
                Info_Box.Items.Add(right_info[i]);
                new_infoYYY[i] = "";
                new_infoYYY[i] = right_info[i].ToString();
            }
            last_move += 1;
            string info = "";
            info = $"#{last_move}\n";
            string line = "";
            StreamWriter wr = new StreamWriter("D://Документы БГТУ//1.ООП//3 Lab//2 Lab//2 Lab//info.txt", true);
            string result = "";
            string for_info = "";
            for (int i = 0; i < Info_Box.Items.Count; ++i)
            {
                line = Info_Box.Items[i].ToString();
                result += line;
                for_info += line;
                if (line == "" || line == null)
                {
                    Info_Box.Items.Add(for_info);
                    for_info = "";
                }
                result += "\n";
            }
            info += result;
            //MessageBox.Show(result);
            wr.WriteLine(info);
            wr.Close();
        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            Last_Move.Items.Clear();
            Last_Move.Items.Add("Была нажата кнопка [СОРТИРОВКА ПО ДАТЕ]");
            string[] all_info = new string[Info_Box.Items.Count];
            for (int i = 0; i < Info_Box.Items.Count; i++)
            {
                all_info[i] = Info_Box.Items[i].ToString();
            }
            string[] dates = new string[all_info.Length];
            string prom1 = "", prom2 = "";
            int index1, index2;
            for (int i = 0; i < Info_Box.Items.Count; i++)
            {
                index1 = Info_Box.Items[i].ToString().IndexOf("[время: ");
                index1 += 8;
                index2 = Info_Box.Items[i].ToString().IndexOf("][автор");
                prom1 = all_info[i].ToString().Substring(index1, index2 - index1);
                prom2 += prom1.Substring(0, 3);
                prom2 += prom1.Substring(3, 3);
                prom2 += prom1.Substring(6, 4);
                dates[i] = prom2;
                prom2 = "";
            }
            var sorted_dates = from date in dates
                               orderby date
                               select date;
            string[] right_info = new string[all_info.Length];
            for (int i = 0; i < Info_Box.Items.Count; i++)
            {
                for (int j = 0; j < Info_Box.Items.Count; j++)
                {
                    if (Info_Box.Items[j].ToString().Contains(sorted_dates.ElementAt(i).ToString()))
                    {
                        right_info[i] = all_info[j].ToString();
                    }
                }
            }
            Info_Box.Items.Clear();
            for (int i = 0; i < right_info.Length; i++)
            {
                Info_Box.Items.Add(right_info[i]);
                new_infoYYY[i] = "";
                new_infoYYY[i] = right_info[i].ToString();
            }
            last_move += 1;
            string info = "";
            info = $"#{last_move}\n";
            string line = "";
            StreamWriter wr = new StreamWriter("D://Документы БГТУ//1.ООП//3 Lab//2 Lab//2 Lab//info.txt", true);
            string result = "";
            string for_info = "";
            for (int i = 0; i < Info_Box.Items.Count; ++i)
            {
                line = Info_Box.Items[i].ToString();
                result += line;
                for_info += line;
                if (line == "" || line == null)
                {
                    Info_Box.Items.Add(for_info);
                    for_info = "";
                }
                result += "\n";
            }
            info += result;
            //MessageBox.Show(result);
            wr.WriteLine(info);
            wr.Close();
        }

        private void toolStripButton3_Click(object sender, EventArgs e)
        {
            Last_Move.Items.Clear();
            Last_Move.Items.Add("Была нажата кнопка [ИСКАТЬ]");
            string search = toolStripTextBox1.Text;
            string search_result = "";
            if (search.Contains("-"))
            {
                int index1 = search.IndexOf("-");
                int first, second, newnumb, index2;
                first = Convert.ToInt32(search.Substring(0, index1));
                second = Convert.ToInt32((search.Substring(index1 + 1)));
                for (int j = 0; j < Info_Box.Items.Count; j++)
                {
                    index1 = Info_Box.Items[j].ToString().IndexOf("количество страниц: ");
                    index1 += 20;
                    index2 = Info_Box.Items[j].ToString().IndexOf("[издатель:");
                    index2 -= 2;
                    newnumb = Convert.ToInt32(Info_Box.Items[j].ToString().Substring(index1, index2 - index1));
                    if (newnumb >= first && newnumb <= second)
                    {
                        search_result += Info_Box.Items[j].ToString();
                        search_result += "\n";
                    }
                }
                MessageBox.Show($"[ПО ИТОГАМ ПОИСКА]\n{search_result}");
            }
            for (int i = 0; i < Info_Box.Items.Count; i++)
            {
                if (Info_Box.Items[i].ToString().Contains(search))
                {
                    search_result += Info_Box.Items[i].ToString();
                    search_result += "\n";
                }
            }
            MessageBox.Show($"[ПО ИТОГАМ ПОИСКА]\n{search_result}");
        }

        private void toolStripDropDownButton1_Click(object sender, EventArgs e)
        {

        }

        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {

        }

        private void toolStripMenuItem2_Click(object sender, EventArgs e)
        {

        }

        private void bindingSource1_CurrentChanged(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton1.Checked)
            {
                Tool_bar.Visible = false;
            }
            if(radioButton2.Checked)
            {
                Tool_bar.Visible = true;
            }
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton1.Checked)
            {
                Tool_bar.Visible = true;
            }
            if(radioButton1.Checked)
            {
                Tool_bar.Visible= false;
            }
        }

        private void toolStripButton4_Click(object sender, EventArgs e)
        {
            Last_Move.Items.Clear();
            Last_Move.Items.Add("Была нажата кнопка [ОЧИСТИТЬ]");
            Info_Box.Items.Clear();
        }

        private void toolStripLabel1_Click(object sender, EventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            string vrem = DateTime.Now.ToShortTimeString();
            string date = DateTime.Now.ToLongDateString();
            richTextBox1.Text = vrem+" "+date;
        }

        private void toolStripButton5_Click(object sender, EventArgs e)
        {
            Last_Move.Items.Clear();
            Last_Move.Items.Add("Была нажата кнопка [ВПЕРЕД]");
            string line = "";
            StreamReader sr = new StreamReader("D://Документы БГТУ//1.ООП//3 Lab//2 Lab//2 Lab//info.txt");
            while (line != $"#{last_move}")
            {
                line = sr.ReadLine();
            }
            Info_Box.Items.Clear();
            while (line != "")
            {
                line = sr.ReadLine();
                if (line == "")
                {
                    break;
                }
                Info_Box.Items.Add(line);
            }
            sr.Close();
        }

        private void Nazad_Click(object sender, EventArgs e)
        {
            string line = "";
            StreamReader sr = new StreamReader("D://Документы БГТУ//1.ООП//3 Lab//2 Lab//2 Lab//info.txt");
            while (line != $"#{last_move - 1}")
            {
                line = sr.ReadLine();
            }
            Info_Box.Items.Clear();
            while(line != $"#{last_move + 1}" || line != "")
            {
                line = sr.ReadLine();
                if(line == "")
                {
                    break;
                }
                Info_Box.Items.Add(line);
            }
            sr.Close();
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }

}