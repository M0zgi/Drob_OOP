#include"Header.h"

Drob::Drob(int ch0, int zn0)
{
	ch = ch0;
	zn = zn0;
}

void Drob::print()
{

}

Drob::~Drob()
{
}

int Drob::GetCh()
{
	return ch;
}

int Drob::GetZn()
{
	return zn;
}

void Drob::SetCh(int ch1)
{
	ch = ch1;
}

void Drob::SetZn(int zn1)
{
	zn = zn1;
}
