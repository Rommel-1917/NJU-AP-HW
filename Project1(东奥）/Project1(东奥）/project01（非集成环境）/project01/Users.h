#include<iostream>
#include<string>
#include<fstream> 
#include<vector>
using namespace std;
struct Users//�û���Ϣ��������Һ����ң�
{
	string user_id = { "U" };
	string user_name;
	string user_password;
	string user_telnum;
	string user_adress;
	float user_wallet = 0;
	string user_state;//��� ����
};
struct Money
{
	//��ֵ��¼
	string user_id;
	string time;
	float result;
};
struct message
{
	//��Ϣ��¼
	string mes;
	string sender;
	string recer;
	int state;//0 �Ѷ���1 δ��
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