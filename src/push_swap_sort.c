/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:47:06 by ssucha            #+#    #+#             */
/*   Updated: 2026/02/16 22:57:02 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts linked list of 3 nodes.
 */
static void	sort_3(t_node **stack_a, t_node **stack_b)
{
	int	x;
	int	y;
	int	z;

	if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	x = (*stack_a)->index;
	y = (*stack_a)->next->index;
	z = (*stack_a)->next->next->index;
	if (x > y && y < z && x < z)
		return (swap(stack_a, stack_b, "sa"));
	else if (x > y && y > z)
		return (swap(stack_a, stack_b, "sa"),
			rev_rotate(stack_a, stack_b, "rra"));
	else if (x > y && y < z && x > z)
		return (rotate(stack_a, stack_b, "ra"));
	else if (x < y && y > z && x < z)
		return (swap(stack_a, stack_b, "sa"), rotate(stack_a, stack_b, "ra"));
	else if (x < y && y > z && x > z)
		return (rev_rotate(stack_a, stack_b, "rra"));
}

/**
 * @brief Sorts linked list of 4 nodes.
 */
static void	sort_4(t_node **stack_a, t_node **stack_b)
{
	rotate_up(stack_a, stack_b, find_min_index(stack_a), "ra");
	push(stack_a, stack_b, "pb");
	sort_3(stack_a, stack_b);
	push(stack_a, stack_b, "pa");
}

/**
 * @brief Sorts linked list of 5 nodes.
 */
static void	sort_5(t_node **stack_a, t_node **stack_b)
{
	int		target;
	int		stack_size;

	stack_size = ft_node_lst_size(*stack_a);
	target = min_or_second_min(stack_size, stack_a);
	rotate_index_to_top(stack_a, stack_b, target, 'a');
	push(stack_a, stack_b, "pb");
	target = find_min_index(stack_a);
	rotate_index_to_top(stack_a, stack_b, target, 'a');
	push(stack_a, stack_b, "pb");
	sort_3(stack_a, stack_b);
	push(stack_a, stack_b, "pa");
	push(stack_a, stack_b, "pa");
}

/**
 * @brief Chooses sorting strategy and performs it.
 */
void	sort(int n, t_node **stack_a, t_node **stack_b)
{
	if (is_circular(stack_a) == 0)
		rotate_index_to_top(stack_a, stack_b, find_min_index(stack_a), 'a');
	else if (n <= 5)
	{
		if (n == 3)
			return (sort_3(stack_a, stack_b));
		else if (n == 4)
			return (sort_4(stack_a, stack_b));
		else if (n == 5)
			return (sort_5(stack_a, stack_b));
	}
	else
	{
		from_a_to_b(n, stack_a, stack_b);
		from_b_to_a(n, stack_a, stack_b);
	}
}
