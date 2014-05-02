/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 04:59:11 by amerle            #+#    #+#             */
/*   Updated: 2014/05/02 05:08:12 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"
#include "common.h"
#include <signal.h>

t_script	*script_singleton(void)
{
	static t_script	sc;

	return (&sc);
}

static void	parse_arg(int ac, char **av, t_script *sc)
{
	int	i;

	i = 1;
	while (i < ac && ft_parse_flag(av[i], sc) != 0)
		i++;
	if (av[i])
	{
		sc->outfile = av[i];
		sc->flag_c = av + i + 1;
	}
}

static void	on_error(int master, int slave, int dokill, t_script *sc)
{
	if (master)
		close(sc->fd_master);
	if (slave)
		close(sc->fd_slave);
	if (dokill)
		kill(sc->child_pid, SIGQUIT);
}

int			main(int ac, char **av)
{
	t_script		*sc;
	int				status;

	sc = script_singleton();
	ft_bzero(sc, sizeof(t_script));
	ft_init(sc);
	parse_arg(ac, av, sc);
	pty_signals();
	if ((status = pty_open(sc)) < 0)
	{
		on_error(status != -1, status != -2, 0, sc);
		return (status);
	}
	if ((status = pty_fork(sc)) < 0)
	{
		on_error(1, 1, 0, sc);
		return (ft_puterror("Unable to fork", status));
	}
	if ((status = pty_script(sc)) < 0)
	{
		on_error(1, 1, 1, sc);
		return (ft_puterror("Failed to start script", status));
	}
	return (0);
}
