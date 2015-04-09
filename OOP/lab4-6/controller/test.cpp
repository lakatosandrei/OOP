#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "../domain/part1.h"
#include "../repository/repository1.h"

int	main(void)
{
	int	*score;
	char	*fname;
	char	*lname;

	score = (int *)malloc(sizeof(int) * 10);
	fname = strdup("a");
	lname = strdup("b");
	Part*	test = new Part(fname, lname, score);
	test->setFName(lname);
	std::cout << test->getFName() << ' ' << test->getAverage();
	Repository	rep();
	delete test;
	return (0);
}
