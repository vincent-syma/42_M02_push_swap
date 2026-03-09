/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_nodes_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:47:06 by ssucha            #+#    #+#             */
/*   Updated: 2026/02/17 13:45:20 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief External functs: malloc >> FREE after use!
 * 
 * Allocates (with malloc(3)) and returns a new node with variables
 * 'number' and 'index' set according to the arguments.
 * The variable ’next’ is initialized to 'NULL'.
 * @return The new node.
 */
t_node	*new_node(int number, int index)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->number = number;
	new->index = index;
	new->next = NULL;
	return (new);
}

/**
 * @brief Deletes and frees the given node and every successor of that node,
 * using the function free(3). The pointer to the list is set to NULL.
 * @param node_lst The address of a pointer to a node.
 * @return None.
 */
void	node_lst_clear(t_node **node_lst)
{
	t_node	*head;
	t_node	*tmp;
	t_node	*next;

	if (!node_lst || !*node_lst)
		return ;
	head = *node_lst;
	tmp = head->next;
	while (tmp != head)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(head);
	*node_lst = NULL;
}
