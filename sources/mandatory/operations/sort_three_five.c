/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:52:42 by roglopes          #+#    #+#             */
/*   Updated: 2024/03/10 19:29:17 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/push_swap.h"

void	ft_sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = ft_find_max(*a);
	if (*a == biggest_node)
		ft_ra(a, false);
	else if ((*a)->next == biggest_node)
		ft_rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		ft_sa(a, false);
}

void	ft_sort_five(t_stack_node **a, t_stack_node **b)
{
	while (ft_stack_len(*a) > 3)
	{
		ft_init_nodes(*a, *b);
		ft_prep_for_push(a, ft_find_min(*a), 'a');
		ft_pb(b, a, false);
	}
}
