/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:39:21 by jurenaul          #+#    #+#             */
/*   Updated: 2023/05/29 22:42:12 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	sort_two_values(t_stack **stack)
{
	if ((*stack)->num > (*stack)->next->num)
	{
		sa(stack, 1);
	}
	return (0);
}

int	sort_three_values_bis(t_stack **stack)
{
	if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num
		&& (*stack)->num > (*stack)->next->next->num)
	{
		ra(stack, 1);
	}
	else if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num
		&& (*stack)->num < (*stack)->next->next->num)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num
		&& (*stack)->num > (*stack)->next->next->num)
	{
		rra(stack, 1);
	}
	return (0);
}

int	sort_three_values(t_stack **stack)
{
	if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num
		&& (*stack)->num < (*stack)->next->next->num)
	{
		sa(stack, 1);
	}
	else if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num
		&& (*stack)->num > (*stack)->next->next->num)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	sort_three_values_bis(stack);
	return (0);
}

void	sort_four_values(t_stack *stacks[2])
{
	pb(&stacks[A], &stacks[B]);
	sort_three_values(&stacks[A]);
	// ft_printf("DONE THREE");
	if (stacks[B]->num > stacks[A]->num
		&& stacks[B]->num < stacks[A]->next->num)
	{
		pa(&stacks[A], &stacks[B], 1);
		sa(&stacks[A], 1);
	}
	else if (stacks[B]->num > stacks[A]->next->num
		&& stacks[B]->num < stacks[A]->next->next->num)
	{
		rra(&stacks[A], 1);
		pa(&stacks[A], &stacks[B], 1);
		ra(&stacks[A], 1);
		ra(&stacks[A], 1);
	}
	else if (stacks[B]->num > stacks[A]->next->next->num)
	{
		pa(&stacks[A], &stacks[B], 1);
		ra(&stacks[A], 1);
	}
	else
	{
		pa(&stacks[A], &stacks[B], 1);
	}
}

void	sort_five_values(t_stack *stacks[2])
{
	int		index;
	t_stack	*min;

	ft_printf("");
	min = get_min_value(stacks[A]);
	index = min->get_prev_count(min);
	if (index == 1)
		sa(&stacks[A], 1);
	else if (index == 2)
	{
		ra(&stacks[A], 1);
		sa(&stacks[A], 1);
	}
	else if (index == 3)
	{
		rra(&stacks[A], 1);
		rra(&stacks[A], 1);
	}
	else if (index == 4)
		rra(&stacks[A], 1);
	pb(&stacks[A], &stacks[B]);
	sort_four_values(&stacks[A]);
	pa(&stacks[A], &stacks[B], 1);
}
