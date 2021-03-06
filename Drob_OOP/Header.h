#pragma once

#include <iostream>
#include <Windows.h>
#include <string.h>
#include <conio.h>

using namespace std;


class Drob
{
private:

	int ch;
	int zn;
	int chast; // целая часть

	//ф-кция сокращения дроби
	void NOD();

	//ф-кция проверки знаменателя на 0

	bool CheckZero();	

public:

	//значения дроби по умолчанию, если не заданны оба значения
	Drob() : Drob(0, 1) {};

	//значения дроби по умолчанию, если не задан знаменатель
	Drob(int ch0) : Drob(ch0, 1) {};
	
	//значения дроби получаемое по значению
	Drob(int ch0, int zn0);

	//печать результата операции
	void print();

	//инициализация значений дроби по параметрам
	void Init(int ch0, int zn0);

	//ручной ввод значений дроби
	void HandInit();

	int GetCh();
	int GetZn();

	Drob Sum(Drob d1, Drob d2);
	Drob Diff(Drob d1, Drob d2);
	Drob Mult(Drob d1, Drob d2);
	Drob Div(Drob d1, Drob d2);
};

//-----------------------------------------------------------------------------------------------

void gotoxy(int, int);

void ChangeCursorStatus(bool);
void MenuFun1();
void MenuFun2(); 
void MenuFun3();
void MenuFun4();

void ExitOption(); 
//-----------------------------------------------------------------------------------------------