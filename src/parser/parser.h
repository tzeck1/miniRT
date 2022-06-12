#ifndef PARSER_H
# define PARSER_H

/*  INCLUDES    */
# include "../../includes/miniRT.h"

/*  MAP PARSING */

/*  DATA INITIALIZATION */

/*  init_data.c */
t_data	*init_data(char **argv);

/*  utils.c */
int     float_to_fix(float n);
float   fix_to_float(int raw);

#endif