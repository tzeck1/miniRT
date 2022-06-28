#ifndef PARSER_H
# define PARSER_H

# include "../../includes/miniRT.h"

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
	UNKNOWN_ID,
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

void	ft_file_error(int error, int fd);
bool	check_for_rt(char *file);
int		file_check(int argc, char **argv);

/*	LINE_CHECK	*/
bool	line_check(int fd);
void	ft_parse_error(int error, int line);
bool	xyz_check(char *line, t_parse_errors *parse_errors);
bool	orientation_check(char *line, t_parse_errors *parse_errors);
bool	fov_check(char *line, t_parse_errors *parser_error);
bool	rgb_check(char *line, t_parse_errors *parse_errors);
bool	ratio_check(char *ratio, t_parse_errors *parse_errors);
bool	diameter_height_check(char *diameter, t_parse_errors *parse_errors);


#endif