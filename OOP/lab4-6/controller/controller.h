#ifndef CONTROLLER_H
# define CONTROLLER_H

# include "../header.h"
# include "../repository/repository.h"

typedef	struct	contr
{
	void (*addPart)		(repository *, char *, char *, int *);
	void (*modifyPart)	(repository *, char *, char *, int *, int);
	void (*deletePart)	(repository *, int poz);
	void (*sortPart)	(repository *, int (*)(void *, void *));
	void (*filterPart)	(repository *, int (*)(void *, void *), void *);
	void (*cleanMemory)	(struct contr *, repository *);
}		controller;
controller	*createController(void);
#endif
