#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include"tcs.h"
#include<iostream>
using namespace std;

//�������һ���������ļ���Ӧ��ini�ļ�, 
readini::readini(FILE **fphead, int *score, char *argv[])
{
	char filename[200], *pfilename= NULL;
	int flag = -1, i;

	strcpy(filename, argv[0]);
	for (i = 0; filename[i] != '\0'; ++i)
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
	for (; filename[i] != '\\'&&i >= 0; --i)pfilename = &filename[i];
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

//��һ���������ļ���Ӧ��ini�ļ�,д����߼�¼
writeini::writeini(FILE **fphead, int *score, char *argv[])
{
	char filename[200], *pfilename=NULL;
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
	for (; filename[i] != '\\'&&i >= 0; i--)pfilename = &filename[i];
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
