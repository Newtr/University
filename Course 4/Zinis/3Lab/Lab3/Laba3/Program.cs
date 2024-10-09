using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Diagnostics;

namespace EncryptionApp
{
    class Program
    {
        static void Main(string[] args)
        {
            string inputFilePath = @"D:\Work\University\Zinis\Lab3\Laba3\Info.txt";
            string encryptedFilePath = @"D:\Work\University\Zinis\Lab3\Laba3\Info_encrypted.txt";
            string decryptedFilePath = @"D:\Work\University\Zinis\Lab3\Laba3\Info_decrypted.txt";
            string timeResultFilePath = @"D:\Work\University\Zinis\Lab3\Laba3\TimeResult.txt"; // Путь к TimeResult.txt

            Console.WriteLine("Выберите операцию:");
            Console.WriteLine("1. Зашифровать");
            Console.WriteLine("2. Расшифровать");
            Console.Write("Введите номер операции: ");
            string choice = Console.ReadLine();

            if (choice == "1")
            {
                Console.WriteLine("Выберите метод шифрования:");
                Console.WriteLine("1. Маршрутная перестановка (змейкой)");
                Console.WriteLine("2. Множественная перестановка");
                Console.Write("Введите номер метода: ");
                string method = Console.ReadLine();

                string text = ReadTextFromFile(inputFilePath);
                string keyword = "Roman Tyshkevich";

                string encryptedText = "";

                if (method == "1")
                {
                    // Инициализируем Stopwatch
                    Stopwatch stopwatch = new Stopwatch();
                    stopwatch.Start();

                    encryptedText = RailFenceEncrypt(text, 3); // Например, 3 ряда

                    stopwatch.Stop();
                    double elapsedMilliseconds = stopwatch.Elapsed.TotalMilliseconds;

                    // Сохраняем время выполнения в TimeResult.txt
                    string timeResult = $"Маршрутная перестановка (змейкой) время шифрования: {elapsedMilliseconds} мс";
                    File.AppendAllText(timeResultFilePath, timeResult + Environment.NewLine);
                }
                else if (method == "2")
                {
                    // Инициализируем Stopwatch
                    Stopwatch stopwatch = new Stopwatch();
                    stopwatch.Start();

                    encryptedText = ColumnarTranspositionEncrypt(text, keyword);

                    stopwatch.Stop();
                    double elapsedMilliseconds = stopwatch.Elapsed.TotalMilliseconds;

                    // Сохраняем время выполнения в TimeResult.txt
                    string timeResult = $"Множественная перестановка время шифрования: {elapsedMilliseconds} мс";
                    File.AppendAllText(timeResultFilePath, timeResult + Environment.NewLine);
                }
                else
                {
                    Console.WriteLine("Неверный выбор метода.");
                    return;
                }

                WriteTextToFile(encryptedFilePath, encryptedText);
                Console.WriteLine($"Текст зашифрован и сохранен в {encryptedFilePath}");
            }
            else if (choice == "2")
            {
                Console.WriteLine("Выберите метод дешифрования:");
                Console.WriteLine("1. Маршрутная перестановка (змейкой)");
                Console.WriteLine("2. Множественная перестановка");
                Console.Write("Введите номер метода: ");
                string method = Console.ReadLine();

                string text = ReadTextFromFile(encryptedFilePath);
                string keyword = "Roman Tyshkevich";

                string decryptedText = "";

                if (method == "1")
                {
                    // Инициализируем Stopwatch
                    Stopwatch stopwatch = new Stopwatch();
                    stopwatch.Start();

                    decryptedText = RailFenceDecrypt(text, 3); // Тот же параметр, что и при шифровании

                    stopwatch.Stop();
                    double elapsedMilliseconds = stopwatch.Elapsed.TotalMilliseconds;

                    // Сохраняем время выполнения в TimeResult.txt
                    string timeResult = $"Маршрутная перестановка (змейкой) время дешифрования: {elapsedMilliseconds} мс";
                    File.AppendAllText(timeResultFilePath, timeResult + Environment.NewLine);
                }
                else if (method == "2")
                {
                    // Инициализируем Stopwatch
                    Stopwatch stopwatch = new Stopwatch();
                    stopwatch.Start();

                    decryptedText = ColumnarTranspositionDecrypt(text, keyword);

                    stopwatch.Stop();
                    double elapsedMilliseconds = stopwatch.Elapsed.TotalMilliseconds;

                    // Сохраняем время выполнения в TimeResult.txt
                    string timeResult = $"Множественная перестановка время дешифрования: {elapsedMilliseconds} мс";
                    File.AppendAllText(timeResultFilePath, timeResult + Environment.NewLine);
                }
                else
                {
                    Console.WriteLine("Неверный выбор метода.");
                    return;
                }

                WriteTextToFile(decryptedFilePath, decryptedText);
                Console.WriteLine($"Текст расшифрован и сохранен в {decryptedFilePath}");
            }
            else
            {
                Console.WriteLine("Неверный выбор операции.");
            }
        }

