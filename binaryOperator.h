#pragma once
#ifndef _BINARYOPERATOR_H
#define _BINARYOPERATOR_H
#include<string>
using std::string;
class binaryOperator
{
public:
	static string binAdd(string numberOne, string numberTwo);
	static string binMul(string numberOne, string numberTwo);
	static string binSub(string numberOne, string numberTwo);
	static string binDiv(string numberOne, string numberTwo);
	static string change(string number);
};
#endif // !_BINARYOPERATOR_H

