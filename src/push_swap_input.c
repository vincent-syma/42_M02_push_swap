/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:47:06 by ssucha            #+#    #+#             */
/*   Updated: 2026/03/09 18:45:21 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 
 * @return 
 */
static int	count_numbers_in_str(char *str)
{
	int		count;
	size_t	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ' && i != 0)
			i++;
		else if (str[i] != ' ' && i != 0)
			error();
		if (!ft_strchr("+-0123456789 ", str[i]))
			error();
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (ft_isdigit(str[i]))
		{
			count++;
			while (ft_isdigit(str[i]))
				i++;
		}
		else
			error();
	}
	return (count);
}

/**
 * @brief Counts distinct numbers in all the argv inputs.
 * @return Number of numbers or exits on invalid input through error().
 */
int	count_numbers(int argc, char **argv)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		count += count_numbers_in_str(argv[i]);
		i++;
	}
	return (count);
}

/**
 * @brief Length of string until space char (or whole string).
 */
size_t	ft_strlen_until_space(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != ' ')
		i++;
	return (i);
}

/**
 * @brief 
 * @return 
 */
static int	parse_arg(int **args, int argc, char **argv)
{
	long	val;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	val = 0;
	while (++i < argc)
	{
		str = argv[i];
		while (*str)
		{
			val = ft_atol(str);
			if (ft_strlen_until_space(str) > 11 || val > INT_MAX || val < INT_MIN)
				return (-1);
			(*args)[j] = (int)val;
			j++;
			while (*str && ft_strchr("+-0123456789", *str))
				str++;
			if (*str == ' ')
				str++;
		}
	}
	return (0);
}

/**
* @brief Reads the argv and checks for invalid input.
* If valid, stores it into an integer array args given as an argument.
* @return Exits on error, 0 if OK.
*/
int	*normalize_input(int argc, char **argv, int n_arg)
{
	int		*args;

	if (argc < 2)
		exit(0);
	args = malloc(sizeof(int) * n_arg);
	if (!args)
		error();
	if (parse_arg(&args, argc, argv) < 0)
	{
		free(args);
		error();
	}
	return (args);
}

/**
* @brief Creates linked list and fills it with numbers
and their normalized indexes.
* @return Head of created linked list.
*/
t_node	*create_stack_a(int *args, int argc)
{
	int		i;
	int		j;
	int		idx;
	t_node	*node;
	t_node	*stack_a;

	i = 0;
	stack_a = NULL;
	while (i < argc)
	{
		idx = 0;
		j = 0;
		while (j < argc)
			idx += (args[j++] < args[i]);
		node = new_node(args[i], idx);
		node_lst_add_back(&stack_a, node);
		i++;
	}
	if (node)
		node->next = stack_a;
	return (stack_a);
}
