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

	//�������� ����� �� ���������
	Drob();

	//�������� ����� ���������� �� ��������
	Drob(int ch0, int zn0);

	//������ �������� �����
	void print();

	//����������
	~Drob();

	int GetCh();
	int GetZn();
	void SetCh(int ch1);
	void SetZn(int zn1);
};