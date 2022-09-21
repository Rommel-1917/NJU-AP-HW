#include<iostream>
#include<fstream>
#include<ctime>
#include<vector>
#include<sstream>
#include<stack>
#include"Date.h"
#include"Users.h"
using namespace std;
extern int usernum, goodnum, ordernum, moneynum, messagenum;
extern string usertitle, goodtitle, ordertitle, moneytitle, messagetitle;
extern vector<Users> alluser;
extern vector<Goods> allgood;
extern vector<Order> allorder;
extern vector<Money> allmoney;
extern vector<message> allmessage;
void Readgood()
{
	Goods g_temp;
	string temp;
	ifstream u("commodity.txt");
	getline(u, temp);
	while (getline(u, temp, ','))
	{
		g_temp.good_id = temp;
		getline(u, g_temp.good_name, ',');
		u >> g_temp.good_price;
		getline(u, temp, ',');
		u >> g_temp.good_num;
		getline(u, temp, ',');
		getline(u, g_temp.good_dis, ',');
		getline(u, g_temp.good_seller_id, ',');
		getline(u, g_temp.good_time, ',');
		getline(u, g_temp.good_state);
		goodnum++;
		allgood.push_back(g_temp);
	}
	u.close();

}
void Readorder()
{
	Order o_temp;
	string temp;
	ifstream u("order.txt");
	getline(u, temp);
	while (getline(u, temp, ','))
	{
		o_temp.order_id = temp;
		getline(u, o_temp.goods_id, ',');
		u >> o_temp.order_per_price;
		getline(u, temp, ',');
		u >> o_temp.order_goods_num;
		getline(u, temp, ',');
		getline(u, o_temp.order_time, ',');
		getline(u, o_temp.order_seller_id, ',');
		getline(u, o_temp.order_buyer_id);
		allorder.push_back(o_temp);
		ordernum++;
	}
	u.close();

}
void Readusers()
{
	Users u_temp;
	string temp;
	ifstream u("user.txt");
	getline(u, temp);
	while (getline(u, temp, ','))
	{
		u_temp.user_id = temp;
		getline(u, u_temp.user_name, ',');
		getline(u, u_temp.user_password, ',');
		getline(u, u_temp.user_telnum, ',');
		getline(u, u_temp.user_adress, ',');
		u >> u_temp.user_wallet;
		getline(u, temp, ',');
		getline(u, u_temp.user_state);
		usernum++;
		alluser.push_back(u_temp);
	}
	u.close();
}
void Readmoney()
{
	Money m_temp;
	string temp;
	ifstream u("money.txt");
	getline(u, temp);
	while (getline(u, temp, ','))
	{
		m_temp.user_id = temp;
		u >> m_temp.result;
		getline(u, m_temp.time, ',');
		getline(u, m_temp.time, ',');
		allmoney.push_back(m_temp);
		moneynum++;
	}
	u.close();

}
void Readmessage()
{
	message m_temp;
	string temp;
	ifstream u("message.txt");
	getline(u, temp);
	while (getline(u, temp, ','))
	{
		m_temp.mes = temp;
		getline(u, m_temp.sender, ',');
		getline(u, m_temp.recer, ',');
		u >> m_temp.state;
		allmessage.push_back(m_temp);
		messagenum++;

		u.close();
	}

}

