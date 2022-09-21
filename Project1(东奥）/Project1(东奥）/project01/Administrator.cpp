#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include"Administrator.h"
#include"Users.h"
#include"Date.h"
#include"SQL.h"
using namespace std;
extern int usernum;
extern int goodnum;
extern int ordernum;
extern vector<Users> alluser;
extern vector<Goods> allgood;
extern vector<Order> allorder;
void menu()
{
	cout << "****************" << "  " << "************" << "  " << "************" << "  "  "****************" << "  " << "****************" << "  " << "************" << "  " << "************" << endl;
	cout << "|1.查看所有商品|" << "  " << "|2.搜索商品|" << "  " << "|3.下架商品|" << "  "  "|4.查看所有订单|" << "  " << "|5.查看所有用户|" << "  " << "|6.封禁用户|" << "  " << "|7.退出登录|" << endl;
	cout << "****************" << "  " << "************" << "  " << "************" << "  "  "****************" << "  " << "****************" << "  " << "************" << "  " << "************" << endl;
}
void Admin_Search(string name)
{
	
	bool isfind = false;
	cout << "*********************************************************" << endl;
	cout << "商品id 商品名称   价格    卖家id     库存数量    商品状态" << endl;
	for (int i = 0; i < goodnum; i++)
	{
		if (allgood[i].good_name.find(name) != allgood[i].good_name.npos && allgood[i].good_state == "销售中")
		{
			cout << " ";
			cout << allgood[i].good_id << "  " << allgood[i].good_name << "     ";
			printf("%.1f", allgood[i].good_price);
			for (int k = 5 - to_string(allgood[i].good_num).length(); k >= 0; k--)
				cout << " ";
			cout << allgood[i].good_seller_id << "        " << allgood[i].good_num << "        " << allgood[i].good_state << endl;
			isfind = true;
		}
	}
	if (!isfind)
	{
		cout << "未找到商品";
	}
	cout << endl;

	ofstream c;
	c.open("commands.txt",ios:: app);
	time_t nowtime;
	struct tm* p;;
	time(&nowtime);
	p = localtime(&nowtime);
	c << to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday) + " " + to_string(p->tm_hour) + ":" + to_string(p->tm_min) + ":" + to_string(p->tm_sec) + ":";
	c << "SELECT * FROM commodity WHERE" <<"good_name CONTAINS "<<name <<endl;
	c.close();
	menu();

}
void Admin_all_User()
{
	if (usernum == 0)
	{
		cout << "no user!" << endl;
		return;
	}
	cout << "****************************************************************" << endl;
	cout << "用户ID   用户名          联系方式           地址            余额" << endl;
	for (int i = 0; i < usernum; i++)
	{
		
		cout << alluser[i].user_id << "     " << alluser[i].user_name;
		for (int k = 10 - alluser[i].user_name.length(); k >= 0; k--)
			cout << " ";
		cout << "     " << alluser[i].user_telnum;
		for (int k = 10 - alluser[i].user_telnum.length(); k >= 0; k--)
			cout << " ";
		cout<< alluser[i].user_adress;
	for (int k = 20 - alluser[i].user_adress.length(); k >= 0; k--)
		cout << " ";
	printf("%.1f", alluser[i].user_wallet);	cout << endl;

	}
	cout << "****************************************************************" << endl;
	ofstream c;
	c.open("commands.txt", ios::app);
	time_t nowtime;
	struct tm* p;;
	time(&nowtime);
	p = localtime(&nowtime);
	c << to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday) + " " + to_string(p->tm_hour) + ":" + to_string(p->tm_min) + ":" + to_string(p->tm_sec) + ":";
	c << "SELECT * FROM users "<<endl;
	c.close();
	menu();

}
void Admin_all_Good()
{
	if (goodnum == 0)
	{
		cout << "no good!" << endl;
		return;
	}
	cout << "***************************************************************" << endl;
	cout << "商品ID   商品名称       价格    卖家ID     库存数量    商品状态" << endl;
	for (int i = 0; i < goodnum; i++)
	{

		cout << " " << allgood[i].good_id << "     " << allgood[i].good_name << "  ";
		for (int k = 10 - allgood[i].good_name.length(); k >= 0; k--)
			cout << " ";
		printf("%.1f", allgood[i].good_price);
		for (int k = 10 - to_string(allgood[i].good_price).length(); k >= 0; k--)
			cout << " ";
		cout << "    " << allgood[i].good_seller_id << "         " << allgood[i].good_num;
		for (int k = 9 - to_string(allgood[i].good_num).length(); k >= 0; k--)
			cout << " ";
		cout<< allgood[i].good_state << endl;
		
	}
	cout << endl;
	cout << "***************************************************************" << endl;
	ofstream c;
	c.open("commands.txt", ios::app);
	time_t nowtime;
	struct tm* p;;
	time(&nowtime);
	p = localtime(&nowtime);
	c << to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday) + " " + to_string(p->tm_hour) + ":" + to_string(p->tm_min) + ":" + to_string(p->tm_sec) + ":";
	c << "SELECT * FROM commodity "<< endl;
	c.close();
	menu();

}
void Admin_all_Order()
{
	if (ordernum == 0)
	{
		cout << "no order!" << endl;
		return;
	}
	cout << "******************************************************************" << endl;
	cout << "订单ID   商品ID   单价     数量         交易时间   卖家ID   买家ID" << endl;
	for (int i = 0; i < ordernum; i++)
	{

		cout <<" " << allorder[i].order_id << "     " << allorder[i].goods_id << "    ";
		printf("%.1f", allorder[i].order_per_price);
		for (int k = 10 - to_string(allorder[i].order_per_price).length(); k >= 0; k--)
			cout << "   ";
		printf("%d", allorder[i].order_goods_num);
		for (int k = 10 - to_string(allorder[i].order_goods_num).length(); k >= 0; k--)
			cout << " ";
		cout << allorder[i].order_time << " ";
		for (int k = 10 - allorder[i].order_time.length(); k >= 0; k--)
			cout << " ";
		cout<<" " << allorder[i].order_seller_id << "     " << allorder[i].order_buyer_id << endl;
	}
	cout << endl;
	cout << "******************************************************************" << endl;
	ofstream c;
	c.open("commands.txt", ios::app);
	time_t nowtime;
	struct tm* p;;
	time(&nowtime);
	p = localtime(&nowtime);
	c << to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday) + " " + to_string(p->tm_hour) + ":" + to_string(p->tm_min) + ":" + to_string(p->tm_sec) + ":";
	c << "SELECT * FROM order " << endl;
	c.close();
	menu();

}
void Admin_Deluser(string id)
{
	for (int i = 0; i < usernum; i++)
	{
		if (id == alluser[i].user_id)
		{
			alluser[i].user_state = "封禁";
			cout << "修改成功" << endl;
			save();
			return;
		}
			for (int j = 0; j < goodnum; j++)
			{
				if (allgood[j].good_seller_id == id)
				{
					allgood[j].good_state = 1;
				}
			}
			ofstream c;
			c.open("commands.txt", ios::app);
			time_t nowtime;
			struct tm* p;;
			time(&nowtime);
			p = localtime(&nowtime);
			c << to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday) + " " + to_string(p->tm_hour) + ":" + to_string(p->tm_min) + ":" + to_string(p->tm_sec) + ":";
			c << "UPDATE commodity SET ggod_id = 已下架 WHERE seller_id = " << id << endl;
			time(&nowtime);
			p = localtime(&nowtime);
			c << to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday) + " " + to_string(p->tm_hour) + ":" + to_string(p->tm_min) + ":" + to_string(p->tm_sec) + ":";
			c << "UPDATE user SET user_state = 封禁 WHERE user_id = "<< id << endl;
			c.close();

			save();
			menu();
			return;
		}
	
	cout << "未找到该用户" << endl;
	menu();
}
void Admin_Delgood(string id)
{
	for (int i = 0; i < goodnum; i++)
	{
		if (id == allgood[i].good_id&&allgood[i].good_state!="已下架")
		{
			allgood[i].good_state = "已下架";
			cout << "下架成功" << endl;
			ofstream c;
			c.open("commands.txt", ios::app);
			time_t nowtime;
			struct tm* p;;
			time(&nowtime);
			p = localtime(&nowtime);
			c << to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday) + " " + to_string(p->tm_hour) + ":" + to_string(p->tm_min) + ":" + to_string(p->tm_sec) + ":";
			c << "UPDATE commodity SET good_state = 已下架 WHERE good_id = "<<id << endl;
			c.close();

			return;
		}
	}
	save();
	menu();

}
bool Admin_Login()
{
	const string ad_name = "admin";
	const string ad_password = "123456";
	string name;
	string password;
	while (true)
	{
		cout << "请输入管理员用户名" << endl;
		cin >> name;
		int result = ad_name.compare(name);
		while (true)
			if (result == 0)
			{ 
				cout << "请输入管理员密码" << endl;
				while (true)
				{
					
					cin >> password;
					result = ad_password.compare(password);
					if (result == 0)
					{
						cout << "登陆成功！" << endl;
						return true;
					}
					else
					{
						cout << "密码错误！！" << endl;
						cin.clear();
						cin.ignore(1024,'\n');
					}
				}
			}
			else
			{
				cout << "用户名错误！！" << endl;
				cin >> name;
				result = ad_name.compare(name);
				cin.clear();
				cin.ignore(1024, '\n');
			}
	}

}
void Admin_menu()
{
	menu();
	while (true)
	{
		string sql;
		cout << "请输入操作" << endl;
		int opt = 0;
		string opt2;

		cin >> opt;
		while (cin.fail())
		{
			cout << "请输入一个合法的数字！";
			cin >> opt;
			cin.clear();
			cin.ignore(1024, '\n');

		}			
		string name;
		bool isfind = false;

		switch (opt)
		{
		case 1:
			sql = "SELECT * FROM commodity";
			analyse(sql, -1);
			break;
		case 2:
			cout << "请输入商品名称" << endl;
			cin >> name;
			sql = "SELECT * FROM commodity WHERE good_name CONTAINS " + name;
			analyse(sql, -1);
			 break;
		case 3:
			cout << "请输入商品id" << endl;
			cin >> name;
			cout << "***************************************************" << endl;
			for (int i = 0; i < goodnum; i++)
			{
				if (name == allgood[i].good_id && allgood[i].good_state != "已下架")
				{
					cout << "商品名称：" << allgood[i].good_name << endl;
					cout << "商品ID；" << allgood[i].good_id << endl;
					cout << "上架时间" << allgood[i].good_time << endl;
					cout << "卖家ID：" << allgood[i].good_seller_id << endl;
					cout << "价格：" << allgood[i].good_price << endl;
					cout << "数量：" << allgood[i].good_num << endl;
					isfind = true;
				}
			}
			if (isfind)
			{
				cout << "确认下架此商品吗？" << endl << "请输入(y/n)" << endl;
				cin >> opt2;
				while (opt2 != "y" && opt2 != "n")
				{
					cout << "请输入y/n" << endl;
					cin >> opt2;
				}
				if (opt2 == "y")
				{
					sql = "UPDATE commodity SET good_state = 已下架 WHERE good_id = " + name;
					analyse(sql, -1);
					break;
				}
				else
				{
					cout << "取消成功!" << endl;
					break;
				}
			}
			else
				cout << "未找到该商品！" << endl;
			break;

		case 4:			
			sql = "SELECT * FROM order";
			analyse(sql, -1);
			break;
		case 5:
			sql = "SELECT * FROM user";
			analyse(sql, -1);
			break;
		case 6:
			cout << "请输入用户id" << endl;
			cin >> name;
			cout << "***************************************************" << endl;
			for (int i = 0; i < usernum; i++)
			{
				if (name == alluser[i].user_id && alluser[i].user_state != "封禁")
				{
					cout << "用户名：" << alluser[i].user_name << endl;
					cout << "用户ID；" << alluser[i].user_id << endl;
					isfind = true;
				}
			}
			if (isfind)
			{
				cout << "确认封禁此用户吗？" << endl << "请输入(y/n)" << endl;
				cin >> opt2;
				while (opt2 != "y" && opt2 != "n")
				{
					cout << "请输入y/n" << endl;
					cin >> opt2;
				}
				if (opt2 == "y")
				{
					sql = "UPDATE user SET user_state = 封禁 WHERE user_id = " + name;
					analyse(sql, -1);
					break;
				}
				else
				{
					cout << "取消成功!" << endl;
					break;
				}
			}
			else
				cout << "未找到该用户！" << endl;
			break;

		case 7:return;
		default:
			cout << "输入异常，请重新输入" << endl;
			break;
		}
	}
}

