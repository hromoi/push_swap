/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:39:52 by yperra-f          #+#    #+#             */
/*   Updated: 2019/10/01 18:38:05 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_push_swap *ft_free_list(t_push_swap *push_swap)
{
	while (push_swap)
	{
		push_swap = push_swap->prev;
		free(push_swap->next);
	}
	push_swap->next = NULL;
	push_swap->prev = NULL;
	return (NULL);
}

t_push_swap *ft_add_list(int *av, int len, t_push_swap *push_swap)
{
	t_push_swap *prev;

	prev = push_swap;
	if (!(push_swap->next = (t_push_swap *)malloc(sizeof(t_push_swap))))
		return (ft_free_list(push_swap));
	push_swap = push_swap->next;
	if (av)
		push_swap->number = *av;
	push_swap->prev = prev;
	push_swap->next = NULL;
	return (push_swap);
}

t_push_swap *ft_init_list(int 	*av, int len, t_push_swap *push_swap)
{
	t_push_swap *head;

	head = NULL;
	if (!push_swap)
	{
		if (!(push_swap = (t_push_swap *)malloc(sizeof(t_push_swap))))
			return (NULL);
		head = push_swap;
		push_swap->next = NULL;
		push_swap->prev = NULL;
		push_swap->number = *av;
		av++;
		len--;
	}
	while (len)
	{
		if (!(push_swap = ft_add_list(av, len, push_swap)))
			return (NULL);
		av++;
		len--;
	}
	return (head);
}

void	ft_print_list(t_push_swap *push_swap)
{
	while (push_swap)
	{
		printf("%d\n", push_swap->number);
		push_swap = push_swap->next;
	}
}

int		ft_check_array_duplicat(t_push_swap_work *push_swap_work, int len_array)
{
	int i;
	int j;
	int len;
	int check_break;

	i = 0;
	check_break = len_array - 1;

	while (len_array)
	{
		j = i + 1;
		len = len_array - 1;
		while (len--)
		{
			if (push_swap_work->array_int[i] == push_swap_work->array_int[j])
			{
				free(push_swap_work->array_int);
				printf("Error\n");
				return (0);
			}
			j++;
		}
		i++;
		len_array--;
		if (i == check_break)
			break ;
	}
	return (1);
}

int		ft_count_word(int ac, char **av)
{
	int i;
	int j;
	int count;
	long long tmp;

	count = 0;
	i = 0;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if ((av[i][j] == 43 && av[i][j + 1] >= 48 && av[i][j + 1] <= 57) || (av[i][j]  == 45 && av[i][j + 1] >= 48 && av[i][j + 1] <= 57) || (av[i][j] >= 48 && av[i][j] <= 57))
			{
				count++;
				j++;
			}
			while (av[i][j] >= 48 && av[i][j] <= 57)
				j++;
			if (av[i][j] && av[i][j] != 32 && av[i][j] != 9)
			{
				printf("Error\n");
				return (-1);
			}
			while (av[i][j] == 32 || av[i][j] == 9)
				j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

int		ft_valid(int ac, char **av)
{
	int count_word;

	if ((count_word = ft_count_word(ac, av)) <= 0)
		return (0);
	return (count_word);
}

int		ft_strlen_array(char **tmp)
{
	int count;

	count = 0;
	while (*tmp++)
		count++;
	return (count);
}

void ft_print_array(int *av, int len)
{
	int i = 0;
	while (len--)
	{
		printf("array[%d] - %d\n", i, av[i]);
		i++;
	}
}

int			*ft_init_array(int ac, char **av, int count_word)
{
	int     i;
	int		j;
	int	    *result;
	char    **tmp;

	i = 0;
	if (!(result = (int *)malloc(sizeof(int) * count_word)))
		return (NULL);
	while (ac-- > 0)
	{
		j = 0;
		if (!(tmp = ft_strsplit(*av)))
			return (NULL);
		while (tmp[j])
			result[i++] = atoi(tmp[j++]);
		if (tmp[j])
			ft_free(tmp, ft_strlen_array(tmp));
		av++;
	}
	return (result);
}

int		ft_free_array_int(int *av)
{
	free(av);
	av = NULL;
	return (0);
}

int			ft_search_median(int *array, int len)
{
	int median;

	quick_sort(array, 0, len - 1, len);
	median = len / 2;
	return (median);
}

int			get_max(t_push_swap *stack_a)
{
	int max;

	max = stack_a->number;
	while (stack_a->next)
	{
		if (stack_a->next->number > max)
			max = stack_a->next->number;
		stack_a = stack_a->next;
	}
	return (max);
}

int			get_min(t_push_swap *stack_a)
{
	int min;

	min = stack_a->number;
	while (stack_a->next)
	{
		if (stack_a->next->number < min)
			min = stack_a->next->number;
		stack_a = stack_a->next;
	}
	return (min);
}

void		sort(t_push_swap **stack_a)
{
	int 		min;
	int 		max;

	max = get_max(*stack_a);
	min = get_min(*stack_a);
	if ((*stack_a)->next)
	{
		while ((*stack_a)->next->next)
		{
			if ((*stack_a)->number == max)
				reverse_list(stack_a);
			else if ((*stack_a)->number == min && (*stack_a)->next->number == max)
			{
				swap_list(stack_a);
				reverse_list(stack_a);
			}
			else if ((*stack_a)->number != min && (*stack_a)->number != max)
				swap_list(stack_a);
			else
				break ;
		}
	}
	if (*stack_a && (*stack_a)->next && (*stack_a)->number == max && (*stack_a)->next->number == min)
		swap_list(stack_a);
}

void		current_stack_element_b(t_push_swap_work *push_swap_work, int current)
{
	push_swap_work->current_stack_element_b = current;
}

int			ft_len_list(t_push_swap *stack)
{
	int count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void		count_rb(t_push_swap **stack_b, t_push_swap_work *push_swap_work)
{
	int count;
	t_push_swap *iter;

	iter = *stack_b;
	count = 0;
	while (iter)
	{
		// printf("hello\n");
		// printf("number_stack_b - %d\n", iter->number);
		// printf("current_element_b - %d\n", push_swap_work->current_stack_element_b);
		// printf("next->number - %d\n", iter->next->number);
		if (iter->number == push_swap_work->current_stack_element_b)
		{
			push_swap_work->rb = count;
			push_swap_work->current_elem = iter->number;
			break ;
		}
		count++;
		iter = iter->next;
	}
}

void		count_rrb(t_push_swap **stack_b, t_push_swap_work *push_swap_work)
{
	int 		count;
	t_push_swap *iter;

	iter = *stack_b;
	count = ft_len_list(*stack_b);
	while (iter)
	{
		if (iter->number == push_swap_work->current_stack_element_b)
		{
			push_swap_work->rrb = count;
			push_swap_work->current_elem = iter->number;
			break ;
		}
		count--;
		iter = iter->next;
	}
}

void		rotate_b_count(t_push_swap_work *push_swap_work, t_push_swap **stack_b)
{
	count_rb(stack_b, push_swap_work);
	count_rrb(stack_b, push_swap_work);
}

void		count_ra(t_push_swap **stack_a, t_push_swap_work *push_swap_work)
{
	int 		count;
	t_push_swap *iter;

	iter = *stack_a;
	count = 1;
	while (iter->next)
	{
		// printf("hello\n");
		// printf("number_stack_a - %d\n", iter->number);
		// printf("current_element_b - %d\n", push_swap_work->current_stack_element_b);
		// printf("next->number - %d\n", iter->next->number);
		if (push_swap_work->current_stack_element_b > iter->number && push_swap_work->current_stack_element_b < iter->next->number)
		{
			push_swap_work->ra = count;
			push_swap_work->current_elem = iter->number;
			break ;
		}
		count++;
		iter = iter->next;
	}
	if (push_swap_work->ra < 0)
		push_swap_work->ra = 0;
}

void		count_rra(t_push_swap **stack_a, t_push_swap_work *push_swap_work)
{
	int count;
	t_push_swap *iter;

	iter = *stack_a;
	count = 1;
	while (iter->next)
		iter = iter->next;
	while (iter->prev)
	{
		if (push_swap_work->current_stack_element_b < iter->number && push_swap_work->current_stack_element_b > iter->prev->number)
		{
			push_swap_work->rra = count;
			push_swap_work->current_elem = iter->number;
			break ;
		}
		count++;
		iter = iter->prev;
	}
	if (push_swap_work->rra < 0)
		push_swap_work->rra = ft_len_list(*stack_a);
}

void		rotate_a_count(t_push_swap_work *push_swap_work, t_push_swap **stack_a)
{
	count_ra(stack_a, push_swap_work);
	count_rra(stack_a, push_swap_work);
}

void		summ_doubler(t_push_swap_work *push_swap_work)
{
	int ra;
	int rb;

	ra = push_swap_work->ra;
	rb = push_swap_work->rb;
	if (push_swap_work->ra && push_swap_work->rb)
	{
		push_swap_work->summ_doubler_ra_rb = push_swap_work->ra < push_swap_work->rb ? push_swap_work->ra : push_swap_work->rb;
		if (push_swap_work->rb > push_swap_work->ra)
		{
			rb -= push_swap_work->ra;
			push_swap_work->doubler_rb_summ = rb;
		}
		else
		{
			ra -= push_swap_work->rb;
			push_swap_work->doubler_ra_summ = ra;
		}
		push_swap_work->summ_doubler_ra_rb += push_swap_work->rb > push_swap_work->ra ? rb : ra;
	}
}

void		summ_doublerr(t_push_swap_work *push_swap_work)
{
	int rra;
	int rrb;

	rra = push_swap_work->rra;
	rrb = push_swap_work->rrb;
	if (push_swap_work->rra && push_swap_work->rrb)
	{
		push_swap_work->summ_doublerr_rra_rrb = push_swap_work->rra < push_swap_work->rrb ? push_swap_work->rra : push_swap_work->rrb;
		if (push_swap_work->rra > push_swap_work->rrb)
		{
			rra -= push_swap_work->rrb;
			push_swap_work->doublerr_rra_summ = rra;
		}
		else
		{
			rrb -= push_swap_work->rra;
			push_swap_work->doublerr_rrb_summ = rrb;
		}
		push_swap_work->summ_doublerr_rra_rrb += push_swap_work->rra > push_swap_work->rrb ? rra : rrb;
	}
}

void		zero_struct(t_push_swap_work *push_swap_work)
{
	push_swap_work->ra = -1;
	push_swap_work->rb = -1;
	push_swap_work->rra = -1;
	push_swap_work->rrb = -1;
	push_swap_work->summ_ra_rra_rb_rrb = -1;
	push_swap_work->summ_doubler_ra_rb = -1;
	push_swap_work->summ_doublerr_rra_rrb = -1;
	push_swap_work->summ_result = -1;
	push_swap_work->doubler_ra_summ = 0;
	push_swap_work->doubler_rb_summ = 0;
	push_swap_work->doublerr_rra_summ = 0;
	push_swap_work->doublerr_rrb_summ = 0;
	push_swap_work->flag_ra_rra_rb_rrb = 0;
	push_swap_work->flag_doubler = 0;
	push_swap_work->flag_doublerr = 0;
}

void		zero_struct_tmp(t_push_swap_work *push_swap_work)
{
	push_swap_work->tmp_ra = -1;
	push_swap_work->tmp_rb = -1;
	push_swap_work->tmp_rra = -1;
	push_swap_work->tmp_rrb = -1;
	push_swap_work->tmp_summ_ra_rra_rb_rrb = -1;
	push_swap_work->tmp_summ_doubler_ra_rb = -1;
	push_swap_work->tmp_summ_doublerr_rra_rrb = -1;
	push_swap_work->tmp_summ_result = -1;
	push_swap_work->tmp_doubler_ra_summ = 0;
	push_swap_work->tmp_doubler_rb_summ = 0;
	push_swap_work->tmp_doublerr_rra_summ = 0;
	push_swap_work->tmp_doublerr_rrb_summ = 0;
	push_swap_work->tmp_flag_ra_rra_rb_rrb = 0;
	push_swap_work->tmp_flag_doubler = 0;
	push_swap_work->tmp_flag_doublerr = 0;
}

int			compare_two(int num, int num_2, t_push_swap_work *push_swap_work)
{
	if (num < num_2)
		return (num);
	return (num_2);
}

int			compare_three(int summ_ra_rra_rb_rrb, int summ_doubler_ra_rb, int summ_doublerr_rra_rrb, t_push_swap_work *push_swap_work)
{
	if (summ_ra_rra_rb_rrb < summ_doubler_ra_rb)
	{
		if (summ_ra_rra_rb_rrb < summ_doublerr_rra_rrb)
		{
			push_swap_work->flag_ra_rra_rb_rrb = 1;
			return (summ_ra_rra_rb_rrb);
		}
		else
		{
			push_swap_work->flag_doublerr = 1;
			return (summ_doublerr_rra_rrb);
		}
	}
	else
	{
		if (summ_doubler_ra_rb < summ_doublerr_rra_rrb)
		{
			push_swap_work->flag_doubler = 1;
			return (summ_doubler_ra_rb);
		}
		else
		{
			push_swap_work->flag_doublerr = 1;
			return (summ_doublerr_rra_rrb);
		}
	}
	return (-1);
}

void		comparison_summ(int summ_ra_rra_rb_rrb, int summ_doubler_ra_rb, int summ_doublerr_rra_rrb, t_push_swap_work *push_swap_work)
{
	if (summ_ra_rra_rb_rrb < 0 && summ_doubler_ra_rb >= 0 && summ_doublerr_rra_rrb >= 0)
	{
		push_swap_work->summ_result = compare_two(summ_doubler_ra_rb, summ_doublerr_rra_rrb, push_swap_work);
		push_swap_work->summ_result == summ_doubler_ra_rb ? (push_swap_work->flag_doubler = 1) : (push_swap_work->flag_doublerr = 1);
	}
	else if (summ_ra_rra_rb_rrb >= 0 && summ_doubler_ra_rb < 0 && summ_doublerr_rra_rrb >= 0)
	{
		push_swap_work->summ_result = compare_two(summ_ra_rra_rb_rrb, summ_doublerr_rra_rrb, push_swap_work);
		push_swap_work->summ_result == summ_ra_rra_rb_rrb ? (push_swap_work->flag_ra_rra_rb_rrb = 1) : (push_swap_work->flag_doublerr = 1);
	}
	else if (summ_ra_rra_rb_rrb >= 0 && summ_doubler_ra_rb >= 0 && summ_doublerr_rra_rrb < 0)
	{
		push_swap_work->summ_result = compare_two(summ_ra_rra_rb_rrb, summ_doubler_ra_rb, push_swap_work);
		push_swap_work->summ_result == summ_ra_rra_rb_rrb ? (push_swap_work->flag_ra_rra_rb_rrb = 1) : (push_swap_work->flag_doubler = 1);
	}
	else if (summ_ra_rra_rb_rrb >= 0 && summ_doubler_ra_rb < 0 && summ_doublerr_rra_rrb < 0)
	{
		push_swap_work->summ_result = summ_ra_rra_rb_rrb;
		push_swap_work->flag_ra_rra_rb_rrb = 1;
	}
	else if (summ_ra_rra_rb_rrb < 0 && summ_doubler_ra_rb >= 0 && summ_doublerr_rra_rrb < 0)
	{
		push_swap_work->summ_result = summ_doubler_ra_rb;
		push_swap_work->flag_doubler = 1;
	}
	else if (summ_ra_rra_rb_rrb < 0 && summ_doubler_ra_rb < 0 && summ_doublerr_rra_rrb >= 0)
	{
		push_swap_work->summ_result = summ_doublerr_rra_rrb;
		push_swap_work->flag_doublerr = 1;
	}
	else if (summ_ra_rra_rb_rrb >= 0 && summ_doubler_ra_rb >= 0 && summ_doublerr_rra_rrb >= 0)
		push_swap_work->summ_result = compare_three(summ_ra_rra_rb_rrb, summ_doubler_ra_rb, summ_doublerr_rra_rrb, push_swap_work);
}

void		summ_ra_rra_rb_rrb(t_push_swap_work *push_swap_work)
{
	push_swap_work->summ_ra_rra_rb_rrb = (push_swap_work->ra < push_swap_work->rra ? push_swap_work->ra : push_swap_work->rra) + (push_swap_work->rb < push_swap_work->rrb ? push_swap_work->rb : push_swap_work->rrb);
	// push_swap_work->res_ra_rra = (push_swap_work->ra < push_swap_work->rra) ? push_swap_work->ra : push_swap_work->rra;
	// push_swap_work->res_rb_rrb = (push_swap_work->rb < push_swap_work->rrb) ? push_swap_work->rb : push_swap_work->rrb;
}

void		print_struct(t_push_swap_work *push_swap_work)
{
	printf("\nstruct\n\n");
	printf("ra - %d\n", push_swap_work->ra);
	printf("rb - %d\n", push_swap_work->rb);
	printf("rra - %d\n", push_swap_work->rra);
	printf("rrb - %d\n", push_swap_work->rrb);
	printf("summ_ra_rra_rb_rrb    %d\n", push_swap_work->summ_ra_rra_rb_rrb);
	printf("summ_doubler_ra_rb    %d\n", push_swap_work->summ_doubler_ra_rb);
	printf("summ_doublerr_rra_rrb %d\n", push_swap_work->summ_doublerr_rra_rrb);
	printf("summ_result           %d\n", push_swap_work->summ_result);
	printf("flag_ra_rra_rb_rrb    %d\n", push_swap_work->flag_ra_rra_rb_rrb);
	printf("flag_doubler          %d\n", push_swap_work->flag_doubler);
	printf("flag_doublerr         %d\n", push_swap_work->flag_doublerr);
	printf("\n");
}

void		print_tmp_struct(t_push_swap_work *push_swap_work)
{
	printf("\ntmp_struct\n\n");
	printf("ra - %d\n", push_swap_work->tmp_ra);
	printf("rb - %d\n", push_swap_work->tmp_rb);
	printf("rra - %d\n", push_swap_work->tmp_rra);
	printf("rrb - %d\n", push_swap_work->tmp_rrb);
	printf("summ_ra_rra_rb_rrb    %d\n", push_swap_work->tmp_summ_ra_rra_rb_rrb);
	printf("summ_doubler_ra_rb    %d\n", push_swap_work->tmp_summ_doubler_ra_rb);
	printf("summ_doublerr_rra_rrb %d\n", push_swap_work->tmp_summ_doublerr_rra_rrb);
	printf("summ_result           %d\n", push_swap_work->tmp_summ_result);
	printf("flag_ra_rra_rb_rrb    %d\n", push_swap_work->tmp_flag_ra_rra_rb_rrb);
	printf("flag_doubler          %d\n", push_swap_work->tmp_flag_doubler);
	printf("flag_doublerr         %d\n", push_swap_work->tmp_flag_doublerr);
	printf("\n");
}

void		arifmetic_summ(t_push_swap_work *push_swap_work)
{
	summ_ra_rra_rb_rrb(push_swap_work);
	summ_doubler(push_swap_work);
	summ_doublerr(push_swap_work);
	comparison_summ(push_swap_work->summ_ra_rra_rb_rrb, push_swap_work->summ_doubler_ra_rb, push_swap_work->summ_doublerr_rra_rrb, push_swap_work);
}

void		copy_struct_to_tmp(t_push_swap_work *push_swap_work)
{
	push_swap_work->tmp_ra = push_swap_work->ra;
	push_swap_work->tmp_rb = push_swap_work->rb;
	push_swap_work->tmp_rra = push_swap_work->rra;
	push_swap_work->tmp_rrb = push_swap_work->rrb;
	push_swap_work->tmp_summ_ra_rra_rb_rrb = push_swap_work->summ_ra_rra_rb_rrb;
	push_swap_work->tmp_summ_doubler_ra_rb = push_swap_work->summ_doubler_ra_rb;
	push_swap_work->tmp_summ_doublerr_rra_rrb = push_swap_work->summ_doublerr_rra_rrb;
	push_swap_work->tmp_summ_result = push_swap_work->summ_result;
	push_swap_work->tmp_doubler_ra_summ = push_swap_work->doubler_ra_summ;
	push_swap_work->tmp_doubler_rb_summ = push_swap_work->doubler_rb_summ;
	push_swap_work->tmp_doublerr_rra_summ = push_swap_work->doublerr_rra_summ;
	push_swap_work->tmp_doublerr_rrb_summ = push_swap_work->doublerr_rrb_summ;
	push_swap_work->tmp_flag_ra_rra_rb_rrb = push_swap_work->flag_ra_rra_rb_rrb;
	push_swap_work->tmp_flag_doubler = push_swap_work->flag_doubler;
	push_swap_work->tmp_flag_doublerr = push_swap_work->flag_doublerr;
}

void		comparison_result_sum_and_recover(t_push_swap_work *push_swap_work)
{
	if (push_swap_work->summ_result < push_swap_work->tmp_summ_result)
	{
		zero_struct_tmp(push_swap_work);
		copy_struct_to_tmp(push_swap_work);
	}
}

void		stack_arifmetics(t_push_swap_work *push_swap_work, t_push_swap **stack_a, t_push_swap **stack_b)
{
	t_push_swap *iter_stack_b;

	iter_stack_b = *stack_b;
	zero_struct(push_swap_work);
	zero_struct_tmp(push_swap_work);
	push_swap_work->flag = 0;
	while (iter_stack_b)
	{
		if (push_swap_work->flag == 0)
		{
			current_stack_element_b(push_swap_work, iter_stack_b->number);
			rotate_b_count(push_swap_work, stack_b);
			rotate_a_count(push_swap_work, stack_a);
			arifmetic_summ(push_swap_work);
			copy_struct_to_tmp(push_swap_work);
			push_swap_work->flag = 1;
		}
		else
		{
			zero_struct(push_swap_work);
			current_stack_element_b(push_swap_work, iter_stack_b->number);
			rotate_b_count(push_swap_work, stack_b);
			rotate_a_count(push_swap_work, stack_a);
			arifmetic_summ(push_swap_work);
			comparison_result_sum_and_recover(push_swap_work);
		}
		// print_struct(push_swap_work);
		// print_tmp_struct(push_swap_work);
		iter_stack_b = iter_stack_b->next;
	}
}

void		perform_ra_rb(t_push_swap **stack, int iter)
{
	while (iter--)
		reverse_list(stack);
}

void		perform_rra_rrb(t_push_swap **stack, int iter)
{
	while (iter--)
		rreverse_list(stack);
}

void		doublerr_perform(t_push_swap_work *push_swap_work, t_push_swap **stack_a, t_push_swap **stack_b)
{
	while (push_swap_work->tmp_summ_doublerr_rra_rrb--)
		rreverse_r(stack_a, stack_b);
	while (push_swap_work->doublerr_rra_summ--)
		rreverse_list(stack_a);
	while (push_swap_work->doublerr_rrb_summ--)
		rreverse_list(stack_b);
}

void		doubler_perform(t_push_swap_work *push_swap_work, t_push_swap **stack_a, t_push_swap **stack_b)
{
	while (push_swap_work->tmp_summ_doubler_ra_rb--)
		reverse_r(stack_a, stack_b);
	while (push_swap_work->doubler_ra_summ--)
		reverse_list(stack_a);
	while (push_swap_work->doubler_rb_summ--)
		reverse_list(stack_b);
}

void		result_operations(t_push_swap_work *push_swap_work, t_push_swap **stack_a, t_push_swap **stack_b)
{
	if (push_swap_work->tmp_flag_ra_rra_rb_rrb)
	{
		push_swap_work->tmp_ra > push_swap_work->tmp_rra ? perform_rra_rrb(stack_a, push_swap_work->tmp_rra) : perform_ra_rb(stack_a, push_swap_work->tmp_ra);
		push_swap_work->tmp_rb > push_swap_work->tmp_rrb ? perform_rra_rrb(stack_b, push_swap_work->tmp_rrb) : perform_ra_rb(stack_b, push_swap_work->tmp_rb);
	}
	else if (push_swap_work->tmp_flag_doubler)
		doubler_perform(push_swap_work, stack_a, stack_b);
	else if (push_swap_work->tmp_flag_doublerr)
		doublerr_perform(push_swap_work, stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void		push_b_first(t_push_swap_work *push_swap_work, t_push_swap **stack_a, t_push_swap **stack_b)
{
	while (push_swap_work->count_word > 3)
	{
		if ((*stack_a)->number == push_swap_work->max_elem_array || (*stack_a)->number == push_swap_work->min_elem_array)
			reverse_list(stack_a);
		else
		{
			push_b(stack_a, stack_b);
			push_swap_work->count_word--;
		}
	}
}

void		count_ra_final(t_push_swap **stack_a, t_push_swap_work *push_swap_work)
{
	t_push_swap *iter;
	int			count;

	iter = *stack_a;
	count = 0;
	while (iter)
	{
		if (iter->number == push_swap_work->min_elem_array)
			push_swap_work->tmp_ra = count;
		count++;
		iter = iter->next;
	}
}

void		count_rra_final(t_push_swap **stack_a, t_push_swap_work *push_swap_work)
{
	t_push_swap *iter;
	int			count;

	iter = *stack_a;
	count = 0;
	while (iter->next)
		iter = iter->next;
	while (iter)
	{
		if (iter->number == push_swap_work->max_elem_array)
			push_swap_work->tmp_rra = count;
		count++;
		iter = iter->prev;
	}
}

void		result_reverse(t_push_swap **stack_a, t_push_swap_work *push_swap_work)
{
	count_ra_final(stack_a, push_swap_work);
	count_rra_final(stack_a, push_swap_work);
	push_swap_work->tmp_ra > push_swap_work->tmp_rra ? perform_rra_rrb(stack_a, push_swap_work->tmp_rra) : perform_ra_rb(stack_a, push_swap_work->tmp_ra);
}

void		ft_work_with_stack(t_push_swap_work *push_swap_work, t_push_swap **stack_a, t_push_swap **stack_b)
{
	if (push_swap_work->count_word > 3)
		push_b_first(push_swap_work, stack_a, stack_b);
	sort(stack_a);
	// printf("stack_a\n");
	// ft_print_list(*stack_a);
	while (*stack_b)
	{
		// printf("stack_a\n");
		// ft_print_list(*stack_a);
		// printf("\n");
		// printf("stack_b\n");
		// ft_print_list(*stack_b);
		stack_arifmetics(push_swap_work, stack_a, stack_b);
		result_operations(push_swap_work, stack_a, stack_b);
		// printf("stack_a\n");
		// ft_print_list(*stack_a);
		// printf("stack_a\n");
		// ft_print_list(*stack_a);
		// printf("\n");
		// printf("stack_b\n");
		// ft_print_list(*stack_b);
	}
	result_reverse(stack_a, push_swap_work);
	printf("stack_a\n");
	ft_print_list(*stack_a);
	// printf("\n");
	// printf("stack_b\n");
	// ft_print_list(*stack_b);
}

void		search_max_min(int *array, int len, t_push_swap_work *push_swap_work)
{
	quick_sort(array, 0, len - 1, len);
	push_swap_work->max_elem_array = array[len - 1];
	push_swap_work->min_elem_array = array[0];
	// printf("max - %d\n", push_swap_work->max_elem_array);
	// printf("min - %d\n", push_swap_work->min_elem_array);
}

int     	main (int ac, char **av)
{
	t_push_swap_work	push_swap_work;
	t_push_swap			*stack_a;
	t_push_swap			*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!(push_swap_work.count_word = ft_valid(ac - 1, av + 1)) || !(push_swap_work.array_int = ft_init_array(ac - 1, av + 1, push_swap_work.count_word)))
		return (0);
	if (!(push_swap_work.check_duplicat = ft_check_array_duplicat(&push_swap_work, push_swap_work.count_word)))
		return (0);
	if (!(stack_a = ft_init_list(push_swap_work.array_int, push_swap_work.count_word, stack_a)))
		return (ft_free_array_int(push_swap_work.array_int));
	search_max_min(push_swap_work.array_int, push_swap_work.count_word, &push_swap_work);
	// printf("stack_a\n");
	// ft_print_list(stack_a);
	// printf("\n");
	ft_work_with_stack(&push_swap_work, &stack_a, &stack_b);
	// printf("stack_a\n");
	// ft_print_list(stack_a);
	// printf("stack_b\n");
	// ft_print_list(stack_b);
	return (0);
}