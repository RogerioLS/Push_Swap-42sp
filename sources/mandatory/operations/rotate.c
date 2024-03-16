/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:48:17 by roglopes          #+#    #+#             */
/*   Updated: 2024/03/10 14:54:52 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/push_swap.h"

void	ft_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				len;

	len = ft_stack_len(*stack);
	if (NULL == stack || NULL == *stack || 1 == len)
		return ;
	last_node = ft_find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ft_ra(t_stack_node **a, bool print)
{
	ft_rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	ft_rb(t_stack_node **b, bool print)
{
	ft_rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	ft_rr(t_stack_node **a, t_stack_node **b, bool print)
{
	ft_rotate(a);
	ft_rotate(b);
	if (!print)
		ft_printf("rr\n");
}
