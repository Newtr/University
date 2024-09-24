using System;
using System.Diagnostics;
using System.IO;
using System.Text;
using System.Linq;

public class Program2
{
    static readonly char[] GermanAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZÄÖÜß".ToCharArray();
    static char[,] TrisemusTable;

    public static void Run()
    {
        // Чтение текста из файла
        string input = File.ReadAllText("Info.txt", Encoding.UTF8).ToUpper();
        string input2 = File.ReadAllText("Info1.txt", Encoding.UTF8).ToUpper();
        Console.WriteLine($"Original Text: {input}");
        string keyword = "ENIGMA";

        // Создаем таблицу Трисемуса
        TrisemusTable = GenerateTrisemusTable(keyword);

        string encryptedText = Encrypt(input);
        Console.WriteLine($"Encrypted: {encryptedText}");
        string decryptedText = Decrypt(encryptedText);
        Console.WriteLine($"Decrypted: {decryptedText}");


        // Способ 1 в файле 1тыс сообщ.  
        // Измерение времени для шифрования
        Stopwatch stopwatch = new Stopwatch();
        stopwatch.Start();
        string encryptedText1 = Encrypt(input2);
        stopwatch.Stop();
        long encryptionTime1 = stopwatch.ElapsedMilliseconds;

        // Измерение времени для дешифрования
        stopwatch.Restart();
        string decryptedText1 = Decrypt(encryptedText1);
        stopwatch.Stop();
        long decryptionTime1 = stopwatch.ElapsedMilliseconds;

        // Запись времени в файл TimeResult2_1.txt
        string timeResults = $"Average Encryption Time: {encryptionTime1} ms\nAverage Decryption Time: {decryptionTime1} ms";
        File.WriteAllText("TimeResult2_1.txt", timeResults);


        //Способ 2 1тыс раз шифруем и дешифруем
        // Измерение времени для шифрования (повторение 1000 раз для точности)
        Stopwatch stopwatch1 = new Stopwatch();
        stopwatch1.Start();
        for (int i = 0; i < 1000000; i++)
        {
            string _encryptedText = Encrypt(input);
        }
        stopwatch1.Stop();
        long encryptionTime = stopwatch1.ElapsedMilliseconds / 1000;  // Усреднение по 1000 повторений

        // Измерение времени для дешифрования (повторение 1000 раз для точности)
        string _encryptedTextSample = Encrypt(input);  // Шифруем один раз для примера
        stopwatch1.Restart();
        for (int i = 0; i < 1000000; i++)
        {
            string _decryptedText = Decrypt(_encryptedTextSample);
        }
        stopwatch1.Stop();
        long decryptionTime = stopwatch1.ElapsedMilliseconds / 1000;  // Усреднение по 1000 повторений

        // Запись времени в файл TimeResult2_2.txt
        string timeResults1 = $"Average Encryption Time: {encryptionTime} ms\nAverage Decryption Time: {decryptionTime} ms";
        File.WriteAllText("TimeResult2_2.txt", timeResults1);
    }

    // Функция для генерации таблицы Трисемуса
    static char[,] GenerateTrisemusTable(string keyword)
    {
        // Убираем дублирующиеся символы из ключевого слова
        string distinctKey = new string(keyword.ToUpper().Distinct().ToArray());

        // Создаем список символов для заполнения таблицы
        string remainingAlphabet = new string(GermanAlphabet.Except(distinctKey).ToArray());

        string fullString = distinctKey + remainingAlphabet;

        char[,] table = new char[6, 5];  // Таблица 6x5 для алфавита

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                table[i, j] = fullString[i * 5 + j];
            }
        }

        return table;
    }

static string Encrypt(string input)
    {
        StringBuilder result = new StringBuilder();

        foreach (char c in input)
        {
            (int row, int col) = FindInTable(c);
            if (row != -1)
            {
                // Сдвигаем символ на одну позицию вниз в таблице
                int newRow = (row + 1) % 6;  // Если дошли до последней строки, переходим к первой
                result.Append(TrisemusTable[newRow, col]);
            }
            else
            {
                result.Append(c);  // Оставляем символ без изменений, если он не в таблице (например, пробел)
            }
        }

        return result.ToString();
    }

    // Дешифрование с использованием таблицы Трисемуса
    static string Decrypt(string input)
    {
        StringBuilder result = new StringBuilder();

        foreach (char c in input)
        {
            (int row, int col) = FindInTable(c);
            if (row != -1)
            {
                // Сдвигаем символ на одну позицию вверх в таблице
                int newRow = (row - 1 + 6) % 6;  // Если в первой строке, переходим к последней
                result.Append(TrisemusTable[newRow, col]);
            }
            else
            {
                result.Append(c);  // Оставляем символ без изменений, если он не в таблице (например, пробел)
            }
        }

        return result.ToString();
    }

    // Функция для поиска символа в таблице Трисемуса
    static (int row, int col) FindInTable(char c)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (TrisemusTable[i, j] == c)
                {
                    return (i, j);
                }
            }
        }
        return (-1, -1);  // Символ не найден
    }
}
