/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:09:56 by jurenaul          #+#    #+#             */
/*   Updated: 2023/05/29 22:25:33 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	grrrrr(t_stack **stack, t_stack *temp, t_stack *save_copy,
t_stack *save)
{
	int	i;

	i = 0;
	while (*stack)
	{
		temp = save_copy;
		i = 0;
		while (temp)
		{
			if ((*stack)->num == temp->num)
			{
				(*stack)->num = i;
				break ;
			}
			i++;
			temp = temp->next;
		}
		*stack = (*stack)->next;
	}
	*stack = save;
	free_stack(save_copy);
}

void	simplify(t_stack **stack, int ac)
{
	t_stack	*save;
	t_stack	*save_copy;
	t_stack	*temp;

	save = *stack;
	save_copy = NULL;
	temp = NULL;
	save_copy = copy_list(save);
	sort(&save_copy, ac);
	grrrrr(stack, temp, save_copy, save);
}

int	grrrcheckbytes(int size)
{
	int	max_num;
	int	max_bits;

	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	return (max_bits);
}

void	radix_sort(t_stack *stacks[2], int ac)
{
	int	i;
	int	j;
	int	num;
	int	size;
	int	max_bits;

	i = 0;
	size = ac;
	max_bits = grrrcheckbytes(size);
	while (i < max_bits)
	{
	j = 0;
		while (j < size)
		{
			num = stacks[A]->num;
			if (((num >> i) & 1) == 1)
				ra(&stacks[A], 1);
			else
				pb(&stacks[A], &stacks[B]);
			j++;
		}
		while (stacks[B])
			pa(&stacks[A], &stacks[B], 1);
		i++;
	}
}

void	big_sort(t_stack *stacks[2], int ac)
{
	simplify(&stacks[A], ac);
	radix_sort(stacks, ac);
}
