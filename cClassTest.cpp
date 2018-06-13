#include "stdafx.h"
#include "cClassTest.h"

#include "classA.h"
#include "classB.h"

#include "classP.h"
#include "classS.h"


cClassTest::cClassTest()
{
	cout << "------classTest------" << endl;
	
	TestToStaticFriend();
	cout << endl;
	
	TestToParentSon();
	cout << endl;
}


cClassTest::~cClassTest()
{
}


//classA friend function
void friendFunc1(void)
{
	//data1 = 5;	//���� �Ұ�
	//data2 = 5;	//���� �Ұ�
	cout << "classA::friendFunc1" << endl;
}

void friendFunc2(void)
{
	//data1 = 6;	//���� �Ұ�
	//data2 = 6;	//���� �Ұ�
	cout << "classA::friendFunc2" << endl;
}

void cClassTest::TestToStaticFriend(void)
{
	//static, friend test
	cout << "static, friend test" << endl;

	classA* A = new classA();
	A->publicFunc1();
	A->staticFunc1();
	friendFunc1();			//���� �Լ� ������ ������ ���ٰ���.
	//A->privateFunc1();	//private ���� �Լ��̱� ������ ���� �Ұ�
	//A->staticFunc2();		//private ���� �Լ��̱� ������ ���� �Ұ�
	friendFunc2();			//private�̾ ���� �Լ� ������ ������ ���ٰ���.

	//���������
	cout << "���������" << endl;
	classA* AA = new classA(*A);
	
	//���Կ�����
	cout << "���Կ�����" << endl;
	*A = *AA;
	delete AA;

	classB* B = new classB();
	B->publicFunc1(A);
	B->staticFunc1(A);
	B->privateFunc1(A);
	B->staticFunc2(A);

	delete A;
	delete B;
}

void cClassTest::TestToParentSon(void)
{
	//case 1 : �θ� �θ�� ����
	//classP* P = new classP(); //���������Լ� Func4 ������ ������ �� ����.

	//case 2 : �θ� �ڽ����� ����
	cout << "case 2 : �θ� �ڽ����� ����" << endl;
	classP* P = new classS();

	P->Func1();				//�����Ͱ� �θ�Ŭ���� �̹Ƿ� �θ� �Լ��� ����
	P->Func2();				//�����Ͱ� �θ�Ŭ���� �̹Ƿ� �θ� �Լ��� ����
	P->Func3();				//�����Լ�(virtual) �̹Ƿ� �ڽ� �Լ��� ����
	P->Func4();				//�����Լ�(virtual) �̹Ƿ� �ڽ� �Լ��� ����
	P->classP::Func1();		//�θ� Ŭ������ �Լ��� ������ ����
	P->classP::Func2();		//�θ� Ŭ������ �Լ��� ������ ����
	P->classP::Func3();		//�θ� Ŭ������ �Լ��� ������ ����
	//P->classS::Func1();	//������ ���� : �θ� �ڽ��� ����� ������ ���� �ʱ� ����
	//P->classS::Func2();	//������ ����
	//P->classS::Func3();	//������ ����
	dynamic_cast<classS*>(P)->Func1(); //�θ������͸� ���� �ڽ����� ĳ�����ϰ� �Լ� ����
	dynamic_cast<classS*>(P)->Func2(); //�θ������͸� ���� �ڽ����� ĳ�����ϰ� �Լ� ����
	dynamic_cast<classS*>(P)->Func3(); //�θ������͸� ���� �ڽ����� ĳ�����ϰ� �Լ� ����

	delete P;
	cout << endl;


	//case 3 : �ڽ��� �ڽ����� ����
	cout << "case 3 : �ڽ��� �ڽ����� ����" << endl;
	classS* S = new classS();

	S->Func1();				//�ڽ��Լ��� ����
	S->Func2();				//�ڽ��Լ��� ����
	S->Func3();				//�ڽ��Լ��� ����
	S->Func4();				//�ڽ��Լ��� ����
	S->classS::Func1();		//�ڽ��Լ��� ����(���� ����)
	S->classS::Func2();		//�ڽ��Լ��� ����(���� ����)
	S->classS::Func3();		//�ڽ��Լ��� ����(���� ����)
	S->classP::Func1();		//�θ��� �Լ� ����
	S->classP::Func2();		//�θ��� �Լ� ����
	S->classP::Func3();		//�θ��� �Լ� ����

	delete S;
	cout << endl;
}


