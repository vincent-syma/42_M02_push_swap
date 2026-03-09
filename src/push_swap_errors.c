/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:47:06 by ssucha            #+#    #+#             */
/*   Updated: 2026/02/16 23:39:51 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Prints an "Error" message on stderr.
 * @return Exits the whole program with 1.
 */
void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

/**
 * @brief Looks for duplicates in an integer array.
 * @return 0 if there are no duplicates, 1 if there is at least one.
 */
int	find_duplicates(int	*args, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i + 1 < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (args[i] == args[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @brief Recognizes if the stack is already sorted,
 * but not neccessarily rotated with min on top
 * @return 0 if is circular, -1 if not.
 */
int	is_circular(t_node **stack)
{
	t_node	*tmp;
	int		breaks;

	if (!stack || !*stack)
		return (0);
	breaks = 0;
	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			breaks++;
		tmp = tmp->next;
		if (tmp == *stack)
			break ;
	}
	if (tmp->index > (*stack)->index)
		breaks++;
	if (breaks > 1)
		return (-1);
	return (0);
}
