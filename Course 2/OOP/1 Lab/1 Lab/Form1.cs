using System.Drawing.Text;

namespace _1_Lab
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Get_Ruslt(comboBox1, textBox2, textBox3, textBox4, comboBox2,textBox1);
        }

        private void Get_Ruslt(ComboBox sex, TextBox weight, TextBox height, TextBox age, ComboBox goal, TextBox pref_weight)
        {
            string selectedGoal = goal.SelectedItem.ToString();
            string selectedSex = sex.SelectedItem.ToString();
            int _weight = 0, _height = 0, _age = 0;
            double prefer_weight = 0;
            try
            {
                _weight = int.Parse(weight.Text);
                _height = int.Parse(height.Text);
                _age = int.Parse(age.Text);
                prefer_weight = double.Parse(pref_weight.Text);
                if(_weight <= 0 || _height <= 0 || _age<= 0 || prefer_weight <=0) 
                {
                    throw new Exception();
                }
            }
            catch (Exception ex) 
            {
                MessageBox.Show("Значения полей введено некорректно!");
                return;
            }
            int ideal_weight_male = _height - 100;
            int ideal_weight_female = _height - 110;
            double _weight2 = prefer_weight - _weight;
            double male_call_per_day1 = 66.4730 + (13.7516 * _weight2) + (5.0033 * _height) - (6.7550 * _age);
            double female_call_per_day1 = 5.0955 + (9.5634 * _weight2) + (1.8496 * _height) - (4.6756 * _age);
            double male_call_per_day = male_call_per_day1 - prefer_weight;
            double female_call_per_day = female_call_per_day1 - prefer_weight;
            string final_text ="";
            if (selectedGoal == "Поддержание")
            {
                if(selectedSex == "Мужской")
                {
                    if(_weight > ideal_weight_male) 
                    {
                        final_text =  $"У вас ожирение. Для поддержания такого же веса, вам в день требуется {male_call_per_day} ккал.";
                        
                    }
                    if(_weight < ideal_weight_male) 
                    { 
                        final_text = $"У вас недостаток веса.Для поддержания такого же веса, вам в день требуется {male_call_per_day} ккал."; 
                    }
                    if(_weight == ideal_weight_male) 
                    {
                        final_text = $"У вас идеальный вес. Продолжайте делать все как делали. Для этого в сутки потребляйте {male_call_per_day}";
                    }


                }
                if(selectedSex == "Женский")
                {
                    if (_weight > ideal_weight_male)
                    {
                        final_text = $"У вас ожирение. Для поддержания такого же веса, вам в день требуется {female_call_per_day} ккал.";

                    }
                    if (_weight < ideal_weight_male)
                    {
                        final_text = $"У вас недостаток веса.Для поддержания такого же веса, вам в день требуется {female_call_per_day} ккал.";
                    }
                    if (_weight == ideal_weight_male)
                    {
                        final_text = $"У вас идеальный вес. Продолжайте делать все как делали. Для этого в сутки потребляйте {female_call_per_day}";
                    }
                }
            }
            if (selectedGoal == "Снижение")
            {
                if(selectedSex == "Мужской")
                {
                    if (_weight > ideal_weight_male)
                    {
                        final_text = $"У вас ожирение. Для снижения веса, вам в день требуется {male_call_per_day - 1.375} ккал.";

                    }
                    if (_weight < ideal_weight_male)
                    {
                        final_text = $"У вас недостаток веса. Для снижения веса, вам в день требуется {male_call_per_day} ккал.";
                    }
                    if (_weight == ideal_weight_male)
                    {
                        final_text =  $"У вас идеальный вес. Для снижения веса, вам в день требуется {male_call_per_day} ккал.";
                    }
                }
                if(selectedSex == "Женский")
                {
                    if (_weight > ideal_weight_male)
                    {
                        final_text = $"У вас ожирение. Для поддержания такого же веса, вам в день требуется {female_call_per_day} ккал.";

                    }
                    if (_weight < ideal_weight_male)
                    {
                        final_text = $"У вас недостаток веса.Для поддержания такого же веса, вам в день требуется {female_call_per_day} ккал.";
                    }
                    if (_weight == ideal_weight_male)
                    {
                        final_text = $"У вас идеальный вес. Продолжайте делать все как делали. Для этого в сутки потребляйте {female_call_per_day}";
                    }
                }
            }
            if (selectedGoal == "Увеличение")
            {
                if(selectedSex == "Мужской")
                {
                    if (_weight > ideal_weight_male)
                    {
                        final_text = $"У вас ожирение. Вам крайне не рекомендуется более повышать свой вес!";

                    }
                    if (_weight < ideal_weight_male)
                    {
                        final_text = $"У вас недостаток веса.Для увеличения веса, вам в день требуется {male_call_per_day+5} ккал.";
                    }
                    if (_weight == ideal_weight_male)
                    {
                        final_text = $"У вас идеальный вес. Для увеличения веса, вам в день требуется {male_call_per_day} ккал.";
                    }
                }
                if(selectedSex == "Женский")
                {
                    if (_weight > ideal_weight_male)
                    {
                        final_text = $"У вас ожирение. Для поддержания такого же веса, вам в день требуется {female_call_per_day} ккал.";

                    }
                    if (_weight < ideal_weight_male)
                    {
                        final_text = $"У вас недостаток веса.Для поддержания такого же веса, вам в день требуется {female_call_per_day} ккал.";
                    }
                    if (_weight == ideal_weight_male)
                    {
                        final_text = $"У вас идеальный вес. Продолжайте делать все как делали. Для этого в сутки потребляйте {female_call_per_day}";
                    }
                }
            }
            MessageBox.Show(final_text);
        }
    }
}