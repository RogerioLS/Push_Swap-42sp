/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:47:14 by roglopes          #+#    #+#             */
/*   Updated: 2024/03/10 16:07:52 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/push_swap.h"

void	ft_rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	int				len;

	len = ft_stack_len(*stack);
	if (NULL == *stack || NULL == stack || 1 == len)
		return ;
	last = ft_find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	ft_rra(t_stack_node **a, bool print)
{
	ft_rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	ft_rrb(t_stack_node **b, bool print)
{
	ft_rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	ft_rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	ft_rev_rotate(b);
	ft_rev_rotate(a);
	if (!print)
		ft_printf("rrr\n");
}
