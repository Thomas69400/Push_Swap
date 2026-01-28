/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufeal <madufeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:14:11 by tchemin           #+#    #+#             */
/*   Updated: 2026/01/28 15:21:37 by madufeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include <stddef.h>
# include <stdlib.h>

typedef struct s_list
{
	int				nb;
	char			name;
	int				origin;
	int				last_index;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct s_bench
{
	int				pa;
	int				pb;
	int				sa;
	int				sb;
	int				ss;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
	int				to_print;
	float			disorder;
}					t_bench;

int					*ft_atoi(char **s);
int					has_numbers(char *to_atoi);
int					is_only_nbr_and_space(char *s);
int					ft_sqrt(int nb);
int					ft_strcmp(char *s1, char *s2);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_bzero(void *s, size_t n);
int					get_size_of_bin(int nbr);

char				*convert_final_index_to_binary(int nbr, t_list *lst);
void				place_final_index(t_list *array_sorted, t_list *lst);
void				*clear_lst(t_list *lst);
void				add_back_lst(t_list **lst, t_list *new);
void				add_front_lst(t_list **lst, t_list *new);
t_list				*new_lst(int nbr, char name, int origin, int last_index);
t_list				*last_lst(t_list *lst);
t_list				*init_list(t_list *lst, char *to_atoi);
t_list				*first_lst(t_list *lst);
t_list				*init_array(t_list *lst);
int					size_lst(t_list *lst);
void				*delone_lst(t_list *lst);
int					get_last_index_min_max(t_list *lst, char *search);

t_list				*choose_alg(char *algo, t_list *a, t_list *b,
						t_bench *bench);

int					verif_duplicate(t_list *lst, int *nbr);
int					print_error(t_list *a, t_list *b);

int					swap(t_list **lst, t_bench *bench);
void				d_swap(t_list *a, t_list *b, t_bench *bench);
int					push(t_list **lst, t_list **lst_pushed_into,
						t_bench *bench);
int					rotate(t_list **lst, t_bench *bench);
void				d_rotate(t_list **a, t_list **b, t_bench *bench);
int					reverse(t_list **lst, t_bench *bench);
void				d_reverse(t_list **a, t_list **b, t_bench *bench);

int					is_sorted(t_list *lst, char order);
void				sort(t_list *lst_a);

t_list				*simple(t_list *lst_a, t_list *lst_b, t_bench *bench,
						int size);
t_list				*medium(t_list *lst_a, t_list *lst_b, t_bench *bench);
t_list				*complex(t_list *lst_a, t_list *lst_b, t_bench *bench);
t_list				*adaptive(t_list *lst_a, t_list *lst_b, t_bench *bench);

float				compute_disorder(t_list *lst);
void				benchmark(t_bench *bench, char *algo);
void				init_bench(t_bench *bench, t_list *a);

#endif