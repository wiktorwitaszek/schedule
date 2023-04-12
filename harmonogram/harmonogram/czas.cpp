#include "czas.h"

using namespace std;

void Czas::pokazczas()
{
	cout << "Czas: ";
	if (hour < 10)
		cout << "0" << hour;
	else
		cout << hour;
	cout << ":";
	if (min < 10)
		cout << "0" << min;
	else
		cout << min;
	cout << ":";
	if (sec < 10)
		cout << "0" << sec;
	else
		cout << sec;

	cout << endl;
}

Czas::Czas(int s, int m, int h)
{
	if(hour<0)
	while (s >= 60)
	{
		m++;
		s -= 60;
	}
	while (m >= 60)
	{
		h++;
		m -= 60;
	}

	sec = s;
	min = m;
	hour = h;
}

Czas& Czas::operator+(Czas& c)
{
	Czas temp = c;
	temp.hour += hour;
	temp.min += min;
	temp.sec += sec;

	return temp;
}

Czas& Czas::operator+=(int s)
{
	sec += s;
	while (sec >= 60)
	{
		min++;
		sec -= 60;
	}
	while (min >= 60)
	{
		hour++;
		min -= 60;
	}
	

	return *this;
}

Czas& Czas::operator+=(Czas& c)
{
	sec += c.sec;
	min += c.min;
	hour += c.hour;
	while (sec >= 60)
	{
		min++;
		sec -= 60;
	}
	while (min >= 60)
	{
		hour++;
		min -= 60;
	}


	return *this;
}

bool Czas::operator==(Czas& c)
{
	if (sec == c.sec && min == c.min && hour == c.hour)
		return true;
	else
		return false;
}

bool Czas::operator!=(Czas& c)
{
	if (!(*this==c))
		return false;
	else
		return true;
}

bool Czas::operator<(Czas& c)
{
	if (hour * 3600 + min * 60 + sec < c.hour * 3600 + c.min * 60 + c.sec)
		return true;
	else
		return false;
}

bool Czas::operator>(Czas& c)
{
	if (!(*this<c) && !(*this == c))
		return true;
	else
		return false;
}

bool Czas::operator<=(Czas& c)
{
	if (*this < c || *this==c)
		return true;
	else
		return false;
}

bool Czas::operator>=(Czas& c)
{
	if (*this > c || *this == c)
		return true;
	else
		return false;
}



void Czas::odlicz()
{
	int p;
	p = hour * 3600 + min * 60 + sec;
	for (int i = p; i >= 0; i--)
	{
		pokazczas();
		Sleep(1000);
		system("cls");
		sec--;
		if (sec == -1 && min>-1)
		{
			sec += 60;
			min--;
		}
		if (min == -1 && hour > -1)
		{
			min += 60;
		}

	}
	cout << "Zakoñczono odliczanie" << endl;
}

void Czas::ustawczas()
{
	int h, m, s;
	do
	{
		if (hour < 0 || min < 0 || sec < 0) cout << endl << "Liczba nie mo¿e byæ mniejsza od zera!";
		cout << endl << "Podaj godzinê: ";
		cin >> h;
		cout << endl << "Podaj minutê: ";
		cin >> m;
		cout << endl << "Podaj sekundê: ";
		cin >> s;
		if (h < 0 || m < 0 || s < 0) cout << "Podan¹ z³¹ liczbê!" << endl;
	} while (h < 0 || m < 0 || s < 0);

	while (s >= 60)
	{
		m++;
		s -= 60;
	}
	while (m >= 60)
	{
		h++;
		m -= 60;
	}
	hour = h;
	min = m;
	sec = s;

	
}