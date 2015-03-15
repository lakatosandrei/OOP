#ifndef	ITERATOR_H
# define ITERATOR_H

typedef struct	iter
{
	int	curent;
	int	len;
}		iterator;
iterator	*createIterator(int len);
int		itValid(iterator *it);
void		itNext(iterator *it);
void		itDel(iterator *it);
#endif
