#include "so_long.h"

void	error_handler(char *msg, char *func, int err_no)
{
	if (err_no)
		errno = err_no;
	printf("Error\n");
	printf("%s\n", msg);
	perror(func);
	exit(EXIT_FAILURE);
}