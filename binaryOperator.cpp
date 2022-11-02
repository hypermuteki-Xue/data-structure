#include"binaryOperator.h"
#include<string>
using std::string;
using std::max;
/*
* 
* 在进行运算时第一位为符号位
*/
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
	return ans;
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
string binaryOperator::binMul(string numberOne, string numberTwo)
{
	string ans = "";
	for (long long i = numberTwo.length() - 1,k=0; i >= 1; i--,k++)
	{
		if (numberTwo[i] == '1')
		{
			string s(k, '0');
			ans = binAdd(ans, numberOne + s);
		}
	}
	return ans;
}
string binaryOperator::binDiv(string NumberOne, string NumberTwo)
{
	string numberOne(NumberOne, 1, NumberOne.length());
	string numberTwo(NumberTwo, 1, NumberTwo.length());
	string ans = "";
	if (numberOne == "00")return "0";
	if (numberTwo == "00") {  exit(0); }
	if (numberOne == numberTwo)return "1";
	if (numberOne.length() < numberTwo.length()
		|| numberOne.length() == numberTwo.length()
		&& numberOne < numberTwo) return"0";
	else
	{
		int times = 0;
		while (numberTwo.length() < (numberOne.length() - 1)) { numberTwo='0'+numberTwo; times++; }
		for (int i = 0; i <= times; i++)
		{
			string _ans = "";
			string _numberTwo(numberTwo, i, numberTwo.length() );
			while ((numberOne.length() > numberTwo.length())
				|| (numberOne.length() == numberTwo.length()
				&& numberOne > numberTwo)||(numberOne==numberTwo))
			{
				_ans = binAdd(_ans, "1");
				numberOne = binSub(numberOne, _numberTwo);

			}
			if (_ans == "")ans += "0";
			ans = ans + _ans;
		}
		return "0"+ans;
	}

}
