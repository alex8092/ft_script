/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pty_script2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 05:14:18 by amerle            #+#    #+#             */
/*   Updated: 2014/05/02 05:14:19 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

void	pty_write(t_script *sc)
{
	char	buf[1024];
	ssize_t	len;

	if (FD_ISSET(sc->fd_master, sc->read_fds))
	{
		if ((len = read(sc->fd_master, buf, 1023)) < 0)
			_exit(1);
		write(1, buf, len);
		write(sc->fd_file, buf, len);
	}
	else if (FD_ISSET(0, sc->read_fds))
	{
		if ((len = read(0, buf, 1023)) < 0)
			_exit(2);
		write(sc->fd_master, buf, len);
	}
}

void	pty_read(t_script *sc)
{
	fd_set	read_fds;

	sc->read_fds = &read_fds;
	while (!sc->exit)
	{
		FD_ZERO(&read_fds);
		FD_SET(0, &read_fds);
		FD_SET(sc->fd_master, &read_fds);
		if ((select(sc->fd_master + 1, &read_fds, NULL, NULL, NULL)) >= 0)
			pty_write(sc);
	}
}
