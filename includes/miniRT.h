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
# include <fcntl.h>
# include <stdbool.h>

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
# define LIGHT_ID		"L"
# define AMB_LIGHT_ID	"A"
# define CAMERA_ID		"C"
# define SPHERE_ID		"sp"
# define PLANE_ID		"pl"
# define CYLINDER_ID	"cy"

# define RGB_MIN	0		//colors
# define RGB_MAX	255
# define NO_VEC_MIN	-1.0	// normalised orientation vector
# define NO_VEC_MAX	1.0
# define LIGHT_MIN	0.0		// direct / ambient light brightness
# define LIGHT_MAX	1.0
# define FOV_MIN	0		// field of view degree
# define FOV_MAX	180

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
	int	x;
	int	y;
	int	z;
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
	t_vector			*i_hat;
	t_vector			*j_hat;
	t_color				*rgb;
	struct s_plane_list	*next;
	struct s_plane_list	*prev;
}	t_plane_list;

typedef struct s_sphere_list
{
	int						identifier;
	int						i;
	t_vector				*center;
	int						radius;
	t_color					*rgb;
	struct s_sphere_list	*next;
	struct s_sphere_list	*prev;
}	t_sphere_list;

typedef struct s_cylinder_list
{
	int						identifier;
	int						i;
	t_vector				*center;
	t_vector				*direction;
	int						radius;
	int						height;
	t_color					*rgb;
	struct s_cylinder_list	*next;
	struct s_cylinder_list	*prev;
}	t_cylinder_list;

typedef struct s_camera
{
	int			identifier;
	t_vector	*position;
	t_vector	*direction;
	int			fov;
}	t_camera;

typedef struct s_direct_light
{
	int			identifier;
	t_vector	*position;
	int			ratio;
	t_color		*rgb;
}	t_direct_light;

typedef struct s_ambient_light
{
	int			identifier;
	int			ratio;
	t_color		*rgb;
}	t_ambient_light;

typedef struct s_objects
{
	struct s_ambient_light	*amb_l;
	struct s_direct_light	*dir_l;
	struct s_camera			*cam;
	struct s_cylinder_list	*cy_head;
	struct s_sphere_list	*sp_head;
	struct s_plane_list		*pl_head;
}	t_objects;

typedef struct s_data
{
	struct s_objects	*objs;
}	t_data;

/*	PARSER	*/

t_objects	*init_objects(char **argv);

/*  DATA INITIALIZATION */

t_ambient_light	*get_ambient_light_data(char **argv);
t_direct_light	*get_direct_light_data(char **argv);
t_camera		*get_camera_data(char **argv);
t_cylinder_list	*creat_cylinder_list(char **argv);
t_sphere_list	*creat_sphere_list(char **argv);
t_plane_list	*creat_plane_list(char **argv);

/*	VECTOR MANAGEMENT	*/

t_vector	*vector_new(int x, int y, int z);
t_vector	*vector_from_str(char *x, char *y, char *z);
void		vector_change(t_vector *vec, int x, int y, int z);
void		vector_copy(t_vector *vec_src, t_vector *vec_dst);
void		vector_add(t_vector *vec_res, t_vector *vec_a, t_vector *vec_b);
void		vector_sub(t_vector *vec_res, t_vector *vec_a, t_vector *vec_b);
void		vector_scale(t_vector *vec_res, t_vector *vec_a, int n);
int			vector_dot(t_vector *vec_a, t_vector *vec_b);

/*	UTILS	*/

char	*get_obj_line(char *rt_file_path, char *obj_id, int obj_index);
int		float_to_fix(float n);
float	fix_to_float(int raw);
t_color	*color_from_str(char *red, char *green, char *blue);

/*	DEBUG	*/

void	debug_print_vector(t_vector *vec);
void	debug_print_rgb(t_color *rgb);
void	debug_print_cylinder_list(t_cylinder_list *head);
void	debug_print_cylinder_node(t_cylinder_list *node);
void	debug_print_ambient_light(t_ambient_light *obj);
void	debug_print_direct_light(t_direct_light *obj);
void	debug_print_camera(t_camera *obj);
void	debug_print_sphere_list(t_sphere_list *head);
void	debug_print_sphere_node(t_sphere_list *node);
void	debug_print_plane_list(t_plane_list *head);
void	debug_print_plane_node(t_plane_list *node);

#endif
