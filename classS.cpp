#include "stdafx.h"
#include "classS.h"


classS::classS()
	: a(0)
{
	cout << "classS constructor" << endl;
}


classS::~classS()
{
	cout << "classS destructor" << endl;
}

void classS::Func1(void)
{
	a = 1;
	classP::a = 11;
	cout << "classS::Func1 : " << "a : " << a << ", super::a : " << classP::a << endl;
}

void classS::Func2(void)
{
	a = 2;
	classP::a = 22;
	cout << "classS::Func2 : " << "a : " << a << ", super::a : " << classP::a << endl;
}

void classS::Func3(void)
{
	a = 3;
	classP::a = 33;
	cout << "classS::Func3 : " << "a : " << a << ", super::a : " << classP::a << endl;
}

void classS::Func4(void)
{
	a = 4;
	classP::a = 44;
	cout << "classS::Func4 : " << "a : " << a << ", super::a : " << classP::a << endl;
}

