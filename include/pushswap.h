/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:33:36 by jurenaul          #+#    #+#             */
/*   Updated: 2023/05/29 22:19:56 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/include/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define A 0
# define B 1

// typedef struct s_stack	t_stack;
typedef struct s_stack
{
	struct s_stack	*prev;
	int				num;
	struct s_stack	*next;
	int				(*get_prev_count)(struct s_stack*);

}			t_stack;

// ########################
// - - - - sort - - - -
// ########################
void	small_sort(t_stack *stacks[2], int ac);
void	big_sort(t_stack *stacks[2], int ac);
int		sort_two_values(t_stack **stack);
int		sort_three_values(t_stack **stack);
void	sort_four_values(t_stack *stacks[2]);
void	sort_five_values(t_stack *stacks[2]);

// ########################
// - - - - utils - - - -
// ########################
void	sort(t_stack **stack, int ac);
t_stack	*get_min_value(t_stack *tail);
void	error_exit(void);
// int		has_duplicates(int argc, char *argv[]);
t_stack	*copy_list(t_stack *list);
void	copy_list_bis(t_stack *copy, t_stack *copy_node, t_stack *new_node);
int		ft_atoi_ps(const char *str);
void	is_sorted(t_stack **stack, int ac);
void	free_all(t_stack *stacks[2], int flag, char **values);
int		str_is_posneg(char *str);
void	free_stack(t_stack *stack);
void	check_args(char **values);
int		has_duplicate(char **av, char *num, int index);
// ########################
// - - - - lists_utils - - - -
// ########################
void	parse_stack_a(t_stack **stack, int ac, char **av);
t_stack	*add_value_back(t_stack *node, int value);
t_stack	*get_last_node(t_stack *tail);
t_stack	*get_first_node(t_stack *head);
int		lst_size(t_stack *stack);
int		get_prev_count(t_stack *stack);

// ########################
// - - - operations - - -
// ########################
// -> sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
//Ne fait rien s’il n’y en a qu’un ou aucun.
int		sa(t_stack **stack, int flag);
// -> sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
// Ne fait rien s’il n’y en a qu’un ou aucun.
int		sb(t_stack **stack, int flag);
// -> ss : sa et sb en même temps.
int		ss(t_stack *stacks[2]);

// -> pa (push a) : Prend le premier élément au sommet de b et le met sur a.
// Ne fait rien si b est vide.
void	pa(t_stack **stack_A, t_stack **stack_B, int flag);
// -> pb (push b) : Prend le premier élément au sommet de a et le met sur b.
// Ne fait rien si a est vide.
int		pb(t_stack **stack_A, t_stack **stack_B);

// -> ra (rotate a) : Décale d’une position vers le haut tous les élements
// de la pile a. Le premier élément devient le dernier.
int		ra(t_stack **stack, int flag);
// -> rb (rotate b) : Décale d’une position vers le haut tous les élements d
// e la pile b. Le premier élément devient le dernier.
int		rb(t_stack **stack_B, int flag);
// -> rr : ra et rb en même temps.
int		rr(t_stack **stack_A, t_stack **stack_B);

// -> rra (reverse rotate a) : Décale d’une position vers le bas tous les
// élements de la pile a. Le dernier élément devient le premier.
int		rra(t_stack **stack, int flag);
// -> rrb (reverse rotate b) : Décale d’une position vers le bas tous les
// élements de la pile b. Le dernier élément devient le premier.
int		rrb(t_stack **stack_B, int flag);
// -> rrr : rra et rrb en même temps.
int		rrr(t_stack **stack_A, t_stack **stack_B);

#endif
