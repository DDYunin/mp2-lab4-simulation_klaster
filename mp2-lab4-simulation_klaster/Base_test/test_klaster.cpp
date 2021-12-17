#include <gtest.h>
#include "Klaster.h"

TEST(TKlaster, can_create_klaster)
{
	ASSERT_NO_THROW(Klaster kl(10,3,5));
}

TEST(TKlaster, klaster_can_do_metod_work)
{
	Klaster kl(10, 3, 5);
	ASSERT_NO_THROW(kl.Work(0.1));
}

TEST(TKlaster, can_t_create_klaster_with_takts_less_than_10)
{
	ASSERT_ANY_THROW(Klaster kl(9, 3, 5));
}

TEST(TKlaster, can_t_create_klaster_with_takts_more_than_1000)
{
	ASSERT_ANY_THROW(Klaster kl(1001, 3, 5));
}

TEST(TKlaster, can_t_create_klaster_with_num_processors_less_than_1)
{
	ASSERT_ANY_THROW(Klaster kl(10, 0, 5));
}

TEST(TKlaster, can_t_create_klaster_with_num_processors_more_than_64)
{
	ASSERT_ANY_THROW(Klaster kl(10, 65, 5));
}

TEST(TKlaster, can_t_create_klaster_with_q_size_less_than_5)
{
	ASSERT_ANY_THROW(Klaster kl(10, 3, 4));
}

TEST(TKlaster, can_t_create_klaster_with_q_size_more_than_50)
{
	ASSERT_ANY_THROW(Klaster kl(10, 3, 51));
}