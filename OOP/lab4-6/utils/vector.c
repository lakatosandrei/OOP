#include "vector.h"

vector	*createVector(void)
{
	vector *newList;

	newList = (vector *)malloc(sizeof(vector));
	newList->len = 0;
	newList->capacity = 9;
	newList->elem = malloc(sizeof(void *) * 10);
	return (newList);
}

void	addToVector(vector *partList, void *elem)
{
	vector	*aux;
	int	i;

	aux = partList;
	if (partList->len == partList->capacity)
	{
		partList = realloc(partList, sizeof(vector) * (partList->len + 1) * 2);
		i = 0;
		while (i < aux->len)
			free(aux->elem[i++]);
		partList->len = partList->capacity * 2;
	}
	partList->elem[partList->len] = elem;
	partList->len += 1;
}

void	modifyFromVector(vector *partList, int poz, void *elem, void (*elib)(void *))
{
	(*elib)(partList->elem[poz]);
	partList->elem[poz] = elem;
}

void	deleteFromVector(vector *partList, int poz, void (*elib)(void *))
{
	(*elib)(partList->elem[poz]);
	while (poz < partList->len)
	{
		partList->elem[poz] = partList->elem[poz + 1];
		poz++;
	}
	partList->len -= 1;
}
