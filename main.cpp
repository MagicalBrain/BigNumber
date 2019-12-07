#include <stdio.h>
#include "BigNumber.h"

//测试移位
int main_000()
//int main()
{
	char num1[100] = "1234567890";

	Bign Num1 = str2BigNum(num1);

	Print_BigNum(Num1);

	int b = 2;
	Bign re;
	re = multiply_low(Num1, b);

	Print_BigNum(re);

	re = LMove_1digit(re,2);

	Print_BigNum(re);

	printf("re's len = %d\n", re.len);

	return 0;
}

//测试加法
int main_01()
//int main()
{
	char num1[100] = "98767828809600000";
	char num2[100] = "11140270331006808";

	Bign Num1 = str2BigNum(num1);
	Bign Num2 = str2BigNum(num2);

	Print_BigNum(Num1);
	Print_BigNum(Num2);

	Bign re;
	re = add(Num2, Num1);

	Print_BigNum(re);
	re = add(Num1, Num2);

	Print_BigNum(re);

	return 0;
}

//测试减法
//int main_02()
int main()
{
	char num1[100] = "1234567890";
	char num2[100] = "7980";

	Bign Num1 = str2BigNum(num1);
	Bign Num2 = str2BigNum(num2);

	Print_BigNum(Num1);
	Print_BigNum(Num2);

	Bign re;
	re = sub(Num1, Num2);

	Print_BigNum(re);

	return 0;
}

//测试低精度乘法
int main_03()
//int main()
{
	char num1[100] = "123459786012";

	Bign Num1 = str2BigNum(num1);

	Print_BigNum(Num1);
	
	int b = 4;
	Bign re;
	re = multiply_low(Num1, b);

	Print_BigNum(re);

	return 0;
}

// 测试高精度乘法
int main_04()
//int main()
{
	char num1[100] = "12345978";
	char num2[100] = "17890234";
	//char num2[100] = "890234";

	Bign Num1 = str2BigNum(num1);
	Bign Num2 = str2BigNum(num2);

	Print_BigNum(Num1);
	Print_BigNum(Num2);

	Bign re;
	re = multiply_high(Num1, Num2);

	Print_BigNum(re);
	printf("re's len:%d\n", re.len);

	return 0;
}