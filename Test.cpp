#include<iostream>
#include"numberOperator.h"
#include"numberList.h"
#include"numberNode.h"
#include"binaryOperator.h"
#include"decFile.h"
#include"binFile.h"
int numberNode::code = 0;
using namespace std;
int main()
{
	binaryOperator b;
	numberOperator n;
	decFile decfile;
	binFile binfile;
	numberList dec=decfile.read();
	numberList bin = binfile.read();
	bin.show();
	dec.show();
	cout << "请输入想做的操作：1+，2-，3*，4/，5mod"<<endl;
	string number;
	cin >> number;
	if (number == "1")
	{
		numberList tempList;
		string numberOne = dec.getfirst().getValue();
		string numberTwo = dec.getLast().getValue();
		numberNode tempnode(n.numberAdd(numberOne, numberTwo));
		tempList.setNext(tempnode);
		decfile.write(tempList);
		numberList tempList2;
		numberOne = bin.getfirst().getValue();
		numberTwo = bin.getLast().getValue();
		numberNode tempnode1(b.binAdd(numberOne, numberTwo));
		tempList2.setNext(tempnode1);
		binfile.write(tempList2);

	}
	else if (number == "2")
	{
		numberList tempList;
		string numberOne = dec.getfirst().getValue();
		string numberTwo = dec.getLast().getValue();
		numberNode tempnode(n.numberSub(numberOne, numberTwo));
		tempList.setNext(tempnode);
		tempList.show();
		decfile.write(tempList);
		numberList tempList2;
		numberOne = bin.getfirst().getValue();
		numberTwo = bin.getLast().getValue();
		numberNode tempnode1(b.binSub(numberOne, numberTwo));
		tempList2.setNext(tempnode1);
		tempList2.show();
		binfile.write(tempList2);
	}
	else if (number == "3")
	{
		numberList tempList;
		string numberOne = dec.getfirst().getValue();
		string numberTwo = dec.getLast().getValue();
		numberNode tempnode(n.numberMul(numberOne, numberTwo));
		tempList.setNext(tempnode);
		tempList.show();
		decfile.write(tempList);
		numberList tempList2;
		numberOne = bin.getfirst().getValue();
		numberTwo = bin.getLast().getValue();
		numberNode tempnode1(b.binMul(numberOne, numberTwo));
		tempList2.setNext(tempnode1);
		tempList2.show();
		binfile.write(tempList2);
	}
	else if (number == "4")
	{
		numberList tempList;
		string numberOne = dec.getfirst().getValue();
		string numberTwo = dec.getLast().getValue();
		numberNode tempnode(n.numberDiv(numberOne, numberTwo));
		tempList.setNext(tempnode);
		tempList.show();
		decfile.write(tempList);
		numberList tempList2;
		numberOne = bin.getfirst().getValue();
		numberTwo = bin.getLast().getValue();
		numberNode tempnode1(b.binDiv(numberOne, numberTwo));
		tempList2.setNext(tempnode1);
		tempList2.show();
		binfile.write(tempList2);
	}
	else if (number == "5")
	{
		numberList tempList;
		string numberOne = dec.getfirst().getValue();
		string numberTwo = dec.getLast().getValue();
		numberNode tempnode(n.numberMod(numberOne, numberTwo));
		tempList.setNext(tempnode);
		decfile.write(tempList);
		numberList tempList2;
		numberOne = bin.getfirst().getValue();
		numberTwo = bin.getLast().getValue();
		numberNode tempnode1(b.binMod(numberOne, numberTwo));
		tempList2.setNext(tempnode1);
		binfile.write(tempList2);
	}
	numberNode* first = bin.first;
	while (first != NULL)
	{
		numberNode* temp = first;
		first = first->next;
		delete temp;
	}
	 first = dec.first;
	while (first != NULL)
	{
		numberNode* temp = first;
		first = first->next;
		delete temp;
	}

}
