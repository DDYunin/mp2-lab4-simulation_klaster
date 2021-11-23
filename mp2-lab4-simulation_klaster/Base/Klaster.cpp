#include "Klaster.h"

bool Klaster::IsKlasterFree(int _num_proc)
{
	//�� 0 �� 63
	int numfreeproc = 0;
	for (int i = 0; i < number_proc; i++)
		if (ArrayProc[i] == true)
			numfreeproc++;
	if (numfreeproc >= _num_proc)
		return true;
	return false;
}

void Klaster::PutTaskInKlaster(Task& ts)
{
	int num_remained_proc = ts.num_proc_for_work;
	for (int i = 0; i < number_proc; i++)
	{
		if (ArrayProc[i] == true)
		{
			ts.ArrIndex.push_back(i);
			ArrayProc[i] = false;
			num_remained_proc--;
		}
		if (num_remained_proc == 0)
			break;
	}
}

bool Klaster::IsDeleteTask(Task& ts, int _now_takt)
{
	if (_now_takt == ts.time_execution)
		return true;
	return false;
}

void Klaster::DeleteTask(Task& ts)
{
	for (int i = 0; i < number_proc; i++) 
	{
		for (int j = 0; j < ts.ArrIndex.size(); j++)
			if (i == ts.ArrIndex[j])
				ArrayProc[i] = true;
	}
}

Klaster::Klaster(int _num_takts, int _num_proc, int _q_size)
{
	if ((_num_takts < 10) || (_num_takts > 1000) || (_num_proc < 1) || (_num_proc > 64) || (_q_size < 5) || (_q_size > 50))
		throw "Error! Uncorrect data!";
	size_time_work = _num_takts;
	number_proc = _num_proc;
	q_size = _q_size;
	for (int i = 0; i < number_proc; i++)
		ArrayProc.push_back(true);//true - ��������
	
}

void Klaster::Work(double _intensiv)
{
	TaskStream task_manager(_intensiv);
	int task_id = 1;
	long sum = 0;
	int num_tasks = 0;
	bool IsWork = false;
	Task temp_task;
	vector<Task> v_for_com_tasks;//������, ����� �������������� ����������� �������.
	TQueue<Task> que(q_size);//������� ��� �������� ������, ����� ����� �� ������� �� ����������
	for (int i = 1; i <= size_time_work; i++)
	{
		if (task_manager.IsTask())
		{
			num_tasks = task_manager.NumTasks();
			//cout << "����� ������� = " << num_tasks << endl;
			int l = 0;
			while (l < num_tasks)
			{
				temp_task = task_manager.CreateNewTask(i, task_id, number_proc);
				task_id++;
				if (!(que.Full()))
					que.Push(temp_task);
				else
					statistic.NumRejection++;
				statistic.NumAppearedTasks++;
				l++;
			}
		}
		vector<bool> v_for_exit_loop(v_for_com_tasks.size());
		for (int j = 0; j < v_for_com_tasks.size(); j++)
			v_for_exit_loop[j] = true;
		bool flag = false;//���� �� ��������
		while (1)
		{
			for (int j = 0; j < v_for_com_tasks.size(); j++)
			{
				if (IsDeleteTask(v_for_com_tasks[j], i))
				{
					DeleteTask(v_for_com_tasks[j]);
					statistic.NumCompleteTasks++;
					v_for_com_tasks.erase(v_for_com_tasks.begin() + j);
					v_for_exit_loop.erase(v_for_exit_loop.begin() + j);
					break;
				}
				else
					v_for_exit_loop[j] = false;
			}
			int k = 0;
			for (int j = 0; j < v_for_exit_loop.size(); j++)
				if (v_for_exit_loop[j] == true)
					k++;
			if (k == 0)
				flag = true;
			if ((v_for_com_tasks.empty()) || (flag))
				break;
		}
		while (1)
		{
			if ((IsKlasterFree(que.Front().num_proc_for_work)) && (!que.Empty()))
			{
				PutTaskInKlaster(que.Front());//������ ������� �� ����������, �� ��� ��������� �� ����� ����������� ����������� ������?
				task_manager.ChangeTimeForEndTask(que.Front(), i);
				v_for_com_tasks.push_back(que.Front());//��������� ������� � �������, ��� �������� ����������
				que.Pop();//������� ��� �� ������� 
			}
			else
			{
				break;
			}
		}
		
		//��������� ���������� �������
		for (int j = 0; j < number_proc; j++)
			if (ArrayProc[j] == false) 
			{
				sum++;
				IsWork = true;
			}
		if (!IsWork)
			statistic.NumEmptyTakts++;
		IsWork = false;
		//������� �� ��������� ���. �������� ���������
		//���������� ���� ����� �� ��������
		//��: ������ ������ ����������� � ��������� � ��������� ��������
		//���: ��������� � ���������� ����
	}
	while (!(que.Empty()))
	{
		statistic.NumPendingTasks++;
		que.Pop();
	}
	statistic.AvKlasterLoad = (double)sum / (double)number_proc / (double)size_time_work;
	statistic.NumRunningTasks = v_for_com_tasks.size();
}

void Klaster::PrintStatistic()
{
	cout << "\n���������� ������ ��������\n";
	cout << "1) ����� ����������� ������� = " << statistic.NumAppearedTasks << endl;
	cout << "2) ����� ������� (��-�� ������������ �������) = " << statistic.NumRejection << endl;
	cout << "3) ����� ����������� ������� = " << statistic.NumCompleteTasks << endl;
	cout << "4) ����� �������, ���������� ������� = " << statistic.NumPendingTasks << endl;
	cout << "5) ����� ������������� ������� = " << statistic.NumRunningTasks << endl;
	cout << "6) ������� �������� �������� = " << statistic.AvKlasterLoad << endl;
	cout << "7) ����� ������ ������� �������� = " << statistic.NumEmptyTakts << endl;
}

