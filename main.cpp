#include "stdafx.h"
#include "cClassTest.h"
#include "cArrayTest.h"

int main()
{
	cClassTest* ClassTest = new cClassTest();
	delete ClassTest;

	cArrayTest* ArrayTest  = new cArrayTest();
	delete ArrayTest;


    return 0;
}