        // Чтение текста из файла
        static string ReadTextFromFile(string path)
        {
            try
            {
                return File.ReadAllText(path, Encoding.UTF8);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка чтения файла: {ex.Message}");
                return "";
            }
        }

        // Запись текста в файл
        static void WriteTextToFile(string path, string text)
        {
            try
            {
                File.WriteAllText(path, text, Encoding.UTF8);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка записи файла: {ex.Message}");
            }
        }

        // Маршрутная перестановка (змейкой) - Шифрование
        static string RailFenceEncrypt(string text, int rails)
        {
            if (rails <= 1)
                return text;

            List<StringBuilder> railList = new List<StringBuilder>();
            for (int i = 0; i < rails; i++)
                railList.Add(new StringBuilder());

            int currentRail = 0;
            bool directionDown = true;

            foreach (char c in text)
            {
                railList[currentRail].Append(c);

                if (directionDown)
                {
                    if (currentRail < rails - 1)
                        currentRail++;
                    else
                    {
                        directionDown = false;
                        currentRail--;
                    }
                }
                else
                {
                    if (currentRail > 0)
                        currentRail--;
                    else
                    {
                        directionDown = true;
                        currentRail++;
                    }
                }
            }

            StringBuilder encrypted = new StringBuilder();
            foreach (var rail in railList)
                encrypted.Append(rail.ToString());

            return encrypted.ToString();
        }

        // Маршрутная перестановка (змейкой) - Дешифрование
        static string RailFenceDecrypt(string text, int rails)
        {
            if (rails <= 1)
                return text;

            // Создаем матрицу для маршрутов
            char[,] matrix = new char[rails, text.Length];
            for (int i = 0; i < rails; i++)
                for (int j = 0; j < text.Length; j++)
                    matrix[i, j] = '\n';

            // Помечаем позиции символов
            int currentRail = 0;
            bool directionDown = true;
            for (int j = 0; j < text.Length; j++)
            {
                matrix[currentRail, j] = '*';

                if (directionDown)
                {
                    if (currentRail < rails - 1)
                        currentRail++;
                    else
                    {
                        directionDown = false;
                        currentRail--;
                    }
                }
                else
                {
                    if (currentRail > 0)
                        currentRail--;
                    else
                    {
                        directionDown = true;
                        currentRail++;
                    }
                }
            }

            // Заполняем матрицу символами из зашифрованного текста
            int index = 0;
            for (int i = 0; i < rails; i++)
            {
                for (int j = 0; j < text.Length; j++)
                {
                    if (matrix[i, j] == '*' && index < text.Length)
                    {
                        matrix[i, j] = text[index++];
                    }
                }
            }

            // Читаем символы в порядке маршрута
            StringBuilder decrypted = new StringBuilder();
            currentRail = 0;
            directionDown = true;
            for (int j = 0; j < text.Length; j++)
            {
                decrypted.Append(matrix[currentRail, j]);

                if (directionDown)
                {
                    if (currentRail < rails - 1)
                        currentRail++;
                    else
                    {
                        directionDown = false;
                        currentRail--;
                    }
                }
                else
                {
                    if (currentRail > 0)
                        currentRail--;
                    else
                    {
                        directionDown = true;
                        currentRail++;
                    }
                }
            }

            return decrypted.ToString();
        }

