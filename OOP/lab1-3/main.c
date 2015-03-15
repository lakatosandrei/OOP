#include "domain/domain.h"

int	main(void)
{
	part		*partM;
	vector		*newList;
	iterator	*it;
	char		*fname = "Potor";
	char		*lname = "Vasile";
	int		score[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int		*scoreP;
	int		i;

	scoreP = score;
	partM = createPart(fname, lname, scoreP);
	printf("%s\n%s\n", getFName(partM), getLName(partM));
	i = 0;
	while (i < 10)
		printf("%d ", partM->score[i++]);
	printf("\n");
	newList = createVector();
	it = createIterator(9);
	i = 0;
	while (i < 9)
	{
	char		*fname1 = strdup("Potor");
	char		*lname1 = strdup("Vasile");
	int		score1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int		*scoreM;
	scoreM = score1;
		partM = createPart(fname1, lname1, scoreM);
		addToVector(newList, partM, it);
		i++;
	}
	i = 0;
	while (i < 9)
	{
		printf("%s\n", getFName((part *)(newList[i])));
		i++;
	}
	deleteFromVector(newList, 4, it);
	i = 0;
	while (i < 8)
	{
		printf("%s\n", getLName((part *)(newList[i])));
		i++;
	}
	char		*fname2 = strdup("Lakatos");
	char		*lname2 = strdup("Alexandru-Andrei");
	partM = createPart(fname2, lname2, score);
	modifyFromVector(newList, 3, partM);
	i = 0;
	while (i < 8)
	{
		printf("%s\n", getLName((part *)(newList[i])));
		i++;
	}
	return (0);
}
