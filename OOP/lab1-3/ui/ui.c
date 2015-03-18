#include "../header.h"

void	printMenu(void)
{
	char	*menu = "Meniu:\n0. Iesire\n1. Adauga participant.\n2. Modifica participant\n3. Sterge participant.\n4. Afiseaza participantii\n5. Sorteaza Participantii.\n6. Filtreaza participantii.";

	printf("%s\n", menu);
}

void	readCommand(char **command)
{
	scanf("%s", *command);
}

char	readType(void)
{
	char	*command;

	command = (char *)malloc(sizeof(char) * 2);
	scanf("%s", command);
	return (command[0]);
}

void	printSortMenu(void)
{
	char	*menu = "Meniu de sortari:\n0. Intoarcere.\n1. Sortare dupa numele de familie.\n2. Sortare dupa scor.";
	printf("%s\n", menu);
}

int	cmpScore(void *a, void *b)
{
	if (getAverage((part *)a) > getAverage((part *)b))
		return (1);
	return (0);
}

int	cmpLastName(void *a, void *b)
{
	if (strcmp(getLName((part *)a), getLName((part *)b)) <= 0)
		return (1);
	return (0);
}

void	sortPart(vector *partList, controller *ct)
{
	char	command;
	int	done;

	done = 0;
	while (done == 0)
	{
		printSortMenu();
		command = readType();
		if (command == '0')
			break ;
		switch (command)
		{
			case '1':
				done = 1;
				ct->sortPart(partList, cmpLastName);
				break ;
			case '2':
				done = 1;
				ct->sortPart(partList, cmpScore);
				break ;
			default:
				break ;
		}
	}
}

void	printFilterMenu(void)
{
	char	*menu = "Meniu de filtre:\n0. Intoarcere.\n1. Filtrare dupa scor.\n2. Filtrare dupa numele de familie.";
	printf("%s\n", menu);
}

double	*readScore(double *score)
{
	printf("Dati scorul care este acceptat ca cel mai mare: ");
	scanf("%lf", score);
	return (score);
}

char	*readLetter(char **letter)
{
	printf("Dati litera cu care trebuia sa inceapa numele de familie: ");
	scanf("%s", *letter);
	return ((*letter));
}

int	filtScore(void *a, void *b)
{
	if (getAverage((part *)a) <= *(double *)b)
		return (1);
	return (0);
}

int	filtLName(void *a, void *b)
{
	if (strchr(getLName((part *)a), *(char *)b) == getLName((part *)a))
		return (1);
	return (0);
}

void	filterPart(vector *partList, controller *ct)
{
	char	command;
	int	done;
	double	score;
	char	*letter;

	letter = (char *)malloc(sizeof(2));
	done = 0;
	while (done == 0)
	{
		printFilterMenu();
		command = readType();
		if (command == '0')
			break ;
		switch (command)
		{
			case '1':
				done = 1;
				ct->filterPart(partList, filtScore, readScore(&score));
				break ;
			case '2':
				done = 1;
				ct->filterPart(partList, filtLName, readLetter(&letter));
				break ;
			default:
				break ;
		}
	}
}

void	startUI(vector *partList, controller *ct, repository *rep)
{
	char	*command;

	command = (char *)malloc(sizeof(char) * 2);
	while (1)
	{
		printMenu();
		readCommand(&command);
		switch (command[0])
		{
			case '0':
				free(command);
				ct->cleanMemory(partList, ct, rep);
			case '1':
				ct->addPart(partList);
				rep->modifyRepository(partList);
				break ;
			case '2':
				ct->modifyPart(partList);
				rep->modifyRepository(partList);
				break ;
			case '3':
				ct->deletePart(partList);
				rep->modifyRepository(partList);
				break ;
			case '4':
				ct->printPart(partList);
				break ;
			case '5':
				sortPart(partList, ct);
				break ;
			case '6':
				filterPart(partList, ct);
				break ;
			default:
				printf("Nu exista comanda.\n");
				break ;
		}
	}
}
