#ifndef PARSER_H
# define PARSER_H

# include "../../includes/miniRT.h"

# define ARG_COUNT_MSG "Program requires exactly one argument!\n"
# define OPEN_ERR_MSG "Cannot open file!\n"
# define WRONG_TYPE_MSG "Wrong or unknown identifier!\n"
# define EMPTY_MAP_MSG "File feels empty (me too)!\n"
# define MULT_CAM_MSG "Multiple cameras!\n"
# define MULT_AMB_MSG "Multiple ambient lightings!\n"
# define MULT_DIR_MSG "Multiple direct lightings!\n"
# define NO_CAM_MSG "Program requires exactly one camera!\n"
# define NO_LIGHT_MSG "Program requires at least one light source!\n"
# define BAD_ARG_MSG "Bad object info!\n"
# define NO_FLOAT_MSG "Invalid number!\n"

# define CAM_LINE_SIZE 4
# define AMB_LINE_SIZE 3
# define DIR_LINE_SIZE 4
# define SP_LINE_SIZE 4
# define CY_LINE_SIZE 6
# define PL_LINE_SIZE 4


typedef enum	e_error
{
	ARG_COUNT,
	OPEN_ERR,
	WRONG_TYPE,
	EMPTY_MAP,
	MULT_CAM,
	MULT_AMB,
	MULT_DIR,
	NO_CAM,
	NO_LIGHT,
	BAD_ARG,
	NO_FLOAT
}	t_error;

typedef enum	e_cam_index
{
	CAM_ID,
	CAM_XYZ,
	CAM_NO_VEC,
	CAM_FOV
}	t_cam_index;

typedef enum	e_amb_index
{
	AMB_ID,
	AMB_RATIO,
	AMB_RGB
}	t_amb_index;

typedef enum	e_dir_index
{
	DIR_ID,
	DIR_XYZ,
	DIR_RATIO,
	DIR_RGB
}	t_dir_index;

typedef enum	e_sp_index
{
	SP_ID,
	SP_XYZ,
	SP_DIA,
	SP_RGB
}	t_sp_index;

typedef enum	e_cy_index
{
	CY_ID,
	CY_XYZ,
	CY_NO_VEC,
	CY_DIA,
	CY_HEIGHT,
	CY_RGB,
}	t_cy_index;

typedef enum	e_pl_index
{
	PL_ID,
	PL_XYZ,
	PL_NO_VEC,
	PL_RGB
}	t_pl_index;

typedef struct s_parse_errors
{
	int		line;
	bool	error;
	bool	cam;
	bool	amb_light;
	bool	dir_light;
}	t_parse_errors;

/*	FILE_CHECK	*/

int		file_check(int argc, char **argv);

/*	LINE_CHECK	*/

void	line_content_check(char *line, t_parse_errors *parse_errors);
bool	check_pl_line(char **line, t_parse_errors *parse_errors);
bool	check_cy_line(char **line, t_parse_errors *parse_errors);
bool	check_sp_line(char **line, t_parse_errors *parse_errors);
bool	check_dir_line(char **line, t_parse_errors *parse_errors);
bool	check_amb_line(char **line, t_parse_errors *parse_errors);
bool	check_cam_line(char **line, t_parse_errors *parse_errors);

/*	ELEMENT_CHECK	*/

bool	rgb_range_check(char *value);
bool	diameter_height_check(char *diameter, t_parse_errors *parse_errors);
bool	ratio_check(char *ratio, t_parse_errors *parse_errors);
bool	rgb_check(char *line, t_parse_errors *parse_errors);
bool	normalized_check(char *x_value, char *y_value, char *z_value);
bool	fov_check(char *line, t_parse_errors *parse_error);
bool	orientation_check(char *line, t_parse_errors *parse_errors);
bool	xyz_check(char *line, t_parse_errors *parse_errors);

/*	ERROR	*/

void	ft_parse_error(int error, int line);
void	ft_file_error(int error, int fd);

/*	UTILS	*/

bool	line_empty(char *line);
int		ft_count_array(char **xyz_block);
bool	float_check(char *block);

#endif