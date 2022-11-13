#include"binaryOperator.h"
#include"numberOperator.h"
#include<string>
#include<iostream>
using std::string;
using std::max;
/*
* 
* 在进行运算时第一位为符号位
*/
string binaryOperator::binAdd(string _numberOne, string _numberTwo)
{
	string ans = "";
	string numberOne(_numberOne, 1, _numberOne.length());
	string numberTwo(_numberTwo, 1, _numberTwo.length());
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
	return binAdd("0"+number, "01");
}
string binaryOperator::binSub(string numberOne, string numberTwo)//0表示
{
	if (numberOne.length() < numberTwo.length()
		|| numberOne.length() == numberTwo.length() 
		&& numberOne < numberTwo)
	{
		string _numberTwo(numberTwo, 1, numberTwo.length());
		numberOne= binAdd(numberOne, change(_numberTwo));
		string number(numberOne, 1, numberOne.length());
		return "1" + number;
		
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
string binaryOperator::binMul(string numberOne, string numberTwo)
{
	string ans = "00";
	std::cout << 1 << std::endl;
	for (long long i = numberTwo.length() - 1,k=0; i >= 1; i--,k++)
	{
		std::cout << 2 << std::endl;
		if (numberTwo[i] == '1')
		{
			string s(k, '0');
			ans = binAdd(ans, numberOne + s);
		}
	}
	return ans;
}
string binaryOperator::binDiv(string numberOne, string numberTwo)
{
	string ans = "";
	if (numberOne == "00")return "00";
	if (numberTwo == "00") {  exit(0); }
	if (numberOne == numberTwo)return "01";
	if (numberOne.length() < numberTwo.length()
		|| numberOne.length() == numberTwo.length()
		&& numberOne < numberTwo) return"00";
	else
	{
		std::cout << numberOne << std::endl;
		std::cout << numberTwo << std::endl;
		int times = 0;
		while (numberTwo.length() < (numberOne.length() - 1)) { numberTwo.append("0"); times++; }
		for (int i = 0; i <= times; i++)
		{
			numberOperator n;
			string _ans = "00";
			string _numberTwo(numberTwo, 0, numberTwo.length()-i );
			while ((numberOne.length() > _numberTwo.length())|| (numberOne.length() == _numberTwo.length() && numberOne> _numberTwo)|| (numberOne == _numberTwo))
			{
				_ans = binAdd(_ans, "01");
                numberOne = binSub(numberOne, _numberTwo);
			}
			string __ans(_ans, 1, _ans.length());
			ans = ans + __ans;
		}
		return "0"+ans;
	}

}
string binaryOperator::binMod(string numberOne, string numberTwo)//2^256取余等于直接取最后256
{
	reverse(numberOne.begin(), numberOne.end());
	string s(numberOne, 0, stoi(numberTwo));
	reverse(s.begin(), s.end());
	return s ;
}
