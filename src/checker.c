/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:47:06 by ssucha            #+#    #+#             */
/*   Updated: 2026/02/18 15:17:03 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*read_store_instructions(void);
static int		perform_actions(t_list **instr, t_node **stack_a,
					t_node **stack_b);
static int		a_sorted_b_empty(t_node **stack_a, t_node **stack_b);
static void		free_everything(t_node **stack_a, t_node **stack_b,
					int **args, t_list **instr);

int	main(int argc, char **argv)
{
	int		*args;
	int		n_arg;
	t_list	*instr;
	t_node	*stack_a;
	t_node	*stack_b;

	n_arg = count_numbers(argc, argv);
	if (n_arg == 0)
		return (0);
	args = normalize_input(argc, argv, n_arg);
	if (find_duplicates(args, n_arg) == 1)
	{
		free(args);
		error();
	}
	instr = read_store_instructions();
	stack_a = create_stack_a(args, n_arg);
	stack_b = NULL;
	if (perform_actions(&instr, &stack_a, &stack_b) < 0)
	{
		free_everything(&stack_a, &stack_b, &args, &instr);
		error();
	}
	a_sorted_b_empty(&stack_a, &stack_b);
	free_everything(&stack_a, &stack_b, &args, &instr);
	return (0);
}

static int	perform_actions(t_list **instr, t_node **stack_a, t_node **stack_b)
{
	while (*instr)
	{
		if (!ft_strncmp((*instr)->content, "sa\n", 3)
			|| !ft_strncmp((*instr)->content, "sb\n", 3)
			|| !ft_strncmp((*instr)->content, "ss\n", 3))
			swap(stack_a, stack_b, (*instr)->content);
		else if (!ft_strncmp((*instr)->content, "pa\n", 3)
			|| !ft_strncmp((*instr)->content, "pb\n", 3))
			push(stack_a, stack_b, (*instr)->content);
		else if (!ft_strncmp((*instr)->content, "rra\n", 4)
			|| !ft_strncmp((*instr)->content, "rrb\n", 4)
			|| !ft_strncmp((*instr)->content, "rrr\n", 4))
			rev_rotate(stack_a, stack_b, (*instr)->content);
		else if (!ft_strncmp((*instr)->content, "ra\n", 3)
			|| !ft_strncmp((*instr)->content, "rb\n", 3)
			|| !ft_strncmp((*instr)->content, "rr\n", 3))
			rotate(stack_a, stack_b, (*instr)->content);
		else
			return (-1);
		*instr = (*instr)->next;
	}
	return (0);
}

static t_list	*read_store_instructions(void)
{
	t_list	*instr;
	t_list	*new;

	instr = NULL;
	while (1)
	{
		new = ft_lstnew(get_next_line(0));
		if (!(new->content))
			break ;
		ft_lstadd_back(&instr, new);
	}
	return (instr);
}

static void	free_everything(t_node **stack_a, t_node **stack_b,
	int **args, t_list **instr)
{
	if (args && *args)
		free(*args);
	if (instr && *instr)
		ft_lstclear(instr, free);
	if (stack_a && *stack_a)
		node_lst_clear(stack_a);
	if (stack_b && *stack_b)
		node_lst_clear(stack_b);
}

/**
 * @brief Recognizes if the stack_b is empty and stack_a is sorted
 * with the min on top. Prints OK/KO accordingly.
 * @return 0 if OK, -1 if not.
 */
static int	a_sorted_b_empty(t_node **stack_a, t_node **stack_b)
{
	if (*stack_b)
	{
		ft_printf("KO\n");
		return (-1);
	}
	if ((!stack_a || !*stack_a))
	{
		ft_printf("OK\n");
		return (0);
	}
	if (is_circular(stack_a) == 0)
	{
		ft_printf("OK\n");
		return (0);
	}
	ft_printf("KO\n");
	return (-1);
}
