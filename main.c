/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchemin <tchemin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:14:28 by tchemin           #+#    #+#             */
/*   Updated: 2026/01/11 14:48:31 by tchemin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*choose_alg(char *algo, t_list *a, t_list *b, t_bench *bench)
{
	if (a)
		sort(a);
	if (!ft_strncmp(algo, "--simple", 8))
		return (simple(a, b, bench, size_lst(a)));
	else if (!ft_strncmp(algo, "--medium", 8))
		return (medium(a, b, bench));
	else if (!ft_strncmp(algo, "--complex", 9))
		return (complex(a, b, bench));
	else
		return (adaptative(a, b, bench));
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

int	parse_arg(t_list **a, t_list **b, int argc, char **argv)
{
	int	i;

	i = 1;
	if (argv[i] && !ft_strncmp(argv[i], "--bench", 7))
		i++;
	if (argv[i] && (!ft_strncmp(argv[i], "--simple", 8) || !ft_strncmp(argv[i],
				"--complex", 9) || !ft_strncmp(argv[i], "--adaptive", 10)
			|| !ft_strncmp(argv[i], "--medium", 8)))
		i++;
	while (i < argc)
	{
		(*a) = init_list(*a, argv[i++]);
		if (!(*a))
			return (0);
	}
	if (!(*a))
		exit(EXIT_SUCCESS);
	if (argv[1] && !ft_strncmp(argv[1], "--bench", 7) && argv[2])
		benchmark(a, b, argv[2]);
	else
		(*a) = choose_alg(argv[1], *a, *b, NULL);
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
