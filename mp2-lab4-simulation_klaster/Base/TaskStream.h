#ifndef __TASKSTREAM_H__
#define __TASKSTREAM_H__

#include <iostream>
#include "Task.h"
#include <cstdlib>
#include <ctime> 

using namespace std;

class TaskStream
{
private:
	double TaskIntåns; // èíòåíñèâíîñòü ïîòîêà çàäà÷
public:
	TaskStream(double _TaskIntens) 
	{
		if (_TaskIntens > 1 || _TaskIntens < 0)
			throw "Error! Uncorrect data!";
		TaskIntåns = _TaskIntens;
		srand(static_cast<unsigned int>(time(0))); 
	}
	Task CreateNewTask(int _time_app, int _id, int num_proc);
	bool IsTask();
	int NumTasks();
	void ChangeTimeForEndTask(Task& ts, int _index);
};


#endif 

