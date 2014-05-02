/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 05:00:27 by amerle            #+#    #+#             */
/*   Updated: 2014/05/02 05:15:08 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCRIPT_H
# define FT_SCRIPT_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <termios.h>

# define FT_TCGETATTR(F, T) ioctl(F, TIOCGETA, T)
# define EXTERN_CHAR_ENVIRON extern char **environ

typedef struct s_script	t_script;

struct				s_script
{
	struct termios	line;
	struct winsize	winp;
	int				fd_master;
	int				fd_slave;
	pid_t			child_pid;
	fd_set			*read_fds;
	int				exit;
	int				fd_file;
	char			*outfile;
	char			**flag_c;
	int				flag_t;
	int				flag_a;
	int				flag_k;
	int				flag_q;
};

t_script			*script_singleton(void);
int					pty_open(t_script *sc);
int					pty_fork(t_script *sc);
int					pty_script(t_script *sc);
int					ft_puterror(char *error, int status);
char				*ft_ptsname(int fd);
int					ft_grantpt(int fd);
int					ft_unlockpt(int fd);
int					ft_init(t_script *sc);
int					ft_parse_flag(char *arg, t_script *sc);
void				pty_signals(void);
void				pty_exit(t_script *sc);
char				*ft_gettime(void);
char				*ft_getshell(void);
void				pty_write(t_script *sc);
void				pty_read(t_script *sc);

#endif
