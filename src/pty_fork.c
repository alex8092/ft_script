/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pty_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 04:59:11 by amerle            #+#    #+#             */
/*   Updated: 2014/05/02 04:59:11 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int			pty_fork(t_script *sc)
{
	if ((sc->child_pid = fork()) == -1)
		return (ft_puterror("Unable to fork()\n", -1));
	else if (sc->child_pid == 0)
	{
		close(sc->fd_master);
		if (setsid() == -1)
			return (ft_puterror("Unable to start a new session\n", -2));
		if (ioctl(sc->fd_slave, TIOCSCTTY, (char *)NULL) == -1)
			return (-1);
		dup2(sc->fd_slave, 0);
		dup2(sc->fd_slave, 1);
		dup2(sc->fd_slave, 2);
		if (sc->fd_slave > 2)
			close(sc->fd_slave);
	}
	else
		close(sc->fd_slave);
	return (0);
}
