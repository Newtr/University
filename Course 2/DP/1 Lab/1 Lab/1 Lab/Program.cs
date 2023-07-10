C1 A_Person = new();
C1 B_Person = new(100);
C1 C_Person = new(B_Person);
A_Person.Public_Say();
A_Person.public_prop = 500;
Console.WriteLine($"Поле = {A_Person.public_field}, Свойство = {A_Person.public_prop}");

Console.WriteLine("Класс С2");

C2 AA_Person = new();
C2 BB_Person = new(500);
C2 CC_Person = new(BB_Person);
AA_Person.Public_Say();
AA_Person.public_field = 123;
AA_Person.public_prop = 300;
Console.WriteLine($"Поле = {AA_Person.public_field}, Свойство = {AA_Person.public_prop}");

C4 C4Person = new();
string example = C4Person.Show_string;
Console.WriteLine($"Наследуем от C3 приватную строку, вот она = {example}");
C4Person.KnowSecret = true;
C4Person.I_Want_Secret();
C4Person.Hello();

C3 C3Person = new();

C4 APerson = new(C3Person);
C4 BPerson = new();

public class C1
{
    private const int private_const = 1;
    public const int public_const = 2;
    protected const int protected_const = 3;

    private int private_field = 11;
    public int public_field = 22;
    protected int protected_field = 33;

    private int private_prop { get; set; }
    public int public_prop { get; set; }
    protected int protected_prop { get; set; }

    public C1() { }
    public C1(C1 another)
    {
        another.public_field = public_field;
        another.public_prop = public_prop;
    }
    public C1(int some_value)
    {
        public_prop = some_value;
    }

    private void Private_Say()
    {
        Console.WriteLine("Приватный привет!");
    }
    public void Public_Say()
    {
        Console.WriteLine("Публичный привет!");
    }
    protected void Protected_Say()
    {
        Console.WriteLine("Защищенный привет!");
    }
}

public interface I1
{
    public int I1_prop { get; set; }
    public void I1_method();
    public event EventHandler I1_event;
    public int this[int index]
    {
        get; set;
    }

}

public class C2 : C1,I1
{
    int[] collection = new int[5];
    private int i1_prop;
    public int I1_prop
    {
        get { return i1_prop; }
        set { i1_prop = value; }
    }
    public void I1_method()
    {
        Console.WriteLine("Метод от I1");
    }
    public event EventHandler I1_event;
    public int this[int index]
    {
        get => collection[index];
        set => collection[index] = value;
    }

    public C2() { }

    public C2(C2 another)
    {
        another.public_field = public_field;
        another.public_prop = public_prop;
    }
    public C2(int some_value)
    {
        public_prop = some_value;
    }
}

public class C3
{
    public string public_string = "Публичная строка";
    protected string private_string = "Приватная строка";
    public string Show_string
    {
        get { return private_string; }
    }
    protected string secret = "Маленький секретик";
    public void Hello()
    {

    }
}


public interface I2
{
    public void Say_Meow();
}

public class C4 : C3,I2   // наследование
{
    public string C4_string = "Это моя строка, строка C4";
    public bool KnowSecret = false;

    public void I_Want_Secret()
    {
        if(KnowSecret == false)
        {
            return;
        }
        else
        {
            Console.WriteLine($"{secret}");
        }
    }

    public void Say_Meow()  //реализация
    {
        Console.WriteLine("Meow!");
    }

    public C3 C3 { get; set; } // Ассоциация

    C3 C3_example;
    /// <summary>
    /// конструктор для композиции
    /// </summary>
    public C4() //композиция
    {
        C3_example = new C3();
    }
    /// <summary>
    /// Конструктор для агрегации
    /// </summary>
    /// <param name="_c3_example"></param>
    public C4(C3 _c3_example)   //Агрегация
    {
        C3_example = _c3_example;
    }
}




