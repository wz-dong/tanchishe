#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include"tcs.h"
#include<iostream>
using namespace std;
void Chessboard::Refresh(int map[MAPX][MAPY], int *grade, int *gamespeed, int *length, int *score) //  ���̰��������
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
			case 1: cout << "\t�ȼ�Ϊ��" << *grade; break;//��ʾ�ȼ�
			//case 3: cout << "\t�Զ�ǰ��ʱ��"; break;
			//case 4: cout << "\t���Ϊ��" << *gamespeed << "ms"; break;//��ʾʱ��
			case 6: cout << "\t��ʷ��߷�Ϊ:" << *score << "��"; break;
			case 7: cout << "\t�����ڵ÷�Ϊ:" << (*length + (*grade - 1) * 8) * 10 << "��"; break;
			case 8: cout << "\t**********************"; break;
			case 9: cout << "\t��Ϸ˵����"; break;
			case 10: cout << "\t(1)��wasd����"; break;
			case 11: cout << "\t��ͷ�˶�����;"; break;
			case 12: cout << "\t(2)��ÿ��һ����������"; break;
			case 13: cout << "\t����һ��;"; break;
			case 14: cout << "\t(3)��ҧ���Լ�������ǽ"; break;
			case 15: cout << "\t����Ϸ������"; break;
			case 18: cout << "\t**********************"; break;
			case 19: cout << "\tC++������ҵ��"; break;
			case 20:cout << "С���Ա�����Ӷ������ǿ�����������̷���ӣ��ΰ������"; break;
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
			for (int j = 0; j < MAPY; j++) {
				getline(sin, field, ','); //���ַ�����sin�е��ַ����뵽field�ַ����У��Զ���Ϊ�ָ��� 
				map[i][j] = atoi(field.c_str());
			}
			i++;
		}
		inFile.close();
		map[0][0] = 111;
		for (i = 0; i < MAPX; i++) {
			for (j = 0; j < MAPY; j++) {
				if (map[i][j] == 111)//�������ǽ��
				{
					Gotoxy(i, j);
					color(FOREGROUND_GREEN, FOREGROUND_RED);
					cout << "��";
				}
			}
		}
}; 
void Chessboard::Changename(string name) {
	this->name = name;
}