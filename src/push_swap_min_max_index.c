/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_min_max_index.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:47:06 by ssucha            #+#    #+#             */
/*   Updated: 2026/02/16 23:29:53 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_or_second_max(int n, t_node **stack)
{
	int		max;
	int		second_max;
	int		cost_max;
	int		cost_second_max;
	t_node	*tmp;

	max = find_max_index(stack);
	second_max = max - 1;
	cost_max = n;
	cost_second_max = n;
	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->index == max)
			cost_max = ft_abs(cost_to_top(stack, tmp->index));
		if (tmp->index == second_max)
			cost_second_max = ft_abs(cost_to_top(stack, tmp->index));
		tmp = tmp->next;
		if (!tmp || tmp == *stack)
			break ;
	}
	if (cost_second_max < cost_max - 1)
		return (second_max);
	return (max);
}

int	min_or_second_min(int n, t_node **stack)
{
	int		min;
	int		second_min;
	int		cost_min;
	int		cost_second_min;
	t_node	*tmp;

	min = find_min_index(stack);
	second_min = min - 1;
	cost_min = n;
	cost_second_min = n;
	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->index == min)
			cost_min = ft_abs(cost_to_top(stack, tmp->index));
		if (tmp->index == second_min)
			cost_second_min = ft_abs(cost_to_top(stack, tmp->index));
		tmp = tmp->next;
		if (!tmp || tmp == *stack)
			break ;
	}
	if (cost_second_min < cost_min - 1)
		return (second_min);
	return (min);
}

/**
 * @brief Finds the lowest index in the stack and returns its value.
 * @return The value of the lowest index in the stack.
 */
int	find_min_index(t_node **stack)
{
	int		min;
	t_node	*tmp;
	t_node	*head;

	if (!stack || !*stack)
		return (INT_MAX);
	head = *stack;
	min = head->index;
	if (!head->next)
		return (min);
	tmp = head->next;
	while (tmp && tmp != head)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

/**
 * @brief Finds the largest index in the stack and returns its value.
 * @return The value of the largest index in the stack.
 */
int	find_max_index(t_node **stack)
{
	int		max;
	t_node	*tmp;
	t_node	*head;

	if (!stack || !*stack)
		return (INT_MIN);
	head = *stack;
	max = head->index;
	if (!head->next)
		return (max);
	tmp = head->next;
	while (tmp && tmp != head)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}
