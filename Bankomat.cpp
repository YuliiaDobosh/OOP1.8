#include "Bankomat.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool Bankomat::Init(int ID_number, Money currentMoney, double max, double min)
{
    if (max > min)
    {
        this->ID_number = ID_number;
        this->currentMoney = currentMoney;
        this->max = max;
        this->min = min;
        return true;
    }
    else
        return false;
}

string Bankomat::toString() const
{
    return  currentMoney.toString();
}

void Bankomat::Display() const
{
    cout << toString() << endl;
}

void Bankomat::Read()
{
    int ID_number;
    int max;
    int min;
    Money currentMoney;
    currentMoney.Read();
    do
    {
        cout << " ¬вед≥ть  ID "; cin >> ID_number;
        cout << " max "; cin >> max;
        cout << " min "; cin >> min;
    } while
        (!Init(ID_number, currentMoney, max, min));
}
void Bankomat::insertMoney(Money m)
{
    currentMoney = doubleToMoney(dod(currentMoney, m));
}
void Bankomat::getMoney(Money i)
{
    if (greatthan(currentMoney, i) && i.sum() >= min && i.sum() <= max)
    {
        currentMoney = doubleToMoney(ded(currentMoney, i));
    }

}
double Bankomat::Money::sum() const
{
	return
		h500 * 500. + h200 * 200. + h100 * 100. + h50 * 50. + h20 * 20. + h10 * 10. + h5 * 5. + h2 * 2. + h1 * 1. + k50 * 0.5 + k25 * 0.25 + k10 * 0.1 + k5 * 0.05 + k2 * 0.02 + k1 * 0.01;
}

Bankomat::Money doubleToMoney(double value)
{
	Bankomat::Money m;

	m.setH500((int)value / 500);
	value -= (int)value / 500 > 0 ? 500 * (int)(value / 500) : 0;

	m.setH200((int)value / 200);
	value -= (int)value / 200 > 0 ? 200 * (int)(value / 200) : 0;

	m.setH100((int)value / 100);
	value -= (int)value / 100 > 0 ? 100 * (int)(value / 100) : 0;

	m.setH50((int)value / 50);
	value -= (int)value / 50 > 0 ? 50 * (int)(value / 50) : 0;

	m.setH20((int)value / 20);
	value -= (int)value / 20 > 0 ? 20 * (int)(value / 20) : 0;

	m.setH10((int)value / 10);
	value -= (int)value / 10 > 0 ? 10 * (int)(value / 10) : 0;

	m.setH5((int)value / 5);
	value -= (int)value / 5 > 0 ? 5 * (int)(value / 5) : 0;

	m.setH2((int)value / 2);
	value -= (int)value / 2 > 0 ? 2 * (int)(value / 2) : 0;

	m.setH1((int)value / 1);
	value -= (int)value / 1 > 0 ? 1 * (int)(value / 1) : 0;

	value *= 100;

	m.setK50((int)value / 50);
	value -= (int)value / 50 > 0 ? 50 * (int)(value / 50) : 0;

	m.setK25((int)value / 25);
	value -= (int)value / 25 > 0 ? 25 * (int)(value / 25) : 0;

	m.setK10((int)value / 10);
	value -= (int)value / 10 > 0 ? 10 * (int)(value / 10) : 0;

	m.setK5((int)value / 5);
	value -= (int)value / 5 > 0 ? 5 * (int)(value / 5) : 0;

	m.setK2((int)value / 2);
	value -= (int)value / 2 > 0 ? 2 * (int)(value / 2) : 0;

	m.setK1((int)value / 1);
	value -= (int)value / 1 > 0 ? 1 * (int)(value / 1) : 0;

	return m;
}

double dod(Bankomat::Money m1, Bankomat::Money m2)
{
	return m1.sum() + m2.sum();
}
double ded(Bankomat::Money m1, Bankomat::Money m2)
{
	return m1.sum() - m2.sum();
}

