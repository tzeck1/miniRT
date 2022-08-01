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
# include <limits.h>
# include <float.h>

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
typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
	int	a;
}	t_color;

typedef struct s_ray
{
	t_vec	og;
	t_vec	dir;
	float	t_min;
	float	t_max;
}	t_ray;

/**
 * @param id: pl in rt file
 * @param i: index for node in pl_list
 * @param center: pos of plane
 * @param dir: normalized oriantation vector
 * @param rgb: color struct
 */
typedef struct s_pl_list
{
	int					id;
	int					i;
	t_vec				center;
	t_vec				dir;
	t_color				rgb;
	struct s_pl_list	*next;
	struct s_pl_list	*prev;
}	t_pl_list;

/**
 * @param id: sp in rt file
 * @param i: index for node in sp_list
 * @param center: pos of sphere
 * @param radius: sphere diameter / 2
 * @param rgb: color struct
 */
typedef struct s_sp_list
{
	int					id;
	int					i;
	t_vec				center;
	float				radius;
	t_color				rgb;
	struct s_sp_list	*next;
	struct s_sp_list	*prev;
}	t_sp_list;

/**
 * @param id: cy in rt file
 * @param i: index for node in cy_list
 * @param center: pos of cylinder
 * @param dir: normalized oriantation vector
 * @param radius: cylinder diameter / 2
 * @param height: cylinder height
 * @param rgb: color struct
 */
typedef struct s_cy_list
{
	int					id;
	int					i;
	t_vec				center;
	t_vec				dir;
	float				radius;
	float				height;
	t_color				rgb;
	struct s_cy_list	*next;
	struct s_cy_list	*prev;
}	t_cy_list;

/**
 * @param id: C in rt file
 * @param pos: pos of camera
 * @param dir: normalized oriantation vector
 * @param fov: horizontal field of view in degrees
 */
typedef struct s_camera
{
	int		id;
	t_vec	pos;
	t_vec	dir;
	float	fov;
}	t_camera;

/**
 * @param id: L in rt file
 * @param pos: pos of direct light
 * @param ratio: light brightness ratio
 * @param rgb: color struct
 */
typedef struct s_dir_light
{
	int		id;
	t_vec	pos;
	float	ratio;
	t_color	rgb;
}	t_dir_light;

/**
 * @param id: A in rt file
 * @param ratio: light brightness ratio
 * @param rgb: color struct
 */
typedef struct s_amb_light
{
	int		id;
	float	ratio;
	t_color	rgb;
}	t_amb_light;

typedef struct s_objects
{
	struct s_amb_light	*amb_l;
	struct s_dir_light	*dir_l;
	struct s_camera		*cam;
	struct s_cy_list	*cy_head;
	struct s_sp_list	*sp_head;
	struct s_pl_list	*pl_head;
}	t_objects;

typedef struct s_screen
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			height;
	int			width;
}	t_screen;

typedef struct s_data
{
	struct s_objects	*objs;
	struct s_screen		*screen;
}	t_data;

void		init_mlx(t_data *data);

/*	PARSER	*/

bool		parser(int argc, char **argv);

/*  DATA INITIALIZATION */

t_objects	*init_objects(char *rt_file_path);
t_amb_light	*get_amb_light_data(char *rt_file_path);
t_dir_light	*get_dir_light_data(char *rt_file_path);
t_camera	*get_camera_data(char *rt_file_path);

/*	RAY TRACER	*/

void		ray_tracing(t_screen *screen, t_objects *objs);

/*	DATA FREE	*/

void		free_objects(t_objects *objs);

/*	VECTOR MANAGEMENT	*/

t_vec		vec_new(float x, float y, float z);
t_vec		vec_from_str(char *x, char *y, char *z);
t_vec		vec_change(t_vec vec, float x, float y, float z);
t_vec		vec_copy(t_vec vec_src);
t_vec		vec_add(t_vec vec_a, t_vec vec_b);
t_vec		vec_sub(t_vec vec_a, t_vec vec_b);
t_vec		vec_scale(t_vec vec, float n);
float		vec_dot(t_vec vec_a, t_vec vec_b);
float		vec_len(t_vec vec);
t_vec		vec_norm(t_vec vec);

/*	UTILS	*/

char		*get_obj_line(char *rt_file_path, char *obj_id, int obj_index);
int			float_to_fix(float n);
float		fix_to_float(int raw);
t_color		color_from_str(char *red, char *green, char *blue);
void		replace_commas(char *line);

/*	DEBUG	*/

void		debug_print_vector(t_vec vec);
void		debug_print_rgb(t_color rgb);
void		debug_print_cylinder_list(t_cy_list *head);
void		debug_print_cylinder_node(t_cy_list *node);
void		debug_print_ambient_light(t_amb_light *obj);
void		debug_print_direct_light(t_dir_light *obj);
void		debug_print_camera(t_camera *obj);
void		debug_print_sphere_list(t_sp_list *head);
void		debug_print_sphere_node(t_sp_list *node);
void		debug_print_plane_list(t_pl_list *head);
void		debug_print_plane_node(t_pl_list *node);
void		print_2d_array(char **array);

#endif
