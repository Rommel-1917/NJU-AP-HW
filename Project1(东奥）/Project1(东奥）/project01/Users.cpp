#include<iostream>
#include<fstream>
#include<ctime>
#include<vector>
#include<sstream>
#include<stack>
#include"Users.h"
#include"SQL.h"
#include"Date.h"
using namespace std;

extern int usernum, goodnum, ordernum, moneynum, messagenum;
extern string usertitle, goodtitle, ordertitle, moneytitle, messagetitle;
extern vector<Users> alluser;
extern vector<Goods> allgood;
extern vector<Order> allorder;
extern vector<Money> allmoney;
extern vector<message> allmessage;
void money(int user);
void Register()
{
	string username;
	Users temp;
	cout << "请输入用户名" << endl;
	while (cin >> username)
	{
		for (int i = 0; i < usernum; i++)
		{
			if (alluser[i].user_name == username)
			{
				cout << "用户名重复！" << endl;
				return;
			}
		}
		while (username.find(",") != -1)
		{
			cout << "用户名中请勿包含\",\"" << endl;
			cin >> username;
		}
		while (username.length() > 10)
		{
			cout << "名称过长！";
			cin >> username;
		}
		break;
		
	}
	if (usernum + 1 <= 9)
	{
		temp.user_id = (string)"U00"  + to_string(usernum + 1);
	}
	if(usernum+1>9&&usernum+1<=99)
		temp.user_id = (string)"U0" + to_string(usernum + 1);
	if(usernum+1>99)
		temp.user_id = (string)"U" + to_string(usernum + 1);
	temp.user_name = username;
			cout << "请输入密码" << endl;
			cin >> temp.user_password;
			while (temp.user_password.find(",") != -1 )
			{
				cout << "密码中请勿包含\",\"" << endl;
				cin >> temp.user_password;
			}
			cout << "请输入联系方式" << endl;
			cin >> temp.user_telnum;
			while (temp.user_telnum.find(",") != -1 )
			{
				cout << "联系方式中请勿包含\",\"" << endl;
				cin >> temp.user_telnum;
			}
			cout << "请输入地址" << endl;
			cin >> temp.user_adress;
			while (temp.user_adress.find(",") != -1 )
			{
				cout << "地址中请勿包含\",\"或" << endl;
				cin >> temp.user_adress;
			}

			temp.user_state = "正常";
			alluser.push_back(temp);
			usernum++;
			save();
}
void umenu()
	{
		cout << "************" << "  " << "************" << "  " <<"****************"<<"  "<< "************" << "  " << "************" << "  " << endl;
		cout << "|1.我是买家|" << "  " << "|2.我是卖家|" << "  " <<"|3.个人信息管理|"<<"  "<< "|4.退出登录|" << "  " << "|5.我的消息|" << "  " << endl;
		cout << "************" << "  " << "************" << "  " <<"****************"<<"  "<< "************" << "  " << "************" << "  " << endl;
	}
void bmenu()
{
	cout << "****************" << "  " << "************" << "  "  << "************"  <<" "<<"****************" <<"  " << "****************" << "  " << "**************" << endl;
	cout << "|1.产看所有商品|" << "  " << "|2.搜索商品|" << "  "  << "|3.购买商品|"  <<" "<<"|4.查看商品信息|" <<"  " << "|5.产看所有订单|" << "  " << "|6.返回主菜单|" << endl;
	cout << "****************" << "  " << "************" << "  "  << "************"  <<" "<<"****************" <<"  " << "****************" << "  " << "**************" << endl;
}
void smenu()
{
	cout << "****************" << "  " << "************" << "  " << "************" << " " << "****************" << "  " << "****************" << "  " << "**************" << endl;
	cout << "|1.产看发布商品|" << "  " << "|2.发布商品|" << "  " << "|3.下架商品|" << " " << "|4.修改商品信息|" << "  " << "|5.产看所有订单|" << "  " << "|6.返回主菜单|" << endl;
	cout << "****************" << "  " << "************" << "  " << "************" << " " << "****************" << "  " << "****************" << "  " << "**************" << endl;
}
void chatmenu()
{
	cout << "****************" << "  " << "************" << "************" <<"************"<<endl;
	cout << "|1.产看所有消息|" << "  " << "|2.发送消息|" << "|3.全部已读|" <<"|4.退出聊天|"<< endl;
	cout << "****************" << "  " << "************" << "************" <<"************"<< endl;

}
void chatcase(int user)
{
	chatmenu();
	for (int i = 0; i < messagenum; i++)
	{
		if (allmessage[i].recer == alluser[user].user_id && allmessage[i].state == 1)
		{
			cout << "有新消息！" << endl;
			break;
		}
	}
	while (true)
	{
		cout << "请输入操作" << endl;
		int opt = 0;
		cin >> opt;
		while (cin.fail())
		{
			cout << "请输入一个合法的数字！";
			cin >> opt;
			cin.clear();
			cin.ignore(1024, '\n');

		}
		string name;
		switch (opt)
		{
		case 1:
		{
			bool isfind = false;
			cout << "我发送的消息:" << endl;
			for (int i = 0; i < messagenum; i++)
			{
				if (allmessage[i].sender == alluser[user].user_id)
				{
					isfind = true;
					for (int j = 0; j < usernum; j++)
					{
						if (alluser[j].user_id == allmessage[i].recer)
						{
							name = alluser[j].user_name;
						}
					}
					cout << "我对(" <<allmessage[i].recer << ")"<<name << "说: " << allmessage[i].mes;
					if (allmessage[i].state == 0)
					{
						cout << "(对方已读)" << endl;
						cout << "---------------------------------------------------------------------------------" << endl;

					}
					else
					{
						cout << "(对方未读)" << endl;
						cout << "---------------------------------------------------------------------------------" << endl;
					}
				}
			}
			cout << endl;
			cout << "我收到的消息:" << endl;
			for (int i = 0; i < messagenum; i++)
			{
				if (allmessage[i].recer == alluser[user].user_id)
				{
					isfind = true;
					for (int j = 0; j < usernum; j++)
					{
						if (alluser[j].user_id == allmessage[i].sender)
						{
							name = alluser[j].user_name;
						}
					}
					if (allmessage[i].state == 1)
						cout << "（未读）";
					cout <<"("<<allmessage[i].sender <<")"<< name << "对我说: " << allmessage[i].mes << endl;
					cout <<"---------------------------------------------------------------------------------"<< endl;
				}
			}
			if (!isfind)
			{
				cout << "没有消息" << endl;
			}
			break;
		}
		case 2:
		{
			string mes;
			string name;
			message temp;
			bool isfind = false;
			cout << "请输入目标ID" << endl;
			cin >> name;
			if (name == alluser[user].user_id)
			{
				cout << "不能给自己发消息！" << endl;
				break;
			}
			else
			{
				for (int i = 0; i < usernum; i++)
				{
					if (alluser[i].user_id == name)
					{
						isfind = true;
						cout << "请输入内容：" << endl;
						cin >> mes;
						temp.mes = mes;
						temp.recer = name;
						temp.sender = alluser[user].user_id;
						allmessage.push_back(temp);
						messagenum++;
						cout << "发送成功" << endl;
						save();
					}
				}
				if (!isfind)
				{
					cout << "未找到该用户!" << endl;
					break;
				}
				break;
			}
		}
		case 3:
		{
			bool isnew = false;
			for (int i = 0; i < messagenum; i++)
			{
				if (allmessage[i].recer == alluser[user].user_id)
				{
					if (allmessage[i].state == 1)
					{
						isnew = true;
						cout << "(" << allmessage[i].sender << ")" << name << "对我说: " << allmessage[i].mes << endl;
						string op;
						cout << "确认已读此消息吗？(请输入y/n)" << endl;
						cin >> op;
						while (op != "y" && op != "n")
						{
							cout << "请输入y/n" << endl;
							cin >> op;
						}
						if (op == "y")
						{
							allmessage[i].state = 0;
							cout << "已读成功！" << endl;
							save();
							break;
						}
					}
				}
			}
			if (!isnew)
			{
				cout << "没有新消息" << endl;
				break;
			}
		}
		case 4:
		{
			return;
		}
		default:
		{
			cout << "请输入一个合法数字" << endl;
			break;
		}
		}
	}

}
void makeorder(string orderid,string goodid,float price,int num,string ordertime,string buyerid,string sellerid)
{
	Order temp;
	int user;
	int seller;
	int good;
	for (int i = 0; i < usernum; i++)
	{
		if (alluser[i].user_id == buyerid)
		{
			user = i;
			break;
		}
	}
	for (int i = 0; i < usernum; i++)
	{
		if (alluser[i].user_id == sellerid)
		{
			seller = i;
			break;
		}
	}
	for (int i = 0; i < goodnum; i++)
	{
		if (allgood[i].good_id == goodid)
		{
			good = i;
			break;
		}
	}
	alluser[user].user_wallet -= allgood[good].good_price * num;
	alluser[seller].user_wallet += allgood[good].good_price * num;
	allgood[good].good_num -= num;
	if (allgood[good].good_num == 0)
	{
		allgood[good].good_state = "已售罄";
	}
	temp.order_id = orderid;
	temp.goods_id=allgood[good].good_id;
	temp.order_buyer_id= alluser[user].user_id;
	temp.order_goods_num = num;
	temp.order_per_price = price;
	temp.order_seller_id = alluser[seller].user_id;
	time_t nowtime;
	struct tm* p;;
	time(&nowtime);
	p = localtime(&nowtime);
	temp.order_time = ordertime;
	ordernum++;
	allorder.push_back(temp);
	ofstream c;
	c.open("commands.txt", ios::app);
	time(&nowtime);
	p = localtime(&nowtime);
	c.setf(ios::fixed);
	c.setf(ios::showpoint);
	c.precision(1);

	c << to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday) + " " + to_string(p->tm_hour) + ":" + to_string(p->tm_min) + ":" + to_string(p->tm_sec) + ":";
	c << "INSERT INTO commodity VALUES (" << temp.order_id << " ," << temp.goods_id << " ," << temp.order_per_price << " ," << temp.order_time <<" ,"<<temp.order_seller_id<<" ,"<<temp.order_buyer_id<< " )" << endl;
	c << to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday) + " " + to_string(p->tm_hour) + ":" + to_string(p->tm_min) + ":" + to_string(p->tm_sec) + ":";
	c << "UPDATE commodity SET good_num = "<<allgood[good].good_num<<"WHERE good_id = "<<allgood[good].good_id<< endl;
	if (allgood[good].good_num == 0)
	{
		c << "UPDATE commodity SET good_state = 已售罄 WHERE good_id = " << allgood[good].good_id << endl;
	}
	c.close();

	save();
}
void buyer_allgood()
{
	int yourgood = 0;
	cout << "**********************************************************" << endl;
	cout << "商品ID   商品名称       价格         上架时间       卖家ID" << endl;
	for (int i = 0; i < goodnum; i++)
	{
		if (allgood[i].good_state == "销售中")
		{
			cout << " " << allgood[i].good_id << "     " << allgood[i].good_name << "  ";
			for (int k = 10 - allgood[i].good_name.length(); k >= 0; k--)
				cout << " ";
			printf("%.1f", allgood[i].good_price);
			for (int k = 10 - to_string(allgood[i].good_price).length(); k >= 0; k--)
				cout << " ";
			cout << "        ";
			cout << allgood[i].good_time;
			for (int k = 10 - allgood[i].good_time.length(); k >= 0; k--)
				cout << " ";
			cout << "    " << allgood[i].good_seller_id << endl;
			yourgood++;
		}

	}
	cout << "*******************************************************" << endl;
	ofstream c;
	c.open("commands.txt", ios::app);
	time_t nowtime;
	struct tm* p;;
	time(&nowtime);
	p = localtime(&nowtime);
	c << to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday) + " " + to_string(p->tm_hour) + ":" + to_string(p->tm_min) + ":" + to_string(p->tm_sec) + ":";
	c << "SELECT * FROM commodity"<< endl;
	c.close();

	if (yourgood == 0)
	{
		cout << "No good!" << endl;
	}
	bmenu();
}
void seller_allgood(string id)
{
	int yourgood = 0;
	cout << "*******************************************************************" << endl;
	cout << "商品ID   商品名称       价格     库存        上架时间      商品状态" << endl;
	for (int i = 0; i < goodnum; i++)
	{
		if (allgood[i].good_seller_id== id)
		{
			cout << " " << allgood[i].good_id << "     " << allgood[i].good_name << "  ";
			for (int k = 10 - allgood[i].good_name.length(); k >= 0; k--)
				cout << " ";

			printf("%.1f", allgood[i].good_price);
			for (int k = 10 - to_string(allgood[i].good_price).length(); k >= 0; k--)
				cout << " ";
				cout << "      ";
			cout << allgood[i].good_num;
			for (int k = 10 - to_string(allgood[i].good_num).length(); k >= 0; k--)
				cout << " ";
			cout << allgood[i].good_time;
			for (int k = 10 - allgood[i].good_time.length(); k >= 0; k--)
				cout << " ";
			cout << "    " << allgood[i].good_state << endl;
			yourgood++;
		}

	}
	cout << "*******************************************************************" << endl;
	if (yourgood == 0)
	{
		cout << "No good!" << endl;
	}
	ofstream c;
	c.open("commands.txt", ios::app);
	time_t nowtime;
	struct tm* p;;
	time(&nowtime);
	p = localtime(&nowtime);
	c << to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday) + " " + to_string(p->tm_hour) + ":" + to_string(p->tm_min) + ":" + to_string(p->tm_sec) + ":";
	c << "SELECT * FROM commodity"<<endl;
	c.close();

	smenu();
}
void buyer_search(string name)
{
	bool isfind = false;
	cout << "*************************************************************" << endl;
	cout << "商品id 商品名称       价格    卖家id     库存数量    商品状态" << endl;
	for (int i = 0; i < goodnum; i++)
	{
		if (allgood[i].good_name.find(name) != allgood[i].good_name.npos&&allgood[i].good_state=="销售中")
		{
			cout << " ";
			cout << allgood[i].good_id << "  " << allgood[i].good_name << "     ";
			printf("%.1f", allgood[i].good_price);
			for (int k = 5 - to_string(allgood[i].good_num).length(); k >= 0; k--)
				cout << " ";
			cout << allgood[i].good_seller_id << "        " << allgood[i].good_num << "        " << allgood[i].good_state;
			isfind = true;
		}
	}
	if (!isfind)
	{
		cout << "未找到商品";
	}
	cout << endl;
	ofstream c;
	c.open("commands.txt", ios::app);
	time_t nowtime;
	struct tm* p;;
	time(&nowtime);
	p = localtime(&nowtime);
	c << to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday) + " " + to_string(p->tm_hour) + ":" + to_string(p->tm_min) + ":" + to_string(p->tm_sec) + ":";
	c << "SELECT * FROM commodity WHERE" << "good_name CONTAINS " << name << endl;
	c.close();

	bmenu();

}
void buyer_allorder(string id)
{
	int yourorder = 0;
	cout << "*********************************************************" << endl;
	cout << "订单ID   商品ID   单价     数量         交易时间   卖家ID" << endl;
	for (int i = 0; i < ordernum; i++)
	{
		if (allorder[i].order_buyer_id == id)
		{
			cout << " " << allorder[i].order_id << "     " << allorder[i].goods_id << "    ";
			printf("%.1f", allorder[i].order_per_price);
			for (int k = 10 - to_string(allorder[i].order_per_price).length(); k >= 0; k--)
				cout << "   ";
			printf("%d", allorder[i].order_goods_num);
			for (int k = 10 - to_string(allorder[i].order_goods_num).length(); k >= 0; k--)
				cout << " ";
			cout << allorder[i].order_time << " ";
			for (int k = 10 - allorder[i].order_time.length(); k >= 0; k--)
				cout << " ";
			cout << allorder[i].order_seller_id;
			cout<< endl;
			
			yourorder++;
		}
	}
	cout << endl;
	cout << "*********************************************************" << endl;
	if (yourorder == 0)
	{
		cout << "NO order!" << endl;
	}
	ofstream c;
	c.open("commands.txt", ios::app);
	time_t nowtime;
	struct tm* p;;
	time(&nowtime);
	p = localtime(&nowtime);
	c << to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday) + " " + to_string(p->tm_hour) + ":" + to_string(p->tm_min) + ":" + to_string(p->tm_sec) + ":";
	c << "SELECT * FROM order"<< endl;
	c.close();

	bmenu();
}
void seller_allorder(string id)
{
	int yourorder = 0;
	cout << "*********************************************************" << endl;
	cout << "订单ID   商品ID   单价     数量         交易时间   买家ID" << endl;
	for (int i = 0; i < ordernum; i++)
	{
		if (allorder[i].order_seller_id == id)
		{
			cout << " " << allorder[i].order_id << "     " << allorder[i].goods_id << "    ";
			printf("%.1f", allorder[i].order_per_price);
			for (int k = 10 - to_string(allorder[i].order_per_price).length(); k >= 0; k--)
				cout << "   ";
			printf("%d", allorder[i].order_goods_num);
			for (int k = 10 - to_string(allorder[i].order_goods_num).length(); k >= 0; k--)
				cout << " ";
			cout << allorder[i].order_time << " ";
			for (int k = 10 - allorder[i].order_time.length(); k >= 0; k--)
				cout << " ";
	
			cout << allorder[i].order_buyer_id;
			cout << endl;
			yourorder++;
		}
	}
	cout << endl;
	cout << "*********************************************************" << endl;
	ofstream c;
	c.open("commands.txt", ios::app);
	time_t nowtime;
	struct tm* p;;
	time(&nowtime);
	p = localtime(&nowtime);
	c << to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday) + " " + to_string(p->tm_hour) + ":" + to_string(p->tm_min) + ":" + to_string(p->tm_sec) + ":";
	c << "SELECT * FROM order"<<endl;
	c.close();

	if (yourorder == 0)
	{
		cout << "NO order!" << endl;
	}
	smenu();
}
void seller_sellgood(string name,float price,int num,string dis,int user)
{
	Goods temp;
	temp.good_name=name;
	temp.good_price = price;
	temp.good_num = num;
	temp.good_dis = dis;
	if (goodnum + 1 <= 9)
	{
		temp.good_id = (string)"M00" + to_string(goodnum + 1);
	}
	if (goodnum + 1 > 9 && usernum + 1 <= 99)
	{
		temp.good_id = (string)"M0" + to_string(goodnum + 1);
	}
	if (goodnum + 1 > 99)
	{
		temp.good_id = (string)"M" + to_string(goodnum + 1);
	}
	cout << "发布成功！" << endl;
	time_t nowtime;
	struct tm* p;;
	time(&nowtime);
	p = localtime(&nowtime);
	temp.good_time = to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday);
	temp.good_state = "销售中";
	goodnum++;	
	temp.good_seller_id = alluser[user].user_id;
	allgood.push_back(temp);
	save();
	ofstream c;
	c.open("commands.txt", ios::app);
	time(&nowtime);
	p = localtime(&nowtime);
	c.setf(ios::fixed);
	c.setf(ios::showpoint);
	c.precision(1);

	c << to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday) + " " + to_string(p->tm_hour) + ":" + to_string(p->tm_min) + ":" + to_string(p->tm_sec) + ":";
	c << "INSERT INTO commodity VALUES ("<<temp.good_name<<" ,"<<temp.good_price<<" ,"<<temp.good_num<<" ,"<<temp.good_dis<<" )" << endl;
	c.close();

}
void seller_delgood(string id)
{
	for (int i = 0; i < goodnum; i++)
	{
		if (allgood[i].good_id == id)
		{
			allgood[i].good_state = "已下架";
		}
	}
	save();
	ofstream c;
	c.open("commands.txt", ios::app);
	time_t nowtime;
	struct tm* p;;
	time(&nowtime);
	p = localtime(&nowtime);
	c << to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday) + " " + to_string(p->tm_hour) + ":" + to_string(p->tm_min) + ":" + to_string(p->tm_sec) + ":";
	c << "UPDATE commodity SET good_state = 已下架 WHERE good_id = " << id << endl;
	c.close();
}
void buyer_gooddetail(string ID)
{
	bool isfind = false;
	for (int i = 0; i < goodnum; i++)
	{
		if (allgood[i].good_id== ID && allgood[i].good_state == "销售中")
		{
			cout << "商品ID:";
			cout << allgood[i].good_id << endl;
			cout << "商品名称：";
			cout << allgood[i].good_name << endl;
			cout << "价格；";
			printf("%.1f\n", allgood[i].good_price);
			cout << "上架时间：";
			cout << allgood[i].good_time << endl;
			cout << "商品描述:";
			cout << allgood[i].good_dis << endl;
			cout << "卖家ID:";
			cout << allgood[i].good_seller_id << endl;
			isfind = true;
		}
	}
	if (!isfind)
	{
		cout << "未找到商品";
	}
	ofstream c;
	c.open("commands.txt", ios::app);
	time_t nowtime;
	struct tm* p;;
	time(&nowtime);
	p = localtime(&nowtime);
	c << to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday) + " " + to_string(p->tm_hour) + ":" + to_string(p->tm_min) + ":" + to_string(p->tm_sec) + ":";
	c << "SELECT * FROM commodity WHERE" << "good_id CONTAINS " << ID << "and good_state = 销售中" << endl;
	c.close();

	cout << endl;
	bmenu();

}
void sellerer_changegoodinfo(string id,float price)
{
	int good;
	for (int i = 0; i < goodnum; i++)
	{
		if (allgood[i].good_id == id)
		{
			good = i;
			break;
		}
	}
	allgood[good].good_price = price;
	ofstream c;
	c.open("commands.txt", ios::app);
	time_t nowtime;
	struct tm* p;;
	time(&nowtime);
	c.setf(ios::fixed);
	c.setf(ios::showpoint);
	c.precision(1);
	p = localtime(&nowtime);
	c << to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday) + " " + to_string(p->tm_hour) + ":" + to_string(p->tm_min) + ":" + to_string(p->tm_sec) + ":";
	c << "UPDATE commodity SET good_price = "<<price<< " WHERE good_id = " << id << endl;
	c.close();
	save();
	return;
					
}
void sellerer_changegoodinfo(string id, string dis)
{
	int good;
	for (int i = 0; i < goodnum; i++)
	{
		if (allgood[i].good_id == id)
		{
			good = i;
			break;
		}
	}

		allgood[good].good_dis = dis;
		save();
		ofstream c;
		c.open("commands.txt", ios::app);
		time_t nowtime;
		struct tm* p;;
		time(&nowtime);
		c.setf(ios::fixed);
		c.setf(ios::showpoint);
		c.precision(1);

		p = localtime(&nowtime);
		c << to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday) + " " + to_string(p->tm_hour) + ":" + to_string(p->tm_min) + ":" + to_string(p->tm_sec) + ":";
		c << "UPDATE commodity SET good_dis = " << dis << "WHERE good_id = " << id << endl;
		c.close();

		return;
}
void buyermenu(int user)
{
	bmenu();
	while (true)
	{
		cout << "请输入操作" << endl;
		int opt = 0;
		cin >> opt;
		while (cin.fail())
		{
			cout << "请输入一个合法的数字！";
			cin >> opt;
			cin.clear();
			cin.ignore(1024, '\n');

		}
		string sql;
		string id;
		std::ostringstream out;

		switch (opt)
		{
		case 1:
		{
			sql = "SELECT * FROM commodity WHERE good_state = 销售中";
			analyse(sql, user);
			break;
		}
		case 2:
		{
			string name;

			bool isfind = false;
			cout << "请输入商品名称" << endl;
			cin >> name;

			sql = "SELECT * FROM commodity WHERE good_name CONTAINS " + name + " and good_state = 销售中";
			analyse(sql, user);
			break;
		}
		case 3:
		{
			int good;
			string sellerID;
			int seller;
			int num;
			float price = 0;
			bool isfind = false;
			string ID;
			string orderid;
			cout << "请输入商品ID" << endl;
			cin >> ID;
			cout << "*********************************************************" << endl;
			cout << "商品id 商品名称   价格    卖家id     库存数量    商品状态" << endl;
			for (int i = 0; i < goodnum; i++)
			{
				if (allgood[i].good_id == ID && allgood[i].good_state == "销售中")
				{
					cout << " ";
					cout << allgood[i].good_id << "  " << allgood[i].good_name << "     ";
					printf("%.1f", allgood[i].good_price);
					for (int k = 13 - to_string(allgood[i].good_price).length(); k >= 0; k--)
						cout << " ";
					cout << allgood[i].good_seller_id << "        " << allgood[i].good_num << "        " << allgood[i].good_state;
					price = allgood[i].good_price;
					good = i;
					for (int j = 0; j < usernum; j++)
					{
						if (alluser[j].user_id == allgood[i].good_seller_id)
							seller = j;
					}
					isfind = true;
				}
			}
			if (!isfind)
			{
				cout << "未找到商品"<<endl;
				break;
			}
			cout << endl;
			
			while (true)
			{
				cout << "请输入购买数量" << endl;
				cin >> num;
				while (cin.fail())
				{
					cout << "请输入一个合法的数字！" << endl;
					cin >> num;
					cin.clear();
					cin.ignore(1024, '\n');
				}
				if (num <= 0 || num > allgood[good].good_num)
				{
					cout << "请输入一个合法的数字！" << endl;
					cin >> num;
				}
				if (num > 0 && alluser[user].user_wallet - allgood[good].good_price * num >= 0 && num <= allgood[good].good_num)
				{
					if (ordernum + 1 <= 9)
					{
						orderid = (string)"T00" + to_string(ordernum + 1);
					}
					if (ordernum + 1 > 9 && usernum + 1 <= 99)
					{
						orderid = (string)"T0" + to_string(ordernum + 1);
					}
					if (ordernum + 1 > 99)
					{
						orderid = (string)"T" + to_string(ordernum + 1);
					}
					time_t nowtime;
					struct tm* p;;
					time(&nowtime);
					p = localtime(&nowtime);
					string ordertime = to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday);
					out.precision(1);
					out << std::fixed << price;
					sql = "INSERT INTO order VALUES(" + orderid + "," + ID + "," + out.str() + "," + to_string(num) + "," + ordertime + "," + alluser[user].user_id + "," + allgood[good].good_seller_id + ")";
					analyse(sql, user);
					alluser[user].user_wallet -= allgood[good].good_price * num;
					cout << "购买成功！" << endl;
					break;
					sql = "UPDATE commodity SET good_num = " + to_string(allgood[good].good_num - num) + " WHERE good_id = " + allgood[good].good_id;
					analyse(sql, user);
					if (allgood[good].good_num - num == 0)
					{
						sql = "UPDATE commodity SET good_state = 已下架 WHERE good_id = " + id;
						analyse(sql, user);
					}

				}
				if (alluser[user].user_wallet - allgood[good].good_price * num < 0)
				{
					cout << "余额不足请充值" << endl;
					money(user);
					break;;
				}
			}
			break;
		}
		case 4:
		{
			string ID;
			cout << "请输入商品ID" << endl;
			cin >> ID;
			sql = "SELECT * FROM commodity WHERE good_id CONTAINS " + ID;
			analyse(sql, user);
			break;
		}
		case 5:
		{
			sql = "SELECT * FROM order WHERE buyer_id = " + alluser[user].user_id;
			analyse(sql, user);
			break; 
		}
		case 6:
		{
			return;
		}
		default:
		{
		cout << "输入异常，请重新输入" << endl;
		break;
		}
		}
	}
}
void sellermenu(int user)
{
	smenu();
	while (true)
	{
		cout << "请输入操作" << endl;
		int opt = 0;
		cin >> opt;
		while (cin.fail())
		{
			cout << "请输入一个合法的数字！";
			cin >> opt;
			cin.clear();
			cin.ignore(1024, '\n');

		}			
		Goods temp;
		string sql;
		string id;
		int good;
		std::ostringstream out;

		switch (opt)
		{
		case 1:
		{
			sql = "SELECT * FROM commodity WHERE seller_id = " + alluser[user].user_id;
		analyse(sql, user);
		break;
		}
		case 2:
		{
			cout << "请输入商品名称:" << endl;
			cin >> temp.good_name;
			while (temp.good_name.length() > 21)
			{
				cout << "名称过长，请重新输入" << endl;
				cin >> temp.good_name;
			}
			cout << "请输入商品价格:" << endl;
			cin >> temp.good_price;
			while (cin.fail() || temp.good_price <= 0)
			{
				cout << "请输入一个合法的数字！";
				cin >> temp.good_price;
				cin.clear();
				cin.ignore(1024, '\n');
			}
			cout << "请输入商品数量:" << endl;
			cin >> temp.good_num;
			while (cin.fail() || temp.good_num <= 0)
			{
				cout << "请输入一个合法的数字！";
				cin >> temp.good_num;
				cin.clear();
				cin.ignore(1024, '\n');
			}
			cout << "请输入商品描述:" << endl;
			cin >> temp.good_dis;
			while (temp.good_dis.length() > 100)
			{
				cout << "描述过长，请重新输入" << endl;
				cin >> temp.good_dis;
			}
			out.precision(1);
			out << std::fixed << temp.good_price;
			sql = "INSERT INTO commodity VALUES (" + temp.good_name + " ," + out.str() + " ," + to_string(temp.good_num) + " ," + temp.good_dis + " )";
			analyse(sql, user);
			break;
		}
		case 3:
		{
			bool isfind = false;
			cout << "请输入商品ID" << endl;
			cin >> id;

			for (int i = 0; i < goodnum; i++)
			{
				if (id == allgood[i].good_id)
				{
					if (allgood[i].good_seller_id != alluser[user].user_id)
					{
						cout << "这不是你的商品！！！" << endl;
						return;
					}
					if (allgood[i].good_state == "已下架")
					{
						cout << "该商品已下架！！！" << endl;
						return;
					}
					isfind = true;
					cout << "确认下架该商品吗？" << endl;
					cout << "商品ID:";
					cout << allgood[i].good_id << endl;
					cout << "商品名称:";
					cout << allgood[i].good_name << endl;
					cout << "价格:";
					printf("%.1f\n", allgood[i].good_price);
					cout << "上架时间:";
					cout << allgood[i].good_time << endl;
					cout << "库存数量:";
					cout << allgood[i].good_num << endl;
					cout << "卖家ID:";
					cout << allgood[i].good_seller_id << endl;
					break;
				}
			}
			if (!isfind)
			{
				cout << "未找到该商品！" << endl;
				break;
			}
			cout << "请输入选择（y/n）" << endl;
			string op;
			cin >> op;
			while (op != "y" && op != "n")
			{
				cout << "请输入y/n" << endl;
				cin >> op;
			}
			if (op == "y")
			{
				sql = "UPDATE commodity SET good_state = 已下架 WHERE good_id = " + id;
				analyse(sql, user);
				cout << "下架成功！" << endl;
				break;
			}
			if (op == "n")
			{
				cout << "取消下架成功" << endl;
				break;
			}
		}
		case 4:
		{
			bool isfind = false;
			cout << "请输入要修改商品的ID" << endl;
			cin >> id;
			for (int i = 0; i < goodnum; i++)
			{
				if (allgood[i].good_id == id && allgood[i].good_state == "销售中")
				{
					good = i;
					if (alluser[user].user_id != allgood[i].good_seller_id)
					{
						cout << "这不是你发布的商品" << endl;
						return;
					}
					isfind = true;
					cout << "请输入要修改的属性(1.价格2.描述)" << endl;
					opt = 0;
					cin >> opt;
					while (cin.fail())
					{
						cout << "请输入一个合法的数字！";
						cin >> opt;
						cin.clear();
						cin.ignore(1024, '\n');
					}
					switch (opt)
					{
					case 1:
					{
						float price;
						cout << "请输入要修改的价格" << endl;
						cin >> price;
						while (cin.fail())
						{
							cout << "请输入一个合法的数字！";
							cin >> opt;
							cin.clear();
							cin.ignore(1024, '\n');
						}
						while (price <= 0)
						{
							cout << "请输入一个合法的数字！";
							cin >> price;
						}
						cout << "*****************************" << endl;
						cout << "请确认商品信息无误" << endl;
						cout << "商品ID:" << allgood[good].good_id << endl;
						cout << "商品名称:" << allgood[good].good_name << endl;
						printf("商品价格:%.1f\n", allgood[good].good_price);
						cout << "商品描述:" << allgood[good].good_dis << endl;
						cout << "*****************************" << endl;
						cout << "请输入选择（y/n）" << endl;
						string opt2;
						cin >> opt2;
						while (opt2 != "y" && opt2 != "n")
						{
							cout << "请输入y/n" << endl;
							cin >> opt2;
						}
						if (opt2 == "y")
						{
							out << std::fixed << price;
							sql = "UPDATE commodity SET good_price = " + out.str() + " WHERE good_id = " + id;
							analyse(sql, user);
							cout << "修改成功！" << endl;
							break;
						}
						if (opt2 == "n")
						{
							cout << "取消修改成功" << endl;
							break;
						}
					}
					case 2:
					{
						string dis;
						cout << "请输入要修改的描述" << endl;
						cin >> dis;
						while (dis.length() > 100)
						{
							cout << "名称过长！";
							cin >> dis;
						}
						cout << "*****************************" << endl;
						cout << "请确认商品信息无误" << endl;
						cout << "商品ID:   " << allgood[good].good_id << endl;
						cout << "商品名称:   " << allgood[good].good_name << endl;
						printf("商品价格:  %.1f\n", allgood[good].good_price);
						cout << "商品描述:" << allgood[good].good_dis << endl;
						cout << "*****************************" << endl;
						cout << "请输入选择（y/n）" << endl;
						string opt2;
						cin >> opt2;
						while (opt2 != "y" && opt2 != "n")
						{
							cout << "请输入y/n" << endl;
							cin >> opt2;
						}
						if (opt2 == "y")
						{
							sql = "UPDATE commodity SET good_dis = " + dis + " WHERE good_id = " + id;
							analyse(sql, user);
							cout << "修改成功！" << endl;

							break;
						}
						if (opt2 == "n")
						{
							cout << "取消修改成功" << endl;
							break;
						}
					}
					default:
						cout << "输入异常，请重新输入" << endl;
						break;
					}
				}

			}
			if (!isfind)
			{
				cout << "未找到该商品！" << endl;
			}
			break;
		}
		case 5:
		{
			sql = "SELECT * FROM order WHERE seller_id = " + alluser[user].user_id;
			analyse(sql, user);
			break;
		}
		case 6:return;
		default:
			cout << "输入异常，请重新输入" << endl;
			break;
		}
	}
}
void User_login()
{
	string name;
	string password;
	while (true)
	{
		cout << "请输入用户名" << endl;
		cin >> name;
		int time = 0;
		for (int i = 0; i < usernum; i++)
		{
			if (alluser[i].user_name == name && alluser[i].user_state == "正常")
			{

				while (true)
				{
					cout << "请输入密码" << endl;
					cin >> password;
					if (password == alluser[i].user_password)
					{
						cout << "登陆成功！" << endl;
						Usermenu(i);
						return;
					}
					else
					{
						if (i == 4)
						{
							return;
						}
						cout << "密码错误！！" << endl;
						cout << "您还可以尝试" << 3 - i << "次" << endl;
						i++;
						cin.clear();
						cin.ignore(1024, '\n');
					}
				}
			}
		}
			cout << "用户名错误！！" << endl;
			return;

	}
}
void userinfo_menu()
{
	cout << "************" << "  " << "************" << "  " << "********" << "  " << "************" << "  " << endl;
	cout << "|1.产看信息|" << "  " << "|2.修改信息|" << "  " << "|3.充值|" << "  " << "|4.退出登录|" << "  " << endl;
	cout << "************" << "  " << "************" << "  " << "********" << "  " << "************" << "  " << endl;
}
void infomenu()
{

	cout << "************" << "  " << "************" << "  " << "**************" << "  " << "********" << "  " << endl;
	cout << "|1.查看信息|" << "  " << "|2.修改信息|" << "  " << "|3.返回主界面|" << "  " << "|4.充值|" << "  " << endl;
	cout << "************" << "  " << "************" << "  " << "**************" << "  " << "********" << "  " << endl;
}
void checkinfo(int user)
{
	cout << "**********************" << endl;
	cout << "用户名:" << alluser[user].user_name << endl;
	cout << "联系方式:" << alluser[user].user_telnum << endl;
	cout << "地址:" << alluser[user].user_adress << endl;
	printf("钱包余额:%.1f\n", alluser[user].user_wallet);
	cout << "**********************" << endl;
	return;
}
void changeinfo(int user)
{
	string name;
	string tel;
	string adress;
	cout << "*************************************************************" << endl;
			cout << "请输入要修改的属性(1.用户名2.联系电话3.地址)" << endl;
			int opt = 0;
			cin >> opt;
			while (cin.fail())
			{
				cout << "请输入一个合法的数字！";
				cin >> opt;
				cin.clear();
				cin.ignore(1024, '\n');
			}
			switch (opt)
			{
			case 1:
			{
				cout << "请输入要修改的用户名" << endl;
				cin >> name;
				
				while (name.length() > 10)
				{
					cout << "名称过长！";
					cin >> name;
				}
				cout << "*****************************" << endl;
				cout << "请确认个人信息无误" << endl;
				cout << "用户名:" << name << endl;
				cout << "*****************************" << endl;
				cout << "请输入选择（y/n）" << endl;
				string opt2;
				cin >> opt2;
				
				if (opt2 == "y")
				{
					alluser[user].user_name = name;
					cout << "修改成功" << endl;
					save();
					return;
				}
				if (opt2 == "n")
				{
					cout << "取消修改成功" << endl;
					return;
				}
			}
			case 2:
			{
				cout << "请输入要修改的联系方式" << endl;
				cin >> tel;
				cout << "*****************************" << endl;
				cout << "请确认个人信息无误" << endl;
				cout << "联系方式" << tel << endl;
				cout << "*****************************" << endl;
				cout << "请输入选择（y/n）" << endl;
				string opt2;
				cin >> opt2;
				if (opt2 == "y")
				{
					alluser[user].user_telnum = tel;
					cout << "修改成功" << endl;
					save();
					return;
				}
				if (opt2 == "n")
				{
					cout << "取消修改成功" << endl;
					return;
				}
			}
			case 3:
			{
				cout << "请输入要修改的地址" << endl;
				cin >> adress;
				cout << "*****************************" << endl;
				cout << "请确认地址无误" << endl;
				cout << "地址" << adress << endl;
				cout << "*****************************" << endl;
				cout << "请输入选择（y/n）" << endl;
				string opt2;
				cin >> opt2;
				if (opt2 == "y")
				{
					alluser[user].user_adress = adress;
					cout << "修改成功" << endl;
					save();
					return;
				}
				if (opt2 == "n")
				{
					cout << "取消修改成功" << endl;
					return;
				}
			}
			default:
				cout << "输入异常，请重新输入" << endl;
				break;
			}
		
	
}
void money(int user)
{
	cout << "***************************" << endl;
	cout << "          消费记录         " << endl;
	cout << "------------卖出商品------------" << endl;
	int yoursell = 0;
	cout << "*********************************************************" << endl;
	cout << "订单ID   商品ID   单价     数量         交易时间   买家ID" << endl;
	for (int i = 0; i < ordernum; i++)
	{
		if (allorder[i].order_seller_id == alluser[user].user_id)
		{
			cout << " " << allorder[i].order_id << "     " << allorder[i].goods_id << "    ";
			printf("%.1f", allorder[i].order_per_price);
			for (int k = 10 - to_string(allorder[i].order_per_price).length(); k >= 0; k--)
				cout << "   ";
			printf("%d", allorder[i].order_goods_num);
			for (int k = 10 - to_string(allorder[i].order_goods_num).length(); k >= 0; k--)
				cout << " ";
			cout << allorder[i].order_time << " ";
			for (int k = 10 - allorder[i].order_time.length(); k >= 0; k--)
				cout << " ";

			cout << allorder[i].order_buyer_id;
			cout << endl;
			yoursell++;
		}
	}	cout << "*************************************************************" << endl;
	if (yoursell == 0)
	{
		cout << "No sell!" << endl;
	}
	cout << "------------购买商品------------" << endl;

			int yourorder = 0;
			cout << "*********************************************************" << endl;
			cout << "订单ID   商品ID   单价     数量         交易时间   卖家ID" << endl;
			for (int i = 0; i < ordernum; i++)
			{
				if (allorder[i].order_buyer_id == alluser[user].user_id)
				{
					cout << " " << allorder[i].order_id << "     " << allorder[i].goods_id << "    ";
					printf("%.1f", allorder[i].order_per_price);
					for (int k = 10 - to_string(allorder[i].order_per_price).length(); k >= 0; k--)
						cout << "   ";
					printf("%d", allorder[i].order_goods_num);
					for (int k = 10 - to_string(allorder[i].order_goods_num).length(); k >= 0; k--)
						cout << " ";
					cout << allorder[i].order_time << " ";
					for (int k = 10 - allorder[i].order_time.length(); k >= 0; k--)
						cout << " ";
					cout << allorder[i].order_seller_id;
					cout << endl;

					yourorder++;
				}
			}
			cout << endl;
			cout << "*********************************************************" << endl;
			if (yourorder == 0)
			{
				cout << "NO order!" << endl;
			}
			cout << "计算余额" << endl;
			cout << makestring(user) << endl;
			cout << "请选择计算方式1.手动2.自动" << endl;
			int opt;
			cin >> opt;
			while (cin.fail())
			{
				cout << "请输入一个合法的数字！";
				cin >> opt;
				cin.clear();
				cin.ignore(1024, '\n');
			}string temps;
			switch (opt)
			{
			case 1:
				cin >> temps;
				cout << "此结果仅作为测试计算器功能使用" << endl;
				calculate(temps); break;
			case 2:calculate(makestring(user)); break;
			default:
				cout << "输入异常，请重新输入" << endl;
				break;
			}

	cout << "*********************************" << endl;
	cout << "请输入充值金额" << endl;
	float m;
	cin >> m;
	while (cin.fail() || m <= 0)
	{
		cout << "请输入一个合法的数字！" << endl;; return;
	}
	cout << "请输入选择（y/n）" << endl;
	string opt2;
	cin >> opt2;
	if (opt2 == "y")
	{
		alluser[user].user_wallet += m;
		Money temp;
		temp.user_id = alluser[user].user_id;
		time_t nowtime;
		struct tm* p;;
		time(&nowtime);
		p = localtime(&nowtime);
		temp.time = to_string(p->tm_year + 1900) + (string)"-" + to_string(p->tm_mon + 1) + (string)"-" + to_string(p->tm_mday);
		moneynum++;
		temp.result = m;		
		allmoney.push_back(temp);
		cout << "充值成功" << endl;
		save();
		return;
	}
	if (opt2 == "n")
	{
		cout << "取消充值成功" << endl;
		return;
	}
	else
	{
		cout << "充值失败" << endl;
	}

}
void userinfo(int user)
{
	while (true)
	{
		infomenu();
		cout << "请输入操作" << endl;
		int opt = 0;
		cin >> opt;
		while (cin.fail())
		{
			cout << "请输入一个合法的数字！";
			cin >> opt;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		switch (opt)
		{
		case 1:checkinfo(user); break;
		case 2:changeinfo(user); break;
		case 3:return; break;
		case 4:money(user); break;
		default:
			cout << "输入异常，请重新输入" << endl;
			break;
		}
	}
}
void Usermenu(int user)
{
	while (true)
{	bool newmessage = false;

	umenu();
	for (int i = 0; i < messagenum; i++)
	{
		if (allmessage[i].state == 1 && allmessage[i].recer == alluser[user].user_id)
			newmessage = true;
	}
	if (newmessage)
	{
		cout << "您有新消息！" << endl;
	}
	cout << "请输入操作" << endl;
	int opt = 0;
	cin >> opt;
	while (cin.fail())
	{
		cout << "请输入一个合法的数字！";
		cin >> opt;
		cin.clear();
		cin.ignore(1024, '\n');
	}
	
	switch (opt)
	{
	case 1:buyermenu(user); break;
	case 2:sellermenu(user); break;
	case 3:userinfo(user); break;
	case 4:return; break;
	case 5:chatcase(user); break;
	default:
		cout << "输入异常，请重新输入" << endl;
		break;
	}
}
}
void save()
{
	ofstream u;
	u.open("user.txt");
	u << usertitle << endl;
	u.setf(ios::fixed);
	u.setf(ios::showpoint);
	u.precision(1);
	for (int i = 0; i < usernum; i++)
	{
		u << alluser[i].user_id << "," << alluser[i].user_name << "," << alluser[i].user_password << "," << alluser[i].user_telnum << "," << alluser[i].user_adress << "," << alluser[i].user_wallet << "," << alluser[i].user_state << endl;
	}
	ofstream g;
	g.open("commodity.txt");
	g << goodtitle << endl;
	g.setf(ios::fixed);
	g.setf(ios::showpoint);
	g.precision(1);
	for (int i = 0; i < goodnum; i++)
	{
		g << allgood[i].good_id << "," << allgood[i].good_name << "," << allgood[i].good_price << "," << allgood[i].good_num << "," << allgood[i].good_dis << "," << allgood[i].good_seller_id<< "," << allgood[i].good_time <<","<<allgood[i].good_state<<endl;
	}
	ofstream o;
	o.open("order.txt");
	o << ordertitle << endl;
	o.setf(ios::fixed);
	o.setf(ios::showpoint);
	o.precision(1);
	for (int i = 0; i < ordernum; i++)
	{
		o << allorder[i].order_id << "," << allorder[i].goods_id << "," << allorder[i].order_per_price << "," << allorder[i].order_goods_num << "," << allorder[i].order_time << "," << allorder[i].order_seller_id<< "," << allorder[i].order_seller_id<< endl;
	}
	ofstream m;
	m.open("money.txt");
	m << moneytitle << endl;
	m.setf(ios::fixed);
	m.setf(ios::showpoint);
	m.precision(1);
	for (int i = 0; i < moneynum; i++)
	{
		m << allmoney[i].user_id << "," << allmoney[i].result<<","<< allmoney[i].time << endl;
	}
	ofstream ms;
	ms.open("message.txt");
	ms << messagetitle << endl;
	for (int i = 0; i < messagenum; i++)
	{
		ms << allmessage[i].mes << "," << allmessage[i].sender << "," << allmessage[i].recer <<","<<allmessage[i].state<<endl;
	}
	u.close();
	g.close();
	o.close();
	m.close();
	ms.close();
}
void forget()
{
	string name;
	string tel;
	string password;
	string temp;
	while (true)
	{
		cout << "请输入用户名" << endl;
		cin >> name;
		for (int i = 0; i < usernum; i++)
		{
			if (alluser[i].user_name == name && alluser[i].user_state == "正常")
			{

				while (true)
				{
					cout << "请输入联系方式" << endl;
					cin >> tel;
					if (tel == alluser[i].user_telnum)
					{
						cout << "请输入新密码" << endl;
						cin >> password;
						cout << "请确认密码" << endl;
						cin >> temp;
						if (temp != password)
						{
							cout << "两次输入不一致！" << endl;
						}
						else
						{
							alluser[i].user_password = password;
							cout << "修改成功！" << endl;
							return;
						}
					}
					else
					{
						cout << "联系方式错误！！" << endl;
						return;
					}
				}
			}
		}
		cout << "未找到该用户！！" << endl;
		return;

	}
}

