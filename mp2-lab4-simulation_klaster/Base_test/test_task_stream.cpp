#include <gtest.h>
#include "TaskStream.h"

TEST(TasksStream, can_create_tasks_stream)
{
	ASSERT_NO_THROW(TaskStream ts(0.2));
}

TEST(TasksStream, can_create_new_task)
{
	TaskStream ts(0.2);
	ASSERT_NO_THROW(ts.CreateNewTask(1,2,4));
}

TEST(TasksStream, can_determine_create_task_or_no)
{
	TaskStream ts(0.2);
	ASSERT_NO_THROW(ts.IsTask());
}

TEST(TasksStream, can_determine_how_much_task_will_create_on_1_takts_from_1_to_3)
{
	TaskStream ts(0.2);
	ASSERT_NO_THROW(ts.NumTasks());
}

TEST(TasksStream, can_change_end_time_for_task)
{
	TaskStream ts(0.2);
	Task task;
	ASSERT_NO_THROW(ts.ChangeTimeForEndTask(task,3));
}

TEST(TasksStream, cant_create_task_stream_with_intensise_less_than_0)
{
	ASSERT_ANY_THROW(TaskStream ts(-1));
}

TEST(TasksStream, cant_create_task_stream_with_intensise_more_than_1)
{
	ASSERT_ANY_THROW(TaskStream ts(2));
}