#pragma once
#include<string>
#include <iostream>

bool IsKPeriodic(int k, const std::string& str)
{
	int strSize = str.length();
	std::string strPeriod;
	int count = 0;
	//	//обработка некорректной строки

	// строка длиной менее 1 символа:
	if (strSize <= 1 || k > strSize / 2 || k == strSize)
	{
		std::cout << "bad string " << std::endl;
		return false;
	}

	for (int i = 0; i < k; ++i)
	{
		strPeriod.push_back(str[i]);
	}

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
{
	std::string string;


	int k = 3;
	string = "abcabcabc";
	print(k, string);

	 k = 4;
	print(k, string);



	//string = "aabaabaab";


	return 0;
}