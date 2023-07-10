#include "Auxil.h" 
#include <ctime>    
namespace auxil
{
	void start()                          // старт  генератора сл. чисел
	{
		srand((unsigned)time(NULL));
	};
	double dget(double rmin, double rmax) // получить случайное число
	{
		return ((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin;
	};
	int iget(int rmin, int rmax)         // получить случайное число
	{
		return (int)dget((double)rmin, (double)rmax);
	}
	int fibonachi(int number)
	{
		int i = 2, fibon = 1, first = 0, second = 1;

		if (number <= 3)
		{
			if (number == 1)
				fibon = 0;
			if (number == 2 or fibon == 3)
				fibon = 1;
		}
		else
		{
			while (i < number)
			{
				fibon = first + second;
				first = second;
				second = fibon;
				i++;
			}
		}

		return fibon;
	}

	int fuctorial(int number)
	{
		int start = 1;

		for (size_t i = 2; i <= number; i++)
		{
			start *= i;
		}

		return start;
	}

	int recursion_fibonachi(int number)
	{
		if (number == 1)
			return 0;
		if (number == 2 or number == 3)
			return 1;
		return recursion_fibonachi(number - 1) + recursion_fibonachi(number - 2);
	}

}