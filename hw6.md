# hw6

## 概念题

1. 在C++中，protect类成员访问控制的作用是什么

   1.用protected说明的成员不能通过对象使用，但可以在派生类中使用。

   2.protected访问控制缓解了封装与继承的矛盾。

2. 派生类除了拥有新定义的成员外，还拥有基类的所有成员（基类的构造函数、析构函数和赋值操作符重载函数除外）

3.  阐述在C++继承中隐藏的概念

   如果派生类中定义了与基类同名的成员，则基类的成员名在派生类的作用域内不直接可见。访问基类同名成员时要用基类名受限。

## 编程题

```c++
	Classic::Classic(string performers, string label, string mainfile, int selections, double playtime):Cd(performers, label, selections, playtime)
	{
		this->mainfile = mainfile;
	}
	Classic::Classic(const Cd& d, string mainfile):Cd(d)
	{
		
		this->mainfile = mainfile;
	}
	Classic::Classic(const Classic& d):Cd(d)
	{
		mainfile = d.mainfile;
	}
	Classic::Classic()
	{
		mainfile = "null";
	}
	Classic::~Classic()
	{

	}
	void Classic::Report() const
	{
		cout << "mainfile: " << mainfile << endl;
		Cd::Report();
	}
	Classic& Classic::operator=(const Classic& d)
	{
		if (this == &d)
			return *this;
		else
		{
			*(Cd*)this = d;
			return *this;
		}
	}
```

