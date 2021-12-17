#ifndef __TASK_H__
#define __TASK_H__

#include <iostream>
#include <vector>

using namespace std;

struct Task
{
	int task_id;//id - �������
	int time_appearance;//����� ���������
	int time_start_of_ex;//����� ���������� � ������
	int duration;//������������
	int time_execution;//����� ����������
	int num_proc_for_work;//����� ����������� ��� ������
	vector<int> ArrIndex;

	Task()
	{
		task_id = 0;
		time_appearance = 0;
		duration = 0;
		time_execution = 0;
		num_proc_for_work = 0;
		time_start_of_ex = 0;
	}

	void PutAll(int _task_id, int _time_appearence, int _duration, int _num_proc_for_work)
	{
		task_id = _task_id;
		time_appearance = _time_appearence;
		duration = _duration;
		num_proc_for_work = _num_proc_for_work;
	}

	void DetermineTimeExecutin(int _time_start_of_execution)
	{
		time_start_of_ex = _time_start_of_execution;
		time_execution = duration + time_start_of_ex;
	}
};

#endif 

