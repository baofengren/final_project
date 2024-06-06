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
		{"",	"",			"花園外圍",	"",						""},
		{"",	"",			"聖影花園",	"翠圓之森",				""},
		{"",	"星空草地",	"城鎮中心",	"神隱之地",		"彩虹花海"},
		{"",	"櫻樹庭園",	"小神愛湖",	"聖影木屋",				""},
		{"",	"",			"黑神木區",	"",						""},
	};
	void display()
	{
		system("cls");
		cout << "現在位置：" << map[map_y][map_x] << endl;
		if (map[map_y][map_x] == "城鎮中心") cout << "這裡是地圖的中心" << endl;
		else if (map[map_y][map_x] == "聖影花園") cout << "這是於原本屬於西城門外遠處的一塊大空地，原本是眾冒險者在比武練習的愛好場地之一，在一個少女來了之後，賦予了這塊滿是傷痕的土地新的生命，鋪上大塊的草皮，栽植了許多奇幻的植物，其花香吸引了許多食花蜜的昆蟲，因環境優良也吸引了不少鳥類就近築巢" << endl;
		else if (map[map_y][map_x] == "花園外圍") cout << "此花園雖然在城外，但外觀卻十分的明顯，只要順著有人為裁剪過得的圓形樹叢的深處走就能來到此花園，其植物越往深處走會越來漂亮。如果怕迷路的話第二條路是順著神愛之湖旁的小磲走也能到達此花園" << endl;
		else if (map[map_y][map_x] == "翠圓之森") cout << "會看到視線裡頭的樹林，但葉與枝都呈現圓形的裁剪痕跡，雖然大多的時間森林內都呈現翠綠，但到了晚上，森林內的樹葉會散發淡淡的綠色螢光，越小的樹木造景所散發的亮度越高，大型的樹木反而只夠看到他的型態而已。" << endl;
		else if (map[map_y][map_x] == "神隱之地") cout << "翠圓之森內有個極度隱密的地方，栽種著白神木「夏娃」之地，並不想去就能去的地方，除了碰運氣外，其所帶的心態也十分重要，心態一不對，說不定一輩子都不會遇到白神木的蹤影。" << endl;
		else if (map[map_y][map_x] == "星空草地") cout << "特殊的改良種草皮，葉的頂端會散發淡淡的螢光，整體看起來就像地面的星空，而這片草皮不完全為了美觀而設計，因為這種草不同於一般的草會吸走其他植物的養分，反而會提供給附近植物成長所需的養分，因此就算在不養得花朵種到了這片草皮上都會漂亮的開花，其中就以「虹光琉璃草」在這片草皮最為亮眼，且「虹光琉璃草」不管白天早上都十分漂亮，白天散發自然的色彩，到了夜晚成為星空中最閃耀的花朵。" << endl;
		else if (map[map_y][map_x] == "小神愛湖") cout << "經過神愛之湖翡翠的同意引入神愛之湖的湖水，四周的花草都是由此湖水做灌溉，神愛湖水特性是早上是清澈透亮的，晚上湖面會閃著點點翡翠色的光芒。" << endl;
		else if (map[map_y][map_x] == "聖影木屋") cout << "一間設備完善的木屋，似乎有一定程度的魔法防護" << endl;
		else if (map[map_y][map_x] == "櫻樹庭園") cout << "花園的中央種植一顆『神櫻木』，與一般的櫻花樹不同，花開花謝的週期是一個月，當櫻花謝了之後的隔天馬上結果，所結的果是可以實用的櫻桃，過了約15天果實掉光了，此樹會馬上會再次結出花苞" << endl;
		else if (map[map_y][map_x] == "彩虹花海") cout << "這是虹光琉璃草成長到足夠的大小後會將他從星空草地移至此地，早上看這片花海如同彩虹，晚上看這片花海如同星河。" << endl;
		else if (map[map_y][map_x] == "黑神木區") cout << "新開放的區域，區域像是一片巨大的空地上，栽種巨大的黑神木，樹木周圍是大片的空地，至少是兩公里見方的空地" << endl;
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
		else cout << "沒路了" << endl;
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
		cout << "現在位置："<<map[map_y][map_y] << endl;
	}
};