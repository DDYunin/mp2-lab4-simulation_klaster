#include "TaskStream.h"

Task TaskStream::CreateNewTask(int _time_app, int _id, int num_proc)
{
    Task ts;
    int duration = rand() % 10 + 1;
    int number_proccesors = rand() % num_proc + 1;
    //int time_exe = duration + _time_app;
    ts.PutAll(_id, _time_app, duration, number_proccesors);
    return ts;
}

bool TaskStream::IsTask()
{
    double probability = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
    if (probability < TaskIntåns)
        return true;
    else
        return false;
}

int TaskStream::NumTasks()
{
    int num = rand() % 3 + 1;
    return num;
}

void TaskStream::ChangeTimeForEndTask(Task& ts, int _index)
{
    ts.DetermineTimeExecutin(_index);
}
