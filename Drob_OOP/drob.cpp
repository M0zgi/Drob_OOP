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

bool Drob::CheckZero()
{	
		if (zn == 0)
			return false;

		if (zn != 0)
			return true;		
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

	else if (ch == 0 && zn == 0 && chast == 0)
	{

		
		cout << "             В результате операции знаментатель дроби равен 0. На ноль делить нельзя";
		
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
		d.ch = 0;
		d.zn = 0;
		d.chast = 0;
		return d;
	}
}

Drob Drob::Diff(Drob d1, Drob d2)
{
	Drob c;

	//Вычитание дробей с одинаковыми знаменателями

	if (d1.zn == d2.zn && d1.ch != d2.ch)
	{
		c.ch = d1.ch - d2.ch;
		c.zn = d1.zn;
		bool checkzn = c.CheckZero();

		if (checkzn)
		{
			c.NOD();
			return c;
		}

		else
		{
			c.ch = 0;
			c.zn = 0;
			c.chast = 0;
			return c;
		}
	}

	//вычитания смешанных чисел с большим числителем первого числа и большим знаменателем
	else if (d1.zn > d2.zn && d1.ch > d2.ch)
	{
		//нужно привести к общему знаменателю дробные части
		//рассчитываем наименьшее общее кратное (НОК)
		//НОК = a.zn * b.zn / НОД (m, n)
		Drob m, n;
		m.zn = d1.zn;
		n.zn = d2.zn;

		while (m.zn != n.zn)
		{
			if (m.zn > n.zn)
			{
				int tmp = m.zn;
				m.zn = n.zn;
				n.zn = tmp;
			}
			n.zn = n.zn - m.zn;
		}

		c.zn = d1.zn * d2.zn / n.zn;
		c.ch = d1.ch - d2.ch;

		bool checkzn = c.CheckZero();

		if (checkzn)
		{
			c.NOD();
			return c;
		}

		else
		{
			c.ch = 0;
			c.zn = 0;
			c.chast = 0;
			return c;
		}
	}

	//вычитания дроби с одинаковым числителем и разным знаменателем
	else if (d1.ch == d2.ch && d1.zn != d2.zn)
	{
		d1.ch *= d2.zn;
		d2.ch *= d1.zn;
		c.ch = d1.ch - d2.ch;
		c.zn = d1.zn * d2.zn;

		bool checkzn = c.CheckZero();

		if (checkzn)
		{
			c.NOD();
			return c;
		}

		else
		{
			c.ch = 0;
			c.zn = 0;
			c.chast = 0;
			return c;
		}
	}

	//Вычитание дробей с разными знаменателями и разными числителями

	else if (d1.zn != d2.zn && d1.ch < d2.ch || d1.zn < d2.zn && d1.ch > d2.ch || d1.zn > d2.zn && d1.ch > d2.ch)
	{
		d1.ch *= d2.zn;
		d2.ch *= d1.zn;
		int tmp;
		tmp = d1.zn;
		d1.zn *= d2.zn;
		d2.zn *= tmp;
		c.ch = d1.ch - d2.ch;
		c.zn = d1.zn;
		bool checkzn = c.CheckZero();

		if (checkzn)
		{
			c.NOD();
			return c;
		}

		else
		{
			c.ch = 0;
			c.zn = 0;
			c.chast = 0;
			return c;
		}
	}

	//Вычитание дробей с одинаковыми знаменателями и числителями, ответ будет 0
	else if (d1.zn == d2.zn && d1.ch == d2.ch)
	{
		c.zn = d2.zn;
		c.ch = d1.ch - d2.ch;
		c.chast = (d1.ch - d2.ch) / d2.zn;
		bool checkzn = c.CheckZero();

		if (checkzn)
		{
			c.NOD();
			return c;
		}

		else
		{
			c.ch = 0;
			c.zn = 0;
			c.chast = 0;
			return c;
		}
	}
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
		d.ch = 0;
		d.zn = 0;
		d.chast = 0;
		return d;
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
		d.ch = 0;
		d.zn = 0;
		d.chast = 0;
		return d;
	}
	
}