#include "parser.h"

t_data	*init_data(char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	data = NULL;
	if (data == NULL)
		ft_error(strerror(errno), NULL);
}