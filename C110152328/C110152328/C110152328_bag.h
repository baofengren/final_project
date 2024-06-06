#pragma once
#pragma once
#include "C110152328_bag.h"
#include "C110152328_store.h"
#include <iostream>
using namespace std;

class RPG_bag
{
public:
	string bag[1000];
	int bag_agile[1000] = { 0 };
	int bag_strength[1000] = { 0 };
	int bag_wisdom[1000] = { 0 };
	int bag_identify[1000] = { 10 };
	int bag_count = 0;
	void displaybag()
	{
		for (int i = 0; i < bag_count; i++)
			cout << bag[i] << " ¤O¶q:" << bag_strength[i] << " ´¼¼z¡G" << bag_wisdom[i] << " ±Ó±¶¡G" << bag_agile[i] << endl;

	}
	void inbag(string input, int temp[])
	{
		bag[bag_count] = input;
		bag_identify[bag_count] = temp[4];
		bag_agile[bag_count] = temp[2];
		bag_wisdom[bag_count] = temp[1];
		bag_strength[bag_count] = temp[0];
		bag_count++;
	}
	string searchbag(string input, int arr[])
	{
		bool flag = false;
		for (int i = 0; i < bag_count; i++)
		{
			if (bag[i] == input)
			{
				arr[0] = bag_strength[i];
				arr[1] = bag_wisdom[i];
				arr[2] = bag_agile[i];
				arr[4] = bag_identify[i];
				return input;
			}
		}
		return "No_found";
	}
	void del_bag(string input)
	{
		int flag = 0;
		int temp;
		for (int i = 0; i < bag_count; i++)
		{
			if (bag[i] == input) 
			{
				flag = i;
				break;
			}
		}
		for (int i = flag; i < 998; i++)
		{
			
			bag[i] =  bag[i + 1];
			bag_strength[i] = bag_strength[i + 1];
			bag_wisdom[i] = bag_wisdom[i + 1];
			bag_agile[i] = bag_agile[i + 1];
		}
		bag_count--;
	}
};