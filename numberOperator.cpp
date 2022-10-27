#include"numberOperator.h"
#include<string>
#include<iostream>
using std::string;
using std::reverse;
using std::max;
using std::cout;
using std::endl;
bool operator >=(string a, string b)
{
	if (a.length() > b.length())return 1;
	else if (a[0] != ' -' && b[0] == '-')return 1;
	else if (a.length() == b.length() && a[0] > b[0])return 1;
	else if (a == b) return 1;
	else return 0;
}
bool operator >(string a, string b)
{
	if (a.length() > b.length())return 1;
	else if (a[0] != ' -' && b[0] == '-')return 1;
	else if (a.length() == b.length() && a[0] > b[0])return 1;
	else return 0;
}
 string numberOperator::numberAdd(string numberOne, string numberTwo)
{ 
	 string ans;
	 if (numberTwo[0] == '-'&&numberOne[0]=='-')//两个负数相加
	 {
		 string s(numberTwo, 1, numberTwo.length());
		 string s1(numberOne, 1, numberOne.length());
		 return "-" + numberAdd(s, s1);
	 }
	 else if (numberTwo[0] == '-')//一正一负相加
	 {
		 string s(numberTwo, 1, numberTwo.length());
		 return numberDiv(numberOne, s);
	 }
	 else if (numberOne[0] == '-')
	 {
		 string s1(numberOne, 1, numberOne.length());
		 return numberDiv(numberTwo,s1);
	 }
	 //前端补零来保持两项数字的长度相等
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
	 if (numberTwo[0] == '-' && numberOne[0] == '-')//两个负数相加
	 {
		 string right(numberTwo, 1, numberTwo.length());
		 string left(numberOne, 1, numberOne.length());
		 return  numberMul(right, left);
	 }
	 else if (numberTwo[0] == '-')//1-（-2）
	 {
		 string right(numberTwo, 1, numberTwo.length());
		 return"-"+ numberMul(numberOne, right);
	 }
	 else if (numberOne[0] == '-')//-1-2
	 {
		 string left(numberOne, 1, numberOne.length());
		 return "-" + numberMul(numberTwo, left);
	 }
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
 string numberOperator::numberSub(string numberOne, string numberTwo)
 {
	 if (numberOne == numberTwo)return "0";
	 if (numberTwo[0] == '-' && numberOne[0] == '-')//两个负数相加
	 {
		 string right(numberTwo, 1, numberTwo.length());
		 string left(numberOne, 1, numberOne.length());
		 return  numberSub(right, left);
	 }
	 else if (numberTwo[0] == '-')//1-（-2）
	 {
		 string right(numberTwo, 1, numberTwo.length());
		 return numberAdd(numberOne, right);
	 }
	 else if (numberOne[0] == '-')//-1-2
	 {
		 string left(numberOne, 1, numberOne.length());
		 return "-"+numberAdd(numberTwo, left);
	 }
	 string ans;
	 int flag = 0; int value = 0;
	 int length = max(numberOne.length(), numberTwo.length());
	 //补零
	 string temp(length - numberOne.length(), '0');
	 numberOne = temp + numberOne;
	 string _temp(length - numberTwo.length(), '0');
	 numberTwo = _temp + numberTwo;
	 if (numberOne < numberTwo)return"-" + numberSub(numberTwo, numberOne);
	 for (int i = length-1; i >=0; i--)
	 {
		 int a = numberOne[i] - '0';
		 int b = numberTwo[i] - '0';
		 if (a<b)
		 {
			 ans += (10 + a - b) + '0';
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
	 for (; i <= ans.length()-1;)//去除前导0
	 {
		 if (ans[i] == '0')i++;
		 else break;
	 }
	 string _ans(ans, i, ans.length());
	 return _ans;
 }
 string numberOperator::numberDiv(string numberOne, string numberTwo)//可以模拟竖式除法但是很复杂，一直减时间复杂度很高
 {
	 string ans="";
	 if (numberOne == "0")return "0";
	 if (numberTwo == "0") { std::cout << "error"; exit(0); }
	 if (numberOne == numberTwo)return "1";
	 if (numberOne.length() < numberTwo.length())
	 {
		 ans += "0.";
		 numberOne.append("0");
		 while (numberOne.length() < numberTwo.length()) { ans.append("0"); numberOne.append("0"); }
		 if (numberOne[0] < numberTwo[0])
		 {
			 ans.append("0");
			 numberOne.append("0");
		 }
		 return ans + numberDiv(numberOne, numberTwo);
	 }
	 else if (numberOne.length() == numberTwo.length() && numberOne[0] < numberTwo[0])
	 {
		 ans += "0.";
		 numberOne.append("0");
		 return ans + numberDiv(numberOne, numberTwo);
	 }
	 else
	 {
		 int times = 0; 
		 while (numberTwo.length() < (numberOne.length()-1)) { numberTwo.append("0"); times++; }
		 for (int i = 0; i <= times; i++)
		 {
			 string _ans="";
			 string _numberTwo(numberTwo, 0, numberTwo.length() - i);
			 while (numberOne >= _numberTwo)
			 {
				 _ans = numberAdd(_ans, "1");
				 numberOne = numberSub(numberOne, _numberTwo);

			 }
			 if (_ans == "")ans += "0";
			  ans =  ans+_ans;
		 }
		 return ans;
	 }

 }
 string numberOperator::numberPow(string numberOne, string numberTwo)
 {
	 string ans="1";
	 if (numberTwo[0] == '-')//指数为负
	 {
		 string temp(numberTwo, 1, numberTwo.length());
		 return numberDiv("1", numberPow(numberOne, temp));
	 }
	 else if(numberTwo == "0")return "1";//指数为0
	 else
	 {
		 while (numberTwo != "0")
		 {
			 ans = numberMul(ans, numberOne);
			 numberTwo = numberSub(numberTwo, "1");
		 }
	 }//指数为正
	 return ans;
 }
 string numberOperator::numberMod(string numberOne, string numberTwo)//可以直接调用函数但是时间复杂度太高
 {
	 if (numberOne == "0")return "0";
	 if (numberTwo == "0") { std::cout << "error"; exit(0); }
	 if (numberTwo > numberOne)return numberOne;
	 else if (numberTwo == numberOne)return "0";
	 else
	 {
		 int times = 0;
		 while (numberTwo.length() < (numberOne.length() - 1)) { numberTwo.append("0"); times++; }
		 for (int i = 0; i <= times; i++)
		 {
			 string _numberTwo(numberTwo, 0, numberTwo.length() - i);
			 while (numberOne >= _numberTwo)
			 {
				 numberOne = numberSub(numberOne, _numberTwo);
			 }
		 }
		 return numberOne;
	 }

 }