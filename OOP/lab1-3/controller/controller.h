#ifndef CONTROLLER_H
# define CONTROLLER_H

# include "../header.h"

typedef	struct	contr
{
	void (*addPart)		(vector *);
	int (*printPart)	(vector *);
	void (*modifyPart)	(vector *);
	void (*deletePart)	(vector *);
	void (*sortPart)	(vector *, int (*)(void *, void *));
	void (*filterPart)	(vector *, int (*)(void *, void *), void *);
}		controller;
controller	*createController(void);
#endif
