#include<iostream>
#include"numberOperator.h"
#include"numberList.h"
#include"numberNode.h"
#include"binaryOperator.h"
#include"decFile.h"
#include"binFile.h"
#include<time.h>
int numberNode::code = 0;
using namespace std;
int main()
{
	binaryOperator b;
	numberOperator n;
	decFile decfile;
	binFile binfile;
	double start, end, cost;
	cout << "请输入你的进制 1十进制 2二进制" << endl;
	string a;
	cin >> a;
	if (a == "1")
	{
		cout << "请输入想做的操作：1+，2-，3*，4/，5mod" << endl;
		string number;
		cin >> number;
		if (number == "1")
		{
			string numberOne;
			string numberTwo;
			cout << "请输入你想操作的数字" << endl;
			cin >> numberOne >> numberTwo;
			start = clock();
			cout << n.numberAdd(numberOne, numberTwo) << endl;
			end = clock();
			cost = end - start;
			cout << "花费：" << cost << "毫秒" << endl;
		}
		else if (number == "2")
		{
			string numberOne;
			string numberTwo;
			cout << "请输入你想操作的数字" << endl;
			cin >> numberOne >> numberTwo;
			start = clock();
			cout << n.numberSub(numberOne, numberTwo) << endl;
			end = clock();
			cost = end - start;
			cout << "花费：" << cost << "毫秒" << endl;
		}
		else if (number == "3")
		{
			string numberOne;
			string numberTwo;
			cout << "请输入你想操作的数字" << endl;
			cin >> numberOne >> numberTwo;
			start = clock();
			cout << n.numberMul(numberOne, numberTwo) << endl;
			end = clock();
			cost = end - start;
			cout << "花费：" << cost << "毫秒" << endl;
		}
		else if (number == "4")
		{
			string numberOne;
			string numberTwo;
			cout << "请输入你想操作的数字" << endl;
			cin >> numberOne >> numberTwo;
			start = clock();
			cout << n.numberDiv(numberOne, numberTwo) << endl;
			end = clock();
			cost = end - start;
			cout << "花费：" << cost << "毫秒" << endl;
		}
		else if (number == "5")
		{
			string numberOne;
			string numberTwo;
			cout << "请输入你想操作的数字" << endl;
			cin >> numberOne >> numberTwo;
			start = clock();
			cout << n.numberMod(numberOne, numberTwo) << endl;
			end = clock();
			cost = end - start;
			cout << "花费：" << cost << "毫秒" << endl;
		}
		else
		{
			cout << "你选错了" << endl;
		}
	}
	else if (a == "2")
	{
		cout << "请输入想做的操作：1+，2-，3*，4/，5mod" << endl;
		string number;
		cin >> number;
		if (number == "1")
		{
			string numberOne;
			string numberTwo;
			cout << "请输入你想操作的数字" << endl;
			cin >> numberOne >> numberTwo;
			start = clock();
			cout << b.binAdd(numberOne, numberTwo) << endl;
			end = clock();
			cost = end - start;
			cout << "花费：" << cost << "毫秒" << endl;
		}
		else if (number == "2")
		{
			string numberOne;
			string numberTwo;
			cout << "请输入你想操作的数字" << endl;
			cin >> numberOne >> numberTwo;
			start = clock();
			cout << b.binSub(numberOne, numberTwo) << endl;
			end = clock();
			cost = end - start;
			cout << "花费：" << cost << "毫秒" << endl;
		}
		else if (number == "3")
		{
			string numberOne;
			string numberTwo;
			cout << "请输入你想操作的数字" << endl;
			cin >> numberOne >> numberTwo;
			start = clock();
			cout << b.binMul(numberOne, numberTwo) << endl;
			end = clock();
			cost = end - start;
			cout << "花费：" << cost << "毫秒" << endl;
		}
		else if (number == "4")
		{
			string numberOne;
			string numberTwo;
			cout << "请输入你想操作的数字" << endl;
			cin >> numberOne >> numberTwo;
			start = clock();
			cout << b.binDiv(numberOne, numberTwo) << endl;
			end = clock();
			cost = end - start;
			cout << "花费：" << cost << "毫秒" << endl;
		}
		else if (number == "5")
		{
			string numberOne;
			string numberTwo;
			cout << "请输入你想操作的数字" << endl;
			cin >> numberOne >> numberTwo;
			start = clock();
			cout << b.binMod(numberOne, numberTwo) << endl;
			end = clock();
			cost = end - start;
			cout << "花费：" << cost << "毫秒" << endl;
		}
		else
		{
			cout << "你选错了" << endl;
		}
	}
	else
	{
		cout << "你输错了" << endl;
		return 0;
	}
}