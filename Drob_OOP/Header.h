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

	void print();
	int GetCh();
	int GetZn();
	void SetCh(int ch1);
	void SetZn(int zn1);
};