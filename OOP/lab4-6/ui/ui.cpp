#include "ui.h"

void	printMenu(void)
{
	char	*menu = strdup("Meniu:\n0. Iesire\n1. Adauga participant.\n2. Modifica participant\n3. Sterge participant.\n4. Afiseaza participantii\n5. Sorteaza Participantii.\n6. Filtreaza participantii.");

	std::cout << menu << '\n';
	free(menu);
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
	char	*menu = strdup("Meniu de sortari:\n0. Intoarcere.\n1. Sortare dupa numele de familie.\n2. Sortare dupa scor.");
	std::cout << menu << '\n';
	free(menu);
}

int	cmpScore(void *a, void *b)
{
	if (((Part *)a)->getAverage() > ((Part *)b)->getAverage())
		return (1);
	return (0);
}

int	cmpLastName(void *a, void *b)
{
	if (strcmp(((Part *)a)->getLName(), ((Part *)b)->getLName()) <= 0)
		return (1);
	return (0);
}

void	sortPart(Controller *ct)
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
				ct->sort(cmpLastName);
				break ;
			case '2':
				done = 1;
				ct->sort(cmpScore);
				break ;
			default:
				break ;
		}
	}
}

void	printFilterMenu(void)
{
	char	*menu = strdup("Meniu de filtre:\n0. Intoarcere.\n1. Filtrare dupa scor.\n2. Filtrare dupa numele de familie.");
	std::cout << menu << '\n';
	free(menu);
}

double	*readScore(double *score)
{
	std::cout << "Dati scorul care este acceptat ca cel mai mare: ";
	scanf("%lf", score);
	return (score);
}

char	*readLetter(char **letter)
{
	std::cout << "Dati litera cu care trebuia sa inceapa numele de familie: ";
	scanf("%s", *letter);
	return ((*letter));
}

int	filtScore(void *a, void *b)
{
	if (((Part *)a)->getAverage() <= *(double *)b)
		return (1);
	return (0);
}

int	filtLName(void *a, void *b)
{
	if (strchr(((Part *)a)->getLName(), *(char *)b) == ((Part *)a)->getLName())
		return (1);
	return (0);
}

void	filterPart(Controller *ct)
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
				ct->filter(filtScore, readScore(&score));
				break ;
			case '2':
				done = 1;
				ct->filter(filtLName, readLetter(&letter));
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

void	addParticipant(Controller *ct)
{
	char	*fname;
	char	*lname;
	int	*score;

	fname = (char *)malloc(sizeof(char) * 30);
	lname = (char *)malloc(sizeof(char) * 30);
	score = (int *)malloc(sizeof(int) * 10);
	readParticipant(&fname, &lname, &score);
	ct->addPart(fname, lname, score);
}

int	readPos(std::vector<Part*>* partList)
{
	int	poz;

	dprintf(2, "Dati pozitia partcipantului: ");
	scanf("%d", &poz);
	if (poz >= 0 && (size_t)poz <= partList->size())
		return (poz);
	return (-1);
}

int	printParticipant(Controller* ct)
{
	int				i;
	std::vector<Part*>*		partList;
	std::vector<Part*>::iterator	it;

	partList = ct->getList();
	if (partList->size() == 0)
	{
		printf("Lista participanti goala.\n");
		return (0);
	}
	i = 0;
	it = partList->begin();
	while (it != partList->end())
	{
		std::cout << i << ' ' << (*it)->getFName() << ' '
		<< (*it)->getLName() << ' ' << (*it)->getAverage() << '\n';
		it++;
		i++;
	}
	return (1);
}

void	modifyParticipant(Controller *ct)
{
	int			poz;
	char			*fname;
	char			*lname;
	int			*score;
	std::vector<Part*>*	partList;

	partList = ct->getList();
	fname = (char *)malloc(sizeof(char) * 30);
	lname = (char *)malloc(sizeof(char) * 30);
	score = (int *)malloc(sizeof(int) * 10);
	if (printParticipant(ct) == 0)
		return ;
	poz = readPos(partList);
	if (poz == -1)
		return ;
	readParticipant(&fname, &lname, &score);
	ct->modifyPart(fname, lname, score, poz);
}

void	delParticipant(Controller *ct)
{
	int			poz;
	std::vector<Part*>*	partList;

	partList = ct->getList();
	if (printParticipant(ct) == 0)
		return ;
	poz = readPos(partList);
	if (poz == -1 || (size_t)poz >= partList->size())
		return ;
	ct->delPart(poz);
}

void	startUI(Controller *ct)
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
				exit(0);
			case '1':
				addParticipant(ct);
				break ;
			case '2':
				modifyParticipant(ct);
				break ;
			case '3':
				delParticipant(ct);
				break ;
			case '4':
				printParticipant(ct);
				break ;
			case '5':
				sortPart(ct);
				break ;
			case '6':
				filterPart(ct);
				break ;
			default:
				printf("Nu exista comanda.\n");
				break ;
		}
	}
}
