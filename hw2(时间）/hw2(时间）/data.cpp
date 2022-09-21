#include<iostream>
using namespace std;
class Date
{
public:
	int y, m, d;
	Date() :y(2022), m(2), d(22)
	{
		y = 2022;
		m = 2;
		d = 22;
	}
	Date(int y1, int m1, int d1)
	{
		y = y1;
		m = m1;
		d = d1;
	}
	void set(int y2, int m2, int d2)
	{
		y = y2;
		m = m2;
		d = d2;
	}
	void display()
	{
		cout << y << "年" << m << "月" << d << "日";
	}
};
class Time
{
	Date dates;
	int hour, min, sec;
public:
	Time()
	{
		dates.set(2022, 2, 22);
		hour = 2;
		min = 2;
		sec = 2;
	}
	Time(Date date, int h, int m, int s)
	{
		dates = date;
		hour = h;
		min = m;
		sec = s;
	}
	void increment()
	{
		if (sec == 59)
		{
			sec = 0;
			min++;
			if (min == 60)
			{
				min = 0;
				hour++;
				if (hour == 24)
				{
					hour = 0;
					dates.d++;
				}
			}
		}
	}
	void display()
	{
		dates.display();
		cout << hour << "点" << min << "分" << sec << "秒";
	}
	bool equal(Time& other_time)
	{
		if (other_time.dates.y != dates.y)
			return false;
		if (other_time.dates.m != dates.m)
			return false;
		if (other_time.dates.d != dates.d)
			return false;
		if (other_time.hour != hour)
			return false;
		if (other_time.min != min)
			return false;
		if (other_time.sec != sec)
			return false;
		return true;
	}
	bool less_than(Time& other_time)
	{
		if(other_time.dates.y>dates.y)
			return true;
		if(other_time.dates.y<dates.y)
			return false;
		if (other_time.dates.m > dates.m)
			return true;
		if (other_time.dates.m < dates.m)
			return false;
		if (other_time.dates.d > dates.d)
			return true;
		if (other_time.dates.d < dates.d)
			return false;
		if (other_time.hour > hour)
			return true;
		if (other_time.hour < hour)
			return false;
		if (other_time.min > min)
			return true;
		if (other_time.min < min)
			return false;
		if (other_time.sec > sec)
			return true;
		return false;
	}
};