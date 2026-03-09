/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_chunk_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:47:06 by ssucha            #+#    #+#             */
/*   Updated: 2026/02/16 23:39:56 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Pushes numbers from stack a to stack b in defined chunks
 * according to the best cost.
 */
void	from_a_to_b(int n, t_node **stack_a, t_node **stack_b)
{
	int		chunk;
	int		current_chunk;
	int		numbers_pushed;
	int		target;

	chunk = (int)(n / 6.15);
	current_chunk = chunk;
	numbers_pushed = 0;
	while (*stack_a)
	{
		target = lowest_cost_index(stack_a, current_chunk, n);
		rotate_index_to_top(stack_a, stack_b, target, 'a');
		push(stack_a, stack_b, "pb");
		numbers_pushed++;
		if ((*stack_b)->index < current_chunk - (int)(chunk / 2.0))
			rotate(stack_a, stack_b, "rb");
		if (numbers_pushed >= current_chunk)
			current_chunk += chunk;
	}
}

/**
 * @brief Pushes numbers from stack b to stack a from max to min index.
 */
void	from_b_to_a(int n, t_node **stack_a, t_node **stack_b)
{
	int		target;

	while (*stack_b)
	{
		target = max_or_second_max(n, stack_b);
		rotate_index_to_top(stack_a, stack_b, target, 'b');
		push(stack_a, stack_b, "pa");
		if ((*stack_a)->next && (*stack_a)->index > (*stack_a)->next->index)
			swap(stack_a, stack_b, "sa");
	}
	if (is_circular(stack_a) == 0)
		rotate_index_to_top(stack_a, stack_b, find_min_index(stack_a), 'a');
}
