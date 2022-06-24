#ifndef PARSER_H
# define PARSER_H

# include "../../includes/miniRT.h"

typedef enum	e_rror
{
	ARG_COUNT,
	OPEN_ERR,
	EMPTY_MAP,
	UNKNOWN_ID
}	t_rror;

void	ft_pars_error(int error);

#endif