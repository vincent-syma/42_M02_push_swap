/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate_reverse_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:47:06 by ssucha            #+#    #+#             */
/*   Updated: 2026/02/16 23:32:56 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Shifts up all elements of stack given as argument by 1.
 * (The first element becomes the last one.)
 */
static void	rotate_a_b(t_node **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
}

/**
 * @brief Shifts up all elements of stack according to the instruction by 1.
 * (The first element becomes the last one.)
 *
 * Instructions (char *):
 * @param ra Shifts up all elements of stack `a` by 1.
 * @param rb Shifts up all elements of stack `b` by 1.
 * @param rr Shifts up all elements of both stack 'a' and stack 'b' by 1.
 */
void	rotate(t_node **stack_a, t_node **stack_b, char *instr)
{
	if (!ft_strncmp("ra", instr, 2))
		rotate_a_b(stack_a);
	else if (!ft_strncmp("rb", instr, 2))
		rotate_a_b(stack_b);
	else if (!ft_strncmp("rr", instr, 2))
	{
		rotate_a_b(stack_a);
		rotate_a_b(stack_b);
	}
}

/**
 * @brief Shifts down all elements of stack given as argument by 1.
 * (The last element becomes the first one.)
 */
static void	rev_rotate_a_b(t_node **stack)
{
	t_node	*head;
	t_node	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	tmp = *stack;
	while (tmp->next->next != head)
		tmp = tmp->next;
	*stack = tmp->next;
}

/**
 * @brief Shifts down all elements of stack according to the instruction by 1.
 * (The last element becomes the first one.)
 *
 * Instructions (char *):
 * @param ra Shifts down all elements of stack `a` by 1.
 * @param rb Shifts down all elements of stack `b` by 1.
 * @param rr Shifts down all elements of both stack 'a' and stack 'b' by 1.
 */
void	rev_rotate(t_node **stack_a, t_node **stack_b, char *instr)
{
	if (!ft_strncmp("rra", instr, 3))
		rev_rotate_a_b(stack_a);
	else if (!ft_strncmp("rrb", instr, 3))
		rev_rotate_a_b(stack_b);
	else if (!ft_strncmp("rrr", instr, 3))
	{
		rev_rotate_a_b(stack_a);
		rev_rotate_a_b(stack_b);
	}
}
