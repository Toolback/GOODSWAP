/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:39:21 by jurenaul          #+#    #+#             */
/*   Updated: 2023/05/29 21:33:24 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	has_duplicate(char **av, char *num, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (ft_strlen(av[i]) != ft_strlen(num))
		{
			i++;
			continue ;
		}
		if (ft_strncmp(av[i], num, ft_strlen(av[1])) == 0)
			return (-1);
		i++;
	}
	return (0);
}

void	check_args(char **values)
{
	int		i;

	i = 0;
	while (values[i])
	{
		if (!str_is_posneg(values[i]))
			error_exit();
		if (has_duplicate(values, values[i], i) == -1)
		{
			error_exit();
		}
		ft_atoi_ps(values[i]);
		i++;
	}
}

void	free_stack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	// if(stack->next)
	free_stack(stack->next);
	free(stack);
}

int	str_is_posneg(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_all(t_stack *stacks[2], int flag, char **values)
{
	if (flag == 1)
	{
		int i = 0;
		while(values[i])
		{
			free(values[i]);
			i++;
		}
		free(values);
	}
	free_stack(stacks[0]);
	free_stack(stacks[1]);
	stacks[0] = NULL;
	stacks[1] = NULL;
	// free(stacks);
}
