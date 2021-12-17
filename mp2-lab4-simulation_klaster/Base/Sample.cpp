#include <iostream>
#include <vector>
#include "Queue.h"
#include "Klaster.h"
#include "Statistics.h"
#include "Task.h"
#include "TaskStream.h"

using namespace std;

int main() 
{
	setlocale(LC_ALL, "Rus");
	bool flag_exit = false;
	int choice_menu;
	while (!flag_exit)
	{
		cout << "\n\t����� ����������!\n1) ������� \"1\" ���� ������ ��������������� ������ �������� � ������� ���������� ������\n2) ������� \"0\" ���� ������ ��������� ������ ��������� " << endl;
		cin >> choice_menu;
		if (choice_menu == 1)
		{
			int T, k, s;
			double q1;
			cout << "������� ���������� ������ ������ �������� (� ��������� �� 10 �� 1000) "; // 10 - 1000
			cin >> T;
			cout << "������� ���������� ����������� � �������� (� ��������� �� 1 �� 64) "; // 1 - 64
			cin >> k;
			cout << "������� ������ ������� �������� ������� (� ��������� �� 5 �� 50) "; // 5 - 50
			cin >> s;
			cout << "������� ������� ��������� ������� (� ��������� �� 0 �� 1) "; // 0 - 1
			cin >> q1;
			cout << endl;
			Klaster	kls(T, k, s);
			kls.Work(q1);
			kls.PrintStatistic();
			system("pause");
			system("cls");
		}
		else if (choice_menu == 0)
		{
			flag_exit = true;
			cout << "�� ��������!" << endl;
		}
	}
	return 0;
}