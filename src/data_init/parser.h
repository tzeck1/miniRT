#ifndef PARSER_H
# define PARSER_H

# include "../../includes/miniRT.h"

/*	SPHERE	*/

int				sphere_count(char **argv);
void			sphere_fill(char **data, t_sphere_list *sp_node);
t_sphere_list	*sphere_initialize_head(char *line);
void			sphere_set_link_pointers(t_sphere_list *head, t_sphere_list *node);
void			sphere_add_node(char *line, t_sphere_list *sp_head);

/*	PLANE	*/

int				plane_count(char **argv);
void			plane_fill(char **data, t_plane_list *pl_node);
t_plane_list	*plane_initialize_head(char *line);
void			plane_set_link_pointers(t_plane_list *head, t_plane_list *node);
void			plane_add_node(char *line, t_plane_list *pl_head);

/*	SPHERE	*/

int				cylinder_count(char **argv);
void			cylinder_fill(char **data, t_cylinder_list *cy_node);
t_cylinder_list	*cylinder_initialize_head(char *line);
void			cylinder_set_link_pointers(t_cylinder_list *head, t_cylinder_list *node);
void			cylinder_add_node(char *line, t_cylinder_list *cy_head);


#endif