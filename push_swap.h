/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:14:11 by tchemin           #+#    #+#             */
/*   Updated: 2025/12/09 18:37:46 by tchemin          ###   ########.fr       */
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

int					*ft_atoi(char *s);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_bzero(void *s, size_t n);
int					ft_strlen(char *s);
int					get_size_of_bin(int nbr);

char				*convert_final_index_to_binary(int nbr, t_list *lst);
void				place_final_index(t_list *array_sorted, t_list *lst);
void				*clear_lst(t_list *lst);
void				add_back_lst(t_list **lst, t_list *new);
void				add_front_lst(t_list **lst, t_list *new);
t_list				*new_lst(int nbr, char name, int origin, int last_index);
t_list				*last_lst(t_list *lst);
t_list				*init_list(t_list *lst, int *nbr);
t_list				*first_lst(t_list *lst);
int					size_lst(t_list *lst);
void				*delone_lst(t_list *lst);

int					verif_duplicate(t_list *lst, int nbr);
int					print_error(t_list *a, t_list *b);

void				swap(t_list **lst);
void				d_swap(t_list *first_lst, t_list *second_lst);
void				push(t_list **lst, t_list **lst_pushed_into);
void				rotate(t_list **lst);
void				d_rotate(t_list **first_lst, t_list **second_lst);
void				reverse(t_list **lst);
void				d_reverse(t_list **first_lst, t_list **second_lst);

int					is_sorted(t_list *lst);
void				sort(t_list *lst_a);
t_list				*simple(t_list *lst_a, t_list *lst_b);
t_list				*complex(t_list *lst_a, t_list *lst_b);
t_list				*init_array(t_list *lst);

#endif