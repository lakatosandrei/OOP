#include "vector.h"
#include "part.h"

int	*createScore(char *string)
{
	int	*score;
	int	i;

	score = (int *)malloc(sizeof(int) * 10);
	i = 0;
	string = strtok(string, " ");
	while (i < 10)
	{
		if (string)
			printf("%d\n", atoi(string));
		score[i] = atoi(string);
		string = strtok(0, ";");
		i++;
	}
	return (score);
}

void	readFromFile(vector **partList)
{
	FILE	*fd;
	char	*buffer;
	size_t	n;
	int	len;
	char	*mat;
	void	*partM;

	(void)partList;
	buffer = 0;
	if ((fd = fopen("repPart", "r")) != 0)
	{
		while ((len = getline(&buffer, &n, fd)) != -1)
		{
			buffer[len - 1] = 0;
			mat = strtok(buffer, ";");
			partM = createPart(mat, strtok(buffer, ";"), createScore(strtok(buffer, ";")));
			printf("%s\n", mat);
			mat = strtok(0, ";");
			printf("%s\n", mat);
			mat = strtok(0, ";");
			printf("%s\n", mat);
			(void)partM;
		}
	}
	else
		printf("Nu exista fisierul\n");
	fclose(fd);
}

vector	*createVector(void)
{
	vector *newList;

	newList = malloc(sizeof(vector *));
	newList->len = 0;
	newList->capacity = 9;
	newList->elem = malloc(sizeof(void *) * 10);
	readFromFile(&newList);
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
		partList[poz] = partList[poz + 1];
		poz++;
	}
	partList->len -= 1;
}
