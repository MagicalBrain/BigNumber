#include <stdio.h>
#include "BigNum.h"

//���Լӷ�
int main_01()
{
	char num1[100] = "1234567890";
	char num2[100] = "7980";

	BigNum Num1 = str2BigNum(num1);
	BigNum Num2 = str2BigNum(num2);

	Print_BigNum(Num1);
	Print_BigNum(Num2);

	BigNum re;
	re = add(Num1, Num2);

	Print_BigNum(re);

	return 0;
}

//���Լ���
int main_02()
{
	char num1[100] = "1234567890";
	char num2[100] = "7980";

	BigNum Num1 = str2BigNum(num1);
	BigNum Num2 = str2BigNum(num2);

	Print_BigNum(Num1);
	Print_BigNum(Num2);

	BigNum re;
	re = add(Num1, Num2);

	Print_BigNum(re);

	return 0;
}

//���Գ˷�
int main()
{
	char num1[100] = "1234567890";
	char num2[100] = "7980";

	BigNum Num1 = str2BigNum(num1);
	BigNum Num2 = str2BigNum(num2);

	Print_BigNum(Num1);
	Print_BigNum(Num2);

	BigNum re;
	re = add(Num1, Num2);

	Print_BigNum(re);

	return 0;
}