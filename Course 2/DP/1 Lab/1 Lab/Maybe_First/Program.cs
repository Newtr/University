Example my_first = new();
Console.WriteLine(my_first.pub_string);
my_first.Show_Strings();

Example2 my_second = new();
Console.WriteLine(my_second.pub_string);
Console.WriteLine(my_second.new_string);
Console.WriteLine();
my_second.Show_Strings();
my_second.Say_Meow();


public class Example
{
    public string pub_string = "I'm public string";
    private string priv_string = "I'm private string";
    public virtual void Show_Strings()
    {
        Console.WriteLine($"Here all my strings: {pub_string} AND {priv_string}");
    }
}

public interface IMyi
{
    public void Say_Meow();
}

public class Example2 : Example, IMyi
{
    public string new_string = "I'm new string";
    public override void Show_Strings()
    {
        Console.WriteLine(new_string);
        base.Show_Strings();
    }
    public void Say_Meow()
    {
        Console.WriteLine("Meow");
    }
}