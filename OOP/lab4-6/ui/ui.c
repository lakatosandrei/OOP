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

void	sortPart(repository *rep, controller *ct)
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
				ct->sortPart(rep, cmpLastName);
				break ;
			case '2':
				done = 1;
				ct->sortPart(rep, cmpScore);
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

void	filterPart(repository *rep, controller *ct)
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
				ct->filterPart(rep, filtScore, readScore(&score));
				break ;
			case '2':
				done = 1;
				ct->filterPart(rep, filtLName, readLetter(&letter));
				break ;
			default:
				break ;
		}
	}
}

void	readParticipant(char **fname, char **lname, int **score)
{
	int	i;

	printf("Dati prenumele si numele (maxim 30 de caracter fiecare) si scorurile:\n");
	scanf("%s", *fname);
	scanf("%s", *lname);
	i = 0;
	while (i < 10)
		scanf("%d", &(*score)[i++]);
}

void	addParticipant(repository *rep, controller *ct)
{
	char	*fname;
	char	*lname;
	int	*score;

	fname = (char *)malloc(sizeof(char) * 30);
	lname = (char *)malloc(sizeof(char) * 30);
	score = (int *)malloc(sizeof(int) * 10);
	readParticipant(&fname, &lname, &score);
	ct->addPart(rep, fname, lname, score);
}

int	readPos(vector *partList)
{
	int	poz;

	dprintf(2, "Dati pozitia partcipantului: ");
	scanf("%d", &poz);
	if (poz >= 0 && poz <= partList->len)
		return (poz);
	return (-1);
}

int	printParticipant(vector *partList)
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

void	modifyParticipant(repository *rep, controller *ct)
{
	int	poz;
	char	*fname;
	char	*lname;
	int	*score;

	fname = (char *)malloc(sizeof(char) * 30);
	lname = (char *)malloc(sizeof(char) * 30);
	score = (int *)malloc(sizeof(int) * 10);
	if (printParticipant(rep->partList) == 0)
		return ;
	poz = readPos(rep->partList);
	if (poz == -1)
		return ;
	readParticipant(&fname, &lname, &score);
	ct->modifyPart(rep, fname, lname, score, poz);
}

void	delParticipant(repository *rep, controller *ct)
{
	int	poz;

	if (printParticipant(rep->partList) == 0)
		return ;
	poz = readPos(rep->partList);
	if (poz == -1 || poz >= rep->partList->len)
		return ;
	ct->deletePart(rep, poz);
}

void	startUI(controller *ct, repository *rep)
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
				ct->cleanMemory(ct, rep);
			case '1':
				addParticipant(rep, ct);
				break ;
			case '2':
				modifyParticipant(rep, ct);
				break ;
			case '3':
				delParticipant(rep, ct);
				break ;
			case '4':
				printParticipant(rep->partList);
				break ;
			case '5':
				sortPart(rep, ct);
				break ;
			case '6':
				filterPart(rep, ct);
				break ;
			default:
				printf("Nu exista comanda.\n");
				break ;
		}
	}
}
