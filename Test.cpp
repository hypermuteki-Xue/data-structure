#include<iostream>
#include"numberOperator.h"
#include"numberList.h"
#include"numberNode.h"
using namespace std;
string ans;
string numberOne="1";
string numberTwo="2";
numberOperator n;
int numberNode::code = 0;
void show(int &a)
{
	int* b = &a;
	cout << b<< endl;
}
int main()
{
	numberNode a("123");
	numberList numberlist(a);
	numberNode b("456");
	numberlist.setNext(b);
	numberlist.show();


}