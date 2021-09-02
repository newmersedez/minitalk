/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:25:49 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/02 17:44:16 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <sys/types.h>
# include <signal.h>

typedef struct s_message
{
	int		char_code;
	size_t	counter;
}	t_message;

t_message	g_msg;

#endif