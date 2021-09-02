/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:25:51 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/02 16:18:25 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	display_server_info(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("Server pid: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	ft_putstr("Use ./client ");
	ft_putnbr(pid);
	ft_putendl(" <message>");
}

void	display_symbol(char c)
{
	ft_putchar(c);
	g_msg.char_code = 0;
	g_msg.counter = 128;
}

void	one_handler(int signo)
{
	(void)signo;
	g_msg.char_code += g_msg.counter;
	g_msg.counter /= 2;
	if (!g_msg.counter)
		display_symbol(g_msg.char_code);
}

void	zero_handler(int signo)
{
	(void)signo;
	g_msg.counter /= 2;
	if (!g_msg.counter)
		display_symbol(g_msg.char_code);
}

int	main(void)
{
	struct sigaction	zero;
	struct sigaction	one;

	display_server_info();
	zero.sa_handler = zero_handler;
	one.sa_handler = one_handler;
	g_msg.char_code = 0;
	g_msg.counter = 128;
	while (1)
	{
		sigaction(SIGUSR1, &one, NULL);
		sigaction(SIGUSR2, &zero, NULL);
		pause();
	}
	return (0);
}
