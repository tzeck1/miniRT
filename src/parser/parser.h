#ifndef PARSER_H
# define PARSER_H

/*  INCLUDES    */
# include "../../includes/miniRT.h"

/*  MAP PARSING */

/*  DATA INITIALIZATION */

/*  init_objects.c */
t_objects	*init_objects(char **argv);

/*  utils.c */
int     float_to_fix(float n);
float   fix_to_float(int raw);

#endif