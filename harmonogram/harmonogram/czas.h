#pragma once
#include <iostream>
#include <locale.h>
#include <Windows.h>

class Czas
{
	int sec, min, hour;
	
	

public:

	void ustawczas();

	void pokazczas();

	Czas(int = 0, int = 0, int = 0);

	Czas& operator+(Czas&);
	Czas& operator+=(int);
	Czas& operator+=(Czas&);
	bool operator==(Czas&);
	bool operator!=(Czas&);
	bool operator<(Czas&);
	bool operator>(Czas&);
	bool operator<=(Czas&);
	bool operator>=(Czas&);

	void odlicz();
	
};
