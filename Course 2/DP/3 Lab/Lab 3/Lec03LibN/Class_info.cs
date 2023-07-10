namespace Lec03LibN
{
    public interface IBonus // вознаграждение
    {
        float cost1hour { get; set; }   // стоимость одного часа
        float calc(float number_hours);  // вычисление возраграждения - количество отработанных часов
    }

    public interface IFactory   // типы вознаграждения
    {
        IBonus getA(float cost1hour);   // тип вознаграждения А
        IBonus getB(float cost1hour, float x);  // тип вознаграждения B
        IBonus getC(float cost1hour, float x, float y); // тип вознаграждения С
    }

    static public partial class Lec03BLib
    {
        static public partial IFactory getL1();
        static public partial IFactory getL2(float a);
        static public partial IFactory getL3(float a, float b);
    }

    public class Employee
    {
        public IBonus bonus { get; private set; }
        public Employee(IBonus bonus)
        {
            this.bonus = bonus;
        }
        public float calcBonus(float number_hours) 
        {
            return bonus.calc(number_hours);
        }
    }
}