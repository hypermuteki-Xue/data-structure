#ifndef _NUMBEROPERATOR_H_
#define _NUMBEROPERATOR_H_
#include<string>
using std::string;
class numberOperator
{
public:
	static string numberAdd(string numberOne, string numberTwo);
	static string numberSub(string numberOne, string numberTwo);
	static string numberMul(string numberOne, string numberTwo);
	static string numberDiv(string numberOne, string numberTwo);
	static string numberPow(string numberOne, string numberTwo);
	static string numberMod(string numberOne, string numberTwo);
	

};
#endif 


