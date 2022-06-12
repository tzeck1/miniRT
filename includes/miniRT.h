#ifndef MINIRT_H
# define MINIRT_H

/*	INCLUDES	*/
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <errno.h>
# include <string.h>

/*	COLORS	*/
# define RED		"\033[31m"
# define RED_BOLD	"\033[1;31m"
# define GREEN		"\033[32m"
# define BLUE		"\033[34m"
# define YELLOW		"\033[33m"
# define RESET		"\033[0m"

/*	DEBUG	*/
# define PRINT_HERE(){printf(YELLOW"In File: %s\nIn Line: %d\n"RESET, __FILE__, __LINE__);}

/*	MACROS	*/
# define RGB_MIN	0		//colors
# define RGB_MAX	255
# define NO_VEC_MIN	-1.0	// normalised orientation vector
# define NO_VEC_MAX	1.0
# define LIGHT_MIN	0.0		// direct / ambient light brightness
# define LIGHT_MAX	1.0
# define FOV_MIN	0		// field of view degree
# define FOV_MAX	180

/*	MAIN FUNCTIONS	*/
void	ft_alloc_error(char *error_message);
void	ft_exit(int status);

/*	ENUMERATIONS	*/
typedef enum e_identifier
{
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_identifier;

/*  STRUCTS */
typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_plane_list
{
	int					identifier;
	int					i;
	t_vector			i_hat;
	t_vector			j_hat;
	t_color				rgb;
	struct s_plane_list	*next;
	struct s_plane_list	*prev;
}	t_plane_list;

typedef struct s_sphere_list
{
	int						identifier;
	int						i;
	t_vector				center;
	float					radius;
	t_color					rgb;
	struct s_sphere_list	*next;
	struct s_sphere_list	*prev;
}	t_sphere_list;

typedef struct s_cylinder_list
{
	int						identifier;
	int						i;
	t_vector				center;
	t_vector				direction;
	float					radius;
	float					height;
	t_color					rgb;
	struct s_cylinder_list	*next;
	struct s_cylinder_list	*prev;
}	t_cylinder_list;

typedef struct s_camera
{
	int			identifier;
	t_vector	position;
	t_vector	direction;
	int			fov;
}	t_camera;

typedef struct s_direct_light
{
	int			identifier;
	t_vector	position;
	float		ratio;
	t_color		rgb;
}	t_direct_light;

typedef struct s_ambient_light
{
	int			identifier;
	float		ratio;
	t_color		rgb;
}	t_ambient_light;

typedef struct s_objects
{
	struct s_ambient_light	amb_l;
	struct s_direct_light	dir_l;
	struct s_camera			cam;
	struct s_cylinder_list	cy_head;
	struct s_sphere_list	sp_head;
	struct s_plane_list		pl_head;
}	t_objects;

typedef struct s_data
{
	struct s_objects	objs;
}	t_data;

#endif
