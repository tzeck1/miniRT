#include "parser.h"

// static bool	line_validate(char **line)
// {
// 	bool	valid;

// 	valid = true;
// 	if (ft_strncmp(line[0], LIGHT_ID, ft_strlen(LIGHT_ID) + 1) == 0)
// 		valid = check_dir_light(line);
// 	else if (ft_strncmp(line[0], AMB_LIGHT_ID, ft_strlen(AMB_LIGHT_ID) + 1) == 0)
// 		valid = check_amb_light(line);
// 	else if (ft_strncmp(line[0], CAMERA_ID, ft_strlen(CAMERA_ID) + 1) == 0)
// 		valid = check_camera(line);
// 	else if (ft_strncmp(line[0], SPHERE_ID, ft_strlen(SPHERE_ID) + 1) == 0)
// 		valid = check_sphere(line);
// 	else if (ft_strncmp(line[0], PLANE_ID, ft_strlen(PLANE_ID) + 1) == 0)
// 		valid = check_plane(line);
// 	else if (ft_strncmp(line[0], CYLINDER_ID, ft_strlen(CYLINDER_ID) + 1) == 0)
// 		valid = check_cylinder(line);
// 	else
// 		valid = ft_line_error(UNKNOWN_ID);
// 	return (valid);
// }

// static bool	line_check(char *line)
// {
// 	char	**split_line;

// 	split_line = ft_split(line, ' ');
// 	if (line_validate(split_line) == false)
// 		return (false);
// 	return (true);
// }

static bool	line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i + 1] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (false);
		i++;
	}
	if (line[i] != '\n')
		return (false); 
	return (true);
}

static int	file_check(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		// ft_file_error(ARG_COUNT);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		printf("cannot open file\n");
	return (fd);
}

bool	parser(int argc, char **argv)
{
	int 	fd;
	bool	valid;
	char	*line;

	fd = file_check(argc, argv);
	printf("fd: %d\n", fd);
	printf("error: %s\n", strerror(errno));
	// valid = true;
	// line = get_next_line(fd);
	// printf("line: %s", line);
	// if (line == NULL)
	// 	ft_file_error(EMPTY_MAP);
	// while (line != NULL)
	// {
	// 	if (line_empty(line) == false)
	// 		printf("line is not empty\n");
	// 	else
	// 		printf("line is empty\n");
	// 		// valid = line_check(line);
	// 	free(line);
	// 	line = get_next_line(fd);
	// }
	close(fd);
	return (valid);
}
