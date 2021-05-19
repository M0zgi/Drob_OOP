#include"Header.h"

Drob d1;
Drob d2;
Drob d;

/*******************************************
 * Menu using the arrow keys from keyboard *
 *      By: Osama Farah . Amman-Jordan     *
 *         osama_f2005@hotmail.com         *
 *******************************************/




//-----------------------------------------------------------------------------------------------
string* MenuItems() // this function returns a pointer to a string.
{
	string* item = new string[5];
	item[0] = "1. Сложение дробей";
	item[1] = "2. Вычетание дробей";
	item[2] = "3. Умножение дробей";
	item[3] = "4. Деление дробей";
	item[4] = "5. Выход из программы";

	return item;
}
//-----------------------------------------------------------------------------------------------
void gotoxy(int xpos, int ypos)  // just take this function as it is.
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
//-----------------------------------------------------------------------------------------------
void MenuFun1()
{
	system("cls"); //clear the screen.
	
	gotoxy(25, 9);
	cout << "Сложение дробей\n";

	gotoxy(25, 10);	
	cout << "Введите числитель и знаменатель первой дроби\n";
	
	d1.HandInit();
	
	gotoxy(25, 15);
	cout << "Введите числитель и знаменатель второй дроби\n";
	
	d2.HandInit();
	
	d = d.Sum(d1, d2);
	
	gotoxy(25, 19);
	
	d.print();

	_getch(); 
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void MenuFun2()
{
	system("cls"); //clear the screen.

	gotoxy(25, 9);
	cout << "Вычетание дробей\n";

	gotoxy(25, 10);
	cout << "Введите числитель и знаменатель первой дроби\n";

	d1.HandInit();

	gotoxy(25, 15);
	cout << "Введите числитель и знаменатель второй дроби\n";

	d2.HandInit();

	d = d.Diff(d1, d2);

	gotoxy(25, 19);

	d.print();

	_getch();
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void MenuFun3()
{
	system("cls");
	gotoxy(25, 9);
	cout << "Умножение дробей\n";
	gotoxy(25, 10);

	cout << "Введите числитель и знаменатель первой дроби\n";

	d1.HandInit();
	gotoxy(25, 15);
	cout << "Введите числитель и знаменатель второй дроби\n";
	d2.HandInit();

	d = d.Mult(d1, d2);
	gotoxy(25, 19);

	d.print();

	_getch();
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void MenuFun4()
{
	system("cls");
	gotoxy(25, 9);
	cout << "Деление дробей\n";
	gotoxy(25, 10);

	cout << "Введите числитель и знаменатель первой дроби\n";

	d1.HandInit();
	gotoxy(25, 15);
	cout << "Введите числитель и знаменатель второй дроби\n";
	d2.HandInit();

	d = d.Div(d1, d2);
	gotoxy(25, 19);

	d.print();

	_getch();
	system("cls");
}
//-----------------------------------------------------------------------------------------------
void ExitOption()
{
	gotoxy(30, 15);
	cout << "Exitting..." << endl;
	_getch();
	exit(0);
}
//-----------------------------------------------------------------------------------------------
void ChangeCursorStatus(bool Visible)
{
	CONSOLE_CURSOR_INFO* c = new CONSOLE_CURSOR_INFO;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	if (Visible)
	{
		c->bVisible = TRUE;
		c->dwSize = 0;
	}
	else
	{
		c->bVisible = FALSE;
		c->dwSize = 1;
	}

	SetConsoleCursorInfo(h, c);
}
//-----------------------------------------------------------------------------------------------
