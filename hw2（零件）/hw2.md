1.在哪些情况下，会调用类的拷贝构造函数？什么时候需要自定义拷贝构造函数，为什么？

在创建一个对象时，若用另一个同类型的对象对其初始化，将会调用对象类中的拷贝构造函数。

在三种情况下，会调用类的拷贝构造函数：

创建对象时显式指出。

把对象作为值参数传给函数时。

把对象作为函数的返回值时。

2.描述 const 关键字在类中的适用场景和作用。

为了防止在一个获取对象状态的成员函数中无意中修改对象的数据成员，可以把它说明成常成员函数。

3.描述 static 关键字在类中的适用场景和作用。

采用静态数据成员可以更好地实现同一个类的不同对象之间的数据共享。

编程题：

```c++
#include<iostream>
using namespace std;
class Component
{
public:
	int Weight;
	static  int TotalWeights;
	int GetWeights()
	{
		return Weight;
	}
	Component(int x)
	{
		Weight = x;
		TotalWeights+=GetWeights();
	}
};
int Component::TotalWeights = 0;
```

