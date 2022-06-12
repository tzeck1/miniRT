#ifndef VECTOR_H
# define VECTOR_H

# include "../../includes/miniRT.h"

/*	MANAGEMENT	*/
t_vector	*new_vector(int x, int y, int z);
void		change_vector(t_vector *vec, int x, int y, int z);
void		copy_vector(t_vector *vec_src, t_vector *vec_dst);

#endif
