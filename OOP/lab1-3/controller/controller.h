#ifndef CONTROLLER_H
# define CONTROLLER_H

# include "../header.h"
# include "../repository/repository.h"

typedef	struct	contr
{
	void (*addPart)		(vector *);
	int (*printPart)	(vector *);
	void (*modifyPart)	(vector *);
	void (*deletePart)	(vector *);
	void (*sortPart)	(vector *, int (*)(void *, void *));
	void (*filterPart)	(vector *, int (*)(void *, void *), void *);
	void (*cleanMemory)	(vector *, struct contr *, repository *);
}		controller;
controller	*createController(void);
#endif
