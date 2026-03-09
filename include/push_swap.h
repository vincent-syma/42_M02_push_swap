/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:52:23 by ssucha            #+#    #+#             */
/*   Updated: 2026/03/09 19:44:15 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
	int				number;
	int				index;
	struct s_node	*next;
}	t_node;

// READING INPUT & ERROR CHECK

int		count_numbers(int argc, char **argv);
int		*normalize_input(int argc, char **argv, int n_arg);
void	error(void);
int		find_duplicates(int	*args, int argc);

t_node	*create_stack_a(int *args, int argc);

// NODE MANIPULATION

t_node	*new_node(int number, int index);
void	node_lst_add_front(t_node **node_lst, t_node *new);
void	node_lst_add_back(t_node **node_lst, t_node *new);
void	node_lst_clear(t_node **node_lst);
int		ft_node_lst_size(t_node *node_lst);
t_node	*ft_node_lst_last(t_node *head);

// PUSH_SWAP ACTIONS

void	swap(t_node **stack_a, t_node **stack_b, char *instr);
void	push(t_node **stack_a, t_node **stack_b, char *instr);
void	rotate(t_node **stack_a, t_node **stack_b, char *instr);
void	rev_rotate(t_node **stack_a, t_node **stack_b, char *instr);

void	rotate_index_to_top(t_node **stack_a, t_node **stack_b, int idx,
			char stack);
void	rotate_up(t_node **stack_a, t_node **stack_b, int idx, char *instr);
void	rotate_down(t_node **stack_a, t_node **stack_b, int idx, char *instr);

// SORTING

void	sort(int n, t_node **stack_a, t_node **stack_b);
void	from_a_to_b(int n, t_node **stack_a, t_node **stack_b);
void	from_b_to_a(int n, t_node **stack_a, t_node **stack_b);

// INDEX COMPARATION

int		find_min_index(t_node **stack);
int		find_max_index(t_node **stack);
int		cost_to_top(t_node **stack, int idx);
int		lowest_cost_index(t_node **stack, int chunk, int n);
int		max_or_second_max(int n, t_node **stack_b);
int		min_or_second_min(int n, t_node **stack_a);
int		is_circular(t_node **stack);

#endif