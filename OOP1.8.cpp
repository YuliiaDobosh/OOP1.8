#include<iostream>
#include"Bankomat.h"
#include<windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Bankomat b;
	cout << " ������ ������� ������ , ��� �� ������ ����������� " << endl;
	b.Read();
	b.Display();
	Bankomat::Money m;
	m.Init();
	cout << " ������ ������� ������ , ��� �� ������ ����� " << endl;
	m.Read();
	b.getMoney(m);
	cout << " ʳ������ ������ , ��� ���������� " << endl;
	b.Display();
	cout << " ������������ 50 �� 500 " << endl;
	m.Init(50);//����������� ������� ����
	b.insertMoney(m);// ����� ������������
	b.Display();//����

}