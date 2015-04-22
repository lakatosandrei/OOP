#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "../domain/part.h"
#include "repository.h"

int	main(void)
{
	int				*score;
	char				*fname;
	char				*lname;
	Repository*			rep = new Repository();
	std::vector<Part*>*		partList = rep->getPart();

	score = (int *)malloc(sizeof(int) * 10);
	fname = strdup("a");
	lname = strdup("b");
	Part*	test = new Part(fname, lname, score);
	std::cout << test->getFName() << ' ' << test->getAverage() << '\n';
	test->setFName(lname);
	std::cout << test->getFName() << ' ' << test->getAverage() << '\n';
	std::vector<Part*>::iterator	it = partList->begin();
	while (it != partList->end())
	{
		std::cout << *it << '\n';
		it++;
	}
	delete	test;
	delete	partList;
	delete	rep;
	free(score);
	free(fname);
	free(lname);
	return (0);
}
