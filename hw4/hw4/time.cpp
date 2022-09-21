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
	//��׺ת��׺
	for (int idx = 0; idx < source.size(); idx++) {
		char c = source[idx];
		bool negative = false;
		switch (c) {
		case '-':
			//�ж�-�ŵ�������ʲô���Ǹ���������������ţ�
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
				goto dealNum;//��ת���������ֵĵط�ִ��
			}//�˴�û��break�����жϳ�-�ŵ����ò��Ǹ������Ŷ����������ʱ��˳��ִ������Ĵ����
		case '+':
			//+-���ȼ�����ջ��Ԫ�أ�ֱ����ջ��
			//��Ϊ+-���ȼ���ͣ�����ֻ�е�ջΪ�յ�ʱ�����ֱ����ջ
			if (sign.empty())
				sign.push(c);
			else {
				//������+-���ȼ��߻���ȵ�����������Ų����ǵ�����£�������������+-*/
				while (!sign.empty() && sign.top() != '(') {
					suffix.emplace_back(new member(sign.top()));
					sign.pop();
				}
				sign.push(c);
			}
			break;
		case '*':
		case '/':
			//*/���ȼ�����ջ��Ԫ�أ�ֱ����ջ
			if (sign.empty() || sign.top() == '+' || sign.top() == '-')
				sign.push(c);
			else {
				//������*/���ȼ��߻�����ȵ�����������Ų����ǵ�����£�����������ֻ��*/
				while (!sign.empty() && (sign.top() == '*' || sign.top() == '/')) {
					suffix.emplace_back(new member(sign.top()));
					sign.pop();
				}
				sign.push(c);
			}
			break;
		case '(':
			//������ֱ����ջ
			sign.push(c);
			break;
		case ')':
			//���ε�������������뵽��׺���ʽ�У�ֱ������������
			while (sign.top() != '(') {
				suffix.emplace_back(new member(sign.top()));
				sign.pop();
			}
			sign.pop();
			break;
		default:
			//����ֱ�Ӽ����׺���ʽ
			//+-*/��ascII�붼С��'0'

			//��ȡ����
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
	//��ɨ�����׺���ʽ����ʱ��ջ�еĵ������������ջ
	while (!sign.empty()) {
		suffix.emplace_back(new member(sign.top()));
		sign.pop();
	}


	//�����׺���ʽ
	for (auto x : suffix) {
		if (x->m_type == SIGN)
			cout << x->sign << ' ';
		else
			cout << x->num << ' ';
	}
	cout << endl;

	//�����׺���ʽ�Ľ��
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