#include "../../unity/unity_fixture.h"

static void RunAllTests(void)
{
	RUN_TEST_GROUP(bacaj_tests);
	RUN_TEST_GROUP(zakljucaj_tests);
	RUN_TEST_GROUP(bacanja_runda_tests);
	RUN_TEST_GROUP(ispis_tests);
}

int main(int argc, char *argv[])
{
	return UnityMain(argc, (const char **)argv, RunAllTests);
}


