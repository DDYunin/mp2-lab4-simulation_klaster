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
		cout << "\n\tДобро пожаловать!\n1) Введите \"1\" если хотите просимулировать работу кластера и вывести статистику работы\n2) Введите \"0\" если хотите завершить работы программы " << endl;
		cin >> choice_menu;
		if (choice_menu == 1)
		{
			int T, k, s;
			double q1;
			cout << "Введите количсетво тактов работы кластера (в диапазоне от 10 до 1000) "; // 10 - 1000
			cin >> T;
			cout << "Введите количество процессоров в кластере (в диапазоне от 1 до 64) "; // 1 - 64
			cin >> k;
			cout << "Введите размер очереди хранения заданий (в диапазоне от 5 до 50) "; // 5 - 50
			cin >> s;
			cout << "Введите частоту появления заданий (в диапазоне от 0 до 1) "; // 0 - 1
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
			cout << "До свидания!" << endl;
		}
	}
	return 0;
}