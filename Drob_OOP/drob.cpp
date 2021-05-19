#include"Header.h"


void Drob::NOD()
{
	
	Drob a;

	a.ch = ch;
	a.zn = zn;

	if (ch > 0)
	{
		//поиск Нод (только для положительных дробей)
		while (a.ch != a.zn)
		{
			if (a.ch > a.zn)
			{
				int tmp = a.ch;
				a.ch = a.zn;
				a.zn = tmp;
			}
			a.zn = a.zn - a.ch;
		}
		//сокращение дроби по общему наибольшему делителю
		ch /= a.ch;
		zn /= a.zn;
	}

	if (ch < 0)
	{
		a.ch *= -1;
		//поиск Нод (только для отрицательных дробей)
		while (a.ch != a.zn)
		{
			if (a.ch > a.zn)
			{
				int tmp = a.ch;
				a.ch = a.zn;
				a.zn = tmp;
			}
			a.zn = a.zn - a.ch;
		}
		//сокращение дроби по общему наибольшему делителю

		
		ch /= a.ch;
		zn /= a.zn;
		a.ch *= -1;		
	}

	//поиск и выделение целой части дроби для отрицательной дроби
	if (ch < 0)
	{
		ch *= -1;
		if (ch > zn || ch == zn)
		{
			chast = ch / zn;
			ch = ch % zn;
		}

		ch *= -1;		
	}
	//поиск и выделение целой части дроби для положительной дроби

	if (ch > 0)
	{
		if (ch > zn || ch == zn)
		{
			chast = ch / zn;
			ch = ch % zn;
		}
	}
}

Drob::Drob(int ch0, int zn0)
{
	ch = ch0;
	zn = zn0;
}

void Drob::print()
{
	cout << "--------------------------------------------" << endl;

	if (chast > 0 && ch > 0)
	{
		cout << "                                            " << ch << endl;
		cout << "                                  Ответ: " << chast << " ---\n";
		cout << "                                            " << zn;
	}

	else if (chast > 0 && ch < 0)
	{
		cout << "                                             " << ch - (ch * 2)<< endl;
		cout << "                                 Ответ: - " << chast << " ---\n";
		cout << "                                             " << zn;
	}

	else if (chast == 0)
	{
		cout << "                                            " << ch << endl;
		cout << "                                  Ответ: " << chast << " ---\n";
		cout << "                                            " << zn;
	}
		

	else if (ch == 0 && chast > 0)
	{
		cout << "                                  Ответ:  " << chast;
	}
		
	else if (ch == 0)
	{
		cout << "                                            " << ch << endl;
		cout << "                                  Ответ:  " << " ---  = 0\n";
		cout << "                                            " << zn;
	}

	else if (ch < 0)
	{
		cout << "                                            " << ch - (ch * 2) << endl;
		cout << "                                  Ответ: -"  << " ---\n";
		cout << "                                            " << zn;
	}
		
	else if (ch != 0 && zn != 0)
	{

		cout << "                                            " << ch << endl;
		cout << "                                    Ответ: ---\n";
		cout << "                                            " << zn;
	}
}

void Drob::Init(int ch0, int zn0)
{
	ch = ch0;
	zn = zn0;
}

void Drob::HandInit()
{
	cout << "                                            ";
	cin >> ch;
	cout << "                                           ---\n";
	cout << "                                            ";
	cin >> zn;	
}

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

	d.ch = d1.ch * d2.zn + d1.zn * d2.ch;
	d.zn = d1.zn * d2.zn;

	bool checkzn = d.CheckZero();

	if (checkzn)
	{
		d.NOD();
		return d;
	}

	else
	{
		gotoxy(25, 19);
		cout << "На ноль делить нельзя";
		system("pause>null");
		system("cls");
		MenuFun1();
	}
}

Drob Drob::Diff(Drob d1, Drob d2)
{
	return Drob();
}

Drob Drob::Mult(Drob d1, Drob d2)
{
	Drob d;
	d.ch = d1.ch * d2.ch;
	d.zn = d1.zn * d2.zn;
	bool checkzn = d.CheckZero();

	if (checkzn)
	{
		d.NOD();
		return d;
	}

	else
	{
		gotoxy(25, 19);
		cout << "На ноль делить нельзя";
		system("pause>null");
		system("cls");
		MenuFun3();
	}
}

Drob Drob::Div(Drob d1, Drob d2)
{
	Drob d;
	d.ch = d1.ch * d2.zn;
	d.zn = d1.zn * d2.ch;	

	bool checkzn = d.CheckZero();

	if (checkzn)
	{
		d.NOD();
		return d;
	}
	
	else
	{
		gotoxy(25, 19);
		cout << "На ноль делить нельзя";
		system("pause>null");
		system("cls");
		MenuFun4();		
	}	
	
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
