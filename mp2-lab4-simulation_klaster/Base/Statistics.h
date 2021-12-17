#ifndef __STATISTICS_H__
#define __STATISTICS_H__

#include <iostream>

using namespace std;

struct Statistics
{
	int NumAppearedTasks = 0; //число появившихся заданий
	int NumRejection = 0; //число отказов из-за переполнения очереди
	int	NumCompleteTasks = 0; // число выполненных заданий
	int NumPendingTasks = 0;//число заданий, которое осталось в очереди, то есть невыполнеными
	int NumRunningTasks = 0;//число выполняющихся заданий
	double AvKlasterLoad = 0;//средняя загрузка кластера - сумма процессоров, которое использовалось на каждом такте и разделить на число процессоров и на число тактов
	int NumEmptyTakts = 0;//число тактов простоя кластера
};

#endif 

