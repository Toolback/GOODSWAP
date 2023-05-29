/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:33:25 by jurenaul          #+#    #+#             */
/*   Updated: 2023/05/19 17:50:39 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	sort(t_stack **stack, int ac)
{
	int		i;
	int		res;
	int		temp;
	t_stack	*save;

	i = -1;
	res = 1;
	temp = 0;
	save = *stack;
	while (++i < ac)
	{
		if (save->next)
		{
			if (save->num > save->next->num)
			{
				temp = save->num;
				save->num = save->next->num;
				save->next->num = temp;
				res = 0;
			}
			save = save->next;
		}
	}
	if (!res)
		sort(stack, ac);
}

t_stack	*get_min_value(t_stack *tail)
{
	t_stack	*save;
	t_stack	*min;

	save = tail;
	while (save)
	{
		if (min->num > save->num)
			min = save;
		save = save->next;
	}
	return (min);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	copy_list_bis(t_stack *copy, t_stack *copy_node, t_stack *new_node)
{
	copy_node = copy;
	while (copy_node->next != NULL)
	{
		copy_node = copy_node->next;
	}
	copy_node->next = new_node;
}
