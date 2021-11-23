#ifndef __KLASTER_H__ 
#define __KLASTER_H__

#include <iostream>
#include <vector>
#include "Queue.h"
#include "Statistics.h"
#include "Task.h"
#include "TaskStream.h"

using namespace std;

class Klaster
{
private:
	int size_time_work;//количество тактов, которое будет работать кластер.
	int number_proc;//число процессоров.
	int q_size;//размер очереди
	vector<bool> ArrayProc;
	Statistics statistic;
	bool IsKlasterFree(int _num_proc);
	void PutTaskInKlaster(Task& ts);
	bool IsDeleteTask(Task& ts, int _now_takt);
	void DeleteTask(Task& ts);
public:
	Klaster(int _num_takts, int _num_proc, int _q_size);
	void Work(double _intensiv);
	void PrintStatistic();
};

#endif 
