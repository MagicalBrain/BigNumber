#pragma once
#include <stdio.h>
#include <string.h>

/*
* 长度超过所有类型的正数的自定义头文件
*/

typedef struct BigNum
{
	int len;
	int num[100];
	BigNum()
	{
		memset(num, 0, sizeof(num));
		len = 0;
	}
}BigNum;

//字符串转BigNum
BigNum str2BigNum(char* num)
{
	BigNum re;
	char t;
	int i = 0;
	int len = strlen(num);
	re.len = len;
	while (num[i] != '\0')
	{
		re.num[re.len - 1 - i] = num[i] - '0';
		i++;
	}
	return re;
}

//输出BigNum
void Print_BigNum(BigNum num)
{
	for (int i = num.len-1; i >= 0; i--)
	{
		printf("%d", num.num[i]);
	}
	printf("\n");
}

//高精度加法
//void add(BigNum num1, BigNum num2)
BigNum add(BigNum num1, BigNum num2)
{
	BigNum re;
	int carry = 0;
	for (int i = 0; i < num1.len; i++)
	{
		int temp = num1.num[i] + num2.num[i] + carry;
		re.num[re.len++] = temp % 10;
	}
	if (carry != 0)
		re.num[re.len++] = carry;
	return re;
}

//高精度减法


//高精度乘法


//高精度除法