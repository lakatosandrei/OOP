#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "../domain/part.h"
#include "../repository/repository.h"

int	main(void)
{
	int			*score;
	char			*fname;
	char			*lname;
	std::vector<Part*>*	partList;

	score = (int *)malloc(sizeof(int) * 10);
	fname = strdup("a");
	lname = strdup("b");
	Part*	test = new Part(fname, lname, score);
	test->setFName(lname);
	std::cout << test->getFName() << ' ' << test->getAverage() << '\n';
	Repository*	rep;

	rep = new Repository();
	partList = rep->getPart();
	(void)partList;
	std::vector<Part*>::iterator it = partList->begin();
	while (it < partList->end())
	{
		std::cout << (*it)->getFName() << '\n';
		it++;
	}
	delete test;
	delete rep;
	return (0);
}
