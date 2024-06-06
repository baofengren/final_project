#pragma once
#pragma once
#include <iostream>
#include "C110152328_bag.h"
using namespace std;

class RPG_Player
{
public:

	string	equipment[5]; // 0-> head 1 -> armor 2 -> shoe 3 -> gloves 4 -> belt 
	int equipment_strength[5];
	int equipment_wisdom[5];
	int equipment_agile[5];
	int HP;
	int MP;

	int head_strength = 0;
	int head_wisdom = 0;
	int head_agile = 0;

	int armor_strength = 0;
	int armor_wisdom = 0;
	int armor_agile = 0;

	int gloves_strength = 0;
	int gloves_wisdom = 0;
	int gloves_agile = 0;

	int shoe_strength = 0;
	int shoe_wisdom = 0;
	int shoe_agile = 0;

	int belt_strength = 0;
	int belt_wisdom = 0;
	int belt_agile = 0;

	int base_strength = 0;
	int base_wisdom = 0;
	int base_agile = 0;

	int strength = 0;
	int wisdom = 0;
	int agile = 0;
	int money = 100;
	int i;
	void display_play()
	{
		cout << "�ͩR�O�G" << HP << " �]�O:" << MP << " �O�q�G" << strength << " ���z�G" << wisdom << " �ӱ��G" << agile << " �����G" << money << endl;
		cout << "�Y���G" << equipment[0] << " �ݥҡG" << equipment[1] << " �c�l�G" << equipment[2] << " ��M�G" << equipment[3] << " �y�a:" << equipment[4] << endl;
	}
	void update()
	{
		strength = head_strength + armor_strength + shoe_strength + gloves_strength + belt_strength + base_strength;
		wisdom = head_wisdom + armor_wisdom + shoe_wisdom + gloves_wisdom + belt_wisdom + base_wisdom;
		agile = head_agile + armor_agile + shoe_agile + gloves_agile + belt_agile + base_agile;
	}
	void equip(string input, int arr[])
	{
		if (arr[4] == 0)
		{
			head_strength = arr[0];
			head_wisdom = arr[1];
			head_agile = arr[2];
		}
		else if (arr[4] == 1)
		{
			armor_strength = arr[0];
			armor_wisdom = arr[1];
			armor_agile = arr[2];
		}
		else if (arr[4] == 2)
		{
			shoe_strength = arr[0];
			shoe_wisdom = arr[1];
			shoe_agile = arr[2];
		}
		else if (arr[4] == 3)
		{
			gloves_strength = arr[0];
			gloves_wisdom = arr[1];
			gloves_agile = arr[2];
		}
		else if (arr[4] == 4)
		{
			belt_strength = arr[0];
			belt_wisdom = arr[1];
			belt_agile = arr[2];
		}
		equipment[arr[4]] = input;
		if (equipment[0] == "���L�Բ�" && equipment[4] == "�ߪe�y�a")  HP = HP * 1.1;
		strength = head_strength + armor_strength + shoe_strength + gloves_strength + belt_strength + base_strength;
		wisdom = head_wisdom + armor_wisdom + shoe_wisdom + gloves_wisdom + belt_wisdom + base_wisdom;
		agile = head_agile + armor_agile + shoe_agile + gloves_agile + belt_agile + base_agile;
	}
};