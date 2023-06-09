/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:06:23 by hael-mou          #+#    #+#             */
/*   Updated: 2023/06/17 23:13:23 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

/*###############################################################
#		* Includes :		    							 	#
###############################################################*/
# include "defines.h"
# include "libft.h"
# include "var.h"

t_list *g_env;
/*###############################################################
#		* Functions :											#
###############################################################*/
int	    minishell_export(char *new_var);
int		minishell_unset(char *var_name);

#endif /* BUILTINS_H */