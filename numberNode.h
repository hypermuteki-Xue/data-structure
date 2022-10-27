#pragma once
#ifndef _NUMBERNODE_H
#define _NUMBERNODE_H
#include<string>
using std::string;
class numberNode
{
public:
	numberNode();
	numberNode(string value);
	numberNode(string value, numberNode* _next);
	numberNode* next;
	string to_String();
	int static code;
private:
	string value;
	string number;
};

#endif // !_NUMBERNODE_H

