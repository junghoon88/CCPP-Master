#include "stdafx.h"
#include "classA.h"

int classA::data2 = 0;

classA::classA()
	: data1(0)
{
}

classA::~classA()
{
}

classA::classA(const classA & copy)
{
	this->data1 = copy.data1;
	//this->data2 = copy.data2; //static 이라서 같은값
}

const classA & classA::operator=(const classA & copy)
{
	this->data1 = copy.data1;
	//this->data2 = copy.data2; //static 이라서 같은값
	return (*this);
}

void classA::publicFunc1(void)
{
	data1 = 1;
	data2 = 1;
	cout << "classA::publicFunc1 - data1 : " << data1 << ", data2 : " << data2 << endl;
}

void classA::staticFunc1(void)
{
	//data1 = 2; //static 변수만 접근 가능
	data2 = 2;
	cout << "classA::staticFunc1 - data2 : " << data2 << endl;
}

void classA::privateFunc1(void)
{
	data1 = 3;
	data2 = 3;
	cout << "classA::privateFunc1 - data1 : " << data1 << ", data2 : " << data2 << endl;
}

void classA::staticFunc2(void)
{
	//data1 = 4; //static 변수만 접근 가능
	data2 = 4;
	cout << "classA::staticFunc2 - data2 : " << data2 << endl;
}

//void classA::friendFunc1(void) //classA 함수라고 생각하지 않음
//void friendFunc1(void)
//{
//	//data1 = 5;
//	//data2 = 5;
//	cout << "classA::friendFunc1" << endl;
//}
//
//void friendFunc2(void)
//{
//	//data1 = 6;
//	//data2 = 6;
//	cout << "classA::friendFunc2" << endl;
//}
