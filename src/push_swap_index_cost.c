/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_index_cost.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:47:06 by ssucha            #+#    #+#             */
/*   Updated: 2026/02/16 23:14:44 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds an index with the best cost.
 * @return The index with a best cost.
 */
int	lowest_cost_index(t_node **stack, int chunk, int n)
{
	int		cost;
	t_node	*tmp;

	cost = 0;
	while (cost <= n / 2)
	{
		tmp = *stack;
		while (tmp)
		{
			if (tmp->index < chunk
				&& ft_abs(cost_to_top(stack, tmp->index)) == cost)
				return (tmp->index);
			tmp = tmp->next;
			if (tmp == *stack)
				break ;
		}
		cost++;
	}
	return (-1);
}

/**
 * @brief Counts the steps needed to rotate number (node)
 * up or down the stack to put it on the top.
 * @return Number of steps, + for rotate up, - for rotate down.
 */
int	cost_to_top(t_node **stack, int idx)
{
	t_node	*tmp;
	int		stack_size;
	int		pos;

	if (!stack || !*stack)
		return (0);
	stack_size = ft_node_lst_size(*stack);
	pos = 0;
	tmp = *stack;
	while (tmp && tmp->index != idx)
	{
		tmp = tmp->next;
		pos++;
	}
	if (pos <= stack_size / 2)
		return (pos);
	return (pos - stack_size);
}
