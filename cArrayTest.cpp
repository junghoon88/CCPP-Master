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
	cout << "arr      : " << arr << endl;		//arr �� �ּ� ���� ������ ����
	cout << "arr + 1  : " << arr + 1 << endl;	//arr + 1 : int ũ��� ��ĭ ����
	cout << "&arr + 1 : " << &arr + 1 << endl;	//&arr + 1 : int[5] ũ��� ��ĭ ����
	//cout << &(arr + 1) + 1) << endl;			//&(arr + 1) : ������ ����

	Test1_1(arr);

	int *ptr = (int*)(&arr + 1);
	cout << "*(ptr - 1) : " << *(ptr - 1) << endl; //&(arr + 1) - 1 �̹Ƿ� int[5]-int �� ��


}

void cArrayTest::InitTest(void)
{
	int arr1[5];
	cout << "�ʱ�ȭ �׽�Ʈ : " << arr1[0] << arr1[1] << arr1[2] << arr1[3] << arr1[4] << endl;
	//�����Ⱚ
	int arr2[5] = { 1 };
	cout << "�ʱ�ȭ �׽�Ʈ : " << arr2[0] << arr2[1] << arr2[2] << arr2[3] << arr2[4] << endl;
	//ó�� ���� 1�� �ְ� �������� 0���� �ڵ����� ����.
	int arr3[5] = {};
	cout << "�ʱ�ȭ �׽�Ʈ : " << arr3[0] << arr3[1] << arr3[2] << arr3[3] << arr3[4] << endl;
	//0���� �ڵ����� ����.
}

void cArrayTest::Test1_1(int arr[])
{
	//���⼭ arr�� ������ó�� �����ϱ� ������ ����� ������ ������� ����
	cout << "sizeof(arr)   : " << sizeof(arr) << endl;
	cout << "sizeof(arr[0] : " << sizeof(arr[0]) << endl;
}
