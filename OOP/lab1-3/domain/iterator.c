#include "domain.h"

iterator	*createIterator(int len)
{
	iterator	*newIt;

	newIt = (iterator *)malloc(sizeof(iterator));
	newIt->curent = 0;
	newIt->len = len;
	return (newIt);
}

int		itValid(iterator *it)
{
	if (it->curent < it->len)
		return (1);
	return (0);
}

void		itNext(iterator *it)
{
	it->curent += 1;
}

void		itDel(iterator *it)
{
	it->curent -= 1;
}
