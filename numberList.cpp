#include"numberList.h"
#include<string>
#include<ctime>
using std::string;
using std::to_string;
numberList::numberList()
{
	value = "";
	number = "";
	next = NULL;
}
numberList::numberList(string value)
{
	this->value = value;
	srand(time(0));
	number = to_string(rand());
	next = NULL;
}
numberList::numberList(string value, numberList* _next)
{
	this->value = value;
	srand(time(0));
	number = to_string(rand());
	next = _next;
}