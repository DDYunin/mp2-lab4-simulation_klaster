#ifndef __STATISTICS_H__
#define __STATISTICS_H__

#include <iostream>

using namespace std;

struct Statistics
{
	int NumAppearedTasks = 0; //����� ����������� �������
	int NumRejection = 0; //����� ������� ��-�� ������������ �������
	int	NumCompleteTasks = 0; // ����� ����������� �������
	int NumPendingTasks = 0;//����� �������, ������� �������� � �������, �� ���� �������������
	int NumRunningTasks = 0;//����� ������������� �������
	double AvKlasterLoad = 0;//������� �������� �������� - ����� �����������, ������� �������������� �� ������ ����� � ��������� �� ����� ����������� � �� ����� ������
	int NumEmptyTakts = 0;//����� ������ ������� ��������
};

#endif 

