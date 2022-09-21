#include<iostream>
#include<string>
#include<fstream> 
#include<vector>
using namespace std;
struct Users//用户信息，包括买家和卖家；
{
	string user_id = { "U" };
	string user_name;
	string user_password;
	string user_telnum;
	string user_adress;
	float user_wallet = 0;
	string user_state;//封禁 正常
};
struct Money
{
	//充值记录
	string user_id;
	string time;
	float result;
};
struct message
{
	//消息记录
	string mes;
	string sender;
	string recer;
	int state;//0 已读，1 未读
};
void buyer_allorder(string id);
void seller_allorder(string id);
void User_login();
void Register();
void makeorder(string orderid, string goodid, float price, int num, string ordertime, string buyerid, string sellerid);
void buyer_allgood();
void buyer_search(string name);
void seller_allgood(string id);
void seller_sellgood(string name, float price, int num, string dis, int user);
void seller_delgood(string id);
void buyer_gooddetail(string ID);
void sellerer_changegoodinfo(string id ,float price);
void sellerer_changegoodinfo(string id, string dis);
void Usermenu(int user);
void buyermenu(int user);
void sellermenu(int user);
void save();
void forget();
void umenu();
void bmenu();
void smenu();