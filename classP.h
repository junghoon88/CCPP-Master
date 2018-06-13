#pragma once

class classP
{
public:
	classP();
	virtual ~classP();

public:
	void Func1(void);
	void Func2(void);
	virtual void Func3(void);
	virtual void Func4(void) = 0;

protected:
	int a;
};

