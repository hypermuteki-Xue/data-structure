#pragma once
#include"numberList.h"
class binFile
{
public:
	numberList read();
	void write(numberList numberlist);
};