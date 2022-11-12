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
	cout<<b.binSub("01100", "01111");
	cout << endl << b.binAdd("01111", "01");
}