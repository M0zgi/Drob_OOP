#pragma once

#include <iostream>
#include <Windows.h>
#include <string.h>

using namespace std;

class Drob
{
private:

	int ch;
	int zn;

public:

	//значения дроби по умолчанию
	Drob();

	//значения дроби получаемое по значению
	Drob(int ch0, int zn0);

	//печать вводимой дроби
	void print();

	//деструктор
	~Drob();

	int GetCh();
	int GetZn();
	void SetCh(int ch1);
	void SetZn(int zn1);
};