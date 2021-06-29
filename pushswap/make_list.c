
#include "../push_swap.h"

int		*make_list(char **argv, int len, int argc, t_info *info)
{
	char *combine_argv;
	int i;
	int j;
	int z;
	
	ft_isnumber(argv, argc);
	if (!(combine_argv = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 1;
	z = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			combine_argv[z++] = argv[i][j++];
		combine_argv[z++] = ' ';
		i++;
	}
	return (ft_split_atoi(combine_argv, ' ', info));
}

int		*get_list(int argc, char **argv, t_info *info)
{
	int i;
	int j;
	int len;
	
	i = 1;
	len = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			j++;
		len += j + 1;
		i++;
	}
	return (make_list(argv, len, argc, info));
}
