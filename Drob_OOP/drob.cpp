#include"Header.h"

Drob d;
Drob d1;
Drob d2;

void Drob::NOD()
{

}

Drob::Drob(int ch0, int zn0)
{
	ch = ch0;
	zn = zn0;
}

void Drob::print()
{

}

void Drob::Init(int ch0, int zn0)
{
	ch = ch0;
	zn = zn0;
}

void Drob::HandInit()
{
	cout << "Введите числитель и знаменатель первой дроби\n";
	cout << " ";
	cin >> d1.ch;
	cout << "---\n";
	cout << " ";
	cin >> d1.zn;

	cout << "Введите числитель и знаменатель второй дроби\n";

	cout << " ";
	cin >> d2.ch;
	cout << "---\n";
	cout << " ";
	cin >> d2.zn;
}

//Drob::~Drob()
//{
//}

int Drob::GetCh()
{
	return ch;
}

int Drob::GetZn()
{
	return zn;
}

Drob Drob::Sum(Drob d1, Drob d2)
{
	return Drob();
}

Drob Drob::Diff(Drob d1, Drob d2)
{
	return Drob();
}

Drob Drob::Mult(Drob d1, Drob d2)
{
	return Drob();
}

Drob Drob::Div(Drob d1, Drob d2)
{
	return Drob();
}

//void Drob::SetCh(int ch1)
//{
//	ch = ch1;
//}
//
//void Drob::SetZn(int zn1)
//{
//	zn = zn1;
//}
