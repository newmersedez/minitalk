/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:25:29 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/02 16:04:27 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	display_args_error_message(void)
{
	ft_putendl("Incorrect format of input data!");
	ft_putendl("It must be ./client <pid> <message>");
}

void	send_message(pid_t pid, char *message)
{
	int	i;

	while (*message)
	{
		i = 128;
		while (i >= 1)
		{
			if (i & *message)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i /= 2;
			usleep(100);
		}
		message++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*message;

	if (argc != 3)
	{
		display_args_error_message();
		exit(1);
	}
	pid = (pid_t)ft_atoi(argv[1]);
	message = argv[2];
	send_message(pid, message);
	return (0);
}
