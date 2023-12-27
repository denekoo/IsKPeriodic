#pragma once
#include<string>
#include <iostream>

bool IsKPeriodic(int k, const std::string& str)
{
	int strSize = str.length();
	
	//	//обработка некорректной строки
	if (strSize <= 1 || k > strSize / 2 || k == strSize)
	{
		std::cout << "bad string " << std::endl;
		return false;
	}

	//	заполнение подстроки
	std::string strPeriod;
	for (int i = 0; i < k; ++i)
	{
		strPeriod.push_back(str[i]);
	}

	int count = 0;  // счетчик совпадающих символов
	int j = 0;		
	for (int i = k; i < strSize; ++i)
	{
		if (j >= k)
		{
			j = 0;
		}

		if (strPeriod[j] == str[i])
		{
			++count;
		}
		else
			break;
		++j;
	}
	// вывод результата работы функции 
	 
	if ((count + k) / k == k)
		return true;
	else
		return false;
}


void print(int k, std::string str)
{
	bool per = IsKPeriodic(k, str);
	std::string answer;
	if (per == true)
		answer = " string is divisible";
	else
		answer = " string is not divisible";

	std::cout << "For string= " << str << " and k = " << k << answer << std::endl;

}


int main()
{	//	//	 проверка работоспособности функции	//	//
	
	std::string string;

	// "нормальная" строка и интервал:
	int k = 3;
	string = "abcabcabc";
	print(k, string);

	// интервал k больше периода
	 k = 4;
	print(k, string);


	// строка без периода
	k = 3;
	string = "aabaajaab";
	print(k, string);
	
	// строка из одного символа
	k = 3;
	string = "a";
	print(k, string);

	//период больше половины длины строки
	k = 5;
	string = "aabaabaab";
	print(k, string);



	return 0;
}