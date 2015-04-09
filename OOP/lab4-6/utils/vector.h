#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct vect
{
	void	**elem;
	int	len;
	int	capacity;
}		vector;
void		addToVector(vector *partList, void *elem);
void		deleteFromVector(vector *partList, int poz, void (*elib)(void *));
void		modifyFromVector(vector *partList, int poz, void *partM, void (*elib)(void *));
vector		*createVector();
#endif
