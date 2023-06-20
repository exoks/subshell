/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:46:06 by hael-mou          #+#    #+#             */
/*   Updated: 2023/06/18 12:20:44 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

/*###############################################################
#		* Includes :		    							 	#
###############################################################*/
# include "libft.h"
# include "defines.h"

/*###############################################################
#		* operator Types :		    						 	#
###############################################################*/
typedef struct s_command
{
	int			type;
	pid_t		pid;
	char		*name;
	char		*path;
	char		**args;
	t_list		*in_out;
}				t_command;

/*###############################################################
#		* Functions :		    							 	#
###############################################################*/
t_command	*create_command_node(void);

#endif /* COMMAND_H */