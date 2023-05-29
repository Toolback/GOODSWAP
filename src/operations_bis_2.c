/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bis_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:31:54 by jurenaul          #+#    #+#             */
/*   Updated: 2023/05/19 18:09:10 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	rrr(t_stack **stack_A, t_stack **stack_B)
{
	if (!rra(stack_A, 0) || !rrb(stack_B, 0))
		return (0);
	ft_printf("rra\n");
	return (1);
}

// pb (push b) : Prend le premier élément au sommet de a et le met sur b.
// Ne fait rien si a est vide.
int	pb(t_stack **stack_A, t_stack **stack_B)
{
	pa(stack_B, stack_A, 0);
	ft_printf("pb\n");
	return (1);
}

void	is_sorted(t_stack **stack, int ac)
{
	int		i;
	t_stack	*save;

	i = -1;
	save = *stack;
	while (++i < ac)
	{
		if (save->next)
		{
			if (save->num > save->next->num)
				return ;
			save = save->next;
		}
	}
	exit(0);
}

int	ft_atoi_ps(const char *str)
{
	int				cnt;
	int				neg;
	long long int	num;

	cnt = 0;
	neg = 1;
	num = 0;
	if (!str)
		return (0);
	while ((str[cnt] >= '\t' && str[cnt] <= '\r') || str[cnt] == ' ')
		cnt++;
	if (str[cnt] == '-')
		neg = -1;
	if (str[cnt] == '+' || str[cnt] == '-')
		cnt++;
	while (str[cnt] >= '0' && str[cnt] <= '9')
	{
		num = (str[cnt] - '0') + (num * 10);
		cnt++;
	}
	if (num >= MAX_INT || (num * neg) <= MIN_INT)
		error_exit();
	return ((int)(num * neg));
}