double div(Bankomat::Money m1, Bankomat::Money m2)
{
	return m1.sum() / m2.sum();
}
double mult(Bankomat::Money m1, Bankomat::Money m2)
{
	return m1.sum() * m2.sum();
}

Bankomat::Money div(Bankomat::Money m, double value)
{
	Bankomat::Money _m;
	double s = m.sum() / value;
	_m = doubleToMoney(s);
	return _m;
}
Bankomat::Money mult(Bankomat::Money m, double value)
{
	Bankomat::Money _m;
	double s = m.sum() * value;
	_m = doubleToMoney(s);
	return _m;
}

void Bankomat::Money::Display() const
{
	cout << toString() << endl;
}

void Bankomat::Money::Read()
{
	int h500, h200, h100, h50, h20, h10, h5, h2, h1, k50, k25, k10, k5, k2, k1;
	do
	{
		cout << " K≥льк≥сть бакнот по 500грн "; cin >> h500;
		cout << " K≥льк≥сть бакнот по 200грн "; cin >> h200;
		cout << " K≥льк≥сть бакнот по 100грн "; cin >> h100;
		cout << " K≥льк≥сть бакнот по 50грн "; cin >> h50;
		cout << " K≥льк≥сть бакнот по 20грн "; cin >> h20;
		cout << " K≥льк≥сть бакнот по 10грн "; cin >> h10;
		cout << " K≥льк≥сть бакнот по 5грн "; cin >> h5;
		cout << " K≥льк≥сть бакнот по 2грн "; cin >> h2;
		cout << " K≥льк≥сть бакнот по 1грн "; cin >> h1;
		cout << " K≥льк≥сть бакнот по 50k "; cin >> k50;
		cout << " K≥льк≥сть бакнот по 25k "; cin >> k25;
		cout << " K≥льк≥сть бакнот по 10k "; cin >> k10;
		cout << " K≥льк≥сть бакнот по 5k "; cin >> k5;
		cout << " K≥льк≥сть бакнот по 2k "; cin >> k2;
		cout << " K≥льк≥сть бакнот по 1k "; cin >> k1;


	} while (!Init(h500, h200, h100, h50, h20, h10, h5, h2, h1, k50, k25, k10, k5, k2, k1));
}

bool Bankomat::Money::Init(int h500, int h200, int h100, int h50, int h20, int h10, int h5, int h2, int h1, int k50, int k25, int k10, int k5, int k2, int k1)
{
	if (h500 < 0 || h200 < 0 || h100 < 0 || h50 < 0 || h20 < 0 || h10 < 0 || h5 < 0 || h2 < 0 || h1 < 0 || k50 < 0 || k25 < 0 || k10 < 0 || k5 < 0 || k2 < 0 || k1 < 0)
		return false;
	setH500(h500);
	setH200(h200);
	setH100(h100);
	setH50(h50);
	setH20(h20);
	setH10(h10);
	setH5(h5);
	setH2(h2);
	setH1(h1);
	setK50(k50);
	setK25(k25);
	setK10(k10);
	setK5(k5);
	setK2(k2);
	setK1(k1);

	return true;
}

string Bankomat::Money::toString() const
{
	double i = sum();
	stringstream sout;
	sout << sum();
	return sout.str();
}

bool lessthan(Bankomat::Money f, Bankomat::Money s)
{
	return f.sum() < s.sum();
}

bool greatthan(Bankomat::Money f, Bankomat::Money s)
{
	return f.sum() > s.sum();
}

bool equal(Bankomat::Money f, Bankomat::Money s)
{
	return f.h500 == s.h500 && f.h200 == s.h200 && f.h100 == s.h100 && f.h50 == s.h50 && f.h20 == s.h20 && f.h10 == s.h10 && f.h5 == s.h5 && f.h2 == s.h2 && f.k50 == s.k50 && f.k25 == s.k25 && f.k10 == s.k10 && f.k5 == s.k5 && f.k2 == s.k2 && f.k1 == s.k1;
}
bool nEqual(Bankomat::Money f, Bankomat::Money s)
{
	return !equal(f, s);
}