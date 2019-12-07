#pragma once
#include <stdio.h>
#include <string.h>

/*
* 长度超过所有类型的正数的自定义头文件
*/

typedef struct Bign
{
	int len;
	int data[100];
	Bign()
	{
		memset(data, 0, sizeof(data));
		len = 0;
	}
}Bign;

/*--------基本操作--------*/

//字符串转Bign
Bign str2BigNum(char* num)
{
	Bign re;
	//int i = 0;
	int len = strlen(num);
	re.len = len;
	
	for (int i = re.len - 1; i >= 0; i--)
	{
		re.data[i] = num[re.len - i - 1] - '0';
	}
	return re;
}

//输出Bign
void Print_BigNum(Bign num)
{
	if (num.len <= 0)
	{
		puts("输出失败！");
		return;
	}

	for (int i = num.len-1; i >= 0; i--)
	{
		printf("%d", num.data[i]);
	}
	printf("\n");
}

//比较大小
int Compare(Bign a, Bign b)
{
	if (a.len > 0 && b.len > 0)
	{
		if (a.len > b.len)
			return 1;
		else if (a.len < b.len)
			return -1;
		else
		{
			for (int i = 0; i < a.len; i++)
			{
				if (a.data[i] > b.data[i])
					return 1;
				else if (b.data[i] > a.data[i])
					return -1;
			}
			return 0;
		}
	}
	else
		return 0;
}

//左移一位
Bign LMove_1digit(Bign num,int d)
{
	Bign re;
	re.len = 0;
	memset(re.data, 0, sizeof(re.data));
	if (num.len <= 0)
	{
		puts("移位失败");
		return re;
	}
	for (int i = num.len-1; i >= 0; i--)
	{
		re.data[i + d] = num.data[i];
	}
	for (int i = 0; i < d; i++)
	{
		re.data[i] = 0;
	}
	
	re.len = num.len + d;

	return re;
}

/*--------四则运算--------*/

//高精度加法
//void add(Bign num1, Bign num2)
Bign add(Bign num1, Bign num2)
{
	Bign re;
	int carry = 0;
	if (num1.len > num2.len)
	{
		for (int i = 0; i < num1.len; i++)
		{
			int temp = num1.data[i] + num2.data[i] + carry;
			re.data[re.len++] = temp % 10;
			carry = temp / 10;
		}
	}
	else
	{
		for (int i = 0; i < num2.len; i++)
		{
			int temp = num2.data[i] + num1.data[i] + carry;
			re.data[re.len++] = temp % 10;
			carry = temp / 10;
		}
	}
	if (carry != 0)
		re.data[re.len++] = carry;
	return re;
}

//高精度减法
Bign sub(Bign a, Bign b)
{
	Bign c;
	c.len = 0;
	
	if (a.len < 1 || b.len < 1)
	{
		puts("相减失败");
		return c;
	}

	int carry = 0;
	if (a.len < b.len)
	{
		for (int i = 0; i < a.len; i++)
		{
			int result = b.data[i] - a.data[i] - carry;
			if (result < 0)
			{
				result += 10;
				carry = 1;
			}
			else
				carry = 0;
			c.data[c.len++] = result;
		}
	}
	else if (a.len > b.len)
	{
		for (int i = 0; i < b.len; i++)
		{
			int result = a.data[i] - b.data[i] - carry;
			if (result < 0)
			{
				result += 10;
				carry = 1;
			}
			else
				carry = 0;
			c.data[c.len++] = result;
		}
	}
	else
	{
		if (a.data[a.len - 1] > b.data[b.len - 1])
		{
			for (int i = 0; i < a.len; i++)
			{
				int result = a.data[i] - b.data[i] - carry;
				if (result < 0)
				{
					result += 10;
					carry = 1;
				}
				else
					carry = 0;
				c.data[c.len++] = result;
			}
		}
	}
	return c;
}

//低精度乘法
Bign multiply_low(Bign a, int b)
{
	Bign c;
	c.len = 0;
	memset(c.data, 0, sizeof(c.data));

	if (a.len < 1 )
	{
		puts("相乘失败！");
		return c;
	}

	int carry = 0;
	for (int i = 0; i < a.len; i++)
	{
		int result = a.data[i] * b + carry;
		c.data[c.len++] = result % 10;
		carry = result / 10;
	}

	while (carry != 0)
	{
		c.data[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

//高精度乘法
Bign multiply_high(Bign a, Bign b)
{
	Bign c;
	c.len = 1;
	memset(c.data, 0, sizeof(c.data));

	if (a.len < 1 || b.len < 1)
	{
		puts("乘法失败！");
		return c;
	}

	int carry = 0;
	int d = 0;
	for (int i = 0; i < b.len; i++)
	{
		Bign t;
		t.len = 0;
		
		t = multiply_low(a, b.data[i]);

		printf("i = %d\n", i);
		printf("t:\n");
		Print_BigNum(t);
		printf("t's len = %d\n", t.len);

		t = LMove_1digit(t,d++);

		printf("t:\n");
		Print_BigNum(t);
		printf("t's len = %d\n",t.len);

		c = add(t,c);
		printf("c:\n");
		Print_BigNum(c);
		printf("c's len = %d\n", c.len);
	}

	return c;
}

//高精度除法