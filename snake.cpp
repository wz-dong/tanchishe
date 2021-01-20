#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include"tcs.h"
#include<iostream>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<sstream>
#include<fstream>
using namespace std;
//□◆●★

/*void Readini(FILE** fphead, int* score, char* argv[]) //创建或打开一个和运行文件对应的ini文件,读取最高纪录
{
	char filename[200], * pfilename = &filename[0];
	int flag = -1, i;

	strcpy(filename, argv[0]);
	for (i = 0; filename[i] != '\0'; i++)
	{
		if ('.' == filename[i])flag = 1;
	}

	if (1 == flag)
	{
		filename[i - 1] = 'i';
		filename[i - 2] = 'n';
		filename[i - 3] = 'i';
	}
	else
	{
		filename[i] = '.';
		filename[i + 1] = 'i';
		filename[i + 2] = 'n';
		filename[i + 3] = 'i';
		filename[i + 4] = '\0';
	}
	for (; filename[i] != '\\' && i >= 0; i--)pfilename = &filename[i];
	if ((*fphead = fopen(pfilename, "rb+")) == NULL)
	{
		if ((*fphead = fopen(pfilename, "wb+")) == NULL)
		{
			printf("无法创建或打开\"%s\"文件\n", pfilename);
			system("pause");
			exit(0);
		}
	}
	else
	{
		fread(score, sizeof(int), 1, *fphead);
	}
}

void Writeini(FILE** fphead, int* score, char* argv[])  //打开一个和运行文件对应的ini文件,写入最高纪录
{
	char filename[200], * pfilename = &filename[0];
	int flag = -1, i;

	strcpy(filename, argv[0]);
	for (i = 0; filename[i] != '\0'; i++)
	{
		if ('.' == filename[i])flag = 1;
	}

	if (1 == flag)
	{
		filename[i - 1] = 'i';
		filename[i - 2] = 'n';
		filename[i - 3] = 'i';
	}
	else
	{
		filename[i] = '.';
		filename[i + 1] = 'i';
		filename[i + 2] = 'n';
		filename[i + 3] = 'i';
		filename[i + 4] = '\0';
	}
	for (; filename[i] != '\\' && i >= 0; i--)pfilename = &filename[i];
	if ((*fphead = fopen(pfilename, "wb+")) == NULL)
	{
		printf("无法写入\"%s\"文件，磁盘写保护!\n", pfilename);
		system("pause");
		exit(0);
	}
	else
	{
		rewind(*fphead);
		fwrite(score, sizeof(int), 1, *fphead);
		fclose(*fphead);
	}
}
*/
Gotoxy::Gotoxy(int x, int y)//光标定位,光标定位函数SetConsoleCursorPosition是左上角位置是0,0然后向左向下延伸
{
	x = x + 10;
	y = y + 15;
	COORD pos;
	pos.X = 2 * y;
	pos.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = false;
	SetConsoleCursorInfo(hOut, &cci);
}

/*class COLOR {
public:
	void color() {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	}

	void color(int color1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
	}
	void color(int color1, int color2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1 | color2);
	}
	void color(int color1, int color2, int color3) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1 | color2 | color3);
	}
private:
	string color1, color2, color3;
};
COLOR Colors;*/

/*class Chessboard {
public:
	void Refresh(int map[33][35], int grade, int gamespeed, int length, int score) //  输出贪吃蛇棋盘
	{
		int i, j;
		for (i = 0; i < 33; i++) {
			for (j = 0; j < 35; j++) {
				map[i][j] = 100;
			}
			Gotoxy(i, 34);
			color(FOREGROUND_GREEN, FOREGROUND_RED);
			switch (i) {
			case 0: cout << "\t					***********************"; break;
			case 1: cout << "\t					等级为：" << grade; break;//显示等级
			case 3: cout << "\t					自动前进时间"; break;
			case 4: cout << "\t					间隔为：" << gamespeed << "ms"; break;//显示时间
			case 6: cout << "\t					历史最高分为:" << score << "分"; break;
			case 7: cout << "\t					你现在得分为:" << (length + (grade - 1) * 8) * 10 << "分"; break;
			case 8: cout << "\t					**********************"; break;
			case 9: cout << "\t					游戏说明："; break;
			case 10: cout << "\t					(1)用wasd控制"; break;
			case 11: cout << "\t					蛇头运动方向;"; break;
			case 12: cout << "\t					(2)蛇每吃一个果子蛇身"; break;
			case 13: cout << "\t					增加一节;"; break;
			case 14: cout << "\t					(3)蛇咬到自己或碰到墙"; break;
			case 15: cout << "\t					壁游戏结束。"; break;
			case 18: cout << "\t					**********************"; break;
			case 19: cout << "\t					C/C++语言作业："; break;
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
			for (int j = 0; j < 35; j++) {
				getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
				map[i][j] = atoi(field.c_str());
			}
			i++;
		}
		inFile.close();
		map[0][0] = 111;
		for (i = 0; i < 33; i++) {
			for (j = 0; j < 35; j++) {
				if (map[i][j] == 111)//输出棋盘墙壁
				{
					Gotoxy(i, j);
					color(FOREGROUND_GREEN, FOREGROUND_RED);
					cout << "□";
				}
			}
		}
	}
	void Changename(string name) {
		this->name = name;
	}
private:
	color Color1;
	string name;
};*/

