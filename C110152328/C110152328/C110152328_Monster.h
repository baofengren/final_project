#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

class Monster
{
public:
	string name[4] = { "�ڭ�","��ù������","��������","�ϩԧJ��" }; // �P�ů�a ���~�� �¯���� �m�i���
	int mx[4] = { 1,2,2,4 };
	int my[4] = { 2,0,4,2 };
	int level[4] = { 1,2,3,4 };
	int HP[4] = { 5,10,15,20 };
	int atk[4] = { 10,20,30,40 };
	int speed[4] = {2,4,6,8};
	string m_item[4] = {"�ڭۤ��a","��ù�����Ȫ��@��","�����������u","�ϩԧJ�����@��" };
	int m_strength[4] = {10,15,20,25};
	int m_wisdom[4] = { 10,15,20,25 };
	int m_agile[4] = { 10,15,20,25 };
	int m_id[4] = {0,1,2,3};
	int m_money[4] = {5,10,15,20};
	string check_Monster(string Mname, int px, int py)
	{
		int id;
		bool flag = false;
		for (int i = 0; i < 4; i++)
		{
			if (Mname == name[i])
			{
				flag = true;
				id = i;
			}
		}
		if (flag)
		{
			if (px == mx[id] && py == my[id]) return "Right ";
			else return "false";
		}
		else return "No_found";
	}
	int check(string M_name)
	{
		for (int i = 0; i < 4; i++)
		{
			if (M_name == name[i]) return i;
		}
	}
	int fight()
	{
		int command;
		cout << "1.����" << endl;
		cout << "2.�ϥ��Ĥ�" << endl;
		cout << "3.�k�]" << endl;
		cin >> command;
		if (command == 1) return 1;			//atk
		else if (command == 2) return 2;	// use
		else if (command == 3) 	return 3;	//�k�]
		else cout << "�L�Ī����O!" << endl;
	}
	string reward(int id,int temp[])
	{
		temp[0] = m_strength[id];
		temp[1] = m_wisdom[id];
		temp[2] = m_agile[id];
		temp[4] = m_id[id];
		return m_item[id];
	}
};