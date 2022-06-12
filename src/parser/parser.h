#ifndef PARSER_H
# define PARSER_H

/*  INCLUDES    */
# include "../../includes/miniRT.h"

/*  MAP PARSING */

/*  DATA INITIALIZATION */
t_ambient_light	*get_ambient_light_data(char **argv);
t_direct_light	*get_direct_light_data(char **argv);
t_camera		*get_camera_data(char **argv);

/*  init_objects.c */
// t_objects	*init_objects(char **argv);

/*  utils.c */
int     float_to_fix(float n);
float   fix_to_float(int raw);

#endif