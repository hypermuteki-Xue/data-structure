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
	cout << "��������Ľ��� 1ʮ���� 2������" << endl;
	string a;
	cin >> a;
	if (a == "1")
	{
		cout << "�����������Ĳ�����1+��2-��3*��4/��5mod" << endl;
		string number;
		cin >> number;
		if (number == "1")
		{
			string numberOne;
			string numberTwo;
			cout << "�������������������" << endl;
			cin >> numberOne >> numberTwo;
			start = clock();
			cout << n.numberAdd(numberOne, numberTwo) << endl;
			end = clock();
			cost = end - start;
			cout << "���ѣ�" << cost << "����" << endl;
		}
		else if (number == "2")
		{
			string numberOne;
			string numberTwo;
			cout << "�������������������" << endl;
			cin >> numberOne >> numberTwo;
			start = clock();
			cout << n.numberSub(numberOne, numberTwo) << endl;
			end = clock();
			cost = end - start;
			cout << "���ѣ�" << cost << "����" << endl;
		}
		else if (number == "3")
		{
			string numberOne;
			string numberTwo;
			cout << "�������������������" << endl;
			cin >> numberOne >> numberTwo;
			start = clock();
			cout << n.numberMul(numberOne, numberTwo) << endl;
			end = clock();
			cost = end - start;
			cout << "���ѣ�" << cost << "����" << endl;
		}
		else if (number == "4")
		{
			string numberOne;
			string numberTwo;
			cout << "�������������������" << endl;
			cin >> numberOne >> numberTwo;
			start = clock();
			cout << n.numberDiv(numberOne, numberTwo) << endl;
			end = clock();
			cost = end - start;
			cout << "���ѣ�" << cost << "����" << endl;
		}
		else if (number == "5")
		{
			string numberOne;
			string numberTwo;
			cout << "�������������������" << endl;
			cin >> numberOne >> numberTwo;
			start = clock();
			cout << n.numberMod(numberOne, numberTwo) << endl;
			end = clock();
			cost = end - start;
			cout << "���ѣ�" << cost << "����" << endl;
		}
		else
		{
			cout << "��ѡ����" << endl;
		}
	}
	else if (a == "2")
	{
		cout << "�����������Ĳ�����1+��2-��3*��4/��5mod" << endl;
		string number;
		cin >> number;
		if (number == "1")
		{
			string numberOne;
			string numberTwo;
			cout << "�������������������" << endl;
			cin >> numberOne >> numberTwo;
			start = clock();
			cout << b.binAdd(numberOne, numberTwo) << endl;
			end = clock();
			cost = end - start;
			cout << "���ѣ�" << cost << "����" << endl;
		}
		else if (number == "2")
		{
			string numberOne;
			string numberTwo;
			cout << "�������������������" << endl;
			cin >> numberOne >> numberTwo;
			start = clock();
			cout << b.binSub(numberOne, numberTwo) << endl;
			end = clock();
			cost = end - start;
			cout << "���ѣ�" << cost << "����" << endl;
		}
		else if (number == "3")
		{
			string numberOne;
			string numberTwo;
			cout << "�������������������" << endl;
			cin >> numberOne >> numberTwo;
			start = clock();
			cout << b.binMul(numberOne, numberTwo) << endl;
			end = clock();
			cost = end - start;
			cout << "���ѣ�" << cost << "����" << endl;
		}
		else if (number == "4")
		{
			string numberOne;
			string numberTwo;
			cout << "�������������������" << endl;
			cin >> numberOne >> numberTwo;
			start = clock();
			cout << b.binDiv(numberOne, numberTwo) << endl;
			end = clock();
			cost = end - start;
			cout << "���ѣ�" << cost << "����" << endl;
		}
		else if (number == "5")
		{
			string numberOne;
			string numberTwo;
			cout << "�������������������" << endl;
			cin >> numberOne >> numberTwo;
			start = clock();
			cout << b.binMod(numberOne, numberTwo) << endl;
			end = clock();
			cost = end - start;
			cout << "���ѣ�" << cost << "����" << endl;
		}
		else
		{
			cout << "��ѡ����" << endl;
		}
	}
	else
	{
		cout << "�������" << endl;
		return 0;
	}
}