string makestring(int user)
{
	vector<string> num;
	string result;
	string tempr;
	vector<string> money;
	vector<pair<string, string>> income;
	vector<pair<string, string>> spand;
	for (int i = 0; i < moneynum; i++)
	{
		int maxnum = 0;
		string temp;
		if (allmoney[i].user_id == alluser[user].user_id)
		{
			stringstream buf;
			buf.precision(1);//覆盖默认精度
			buf.setf(std::ios::fixed);//保留小数位
			buf << allmoney[i].result;
			temp = buf.str();
			money.push_back(temp);
		}
	}
	for (int i = 0; i < ordernum; i++)
	{
		pair<string, string> temp;
		if (allorder[i].order_buyer_id == alluser[user].user_id)
		{
			stringstream buf;
			buf.precision(1);//覆盖默认精度
			buf.setf(std::ios::fixed);//保留小数位
			buf << allorder[i].order_per_price;
			temp.first = to_string(allorder[i].order_goods_num);
			temp.second = buf.str();
			spand.push_back(temp);
			if (num.empty())
			{
				num.push_back(temp.first);
			}
			else
			{
				bool issame = true;
				for (int k = 0; k < num.size(); k++)
				{
					if (num[k] == temp.first)
					{
						issame = false;
						break;
					}
				}
				if (issame)
				{
					num.push_back(temp.first);
				}
			}
		}
	}
	for (int i = 0; i < ordernum; i++)
	{
		pair<string, string> temp;
		if (allorder[i].order_seller_id == alluser[user].user_id)
		{
			stringstream buf;
			buf.precision(1);//覆盖默认精度
			buf.setf(std::ios::fixed);//保留小数位
			buf << allorder[i].order_per_price;
			temp.first = to_string(allorder[i].order_goods_num);
			temp.second = buf.str();
			income.push_back(temp);
			if (num.empty())
			{
				num.push_back(temp.first);
			}
			else
			{
				bool issame = true;
				for (int k = 0; k < num.size(); k++)
				{
					if (num[k] == temp.first)
					{
						issame = false;
						break;
					}
				}
				if (issame)
				{
					num.push_back(temp.first);
				}

			}
		}
	}
	if (money.size() == 0 && spand.size() == 0 && income.size() == 0)
	{
		return "0";
	}
	if (!money.empty())
	{
		for (int i = 0; i < money.size(); i++)
		{
			result += money[i] + "+";
		}
	}
	bool isvalid = false;
	if (spand.size() == 0 && income.size() == 0)
		result[result.length() - 1] = '0';
	for (int i = 0; i < num.size(); i++)
	{
		tempr = num[i] + "*(";
		for (int j = 0; j < income.size(); j++)
		{
			if (income[j].first == num[i])
			{
				tempr += income[j].second + "+";
				isvalid = true;
			}
		}
		tempr[tempr.length() - 1] = '-';
		for (int j = 0; j < spand.size(); j++)
		{
			if (spand[j].first == num[i])
			{
				tempr += spand[j].second + "-";
				isvalid = true;
			}
		}
		if (isvalid)
		{
			tempr.pop_back();
			tempr += ")";
			result += tempr;
		}
	}
	return result;

}
float calculate(string source)
{
	string  num_tmp;
	stack<char> sign;
	vector<member*> suffix;
	for (int idx = 0; idx < source.size(); idx++) {
		char c = source[idx];
		bool negative = false;
		switch (c) {
		case '-':
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
				goto dealNum;
			}
		case '+':
			if (sign.empty())
				sign.push(c);
			else {
				while (!sign.empty() && sign.top() != '(') {
					suffix.emplace_back(new member(sign.top()));
					sign.pop();
				}
				sign.push(c);
			}
			break;
		case '*':
		case '/':
			if (sign.empty() || sign.top() == '+' || sign.top() == '-')
				sign.push(c);
			else {
				while (!sign.empty() && (sign.top() == '*' || sign.top() == '/')) {
					suffix.emplace_back(new member(sign.top()));
					sign.pop();
				}
				sign.push(c);
			}
			break;
		case '(':
			sign.push(c);
			break;
		case ')':
			while (sign.top() != '(') {
				suffix.emplace_back(new member(sign.top()));
				sign.pop();
			}
			sign.pop();
			break;
		default:
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
	while (!sign.empty()) {
		suffix.emplace_back(new member(sign.top()));
		sign.pop();
	}


	for (auto x : suffix) {
		if (x->m_type == SIGN)
			cout << x->sign << ' ';
		else
			cout << x->num << ' ';
	}
	cout << endl;

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
	return nums.top();
}
