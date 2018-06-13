#include "stdafx.h"
#include "classP.h"


classP::classP()
	: a(0)
{
	cout << "classP constructor" << endl;
}


classP::~classP()
{
	cout << "classP destructor" << endl;
}

void classP::Func1(void)
{
	a = 1;
	cout << "classP::Func1 : " << "a : " << a << endl;
}

void classP::Func2(void)
{
	a = 2;
	cout << "classP::Func2 : " << "a : " << a << endl;
}

void classP::Func3(void)
{
	a = 3;
	cout << "classP::Func3 : " << "a : " << a << endl;
}
