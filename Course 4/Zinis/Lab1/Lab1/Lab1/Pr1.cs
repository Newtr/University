using System;

class Program
{
    static void Main(string[] args)
    {
        int m = 399;
        int n = 433;

        // Разложение на простые множители
        Console.WriteLine($"Разложение {m} на простые множители: {PrimeFactorization(m)}");
        Console.WriteLine($"Разложение {n} на простые множители: {PrimeFactorization(n)}");

        // Проверка, является ли конкатенация простым числом
        if (IsConcatenationPrime(m, n))
        {
            Console.WriteLine($"Число, полученное из конкатенации {m} и {n}, является простым.");
        }
        else
        {
            Console.WriteLine($"Число, полученное из конкатенации {m} и {n}, не является простым.");
        }

        while (true)
        {
            Console.WriteLine("Выберите действие:");
            Console.WriteLine("1. Найти простые числа в интервале [2,n] (n = 433)");
            Console.WriteLine("2. Найти простые числа в интервале [m,n] (m = 399, n = 433)");
            Console.WriteLine("3. Выполнить вычисления с двумя или тремя числами");
            Console.WriteLine("4. Найти простые числа на произвольном интервале");
            Console.WriteLine("5. Выйти");

            string choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                    FindPrimesInRange(2, 433);
                    break;
                case "2":
                    FindPrimesInRangeEratosfen(399, 433);
                    break;
                case "3":
                    PerformCalculations();
                    break;
                case "4":
                    FindPrimesInCustomRange();
                    break;
                case "5":
                    return;
                default:
                    Console.WriteLine("Неверный выбор, попробуйте снова.");
                    break;
            }
        }
    }

    static void FindPrimesInRange(int m, int n)
    {
        Console.WriteLine($"Поиск простых чисел в интервале [{m}, {n}]...");

        var primes = GetPrimes(m, n);
        Console.WriteLine($"Простые числа: {string.Join(", ", primes)}");

        int primeCount = primes.Count;
        int nln = n / (int)Math.Log(n);
        int gdc = GCD(primeCount, nln);
        Console.WriteLine($"Количество простых чисел: {primeCount}");
        Console.WriteLine($"{primeCount} > n/ln(n) = {nln}");
    }

    static void FindPrimesInRangeEratosfen(int m, int n)
    {
        Console.WriteLine($"Поиск простых чисел в интервале [{m}, {n}] с использованием решета Эратосфена...");

        // булев массив для обозначения простых чисел false default
        bool[] isPrime = new bool[n + 1];
        for (int i = 2; i <= n; i++)
            isPrime[i] = true;

        // Эратосфен
        for (int i = 2; i * i <= n; i++)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }

        // Список для хранения простых чисел в интервале [m, n]
        List<int> primes = new List<int>();
        for (int i = Math.Max(m, 2); i <= n; i++)
        {
            if (isPrime[i])
            {
                primes.Add(i);
            }
        }

        // Вывод найденных простых чисел
        Console.WriteLine($"Простые числа: {string.Join(", ", primes)}");

        // Сравнение с n/ln(n) и вычисление НОД
        int primeCount = primes.Count;
        int nln = n / (int)Math.Log(n);
        int gcd = GCD(primeCount, nln);

        Console.WriteLine($"Количество простых чисел: {primeCount}");
        Console.WriteLine($"n/ln(n): {nln}");
        Console.WriteLine($"НОД({primeCount}, n/ln(n) = {nln}): {gcd}");
    }

    static List<int> GetPrimes(int m, int n)
    {
        List<int> primes = new List<int>();

        for (int i = m; i <= n; i++)
        {
            if (IsPrime(i))
            {
                primes.Add(i);
            }
        }

        return primes;
    }

    static bool IsPrime(int number)
    {
        if (number < 2)
            return false;


        for (int i = 2; i <= Math.Sqrt(number); i++)
        {
            if (number % i == 0)
                return false;
        }

        return true;
    }

    static void PerformCalculations()
    {
        Console.WriteLine("Введите количество чисел для вычисления НОД (2 или 3):");
        int count = int.Parse(Console.ReadLine());

        if (count == 2)
        {
            Console.WriteLine("Введите два числа:");
            int num1 = int.Parse(Console.ReadLine());
            int num2 = int.Parse(Console.ReadLine());

            int gcd = GCD(num1, num2);
            Console.WriteLine($"НОД({num1}, {num2}) = {gcd}");
        }
        else if (count == 3)
        {
            Console.WriteLine("Введите три числа:");
            int num1 = int.Parse(Console.ReadLine());
            int num2 = int.Parse(Console.ReadLine());
            int num3 = int.Parse(Console.ReadLine());

            int gcd = GCD(GCD(num1, num2), num3); // Сначала находим НОД для первых двух чисел, третьего числа
            Console.WriteLine($"НОД({num1}, {num2}, {num3}) = {gcd}");
        }
        else
        {
            Console.WriteLine("Некорректное количество чисел.");
        }
    }

    // Функция для вычисления НОД двух чисел с использованием алгоритма Евклида
    static int GCD(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static void FindPrimesInCustomRange()
    {
        // Ввод интервала от пользователя
        Console.WriteLine("Введите начало интервала (m):");
        int m = int.Parse(Console.ReadLine());

        Console.WriteLine("Введите конец интервала (n):");
        int n = int.Parse(Console.ReadLine());

        if (m > n)
        {
            Console.WriteLine("Некорректный интервал. Начало интервала должно быть меньше или равно концу.");
            return;
        }

        // Поиск простых чисел в заданном интервале
        List<int> primes = GetPrimes(m, n);

        // Вывод результата
        if (primes.Count > 0)
        {
            Console.WriteLine($"Простые числа в интервале [{m}, {n}]: {string.Join(", ", primes)}");
        }
        else
        {
            Console.WriteLine($"Простых чисел в интервале [{m}, {n}] не найдено.");
        }
    }

    static string PrimeFactorization(int number)
    {
        List<int> factors = new List<int>();
        int divisor = 2;

        while (number > 1)
        {
            while (number % divisor == 0)
            {
                factors.Add(divisor);
                number /= divisor;
            }
            divisor++;
        }

        // Преобразуем список множителей в строку в канонической форме
        Dictionary<int, int> factorCounts = factors.GroupBy(x => x).ToDictionary(g => g.Key, g => g.Count());
        string canonicalForm = string.Join(" * ", factorCounts.Select(fc => fc.Value > 1 ? $"{fc.Key}^{fc.Value}" : fc.Key.ToString()));

        return canonicalForm;
    }

    static bool IsConcatenationPrime(int m, int n)
    {
        // Объединяем числа m и n в одно число
        string concatenatedString = m.ToString() + n.ToString();
        int concatenatedNumber = int.Parse(concatenatedString);

        // Проверяем, является ли это число простым
        return IsPrime(concatenatedNumber);
    }



}
