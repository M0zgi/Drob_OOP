#include"Header.h"




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
	cout << "--------------------------------------------" << endl;
	cout << "                                            " << ch << endl;
	cout << "                                    Ответ: ---\n";
	cout << "                                            " << zn;

}

void Drob::Init(int ch0, int zn0)
{
	ch = ch0;
	zn = zn0;
}

void Drob::HandInit()
{
	//cout << "Введите числитель и знаменатель первой дроби\n";
	cout << "                                            ";
	cin >> ch;
	cout << "                                           ---\n";
	cout << "                                            ";
	cin >> zn;
	//cout << "Введите числитель и знаменатель второй дроби\n";

	/*cout << " ";
	cin >> ch;
	cout << "---\n";
	cout << " ";
	cin >> zn;*/
	
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
	Drob d;

	//cout << d1.ch << d1.zn << endl;
	//cout << d2.ch << d2.zn << endl;

	d.ch = d1.ch + 2;
	d.zn = d2.zn + 3;	

	return d;
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
