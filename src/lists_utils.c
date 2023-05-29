/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:09:28 by jurenaul          #+#    #+#             */
/*   Updated: 2023/03/15 16:23:50 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	parse_stack_a(t_stack **stack, int ac, char **av)
{
	int		i;
	t_stack	*last;

	i = 1;
	*stack = NULL;
	*stack = add_value_back(*stack, ft_atoi(av[0]));
	last = *stack;
	while (ac > i)
	{
		last = add_value_back(last, ft_atoi(av[i++]));
	}
}

t_stack	*add_value_back(t_stack *node, int value)
{
	if (!node)
	{
		node = (t_stack *)malloc(sizeof(t_stack));
		if (node == NULL)
			error_exit();
		node->prev = NULL;
		node->num = value;
		node->next = NULL;
		node->get_prev_count = &get_prev_count;
		return (node);
	}
	else
	{
		node->next = (t_stack *)malloc(sizeof(t_stack));
		if (node->next == NULL)
			error_exit();
		node->next->prev = node;
		node->next->num = value;
		node->next->next = NULL;
		node->next->get_prev_count = &get_prev_count;
		return (node->next);
	}
}

t_stack	*get_first_node(t_stack *head)
{
	t_stack	*temp;

	if (!head)
	{
		ft_printf("get_first_node: head is null\n");
		return (NULL);
	}
	temp = head;
	while (temp->prev)
		temp = temp->prev;
	return (temp);
}

t_stack	*get_last_node(t_stack *tail)
{
	t_stack	*temp;

	if (!tail)
	{
		ft_printf("get_last_node: tail is null\n");
		return (NULL);
	}
	temp = tail;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

int	lst_size(t_stack *stack)
{
	int		num;
	t_stack	*save;

	num = 0;
	if (stack == NULL)
	{
		return (num);
	}
	save = stack;
	while (save)
	{
		num++;
		save = save->next;
	}
	return (num);
}
