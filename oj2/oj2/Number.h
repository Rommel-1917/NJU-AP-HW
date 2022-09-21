#include<iostream>
#include<cmath>
using namespace std;
class Number
{
public:

	int num[100];
	int length;
	Number()
	{
		num[0]=0;
		length = 1;
		for (int i = 1; i < 100; i++)
		{
			num[i] = 0;
		}
	}
	Number(char* s, int l)
	{
		for (int i = 0; i < l; i++)
		{
			num[i] =s[i]-'0';
		
		}
		for (int i = l; i < 100; i++)
		{
			num[i] = 0;
		}
		length = l;
	}
	Number(const Number& number)
	{
		for (int i = 0; i < number.length; i++)
		{
			num[i] = number.num[i];
		}
		length = number.length;
		for (int i = length; i < 100; i++)
		{
			num[i] = 0;
		}
	}
	~Number()
	{

	}
	
		Number operator +(const Number & number) {
			Number sum;
			int a[100] = { 0 };
			int temp = 0;
			int j;
			if (length < number.length) {
				for (int i = 0; i < length; i++) {
					j = num[length - i - 1] + number.num[number.length - i - 1] + temp;
					a[99 - i] = j % 10;
					temp = j / 10;
				}
				for (int i = length; i < number.length; i++) {
					j = number.num[number.length - i - 1] + temp;
					a[99 - i] = j % 10;
					temp = j / 10;
				}
			}
			else if (length == number.length) {
				for (int i = 0; i < length; i++) {
					j = num[length - i - 1] + number.num[number.length - i - 1] + temp;
					a[99 - i] = j % 10;
					temp = j / 10;
				}
				a[99 - length] = temp;
			}
			else {
				for (int i = 0; i < number.length; i++) {
					j = number.num[number.length - i - 1] + num[length - i - 1] + temp;
					a[99 - i] = j % 10;
					temp = j / 10;
				}
				for (int i = number.length; i < length; i++) {
					j = num[length - i - 1] + temp;
					a[99 - i] = j % 10;
					temp = j / 10;
				}
			}
			int i = 0;
			while (a[i] == 0) {
				i++;
			}
			sum.length = 100 - i;
			sum.num = new int[sum.length];
			for (int i = 1; i <= sum.length; i++) 
			{
				sum.num[sum.length - i] = a[100 - i];
			}
			return sum;
		}

	}
	Number operator *( const Number& number)
	{
		Number temp;
		Number temp2;
		if ((num[0] == 0 && length == 1) || (number.num[0] == 0 && number.length == 1))
		{
			temp2.length = 1;
			temp2.num[0] = 0;
			return temp2;
		}
		for (int i = 0; i < 99; i++)
		{
			temp.num[i] = 0;
		}
		int l= length+number.length-1;
		
		
		for (int i = number.length-1,k=0;i>=0;i--,k++)
		{
			for (int j = length-1,q=0; j>=0;q++,j--)
			{
				temp.num[k + q] += num[j] * number.num[i];
			}
		}
		
		for (int i = 0; i <l; i++) 
		{
			if (temp.num[i] > 9) 
			{
				temp.num[i + 1] += temp.num[i] / 10;
				temp.num[i] %= 10;
				
				if (i == l - 1 && temp.num[i + 1] != 0)
					l++;
			}
		}
		for (int i = l-1, j = 0; i >= 0; j++, i--)
		{
			temp2.num[j] = temp.num[i];
			
		}
		temp2.length = l;
		return temp2;
	}
		
		
			
		
	
	bool  operator <(const Number& number)
	{
		if (length > number.length)
		{
			return false;
		}
		if (length < number.length)
		{
			return true;
		}
		else
		{
			for (int i = 0; i < length; i++)
			{
				if (num[i] < number.num[i])
					return true;
			}
		}
		return false;
	}
	friend void showNumber(const Number& number);
};