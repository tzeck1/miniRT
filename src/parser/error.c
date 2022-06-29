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

/**
 * @brief  prints error message and calls ft_exit()
 * @param  error: error code 
 * @param  fd: close file when an error happens
 */
void	ft_file_error(int error, int fd)
{
	close(fd);	// what happens if close(-1), is that fine?
	if (error == ARG_COUNT)
		fprintf(stderr, "Error: Program requires exactly one argument!\n");
	else if (error == WRONG_TYPE)
		fprintf(stderr, "Error: File requires .rt extension!\n");
	else if (error == OPEN_ERR)
		fprintf(stderr, "Error: Cannot open file!\n");
	else if (error == EMPTY_MAP)
		fprintf(stderr, "Error: File feels empty (me too)!\n");
	ft_exit(EXIT_FAILURE);
}