#include<iostream>
#include"Users.h"
#include"Administrator.h"
#include"Date.h"
#include<vector>

using namespace std;
int usernum = 0, goodnum = 0, ordernum = 0, moneynum = 0,messagenum = 0;
string usertitle = "用户ID,用户名,密码,联系方式,地址,钱包余额,用户状态", goodtitle = "商品ID,名称,价格,数量,描述,卖家ID,上架时间,商品状态", ordertitle = "订单ID,商品ID,交易单价,数量,交易时间,卖家ID,买家ID", moneytitle = "用户ID,金额,充值时间", messagetitle = "内容，发件人，收件人，状态";
vector<Users> alluser;
vector<Goods> allgood;
vector<Order> allorder;
vector<Money> allmoney;
vector<message> allmessage;
void mainmenu()
{
	cout << "************" << "  " << "************" << "  " << "**************" << "  " << "************" << "  " << "************" << endl;
	cout << "|1.用户登录|" << "  " << "|2.用户注册|" << "  " << "|3.管理员登陆|" << "  " << "|4.退出程序|" << "  " << "|5.忘记密码|"<< endl;
	cout << "************" << "  " << "************" << "  " << "**************" << "  " << "************" << "  " << "************" << endl;
}

int main()
{
	Readusers();
	Readgood();
	Readorder();
	Readmoney();
	Readmessage();
	while (true)
	{
		mainmenu();
		int opt;
		cin >> opt;
		while (cin.fail())
		{
			cout << "请输入一个合法的数字！";
			cin >> opt;
			cin.clear();
			cin.ignore(1024,'\n');
			
		}
		switch (opt)
		{
		case 1:User_login(); break;
		case 2:
		{
			Register();
			break;
		}
		case 3:
		{
			if (Admin_Login())
			{
				Admin_menu();
			}
			break;
		}
		case 4:exit(0);break;
		case 5:
			forget(); break;
		default:  
			cout << "输入异常，请重新输入" << endl;
			break;
		}
	}
	return 0;
}