#ifndef PARSER_H
# define PARSER_H

# include "../../includes/miniRT.h"

typedef enum	e_error
{
	ARG_COUNT,
	OPEN_ERR,
	WRONG_TYPE,
	EMPTY_MAP,
	MULT_CAM,
	MULT_AMB,
	MULT_DIR,
	NO_CAM,
	NO_LIGHT,
	UNKNOWN_ID
}	t_error;

typedef struct s_parse_errors
{
	int		line;
	bool	error;
	bool	cam;
	bool	amb_light;
	bool	dir_light;
}	t_parse_errors;

/*	FILE_CHECK	*/

void	ft_file_error(int error, int fd);
bool	check_for_rt(char *file);
int		file_check(int argc, char **argv);

/*	LINE_CHECK	*/
bool	line_check(int fd);


#endif