/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:45:03 by roglopes          #+#    #+#             */
/*   Updated: 2024/03/10 13:46:00 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/push_swap.h"

void	ft_push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (*src == NULL)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	ft_pa(t_stack_node **a, t_stack_node **b, bool print)
{
	ft_push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	ft_pb(t_stack_node **b, t_stack_node **a, bool print)
{
	ft_push(b, a);
	if (!print)
		ft_printf("pb\n");
}
