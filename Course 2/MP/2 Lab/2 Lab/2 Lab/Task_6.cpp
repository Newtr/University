//#include "stdafx.h"
//#include "Auxil.h"
//#include <iostream>
//#include <iomanip> 
//#include <time.h>
//#include "Task_5.h"
//#define SPACE(n) std::setw(n)<<" "
//#define N 12
//int main()
//{
//    setlocale(LC_ALL, "rus");
//    int d[N * N + 1], r[N];
//    auxil::start();
//    for (int i = 0; i <= N * N; i++) d[i] = auxil::iget(10, 100);
//    std::cout << std::endl << "-- ������ ������������ -- ";
//    std::cout << std::endl << "-- ���������� ------ ����������������� -- ";
//    std::cout << std::endl << "      �������           ����������  ";
//    clock_t t1, t2;
//    for (int i = 6; i <= N; i++)
//    {
//        t1 = clock();
//        salesman(i, (int*)d, r);
//        t2 = clock();
//        std::cout << std::endl << SPACE(7) << std::setw(2) << i
//            << SPACE(15) << std::setw(5) << (t2 - t1);
//    }
//    std::cout << std::endl;
//    system("pause");
//    return 0;
//}