void makefood(int map[MAPX][MAPY], int* length) {
	int x, y;
	srand(time(0));//设置随机种子
	do
	{
		x = rand() % (MAPX-2) + 1;
		y = rand() % (MAPY-2) + 1;
		
	} while (map[x][y] % 10 == (1 || 3));//如果不是在空白处重新出果子
	map[x][y] = 102;
	Gotoxy(x, y);
	color(FOREGROUND_GREEN);
	cout << "◆";
	*length += 1;

}

void move(int map[MAPX][MAPY], int* tailx, int* taily, int* headx, int* heady, char* direction, int* gamegoing, int* length, int* gamespeed) {
	int tailxtemp = *tailx, tailytemp = *taily;
	int headxtemp = *headx, headytemp = *heady;
	int guonum=0;
	//头移动
	switch (*direction) {
	case 'w': {
		map[*headx][*heady] = 123;
		*headx -= 1;
		break;
	}
	case 'a':
	{
		map[*headx][*heady] = 133;
		*heady -= 1;
		break;
	}
	case 's':
	{
		map[*headx][*heady] = 143;
		*headx += 1;
		break;
	}
	case 'd':
	{
		map[*headx][*heady] = 113;
		*heady += 1;
		break;
	}
	}
	//其他情况  
	switch (map[*headx][*heady] % 10) {
	case 2: {*gamegoing = 1;
		makefood(map, length);
		if (*gamespeed > 100 && *length % 3 == 0) {
			if (*gamespeed > 200) {
				*gamespeed = *gamespeed - 50;
			}
			else
				*gamespeed = *gamespeed - 20;
			//Gotoxy(4, 62);
			//cout << *gamespeed;
		}

		goto goto1;break;//吃到果实跳过去尾操作
	}
	case 1:*gamegoing = 0; break;//撞墙
	case 3:*gamegoing = 0; break;
	default:break;
	}
	

	//更新尾巴
	switch (map[*tailx][*taily]) {
	case 113: {
		*taily += 1;
		break;
	}
	case 123: {
		*tailx -= 1;
		break;
	}
	case 133: {
		*taily -= 1;
		break;
	}
	case 143: {
		*tailx += 1;
		break;
	}
	}
	Gotoxy(tailxtemp, tailytemp);
	cout << "  ";
	map[tailxtemp][tailytemp] = 100;

goto1:
	Gotoxy(*headx, *heady);
	color(FOREGROUND_GREEN, FOREGROUND_RED);
	cout << "★";
	Gotoxy(headxtemp, headytemp);
	color(FOREGROUND_RED);
	cout << "●";
}

void full_screen()
{
	HWND hwnd = GetForegroundWindow();
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);   /* 标准输出缓冲区句柄 */
	int cx = GetSystemMetrics(SM_CXSCREEN);            /* 屏幕宽度 */
	int cy = GetSystemMetrics(SM_CYSCREEN);            /* 屏幕高度 */

	
	char cmd[32] = { 0 };
	sprintf(cmd, "MODE CON: COLS=%d LINES=%d", cx , cy );
	system(cmd);
	SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}

