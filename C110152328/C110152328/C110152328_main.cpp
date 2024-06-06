#include <iostream>
#include <Windows.h>
#include "C110152328_map.h"
#include "C110152328_bag.h"
#include "C110152328_store.h"
#include "C110152328_player.h"
#include "C110152328_monster.h"
using namespace std;
int main()
{
	int i, j;
	int store_temp[5] = { 0 }; // 0->力量 1->智慧 2->敏捷 3->金錢 4->識別項
	int bag_temp[5];
	string monster_name;
	string temp_name;
	RPG_map map;
	RPG_bag bag;
	RPG_store store;
	RPG_Player player;
	Monster M;
	string input, destination, item, profession;
	string command[] = { "west","north","east","south","move","display_player","display_bag","searchbag","store","buy","equip","kill" ,"use"};
	while (1)
	{

		cout << "請選擇職業" << endl;
		cout << "蠻人：力量賦予的屬性偏向原始傷害的強化，武器上則以較高的基礎傷害來呈現。偏重力量的怪物通常造成較高的傷害且比較難以擊殺。" << endl;
		cout << "女巫：智慧賦予的屬性偏向神秘魔法及致命的戰鬥技巧，武器上則以較高的致命率來呈現。偏重智慧的怪物通常會是脆弱但致命的玻璃大砲。" << endl;
		cout << "遊俠：敏捷賦予的屬性偏向戰鬥中的靈敏性，武器上則以較高的攻擊速度來呈現。通常會保持距離進行攻擊。" << endl;
		cin >> profession;
		if (profession == "蠻人")
		{
			player.base_strength = 10;
			player.base_agile = 5;
			player.base_wisdom = 1;
			player.HP = 200;
			player.MP = 50;
			player.update();
			break;
		}
		else if (profession == "女巫")
		{
			player.base_strength = 1;
			player.base_agile = 5;
			player.base_wisdom = 10;
			player.HP = 100;
			player.MP = 150;
			player.update();
			break;
		}
		else if (profession == "遊俠")
		{
			player.base_strength = 3;
			player.base_agile = 10;
			player.base_wisdom = 3;
			player.HP = 150;
			player.MP = 150;
			player.update();
			break;
		}
		else
		{
			system("cls");
			cout << "未知的職業，請重新選擇!" << endl;
		}
	}
	system("cls");
	for (i = 0; i < 4; i++)
		cout << "名字:" << M.name[i] << " LV:" << M.level[i] << " 位置：" << map.map[M.my[i]][M.mx[i]] << " 生命:" << M.HP[i] << " 攻擊力:" << M.atk[i] << endl;
	cout << "現在位置：" << map.map[map.map_y][map.map_x] << endl;
	cout << "這裡是地圖的中心" << endl;
	while (1)
	{
		bool command_flag = true;
		cout << "請輸入指令!" << endl;
		cin >> input;
		if (input == "exit") break;
		for (i = 0; i < sizeof command / sizeof command[0]; i++)
		{
			if (input == command[i] && i < 4) // wasd
			{
				map.move(input);
				command_flag = false;
			}
			else if (input == command[i] && i == 4) // move
			{
				cin >> destination;
				map.transfer(destination);
				command_flag = false;
			}
			else if (input == command[i] && i == 5) // display_player
			{
				player.display_play();
				command_flag = false;
			}
			else if (input == command[i] && i == 6) // display_bag
			{
				bag.displaybag();
				command_flag = false;
			}
			else if (input == command[i] && i == 7) //searchbag
			{
				cout << "請輸入要查詢的東西:" << endl;
				cin >> item;
				cout << bag.searchbag(item, store_temp) << endl;
				command_flag = false;
			}
			else if (input == command[i] && i == 8) //store
			{
				if (map.map[map.map_y][map.map_x] == "城鎮中心")	store.display_store();
				else	cout << "請先移動到城鎮中心!" << endl;
				command_flag = false;
			}
			else if (input == command[i] && i == 9) //buy
			{
				cin >> item;
				if (store.buy(item, store_temp, player.money) == "No_found")
					cout << "No_found" << endl;
				else if (store.buy(item, store_temp, player.money) == "No_money")
					cout << "No_money" << endl;
				else
				{
					bag.inbag(store.buy(item, store_temp, player.money), store_temp);
					player.money -= store_temp[3];
					cout << "購買成功" << endl;
				}
				command_flag = false;
			}
			else if (input == command[i] && i == 10) //裝備
			{
				cin >> item;
				if (bag.searchbag(item, store_temp) == "No_found")	cout << "No_found" << endl;
				else
				{
					if (player.equipment[store_temp[4]] == "")
					{
						player.equip(item, store_temp);
						bag.del_bag(item);
						cout << "裝備成功!" << endl;
					}
					else
					{
						temp_name = player.equipment[store_temp[4]];
						if (store_temp[4] == 0)
						{
							bag_temp[0] = player.head_strength;
							bag_temp[1] = player.head_wisdom;
							bag_temp[2] = player.head_agile;
							bag_temp[4] = 0;
						}
						else if (store_temp[4] == 1)
						{
							bag_temp[0] = player.armor_strength;
							bag_temp[1] = player.armor_wisdom;
							bag_temp[2] = player.armor_agile;
							bag_temp[4] = 1;
						}
						else if (store_temp[4] == 2)
						{
							bag_temp[0] = player.shoe_strength;
							bag_temp[1] = player.shoe_wisdom;
							bag_temp[2] = player.shoe_agile;
							bag_temp[4] = 2;
						}
						else if (store_temp[4] == 3)
						{
							bag_temp[0] = player.gloves_strength;
							bag_temp[1] = player.gloves_wisdom;
							bag_temp[2] = player.gloves_agile;
							bag_temp[4] = 3;
						}
						else if (store_temp[4] == 4)
						{
							bag_temp[0] = player.belt_strength;
							bag_temp[1] = player.belt_wisdom;
							bag_temp[2] = player.belt_agile;
							bag_temp[4] = 4;
						}
						player.equip(item, store_temp);
						bag.del_bag(item);
						bag.inbag(temp_name, bag_temp);
						cout << "裝備成功!" << endl;
					}
				}
				command_flag = false;
			}
			else if (input == command[i] && i == 11) //kill
			{
				cin >> monster_name;
				if (M.check_Monster(monster_name, map.map_x, map.map_y) == "No_found") cout << "沒有發現怪物" << endl;
				else if (M.check_Monster(monster_name, map.map_x, map.map_y) == "false") cout << "位置不對喔!" << endl;
				else
				{
					int t,h;
					bool f_flag;
					string reword;
					t = M.HP[M.check(monster_name)];
					h = player.HP;
					cout << "戰鬥開始!" << endl;
					while (1)
					{
						int mode = M.fight();
						if (mode == 1)
						{
							t -= player.strength;
							cout << "----------------------------" << endl;
							cout << "你造成" << player.strength << "點傷害" << endl;
							cout << "你現在的血量：" << h << endl;
							cout << monster_name << "現在的血量：" << t << endl;
							cout << "----------------------------" << endl;
							Sleep(1000);
							if (t <= 0)
							{
								cout << "你贏了!" << endl;
								f_flag = true;
								player.HP = h;
								break;
							}
						}
						else if (mode == 2)
						{
							int temp;
							cin >> item;
							f_flag = false;
							if (bag.searchbag(item, store_temp) == "No_found")	cout << "No_found" << endl;
							else if (item == "生命藥水")
							{
								h += 10;
								bag.del_bag(item);
								cout << "使用成功!" << endl;
							}
							else if (item == "魔力藥水")
							{
								h += 10;
								bag.del_bag(item);
								cout << "使用成功!" << endl;
							}
							else	cout << "該物品無法使用!" << endl;
						}
						else
						{
							player.HP = h;
							f_flag = false;
							break;
						}
						h -= M.atk[M.check(monster_name)];
						cout << "----------------------------" << endl;
						cout << "他造成" << M.atk[M.check(monster_name)] << "點傷害" << endl;
						cout << "你現在的血量：" << h << endl;
						cout << monster_name << "現在的血量：" << t << endl;
						cout << "----------------------------" << endl;
						Sleep(1000);
						if (h <= 0)
						{
							f_flag = false;
							cout << "你輸了!你沒有血量了!" << endl;
							break;
						}
					}
					if (f_flag)		// 掉東西
					{
						reword = M.reward(M.check(monster_name),store_temp);
						cout << "恭喜獲得：" << reword << endl;
						player.money += (M.check(monster_name) + 1) * 10;
						cout << "恭喜獲得：" << (M.check(monster_name) + 1) * 10 << "元!" << endl;
						bag.inbag(reword,store_temp);
					}
				}
				command_flag = false;
			}
			else if (input == command[i] && i == 12) //use
			{
				int temp;
				cin >> item;
				if (bag.searchbag(item, store_temp) == "No_found")	cout << "No_found" << endl;
				else if (item == "生命藥水")
				{
					player.HP += 10;
					bag.del_bag(item);
					cout << "使用成功!" << endl;
				}
				else if (item == "魔力藥水")
				{
					player.MP += 10;
					bag.del_bag(item);
					cout << "使用成功!" << endl;
				}
				else	cout << "該物品無法使用!" << endl;
				command_flag = false;
			}
			else if (input == command[i] && i == 13)
			{
				map.dis_map();
				command_flag = false;
			}
		}
		if (command_flag)	cout << "未知的指令" << endl;
	}
	return 0;
}