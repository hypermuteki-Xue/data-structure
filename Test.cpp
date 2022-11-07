#include<iostream>
#include"numberOperator.h"
#include"numberList.h"
#include"numberNode.h"
#include"binaryOperator.h"
#include<fstream>
#include"decFile.h"
using namespace std;
string ans;
string numberOne="110001";
string numberTwo="9";
numberOperator n;
binaryOperator b;
int numberNode::code = 0;
int main()
{
	decFile file;
	numberList d=file.read();
	d.show();
	file.write(d);
}
