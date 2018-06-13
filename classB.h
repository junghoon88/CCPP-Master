#pragma once

class classA;

class classB
{
public:
	classB();
	~classB();

public:
	void publicFunc1(classA* a);
	static void staticFunc1(classA* a);
	void privateFunc1(classA* a);
	static void staticFunc2(classA* a);

};

