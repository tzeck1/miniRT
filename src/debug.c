#include "../includes/miniRT.h"

char	*get_type(int type)
{
	switch(type)
	{
		case 0:		return ("\e[93mAMBIENT\e[0m");	break;
		case 1: 	return ("\e[93mCAMERA\e[0m");	break;
		case 2:		return ("\e[93mLIGHT\e[0m");	break;
		case 3:		return ("\e[93mSPHERE\e[0m");	break;
		case 4:		return ("\e[93mPLANE\e[0m");	break;
		case 5:		return ("\e[93mCYLINDER\e[0m");	break;
		default:	return ("\e[93mUNKNOWN\e[0m");	break;
	}
	return (NULL);
}

void	debug_print_vector(t_vector *vec)
{
	printf("x-raw:\t\t\t%f\n", vec->x);
	// printf("x-float:\t\t%f\n", fix_to_float(vec->x));
	printf("y-raw:\t\t\t%f\n", vec->y);
	// printf("y-float:\t\t%f\n", fix_to_float(vec->y));
	printf("z-raw:\t\t\t%f\n", vec->z);
	// printf("z-float:\t\t%f\n", fix_to_float(vec->z));
}

void	debug_print_rgb(t_color *rgb)
{
	printf("red:\t\t\t%i\n", rgb->red);
	printf("green:\t\t\t%i\n", rgb->green);
	printf("blue:\t\t\t%i\n", rgb->blue);
}

void	debug_print_ambient_light(t_amb_light *obj)
{
	printf("identifier:\t\t%s\n", get_type(obj->identifier));
	printf("ratio-raw:\t\t%f\n", obj->ratio);
	// printf("ratio-float:\t\t%f\n", fix_to_float(obj->ratio));
	debug_print_rgb(obj->rgb);
	printf("\n");
}

void	debug_print_direct_light(t_dir_light *obj)
{
	printf("identifier:\t\t%s\n", get_type(obj->identifier));
	debug_print_vector(obj->position);
	printf("ratio-raw:\t\t%f\n", obj->ratio);
	// printf("ratio-float:\t\t%f\n", fix_to_float(obj->ratio));
	debug_print_rgb(obj->rgb);
	printf("\n");
}

void	debug_print_camera(t_camera *obj)
{
	printf("identifier:\t\t%s\n", get_type(obj->identifier));
	debug_print_vector(obj->position);
	debug_print_vector(obj->direction);
	printf("FOV-raw:\t\t%f\n", obj->fov);
	// printf("FOV-float:\t\t%f\n", fix_to_float(obj->fov));
	printf("\n");
}

void	debug_print_cylinder_list(t_cy_list *head)
{
	int	i;

	while (head->i != 0)
		head = head->next;
	i = head->prev->i;
	while (i >= 0)
	{
		debug_print_cylinder_node(head);
		head = head->next;
		i--;
	}
}

void	debug_print_cylinder_node(t_cy_list *node)
{
	printf("identifier:\t\t%s\n", get_type(node->identifier));
	printf("index:\t\t\t%i\n", node->i);
	debug_print_vector(node->center);
	debug_print_vector(node->direction);
	printf("radius-raw:\t\t%f\n", node->radius);
	// printf("radius-float:\t\t%f\n", fix_to_float(node->radius));
	printf("height-raw:\t\t%f\n", node->height);
	// printf("height-float:\t\t%f\n", fix_to_float(node->height));
	debug_print_rgb(node->rgb);
	printf("address:\t\t%p\n", node);
	printf("next:\t\t\t%p\n", node->next);
	printf("prev:\t\t\t%p\n", node->prev);
	printf("\n");
}

void	debug_print_sphere_list(t_sp_list *head)
{
	int	i;

	while (head->i != 0)
		head = head->next;
	i = head->prev->i;
	while (i >= 0)
	{
		debug_print_sphere_node(head);
		head = head->next;
		i--;
	}
}

void	debug_print_sphere_node(t_sp_list *node)
{
	printf("identifier:\t\t%s\n", get_type(node->identifier));
	printf("index:\t\t\t%i\n", node->i);
	debug_print_vector(node->center);
	printf("radius-raw:\t\t%f\n", node->radius);
	// printf("radius-float:\t\t%f\n", fix_to_float(node->radius));
	debug_print_rgb(node->rgb);
	printf("address:\t\t%p\n", node);
	printf("next:\t\t\t%p\n", node->next);
	printf("prev:\t\t\t%p\n", node->prev);
	printf("\n");
}

void	debug_print_plane_list(t_pl_list *head)
{
	int	i;

	while (head->i != 0)
		head = head->next;
	i = head->prev->i;
	while (i >= 0)
	{
		debug_print_plane_node(head);
		head = head->next;
		i--;
	}
}

void	debug_print_plane_node(t_pl_list *node)
{
	printf("identifier:\t\t%s\n", get_type(node->identifier));
	printf("index:\t\t\t%i\n", node->i);
	debug_print_vector(node->i_hat);
	debug_print_vector(node->j_hat);
	debug_print_rgb(node->rgb);
	printf("address:\t\t%p\n", node);
	printf("next:\t\t\t%p\n", node->next);
	printf("prev:\t\t\t%p\n", node->prev);
	printf("\n");
}