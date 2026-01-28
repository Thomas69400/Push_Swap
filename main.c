/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:14:28 by tchemin           #+#    #+#             */
/*   Updated: 2026/01/28 16:14:40 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*choose_alg(char *algo, t_list *a, t_list *b, t_bench *bench)
{
	if (a)
		sort(a);
	if (ft_strcmp(algo, "--simple") == 0)
		return (simple(a, b, bench, size_lst(a)));
	else if (ft_strcmp(algo, "--medium") == 0)
		return (medium(a, b, bench));
	else if (ft_strcmp(algo, "--complex") == 0)
		return (complex(a, b, bench));
	else
		return (adaptive(a, b, bench));
	print_error(a, b);
	return (NULL);
}

static int	success(t_list *a, t_list *b)
{
	if (a)
		clear_lst(a);
	if (b)
		clear_lst(b);
	return (0);
}

int	get_stack(t_list **a, int start, char **argv, int argc)
{
	while (start < argc)
	{
		(*a) = init_list(*a, argv[start++]);
		if (!(*a))
			return (0);
	}
	if (!(*a))
		exit(EXIT_SUCCESS);
	return (1);
}

int	parse_arg(t_list **a, t_list **b, int argc, char **argv)
{
	int		i;
	t_bench	bench;

	i = 1;
	if (argv[i] && ft_strcmp(argv[i], "--bench") == 0)
		i++;
	if (argv[i] && (ft_strcmp(argv[i], "--simple") == 0 || ft_strcmp(argv[i],
				"--complex") == 0 || ft_strcmp(argv[i], "--adaptive") == 0
			|| ft_strcmp(argv[i], "--medium") == 0))
		i++;
	if (!get_stack(a, i, argv, argc))
		return (0);
	init_bench(&bench, *a);
	(*a) = choose_alg(argv[i - 1], *a, *b, &bench);
	if (argv[2] && ft_strcmp(argv[1], "--bench") == 0)
		benchmark(&bench, argv[2]);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (1);
	if (!parse_arg(&a, &b, argc, argv))
		return (print_error(a, b));
	return (success(a, b));
}
