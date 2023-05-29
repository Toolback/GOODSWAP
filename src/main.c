/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:10:49 by jurenaul          #+#    #+#             */
/*   Updated: 2023/05/29 22:25:26 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	small_sort(t_stack *stacks[2], int ac)
{
	if (ac == 2)
		sort_two_values(&stacks[A]);
	if (ac == 3)
		sort_three_values(&stacks[A]);
	if (ac == 4)
		sort_four_values(stacks);
	if (ac == 5)
		sort_five_values(stacks);
}

void	grrr(t_stack *stacks[2], char **values, int ac)
{
	parse_stack_a(&stacks[A], ac, values);
	stacks[B] = NULL;
	is_sorted(stacks, ac);
	if (ac <= 5)
		small_sort(stacks, ac);
	if (ac > 5)
		big_sort(stacks, ac);
}

t_stack	*copy_list(t_stack *list)
{
	t_stack	*copy;
	t_stack	*curr_node;
	t_stack	*new_node;
	t_stack	*copy_node;

	copy = NULL;
	copy_node = NULL;
	curr_node = list;
	while (curr_node != NULL)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		new_node->num = curr_node->num;
		new_node->next = NULL;
		if (copy == NULL)
			copy = new_node;
		else
		{
			copy_list_bis(copy, copy_node, new_node);
		}
		curr_node = curr_node->next;
	}
	return (copy);
}

int	get_prev_count(t_stack *stack)
{
	int		count;
	t_stack	*save;

	count = 0;
	if (!stack)
	{
		ft_printf("get_prev_count: stack is null\n");
		return (-1);
	}
	save = stack;
	while (save->prev)
	{
		save = save->prev;
		count++;
	}
	return (count);
}

static int	count_words(const char *str, char c)
{
	int i;
	int trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char		**ft_split_custom(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s || !(split = malloc((count_words(s, c) + 1) * sizeof(char *))))
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}


int	main(int ac, char **av)
{
	t_stack	*stacks[2];
	char	**values;
	int		flag;

	flag = 0;
	if (ac > 1)
	{
		if (ac == 2)
		{
			flag = 1;
			values = ft_split_custom((const char *) av[1], ' ');
			ac = ft_strarrlen(values);
		}
		else
		{
			values = av + 1;
			ac = ac - 1;
		}
		check_args(values);
		grrr(stacks, values, ac);
		free_all(stacks, flag, values);
	}
	return (0);
}
