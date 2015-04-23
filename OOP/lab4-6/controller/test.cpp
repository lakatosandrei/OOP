#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "../domain/part.h"
#include "../repository/repository.h"
#include "controller.h"

int	main(void)
{
	int				*score;
	char				*fname;
	char				*lname;
	Repository*			rep = new Repository();
	Controller*			ct = new Controller(rep);
	std::vector<Part*>*		partList = rep->getPart();

	score = (int *)malloc(sizeof(int) * 10);
	fname = strdup("a");
	lname = strdup("b");
	Part*	test = new Part(fname, lname, score);
	std::cout << test->getFName() << ' ' << test->getAverage() << '\n';
	test->setFName(lname);
	std::cout << test->getFName() << ' ' << test->getAverage() << '\n';
	std::vector<Part*>::iterator	it = partList->begin();
	ct->addPart(fname, lname, score);
	while (it != partList->end())
	{
		std::cout << *it << '\n';
		it++;
	}
	free(score);
	free(fname);
	free(lname);
	delete rep;
	delete test;
	return (0);
}
