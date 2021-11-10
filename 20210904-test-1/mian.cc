/*
 * mian.cc
 *
 *  Created on: 2 окт. 2021 г.
 *      Author: Никита
 */

#include <iostream>
#include <cstdint>
#include <cmath>
#include <iomanip>


int main()
{

//	std::cout << "Hello, World!" << std::endl;
//
//	std::cout << "char        :" << 8*sizeof(char)         << std::endl;
//	std::cout << "short       :" << 8*sizeof(short)        << std::endl;
//	std::cout << "int         :" << 8*sizeof(int)          << std::endl;
//	std::cout << "long        :" << 8*sizeof(long)         << std::endl;
//	std::cout << "long long   :" << 8*sizeof(long long)    << std::endl;

//	std::cout << "float       :" << 8*sizeof(float)       << std::endl;
//	std::cout << "double      :" << 8*sizeof(double)      << std::endl;
//	std::cout << "long double :" << 8*sizeof(long double) << std::endl;


	//С-строки, ASCIZ
	//       - очень простые, массив символов
	//       - определние длины строки - сложная операция
	//С++ - строки, класс std::string
	//       - составной тип данных, кроме строки хранит длину и др.
	//       - для ряда операций требуется конвертация в С-строку

	//Булевый тип bool - trure либо false
	//bool == int
	//false == 0
	//true == 1
	//любое значение, кроме 0 == true

//	std::cout << "Это очень \0 длинная строка" << std::endl;

	//const double pi = 3.1415;

	//std::cout << "Введите радиус окружности: ";
	//	double r;
	//std::cin >> r;

	//std::cout << "Длина окружности = " << 2 * pi * r << std::endl;
	//std::cout << "Площадь круга    = " << pi  * pow(r,2) <<std::endl;

	double x, y, a, b, s;

	std::cout << "Введите начало, конец и шаг промежутка" ;
	std::cin >> a >> b >> s;

	/*
	 *      x   |  sin(x)
	 * ---------+------------
	 *  -00.000 | -0.00000
	 *
	 *
	 */
	std::cout <<"    X     |  sin(x)  "<< std::endl <<"----------+----------"<<std::endl;

	std::cout << std::fixed;

	int w;
	for(x = a; x <= b; x += s){
		y = sin(x);
		w = int(2 + (y + 1) * 20);
		std::cout << std::setw(8) << std::setprecision(3) << x << " | "<< std::setw(7) << std::setprecision(3) << y << " | " << std::setw(w) << '*' <<  std::endl;
	}



	return 0;
}


