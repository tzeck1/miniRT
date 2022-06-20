#ifndef DATA_INIT_H
# define DATA_INIT_H

# include "../../includes/miniRT.h"

/*	SPHERE	*/

int			sp_counter(char *rt_file_path);
void		sp_fill(char **data, t_sp_list *sp_node);
t_sp_list	*sp_init_head(char *line);
void		sp_set_link_ptr(t_sp_list *head, t_sp_list *node);
void		sp_add_node(char *line, t_sp_list *sp_head);

/*	PLANE	*/

int			pl_counter(char *rt_file_path);
void		pl_fill(char **data, t_pl_list *pl_node);
t_pl_list	*pl_init_head(char *line);
void		pl_set_link_ptr(t_pl_list *head, t_pl_list *node);
void		pl_add_node(char *line, t_pl_list *pl_head);

/*	SPHERE	*/

int			cy_counter(char *rt_file_path);
void		cy_fill(char **data, t_cy_list *cy_node);
t_cy_list	*cy_init_head(char *line);
void		cy_set_link_ptr(t_cy_list *head, t_cy_list *node);
void		cy_add_node(char *line, t_cy_list *cy_head);

#endif