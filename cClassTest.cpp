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
	//data1 = 5;	//접근 불가
	//data2 = 5;	//접근 불가
	cout << "classA::friendFunc1" << endl;
}

void friendFunc2(void)
{
	//data1 = 6;	//접근 불가
	//data2 = 6;	//접근 불가
	cout << "classA::friendFunc2" << endl;
}

void cClassTest::TestToStaticFriend(void)
{
	//static, friend test
	cout << "static, friend test" << endl;

	classA* A = new classA();
	A->publicFunc1();
	A->staticFunc1();
	friendFunc1();			//실제 함수 선언한 곳에서 접근가능.
	//A->privateFunc1();	//private 영역 함수이기 때문에 접근 불가
	//A->staticFunc2();		//private 영역 함수이기 때문에 접근 불가
	friendFunc2();			//private이어도 실제 함수 선언한 곳에서 접근가능.

	//복사생성자
	cout << "복사생성자" << endl;
	classA* AA = new classA(*A);
	
	//대입연산자
	cout << "대입연산자" << endl;
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
	//case 1 : 부모를 부모로 생성
	//classP* P = new classP(); //순수가상함수 Func4 때문에 생성할 수 없다.

	//case 2 : 부모를 자식으로 생성
	cout << "case 2 : 부모를 자식으로 생성" << endl;
	classP* P = new classS();

	P->Func1();				//포인터가 부모클래스 이므로 부모 함수를 실행
	P->Func2();				//포인터가 부모클래스 이므로 부모 함수를 실행
	P->Func3();				//가상함수(virtual) 이므로 자식 함수를 실행
	P->Func4();				//가상함수(virtual) 이므로 자식 함수를 실행
	P->classP::Func1();		//부모 클래스의 함수를 강제로 실행
	P->classP::Func2();		//부모 클래스의 함수를 강제로 실행
	P->classP::Func3();		//부모 클래스의 함수를 강제로 실행
	//P->classS::Func1();	//컴파일 에러 : 부모가 자식을 멤버로 가지고 있지 않기 때문
	//P->classS::Func2();	//컴파일 에러
	//P->classS::Func3();	//컴파일 에러
	dynamic_cast<classS*>(P)->Func1(); //부모포인터를 원본 자식으로 캐스팅하고 함수 실행
	dynamic_cast<classS*>(P)->Func2(); //부모포인터를 원본 자식으로 캐스팅하고 함수 실행
	dynamic_cast<classS*>(P)->Func3(); //부모포인터를 원본 자식으로 캐스팅하고 함수 실행

	delete P;
	cout << endl;


	//case 3 : 자식을 자식으로 생성
	cout << "case 3 : 자식을 자식으로 생성" << endl;
	classS* S = new classS();

	S->Func1();				//자식함수로 실행
	S->Func2();				//자식함수로 실행
	S->Func3();				//자식함수로 실행
	S->Func4();				//자식함수로 실행
	S->classS::Func1();		//자식함수로 실행(위와 동일)
	S->classS::Func2();		//자식함수로 실행(위와 동일)
	S->classS::Func3();		//자식함수로 실행(위와 동일)
	S->classP::Func1();		//부모의 함수 실행
	S->classP::Func2();		//부모의 함수 실행
	S->classP::Func3();		//부모의 함수 실행

	delete S;
	cout << endl;
}


