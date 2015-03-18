#ifndef REPOSITORY_H
# define REPOSITORY_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../domain/vector.h"
# include "../domain/part.h"

typedef	struct rep	
{
	void (*readFromFile)		(vector **);
	void (*modifyRepository)	(vector *);
}		repository;
repository	*createRepository(void);
#endif
