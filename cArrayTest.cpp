#include "stdafx.h"
#include "cArrayTest.h"


cArrayTest::cArrayTest()
{
	cout << "cArrayTest" << endl;

	Test1();
	InitTest();
}


cArrayTest::~cArrayTest()
{
}


void cArrayTest::Test1(void)
{
	int arr[5] = { 0, 1, 2, 3, 4 };
	cout << "arr[0]   : " << arr[0] << endl;		
	cout << "arr      : " << arr << endl;		//arr 은 주소 값을 가지고 있음
	cout << "arr + 1  : " << arr + 1 << endl;	//arr + 1 : int 크기로 한칸 증가
	cout << "&arr + 1 : " << &arr + 1 << endl;	//&arr + 1 : int[5] 크기로 한칸 증가
	//cout << &(arr + 1) + 1) << endl;			//&(arr + 1) : 컴파일 에러

	Test1_1(arr);

	int *ptr = (int*)(&arr + 1);
	cout << "*(ptr - 1) : " << *(ptr - 1) << endl; //&(arr + 1) - 1 이므로 int[5]-int 가 됨


}

void cArrayTest::InitTest(void)
{
	int arr1[5];
	cout << "초기화 테스트 : " << arr1[0] << arr1[1] << arr1[2] << arr1[3] << arr1[4] << endl;
	//쓰래기값
	int arr2[5] = { 1 };
	cout << "초기화 테스트 : " << arr2[0] << arr2[1] << arr2[2] << arr2[3] << arr2[4] << endl;
	//처음 값만 1을 넣고 나머지는 0으로 자동으로 들어간다.
	int arr3[5] = {};
	cout << "초기화 테스트 : " << arr3[0] << arr3[1] << arr3[2] << arr3[3] << arr3[4] << endl;
	//0으로 자동으로 들어간다.
}

void cArrayTest::Test1_1(int arr[])
{
	//여기서 arr은 포인터처럼 동작하기 때문에 사이즈도 포인터 사이즈로 나옴
	cout << "sizeof(arr)   : " << sizeof(arr) << endl;
	cout << "sizeof(arr[0] : " << sizeof(arr[0]) << endl;
}
