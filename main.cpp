#include <stdio.h>
#include "BigNum.h"

//²âÊÔ¼Ó·¨
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

//²âÊÔ¼õ·¨
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

//²âÊÔ³Ë·¨
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