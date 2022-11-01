#include"binaryOperator.h"
#include<string>
using std::string;
using std::max;
string binaryOperator::binAdd(string numberOne, string numberTwo)
{
	string ans = "";
	if (numberOne.length() > numberTwo.length())
	{
		long long length = numberOne.length() - numberTwo.length();
		string temp(length, '0');
		numberTwo = temp + numberTwo;
	}
	else if(numberOne.length() < numberTwo.length())
	{
		long long length = numberTwo.length() - numberOne.length();
		string temp(length, '0');
		numberOne = temp + numberOne;
	}
	int flag = 0; 
	for (long long i = numberOne.length() - 1; i >= 0; i--)
	{
		int a = numberOne[i] - '0';
		int b = numberTwo[i] - '0';
		int answer = a ^ b ^ flag;
		if (a + b + flag > 1)flag = 1;
		else flag = 0;
		ans += (answer + '0');
	}
	if (flag == 1)ans += '1';
	reverse(ans.begin(), ans.end());
	return "0"+ans;
}
string binaryOperator::change(string number)
{
	for (int i = 0; i <= number.length() - 1; i++)
	{
		if (number[i] == '0')number[i] = '1';
		else if (number[i] == '1')number[i] = '0';
		else { exit(0); }
	}
	return binAdd(number, "1");
}
string binaryOperator::binSub(string numberOne, string numberTwo)//0表示
{
	if (numberOne.length() < numberTwo.length()
		|| numberOne.length() == numberTwo.length() 
		&& numberOne < numberTwo)
	{
		string _numberOne(numberOne, 1, numberOne.length());
		string _numberTwo(numberTwo, 1, numberTwo.length());
		return "1"+binAdd(_numberOne, change(_numberTwo));
	}//小减大，加补码
	else//大减小直接来
	{
		string ans;
		int flag = 0; int value = 0;
		int length = max(numberOne.length(), numberTwo.length());
		//补零
		string temp(length - numberOne.length(), '0');
		numberOne = temp + numberOne;
		string _temp(length - numberTwo.length(), '0');
		numberTwo = _temp + numberTwo;
		if (numberOne < numberTwo)return"-" + binSub(numberTwo, numberOne);
		for (int i = length - 1; i >= 0; i--)
		{
			int a = numberOne[i] - '0';
			int b = numberTwo[i] - '0';
			if (a < b)
			{
				ans += (2 + a - b) + '0';
				int temp = numberOne[i - 1] - '0';
				temp--;
				numberOne[i - 1] = temp + '0';
			}
			else
			{
				ans += ((a - b) + '0');
			}
		}
		reverse(ans.begin(), ans.end());
		int i = 0;
		for (; i <= ans.length() - 1;)//去除前导0
		{
			if (ans[i] == '0')i++;
			else break;
		}
		string _ans(ans, i, ans.length());
		if (_ans == "")_ans = "0";
		return "0"+_ans;
	}
}