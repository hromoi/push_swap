/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:39:55 by yperra-f          #+#    #+#             */
/*   Updated: 2019/10/01 14:30:57 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct          s_push_swap
{
	int                 number;
	struct s_push_swap  *next;
	struct s_push_swap  *prev;
}                       t_push_swap;

typedef struct          s_push_swap_work
{
	int                 *array_int;
	int                 count_word;
	int                 check_duplicat;
	int                 median;
	int                 ra;
	int                 rra;
	int                 rb;
	int                 rrb;
	int					doubler_ra_summ;
	int					doubler_rb_summ;
	int					doublerr_rra_summ;
	int					doublerr_rrb_summ;
	int                 flag_ra_rra_rb_rrb;
	int                 flag_doubler;
	int                 flag_doublerr;
	int                 summ_ra_rra_rb_rrb;
	int                 summ_doubler_ra_rb;
	int                 summ_doublerr_rra_rrb;
	int                 summ_result;
	int                 tmp_ra;
	int                 tmp_rra;
	int                 tmp_rb;
	int                 tmp_rrb;
	int					tmp_doubler_ra_summ;
	int					tmp_doubler_rb_summ;
	int					tmp_doublerr_rra_summ;
	int					tmp_doublerr_rrb_summ;
	int                 tmp_flag_ra_rra_rb_rrb;
	int                 tmp_flag_doubler;
	int                 tmp_flag_doublerr;
	int                 tmp_summ_ra_rra_rb_rrb;
	int                 tmp_summ_doubler_ra_rb;
	int                 tmp_summ_doublerr_rra_rrb;
	int                 tmp_summ_result;
	int                 current_stack_element_b;
	int                 current_elem;
	int                 flag;
	int					max_elem_array;
	int					min_elem_array;
}                       t_push_swap_work;

char                    **ft_strsplit(const char *av);
void                    ft_free_array(char **av);
char                    **ft_free(char **av, int j);
char                    *ft_strdup(const char *av);
char                    *ft_strsub(const char *av, unsigned int start, size_t len);
void                    quick_sort(int *av, int left, int right, int len);
void					swap_list(t_push_swap **stack);
void					swap_ss(t_push_swap **stack_a, t_push_swap **stack_b);
void					rreverse_list(t_push_swap **stack);
void                    rreverse_r(t_push_swap **stack_a, t_push_swap **stack_b);
void                    reverse_list(t_push_swap **stack);
void                    reverse_r(t_push_swap **stack_a, t_push_swap **stack_b);
void                    push_a(t_push_swap **stack_a, t_push_swap **stack_b);
void                    push_b(t_push_swap **stack_a, t_push_swap **stack_b);

#endif