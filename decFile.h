#pragma once
#ifndef _DECFILE_H
#define _DECFILE_H
#include"numberList.h"
class decFile
{
 public:
	 numberList read();
	 void write(numberList numberlist);
};

#endif // !_DECFILE_H
