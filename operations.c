/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:54:29 by yperra-f          #+#    #+#             */
/*   Updated: 2019/10/01 16:03:43 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap_list(t_push_swap **stack)
{
	t_push_swap *second_elem;
	t_push_swap *third_elem;

	if (*stack && (*stack)->next)
	{
		second_elem = (*stack)->next;
		third_elem = (*stack)->next->next;
		(*stack)->next = third_elem;
		if (third_elem)
			third_elem->prev = *stack;
		second_elem->next = *stack;
		second_elem->prev = NULL;
		(*stack)->prev = second_elem;
		*stack = second_elem;
	}
}

void		swap_ss(t_push_swap **stack_a, t_push_swap **stack_b)
{
	swap_list(stack_a);
	swap_list(stack_b);
}

void		rreverse_list(t_push_swap **stack)
{
	t_push_swap	*first_elem;
	t_push_swap *before_last_elem;

	if (*stack && (*stack)->next && (*stack)->next->next)
	{
		first_elem = *stack;
		while ((*stack)->next)
			*stack = (*stack)->next;
		before_last_elem = (*stack)->prev;
		first_elem->prev = *stack;
		(*stack)->next = first_elem;
		(*stack)->prev = NULL;
		before_last_elem->next = NULL;
	}
	else if (*stack && (*stack)->next)
	{
		first_elem = *stack;
		while ((*stack)->next)
			*stack = (*stack)->next;
		(*stack)->next = first_elem;
		(*stack)->prev = NULL;
		first_elem->prev = *stack;
		first_elem->next = NULL;
	}
}

void		rreverse_r(t_push_swap **stack_a, t_push_swap **stack_b)
{
	rreverse_list(stack_a);
	rreverse_list(stack_b);
}

void		reverse_list(t_push_swap **stack)
{
	t_push_swap *first_elem;
	t_push_swap *second_elem;

	if (*stack && (*stack)->next)
	{
		first_elem = *stack;
		second_elem = (*stack)->next;
		while ((*stack)->next)
			*stack = (*stack)->next;
		(*stack)->next = first_elem;
		first_elem->prev = *stack;
		*stack = second_elem;
		second_elem->prev = NULL;
		first_elem->next = NULL;
	}
}

void		reverse_r(t_push_swap **stack_a, t_push_swap **stack_b)
{
	reverse_list(stack_a);
	reverse_list(stack_b);
}

void		push_a(t_push_swap **stack_a, t_push_swap **stack_b)
{
	t_push_swap *first_b;
	t_push_swap *second_b;

	if ((*stack_b)->next)
	{
		first_b = *stack_b;
		second_b = (*stack_b)->next;
		second_b->prev = NULL;
		first_b->next = *stack_a;
		if (*stack_a)
			(*stack_a)->prev = first_b;
		first_b->prev = NULL;
		*stack_a = first_b;
		*stack_b = second_b;	
	}
	else if (*stack_b)
	{
		(*stack_b)->next = *stack_a;
		if (*stack_a)
			(*stack_a)->prev = *stack_b;
		(*stack_b)->prev = NULL;
		*stack_a = *stack_b;
		*stack_b = NULL;
	}
}

void		push_b(t_push_swap **stack_a, t_push_swap **stack_b)
{
	t_push_swap *first_a;
	t_push_swap *second_a;

	if ((*stack_a)->next)
	{
		first_a = *stack_a;
		second_a = (*stack_a)->next;
		second_a->prev = NULL;
		first_a->next = *stack_b;
		if (*stack_b)
			(*stack_b)->prev = first_a;
		first_a->prev = NULL;
		*stack_b = first_a;
		*stack_a = second_a;
	}
	else if (*stack_a)
	{
		(*stack_a)->next = *stack_b;
		if (*stack_b)
			(*stack_b)->prev = *stack_a;
		(*stack_a)->prev = NULL;
		*stack_b = *stack_a;
		*stack_a = NULL;
	}
}