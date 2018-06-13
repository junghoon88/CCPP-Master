#pragma once

class classB;

class classA
{
public:
	friend classB;

public:
	classA();
	~classA();

	//���������
	classA(const classA& copy);
	//���Կ�����
	const classA& operator=(const classA& copy);
	const classA* operator=(const classA* copy);


public:
	void publicFunc1(void);
	static void staticFunc1(void);
	friend void friendFunc1(void);

private:
	void privateFunc1(void);
	static void staticFunc2(void);
	friend void friendFunc2(void);



private:
	int data1;
	static int data2;
	//friend int data3;	//�������� friend ��� �Ұ�.

	
};

