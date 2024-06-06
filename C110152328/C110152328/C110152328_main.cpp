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
	int store_temp[5] = { 0 }; // 0->�O�q 1->���z 2->�ӱ� 3->���� 4->�ѧO��
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

		cout << "�п��¾�~" << endl;
		cout << "�Z�H�G�O�q�ᤩ���ݩʰ��V��l�ˮ`���j�ơA�Z���W�h�H��������¦�ˮ`�ӧe�{�C�����O�q���Ǫ��q�`�y���������ˮ`�B������H�����C" << endl;
		cout << "�k�šG���z�ᤩ���ݩʰ��V�����]�k�έP�R���԰��ޥ��A�Z���W�h�H�������P�R�v�ӧe�{�C�������z���Ǫ��q�`�|�O�ܮz���P�R�������j���C" << endl;
		cout << "�C�L�G�ӱ��ᤩ���ݩʰ��V�԰������F�өʡA�Z���W�h�H�����������t�רӧe�{�C�q�`�|�O���Z���i������C" << endl;
		cin >> profession;
		if (profession == "�Z�H")
		{
			player.base_strength = 10;
			player.base_agile = 5;
			player.base_wisdom = 1;
			player.HP = 200;
			player.MP = 50;
			player.update();
			break;
		}
		else if (profession == "�k��")
		{
			player.base_strength = 1;
			player.base_agile = 5;
			player.base_wisdom = 10;
			player.HP = 100;
			player.MP = 150;
			player.update();
			break;
		}
		else if (profession == "�C�L")
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
			cout << "������¾�~�A�Э��s���!" << endl;
		}
	}
	system("cls");
	for (i = 0; i < 4; i++)
		cout << "�W�r:" << M.name[i] << " LV:" << M.level[i] << " ��m�G" << map.map[M.my[i]][M.mx[i]] << " �ͩR:" << M.HP[i] << " �����O:" << M.atk[i] << endl;
	cout << "�{�b��m�G" << map.map[map.map_y][map.map_x] << endl;
	cout << "�o�̬O�a�Ϫ�����" << endl;
	while (1)
	{
		bool command_flag = true;
		cout << "�п�J���O!" << endl;
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
				cout << "�п�J�n�d�ߪ��F��:" << endl;
				cin >> item;
				cout << bag.searchbag(item, store_temp) << endl;
				command_flag = false;
			}
			else if (input == command[i] && i == 8) //store
			{
				if (map.map[map.map_y][map.map_x] == "������")	store.display_store();
				else	cout << "�Х����ʨ쫰����!" << endl;
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
					cout << "�ʶR���\" << endl;
				}
				command_flag = false;
			}
			else if (input == command[i] && i == 10) //�˳�
			{
				cin >> item;
				if (bag.searchbag(item, store_temp) == "No_found")	cout << "No_found" << endl;
				else
				{
					if (player.equipment[store_temp[4]] == "")
					{
						player.equip(item, store_temp);
						bag.del_bag(item);
						cout << "�˳Ʀ��\!" << endl;
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
						cout << "�˳Ʀ��\!" << endl;
					}
				}
				command_flag = false;
			}
			else if (input == command[i] && i == 11) //kill
			{
				cin >> monster_name;
				if (M.check_Monster(monster_name, map.map_x, map.map_y) == "No_found") cout << "�S���o�{�Ǫ�" << endl;
				else if (M.check_Monster(monster_name, map.map_x, map.map_y) == "false") cout << "��m�����!" << endl;
				else
				{
					int t,h;
					bool f_flag;
					string reword;
					t = M.HP[M.check(monster_name)];
					h = player.HP;
					cout << "�԰��}�l!" << endl;
					while (1)
					{
						int mode = M.fight();
						if (mode == 1)
						{
							t -= player.strength;
							cout << "----------------------------" << endl;
							cout << "�A�y��" << player.strength << "�I�ˮ`" << endl;
							cout << "�A�{�b����q�G" << h << endl;
							cout << monster_name << "�{�b����q�G" << t << endl;
							cout << "----------------------------" << endl;
							Sleep(1000);
							if (t <= 0)
							{
								cout << "�AĹ�F!" << endl;
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
							else if (item == "�ͩR�Ĥ�")
							{
								h += 10;
								bag.del_bag(item);
								cout << "�ϥΦ��\!" << endl;
							}
							else if (item == "�]�O�Ĥ�")
							{
								h += 10;
								bag.del_bag(item);
								cout << "�ϥΦ��\!" << endl;
							}
							else	cout << "�Ӫ��~�L�k�ϥ�!" << endl;
						}
						else
						{
							player.HP = h;
							f_flag = false;
							break;
						}
						h -= M.atk[M.check(monster_name)];
						cout << "----------------------------" << endl;
						cout << "�L�y��" << M.atk[M.check(monster_name)] << "�I�ˮ`" << endl;
						cout << "�A�{�b����q�G" << h << endl;
						cout << monster_name << "�{�b����q�G" << t << endl;
						cout << "----------------------------" << endl;
						Sleep(1000);
						if (h <= 0)
						{
							f_flag = false;
							cout << "�A��F!�A�S����q�F!" << endl;
							break;
						}
					}
					if (f_flag)		// ���F��
					{
						reword = M.reward(M.check(monster_name),store_temp);
						cout << "������o�G" << reword << endl;
						player.money += (M.check(monster_name) + 1) * 10;
						cout << "������o�G" << (M.check(monster_name) + 1) * 10 << "��!" << endl;
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
				else if (item == "�ͩR�Ĥ�")
				{
					player.HP += 10;
					bag.del_bag(item);
					cout << "�ϥΦ��\!" << endl;
				}
				else if (item == "�]�O�Ĥ�")
				{
					player.MP += 10;
					bag.del_bag(item);
					cout << "�ϥΦ��\!" << endl;
				}
				else	cout << "�Ӫ��~�L�k�ϥ�!" << endl;
				command_flag = false;
			}
			else if (input == command[i] && i == 13)
			{
				map.dis_map();
				command_flag = false;
			}
		}
		if (command_flag)	cout << "���������O" << endl;
	}
	return 0;
}