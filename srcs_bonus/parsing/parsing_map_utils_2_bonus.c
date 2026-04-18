/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils_2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:55:45 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:55:45 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3D_bonus.h"

int	check_extension(char *file_name)
{
	int	len;

	if (!file_name)
		return (0);
	len = ft_strlen(file_name);
	if (len < 4)
		return (0);
	if (ft_strncmp(file_name + len - 4, ".cub", 4) != 0)
		return (0);
	return (1);
}

int	open_file(char *file_name)
{
	int	fd;

	if (!check_extension(file_name))
	{
		printf("Error\nInvalid file extension\n");
		return (-1);
	}
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		printf("Error\nUnable to open file\n");
	return (fd);
}

t_line	*processus_of_line(t_line *lst, char *line)
{
	char	*after_strtrim;

	after_strtrim = ft_strtrim(line, "\n");
	free(line);
	if (!after_strtrim)
		return (NULL);
	lst = add_line(lst, after_strtrim);
	if (!lst)
		free(after_strtrim);
	return (lst);
}

t_line	*read_line(int fd)
{
	t_line	*lst;
	t_line	*new_lst;
	char	*line;

	lst = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		new_lst = processus_of_line(lst, line);
		if (!new_lst)
		{
			free_lst(lst);
			close(fd);
			return (NULL);
		}
		lst = new_lst;
		line = get_next_line(fd);
	}
	return (lst);
}

char	**read_file_to_array(char *file_name)
{
	t_line	*lst;
	char	**array;
	int		fd;

	fd = open_file(file_name);
	if (fd < 0)
		return (NULL);
	lst = read_line(fd);
	close(fd);
	if (!lst || count_line(lst) == 0)
	{
		free_lst(lst);
		printf("Error\nFile Empty\n");
		return (NULL);
	}
	array = convert_lst_to_array(lst, count_line(lst));
	free_lst(lst);
	return (array);
}
