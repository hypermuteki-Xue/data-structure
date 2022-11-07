#include"decFile.h"
#include<fstream>
#include<iostream>
using std::ifstream;
using std::ios;
using std::cout;
using std::endl;
numberList decFile::read()
{
	numberList decList;
	ifstream ifs1;
	ifs1.open("dec.txt", ios::in);
	if (!ifs1.is_open())
	{
		cout << "不存在十进制文件" << endl;
		exit(0);
	}
	else
	{
		string numberOne = "", numberTwo = "";
		while (ifs1 >> numberOne >> numberTwo)
		{
			numberNode* numbernode = new numberNode(numberOne);
			numberNode* numbernode_ = new numberNode(numberTwo);
			decList.setNext(numbernode);
			decList.setNext(numbernode_);
		}
	}
	ifs1.close();
	return decList;
}
void decFile::write(numberList list)
{
	std::ofstream ofs;
	ofs.open("dec.txt", ios::out);
	numberNode* temp = list.first;
	while (temp != NULL)
	{
		ofs << temp->getValue() << " ";
		temp = temp->next;
	}
	ofs.close();
}