        // Множественная перестановка - Шифрование (с сохранением пробелов и переносов строк)
static string ColumnarTranspositionEncrypt(string text, string keyword)
{
    // Сохраняем пробелы и переносы строк, не приводим к верхнему регистру
    string cleanText = text; // Удалили фильтрацию пробелов

    // Определяем порядок колонок
    string key = new string(keyword.ToUpper().Where(c => char.IsLetter(c)).ToArray());
    int[] order = GetColumnOrder(key);

    // Определяем количество строк
    int numCols = key.Length;
    int numRows = (int)Math.Ceiling((double)cleanText.Length / numCols);

    // Заполняем матрицу
    char[,] matrix = new char[numRows, numCols];
    int index = 0;
    for (int r = 0; r < numRows; r++)
    {
        for (int c = 0; c < numCols; c++)
        {
            if (index < cleanText.Length)
                matrix[r, c] = cleanText[index++];
            else
                matrix[r, c] = 'X'; // Заполнение пустых мест
        }
    }

    // Читаем колонки в порядке ключа
    StringBuilder encrypted = new StringBuilder();
    for (int i = 0; i < order.Length; i++)
    {
        int col = Array.IndexOf(order, i + 1);
        for (int r = 0; r < numRows; r++)
        {
            encrypted.Append(matrix[r, col]);
        }
    }

    return encrypted.ToString();
}

// Множественная перестановка - Дешифрование (с сохранением пробелов и переносов строк)
static string ColumnarTranspositionDecrypt(string text, string keyword)
{
    string key = new string(keyword.ToUpper().Where(c => char.IsLetter(c)).ToArray());
    int[] order = GetColumnOrder(key);
    int numCols = key.Length;
    int numRows = (int)Math.Ceiling((double)text.Length / numCols);

    char[,] matrix = new char[numRows, numCols];
    int index = 0;

    // Заполняем колонки по порядку ключа
    for (int i = 0; i < order.Length; i++)
    {
        int col = Array.IndexOf(order, i + 1);
        for (int r = 0; r < numRows; r++)
        {
            if (index < text.Length)
                matrix[r, col] = text[index++];
            else
                matrix[r, col] = 'X'; // Заполнение пустых мест
        }
    }

    // Читаем строками
    StringBuilder decrypted = new StringBuilder();
    for (int r = 0; r < numRows; r++)
    {
        for (int c = 0; c < numCols; c++)
        {
            decrypted.Append(matrix[r, c]);
        }
    }

    // Удаляем только конечные 'X', оставляя пробелы и переносы строк
    return RemoveTrailingX(decrypted.ToString());
}

// Вспомогательная функция для удаления только конечных 'X'
static string RemoveTrailingX(string text)
{
    int lastIndex = text.Length;
    while (lastIndex > 0 && text[lastIndex - 1] == 'X')
    {
        lastIndex--;
    }
    return text.Substring(0, lastIndex);
}

        // Получение порядка колонок на основе ключа
        static int[] GetColumnOrder(string key)
        {
            var ordered = key.Select((c, i) => new { Character = c, Index = i })
                             .OrderBy(x => x.Character)
                             .ThenBy(x => x.Index)
                             .ToList();

            int[] order = new int[key.Length];
            for (int i = 0; i < ordered.Count; i++)
            {
                order[ordered[i].Index] = i + 1;
            }

            return order;
        }
    }
}
