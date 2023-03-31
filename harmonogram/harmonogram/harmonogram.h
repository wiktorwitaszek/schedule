#pragma once
#include <iostream>
#include <locale.h>
#include "czas.h"

class Harmonogram
{
	int number;
	Czas* tab;

	friend Harmonogram copybytime(Harmonogram& _copy);
	friend Harmonogram copybynumber(const Harmonogram& _copy);
	
public:

	Harmonogram(int = 0);
	void add(Czas&);
	void show();
	Czas sum();
	int GetNumber();
	const Harmonogram(const Harmonogram& _inny);
	Harmonogram& operator=(const Harmonogram& _str) = delete;

	const Czas& operator[](int n) const;
	Czas& operator[](int n);
	
	
}; 