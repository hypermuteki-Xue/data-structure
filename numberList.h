#ifndef _NUMBERLIST_H_
#define _NUMBERLIST_H_
#include<string>
#include<list>
#include"numberNode.h"
using std::string;
class numberList
{
public:
	numberList();
	numberList(numberNode &_numberNode);
	numberNode* first=NULL;
	numberNode* last=NULL;
	numberNode getfirst();
	numberNode getLast();
	void setNext(numberNode& _numberNode);
	void show();
};

#endif