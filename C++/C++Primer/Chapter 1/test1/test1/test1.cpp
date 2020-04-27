// test1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>




int main()
{
	//练习1.5 基本输入输出
	/*std::cout << " 请输入两个数：" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << v1 << " 和 " << v2 << " 之积为 "
		<< v1 * v2 << std::endl;*/

	//练习1.9 使用while循环计算50~100加和
	/*int sum = 0;
	int i = 50;
	while (i <= 100) {
		sum += i;
		i++;
	}
	std::cout << sum
		<< std::endl;*/

	//练习1.10 使用--运算符打印10到0
	/*int i = 10;
	while (i >= 0) {
		std::cout << i-- << std::endl;
	}

	int j = 10;
	while (j >= 0) {
		std::cout << j-- << " ";
	}*/

	// 练习1.11 根据用户输入打印范围
	/*int start = 0;
	int end = 0;
	std::cout << "Please input two numbers: " << std::endl;
	std::cin >> start >> end;
	if (start <= end) {
		for (int i = start; i <= end; i++) {
			std::cout << i << " ";
		}
	
	}
	else {
		for (int i = end; i <= start; i++) {
			std::cout << i << " ";
		}
	}*/

	//练习 1.16 从cin 读取一组数，输出其和

	return     0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

