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
		numberTwo = temp + numberOne;
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
string binaryOperator::binSub(string numberOne, string numberTwo)
{
	string ans;
	int flag = 0; int value = 0;
	int length = max(numberOne.length(), numberTwo.length());
	//≤π¡„
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
			ans += (2+ a - b) + '0';
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
	for (; i <= ans.length() - 1;)//»•≥˝«∞µº0
	{
		if (ans[i] == '0')i++;
		else break;
	}
	string _ans(ans, i, ans.length());
	if (_ans == "")_ans = "0";
	return _ans;
}