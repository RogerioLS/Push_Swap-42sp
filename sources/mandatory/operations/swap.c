/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:53:41 by roglopes          #+#    #+#             */
/*   Updated: 2024/03/10 14:55:10 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/push_swap.h"

void	ft_swap(t_stack_node **head)
{
	int	len;

	len = ft_stack_len(*head);
	if (NULL == *head || NULL == head || 1 == len)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	ft_sa(t_stack_node	**a, bool print)
{
	ft_swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	ft_sb(t_stack_node **b, bool print)
{
	ft_swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ft_ss(t_stack_node **a, t_stack_node **b, bool print)
{
	ft_swap(a);
	ft_swap(b);
	if (!print)
		ft_printf("ss\n");
}
