#include "parser.h"

bool	parser(int argc, char **argv)
{
	int		fd;

	fd = file_check(argc, argv);
	if (line_check(fd) == true)
		return (true);
	else
		return (false);
}