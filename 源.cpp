#include<iostream>
#include"numberOperator.h"
#include"numberList.h"
#include"numberNode.h"
#include"binaryOperator.h"
#include"decFile.h"
#include"binFile.h"
#include<string>
#include<cstring>
int numberNode::code = 0;
using namespace std;
int main()
{
	binaryOperator b;
	numberOperator n;
	string a = "1";
	string c(a, 1, a.length());
	cout << c << endl;
	cout << b.binAdd("0","01") << endl;
	cout<<b.binDiv("0100010001", "0111");
}