#include"binaryOperator.h"
#include<string>
using std::string;
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