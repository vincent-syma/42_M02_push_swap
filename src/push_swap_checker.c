/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:47:06 by ssucha            #+#    #+#             */
/*   Updated: 2026/02/16 23:11:55 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swaps the first 2 elements at the top of stack given as argument.
 * Does nothing if there is only one element or none.
 */
static void	swap_a_b(t_node **stack)
{
	t_node	*tmp_1;
	t_node	*tmp_2;
	int		tmp_idx;
	int		tmp_number;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp_1 = *stack;
	tmp_2 = tmp_1->next;
	tmp_idx = tmp_1->index;
	tmp_number = tmp_1->number;
	tmp_1->index = tmp_2->index;
	tmp_1->number = tmp_2->number;
}

/**
 * @brief Swaps the first 2 elements at the top of stack/s
 * according to the instruction given as argument.
 * Does nothing if there is only one element or none.
 * 
 * Instructions (char *):
 * @param sa Swaps first 2 elements in stack 'a'.
 * @param sb Swaps first 2 elements in stack 'b'.
 * @param ss Swaps first 2 elements in both stack 'a' and stack 'b'.
 */
void	swap(t_node **stack_a, t_node **stack_b, char *instr)
{
	if (!ft_strncmp("sa", instr, 2))
		swap_a_b(stack_a);
	else if (!ft_strncmp("sb", instr, 2))
		swap_a_b(stack_b);
	else if (!ft_strncmp("ss", instr, 2))
	{
		swap_a_b(stack_a);
		swap_a_b(stack_b);
	}
}

/**
 * @brief
 */
static void	push_a_b(t_node **src, t_node **dest)
{
	t_node	*tmp;
	t_node	*tail;

	tmp = *src;
	if (tmp->next == tmp)
		*src = NULL;
	else
	{
		tail = ft_node_lst_last(*src);
		*src = tmp->next;
		tail->next = *src;
	}
	if (!dest || !*dest)
	{
		tmp->next = tmp;
		*dest = tmp;
	}
	else
	{
		tail = ft_node_lst_last(*dest);
		tmp->next = *dest;
		tail->next = tmp;
		*dest = tmp;
	}
}

/**
 * @brief Instructions (char *):
 * @param pa Takes the first element at the top of `b`
 * and puts it at the top of `a`. Does nothing if `b` is empty.
 * @param pb Takes the first element at the top of `a`
 * and puts it at the top of `b`. Does nothing if `a` is empty.
 */
void	push(t_node **stack_a, t_node **stack_b, char *instr)
{
	if (!ft_strncmp("pb", instr, 2))
	{
		if (!stack_a || !*stack_a)
			return ;
		push_a_b(stack_a, stack_b);
	}
	else if (!ft_strncmp("pa", instr, 2))
	{
		if (!stack_b || !*stack_b)
			return ;
		push_a_b(stack_b, stack_a);
	}
	else
		return ;
}
