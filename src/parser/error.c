#include "parser.h"

void	ft_parse_error(int error, int line)
{
	if (error == WRONG_TYPE)
		fprintf(stderr, YELLOW"Error[line %d]: Wrong identifier!\n"RESET, line);
	else if (error == MULT_CAM)
		fprintf(stderr, YELLOW"Error[line %d]: Multiple cameras!\n"RESET, line);
	else if (error == MULT_AMB)
		fprintf(stderr, YELLOW"Error[line %d]: Multiple amb_lights!\n"RESET, line);
	else if (error == MULT_DIR)
		fprintf(stderr, YELLOW"Error[line %d]: Multiple dir_lights!\n"RESET, line);
	else if (error == BAD_ARG)
		fprintf(stderr, YELLOW"Error[line %d]: Bad object info!\n"RESET, line);
	else if (error == NO_FLOAT)
		fprintf(stderr, YELLOW"Error[line %d]: No number given!\n"RESET, line);
}
