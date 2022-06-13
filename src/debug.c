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

void	debug_print_vector(t_vector *v)
{
	printf("x-raw:\t\t\t%i\n", v->x);
	printf("x-float:\t\t%f\n", fix_to_float(v->x));
	printf("y-raw:\t\t\t%i\n", v->y);
	printf("y-float:\t\t%f\n", fix_to_float(v->y));
	printf("z-raw:\t\t\t%i\n", v->z);
	printf("z-float:\t\t%f\n", fix_to_float(v->z));
}

void	debug_print_rgb(t_color *rgb)
{
	printf("red:\t\t\t%i\n", rgb->red);
	printf("green:\t\t\t%i\n", rgb->green);
	printf("blue:\t\t\t%i\n", rgb->blue);
}

/*
void	debug_print_ambient_light(t_ambient_light *obj)
{

}

void	debug_print_direct_light(t_direct_light *obj)
{

}

void	debug_print_camera(t_camera *obj)
{

}
*/

void	debug_print_cylinder_list(t_cylinder_list *head)
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

void	debug_print_cylinder_node(t_cylinder_list *node)
{
	printf("identifier:\t\t%s\n", get_type(node->identifier));
	printf("index:\t\t\t%i\n", node->i);
	debug_print_vector(node->center);
	debug_print_vector(node->direction);
	printf("radius-raw:\t\t%i\n", node->radius);
	printf("radius-float:\t\t%f\n", fix_to_float(node->radius));
	printf("height-raw:\t\t%i\n", node->height);
	printf("height-float:\t\t%f\n", fix_to_float(node->height));
	debug_print_rgb(node->rgb);
	printf("address:\t\t%p\n", node);
	printf("next:\t\t\t%p\n", node->next);
	printf("prev:\t\t\t%p\n", node->prev);
	printf("\n");
}

/*
void	debug_print_sphere_list(t_sphere_list *head)
{

}

void	debug_print_sphere_node(t_sphere_list *node)
{

}

void	debug_print_plane_list(t_plane_list *head)
{

}

void	debug_print_plane_node(t_plane_list *node)
{

}
*/