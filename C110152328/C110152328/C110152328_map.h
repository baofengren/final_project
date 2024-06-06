#pragma once
#pragma once
#include <iostream>
#include "C110152328_map.h"
#include <stdlib.h>
using namespace std;

class RPG_map
{
public:
	int map_x = 2, map_y = 2;
	int i, j;
	string location;
	string map[5][5] =
	{
		{"",	"",			"���~��",	"",						""},
		{"",	"",			"�t�v���",	"�A�ꤧ��",				""},
		{"",	"�P�ů�a",	"������",	"�������a",		"�m�i���"},
		{"",	"���x��",	"�p���R��",	"�t�v���",				""},
		{"",	"",			"�¯����",	"",						""},
	};
	void display()
	{
		system("cls");
		cout << "�{�b��m�G" << map[map_y][map_x] << endl;
		if (map[map_y][map_x] == "������") cout << "�o�̬O�a�Ϫ�����" << endl;
		else if (map[map_y][map_x] == "�t�v���") cout << "�o�O��쥻�ݩ�諰���~���B���@���j�Ŧa�A�쥻�O���_�I�̦b��Z�m�ߪ��R�n���a���@�A�b�@�Ӥ֤k�ӤF����A�ᤩ�F�o�����O�˲����g�a�s���ͩR�A�Q�W�j������֡A��ӤF�\�h�_�۪��Ӫ��A��᭻�l�ޤF�\�h����e�����ΡA�]�����u�}�]�l�ޤF���ֳ����N��v�_" << endl;
		else if (map[map_y][map_x] == "���~��") cout << "��������M�b���~�A���~�[�o�Q��������A�u�n���ۦ��H�����ŹL�o����ξ��O���`�B���N��Ө즹���A��Ӫ��V���`�B���|�V�Ӻ}�G�C�p�G�Ȱg�����ܲĤG�����O���ۯ��R����Ǫ��p���]���F�����" << endl;
		else if (map[map_y][map_x] == "�A�ꤧ��") cout << "�|�ݨ���u���Y����L�A�����P�K���e�{��Ϊ����Ų���A���M�j�h���ɶ��˪L�����e�{�A��A����F�ߤW�A�˪L�����𸭷|���o�H�H�����å��A�V�p�����y���Ҵ��o���G�׶V���A�j�������Ϧӥu���ݨ�L�����A�Ӥw�C" << endl;
		else if (map[map_y][map_x] == "�������a") cout << "�A�ꤧ�ˤ����ӷ������K���a��A��صۥկ���u�L���v���a�A�ä��Q�h�N��h���a��A���F�I�B��~�A��ұa���ߺA�]�Q�����n�A�ߺA�@����A�����w�@���l�����|�J��կ��쪺�ܼv�C" << endl;
		else if (map[map_y][map_x] == "�P�ů�a") cout << "�S����}�د�֡A�������ݷ|���o�H�H���å��A����ݰ_�ӴN���a�����P�šA�ӳo����֤��������F���[�ӳ]�p�A�]���o�د󤣦P��@�몺��|�l����L�Ӫ����i���A�Ϧӷ|���ѵ�����Ӫ������һݪ��i���A�]���N��b���i�o�ᦷ�ب�F�o����֤W���|�}�G���}��A�䤤�N�H�u�i���[����v�b�o����ֳ̬��G���A�B�u�i���[����v���ޥդѦ��W���Q���}�G�A�դѴ��o�۵M����m�A��F�]�ߦ����P�Ť��̰{ģ���ᦷ�C" << endl;
		else if (map[map_y][map_x] == "�p���R��") cout << "�g�L���R����B�A���P�N�ޤJ���R���򪺴���A�|�P����󳣬O�Ѧ��������@�A���R����S�ʬO���W�O�M���z�G���A�ߤW�򭱷|�{���I�I�B�A�⪺���~�C" << endl;
		else if (map[map_y][map_x] == "�t�v���") cout << "�@���]�Ƨ�������ΡA���G���@�w�{�ת��]�k���@" << endl;
		else if (map[map_y][map_x] == "���x��") cout << "��骺�����شӤ@���y�����z�A�P�@�몺���𤣦P�A��}���ª��g���O�@�Ӥ�A������¤F���᪺�j�Ѱ��W���G�A�ҵ����G�O�i�H��Ϊ����A�L�F��15�ѪG�걼���F�A����|���W�|�A�����X��c" << endl;
		else if (map[map_y][map_x] == "�m�i���") cout << "�o�O�i���[���󦨪��쨬�����j�p��|�N�L�q�P�ů�a���ܦ��a�A���W�ݳo������p�P�m�i�A�ߤW�ݳo������p�P�P�e�C" << endl;
		else if (map[map_y][map_x] == "�¯����") cout << "�s�}�񪺰ϰ�A�ϰ칳�O�@�����j���Ŧa�W�A��إ��j���¯���A���P��O�j�����Ŧa�A�ܤ֬O�⤽�����誺�Ŧa" << endl;
	}
	void move(string input)
	{
		if (input == "north" && map_y - 1 >= 0 && map[map_y - 1][map_x] != "")
		{
			map_y--;
			display();
		}
		else if (input == "west" && map_x - 1 >= 0 && map[map_y][map_x - 1] != "")
		{
			map_x--;
			display();
		}
		else if (input == "east" && map_x + 1 <= 4 && map[map_y][map_x + 1] != "")
		{
			map_x++;
			display();
		}
		else if (input == "south" && map_y + 1 <= 4 && map[map_y + 1][map_x] != "")
		{
			map_y++;
			display();
		}
		else cout << "�S���F" << endl;
	}
	void transfer(string input)
	{
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if (input == map[i][j])
				{
					map_y = i;
					map_x = j;
				}
			}
		}
		display();
	}
	void dis_map()
	{
		cout << "�{�b��m�G"<<map[map_y][map_y] << endl;
	}
};