#ifndef _TCS_H
#define _TCS_H
#define MAPX 33
#define MAPY 35
#include<windows.h>
#include<iostream>
#include<time.h>
#include<conio.h>
#include<sstream>
#include<fstream>
#include<string.h>
using namespace std;


class  readini
{
private:

public:
	readini();
	readini(FILE**, int*, char*[]);
};
class  writeini
{
private:

public:
	writeini();
	writeini(FILE**, int*, char*[]);
};
class color 
{
public:
	color();
	color(int );
	color(int , int );
	color(int , int , int );
private:
	string color1;
	string color2;
	string color3;
};

class Chessboard {
public:
	void Refresh(int map[MAPX][MAPY], int* , int* , int* , int* );
	void Changename(string name);
private:
	color Color1;
	string name;
};
class Gotoxy {
public:
	Gotoxy(int, int);
private:

};
#endif