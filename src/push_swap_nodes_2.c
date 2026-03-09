/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_nodes_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:47:06 by ssucha            #+#    #+#             */
/*   Updated: 2026/02/17 13:46:51 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Adds the node ’new’ at the beginning of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 * @return None.
 */
void	node_lst_add_front(t_node **node_lst, t_node *new)
{
	new->next = *node_lst;
	*node_lst = new;
}

/**
 * @brief Adds the node ’new’ at the end of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 * @return None.
 */
void	node_lst_add_back(t_node **node_lst, t_node *new)
{
	t_node	*last;

	if (!new)
		return ;
	if (*node_lst == NULL)
	{
		*node_lst = new;
		return ;
	}
	last = *node_lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

/**
 * @return The size of the list.
 */
int	ft_node_lst_size(t_node *node_lst)
{
	int		count;
	t_node	*head;

	if (!node_lst)
		return (0);
	count = 1;
	head = node_lst;
	node_lst = node_lst->next;
	while (node_lst != head)
	{
		node_lst = node_lst->next;
		count++;
	}
	return (count);
}

/**
 * @param lst The head of the circular list.
 * @return "Last" node of the circular list.
 */
t_node	*ft_node_lst_last(t_node *head)
{
	t_node	*tmp;

	if (!head)
		return (NULL);
	tmp = head;
	while (tmp->next != head)
		tmp = tmp->next;
	return (tmp);
}
