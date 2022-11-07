#include"numberList.h"
#include<string>
#include<ctime>
using std::string;
using std::to_string;
numberNode::numberNode()
{
	value = "";
	number = "";
	next = NULL;
}
numberNode::numberNode(string value)
{
	this->value = value;
	number = to_string(code++);
	next = NULL;
}
numberNode::numberNode(string value, numberNode* _next)
{
	this->value = value;
	number = to_string(code++);
	next = _next;
}
string numberNode::to_String()
{
	string b = "number=" + number + " value=" + value + "\n";
	return b;
}
string numberNode::getValue()
{
	return value;
}