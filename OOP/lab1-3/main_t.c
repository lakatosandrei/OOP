#include "header.h"

int	main(void)
{
	vector		*partList;
	controller	*ct;

	partList = createVector();
	ct = createController();
	startUI(partList, ct);
	return (0);
}
