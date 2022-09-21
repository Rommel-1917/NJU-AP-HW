#include<iostream>
#include<string>
#include<vector>

#include"Administrator.h"
#include"Users.h"
#include "SQL.h"
using namespace std;

void analyse(string command,int level)
{

	if (command[0] == 'S')
	{
		int i = 0;
		int j = command.length() - 1;
		vector<char> temp;
		string result;
		for (; i < command.length() && command[i] != ' '; i++);
		i++;
		for (; i < command.length() && command[i] != ' '; i++);
		i++;
		for (; i < command.length() && command[i] != ' '; i++);
		i++;
		if (command[i] == 'c' && level == -1)
		{
			if (command.length() <= 25)
			{
				Admin_all_Good();
				return;
			}
			for (j = command.length() - 1; command[j] != ' '; j--);
			j++;
			for (int k = 0; j < command.length(); j++, k++)
			{

				temp.push_back(command[j]);
			}
			for (int i = 0; i < temp.size(); i++)
			{
				result += temp[i];
			}
			Admin_Search(result);
			return;
		}
		if (command[i] == 'c'&& command.find("seller_id")!= -1)
		{
				string id;
				for (int k = 1; k <= 4; k++)
				{
					id += command[j - 4 + k];
				}
				seller_allgood(id);
				return;

		}
		if (command[i] == 'c' && command.find("good_name") != -1)
		{
			for (; i < command.length() && command[i] != ' '; i++);
			i++;
			for (; i < command.length() && command[i] != ' '; i++);
			i++;
			for (; i < command.length() && command[i] != ' '; i++);
			i++;
			for (; i < command.length() && command[i] != ' '; i++);
			i++;
			for (; i < command.length()&&command[i]!=' '; i++)
			{
				result += command[i];
			}
			buyer_search(result);
				return;


		}
		if (command[i] == 'c' && command.find("good_id") != -1)
		{
			string id;
			for (int k = 1; k <= 4; k++)
			{
				id += command[j - 4 + k];
			}
			buyer_gooddetail(id);
			return;
		}
		if (command[i] == 'o' && command.find("buyer_id") != -1)
		{
			string id;
			for (int k = 1; k <= 4; k++)
			{
				id += command[j - 4 + k];
			}
			buyer_allorder(id);
			return;

		}

		if (command[i] == 'c' && command.find("seller_id") != -1)
		{
			string id;
			for (int k = 1; k <= 4; k++)
			{
				id += command[j - 4 + k];
			}
			seller_allorder(id);
			return;
		}
		if (command[i] == 'u' && level == -1)
		{
			if (command.length() <= 25)
			{
				Admin_all_User();
				return;
			}
		}
		if (command[i] == 'o' && level == -1)
		{
			if (command.length() <= 25)
			{
				Admin_all_Order();
				return;
			}

		}
		if (command[i] == 'o' && command.find("seller_id") != -1)
		{

			string id;
			for (int k = 1; k <= 4; k++)
			{
				id += command[j - 4 + k];
			}
			seller_allorder(id);
			return;
		}


		if (command[i] == 'c' && command.find("good_state") !=- 1)
		{

			buyer_allgood();
			return;
		}

	}
	if (command[0] == 'U')
	{
		int i = 0;
		int j = command.length()-1;		
		int flag = 0;
		vector<char> temp;
		string result;
		for (; i < command.length() && command[i] != ' '; i++);
		i++;
		if (command[i] == 'c')
		{
			if (level == -1)
			{
				for (; flag!=2; i++)
				{
					if (command[i] == '=')
						flag++;
				}
				i += 1;
				if (command[i] == 'M')
				{
					for (int k = 0; i < command.length(); i++, k++)
					{
						temp.push_back(command[i]);
					}
					for (int i = 0; i<temp.size();i++)
					{
						result += temp[i];
					}
					Admin_Delgood(result);
				}
			}

			if (command.find("good_state") != -1)
			{
				string id;
				for (int k = 1; k <= 4; k++)
				{
					id += command[j - 4 + k];
				}
				seller_delgood(id);
				return;
			}
			if (command.find("good_price") != -1)
			{
				for (; flag != 1; i++)
				{
					if (command[i] == '=')
						flag++;
				}
				i += 1;
				for (; command[i] != ' '; i++)
				{
					temp.push_back(command[i]);
				}
				for (int k = 0; k < temp.size(); k++)
				{
					result += temp[k];
				}
				float p = atof(result.c_str());
				string id;
				for (int k = 1; k <=4; k++)
				{
					id += command[j - 4 + k];
				}
				sellerer_changegoodinfo(id, p);
				return;
			}
			if (command.find("good_dis") != -1)
			{
				for (; flag != 1; i++)
				{
					if (command[i] == '=')
						flag++;
				}
				i += 1;

				for (; command[i] != ' '; i++)
				{
					temp.push_back(command[i]);
				}
				for (int k = 0; k < temp.size(); k++)
				{
					result += temp[k];
				}
				string id;
				for (int k = 1; k <= 4; k++)
				{
					id += command[j - 4 + k];
				}
				sellerer_changegoodinfo(id, result);
				return;
			}
		}
		if (command[i] == 'u')
		{
			if (level == -1)
			{
				for (; flag != 2; i++)
				{
					if (command[i] == '=')
						flag++;
				}
				i += 1;
				if (command[i] == 'U')
				{
					for (int k = 0; i < command.length(); i++, k++)
					{
						temp.push_back(command[i]);
					}
					for (int i = 0; i < temp.size(); i++)
					{
						result += temp[i];
					}
					Admin_Deluser(result);
					return;
				}
			}

		}
	}
	if (command[0] == 'I')
	{
		int i = 0;
		int j = command.length() - 1;
		int flag = 0;
		vector<char> temp;
		string result;
		for (; i < command.length() && command[i] != ' '; i++);
		i++;
		for (; i < command.length() && command[i] != ' '; i++);
		i++;
		if (command[i] == 'c')
		{

			string name;
			string num;
			string price;
			string dis;

			for (; i < command.length() && command[i] != '('; i++);
			i++;
			for (; i < command.length() && command[i] != ',' && command[i] != ')'; i++)
			{
				temp.push_back(command[i]);
			}
			i++;
			for (int k = 0; k < temp.size(); k++)
			{
				name += temp[k];
			}
			temp.erase(temp.begin(), temp.end());
			for (; i < command.length() && command[i] != ',' && command[i] != ')'; i++)
			{
				temp.push_back(command[i]);
			}
			i++;
			for (int k = 0; k < temp.size(); k++)
			{
				price += temp[k];
			}
			temp.erase(temp.begin(), temp.end());
			for (; i < command.length() && command[i] != ',' && command[i] != ')'; i++)
			{
				temp.push_back(command[i]);
			}
			i++;
			for (int k = 0; k < temp.size(); k++)
			{
				num += temp[k];
			}
			temp.erase(temp.begin(), temp.end());
			for (; i < command.length() && command[i] != ',' && command[i] != ')'; i++)
			{
				temp.push_back(command[i]);
			}
			i++;
			for (int k = 0; k < temp.size(); k++)
			{
				dis += temp[k];
			}
			temp.erase(temp.begin(), temp.end());
			float p = atof(price.c_str());
			int n = atoi(num.c_str());
			seller_sellgood(name, p, n, dis, level);
			return;
		}
		if (command[i] == 'o')
		{
			string orderid;
			string goodid;
			string price;
			string num;
			string time;
			string buyer;
			string seller;
			for (; command[i] != '('; i++);
			i++;
			for (; command[i] != ','; i++)
			{
				orderid += command[i];
			}
			i++;
			for (; command[i] != ','; i++)
			{
				goodid += command[i];
			}
			i++;
			for (; command[i] != ','; i++)
			{
				price += command[i];
			}
			i++;
			for (; command[i] != ','; i++)
			{
				num += command[i];
			}
			i++;
			for (; command[i] != ','; i++)
			{
				time += command[i];
			}
			i++;
			for (; command[i] != ','; i++)
			{
				buyer += command[i];
			}
			i++;
			for (; command[i] != ')'; i++)
			{
				seller += command[i];
			}
			i++;
			float p = atof(price.c_str());
			int n = atoi(num.c_str());
			makeorder(orderid, goodid, p, n, time, buyer, seller);
		}
}
	
}

