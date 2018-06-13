#include "stdafx.h"
#include "classB.h"
#include "classA.h"


classB::classB()
{
}


classB::~classB()
{
}

void classB::publicFunc1(classA * a)
{
	cout << "classB::publicFunc1 -> ";
	a->publicFunc1();
}

void classB::staticFunc1(classA * a)
{
	cout << "classB::staticFunc1 -> ";
	a->staticFunc1();
}

void classB::privateFunc1(classA * a)
{
	cout << "classB::privateFunc1 -> ";
	a->privateFunc1();
}

void classB::staticFunc2(classA * a)
{
	cout << "classB::staticFunc2 -> ";
	a->staticFunc2();
}
