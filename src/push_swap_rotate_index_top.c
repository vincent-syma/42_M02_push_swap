/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate_index_top.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:47:06 by ssucha            #+#    #+#             */
/*   Updated: 2026/02/16 22:45:58 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Pushes the selected node to the top of stack b
 * and then to the top of stack_a.
 * If its the max from stack b, it ends here.
 * If it is the second max, it is swapped on the top of stack a.
 */
void	rotate_index_to_top(t_node **stack_a, t_node **stack_b,
	int idx, char stack)
{
	int	cost;

	if (stack == 'a')
	{
		cost = cost_to_top(stack_a, idx);
		if (cost > 0)
			rotate_up(stack_a, stack_b, idx, "ra");
		else if (cost < 0)
			rotate_down(stack_a, stack_b, idx, "rra");
	}
	else if (stack == 'b')
	{
		cost = cost_to_top(stack_b, idx);
		if (cost > 0)
			rotate_up(stack_a, stack_b, idx, "rb");
		else if (cost < 0)
			rotate_down(stack_a, stack_b, idx, "rrb");
	}
}

/**
 * @brief Pushes the node with index given as argument to the top of the stack
 * by rotating it up.
 * @param instr "ra" for rotating stack_a and "rb" for rotating stack_b
 */
void	rotate_up(t_node **stack_a, t_node **stack_b, int idx, char *instr)
{
	int	stack_size;

	stack_size = 0;
	if (!ft_strncmp("ra", instr, 2))
	{
		stack_size = ft_node_lst_size(*stack_a);
		while ((*stack_a)->index != idx && stack_size--)
			rotate(stack_a, stack_b, instr);
	}
	else if (!ft_strncmp("rb", instr, 2))
	{
		stack_size = ft_node_lst_size(*stack_b);
		while ((*stack_b)->index != idx && stack_size--)
			rotate(stack_a, stack_b, instr);
	}
}

/**
 * @brief Pushes the node with index given as argument to the top of the stack
 * by rotating it down.
 * @param instr "rra" for rotating stack_a and "rrb" for rotating stack_b
 */
void	rotate_down(t_node **stack_a, t_node **stack_b, int idx, char *instr)
{
	int	count;
	int	stack_size;

	count = 0;
	stack_size = 0;
	if (!ft_strncmp("rra", instr, 3))
	{
		stack_size = ft_node_lst_size(*stack_a);
		while ((*stack_a)->index != idx && stack_size--)
			rev_rotate(stack_a, stack_b, instr);
	}
	else if (!ft_strncmp("rrb", instr, 3))
	{
		stack_size = ft_node_lst_size(*stack_b);
		while ((*stack_b)->index != idx && stack_size--)
			rev_rotate(stack_a, stack_b, instr);
	}
}
