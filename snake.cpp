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
//�������

/*void Readini(FILE** fphead, int* score, char* argv[]) //�������һ���������ļ���Ӧ��ini�ļ�,��ȡ��߼�¼
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
			printf("�޷��������\"%s\"�ļ�\n", pfilename);
			system("pause");
			exit(0);
		}
	}
	else
	{
		fread(score, sizeof(int), 1, *fphead);
	}
}

void Writeini(FILE** fphead, int* score, char* argv[])  //��һ���������ļ���Ӧ��ini�ļ�,д����߼�¼
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
		printf("�޷�д��\"%s\"�ļ�������д����!\n", pfilename);
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
Gotoxy::Gotoxy(int x, int y)//��궨λ,��궨λ����SetConsoleCursorPosition�����Ͻ�λ����0,0Ȼ��������������
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
	void Refresh(int map[33][35], int grade, int gamespeed, int length, int score) //  ���̰��������
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
			case 1: cout << "\t					�ȼ�Ϊ��" << grade; break;//��ʾ�ȼ�
			case 3: cout << "\t					�Զ�ǰ��ʱ��"; break;
			case 4: cout << "\t					���Ϊ��" << gamespeed << "ms"; break;//��ʾʱ��
			case 6: cout << "\t					��ʷ��߷�Ϊ:" << score << "��"; break;
			case 7: cout << "\t					�����ڵ÷�Ϊ:" << (length + (grade - 1) * 8) * 10 << "��"; break;
			case 8: cout << "\t					**********************"; break;
			case 9: cout << "\t					��Ϸ˵����"; break;
			case 10: cout << "\t					(1)��wasd����"; break;
			case 11: cout << "\t					��ͷ�˶�����;"; break;
			case 12: cout << "\t					(2)��ÿ��һ����������"; break;
			case 13: cout << "\t					����һ��;"; break;
			case 14: cout << "\t					(3)��ҧ���Լ�������ǽ"; break;
			case 15: cout << "\t					����Ϸ������"; break;
			case 18: cout << "\t					**********************"; break;
			case 19: cout << "\t					C/C++������ҵ��"; break;
			}
		}
		
		ifstream inFile(name, ios::in);
		if (!inFile)
		{
			cout << "���ļ�ʧ�ܣ�" << endl;
			exit(1);
		}
		i = 0;
		string line;
		string field;
		while (getline(inFile, line))//getline(inFile, line)��ʾ���ж�ȡCSV�ļ��е�����
		{
			string field;
			istringstream sin(line); //�������ַ���line���뵽�ַ�����sin��
			for (int j = 0; j < 35; j++) {
				getline(sin, field, ','); //���ַ�����sin�е��ַ����뵽field�ַ����У��Զ���Ϊ�ָ��� 
				map[i][j] = atoi(field.c_str());
			}
			i++;
		}
		inFile.close();
		map[0][0] = 111;
		for (i = 0; i < 33; i++) {
			for (j = 0; j < 35; j++) {
				if (map[i][j] == 111)//�������ǽ��
				{
					Gotoxy(i, j);
					color(FOREGROUND_GREEN, FOREGROUND_RED);
					cout << "��";
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
	srand(time(0));//�����������
	do
	{
		x = rand() % (MAPX-2) + 1;
		y = rand() % (MAPY-2) + 1;
		
	} while (map[x][y] % 10 == (1 || 3));//��������ڿհ״����³�����
	map[x][y] = 102;
	Gotoxy(x, y);
	color(FOREGROUND_GREEN);
	cout << "��";
	*length += 1;

}

void move(int map[MAPX][MAPY], int* tailx, int* taily, int* headx, int* heady, char* direction, int* gamegoing, int* length, int* gamespeed) {
	int tailxtemp = *tailx, tailytemp = *taily;
	int headxtemp = *headx, headytemp = *heady;
	int guonum=0;
	//ͷ�ƶ�
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
	//�������  
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

		goto goto1;break;//�Ե���ʵ����ȥβ����
	}
	case 1:*gamegoing = 0; break;//ײǽ
	case 3:*gamegoing = 0; break;
	default:break;
	}
	

	//����β��
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
	cout << "��";
	Gotoxy(headxtemp, headytemp);
	color(FOREGROUND_RED);
	cout << "��";
}

void full_screen()
{
	HWND hwnd = GetForegroundWindow();
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);   /* ��׼������������ */
	int cx = GetSystemMetrics(SM_CXSCREEN);            /* ��Ļ��� */
	int cy = GetSystemMetrics(SM_CYSCREEN);            /* ��Ļ�߶� */

	
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
	system("cls");//�����Ļ
	
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
	int map[MAPX][MAPY];     //  ̰����������һ����ά����(��22*22������ǽ��)
	color(FOREGROUND_GREEN);
	for (int p = 0; p < 40; ++p)cout << "��ͼ������.....................��ͼ������......................��ͼ������..........��ͼ������......................��ͼ������..........��ͼ������......................��ͼ������..........��ͼ������......................��ͼ������..........��ͼ������......................��ͼ������.........." << endl;
	full_screen();

	FILE* fpini;//*fpini ��Ϣ�ļ�
	readini(&fpini, &score, argv);//��ȡini�ļ�����߼�¼
	if (score < 0)//��߳ɼ�С��������Ϊ�㣬�����ļ����Ǹ���
		score = 0;
	Chassboards.Refresh(map, &grade, &gamespeed, &length, &score);
	//��ʼ����
	map[1][2] = 113;
	map[1][3] = 113;
	map[1][4] = 113;
	map[1][5] = 113;
	tailx = 1; taily = 2;
	headx = 1; heady = 5;
	Gotoxy(tailx, taily);
	color(FOREGROUND_RED);
	cout << "����";
	color(FOREGROUND_GREEN, FOREGROUND_RED);
	cout << "��";
	makefood(map, length_);
	Gotoxy(35, 8);
	color();
	cout << "\t ��Ϸ������!" << endl;
	while (1) {
		Gotoxy(36, 8);
		color();
		cout << "\t���Ϊ��" << *gamespeed_ << "ms";
		start = clock();
		while ((timeover = ((starttemp = clock()) - start <= gamespeed)) && !kbhit());//����м����»�ʱ�䳬���Զ�ǰ��ʱ��������ֹѭ��
		if (direction == 'w' || direction == 'a' || direction == 's' || direction == 'd')//��ֹ��������
			directiontemp = direction;//������һ�η��򰴼�
		while (kbhit())
		{
			if (timeover)
			{
				direction = getch();
			}
			if (!(direction == 'w' || direction == 'a' || direction == 's' || direction == 'd'))
			{
				direction = directiontemp;//�жϷ�����Ч//  �����Ƿ������otherkey����Ϊ0
			}
			else
			{
				if (fabs(float(direction) - float(directiontemp)) == 3 || fabs(float(direction) - float(directiontemp)) == 4)
					direction = directiontemp;//�жϷ�����Ч
			}


		}
		while ((timeover = ((starttemp = clock()) - start <= gamespeed)));

		if (gamegoing)//�ƶ�һ��
			move(map, tailx_, taily_, headx_, heady_, direction_, gamegoing_, length_, gamespeed_);
		else break;
		if (length > 6) {
			*m_ = *m_ + 1;
			Gotoxy(35, 7);
			cout << "��ϲ������һ��";
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
				cout << "�ۣ��������ѽ������������" << endl;
				Gotoxy(37, 10);
				color();
				cout <<"���ߣ����Ӷ������ǿ�����������̷���ӣ��ΰ������" << endl;
				break;
			}
		}

	}
	//while(1)
	//cout << "\t��Ϸ������!" << endl;
	//grade = length / 8;
	if (score >= (length + (grade - 1) * 8) * 10)//�ж��Ƿ��Ƽ�¼
	{
		Gotoxy(35, 10);
		color();
		cout << "����ʧ�� ����Ү!" << endl;
		fclose(fpini);//�ر�ini�ļ�
	}
	else
	{
		Gotoxy(35, 10);
		color();
		cout << "��ϲ�����Ƽ�¼!" << endl;
		score = (length + (grade - 1) * 8) * 10;
		writeini(&fpini, &score, argv);//д��ini�ļ�����߼�¼
	}
	Gotoxy(36, 7);
	cout << "���س������¿�ʼ����ESC�˳���Ϸ" << endl;
	Chassboards.Refresh(map, &grade, &gamespeed, &length - 1, &score);
	while (1)
	{
		while (!kbhit());
		direction = getch();
		if (direction == 13 || direction == 27){//�������Ĳ�����������ѭ��
			if (direction == 13)//���س�����ʼ��һ��
				goto goto2;
			break;
			if (direction == 27)//��ESC�˳���Ϸ
				exit(0); return 0;
		}
		else
		{
			continue;
		}
	}


	
}