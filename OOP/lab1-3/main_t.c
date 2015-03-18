#include "header.h"

int	main(void)
{
	vector		*partList;
	controller	*ct;
	repository	*rep;

	rep = createRepository();
	partList = createVector();
	rep->readFromFile(&partList);
	ct = createController();
	startUI(partList, ct, rep);
	return (0);
}
