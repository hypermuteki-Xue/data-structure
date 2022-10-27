#include"numberList.h"
#include<string>
#include<ctime>
#include<iostream>
using std::string;
using std::to_string;
numberList::numberList()
{
	first = NULL;
	last = NULL;
}
numberList::numberList(numberNode &_numberNode)
{
	first = &_numberNode;
	last = first;
}
numberNode numberList::getfirst()
{
	return (*first);
}
numberNode numberList::getLast()
{
	return (*last);
}
void numberList::show()
{
	numberNode* temp=first;
	while (temp != NULL)
	{
		std::cout << temp->to_String();
		temp = temp->next;
	}
}
void numberList::setNext(numberNode& _numberNode)
{
	if (first == NULL) { first = &_numberNode; }
	if (last == NULL) { last = first; }
	else
	{
	 	last->next = &_numberNode;
	last = last->next;
	}
}