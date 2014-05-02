/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pty_script.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 04:59:11 by amerle            #+#    #+#             */
/*   Updated: 2014/05/02 05:13:55 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"
#include "common.h"

EXTERN_CHAR_ENVIRON;

static void		pty_print_begend(t_script *sc, int end)
{
	char	*stime;

	stime = ft_gettime();
	if (sc->flag_q)
		return ;
	if (end)
		write(sc->fd_file, "\n", 1);
	write(sc->fd_file, "Script ", sizeof("Script ") - 1);
	if (!end)
		write(sc->fd_file, "started", sizeof("started") - 1);
	else
		write(sc->fd_file, "done", sizeof("done") - 1);
	write(sc->fd_file, " on ", sizeof(" on ") - 1);
	write(sc->fd_file, stime, ft_strlen(stime));
	if (!end)
		write(sc->fd_file, "\n", 1);
}

static size_t	tablen(t_script *sc)
{
	char	**tab;
	size_t	count;

	tab = sc->flag_c;
	count = 0;
	while (tab && *tab)
	{
		if (count)
			++count;
		count += ft_strlen(*tab);
		++tab;
	}
	return (count);
}

static void		tabconcat(t_script *sc, char *buffer)
{
	size_t	i;
	size_t	j;
	char	**tab;

	i = 0;
	tab = sc->flag_c;
	while (tab && *tab)
	{
		j = 0;
		while ((*tab)[j])
		{
			buffer[i + j] = (*tab)[j];
			++j;
		}
		i += j;
		buffer[i++] = ' ';
		++tab;
	}
	buffer[i] = 0;
}

static void		do_arg(t_script *sc, char **argv, char *cmd, char **shell2)
{
	char	*shell;

	shell = ft_getshell();
	argv[0] = shell;
	if (sc->flag_c && *sc->flag_c)
	{
		argv[1] = "-c";
		tabconcat(sc, cmd);
		argv[2] = cmd;
		argv[3] = 0;
	}
	else
		argv[1] = 0;
	*shell2 = shell;
}

int				pty_script(t_script *sc)
{
	char	*shell;
	char	*argv[4];
	char	cmd[tablen(sc) + 1];

	if (sc->child_pid == 0)
	{
		do_arg(sc, argv, cmd, &shell);
		execve(shell, argv, environ);
		_exit(-1);
	}
	else
	{
		if (!sc->flag_q)
		{
			ft_putstr("Script started, output file is ");
			ft_putstr(sc->outfile);
			ft_putstr("\n");
		}
		pty_print_begend(sc, 0);
		pty_read(sc);
		pty_print_begend(sc, 1);
		pty_exit(sc);
	}
	return (0);
}
