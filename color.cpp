#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include"tcs.h"
#include<iostream>
using namespace std;

color::color() {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	}

color::color(int color1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
	}
color::color(int color1, int color2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1 | color2);
	}
color::color(int color1, int color2, int color3) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1 | color2 | color3);
	}