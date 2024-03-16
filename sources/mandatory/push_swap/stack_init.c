/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:13:34 by roglopes          #+#    #+#             */
/*   Updated: 2024/03/15 18:49:20 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/push_swap.h"

long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

void	ft_append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (NULL == stack)
		return ;
	node = calloc(1, sizeof(t_stack_node));
	if (NULL == node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (NULL == *stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	ft_init_stack_a(t_stack_node **a, char **argv, bool argc_2)
{
	long	n;
	int		i;

	i = 0;
	n = 0;
	while (argv[i] != NULL)
	{
		if (ft_error_syntax(argv[i]))
			ft_free_errors(a, argv, argc_2);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_free_errors(a, argv, argc_2);
		if (ft_error_duplicate(*a, (int)n))
			ft_free_errors(a, argv, argc_2);
		ft_append_node(a, (int)n);
		i++;
	}
	if (argc_2)
		ft_free_argc(argv);
}

t_stack_node	*ft_get_cheapest(t_stack_node *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	ft_prep_for_push(t_stack_node **stack, t_stack_node *top_node, \
						char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ft_ra(stack, false);
			else
				ft_rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				ft_rb(stack, false);
			else
				ft_rrb(stack, false);
		}
	}
}
