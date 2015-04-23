#include "header.h"

int	main(void)
{
	Repository*	rep;
	Controller*	ct;

	rep = new Repository();
	ct = new Controller(rep);
	startUI(ct);
}
