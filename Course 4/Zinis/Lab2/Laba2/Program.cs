using System;

class Program
{
    static void Main(string[] args)
    {
        while(true)
        {
            Console.WriteLine("Соотношения - 1\nТрисемус - 2\nВыход - 3");
            string? choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                    Program1.Run();
                    break;
                case "2":
                    Program2.Run();
                    break;
                case "3":
                    return;
                default:
                    Console.WriteLine("Неверный выбор, попробуйте снова.");
                    break;
            }
        }

    }
}
