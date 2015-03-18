#include "../header.h"

part	*readPart(void)
{
	char	*fname;
	char	*lname;
	int	*score;
	int	i;

	fname = (char *)malloc(sizeof(char) * 30);
	lname = (char *)malloc(sizeof(char) * 30);
	score = (int *)malloc(sizeof(int) * 10);
	printf("Dati prenumele si numele (maxim 30 de caracter fiecare) si scorurile:\n");
	scanf("%s", fname);
	scanf("%s", lname);
	i = 0;
	while (i < 10)
		scanf("%d", &score[i++]);
	return (createPart(fname, lname, score));
}

void	addPart(vector *partList)
{
	part	*partM;

	partM = readPart();
	addToVector(partList, partM);
}

int	printPart(vector *partList)
{
	int	i;

	if (partList->len == 0)
	{
		printf("Lista participanti goala.\n");
		return (0);
	}
	i = 0;
	while (i < partList->len)
	{
		printf("%d\n%s %s %f\n", i, getFName((part *)(partList->elem[i])), getLName((part *)(partList->elem[i])), getAverage((part *)(partList->elem[i])));
		i++;
	}
	return (1);
}

int	readPoz(vector *partList)
{
	int	poz;

	dprintf(2, "Dati pozitia partcipantului: ");
	scanf("%d", &poz);
	if (poz >= 0 && poz <= partList->len)
		return (poz);
	return (-1);
}

void	elibPart(void *a)
{
	free((*(part *)(a)).score);
	free((*(part *)(a)).fname);
	free((*(part *)(a)).lname);
}

void	modifyPart(vector *partList)
{
	int	poz;
	part	*partM;

	if (printPart(partList) == 0)
		return ;
	poz = readPoz(partList);
	if (poz == -1)
		return ;
	partM = readPart();
	modifyFromVector(partList, poz, partM, elibPart);
}

void	delPart(vector *partList)
{
	int	poz;

	if (printPart(partList) == 0)
		return ;
	poz = readPoz(partList);
	if (poz == -1 || poz >= partList->len)
		return ;
	deleteFromVector(partList, poz, elibPart);
}

void	sort(vector *partList, int (*cmp)(void *, void *))
{
	int	i;
	int	j;
	void	*aux;

	i = 0;
	while (i < partList->len)
	{
		j = 0;
		while (j < partList->len - 1)
		{
			if ((*cmp)(partList->elem[i], partList->elem[j]) == 1)
			{
				aux = partList->elem[i];
				partList->elem[i] = partList->elem[j];
				partList->elem[j] = aux;
			}
			j++;
		}
		i++;
	}
}

void	filter(vector *partList, int (*filt)(void *, void *), void *info)
{
	int	i;

	i = 0;
	while (i < partList->len)
	{
		if ((*filt)(partList->elem[i], info) == 1)
			printf("%d\n%s %s %f\n", i,
			getFName((part *)(partList->elem[i])),
			getLName((part *)(partList->elem[i])),
			getAverage((part *)(partList->elem[i])));
		i++;
	}
}

void	cleanMemory(vector *partList, controller *ct, repository *rep)
{
	int	i;

	(void)partList;
	(void)ct;
	(void)rep;
	i = 0;
	while (i < partList->len)
	{
		elibPart(partList->elem[i]);
		free(partList->elem[i]);
		i++;
	}
	free(partList->elem);
	free(partList);
	free(ct);
	free(rep);
	exit(0);
}

controller	*createController(void)
{
	controller	*ct;

	ct = (controller *)malloc(sizeof(controller));
	ct->printPart = printPart;
	ct->addPart = addPart;
	ct->modifyPart = modifyPart;
	ct->deletePart = delPart;
	ct->sortPart = sort;
	ct->filterPart = filter;
	ct->cleanMemory = cleanMemory;
	return (ct);
}
