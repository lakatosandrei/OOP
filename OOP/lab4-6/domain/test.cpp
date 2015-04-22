#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "part.h"

int	main(void)
{
	int	*score;
	char	*fname;
	char	*lname;

	score = (int *)malloc(sizeof(int) * 10);
	fname = strdup("a");
	lname = strdup("b");
	Part*	test = new Part(fname, lname, score);
	std::cout << test->getFName() << ' ' << test->getAverage() << '\n';
	test->setFName(lname);
	std::cout << test->getFName() << ' ' << test->getAverage() << '\n';
	delete test;
	free(score);
	free(fname);
	free(lname);
	Part*	b = new Part();
	std::cin >> b;
	std::cout << b;
	return (0);
}
