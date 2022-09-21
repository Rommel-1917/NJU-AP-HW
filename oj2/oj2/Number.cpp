#include<iostream>
#include"Number.h"
using namespace std;
void showNumber(const Number& number)
{
	
	
		for (int i = 0; i < number.length; i++)
		{
			
			cout <<number.num[i];
		}
		cout << endl;
	
}
int main()
{
	
	char s1[] = "501", s2[] = "7";
	Number n1(s1, 3);
	Number n2(s2, 1);
	Number n3 = n1 + n2;
	showNumber(n3);


}