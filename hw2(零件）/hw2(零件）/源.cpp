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

int main()
{
	if (3++3)
		cout<< true;
	else
		return false;
}