#include<iostream>
#include"Users.h"
#include"Administrator.h"
#include"Date.h"
#include<vector>

using namespace std;
int usernum = 0, goodnum = 0, ordernum = 0, moneynum = 0,messagenum = 0;
string usertitle = "�û�ID,�û���,����,��ϵ��ʽ,��ַ,Ǯ�����,�û�״̬", goodtitle = "��ƷID,����,�۸�,����,����,����ID,�ϼ�ʱ��,��Ʒ״̬", ordertitle = "����ID,��ƷID,���׵���,����,����ʱ��,����ID,���ID", moneytitle = "�û�ID,���,��ֵʱ��", messagetitle = "���ݣ������ˣ��ռ��ˣ�״̬";
vector<Users> alluser;
vector<Goods> allgood;
vector<Order> allorder;
vector<Money> allmoney;
vector<message> allmessage;
void mainmenu()
{
	cout << "************" << "  " << "************" << "  " << "**************" << "  " << "************" << "  " << "************" << endl;
	cout << "|1.�û���¼|" << "  " << "|2.�û�ע��|" << "  " << "|3.����Ա��½|" << "  " << "|4.�˳�����|" << "  " << "|5.��������|"<< endl;
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
			cout << "������һ���Ϸ������֣�";
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
			cout << "�����쳣������������" << endl;
			break;
		}
	}
	return 0;
}