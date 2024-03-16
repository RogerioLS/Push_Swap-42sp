/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:05:36 by roglopes          #+#    #+#             */
/*   Updated: 2024/03/10 19:15:26 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/push_swap.h"

void	ft_current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (NULL == stack)
		return ;
	median = ft_stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	ft_set_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->target_node = ft_find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	ft_cost_analysis(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_len(a);
	len_b = ft_stack_len(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!(b->above_median))
		{
			b->push_cost = len_b - (b->index);
		}
		if (b->target_node->above_median)
			b->push_cost += b->target_node->index;
		else
			b->push_cost += len_a - (b->target_node->index);
		b = b->next;
	}
}

void	ft_set_cheapest(t_stack_node *b)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if (NULL == b)
		return ;
	cheapest_value = LONG_MAX;
	while (b)
	{
		if (b->push_cost < cheapest_value)
		{
			cheapest_value = b->push_cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->cheapest = true;
}

void	ft_init_nodes(t_stack_node *a, t_stack_node *b)
{
	ft_current_index(a);
	ft_current_index(b);
	ft_set_target(a, b);
	ft_cost_analysis(a, b);
	ft_set_cheapest(b);
}
