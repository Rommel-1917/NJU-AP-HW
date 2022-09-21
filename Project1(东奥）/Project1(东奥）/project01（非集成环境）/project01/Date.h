#include<iostream>
#include<fstream>
#include<ctime>
#include<vector>
#include<sstream>
#include<stack>
using namespace std;
struct Goods
{
	//货物信息

	string good_id = { "M" };
	string good_name;
	float good_price;
	int good_num;
	string good_dis;
	string good_seller_id = { "U" };
	string good_time;
	string good_state;
};
struct Order
{
	//订单信息
	string order_id = { "T" };
	string goods_id = { "M" };
	float order_per_price;
	int order_goods_num;
	string order_time;
	string order_seller_id;
	string order_buyer_id;
};
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
void Readgood();
void Readorder();
string makestring(int user);
float calculate(string source);
void Readusers();
void Readmoney();
void Readmessage();