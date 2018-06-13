#pragma once
#include "classP.h"

class classS : public classP
{
public:
	classS();
	~classS();

public:
	void Func1(void);
	void Func2(void);
	virtual void Func3(void) override;
	virtual void Func4(void) override;

private:
	int a;
};

