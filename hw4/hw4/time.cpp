#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
enum Member_type {
	NUM, SIGN
};
struct member {
	member(double n) {
		m_type = NUM;
		num = n;
	}
	member(char n) {
		m_type = SIGN;
		sign = n;
	}
	Member_type m_type;
	double num;
	char sign;
};
int main() {
	string source, num_tmp;
	stack<char> sign;
	vector<member*> suffix;
	source = "1+10*(10.0-10.0)";
	//中缀转后缀
	for (int idx = 0; idx < source.size(); idx++) {
		char c = source[idx];
		bool negative = false;
		switch (c) {
		case '-':
			//判断-号的作用是什么，是负数？还是运算符号？
			if (isdigit(source[idx + 1])) {
				if (idx == 0)
					negative = true;
				else if (!isdigit(source[idx - 1]))
					negative = true;
			}
			if (negative) {
				num_tmp.clear();
				num_tmp.push_back('-');
				++idx;
				goto dealNum;//跳转到处理数字的地方执行
			}//此处没有break，当判断出-号的作用不是负数符号而是运算符号时，顺序执行下面的代码块
		case '+':
			//+-优先级高于栈顶元素，直接入栈。
			//因为+-优先级最低，所以只有当栈为空的时候才能直接入栈
			if (sign.empty())
				sign.push(c);
			else {
				//弹出比+-优先级高或相等的运算符，括号不考虑的情况下，符合条件的有+-*/
				while (!sign.empty() && sign.top() != '(') {
					suffix.emplace_back(new member(sign.top()));
					sign.pop();
				}
				sign.push(c);
			}
			break;
		case '*':
		case '/':
			//*/优先级高于栈顶元素，直接入栈
			if (sign.empty() || sign.top() == '+' || sign.top() == '-')
				sign.push(c);
			else {
				//弹出比*/优先级高或者相等的运算符，括号不考虑的情况下，符合条件的只有*/
				while (!sign.empty() && (sign.top() == '*' || sign.top() == '/')) {
					suffix.emplace_back(new member(sign.top()));
					sign.pop();
				}
				sign.push(c);
			}
			break;
		case '(':
			//左括号直接入栈
			sign.push(c);
			break;
		case ')':
			//依次弹出运算符，加入到后缀表达式中，直到碰到左括号
			while (sign.top() != '(') {
				suffix.emplace_back(new member(sign.top()));
				sign.pop();
			}
			sign.pop();
			break;
		default:
			//数字直接加入后缀表达式
			//+-*/的ascII码都小于'0'

			//截取数字
			num_tmp.clear();
		dealNum:while (source[idx] >= '0' || source[idx] == '.') {
			num_tmp.push_back(source[idx]);
			++idx;
		}
		--idx;
		suffix.emplace_back(new member(stod(num_tmp)));
		break;
		}
	}
	//当扫描的中缀表达式结束时，栈中的的所有运算符出栈
	while (!sign.empty()) {
		suffix.emplace_back(new member(sign.top()));
		sign.pop();
	}


	//输出后缀表达式
	for (auto x : suffix) {
		if (x->m_type == SIGN)
			cout << x->sign << ' ';
		else
			cout << x->num << ' ';
	}
	cout << endl;

	//计算后缀表达式的结果
	stack<double> nums;
	for (auto x : suffix) {
		if (x->m_type == NUM)
			nums.push(x->num);
		else {
			double b = nums.top();
			nums.pop();
			double a = nums.top();
			nums.pop();
			switch (x->sign) {
			case '+':
				nums.push(a + b);
				break;
			case '-':
				nums.push(a - b);
				break;
			case '*':
				nums.push(a * b);
				break;
			case '/':
				nums.push(a / b);
				break;
			}
		}
	}
	cout << nums.top() << endl;
	return 0;
}