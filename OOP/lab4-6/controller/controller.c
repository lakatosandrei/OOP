#include "../header.h"

void	addPart(repository *rep, char *fname, char *lname, int *score)
{
	part	*partM;

	partM = createPart(fname, lname, score);
	addToVector(rep->partList, partM);
	rep->modifyRepository(rep->partList);
}

void	elibPart(void *a)
{
	free((*(part *)(a)).score);
	free((*(part *)(a)).fname);
	free((*(part *)(a)).lname);
}

void	modifyPart(repository *rep, char *fname, char *lname, int *score, int poz)
{
	part	*partM;

	partM = createPart(fname, lname, score);
	modifyFromVector(rep->partList, poz, partM, elibPart);
	rep->modifyRepository(rep->partList);
}

void	delPart(repository *rep, int poz)
{
	if (poz == -1 || poz >= rep->partList->len)
		return ;
	deleteFromVector(rep->partList, poz, elibPart);
	rep->modifyRepository(rep->partList);
}

void	sort(repository *rep, int (*cmp)(void *, void *))
{
	int	i;
	int	j;
	void	*aux;

	i = 0;
	while (i < rep->partList->len)
	{
		j = 0;
		while (j < rep->partList->len - 1)
		{
			if ((*cmp)(rep->partList->elem[i], rep->partList->elem[j]) == 1)
			{
				aux = rep->partList->elem[i];
				rep->partList->elem[i] = rep->partList->elem[j];
				rep->partList->elem[j] = aux;
			}
			j++;
		}
		i++;
	}
}

void	filter(repository *rep, int (*filt)(void *, void *), void *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < rep->partList->len)
	{
		if ((*filt)(rep->partList->elem[i], info) == 1)
			printf("%d\n%s %s %f\n", i,
			getFName((part *)(rep->partList->elem[i])),
			getLName((part *)(rep->partList->elem[i])),
			getAverage((part *)(rep->partList->elem[i])));
		i++;
	}
}

void	cleanMemory(struct contr *ct, repository *rep)
{
	int	i;

	i = 0;
	while (i < rep->partList->len)
	{
		elibPart(rep->partList->elem[i]);
		free(rep->partList->elem[i]);
		i++;
	}
	free(rep->partList->elem);
	free(rep->partList);
	free(ct);
	free(rep);
	exit(0);
}

controller	*createController(void)
{
	controller	*ct;

	ct = (controller *)malloc(sizeof(controller));
	ct->addPart = addPart;
	ct->modifyPart = modifyPart;
	ct->deletePart = delPart;
	ct->sortPart = sort;
	ct->filterPart = filter;
	ct->cleanMemory = cleanMemory;
	return (ct);
}
