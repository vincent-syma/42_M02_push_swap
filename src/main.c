/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:47:06 by ssucha            #+#    #+#             */
/*   Updated: 2026/03/09 18:44:12 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		n_arg;
	int		*args;
	t_node	*stack_a;
	t_node	*stack_b;

	n_arg = count_numbers(argc, argv);
	if (n_arg == 0)
		return (0);
	args = normalize_input(argc, argv, n_arg);
	if (n_arg == 1)
	{
		free(args);
		return (0);
	}
	if (find_duplicates(args, n_arg) == 1)
	{
		free(args);
		error();
	}
	stack_a = create_stack_a(args, n_arg);
	stack_b = NULL;
	sort(n_arg, &stack_a, &stack_b);
	free(args);
	node_lst_clear(&stack_a);
	node_lst_clear(&stack_b);
	return (0);
}
