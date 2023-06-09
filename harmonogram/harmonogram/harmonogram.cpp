#include "harmonogram.h"

using namespace std;

Harmonogram::Harmonogram(int n)
{
	number = n;
	tab = nullptr;
}

void Harmonogram::add(Czas& arg)
{
	Czas* temp;
	temp = new Czas[number + 1];
	for (int i = 0; i < number; i++)
	{
		temp[i] = tab[i];
	}
	temp[number] = arg;
	delete[] tab;
	tab = temp;
	number++;
}

void Harmonogram::show()
{
	for (int i = 0; i < number; i++)
	{
		tab[i].pokazczas();
	}
}

Czas Harmonogram::sum()
{
	Czas temp = NULL;
	for (int i =0; i<number;i++)
	{
		temp += tab[i];
	}
	return temp;
}


Czas& Harmonogram::operator[](int n) {
	Czas temp = NULL;
	if (n > number || n < 0)
	{
		return temp;
	}
	return tab[n];
}

const Czas& Harmonogram::operator[](int n) const {
	Czas temp = NULL;
	if (n > number || n < 0)
	{
		return temp;
	}
	return tab[n];
}

Harmonogram::Harmonogram(const Harmonogram& _inny) {
	number = _inny.number; 
	tab = new Czas[number]; 
	for (int i = 0; i < number; i++) {
		tab[i] = _inny.tab[i];
	}
}

int Harmonogram::GetNumber() {
	return number;
}


	