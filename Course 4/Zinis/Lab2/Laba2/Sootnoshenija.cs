using System;
using System.Diagnostics;
using System.IO;
using System.Text;

public class Program1
{
    static readonly char[] GermanAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZÄÖÜß".ToCharArray();
    const int N = 30;  // Количество символов в алфавите
    const int K = 7;   // Значение ключа

    public static void Run()
    {
        // Чтение текста из файла
        string input = File.ReadAllText("Info.txt", Encoding.UTF8).ToUpper();
        string input2 = File.ReadAllText("Info1.txt", Encoding.UTF8).ToUpper();
        Console.WriteLine($"Original Text: {input}");

        string encryptedText = Encrypt(input, K);
        Console.WriteLine($"Encrypted: {encryptedText}");
        string decryptedText = Decrypt(encryptedText, K);
        Console.WriteLine($"Decrypted: {decryptedText}");


        // Способ 1 в файле 1тыс сообщ.  
        // Измерение времени для шифрования
        Stopwatch stopwatch = new Stopwatch();
        stopwatch.Start();
        string encryptedText1 = Encrypt(input2,K);
        stopwatch.Stop();
        long encryptionTime1 = stopwatch.ElapsedMilliseconds;

        // Измерение времени для дешифрования
        stopwatch.Restart();
        string decryptedText1 = Decrypt(encryptedText1,K);
        stopwatch.Stop();
        long decryptionTime1 = stopwatch.ElapsedMilliseconds;

        // Запись времени в файл TimeResult2_1.txt
        string timeResults = $"Average Encryption Time: {encryptionTime1} ms\nAverage Decryption Time: {decryptionTime1} ms";
        File.WriteAllText("TimeResult1_1.txt", timeResults);


        //Способ 2 1тыс раз шифруем и дешифруем
        // Измерение времени для шифрования (повторение 1000 раз для точности)
        Stopwatch stopwatch1 = new Stopwatch();
        stopwatch1.Start();
        for (int i = 0; i < 3000000; i++)
        {
            string _encryptedText = Encrypt(input,K);
        }
        stopwatch1.Stop();
        long encryptionTime = stopwatch1.ElapsedMilliseconds / 1000;  // Усреднение по 1000 повторений

        // Измерение времени для дешифрования (повторение 1000 раз для точности)
        string _encryptedTextSample = Encrypt(input,K);  // Шифруем один раз для примера
        stopwatch1.Restart();
        for (int i = 0; i < 3000000; i++)
        {
            string _decryptedText = Decrypt(_encryptedTextSample,K);
        }
        stopwatch1.Stop();
        long decryptionTime = stopwatch1.ElapsedMilliseconds / 1000;  // Усреднение по 1000 повторений

        // Запись времени в файл TimeResult2_2.txt
        string timeResults1 = $"Average Encryption Time: {encryptionTime} ms\nAverage Decryption Time: {decryptionTime} ms";
        File.WriteAllText("TimeResult1_2.txt", timeResults1);

    }

    static string Encrypt(string input, int key)
    {
        StringBuilder result = new StringBuilder();
        foreach (char c in input.ToUpper())
        {
            int index = Array.IndexOf(GermanAlphabet, c);
            if (index >= 0)
            {
                int newIndex = (index + key) % N;
                result.Append(GermanAlphabet[newIndex]);
            }
            else
            {
                result.Append(c);  // Оставляем символ без изменений, если он не в таблице (например, пробел)
            }
        }
        return result.ToString();
    }

    static string Decrypt(string input, int key)
    {
        StringBuilder result = new StringBuilder();
        foreach (char c in input.ToUpper())
        {
            int index = Array.IndexOf(GermanAlphabet, c);
            if (index >= 0)
            {
                int newIndex = (index - key + N) % N;
                result.Append(GermanAlphabet[newIndex]);
            }
            else
            {
                result.Append(c);  // Оставляем символ без изменений, если он не в таблице (например, пробел)
            }
        }
        return result.ToString();
    }
}
