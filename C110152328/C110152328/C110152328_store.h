#pragma once
#pragma once
#include <iostream>
#include "C110152328_bag.h"
using namespace std;

class RPG_store
{
public:
	int i;
	string head_store[5] = { "夢魘戰盔","鐵鍛之冠", "靈骨之冠", "靈主之環", "皮帽" };
	int head_agile[5] = { 5,4,3,2,1 };
	int head_strength[5] = { 5,4,3,2,1 };
	int head_wisdom[5] = { 5,4,3,2,1 };
	int head_cost[5] = { 5,4,3,2,1 };
	const int head_identify = 0;
	string armor_store[5] = { "權貴環甲","光耀皮甲", "征戰重鎧", "莊嚴之鎧", "哨兵之衣" };
	int armor_agile[5] = { 5,4,3,2,1 };
	int armor_strength[5] = { 5,4,3,2,1 };
	int armor_wisdom[5] = { 5,4,3,2,1 };
	int armor_cost[5] = { 5,4,3,2,1 };
	const int armor_identify = 1;
	string shoe_store[5] = { "軍團長靴","聖戰長靴", "粗革短靴", "龍鱗長靴", "匿蹤短靴" };
	int shoe_agile[5] = { 5,4,3,2,1 };
	int shoe_strength[5] = { 5,4,3,2,1 };
	int shoe_wisdom[5] = { 5,4,3,2,1 };
	int shoe_cost[5] = { 5,4,3,2,1 };
	const int shoe_identify = 2;
	string gloves_store[5] = { "魔指手套","遠古護手", "瓦爾護手", "禁禮護手", "粗革手套" };
	int gloves_agile[5] = { 5,4,3,2,1 };
	int gloves_strength[5] = { 5,4,3,2,1 };
	int gloves_wisdom[5] = { 5,4,3,2,1 };
	int gloves_cost[5] = { 5,4,3,2,1 };
	const int gloves_identify = 3;
	string belt_store[5] = { "冥河腰帶","皮革腰帶", "扣釘腰帶", "扣鏈腰帶", "飾布腰帶" };
	int belt_agile[5] = { 5,4,3,2,1 };
	int belt_strength[5] = { 5,4,3,2,1 };
	int belt_wisdom[5] = { 5,4,3,2,1 };
	int belt_cost[5] = { 5,4,3,2,1 };
	const int belt_identify = 4;
	string water_store[2] = { "生命藥水","魔力藥水" };
	int water_cost[2] = { 5,5 };
	const int water_identify = 5;
	void display_store()
	{
		cout << "頭盔商店" << endl;
		for (i = 0; i < 5; i++)
			cout << "名稱：" << head_store[i] << " 力量：" << head_strength[i] << " 智慧：" << head_wisdom[i] << " 敏捷：" << head_agile[i] << " 花費：" << head_cost[i] << endl;
		cout << "胸甲商店" << endl;
		for (i = 0; i < 5; i++)
			cout << "名稱：" << armor_store[i] << " 力量：" << armor_strength[i] << " 智慧：" << armor_wisdom[i] << " 敏捷：" << armor_agile[i] << " 花費：" << armor_cost[i] << endl;
		cout << "靴子商店" << endl;
		for (i = 0; i < 5; i++)
			cout << "名稱：" << shoe_store[i] << " 力量：" << shoe_strength[i] << " 智慧：" << shoe_wisdom[i] << " 敏捷：" << shoe_agile[i] << " 花費：" << shoe_cost[i] << endl;
		cout << "手套商店" << endl;
		for (i = 0; i < 5; i++)
			cout << "名稱：" << gloves_store[i] << " 力量：" << gloves_strength[i] << " 智慧：" << gloves_wisdom[i] << " 敏捷：" << gloves_agile[i] << " 花費：" << gloves_cost[i] << endl;
		cout << "腰帶商店" << endl;
		for (i = 0; i < 5; i++)
			cout << "名稱：" << belt_store[i] << " 力量：" << belt_strength[i] << " 智慧：" << belt_wisdom[i] << " 敏捷：" << belt_agile[i] << " 花費：" << belt_cost[i] << endl;
		cout << "藥水商店" << endl;
		for (i = 0; i < 2; i++)
			cout << water_store[i] << " 花費：" << water_cost[i] << endl;
		cout << "ps:同時裝備夢魘戰盔和冥河腰帶血量可以啟動血量加10%喔!" << endl;
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