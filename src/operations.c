/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:31:54 by jurenaul          #+#    #+#             */
/*   Updated: 2023/05/17 15:08:02 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
//Ne fait rien s’il n’y en a qu’un ou aucun.
int	sa(t_stack **stack, int flag)
{
	t_stack	*node_1;
	t_stack	*node_2;

	if ((*stack)->next)
	{
		node_1 = *stack;
		node_2 = node_1->next;
		node_1->prev = node_2;
		node_2->prev = NULL;
		node_1->next = node_2->next;
		if (node_1->next)
			node_1->next->prev = node_1;
		node_2->next = node_1;
		*stack = node_2;
		if (flag)
			ft_printf("sa\n");
		return (1);
	}
	return (0);
}

// sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
// Ne fait rien s’il n’y en a qu’un ou aucun.
int	sb(t_stack **stack, int flag)
{
	if (!sa(stack, 0))
	{
		ft_printf("sb : No Stack Allocated");
		return (0);
	}
	if (flag)
		ft_printf("sb\n");
	return (1);
}

// ss : sa et sb en même temps.
int	ss(t_stack *stacks[2])
{
	if (!sa(&stacks[A], 0) || sb(&stacks[B], 0))
	{
		ft_printf("ss : No Stack Allocated");
		return (0);
	}
	ft_printf("ss\n");
	return (1);
}

void	refacto(t_stack **stack_A, t_stack **stack_B)
{
	t_stack	*temp;

	temp = *stack_B;
	if ((*stack_B)->next)
	{
		(*stack_B)->next->prev = NULL;
		*stack_B = (*stack_B)->next;
	}
	else
		*stack_B = NULL;
	if (*stack_A)
	{
		temp->next = *stack_A;
		(*stack_A)->prev = temp;
		*stack_A = temp;
	}
	else
	{
		temp->next = NULL;
		temp->prev = NULL;
		*stack_A = temp;
	}
}

// pa (push a) : Prend le premier élément au sommet de b et le met sur a.
// Ne fait rien si b est vide.
void	pa(t_stack **stack_A, t_stack **stack_B, int flag)
{
	if (*stack_B)
	{
		refacto(stack_A, stack_B);
		if (flag)
			ft_printf("pa\n");
	}
}
