#include "parser.h"

static int	check_line(char **line)
{
	int	error_count;

	error_count = 0;
	if (ft_strncmp(line[0], LIGHT_ID, ft_strlen(LIGHT_ID) + 1) == 0)
		error_count += check_dir_light(line);	// WRITEME
	else if (ft_strncmp(line[0], AMB_LIGHT_ID, ft_strlen(AMB_LIGHT_ID) + 1) == 0)
		error_count += check_amb_light(line);	// WRITEME
	else if (ft_strncmp(line[0], CAMERA_ID, ft_strlen(CAMERA_ID) + 1) == 0)
		error_count += check_camera(line);	//WRITEME
	else if (ft_strncmp(line[0], SPHERE_ID, ft_strlen(SPHERE_ID) + 1) == 0)
		error_count += check_sphere(line);	//WRITEME
	else if (ft_strncmp(line[0], PLANE_ID, ft_strlen(PLANE_ID) + 1) == 0)
		error_count += check_plane(line);	//WRITEME
	else if (ft_strncmp(line[0], CYLINDER_ID, ft_strlen(CYLINDER_ID) + 1) == 0)
		error_count += check_cylinder(line);	//WRITEME
	else
		error_count += ft_soft_error(UNKNOWN_ID);
	return (error_count);
}

static int	general_check(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		ft_pars_error(ARG_COUNT);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_pars_error(OPEN_ERR);
	// might be missing something, idk yet
}

int	parser(int argc, char **argv)
{
	int 	fd;
	char	*line;
	char	**split_line;
	int		error_count;

	fd = general_check(argc, argv);
	line = get_next_line(fd);
	if (line == NULL)
		ft_pars_error(EMPTY_MAP);	// FIXME there bight be some spaces but nothing else, technically not empty but would this be enough?
	error_count = 0;
	while (line != NULL)
	{
		invalid_char(line);
		split_line = ft_split(line, ' ');
		if (line_empty(split_line) == false)
			error_count += check_line(split_line);	// FIXME do we want to free 'line' before exit? If yes then this func needs a second parameter
		ft_free_split(split_line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (error_count);
}