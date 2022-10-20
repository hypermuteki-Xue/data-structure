#ifndef _NUMBERLIST_H_
#define _NUMBERLIST_H_
#include<string>
using std::string;
class numberList
{
public:
	numberList* next;
	numberList();
	numberList(string value);
	numberList(string value, numberList* _next);
private:
	string value;
	string number;
};
#endif