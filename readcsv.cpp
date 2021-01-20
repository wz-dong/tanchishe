#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include"tcs.h"
#include<iostream>
using namespace std;
void Chessboard::Refresh(int map[MAPX][MAPY], int *grade, int *gamespeed, int *length, int *score) //  输出贪吃蛇棋盘
	{
		int i, j;
		for (i = 0; i < MAPX; i++) {
			for (j = 0; j < MAPY; j++) {
				map[i][j] = 100;
			}
			Gotoxy(i, 40);
			color(FOREGROUND_GREEN, FOREGROUND_RED);
			switch (i) {
			case 0: cout << "\t***********************"; break;
			case 1: cout << "\t等级为：" << *grade; break;//显示等级
			//case 3: cout << "\t自动前进时间"; break;
			//case 4: cout << "\t间隔为：" << *gamespeed << "ms"; break;//显示时间
			case 6: cout << "\t历史最高分为:" << *score << "分"; break;
			case 7: cout << "\t你现在得分为:" << (*length + (*grade - 1) * 8) * 10 << "分"; break;
			case 8: cout << "\t**********************"; break;
			case 9: cout << "\t游戏说明："; break;
			case 10: cout << "\t(1)用wasd控制"; break;
			case 11: cout << "\t蛇头运动方向;"; break;
			case 12: cout << "\t(2)蛇每吃一个果子蛇身"; break;
			case 13: cout << "\t增加一节;"; break;
			case 14: cout << "\t(3)蛇咬到自己或碰到墙"; break;
			case 15: cout << "\t壁游戏结束。"; break;
			case 18: cout << "\t**********************"; break;
			case 19: cout << "\tC++语言作业："; break;
			case 20:cout << "小组成员：王子东，王智凯，王天琪，谭永延，臧伟，王晨"; break;
			}
		}

		ifstream inFile(name, ios::in);
		if (!inFile)
		{
			cout << "打开文件失败！" << endl;
			exit(1);
		}
		i = 0;
		string line;
		string field;
		while (getline(inFile, line))//getline(inFile, line)表示按行读取CSV文件中的数据
		{
			string field;
			istringstream sin(line); //将整行字符串line读入到字符串流sin中
			for (int j = 0; j < MAPY; j++) {
				getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
				map[i][j] = atoi(field.c_str());
			}
			i++;
		}
		inFile.close();
		map[0][0] = 111;
		for (i = 0; i < MAPX; i++) {
			for (j = 0; j < MAPY; j++) {
				if (map[i][j] == 111)//输出棋盘墙壁
				{
					Gotoxy(i, j);
					color(FOREGROUND_GREEN, FOREGROUND_RED);
					cout << "□";
				}
			}
		}
}; 
void Chessboard::Changename(string name) {
	this->name = name;
}