#include "parser.h"

void	ft_parse_error(int error, int line)
{
	if (error == WRONG_TYPE)
		fprintf(stderr, YELLOW "Error[line %d]: " WRONG_TYPE_MSG RESET, line);
	else if (error == MULT_CAM)
		fprintf(stderr, YELLOW "Error[line %d]: " MULT_CAM_MSG RESET, line);
	else if (error == MULT_AMB)
		fprintf(stderr, YELLOW "Error[line %d]: " MULT_AMB_MSG RESET, line);
	else if (error == MULT_DIR)
		fprintf(stderr, YELLOW "Error[line %d]: " MULT_DIR_MSG RESET, line);
	else if (error == BAD_ARG)
		fprintf(stderr, YELLOW "Error[line %d]: " BAD_ARG_MSG RESET, line);
	else if (error == NO_FLOAT)
		fprintf(stderr, YELLOW "Error[line %d]: " NO_FLOAT_MSG RESET, line);
}

/**
 * @brief  prints error message and calls ft_exit()
 * @param  error: error code 
 * @param  fd: close file when an error happens
 */
void	ft_file_error(int error, int fd)
{
	close(fd);
	if (error == ARG_COUNT)
		fprintf(stderr, "Error: " ARG_COUNT_MSG);
	else if (error == WRONG_TYPE)
		fprintf(stderr, "Error: " WRONG_TYPE_MSG);
	else if (error == OPEN_ERR)
		fprintf(stderr, "Error: " OPEN_ERR_MSG);
	else if (error == EMPTY_MAP)
		fprintf(stderr, "Error: " EMPTY_MAP_MSG);
	ft_exit(EXIT_FAILURE);
}
