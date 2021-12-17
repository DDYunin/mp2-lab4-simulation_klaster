#include <gtest.h>
#include "Queue.h"

TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue<int> q(3));
}

TEST(TQueue, cant_create_queue_with_negative)
{
	ASSERT_ANY_THROW(TQueue<int> q(-3));
}

TEST(TQueue, cant_create_queue_with_too_much_size)
{
	ASSERT_ANY_THROW(TQueue<int> q(-3));
}

TEST(TQueue, true_if_queue_is_empty)
{
	TQueue<int> q(3);
	EXPECT_EQ(true, q.Empty());
}

TEST(TQueue, true_if_queue_is_full)
{
	TQueue<int> q(2);
	q.Push(2);
	q.Push(3);
	EXPECT_EQ(true, q.Full());
}

TEST(TQueue, false_if_queue_is_un_empty)
{
	TQueue<int> q(3);
	q.Push(2);
	EXPECT_EQ(false, q.Empty());
}

TEST(TQueue, false_if_queue_isnt_full)
{
	TQueue<int> q(3);
	q.Push(5);
	EXPECT_EQ(false, q.Full());
}

TEST(TQueue, can_get_queue_size)
{
	TQueue<int> q(3);
	ASSERT_NO_THROW(q.GetSizeQueue());
}

TEST(TQueue, can_get_queue_data_count)
{
	TQueue<int> q(3);
	ASSERT_NO_THROW(q.GetCountData());
}

TEST(TQueue, get_correct_queue_size)
{
	TQueue<int> q(3);
	EXPECT_EQ(3, q.GetSizeQueue());
}

TEST(TQueue, get_correct_queue_data_count)
{
	TQueue<int> q(3);
	q.Push(6);
	ASSERT_NO_THROW(1, q.GetCountData());
}

TEST(TQueue, can_print_queue)
{
	TQueue<int> q(3);
	q.Push(3);
	ASSERT_NO_THROW(q.PrintQueue());
}

TEST(TQueue, throws_if_do_push_and_queue_is_full)
{
	TQueue<int> q(2);
	q.Push(4);
	q.Push(5);
	ASSERT_ANY_THROW(q.Push(3));
}

TEST(TQueue, can_do_push_metod_of_queue)
{
	TQueue<int> q(3);
	ASSERT_NO_THROW(q.Push(4));
}

TEST(TQueue, throws_if_do_pop_and_queue_is_empty)
{
	TQueue<int> q(2);
	ASSERT_ANY_THROW(q.Pop());
}

TEST(TQueue, can_do_pop_metod_of_queue)
{
	TQueue<int> q(3);
	q.Push(4);
	ASSERT_NO_THROW(q.Pop());
}

TEST(TQueue, get_correct_first_elem_of_queue)
{
	TQueue<int> q(2);
	q.Push(4);
	EXPECT_EQ(4, q.Front());
}

TEST(TQueue, can_get_first_elem_of_queue)
{
	TQueue<int> q(3);
	q.Push(4);
	ASSERT_NO_THROW(q.Front());
}

TEST(TQueue, get_correct_end_elem_of_queue)
{
	TQueue<int> q(2);
	q.Push(4);
	q.Push(5);
	EXPECT_EQ(5, q.Back());
}

TEST(TQueue, can_get_end_elem_of_queue)
{
	TQueue<int> q(3);
	q.Push(11);
	q.Push(21);
	ASSERT_NO_THROW(q.Back());
}

TEST(TQueue, can_change_back_elem_without_his_delete)
{
	TQueue<int> q(2);
	q.Push(4);
	q.Push(5);
	q.Back() = 55;
	EXPECT_EQ(55, q.Back());
}

TEST(TQueue, can_change_first_elem_without_his_delete)
{
	TQueue<int> q(2);
	q.Push(4);
	q.Push(5);
	q.Front() = 42;
	EXPECT_EQ(42, q.Front());
}