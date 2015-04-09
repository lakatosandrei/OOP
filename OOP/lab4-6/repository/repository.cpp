#include "repository1.h"

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
	char	*sp = strdup(" ");

	score = (int *)malloc(sizeof(int) * 11);
	mat = strsplit(string, sp);
	i = 0;
	while (i < 10)
	{
		score[i] = atoi(mat[i]);
		i++;
	}
	return (score);
}

void	Repository::modifyRepository(std::vector<Part>* partList)
{
	int	fd;	
	int	i;
	int	j;
	int	*score;

	remove("repPart");
	if ((fd = open("repPart", O_CREAT | O_WRONLY)) != 0)
	{
		i = 0;
		while (i < partList->size())
		{
			dprintf(fd, "%s;", (*partList)[i].getFName());
			dprintf(fd, "%s;", (*partList)[i].getLName());
			score = (*partList)[i].getScore();
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

void	Repository::readFromFile(void)
{
	FILE	*fd;
	char	*buffer;
	size_t	n;
	int	len;
	char	**mat;
	char	*pv = strdup(";");
	std::vector<Part>*	partList;

	partList = new std::vector<Part>();
	buffer = 0;
	if ((fd = fopen("repPart", "r")) != 0)
	{
		while ((len = getline(&buffer, &n, fd)) != -1)
		{
			buffer[len - 1] = 0;
			mat = strsplit(buffer, pv);
			partList->push_back(Part(mat[0], mat[1], createScore(mat[2])));
		}
	}
	else
		printf("Nu exista fisierul\n");
	fclose(fd);
}
