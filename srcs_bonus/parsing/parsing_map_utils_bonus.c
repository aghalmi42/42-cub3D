/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:55:58 by aghalmi           #+#    #+#             */
/*   Updated: 2026/04/15 13:55:58 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3D_bonus.h"

t_line	*add_line(t_line *lst, char *content)
{
	t_line	*new;
	t_line	*tmp;

	new = malloc(sizeof(t_line));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	if (lst == NULL)
		return (new);
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (lst);
}

int	count_line(t_line *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	free_lst(t_line *lst)
{
	t_line	*tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

char	**convert_lst_to_array(t_line *lst, int size)
{
	char	**array;
	int		i;

	i = 0;
	array = malloc(sizeof(char *) * (size + 1));
	if (!array)
		return (NULL);
	while (i < size && lst != NULL)
	{
		array[i] = lst->content;
		lst = lst->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}
