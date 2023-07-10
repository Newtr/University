#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <memory.h>
#include <string>
#include "Levenshtein.h"
#include "MultiMatrix.h"
#include "LCS.h"
#define N 6

using namespace std;

int main()
{
	srand(time(NULL));

	string S1 = "";
	for (int i = 0; i < 10; i++)
	{
		S1 += ('a' + rand() % 26);
	}

	string S2 = "";
	for (int i = 0; i < 10; i++)
	{
		S2 += ('a' + rand() % 26);
	}

	cout << "S1: " << S1 << endl << endl;
	cout << "S2: " << S2 << endl;

	setlocale(LC_ALL, "rus");
	clock_t t1 = 0, t2 = 0, t3, t4;
	const int count = 11;
	double k[count] = { 1. / 10, 1. / 5, 1. / 4, 1. / 3, 4. / 10, 5. / 10, 6. / 10, 7. / 10, 8. / 10, 9. / 10, 1. };
	int  lx = S1.length(), ly = S2.length();
	cout << endl;
	//cout << endl << "Расстояние Левенштейна" << endl;
	string a = "ель", b = "дрель";

	cout << levenshtein(3, a, 5, b);
	//for (int i = 0; i < count; i++)
	//{
	//	//cout << endl << "Длина строк: " << (int)(lx * k[i]) << "/" << (int)(ly * k[i]);
	//	///*cout << "\tРасстояние по рекурсии: ";
	//	//cout << levenshtein_r(lx * k[i], S1, ly * k[i], S2);*/
	//	//cout << "\t Расстояние по дин.прог.: ";
	//	//cout << levenshtein(lx * k[i], S1, ly * k[i], S2);
	//	cout << endl << "Длина строк: " << (int)(lx * k[i]) << "/" << (int)(ly * k[i]);
	//	t1 = clock();
	//	levenshtein_r(lx * k[i], S1, ly * k[i], S2);
	//	t2 = clock();

	//	cout << "\tВремя по рекурсии: " << (t2 - t1) << " ms";

	//	/*t3 = clock();
	//	levenshtein(lx * k[i], S1, ly * k[i], S2);
	//	t4 = clock();
	//	cout << "\t Время по дин.прог.: " << (t4 - t3) << " ms";*/

	//}

	cout << endl;
	system("pause");
	return 0;
}

//int main()
//{
//	setlocale(LC_ALL, "rus");
//
//	int Mc[N + 1] = { 9,12,20,23,30,40,51 }, Ms[N][N], r = 0, rd = 0;
//
//	memset(Ms, 0, sizeof(int) * N * N);
//	clock_t t1, t2;
//	t1 = clock();
//	r = OptimalM(1, N, N, Mc, OPTIMALM_PARM(Ms));
//	t2 = clock();
//	cout << endl;
//	cout << endl << "-- расстановка скобок (рекурсивное решение) " << endl;
//	cout << endl << "размерности матриц: ";
//	for (int i = 1; i <= N; i++) cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
//	cout << endl << "минимальное количество операций умножения: " << r;
//	cout << endl << endl << "матрица S" << endl;
//	for (int i = 0; i < N; i++)
//	{
//		cout << endl;
//		for (int j = 0; j < N; j++)  cout << Ms[i][j] << "  ";
//	}
//	cout << endl;
//	cout << "Затраченное время: " << (t2 - t1) << " ms" << endl;
//
//	memset(Ms, 0, sizeof(int) * N * N);
//	clock_t t3, t4;
//	t3 = clock();
//	rd = OptimalMD(N, Mc, OPTIMALM_PARM(Ms));
//	t4 = clock();
//	cout << endl
//		<< "-- расстановка скобок (динамичеое программирование) " << endl;
//	cout << endl << "размерности матриц: ";
//	for (int i = 1; i <= N; i++)
//		cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
//	cout << endl << "минимальное количество операций умножения: "
//		<< rd;
//	cout << endl << endl << "матрица S" << endl;
//	for (int i = 0; i < N; i++)
//	{
//		cout << endl;
//		for (int j = 0; j < N; j++)  cout << Ms[i][j] << "  ";
//	}
//	cout << endl;
//	cout << "Затраченное время: " << (t4 - t3) << " ms" << endl;
//	system("pause");
//
//	return 0;
//}



//int main()
//{
//    setlocale(LC_ALL, "rus");
//    char X[] = "ALBDACD", Y[] = "CDLDCA";
//    std::cout << std::endl << "-- вычисление длины LCS для X и Y(рекурсия)";
//    std::cout << std::endl << "-- последовательность X: " << X;
//    std::cout << std::endl << "-- последовательность Y: " << Y;
//    int s = lcs(
//        sizeof(X) - 1,  // длина   последовательности  X   
//        "ALBDACD",       // последовательность X
//        sizeof(Y) - 1,  // длина   последовательности  Y
//        "CDLDCA"       // последовательность Y
//    );
//    std::cout << std::endl << "-- длина LCS: " << s << std::endl;
//
//    char z[100] = "";
//    char x[] = "ALBDACD",
//        y[] = "CDLDCA";
//
//    int l = lcsd(x, y, z);
//    std::cout << std::endl
//        << "-- наибольшая общая подпоследовательость - LCS(динамическое "
//        << "программирование)" << std::endl;
//    std::cout << std::endl << "последовательость X: " << x;
//    std::cout << std::endl << "последовательость Y: " << y;
//    std::cout << std::endl << "                LCS: " << z;
//   std::cout << std::endl << "          длина LCS: " << l;
//   std::cout << std::endl;
//
//
//    system("pause");
//    return 0;
//}
