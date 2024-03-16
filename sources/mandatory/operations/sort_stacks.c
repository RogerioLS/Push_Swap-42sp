/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:49:08 by roglopes          #+#    #+#             */
/*   Updated: 2024/03/10 19:29:14 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/push_swap.h"

void	ft_rotate_both(t_stack_node **a, t_stack_node **b, \
							t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node \
		&& *b != cheapest_node)
		ft_rr(a, b, false);
	ft_current_index(*a);
	ft_current_index(*b);
}

void	ft_rev_rotate_both(t_stack_node **a, t_stack_node **b, \
								t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node \
			&& *b != cheapest_node)
		ft_rrr(a, b, false);
	ft_current_index(*a);
	ft_current_index(*b);
}

void	ft_move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = ft_get_cheapest(*b);
	if (cheapest_node->above_median \
		&& cheapest_node->target_node->above_median)
		ft_rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		ft_rev_rotate_both(a, b, cheapest_node);
	ft_prep_for_push(b, cheapest_node, 'b');
	ft_prep_for_push(a, cheapest_node->target_node, 'a');
	ft_pa(a, b, false);
}

void	ft_min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != ft_find_min(*a)->nbr)
	{
		if (ft_find_min(*a)->above_median)
			ft_ra(a, false);
		else
			ft_rra(a, false);
	}
}

void	ft_sort_stacks(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				len_a;

	len_a = ft_stack_len(*a);
	if (len_a == 5)
		ft_sort_five(a, b);
	else
	{
		while (len_a-- > 3)
			ft_pb(b, a, false);
	}
	ft_sort_three(a);
	while (*b)
	{
		ft_init_nodes(*a, *b);
		ft_move_a_to_b(a, b);
	}
	ft_current_index(*a);
	smallest = ft_find_min(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ft_ra(a, false);
	else
		while (*a != smallest)
			ft_rra(a, false);
}