int main(int argc, char* argv[]) {
	Chessboard Chassboards;
	Chassboards.Changename("namemap1.csv");
	int m = 0;
	int grade = 1, gamespeed = 300, *gamespeed_ = &gamespeed;
goto2:
	system("cls");//清除屏幕
	
	int length = 4, * length_ = &length;
	int i, j, score, directiontemp, gamegoing = 1, * gamegoing_ = &gamegoing;
	int iffood = 1, * iffood_ = &iffood;
	char direction = 'd', * direction_ = &direction;
	int door = 0;
	
	int *m_ = &m;
	int tailx, * tailx_ = &tailx;
	int taily, * taily_ = &taily;
	int headx, * headx_ = &headx;
	int heady, * heady_ = &heady;
	long start, timeover, starttemp;
	int map[MAPX][MAPY];     //  贪吃蛇棋盘是一个二维数组(如22*22，包括墙壁)
	color(FOREGROUND_GREEN);
	for (int p = 0; p < 40; ++p)cout << "地图加载中.....................地图加载中......................地图加载中..........地图加载中......................地图加载中..........地图加载中......................地图加载中..........地图加载中......................地图加载中..........地图加载中......................地图加载中.........." << endl;
	full_screen();

	FILE* fpini;//*fpini 信息文件
	readini(&fpini, &score, argv);//读取ini文件的最高纪录
	if (score < 0)//最高成绩小于零设置为零，初建文件会是负数
		score = 0;
	Chassboards.Refresh(map, &grade, &gamespeed, &length, &score);
	//初始化蛇
	map[1][2] = 113;
	map[1][3] = 113;
	map[1][4] = 113;
	map[1][5] = 113;
	tailx = 1; taily = 2;
	headx = 1; heady = 5;
	Gotoxy(tailx, taily);
	color(FOREGROUND_RED);
	cout << "●●●";
	color(FOREGROUND_GREEN, FOREGROUND_RED);
	cout << "★";
	makefood(map, length_);
	Gotoxy(35, 8);
	color();
	cout << "\t 游戏进行中!" << endl;
	while (1) {
		Gotoxy(36, 8);
		color();
		cout << "\t间隔为：" << *gamespeed_ << "ms";
		start = clock();
		while ((timeover = ((starttemp = clock()) - start <= gamespeed)) && !kbhit());//如果有键按下或时间超过自动前进时间间隔则终止循环
		if (direction == 'w' || direction == 'a' || direction == 's' || direction == 'd')//防止其它按键
			directiontemp = direction;//保留上一次方向按键
		while (kbhit())
		{
			if (timeover)
			{
				direction = getch();
			}
			if (!(direction == 'w' || direction == 'a' || direction == 's' || direction == 'd'))
			{
				direction = directiontemp;//判断反向无效//  按键非方向键，otherkey设置为0
			}
			else
			{
				if (fabs(float(direction) - float(directiontemp)) == 3 || fabs(float(direction) - float(directiontemp)) == 4)
					direction = directiontemp;//判断反向无效
			}


		}
		while ((timeover = ((starttemp = clock()) - start <= gamespeed)));

		if (gamegoing)//移动一格
			move(map, tailx_, taily_, headx_, heady_, direction_, gamegoing_, length_, gamespeed_);
		else break;
		if (length > 6) {
			*m_ = *m_ + 1;
			Gotoxy(35, 7);
			cout << "恭喜进入下一关";
			grade += 1;
			switch (*m_)
			{
			case 1:Chassboards.Changename("namemap2.csv"); *gamegoing_ = *gamegoing_ - 50; break;
			case 2:Chassboards.Changename("namemap3.csv"); *gamegoing_ = *gamegoing_ - 50; break;
			case 3:Chassboards.Changename("namemap4.csv"); *gamegoing_ = *gamegoing_ - 50; break;
			case 4:Chassboards.Changename("namemap5.csv"); *gamegoing_ = *gamegoing_ - 50; break;
			case 5:Chassboards.Changename("namemap6.csv"); *gamegoing_ = *gamegoing_ - 50; break;
				//case 5:Chassboards.Changename("namemap6.csv"); break;
			default:
				break;
			}
			if (*m_ < 6){ goto goto2; }
			else
			{
				Gotoxy(35, 7);
				color();
				cout << "哇！你好厉害呀！！！过关啦" << endl;
				Gotoxy(37, 10);
				color();
				cout <<"作者：王子东，王智凯，王天琪，谭永延，臧伟，王晨" << endl;
				break;
			}
		}

	}
	//while(1)
	//cout << "\t游戏进行中!" << endl;
	//grade = length / 8;
	if (score >= (length + (grade - 1) * 8) * 10)//判断是否破记录
	{
		Gotoxy(35, 10);
		color();
		cout << "闯关失败 加油耶!" << endl;
		fclose(fpini);//关闭ini文件
	}
	else
	{
		Gotoxy(35, 10);
		color();
		cout << "恭喜您打破记录!" << endl;
		score = (length + (grade - 1) * 8) * 10;
		writeini(&fpini, &score, argv);//写入ini文件的最高纪录
	}
	Gotoxy(36, 7);
	cout << "按回车键重新开始，按ESC退出游戏" << endl;
	Chassboards.Refresh(map, &grade, &gamespeed, &length - 1, &score);
	while (1)
	{
		while (!kbhit());
		direction = getch();
		if (direction == 13 || direction == 27){//如果输入的不是这两个就循环
			if (direction == 13)//按回车键开始下一局
				goto goto2;
			break;
			if (direction == 27)//按ESC退出游戏
				exit(0); return 0;
		}
		else
		{
			continue;
		}
	}


	
}