#pragma once
#pragma once
#include <iostream>
#include "C110152328_bag.h"
using namespace std;

class RPG_store
{
public:
	int i;
	string head_store[5] = { "���L�Բ�","�K�뤧�a", "�F�����a", "�F�D����", "�ִU" };
	int head_agile[5] = { 5,4,3,2,1 };
	int head_strength[5] = { 5,4,3,2,1 };
	int head_wisdom[5] = { 5,4,3,2,1 };
	int head_cost[5] = { 5,4,3,2,1 };
	const int head_identify = 0;
	string armor_store[5] = { "�v�Q����","��ģ�֥�", "���ԭ��Z", "���Y���Z", "��L����" };
	int armor_agile[5] = { 5,4,3,2,1 };
	int armor_strength[5] = { 5,4,3,2,1 };
	int armor_wisdom[5] = { 5,4,3,2,1 };
	int armor_cost[5] = { 5,4,3,2,1 };
	const int armor_identify = 1;
	string shoe_store[5] = { "�x�Ϊ��u","�t�Ԫ��u", "�ʭ��u�u", "�s����u", "���ܵu�u" };
	int shoe_agile[5] = { 5,4,3,2,1 };
	int shoe_strength[5] = { 5,4,3,2,1 };
	int shoe_wisdom[5] = { 5,4,3,2,1 };
	int shoe_cost[5] = { 5,4,3,2,1 };
	const int shoe_identify = 2;
	string gloves_store[5] = { "�]����M","���j�@��", "�˺��@��", "�T§�@��", "�ʭ���M" };
	int gloves_agile[5] = { 5,4,3,2,1 };
	int gloves_strength[5] = { 5,4,3,2,1 };
	int gloves_wisdom[5] = { 5,4,3,2,1 };
	int gloves_cost[5] = { 5,4,3,2,1 };
	const int gloves_identify = 3;
	string belt_store[5] = { "�ߪe�y�a","�֭��y�a", "���v�y�a", "����y�a", "�����y�a" };
	int belt_agile[5] = { 5,4,3,2,1 };
	int belt_strength[5] = { 5,4,3,2,1 };
	int belt_wisdom[5] = { 5,4,3,2,1 };
	int belt_cost[5] = { 5,4,3,2,1 };
	const int belt_identify = 4;
	string water_store[2] = { "�ͩR�Ĥ�","�]�O�Ĥ�" };
	int water_cost[2] = { 5,5 };
	const int water_identify = 5;
	void display_store()
	{
		cout << "�Y���ө�" << endl;
		for (i = 0; i < 5; i++)
			cout << "�W�١G" << head_store[i] << " �O�q�G" << head_strength[i] << " ���z�G" << head_wisdom[i] << " �ӱ��G" << head_agile[i] << " ��O�G" << head_cost[i] << endl;
		cout << "�ݥҰө�" << endl;
		for (i = 0; i < 5; i++)
			cout << "�W�١G" << armor_store[i] << " �O�q�G" << armor_strength[i] << " ���z�G" << armor_wisdom[i] << " �ӱ��G" << armor_agile[i] << " ��O�G" << armor_cost[i] << endl;
		cout << "�u�l�ө�" << endl;
		for (i = 0; i < 5; i++)
			cout << "�W�١G" << shoe_store[i] << " �O�q�G" << shoe_strength[i] << " ���z�G" << shoe_wisdom[i] << " �ӱ��G" << shoe_agile[i] << " ��O�G" << shoe_cost[i] << endl;
		cout << "��M�ө�" << endl;
		for (i = 0; i < 5; i++)
			cout << "�W�١G" << gloves_store[i] << " �O�q�G" << gloves_strength[i] << " ���z�G" << gloves_wisdom[i] << " �ӱ��G" << gloves_agile[i] << " ��O�G" << gloves_cost[i] << endl;
		cout << "�y�a�ө�" << endl;
		for (i = 0; i < 5; i++)
			cout << "�W�١G" << belt_store[i] << " �O�q�G" << belt_strength[i] << " ���z�G" << belt_wisdom[i] << " �ӱ��G" << belt_agile[i] << " ��O�G" << belt_cost[i] << endl;
		cout << "�Ĥ��ө�" << endl;
		for (i = 0; i < 2; i++)
			cout << water_store[i] << " ��O�G" << water_cost[i] << endl;
		cout << "ps:�P�ɸ˳ƹ��L�Բ��M�ߪe�y�a��q�i�H�Ұʦ�q�[10%��!" << endl;
	}
	string buy(string item, int tmp[], int money)
	{
		string temp;
		bool flag = true;
		bool money_flag = true;
		for (i = 0; i < 5; i++)
		{
			if (item == head_store[i])
			{
				if (money >= head_cost[i])
				{
					temp = head_store[i];
					tmp[0] = head_strength[i];
					tmp[1] = head_wisdom[i];
					tmp[2] = head_agile[i];
					tmp[3] = head_cost[i];
					tmp[4] = 0;
					money_flag = false;
				}
				flag = false;
			}
			if (item == armor_store[i])
			{
				if (money >= armor_cost[i])
				{
					temp = armor_store[i];
					tmp[0] = armor_strength[i];
					tmp[1] = armor_wisdom[i];
					tmp[2] = armor_agile[i];
					tmp[3] = armor_cost[i];
					tmp[4] = 1;
					money_flag = false;
				}
				flag = false;
			}
			if (item == shoe_store[i])
			{
				if (money >= shoe_cost[i])
				{
					temp = shoe_store[i];
					tmp[0] = shoe_strength[i];
					tmp[1] = shoe_wisdom[i];
					tmp[2] = shoe_agile[i];
					tmp[3] = shoe_cost[i];
					tmp[4] = 2;
					money_flag = false;
				}
				flag = false;
			}
			if (item == gloves_store[i])
			{
				if (money >= gloves_cost[i])
				{
					temp = gloves_store[i];
					tmp[0] = gloves_strength[i];
					tmp[1] = gloves_wisdom[i];
					tmp[2] = gloves_agile[i];
					tmp[3] = gloves_cost[i];
					tmp[4] = 3;
					money_flag = false;
				}
				flag = false;
			}
			if (item == belt_store[i])
			{
				if (money >= belt_cost[i])
				{
					temp = belt_store[i];
					tmp[0] = belt_strength[i];
					tmp[1] = belt_wisdom[i];
					tmp[2] = belt_agile[i];
					tmp[3] = belt_cost[i];
					tmp[4] = 4;
					money_flag = false;
				}
				flag = false;
			}
		}
		for (i = 0; i < 2; i++)
		{
			if (item == water_store[i])
			{
				if (money >= water_cost[i])
				{
					temp = water_store[i];
					tmp[0] = 0;
					tmp[1] = 0;
					tmp[2] = 0;
					tmp[3] = water_cost[i];
					tmp[4] = 5;
					money_flag = false;
				}
				flag = false;
			}
		}
		if (flag)	return "No_found";
		else if (money_flag) return "No_money";
		else	return temp;
	}
};