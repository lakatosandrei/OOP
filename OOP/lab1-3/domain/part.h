#ifndef PART_H
# define PART_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct	participant
{
	char	*fname;
	char	*lname;
	int	*score;
}		part;
part		*createPart(char *fname, char *lname, int *score);
char		*getFName(part *partM);
char		*getLName(part *partM);
int		*getScore(part *partM);
void		setFName(part *partM, char *newFName);
void		setLName(part *partM, char *newLName);
void		setScore(part *partM, int *newScore);
double		getAverage(part *partM);
void		deletePart(part *partM);
#endif
