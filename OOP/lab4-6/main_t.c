#include "header1.h"

int	main(void)
{
	controller	*ct;
	repository	*rep;

	rep = createRepository();
	ct = createController();
	startUI(ct, rep);
	return (0);
}
