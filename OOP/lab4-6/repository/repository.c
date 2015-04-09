#include "repository.h"

int	count(char *string, char c)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (string[i])
	{
		if (string[i] == c)
			s++;
		i++;
	}
	return (s);
}

char	**strsplit(char *string, char *c)
{
	char	**mat;
	char	*s;
	int	i;

	mat = (char **)malloc(sizeof(char *) * (count(string, c[0]) + 1));
	s = strtok(string, c);
	i = 0;
	while (s != 0)
	{
		mat[i++] = s;
		s = strtok(0, c);
	}
	return (mat);
}

int	*createScore(char *string)
{
	int	*score;
	char	**mat;
	int	i;

	score = (int *)malloc(sizeof(int) * 11);
	mat = strsplit(string, " ");
	i = 0;
	while (i < 10)
	{
		score[i] = atoi(mat[i]);
		i++;
	}
	return (score);
}

vector	*readFromFile(void)
{
	FILE	*fd;
	char	*buffer;
	size_t	n;
	int	len;
	char	**mat;
	vector	*partList;

	partList = createVector();
	buffer = 0;
	if ((fd = fopen("repPart", "r")) != 0)
	{
		while ((len = getline(&buffer, &n, fd)) != -1)
		{
			buffer[len - 1] = 0;
			mat = strsplit(buffer, ";");
			addToVector(partList, createPart(mat[0], mat[1], createScore(mat[2])));
		}
	}
	else
		printf("Nu exista fisierul\n");
	fclose(fd);
	return (partList);
}

void	modifyRepository(vector *partList)
{
	int	fd;	
	int	i;
	int	j;
	int	*score;

	remove("repPart");
	if ((fd = open("repPart", O_CREAT | O_WRONLY)) != 0)
	{
		i = 0;
		while (i < partList->len)
		{
			dprintf(fd, "%s;", getFName((part *)(partList->elem[i])));
			dprintf(fd, "%s;", getLName((part *)(partList->elem[i])));
			score = getScore((part *)(partList->elem[i]));
			j = 0;
			while (j < 10)
			{
				if (j != 9)
					dprintf(fd, "%d ", score[j]);
				else
					dprintf(fd, "%d\n", score[j]);
				j++;
			}
			i++;
		}
	}
	else
		printf("Eroare la modificare fisier.\n");
	close(fd);
}

repository	*createRepository(void)
{
	repository	*rep;

	rep = (repository *)malloc(sizeof(repository));
	rep->readFromFile = readFromFile;
	rep->partList = readFromFile();
	rep->modifyRepository = modifyRepository;
	return (rep);
}

