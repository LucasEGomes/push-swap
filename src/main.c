#include "application/application.h"
#include <stddef.h>

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc < 2)
		return (0);
	start_application(NULL);
	return (0);
}
