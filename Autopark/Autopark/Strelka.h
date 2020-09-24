#pragma once 
#include <iostream>
#include <Windows.h>
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS


 inline void SetPos(COORD dwCursorPosition) {// функция для установки позиции каретки по координатам
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), dwCursorPosition);
}
inline void SetPos(int x, int y) {
	COORD cd;
	cd.X = x;
	cd.Y = y;
	SetPos(cd);
}
inline void showArrow(int pos)
{
	for (int i = 0; i < 6; i++)
	{
		SetPos(0, i + 1);
		std::cout << "   ";
	}
	SetPos(0, pos);
	std::cout << ">>>";
}