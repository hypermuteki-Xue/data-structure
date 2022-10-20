#include"numberOperator.h"
#include<string>
using std::string;
using std::reverse;
 string numberOperator::numberAdd(string numberOne, string numberTwo)
{ 
	 string ans;
	 if (numberOne.length() < numberTwo.length())
	 {
		 string temp(numberTwo.length() - numberOne.length(), '0');
		 numberOne = temp + numberOne;
	 }
	 else if (numberOne.length() > numberTwo.length())
	 {
		 string temp(numberOne.length() - numberTwo.length(), '0');
		 numberTwo = temp+ numberTwo;
	 }
	 int flag = 0; int value = 0;
	 for (long long i = numberOne.length()-1; i>=0;i--)
	 {
		 value = (numberOne[i] - '0') + (numberTwo[i] - '0') + flag;
		 flag = value / 10;
		 ans += (value % 10) + '0';
	 }
	 if(flag!=0)
	 ans += (flag+'0');
	 reverse(ans.begin(),ans.end());
	 return ans;
}
 string numberOperator::numberMul(string numberOne, string numberTwo)
 {
	 string ans;
	 int flag = 0; int value = 0;
	 int length = (numberOne.length() + numberTwo.length()) - 1;
	 //补零
	 string temp(length - numberOne.length(), '0');
	 numberOne = temp + numberOne;
	 string _temp(length - numberTwo.length(), '0');
	 numberTwo = _temp + numberTwo;
	 //竖式计算和字符串遍历顺序相反
	 reverse(numberOne.begin(),numberOne.end());
	 reverse(numberTwo.begin(),numberTwo.end());
	 //开始高精度乘法
	 for (int i = 0; i<=length-1; i++)
	 {
		 value = 0;
		 for (int j = 0; j <= i; j++)
		 {
			 value += (numberOne[j] - '0') * (numberTwo[i-j] - '0');
		 }
		 value = value + flag;
		 ans += ((value % 10)+'0');
		 flag = value / 10;

	 }
	 if (flag != 0)
	 ans += (flag + '0');
	 reverse(ans.begin(), ans.end());
	 return ans;
 }