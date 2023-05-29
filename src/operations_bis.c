/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:31:54 by jurenaul          #+#    #+#             */
/*   Updated: 2023/03/15 16:08:30 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	ra(t_stack **stack, int flag)
{
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
	{
		ft_printf("ra : No Stack Allocated, or only one element");
		return (0);
	}
	temp = *stack;
	*stack = temp->next;
	(*stack)->prev = NULL;
	temp->next = NULL;
	temp->prev = get_last_node(*stack);
	temp->prev->next = temp;
	if (flag)
		ft_printf("ra\n");
	return (1);
}

int	rb(t_stack **stack_B, int flag)
{
	if (!ra(stack_B, 0))
		return (0);
	if (flag)
		ft_printf("rb\n");
	return (1);
}

int	rr(t_stack **stack_A, t_stack **stack_B)
{
	if (!ra(stack_A, 0) || !rb(stack_B, 0))
		return (0);
	ft_printf("rr\n");
	return (1);
}

int	rra(t_stack **stack, int flag)
{
	t_stack	*last_node;
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
	{
		ft_printf("rra : No Stack Allocated, or only one element");
		return (0);
	}
	last_node = get_last_node(*stack);
	last_node->prev->next = NULL;
	temp = *stack;
	last_node->prev = NULL;
	last_node->next = temp;
	temp->prev = last_node;
	*stack = last_node;
	if (flag)
		ft_printf("rra\n");
	return (1);
}

int	rrb(t_stack **stack_B, int flag)
{
	if (!rra(stack_B, 0))
		return (0);
	if (flag)
		ft_printf("rrb\n");
	return (1);
}
