#include "domain.h"

part	*createPart(char *fname, char *lname, int *score)
{
	part	*newPart;
	int	i;

	newPart = (part *)malloc(sizeof(part));
	newPart->fname = strdup(fname);
	newPart->lname = strdup(lname);
	newPart->score = (int *)malloc(sizeof(int) * 10);
	i = 0;
	while (i < 10)
	{
		newPart->score[i] = score[i];
		i++;
	}
	return (newPart);
}

void	deletePart(part *partM)
{
	free(partM->score);
	free(partM->fname);
	free(partM->lname);
}

char	*getFName(part *partM)
{
	return (partM->fname);
}

char	*getLName(part *partM)
{
	return (partM->lname);
}

int	*getScore(part *partM)
{
	return (partM->score);
}

void	setFName(part *partM, char *newFName)
{
	free(partM->fname);
	partM->fname = strdup(newFName);
}

void	setLName(part *partM, char *newLName)
{
	free(partM->lname);
	partM->lname = strdup(newLName);
}

void	setScore(part *partM, int *newScore)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		partM->score[i] = newScore[i];
		i++;
	}
}

double	getAverage(part *partM)
{
	int	i;
	int	s;

	s = 0;
	i = 0;
	while (i < 10)
		s += partM->score[i++];
	return ((double)s / 10);
}
